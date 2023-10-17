# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: MPL-2.0

# ignore pylint warning protected-access
# pylint: disable=protected-access
# pylint: disable=no-self-use

from pathlib import Path

from themachinethatgoesping.echosounders import index_functions


class Test_echosounders_index_functions:
    def test_get_index_file_name(self):
        index_file1 = index_functions.get_index_file_name(
            folder_path="folder_path",
            index_root=None,
            index_name="index_name",
            create_dir = False
        )
        
        index_file2 = index_functions.get_index_file_name(
            folder_path="folder_path",
            index_root='index_root',
            index_name="index_name",
            create_dir = False
        )
        
        base_path = Path.cwd()
        # get base path without root as single Path object
        base_path_no_root = Path("")
        for p in Path.cwd().parts[1:]:
            base_path_no_root = base_path_no_root / Path(p)
        expected_result = Path(base_path) / Path("index_root") / Path("root_") / Path(base_path_no_root) / Path("folder_path/index_name")
        
        assert index_file1 == Path("folder_path/index_name")
        assert index_file2 == expected_result
        
        
       