// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "kongsbergallfilehandler.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {

template<typename t_ifstream>
tools::classhelper::ObjectPrinter KongsbergAllFileHandler<t_ifstream>::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "KongsbergAllFileHandler", float_precision, superscript_exponents);

    auto interface_printer = t_base::__printer__(float_precision, superscript_exponents);

    printer.append(interface_printer);

    printer.register_section("Detected Pings");
    printer.append(
        _ping_interface->get_pings().__printer__(float_precision, superscript_exponents),
        false,
        '^');

    return printer;
}

// Explicit template instantiation for common stream types
template class KongsbergAllFileHandler<std::ifstream>;

} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
