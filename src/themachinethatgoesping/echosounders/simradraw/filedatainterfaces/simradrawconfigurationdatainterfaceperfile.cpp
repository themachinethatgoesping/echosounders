// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "simradrawconfigurationdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

template<typename t_ifstream>
tools::classhelper::ObjectPrinter
SimradRawConfigurationDataInterfacePerFile<t_ifstream>::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents)
{
    tools::classhelper::ObjectPrinter printer(
        this->class_name(), float_precision, superscript_exponents);

    // printer.register_section("DatagramInterface");
    printer.append(t_base::__printer__(float_precision, superscript_exponents));

    printer.register_section("SimradRawConfigurationDataInterfacePerFile");
    auto position_sources = this->get_position_sources();
    auto heading_sources  = this->get_heading_sources();
    auto attitude_sources = this->get_attitude_sources();
    auto depth_sources    = this->get_depth_sources();

    printer.register_string("Position source",
                            fmt::format("'{}'", position_sources[0].Name),
                            position_sources.size() < 2
                                ? ""
                                : fmt::format("Alternatives: {}", position_sources.size() - 1));
    printer.register_string("Heading source",
                            fmt::format("'{}'", heading_sources[0].Name),
                            heading_sources.size() < 2
                                ? ""
                                : fmt::format("Alternatives: {}", heading_sources.size() - 1));
    printer.register_string("Attitude source",
                            fmt::format("'{}'", attitude_sources[0].Name),
                            attitude_sources.size() < 2
                                ? ""
                                : fmt::format("Alternatives: {}", attitude_sources.size() - 1));
    printer.register_string("Depth source",
                            fmt::format("'{}'", depth_sources[0].Name),
                            depth_sources.size() < 2
                                ? ""
                                : fmt::format("Alternatives: {}", depth_sources.size() - 1));

    return printer;
}

// Explicit template instantiation for common stream types
template class SimradRawConfigurationDataInterfacePerFile<std::ifstream>;

} // namespace filedatainterfaces
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
