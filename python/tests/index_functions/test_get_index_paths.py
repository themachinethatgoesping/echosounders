# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2022 - 2023 
# Peter Urban, Ghent University

# ignore pylint warning protected-access
# pylint: disable=protected-access
# pylint: disable=no-self-use

from pathlib import Path
import os

from themachinethatgoesping.echosounders import index_functions
import tempfile


class Test_echosounders_index_functions:
    def test_get_index_file_name_no_root(self):
        # Test the get_index_path() function with no index root
        # and a folder path and index name specified.
        index_file1 = index_functions.get_index_path(
            file_path="folder_path/file.txt",
            index_root=None,
            index_file_ending=".index",
            create_dir=False
        )
        
        # Test the get_index_path() function with an index root
        # and a folder path and index name specified.
        index_file2 = index_functions.get_index_path(
            file_path="folder_path/file.txt",
            index_root='index_root',
            index_file_ending=".index",
            create_dir=False
        )
        
        # Get the current working directory.
        base_path = Path.cwd()       

        # Create a Path object for the index path.
        index_path = Path(base_path) / Path("index_root")

            
        index_file = Path(os.path.abspath('index_root'))
        file_path = Path(os.path.abspath('folder_path/file.txt'))
        root_path = 'root_' + file_path.parts[0]
        root_path = root_path.replace(':', '')

        expected_result = index_file.joinpath(root_path, *(Path(str(file_path) + ".index")).parts[1:])

        
        # Check that the function returns the expected results.
        assert Path(index_file1) == Path("folder_path/file.txt.index")
        assert index_file2 == str(expected_result)
        