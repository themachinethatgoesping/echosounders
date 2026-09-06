// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "attitudesamplecontainer.hpp"
#include <xtensor/core/xmath.hpp> // for xt::rad2deg

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

const std::vector<AttitudeSample>& AttitudeSampleContainer::get_attitudes() const
{
    return _attitudes;
}

std::vector<AttitudeSample>& AttitudeSampleContainer::attitudes()
{
    return _attitudes;
}

void AttitudeSampleContainer::set_attitudes(const std::vector<AttitudeSample>& attitudes)
{
    _attitudes = attitudes;
}

xt::xtensor<uint16_t, 1> AttitudeSampleContainer::get_delta_time_tensor() const
{
    return build_tensor<uint16_t>(
        [](const AttitudeSample& sample) { return sample.get_delta_time(); });
}

xt::xtensor<float, 1> AttitudeSampleContainer::get_roll_tensor() const
{
    return build_tensor<float>([](const AttitudeSample& sample) { return sample.get_roll(); });
}

xt::xtensor<float, 1> AttitudeSampleContainer::get_pitch_tensor() const
{
    return build_tensor<float>([](const AttitudeSample& sample) { return sample.get_pitch(); });
}

xt::xtensor<float, 1> AttitudeSampleContainer::get_heave_tensor() const
{
    return build_tensor<float>([](const AttitudeSample& sample) { return sample.get_heave(); });
}

xt::xtensor<float, 1> AttitudeSampleContainer::get_heading_tensor() const
{
    return build_tensor<float>([](const AttitudeSample& sample) { return sample.get_heading(); });
}

size_t AttitudeSampleContainer::get_number_of_attitudes() const
{
    return _attitudes.size();
}

// ----- processed -----
xt::xtensor<double, 1> AttitudeSampleContainer::get_delta_time_in_seconds_tensor() const
{
    return build_tensor<uint16_t>(
               [](const AttitudeSample& sample) { return sample.get_delta_time(); }) *
           0.001;
}

xt::xtensor<float, 1> AttitudeSampleContainer::get_roll_in_degrees_tensor() const
{
    return xt::rad2deg(
        build_tensor<float>([](const AttitudeSample& sample) { return sample.get_roll(); }));
}

xt::xtensor<float, 1> AttitudeSampleContainer::get_pitch_in_degrees_tensor() const
{
    return xt::rad2deg(
        build_tensor<float>([](const AttitudeSample& sample) { return sample.get_pitch(); }));
}

xt::xtensor<float, 1> AttitudeSampleContainer::get_heading_in_degrees_tensor() const
{
    return xt::rad2deg(
        build_tensor<float>([](const AttitudeSample& sample) { return sample.get_heading(); }));
}

tools::classhelper::ObjectPrinter AttitudeSampleContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "AttitudeSampleContainer", float_precision, superscript_exponents);

    printer.register_section("Attitudes (.attitudes)");
    printer.register_value(
        "attitudes (vector)", fmt::format("size={}", get_number_of_attitudes()), "attitudes");

    printer.register_container("delta_time_tensor", get_delta_time_tensor(), "ms");
    printer.register_container("roll_tensor", get_roll_tensor(), "rad");
    printer.register_container("pitch_tensor", get_pitch_tensor(), "rad");
    printer.register_container("heave_tensor", get_heave_tensor(), "m");
    printer.register_container("heading_tensor", get_heading_tensor(), "rad");

    printer.register_section("processed");
    printer.register_container(
        "delta_time_in_seconds_tensor", get_delta_time_in_seconds_tensor(), "s");
    printer.register_container("roll_in_degrees_tensor", get_roll_in_degrees_tensor(), "deg");
    printer.register_container("pitch_in_degrees_tensor", get_pitch_in_degrees_tensor(), "deg");
    printer.register_container("heading_in_degrees_tensor", get_heading_in_degrees_tensor(), "deg");

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
