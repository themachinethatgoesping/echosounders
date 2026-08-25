// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "networkattitudevelocitydatagramattitudescontainer.hpp"

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

const std::vector<NetworkAttitudeVelocityDatagramAttitude>&
NetworkAttitudeVelocityDatagramAttitudesContainer::get_attitudes() const
{
    return _attitudes;
}

std::vector<NetworkAttitudeVelocityDatagramAttitude>&
NetworkAttitudeVelocityDatagramAttitudesContainer::attitudes()
{
    return _attitudes;
}

void NetworkAttitudeVelocityDatagramAttitudesContainer::set_attitudes(
    const std::vector<NetworkAttitudeVelocityDatagramAttitude>& attitudes)
{
    _attitudes = attitudes;
}

xt::xtensor<float, 1> NetworkAttitudeVelocityDatagramAttitudesContainer::get_time_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>(
        [](const NetworkAttitudeVelocityDatagramAttitude& a) { return a.get_time(); }, indices);
}

xt::xtensor<int16_t, 1> NetworkAttitudeVelocityDatagramAttitudesContainer::get_roll_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<int16_t>(
        [](const NetworkAttitudeVelocityDatagramAttitude& a) { return a.get_roll(); }, indices);
}

xt::xtensor<int16_t, 1> NetworkAttitudeVelocityDatagramAttitudesContainer::get_pitch_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<int16_t>(
        [](const NetworkAttitudeVelocityDatagramAttitude& a) { return a.get_pitch(); }, indices);
}

xt::xtensor<int16_t, 1> NetworkAttitudeVelocityDatagramAttitudesContainer::get_heave_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<int16_t>(
        [](const NetworkAttitudeVelocityDatagramAttitude& a) { return a.get_heave(); }, indices);
}

xt::xtensor<uint16_t, 1> NetworkAttitudeVelocityDatagramAttitudesContainer::get_heading_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<uint16_t>(
        [](const NetworkAttitudeVelocityDatagramAttitude& a) { return a.get_heading(); }, indices);
}

xt::xtensor<uint16_t, 1>
NetworkAttitudeVelocityDatagramAttitudesContainer::get_number_of_bytes_in_input_datagram_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<uint16_t>(
        [](const NetworkAttitudeVelocityDatagramAttitude& a) {
            return a.get_number_of_bytes_in_input_datagram();
        },
        indices);
}

xt::xtensor<float, 1> NetworkAttitudeVelocityDatagramAttitudesContainer::get_time_in_seconds_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>(
        [](const NetworkAttitudeVelocityDatagramAttitude& a) { return a.get_time_in_seconds(); },
        indices);
}

xt::xtensor<float, 1> NetworkAttitudeVelocityDatagramAttitudesContainer::get_roll_in_degrees_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>(
        [](const NetworkAttitudeVelocityDatagramAttitude& a) { return a.get_roll_in_degrees(); },
        indices);
}

xt::xtensor<float, 1> NetworkAttitudeVelocityDatagramAttitudesContainer::get_pitch_in_degrees_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>(
        [](const NetworkAttitudeVelocityDatagramAttitude& a) { return a.get_pitch_in_degrees(); },
        indices);
}

xt::xtensor<float, 1> NetworkAttitudeVelocityDatagramAttitudesContainer::get_heave_in_meters_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>(
        [](const NetworkAttitudeVelocityDatagramAttitude& a) { return a.get_heave_in_meters(); },
        indices);
}

xt::xtensor<float, 1>
NetworkAttitudeVelocityDatagramAttitudesContainer::get_heading_in_degrees_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>(
        [](const NetworkAttitudeVelocityDatagramAttitude& a) { return a.get_heading_in_degrees(); },
        indices);
}

size_t NetworkAttitudeVelocityDatagramAttitudesContainer::get_number_of_attitudes() const
{
    return _attitudes.size();
}

tools::classhelper::ObjectPrinter NetworkAttitudeVelocityDatagramAttitudesContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "NetworkAttitudeVelocityDatagramAttitudesContainer", float_precision, superscript_exponents);

    printer.register_section("Attitudes (.attitudes)");
    printer.register_value(
        "attitudes (vector)", fmt::format("size={}", get_number_of_attitudes()), "attitudes");

    printer.register_container("time", get_time_tensor(), "ms");
    printer.register_container("roll", get_roll_tensor(), "0.01 deg");
    printer.register_container("pitch", get_pitch_tensor(), "0.01 deg");
    printer.register_container("heave", get_heave_tensor(), "cm");
    printer.register_container("heading", get_heading_tensor(), "0.01 deg");
    printer.register_container(
        "number_of_bytes_in_input_datagram", get_number_of_bytes_in_input_datagram_tensor(), "bytes");

    printer.register_section("processed");
    printer.register_value("number_of_attitudes", get_number_of_attitudes());
    printer.register_container("indices_sorted_by_time", get_indices_sorted_by_time());
    printer.register_container("time_in_seconds", get_time_in_seconds_tensor(), "s");
    printer.register_container("roll_in_degrees", get_roll_in_degrees_tensor(), "deg");
    printer.register_container("pitch_in_degrees", get_pitch_in_degrees_tensor(), "deg");
    printer.register_container("heave_in_meters", get_heave_in_meters_tensor(), "m");
    printer.register_container("heading_in_degrees", get_heading_in_degrees_tensor(), "deg");

    return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
