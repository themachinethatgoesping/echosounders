# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: MPL-2.0

# ignore pylint warning protected-access
# pylint: disable=protected-access
# pylint: disable=no-self-use

from themachinethatgoesping.echosounders import index_functions as ifunc


class Test_echosounders_index_functions:
    def test_get_index_file_name(self):
        index_file = ifunc.get_index_file_name(
            folder_path="folder_path",
            index_root=None,
            index_name="index_name",
        )
        
        # assert index_file == "index_root/index_name"
        
        
       