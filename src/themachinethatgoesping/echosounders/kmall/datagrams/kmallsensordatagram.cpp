// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "kmallsensordatagram.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

// ----- objectprinter -----

tools::classhelper::ObjectPrinter KMALLSensorDatagram::__printer__(unsigned int float_precision,
                                                                   bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "KMALLSensorDatagram", float_precision, superscript_exponents);

    printer.append(KMALLDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("bytes_content", _bytes_content);
    printer.register_value("sensor_system", _sensor_system);
    printer.register_value("sensor_status", _sensor_status);
    printer.register_value("padding", _padding);
    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
