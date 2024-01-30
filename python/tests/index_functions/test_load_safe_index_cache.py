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
    def test_get_cache_file_name_no_root(self):
        # Test the get_cache_file_name() function with no index root
        # and a folder path and index name specified.
        index_file1 = index_functions.get_cache_file_name(
            folder_path="folder_path",
            cache_root=None,
            cache_name="cache_name",
            create_dir=False
        )
        
        # Test the get_cache_file_name() function with an index root
        # and a folder path and index name specified.
        index_file2 = index_functions.get_cache_file_name(
            folder_path="folder_path",
            cache_root='cache_root',
            cache_name="cache_name",
            create_dir=False
        )
        
        # Get the current working directory.
        base_path = Path.cwd()       

        # Create a Path object for the index path.
        index_path = Path(base_path) / Path("cache_root")

            
        index_file = Path(os.path.abspath('cache_root'))
        folder_path = Path(os.path.abspath('folder_path'))
        root_path = 'root_' + folder_path.parts[0]
        root_path = root_path.replace(':', '')

        expected_result = index_file.joinpath(root_path, *folder_path.parts[1:], "cache_name")

        
        # Check that the function returns the expected results.
        assert index_file1 == Path("folder_path/cache_name")
        assert index_file2 == expected_result
        