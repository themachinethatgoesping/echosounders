// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "kmallmultibeamdatagram.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

// ----- objectprinter -----

tools::classhelper::ObjectPrinter KMALLMultibeamDatagram::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "KMALLMultibeamDatagram", float_precision, superscript_exponents);

    printer.append(KMALLDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("bytes_content", _scommon.bytes_content);
    printer.register_value("ping_count", _scommon.ping_count);
    printer.register_value("rx_fans_per_ping", _scommon.rx_fans_per_ping);
    printer.register_value("rx_fan_index", _scommon.rx_fan_index);
    printer.register_value("swaths_per_ping", _scommon.swaths_per_ping);
    printer.register_value("swath_along_position", _scommon.swath_along_position);
    printer.register_value("tx_transducer_ind", _scommon.tx_transducer_ind);
    printer.register_value("rx_transducer_ind", _scommon.rx_transducer_ind);
    printer.register_value("number_of_rx_transducers", _scommon.number_of_rx_transducers);
    printer.register_value("algorithm_type", _scommon.algorithm_type);
    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
