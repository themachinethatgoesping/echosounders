// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "attitudedatagramattitudescontainer.hpp"

#include <fmt/core.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

const std::vector<AttitudeDatagramAttitude>&
AttitudeDatagramAttitudesContainer::get_attitudes() const
{
    return _attitudes;
}

std::vector<AttitudeDatagramAttitude>& AttitudeDatagramAttitudesContainer::attitudes()
{
    return _attitudes;
}

void AttitudeDatagramAttitudesContainer::set_attitudes(
    const std::vector<AttitudeDatagramAttitude>& attitudes)
{
    _attitudes = attitudes;
}

xt::xtensor<float, 1> AttitudeDatagramAttitudesContainer::get_time_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>([](const AttitudeDatagramAttitude& a) { return a.get_time(); },
                               indices);
}

xt::xtensor<uint16_t, 1> AttitudeDatagramAttitudesContainer::get_sensor_status_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<uint16_t>(
        [](const AttitudeDatagramAttitude& a) { return a.get_sensor_status(); }, indices);
}

xt::xtensor<int16_t, 1> AttitudeDatagramAttitudesContainer::get_roll_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<int16_t>([](const AttitudeDatagramAttitude& a) { return a.get_roll(); },
                                 indices);
}

xt::xtensor<int16_t, 1> AttitudeDatagramAttitudesContainer::get_pitch_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<int16_t>(
        [](const AttitudeDatagramAttitude& a) { return a.get_pitch(); }, indices);
}

xt::xtensor<int16_t, 1> AttitudeDatagramAttitudesContainer::get_heave_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<int16_t>([](const AttitudeDatagramAttitude& a) { return a.get_heave(); },
                                 indices);
}

xt::xtensor<uint16_t, 1> AttitudeDatagramAttitudesContainer::get_heading_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<uint16_t>(
        [](const AttitudeDatagramAttitude& a) { return a.get_heading(); }, indices);
}

xt::xtensor<float, 1> AttitudeDatagramAttitudesContainer::get_time_in_seconds_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>(
        [](const AttitudeDatagramAttitude& a) { return a.get_time_in_seconds(); }, indices);
}

xt::xtensor<float, 1> AttitudeDatagramAttitudesContainer::get_roll_in_degrees_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>(
        [](const AttitudeDatagramAttitude& a) { return a.get_roll_in_degrees(); }, indices);
}

xt::xtensor<float, 1> AttitudeDatagramAttitudesContainer::get_pitch_in_degrees_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>(
        [](const AttitudeDatagramAttitude& a) { return a.get_pitch_in_degrees(); }, indices);
}

xt::xtensor<float, 1> AttitudeDatagramAttitudesContainer::get_heave_in_meters_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>(
        [](const AttitudeDatagramAttitude& a) { return a.get_heave_in_meters(); }, indices);
}

xt::xtensor<float, 1> AttitudeDatagramAttitudesContainer::get_heading_in_degrees_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<float>(
        [](const AttitudeDatagramAttitude& a) { return a.get_heading_in_degrees(); }, indices);
}

size_t AttitudeDatagramAttitudesContainer::get_number_of_attitudes() const
{
    return _attitudes.size();
}

tools::classhelper::ObjectPrinter AttitudeDatagramAttitudesContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "AttitudeDatagramAttitudesContainer", float_precision, superscript_exponents);

    printer.register_section("Attitudes (.attitudes)");
    printer.register_value(
        "attitudes (vector)", fmt::format("size={}", get_number_of_attitudes()), "attitudes");

    printer.register_container("time", get_time_tensor(), "ms");
    printer.register_container("sensor_status", get_sensor_status_tensor());
    printer.register_container("roll", get_roll_tensor(), "0.01deg");
    printer.register_container("pitch", get_pitch_tensor(), "0.01deg");
    printer.register_container("heave", get_heave_tensor(), "cm");
    printer.register_container("heading", get_heading_tensor(), "0.01deg");

    printer.register_section("processed");
    printer.register_value("number_of_attitudes", get_number_of_attitudes());
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
