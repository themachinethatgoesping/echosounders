// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "sampleamplitudesstructure.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

float SampleAmplitudesStructure::get_db_step_size() const
{
    return _db_step_size;
}

const xt::xtensor<t_sample, 1>& SampleAmplitudesStructure::get_sample_amplitudes() const
{
    return _sample_amplitudes;
}

const std::vector<uint16_t>& SampleAmplitudesStructure::get_start_index_per_beam() const
{
    return _start_index_per_beam;
}

const std::vector<uint16_t>& SampleAmplitudesStructure::get_samples_per_beam() const
{
    return _samples_per_beam;
}

void SampleAmplitudesStructure::set_db_step_size(float db_step_size)
{
    _db_step_size = db_step_size;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
