# SPDX-FileCopyrightText: 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: MPL-2.0

import os
from pathlib import Path

def get_index_file_name(folder_path, 
                        index_root, 
                        index_name) -> Path:
    
    if index_root is None:
            return Path(folder_path) / Path(index_name)
            
    index_file = Path(os.path.abspath(index_root))
    folder_path = Path(os.path.abspath(folder_path))
    root_path = 'root_' + folder_path.parts[0]

    index_file = index_file.joinpath(root_path, *folder_path.parts[1:], index_name)
    
    os.makedirs(index_file.parent, exist_ok = True)
    
    return index_file


def load_index_files(file_paths, 
                     force_new = False, 
                     index_name = 'tmtgp.index', 
                     index_root = 'index', 
                     update_index = None, 
                     verbose = False):
    
    if update_index is None:
        index = {}
    else:
        index = update_index
        
    loaded_index_files = set()
    
    # look for existing files in each folder
    for fp in file_paths:
        folder_path,file = os.path.split(fp)
        
        index_file = get_index_file_name(folder_path, index_root, index_name)            
        
        if index_file in loaded_index_files:
            continue
            
        loaded_index_files.add(index_file)
        
        if os.path.exists(index_file) and not force_new:
            if verbose:
                print('Open:', index_file)
            load_index = pickle.load(open(index_file,'rb'))
            index.update(load_index)
            
    return index

def update_index_files(cached_index_dict, force_new = False, index_name = 'tmtgp.index', index_root = 'index', verbose = False):
    
    # group index dict into per folder index files
    index_per_folder = defaultdict(dict)
    for k,v in cached_index_dict.items():
        folder_path,file = os.path.split(k)        
        index_file = get_index_file_name(folder_path, index_root, index_name)    
        index_per_folder[index_file].update({k:v})
        
    # write an index file into each folder
    for index_file, index in index_per_folder.items():
        if verbose:
            print(index_file)
        
        if not os.path.exists(index_file) or force_new:
            write_index = {}
        else:
            write_index = pickle.load(open(index_file,'rb'))
            
        write_index.update(index)
        pickle.dump(write_index, open(index_file,'wb'))
        