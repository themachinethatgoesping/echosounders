# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: MPL-2.0

from typing import List, Dict, Union, Tuple

from .get_index_paths import *
from .index_file_functions import *
from .find_files import *


def find_files_and_index(
    folders: Union[str, List[str]],
    endings: Union[str, List[str]],
    followlinks: bool = False,
    remove_duplicated_files: bool = True,
    verbose: bool = True,
    index_file_ending: str = '.tmtgp.index',
    index_root: str = 'index',
    create_dir: bool = True,
) -> Tuple[List[str], Dict[str, str]]:
    """Find files and get their corresponding index paths.
    
    This function combines find_files and get_index_paths for convenience.

    Parameters
    ----------
    folders : Union[str, List[str]]
        The folders to search for files.
    endings : Union[str, List[str]]
        The file endings to match.
    followlinks : bool, optional
        If True, follows symbolic links. Defaults to False.
    remove_duplicated_files : bool, optional
        If True, removes any duplicate files found. Defaults to True.
    verbose : bool, optional
        If True, prints progress messages. Defaults to True.
    index_file_ending : str, optional
        The ending for index files. Defaults to '.tmtgp.index'.
    index_root : str, optional
        The path to the root folder containing all index files. Defaults to 'index'.
    create_dir : bool, optional
        If True, creates the index directory if it doesn't exist. Defaults to True.

    Returns
    -------
    Tuple[List[str], Dict[str, str]]
        A tuple containing:
        - file_paths: List of found file paths
        - index_paths: Dictionary mapping file paths to their index file paths
    """
    file_paths = find_files(
        folders=folders,
        endings=endings,
        followlinks=followlinks,
        remove_duplicated_files=remove_duplicated_files,
        verbose=verbose,
    )
    
    index_paths = get_index_paths(
        file_paths=file_paths,
        index_file_ending=index_file_ending,
        index_root=index_root,
        verbose=verbose,
        create_dir=create_dir,
    )
    
    return file_paths, index_paths