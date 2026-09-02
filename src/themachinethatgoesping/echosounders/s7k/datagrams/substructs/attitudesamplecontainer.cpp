// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "attitudesamplecontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

const std::vector<AttitudeSample>& AttitudeSampleContainer::get_samples() const
{
    return _samples;
}

std::vector<AttitudeSample>& AttitudeSampleContainer::samples()
{
    return _samples;
}

void AttitudeSampleContainer::set_samples(const std::vector<AttitudeSample>& samples)
{
    _samples = samples;
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

size_t AttitudeSampleContainer::get_number_of_samples() const
{
    return _samples.size();
}

tools::classhelper::ObjectPrinter AttitudeSampleContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "AttitudeSampleContainer", float_precision, superscript_exponents);

    printer.register_value("number_of_samples", get_number_of_samples());

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
