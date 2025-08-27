// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "kongsbergallconfigurationdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatainterfaces {

tools::classhelper::ObjectPrinter KongsbergAllConfigurationDataInterfacePerFile::__printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
{
    tools::classhelper::ObjectPrinter printer(
        this->class_name(), float_precision, superscript_exponents);

    // printer.register_section("DatagramInterface");
    printer.append(t_base::__printer__(float_precision, superscript_exponents));

    printer.register_section("KongsbergAllConfigurationDataInterfacePerFile");
    printer.register_value("_active_position_system_number", _active_position_system_number);
    printer.register_enum("_active_pitch_roll_sensor", _active_pitch_roll_sensor);
    printer.register_enum("_active_heave_sensor", _active_heave_sensor);
    printer.register_enum("_active_heading_sensor", _active_heading_sensor);
    // auto position_sources = this->get_position_sources();
    // auto heading_sources  = this->get_heading_sources();
    // auto attitude_sources = this->get_attitude_sources();
    // auto depth_sources    = this->get_depth_sources();

    // printer.register_string("Position source",
    //                         fmt::format("'{}'", position_sources[0].Name),
    //                         position_sources.size() < 2
    //                             ? ""
    //                             : fmt::format("Alternatives: {}", position_sources.size() -
    //                             1));
    // printer.register_string("Heading source",
    //                         fmt::format("'{}'", heading_sources[0].Name),
    //                         heading_sources.size() < 2
    //                             ? ""
    //                             : fmt::format("Alternatives: {}", heading_sources.size() -
    //                             1));
    // printer.register_string("Attitude source",
    //                         fmt::format("'{}'", attitude_sources[0].Name),
    //                         attitude_sources.size() < 2
    //                             ? ""
    //                             : fmt::format("Alternatives: {}", attitude_sources.size() -
    //                             1));
    // printer.register_string("Depth source",
    //                         fmt::format("'{}'", depth_sources[0].Name),
    //                         depth_sources.size() < 2
    //                             ? ""
    //                             : fmt::format("Alternatives: {}", depth_sources.size() - 1));

    return printer;
}

uint16_t KongsbergAllConfigurationDataInterfacePerFile::read_extra_info_serial_number(
    const typename t_base::type_DatagramInfo_ptr& datagram_ptr)
{
    if (datagram_ptr->get_extra_infos().size() != 4)
        throw std::runtime_error(fmt::format(
            "KongsbergAllPingConfigurationDataInterfacePerFile::read_extra_info_serial_number: "
            "DatagramInfoData: extra info for datagram {} at pos "
            "{} is not available",
            datagram_type_to_string(datagram_ptr->get_datagram_identifier()),
            datagram_ptr->get_file_pos()));

    // ping_counter  = datagram_ptr->template get_extra_info<uint16_t>(0);
    return datagram_ptr->template get_extra_info<uint16_t>(sizeof(uint16_t));
}

} // namespace filedatainterfaces
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
