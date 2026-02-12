# This file is authored by Peter Urban, Ghent University, and is subject to the MPL-2.0 license.
# SPDX-License-Identifier: MPL-2.0

import os
from pathlib import Path
from collections import defaultdict
from typing import List, Dict, Union
import hashlib
from tqdm.auto import tqdm
import numpy as np

# Prefer xxhash (non-cryptographic, ~10x faster than SHA-256) if available
try:
    import xxhash
    _HASH_ALGO = "xxhash"
except ImportError:
    _HASH_ALGO = "md5"  # md5 is ~2-3x faster than sha256; security is irrelevant here


def _new_hasher():
    """Return a fresh hash object (xxhash if available, else md5)."""
    if _HASH_ALGO == "xxhash":
        return xxhash.xxh128()
    return hashlib.md5()


def _quick_fingerprint(file_name: str, block_size: int = 1024 * 1024) -> str:
    """Return a fast fingerprint by hashing only the first and last *block_size* bytes.

    For files smaller than 2 * block_size the whole file is read.
    This is very cheap (two sequential reads) and eliminates the vast majority
    of non-identical same-name-same-size files before a full sampled hash is needed.
    """
    file_size = os.path.getsize(file_name)
    h = _new_hasher()
    with open(file_name, "rb") as f:
        h.update(f.read(block_size))
        if file_size > 2 * block_size:
            f.seek(-block_size, os.SEEK_END)
        h.update(f.read(block_size))
    return h.hexdigest()


def get_hash(file_name: str, max_read_size_mb: Union[int, None] = 5, hash_fraction: float = 0.1) -> str:
    """
    Calculate a sampled hash of a file.

    Uses xxhash (if installed) or md5 as the hash function. These are
    non-cryptographic / fast hashes that are perfectly adequate for
    duplicate detection.

    Parameters
    ----------
    file_name : str
        The path to the file to be hashed.
    max_read_size_mb : Union[int, None], optional
        The maximum total amount of data (in MB) to read from the file.
        If the file is larger, chunks are spread across the file so that
        at most this many MB are read.  By default 5.
    hash_fraction : float, optional
        Fraction of the file bytes to hash (0 < hash_fraction <= 1). For
        example, 0.1 means roughly every 10th chunk is hashed.  By default 0.1.

    Returns
    -------
    str
        The hex-digest of the hash.
    """
    # Use 256 KB chunks — 64x fewer syscalls than the old 4 KB chunks
    chunk_size = 256 * 1024
    skip_bytes = 0

    # Apply fraction-based skipping: read one chunk, skip (1/fraction - 1) chunks
    if hash_fraction is not None and 0 < hash_fraction < 1.0:
        skip_bytes = int(chunk_size * (1.0 / hash_fraction - 1.0))

    # If max_read_size_mb is set, cap total bytes read
    if max_read_size_mb is not None:
        file_size = os.path.getsize(file_name)
        max_read_bytes = max_read_size_mb * 1024 * 1024
        if file_size > max_read_bytes:
            n_chunks = max(1, int(max_read_bytes / chunk_size))
            skip_for_cap = int(file_size / n_chunks) - chunk_size
            skip_bytes = max(skip_bytes, skip_for_cap)

    h = _new_hasher()
    with open(file_name, "rb") as f:
        for chunk in iter(lambda: f.read(chunk_size), b""):
            h.update(chunk)
            if skip_bytes > 0:
                f.seek(skip_bytes, os.SEEK_CUR)

    return h.hexdigest()


def group_by_hash(file_paths: List[str], hash_read_size_mb: Union[int, None] = 5, hash_fraction: float = 0.1) -> Dict[str, List[str]]:
    """
    Groups a list of file paths by their hash value.

    Parameters
    ----------
    file_paths : List[str]
        A list of file paths to group by hash value.
    hash_read_size_mb : Union[int, None], optional
        The number of megabytes to read from each file when calculating its hash value. If None, the entire file will be read. By default, 5.
    hash_fraction : float, optional
        Fraction of the file bytes to hash (0 < hash_fraction <= 1). By default, 0.1.

    Returns
    -------
    Dict[str, List[str]]
        A dictionary where the keys are hash values and the values are lists of file paths that have that hash value.
    """
    fdict = defaultdict(list)
    for file in file_paths:
        fdict[get_hash(file, hash_read_size_mb, hash_fraction)].append(file)
    return fdict


def remove_duplicates(file_paths: List[str], hash_read_size_mb: Union[int, None] = 5, hash_fraction: float = 0.1, verbose: bool = True) -> List[str]:
    """
    Remove duplicate files from a list of file paths.

    Uses a three-stage approach for speed:
      1. Group by basename (free).
      2. Among same-name files, group by file size (free).
      3. Among same-name-same-size files, compare a quick fingerprint
         (first + last 1 MB).  Only if fingerprints collide, fall through
         to a full sampled hash.

    Parameters
    ----------
    file_paths : List[str]
        A list of file paths.
    hash_read_size_mb : Union[int, None], optional
        The size of the chunk to read from the file for hashing. If None, the entire file is read. By default, 5.
    hash_fraction : float, optional
        Fraction of the file bytes to hash (0 < hash_fraction <= 1). Lower values are faster but
        have a (very small) chance of missing non-identical files with the same name and size.
        By default, 0.1 (hash 1/10th of bytes).
    verbose : bool, optional
        Whether to print the number of removed duplicates. By default, True.

    Returns
    -------
    List[str]
        A list of file paths with duplicates removed.
    """
    # Create a dictionary to group files by their basename
    fdict = defaultdict(list)
    # Create a dictionary to count the number of files per folder
    number_files_per_folder = defaultdict(int)
    # Create a list to store the new file paths
    new_file_paths = []

    # Group files by their basename and count the number of files per folder
    for file in file_paths:
        fdict[os.path.basename(file)].append(file)
        number_files_per_folder[os.path.dirname(file)] += 1

    def _pick_best(ff_files: List[str]) -> str:
        """From a set of duplicate files, pick the one in the folder with the most files."""
        nf = [number_files_per_folder[os.path.dirname(f)] for f in ff_files]
        return ff_files[np.argmax(nf)]

    # Iterate over the files grouped by their basename
    for f_name, f_paths in tqdm(fdict.items(), desc='removing duplicates', delay=3):
        if len(f_paths) == 1:
            new_file_paths.append(f_paths[0])
            continue

        # Stage 1: group by file size (free — no I/O)
        size_groups = defaultdict(list)
        for fp in f_paths:
            size_groups[os.path.getsize(fp)].append(fp)

        for size, same_size_paths in size_groups.items():
            if len(same_size_paths) == 1:
                new_file_paths.append(same_size_paths[0])
                continue

            # Stage 2: quick fingerprint (first + last 1 MB — two reads per file)
            fp_groups = defaultdict(list)
            for fp in same_size_paths:
                fp_groups[_quick_fingerprint(fp)].append(fp)

            for fp_key, fp_files in fp_groups.items():
                if len(fp_files) == 1:
                    new_file_paths.append(fp_files[0])
                    continue

                # Stage 3: full sampled hash (only reached for files identical
                # at head+tail — almost always true duplicates)
                files_per_hash = group_by_hash(fp_files, hash_read_size_mb, hash_fraction)
                for ff_hash, ff_files in files_per_hash.items():
                    new_file_paths.append(_pick_best(ff_files))

    if verbose:
        print(f"Removed {len(file_paths) - len(new_file_paths)} duplicate files")

    return new_file_paths



def find_files(
    folders: Union[str, List[str]], 
    endings: Union[str, List[str]], 
    followlinks: bool = False,
    remove_duplicated_files: bool = True, 
    hash_fraction: float = 0.1,
    verbose: bool = True) -> List[str]:
    """
    Recursively searches for files with the given endings in the specified folders.

    Parameters
    ----------
    folders : Union[str, List[str]]
        The folders to search for files.
    endings : Union[str, List[str]]
        The file endings to match.
    followlinks : bool, optional
        If True, follows symbolic links. Defaults to False.
    remove_duplicated_files : bool, optional
        If True, removes any duplicate files found (comparing first file name then hash). Defaults to True.
    hash_fraction : float, optional
        Fraction of the file bytes to hash when checking for duplicates (0 < hash_fraction <= 1).
        Lower values are faster. By default, 0.1 (hash 1/10th of bytes).
    verbose : bool, optional
        If True, prints progress messages indicating how many files were found and how many duplicates were removed (if applicable). Defaults to True.

    Returns
    -------
    List[str]
        A list of file paths (as strings) that match the specified endings and are found in the specified folders.
    """
    # initialize an empty list to store file paths
    file_paths = []

    # convert folders to list if it is a string or a pathlib.Path object
    if isinstance(folders, (str, Path)):
        folders = [folders]

    # convert endings to list if it is a string
    if isinstance(endings, str):
        endings = [endings]
    
    # iterate over each folder and ending to search for files
    for folder in folders:
        for r,d,f in os.walk(folder, followlinks=followlinks):
            for file in f:
                for ending in endings:
                    if file.endswith(ending):
                        file_paths.append(os.path.join(r,file))

    # convert the file paths to strings
    file_paths = [str(f) for f in file_paths]

    # remove duplicated files if specified
    if remove_duplicated_files:
        file_paths_deduplicated = remove_duplicates(file_paths, hash_fraction=hash_fraction, verbose=False)
        if verbose:
            # print progress message indicating how many files were found and how many duplicates were removed
            if len(file_paths_deduplicated) < len(file_paths):
                print(f"Found {len(file_paths_deduplicated)} files + {len(file_paths) - len(file_paths_deduplicated)} duplicates (discarded)")
            else:
                print(f"Found {len(file_paths_deduplicated)} files")
        return file_paths_deduplicated

    # if not removing duplicated files, simply print progress message indicating how many files were found
    if verbose:
        print(f"Found {len(file_paths)} files")

    return file_paths
    
def find_folders_with_files(
    folders: Union[str, List[str]], 
    endings: Union[str, List[str]], 
    followlinks: bool = False,
    verbose: bool = True) -> List[str]:
    """
    Find folders that contain files with specified endings.

    Args:
        folders (Union[str, List[str]]): Path or list of paths to search for files.
        endings (Union[str, List[str]]): File endings to filter files.
        followlinks (bool, optional): Whether to follow symbolic links. Defaults to False.
        verbose (bool, optional): Whether to display progress information. Defaults to True.

    Returns:
        List[str]: List of folders that contain files with specified endings.
    """

    file_paths = find_files(folders,endings,remove_duplicated_files=False,followlinks=followlinks,verbose=verbose)

    folders_with_files = list(set([os.path.dirname(f) for f in file_paths]))

    return folders_with_files


    