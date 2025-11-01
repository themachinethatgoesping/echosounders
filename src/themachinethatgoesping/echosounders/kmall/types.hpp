// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/types.doc.hpp"

#include <bit>
#include <complex>

#include <fmt/core.h>
#include <magic_enum/magic_enum.hpp>

#include <themachinethatgoesping/tools/classhelper/option_frozen.hpp>
#include <themachinethatgoesping/tools/helper/stringconversion.hpp>

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
namespace kmall {

// Constexpr function to convert 4-char string to uint32_t at compile time
constexpr uint32_t c_DGM2Int(const char five_chars[5])
{
    // Use first 4 bytes, ignore the null terminator
    std::array<char, 4> four_chars = { five_chars[0], five_chars[1], five_chars[2], five_chars[3] };
    return std::bit_cast<uint32_t>(four_chars);
}

enum class t_KMALLDatagramIdentifier : uint32_t
{
    // I-datagrams (Installation)
    I_INSTALLATION_PARAM = c_DGM2Int("#IIP"),
    I_OP_RUNTIME         = c_DGM2Int("#IOP"),

    // S-datagrams (Sensor)
    S_POSITION                  = c_DGM2Int("#SPO"),
    S_POSITION_ERROR            = c_DGM2Int("#SPE"),
    S_POSITION_DATUM            = c_DGM2Int("#SPD"),
    S_KM_BINARY                 = c_DGM2Int("#SKM"),
    S_SOUND_VELOCITY_PROFILE    = c_DGM2Int("#SVP"),
    S_SOUND_VELOCITY_TRANSDUCER = c_DGM2Int("#SVT"),
    S_CLOCK                     = c_DGM2Int("#SCL"),
    S_DEPTH                     = c_DGM2Int("#SDE"),
    S_HEIGHT                    = c_DGM2Int("#SHI"),

    // M-datagrams (Multibeam)
    M_RANGE_AND_DEPTH = c_DGM2Int("#MRZ"),
    M_WATER_COLUMN    = c_DGM2Int("#MWC"),

    // C-datagrams (Compatibility)
    C_POSITION = c_DGM2Int("#CPO"),
    C_HEAVE    = c_DGM2Int("#CHE"),

    // F-datagrams (File)
    F_CALIBRATION_FILE = c_DGM2Int("#FCF"),

    unspecified = std::numeric_limits<uint32_t>::max(),
};

static constexpr std::array<t_KMALLDatagramIdentifier, 16> t_KMALLDatagramIdentifier_values = {
    t_KMALLDatagramIdentifier::I_INSTALLATION_PARAM,
    t_KMALLDatagramIdentifier::I_OP_RUNTIME,
    t_KMALLDatagramIdentifier::S_POSITION,
    t_KMALLDatagramIdentifier::S_POSITION_ERROR,
    t_KMALLDatagramIdentifier::S_POSITION_DATUM,
    t_KMALLDatagramIdentifier::S_KM_BINARY,
    t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_PROFILE,
    t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_TRANSDUCER,
    t_KMALLDatagramIdentifier::S_CLOCK,
    t_KMALLDatagramIdentifier::S_DEPTH,
    t_KMALLDatagramIdentifier::S_HEIGHT,
    t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH,
    t_KMALLDatagramIdentifier::M_WATER_COLUMN,
    t_KMALLDatagramIdentifier::C_POSITION,
    t_KMALLDatagramIdentifier::C_HEAVE,
    t_KMALLDatagramIdentifier::F_CALIBRATION_FILE
};

static constexpr std::array<std::string_view, 16> t_KMALLDatagramIdentifier_names = {
    "I_INSTALLATION_PARAM",
    "I_OP_RUNTIME",
    "S_POSITION",
    "S_POSITION_ERROR",
    "S_POSITION_DATUM",
    "S_KM_BINARY",
    "S_SOUND_VELOCITY_PROFILE",
    "S_SOUND_VELOCITY_TRANSDUCER",
    "S_CLOCK",
    "S_DEPTH",
    "S_HEIGHT",
    "M_RANGE_AND_DEPTH",
    "M_WATER_COLUMN",
    "C_POSITION",
    "C_HEAVE",
    "F_CALIBRATION_FILE"
};
static constexpr std::array<std::string_view, 16> t_KMALLDatagramIdentifier_alt_names = {
    "#IIP", "#IOP", "#SPO", "#SPE", "#SPD", "#SKM", "#SVP", "#SVT",
    "#SCL", "#SDE", "#SHI", "#MRZ", "#MWC", "#CPO", "#CHE", "#FCF"
};

using o_KMALLDatagramIdentifier = themachinethatgoesping::tools::classhelper::OptionFrozen<
    t_KMALLDatagramIdentifier,
    t_KMALLDatagramIdentifier_values.size(),
    t_KMALLDatagramIdentifier_values,
    t_KMALLDatagramIdentifier_names,
    t_KMALLDatagramIdentifier_alt_names>;
/**
 * @brief Convert datagram type from uint32_t to string representation.
 * @param value Datagram type as uint32_t.
 * @return String representation (decimal) of the datagram type.
 */
inline std::string datagram_type_to_string(uint32_t value)
{
    return tools::helper::int_as_string<uint32_t>(value);
}

/**
 * @brief Convert datagram type identifier to string representation.
 * @param value Datagram type identifier enum.
 * @return String representation (decimal) of the datagram type.
 */
inline std::string datagram_type_to_string(t_KMALLDatagramIdentifier value)
{
    return tools::helper::int_as_string<uint32_t>(uint32_t(value));
}

/**
 * @brief Parse datagram type from string representation.
 * @param value String view containing decimal representation.
 * @return Parsed datagram type numeric value.
 */
inline uint32_t KMALLDatagram_type_from_string(std::string_view value)
{
    return tools::helper::string_as_int<uint32_t>(value);
}

} // namespace kmall

// ----- interface utility functions -----

// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_datagram_identifier_to_string
/**
 * @brief Convert datagram identifier enum to string.
 * @param value Datagram identifier.
 * @return Decimal string representation.
 */
inline std::string datagram_identifier_to_string(kmall::t_KMALLDatagramIdentifier value)
{
    return tools::helper::int_as_string<uint32_t>(uint32_t(value));
}

//IGNORE_DOC:__doc_themachinethatgoesping_echosounders_datagram_identifiers_to_string
/**
 * @brief Convert vector of datagram identifiers to vector of strings.
 * @param values Vector of identifiers.
 * @return Vector of decimal string representations.
 */
std::vector<std::string> datagram_identifiers_to_string(
    const std::vector<kmall::t_KMALLDatagramIdentifier>& values);


//IGNORE_DOC:__doc_themachinethatgoesping_echosounders_datagram_identifiers_to_string2
/**
 * @brief Convert set of datagram identifiers to vector of strings.
 * @param values Set of identifiers.
 * @return Vector of decimal string representations (in set iteration order).
 */
std::vector<std::string> datagram_identifiers_to_string(
    const std::set<kmall::t_KMALLDatagramIdentifier>& values);

/**
 * @brief Get descriptive information about a datagram type.
 * @param datagram_type Datagram identifier.
 * @return Human-readable description.
 */
//IGNORE_DOC:__doc_themachinethatgoesping_echosounders_datagram_identifier_info
std::string datagram_identifier_info(kmall::t_KMALLDatagramIdentifier datagram_type);

}
}

extern template class themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier,
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_values.size(),
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_values,
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_names,
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_alt_names>;