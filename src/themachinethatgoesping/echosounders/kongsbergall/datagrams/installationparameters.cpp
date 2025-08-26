// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "installationparameters.hpp"

#include <fmt/core.h>
#include <magic_enum/magic_enum.hpp>
#include <stdexcept>
#include <algorithm>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

// ----- factory functions -----
InstallationParameters InstallationParameters::merge(InstallationParameters first, InstallationParameters second)
{
    static const std::array<const std::string, 2> uncritical_keys = {
        "RFN", // raw file name
        "SID"  // survey identifier
    };

    // use the datagram with the lower timestamp as base
    if (first.get_timestamp() > second.get_timestamp())
        std::swap(first, second);

    auto& params_first  = first._parsed_installation_parameters;
    auto& params_second = second._parsed_installation_parameters;

    // if both installation parameters are the same, return the first one
    if (params_first == params_second)
        return first;

    // check if the difference is caused by an uncritical key
    for (const auto& key : uncritical_keys)
    {
        const auto& f = params_first.find(key);
        const auto& s = params_second.find(key);

        if (f == params_first.end())
        {
            if (s == params_second.end())
                continue;

            params_first[key] = s->second;
        }
        else if (s == params_second.end())
        {
            params_second[key] = f->second;
        }
    }

    // if both installation parameters are the same now, return the first one
    if (params_first == params_second)
        return first;

    // list all keys that are missing in params_first
    std::string missing_keys_1, missing_keys_2;
    for (const auto& [key, value] : params_second)
    {
        if (params_first.find(key) == params_first.end())
            missing_keys_1 += key + " ";
    }

    // list all keys that are missing in params_second
    for (const auto& [key, value] : params_first)
    {
        if (params_second.find(key) == params_second.end())
            missing_keys_2 += key + " ";
    }

    // list all keys that are different
    std::string different_keys;
    for (const auto& [key, value] : params_first)
    {
        if (params_first.find(key) == params_first.end())
            continue;

        if (params_second.find(key) == params_second.end())
            continue;

        if (params_second.find(key) == params_second.end())
            continue;

        if (params_second[key] != value)
            different_keys += key + " ";
    }

    throw(std::runtime_error(
        fmt::format("InstallationParameters::merge: Installation parameters cannot be merged: "
                    "missing keys in first: {}"
                    "\nmissing keys in second: {}"
                    "\nkeys with different values: {}",
                    missing_keys_1,
                    missing_keys_2,
                    different_keys)));
}

bool InstallationParameters::is_dual_rx() const
{
    auto stc = get_system_transducer_configuration();

    switch (stc)
    {
        case t_KongsbergAllSystemTransducerConfiguration::SingleHead:
            [[fallthrough]];
        case t_KongsbergAllSystemTransducerConfiguration::PortableSingleHead:
            [[fallthrough]];
        case t_KongsbergAllSystemTransducerConfiguration::SingleTXSingleRX:
            return false;
        case t_KongsbergAllSystemTransducerConfiguration::SingleTXDualRX:
            return true;
        default:
            throw(std::runtime_error(fmt::format("InstallationParameters::is_dual_rx: "
                                                 "unsupported transducer configuration: {}",
                                                 magic_enum::enum_name(stc))));
    }
}

std::string InstallationParameters::build_channel_id() const
{
    std::string channel_id = "EM" + std::to_string(get_model_number());
    channel_id +=
        " " + std::string(magic_enum::enum_name(get_system_transducer_configuration()));
    channel_id += " " + std::to_string(this->get_system_serial_number());

    if (is_dual_rx())
        channel_id += "-" + std::to_string(this->get_secondary_system_serial_number());

    return channel_id;
}

t_KongsbergAllSystemTransducerConfiguration InstallationParameters::get_system_transducer_configuration() const
{
    unsigned int val = get_value_int("STC", 0);

    if (val > 6)
        throw(std::runtime_error(
            fmt::format("InstallationParameters::get_system_transducer_configuration: "
                        "invalid transducer configuration: {}",
                        val)));

    return t_KongsbergAllSystemTransducerConfiguration(val);
}

std::string InstallationParameters::get_tx_array_size() const
{
    switch (get_value_string("S1S", "")[0])
    {
        case '0':
            return "0.5°";
        case '1':
            return "1°";
        case '2':
            return "2°";
        default:
            return "Unknown";
    }
}

std::string InstallationParameters::get_rx_array_size() const
{
    switch (get_value_string("S2S", "")[0])
    {
        case '0':
            return "0.5°";
        case '1':
            return "1°";
        case '2':
            return "2°";
        default:
            return "Unknown";
    }
}

t_KongsbergAllActiveSensor InstallationParameters::get_active_pitch_roll_sensor() const
{
    std::string active_sensor = get_value_string("ARO");

    switch (active_sensor[0])
    {
        case '2':
            return t_KongsbergAllActiveSensor::MotionSensor1;
        case '3':
            return t_KongsbergAllActiveSensor::MotionSensor2;
        case '8':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor1;
        case '9':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor2;
        default:
            throw std::invalid_argument(fmt::format("get_active_pitch_roll_sensor: Invalid "
                                                    "active roll pitch sensor: {} (must be "
                                                    "2, 3, 8 or 9)",
                                                    active_sensor));
    }
}

t_KongsbergAllActiveSensor InstallationParameters::get_active_heave_sensor() const
{
    std::string active_sensor = get_value_string("AHE");

    switch (active_sensor[0])
    {
        case '2':
            return t_KongsbergAllActiveSensor::MotionSensor1;
        case '3':
            return t_KongsbergAllActiveSensor::MotionSensor2;
        case '8':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor1;
        case '9':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor2;
        default:
            throw std::invalid_argument(fmt::format("get_active_heave_sensor: Invalid "
                                                    "active roll pitch sensor: {} (must be "
                                                    "2, 3, 8 or 9)",
                                                    active_sensor));
    }
}

t_KongsbergAllActiveSensor InstallationParameters::get_active_heading_sensor() const
{
    std::string active_sensor = get_value_string("AHE");

    switch (active_sensor[0])
    {
        case '0':
            return t_KongsbergAllActiveSensor::PositionSystem3; // COM4
        case '1':
            return t_KongsbergAllActiveSensor::PositionSystem1; // COM1
        case '2':
            return t_KongsbergAllActiveSensor::MotionSensor1; // COM2
        case '3':
            return t_KongsbergAllActiveSensor::MotionSensor2; // COM3
        case '4':
            return t_KongsbergAllActiveSensor::PositionSystem3; // UDP2
        case '5':
            return t_KongsbergAllActiveSensor::MultiCast1;
        case '6':
            return t_KongsbergAllActiveSensor::MultiCast2;
        case '7':
            return t_KongsbergAllActiveSensor::MultiCast3;
        case '8':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor1;
        case '9':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor2;
        default:
            throw std::invalid_argument(fmt::format("get_active_heading_sensor: Invalid "
                                                    "active roll pitch sensor: {} (must be "
                                                    "0-9)",
                                                    active_sensor));
    }
}

uint8_t InstallationParameters::get_active_attitude_velocity_sensor() const
{
    return std::stoi(get_value_string("VSN"));
}
