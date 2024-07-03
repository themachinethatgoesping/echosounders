# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: MPL-2.0

# ignore pylint warning protected-access
# pylint: disable=protected-access
# pylint: disable=no-self-use

import logging
import themachinethatgoesping as Ping
from themachinethatgoesping.echosounders import kongsbergall



LOGGER = logging.getLogger(__name__)

class Test_echosounders_kongsbergall_KongsbergAllDatagram:
    
    def __init__(self):
        self.test_folders = '../../../unittest_data/'

        LOGGER.info(f'findings test files in {self.test_folders}')
        self.files = Ping.echosounders.index_functions.find_files(self.test_folders)
        self.cache_files = Ping.echosounders.index_functions.find_files(self.test_folders, 'cache')

    def clean_cache(self):
        LOGGER.info(f'Cleaning up cache files')
        for file in self.cache_files:
            os.remove(file)

    def test_open_files(self):
        # binary
        
        assert True
