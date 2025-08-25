// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {

int t_KongsbergAllActiveSensor_to_attitude_sensor_number(t_KongsbergAllActiveSensor value)
{
    switch (value)
    {
        case t_KongsbergAllActiveSensor::AttitudeVelocitySensor1:
            [[fallthrough]];
        case t_KongsbergAllActiveSensor::MotionSensor1:
            return 1;
        case t_KongsbergAllActiveSensor::AttitudeVelocitySensor2:
            [[fallthrough]];
        case t_KongsbergAllActiveSensor::MotionSensor2:
            return 2;
        default:
            return 0;
    }
}

std::string datagram_type_to_string(t_KongsbergAllDatagramIdentifier value)
{
    // convert to string using magic enum
    return std::string(magic_enum::enum_name(value));
}

t_KongsbergAllDatagramIdentifier KongsbergAllDatagram_type_from_string(
    std::string_view value)
{
    // convert to datagram type using magic enum
    return magic_enum::enum_cast<t_KongsbergAllDatagramIdentifier>(value).value_or(
        t_KongsbergAllDatagramIdentifier::unspecified);
}

} // namespace kongsbergall

// ----- interface functions -----

std::string datagram_identifier_to_string(
    kongsbergall::t_KongsbergAllDatagramIdentifier value)
{
    return kongsbergall::datagram_type_to_string(value);
}

std::string datagram_identifier_info(
    kongsbergall::t_KongsbergAllDatagramIdentifier datagram_type)
{
    return fmt::format("{:x}", uint8_t(datagram_type));
}

std::vector<std::string> datagram_identifiers_to_string(
    const std::vector<kongsbergall::t_KongsbergAllDatagramIdentifier>& values)
{
    std::vector<std::string> result;
    for (auto value : values)
    {
        result.push_back(datagram_identifier_to_string(value));
    }
    return result;
}

std::vector<std::string> datagram_identifiers_to_string(
    const std::set<kongsbergall::t_KongsbergAllDatagramIdentifier>& values)
{
    std::vector<std::string> result;
    for (auto value : values)
    {
        result.push_back(datagram_identifier_to_string(value));
    }
    return result;
}

} // namespace echosounders
} // namespace themachinethatgoesping