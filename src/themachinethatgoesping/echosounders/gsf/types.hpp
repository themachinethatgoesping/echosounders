// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/types.doc.hpp"

#include <complex>

#include <fmt/core.h>
#include <magic_enum/magic_enum.hpp>

#include <themachinethatgoesping/tools/classhelper/option.hpp>

/**
 * @brief Type definitions for kongsberg .all types according to kongsberg em series datagram
 * formats specificaztion see also
 * https://www.kongsberg.com/contentassets/47d7f3d5d4fa4c1b980d9861d1c70c12/160692_em_datagram_formats.pdf
 *
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace gsf {

enum class t_GSFDatagramIdentifier : uint32_t
{
    // Multibeam data
    HEADER                 = 1,
    SWATH_BATHYMETRY       = 2,
    SOUND_VELOCITY_PROFILE = 3,
    PROCESSING_PARAMETERS  = 4,
    SENSOR_PARAMETERS      = 5,
    COMMENT                = 6,
    HISTORY                = 7,
    NAVIGATION_ERROR       = 8,
    SWATH_BATHY_SUMMARY    = 9,
    SINGLE_BEAM_SOUNDING   = 10,
    HV_NAVIGATION_ERROR    = 11,
    ATTITUDE               = 12,
    unspecified            = std::numeric_limits<uint32_t>::max(),
};

using o_GSFDatagramIdentifier =
    tools::classhelper::Option<t_GSFDatagramIdentifier, t_GSFDatagramIdentifier::unspecified>;

// ----- other enums -----

// inline std::string datagram_type_to_string(uint8_t value)
// {
//     return tools::helper::int_as_string<gsf_long>(value);
// }

inline std::string datagram_type_to_string(t_GSFDatagramIdentifier value)
{
    // convert to string using magic enum
    return std::string(magic_enum::enum_name(value));
}

inline t_GSFDatagramIdentifier GSFDatagram_type_from_string(std::string_view value)
{
    // convert to datagram type using magic enum
    return magic_enum::enum_cast<t_GSFDatagramIdentifier>(value).value_or(
        t_GSFDatagramIdentifier::unspecified);
}
} // namespace gsf

// ----- interface? -----
// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_datagram_identifier_to_string
inline std::string datagram_identifier_to_string(gsf::t_GSFDatagramIdentifier value)
{
    return gsf::datagram_type_to_string(value);
}

// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_datagram_identifier_info
inline std::string datagram_identifier_info(gsf::t_GSFDatagramIdentifier datagram_type)
{
    return fmt::format("{:x}", uint8_t(datagram_type));
}

} // namespace echosounders
} // namespace themachinethatgoesping

extern template struct themachinethatgoesping::tools::classhelper::Option<
    themachinethatgoesping::echosounders::gsf::t_GSFDatagramIdentifier,
    themachinethatgoesping::echosounders::gsf::t_GSFDatagramIdentifier::unspecified>;