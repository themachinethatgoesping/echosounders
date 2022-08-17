# SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
#
# SPDX-License-Identifier: MPL-2.0

# ignore pylint warning protected-access
# pylint: disable=protected-access

from themachinethatgoesping.echosounders.simrad.datagrams import EK60_Datagram


class Test_navigation_EK60_Datagram:
    def test_EK60_Datagram_should_support_common_functions(self):
        dat = EK60_Datagram()
        dat._Length = 100
        dat._DatagramType = 1234
        dat._LowDateTime = 10
        dat._HighDateTime = 20

        print(dat)

        # print
        assert len(str(dat)) != 0

        # copy
        dat2 = dat.copy()
        assert dat == dat2
        dat2._Length = 12
        assert dat != dat2

        # binary
        assert dat == EK60_Datagram.from_binary(dat.to_binary())
