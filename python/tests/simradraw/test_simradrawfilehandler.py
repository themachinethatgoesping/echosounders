# SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University
#
# SPDX-License-Identifier: MPL-2.0

# ignore pylint warning protected-access
# pylint: disable=protected-access
# pylint: disable=no-self-use

import os
import logging
import themachinethatgoesping as theping
from themachinethatgoesping.echosounders import simradraw


LOGGER = logging.getLogger(__name__)


class Test_echosounders_simradraw_SimradRawFileHandler:
    files = None

    def find_files(self):
        if self.files is not None:
            return

        dirname = os.path.dirname(__file__)
        self.test_folders = os.path.join(dirname, "../../../unittest_data/")

        LOGGER.info(f"findings test files in {self.test_folders}")
        self.files = theping.echosounders.index_functions.find_files(self.test_folders, ".raw")
        self.files.sort()
        self.index_files = theping.echosounders.index_functions.get_index_paths(self.files)

        assert len(self.files) > 0
        assert len(self.index_files) > 0

    def clean_index(self):
        LOGGER.info(f"Cleaning up cache files")
        for file in self.index_files:
            os.remove(file)

    def open_files_and_loop_through_pings(self, file, cache=False):
        if cache:
            fm = simradraw.SimradRawFileHandler(file, index_paths=self.index_files, show_progress=False)
        else:
            fm = simradraw.SimradRawFileHandler(file, show_progress=False)

        for d in fm.datagram_interface.datagrams():
            d.get_timestamp()

        for pnr,ping in enumerate(fm.get_pings()):
            try:
                theping.echosounders.evaluate_ping_features_can_be_called(ping)
            except Exception as e:
                LOGGER.error(f"Error for file: {file}")
                LOGGER.error(f"Error for ping number : {pnr}")
                LOGGER.error(f"Error: {e}")
                raise e

        return fm.get_pings()

    def test_open_files_should_not_crash(self):
        self.find_files()

        # individually open all files and loop through all pings
        for file in self.files:
            LOGGER.info(f"Opening {file}")
            assert len(self.open_files_and_loop_through_pings(file, cache=False)) > 0
            assert len(self.open_files_and_loop_through_pings(file, cache=True)) > 0
            assert len(self.open_files_and_loop_through_pings(file, cache=True)) > 0
            assert len(self.open_files_and_loop_through_pings(file, cache=False)) > 0

        # open all files at once and loop through all pings
        assert len(self.open_files_and_loop_through_pings(self.files, cache=False)) > 0
        assert len(self.open_files_and_loop_through_pings(self.files, cache=True)) > 0
        assert len(self.open_files_and_loop_through_pings(self.files, cache=True)) > 0
        assert len(self.open_files_and_loop_through_pings(self.files, cache=False)) > 0
