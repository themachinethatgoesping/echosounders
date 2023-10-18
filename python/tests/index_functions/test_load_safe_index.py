# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2022 - 2023 
# Peter Urban, Ghent University

# ignore pylint warning protected-access
# pylint: disable=protected-access
# pylint: disable=no-self-use

from pathlib import Path

from themachinethatgoesping.echosounders import index_functions
import tempfile


class Test_echosounders_index_functions:
    def test_get_index_file_name_no_root(self):
        # Test the get_index_file_name() function with no index root
        # and a folder path and index name specified.
        index_file1 = index_functions.get_index_file_name(
            folder_path="folder_path",
            index_root=None,
            index_name="index_name",
            create_dir=False
        )
        
        # Test the get_index_file_name() function with an index root
        # and a folder path and index name specified.
        index_file2 = index_functions.get_index_file_name(
            folder_path="folder_path",
            index_root='index_root',
            index_name="index_name",
            create_dir=False
        )
        
        # Get the current working directory.
        base_path = Path.cwd()       

        # Create a Path object for the index path.
        index_path = Path(base_path) / Path("index_root")

        # Create a root path based on the first part of the current working directory.
        root_path = 'root_' + base_path.parts[0]

        # Create the expected result by joining the index path, root path, and folder path and index name.
        expected_result = index_path.joinpath(root_path, *base_path.parts[1:], 'folder_path', 'index_name')
        
        # Check that the function returns the expected results.
        assert index_file1 == Path("folder_path/index_name")
        assert index_file2 == expected_result
        