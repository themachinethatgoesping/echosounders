// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mwcsectorinfo.hpp"

#include <fmt/format.h>

#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

bool MWCSectorInfo::operator==(const MWCSectorInfo& other) const
{
    using themachinethatgoesping::tools::helper::float_equals;
    return float_equals(_tilt_angle_re_tx_deg, other._tilt_angle_re_tx_deg) &&
           float_equals(_centre_frequency_hz, other._centre_frequency_hz) &&
           float_equals(_tx_beam_width_along_deg, other._tx_beam_width_along_deg) &&
           _tx_sector_number == other._tx_sector_number && _padding == other._padding;
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MWCSectorInfo::__printer__(unsigned int float_precision,
                                                             bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MWCSectorInfo", float_precision, superscript_exponents);

    printer.register_value("tilt_angle_re_tx_deg", _tilt_angle_re_tx_deg, "deg");
    printer.register_value("centre_frequency_hz", _centre_frequency_hz, "Hz");
    printer.register_value("tx_beam_width_along_deg", _tx_beam_width_along_deg, "deg");
    printer.register_value("tx_sector_number", _tx_sector_number);
    printer.register_value("padding", _padding);

    return printer;
}

}
}
}
}
}
