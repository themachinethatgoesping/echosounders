// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "simradrawpingcommon.hpp"

#include <fmt/core.h>
#include <stdexcept>

// Include stream headers for template instantiations
#include <fstream>
#include "../../filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {

// ----- SimradRawPingCommon implementation -----

template<typename t_ifstream>
void SimradRawPingCommon<t_ifstream>::beam_selection_must_be_one(
    std::string_view                      method_name,
    const pingtools::BeamSampleSelection& selection) const
{
    if (selection.get_number_of_beams() == 1)
        if (selection.get_beam_numbers()[0] == 0)
            return;

    throw std::runtime_error(fmt::format(
        "{}: SimradRaw functions do not support beam selections yet!", __func__, method_name));
}

// ----- Explicit template instantiations -----
template class SimradRawPingCommon<std::ifstream>;
template class SimradRawPingCommon<filetemplates::datastreams::MappedFileStream>;

} // namespace filedatatypes
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
