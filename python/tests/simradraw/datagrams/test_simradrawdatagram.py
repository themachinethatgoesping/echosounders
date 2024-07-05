# SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University
#
# SPDX-License-Identifier: MPL-2.0

# ignore pylint warning protected-access
# pylint: disable=protected-access
# pylint: disable=no-self-use

from themachinethatgoesping.echosounders import simradraw
SimradRawDatagram = simradraw.datagrams.SimradRawDatagram


class Test_echosounders_simradraw_SimradRawDatagram:
    def test_SimradRawDatagram_should_support_common_functions(self):
        dat = SimradRawDatagram()
        dat.set_length(100)
        dat.set_datagram_type(810306904)
        dat.set_low_date_time(10)
        dat.set_high_date_time(20)

        print(dat)

        # print
        assert len(str(dat)) != 0
        assert "XML0" in str(dat)

        # copy
        dat2 = dat.copy()
        assert dat == dat2
        dat2.set_length(12)
        assert dat != dat2

        # binary
        assert dat == SimradRawDatagram.from_binary(dat.to_binary())
