// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "types.hpp"

namespace themachinethatgoesping {
namespace echosounders {

std::vector<std::string> datagram_identifiers_to_string(
    const std::set<kmall::t_KMALLDatagramIdentifier>& datagram_identifiers)
{
    std::vector<std::string> result;
    result.reserve(datagram_identifiers.size());
    for (const auto& datagram_identifier : datagram_identifiers)
    {
        result.push_back(datagram_identifier_to_string(datagram_identifier));
    }
    return result;
}

// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_datagram_identifier_info
std::string datagram_identifier_info(kmall::t_KMALLDatagramIdentifier datagram_identifier)
{
    // this should work, but doesn't
    return std::string(kmall::o_KMALLDatagramIdentifier(datagram_identifier).name());
}

}
}

template class themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier,
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_values.size(),
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_values,
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_names,
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_alt_names>;