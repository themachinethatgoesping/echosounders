// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <complex>
#include <themachinethatgoesping/tools/helper.hpp>

/**
 * @brief Type definitions for Ek60 types according to Ek60 Reference manual
 * see also http://www.em3000.net/em3000_ref_english/default.htm
 *
 * Note: these definitions are valid for EK60 and the EK80 files.
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {

enum class t_EM3000DatagramIdentifier : uint8_t
{
    // Multibeam data
    DepthDatagram       = 0x44,
    XYZDatagram         = 0x58,
    RawRangeAndAngle    = 0x4e,
    SeabedImageData     = 0x59,
    WaterColumnDatagram = 0x6b,
    CombinedWaterColumnDatagram =
        0x6c, ///< virtual package that combines the split water column datagrams
    QualityFactorDatagram = 0x4f, ///< TODO: implement!

    // External sensors
    AttitudeDatagram                = 0x41,
    NetworkAttitudeVelocityDatagram = 0x6e, ///< TODO: implement!
    ClockDatagram                   = 0x43,
    DepthOrHeightDatagram           = 0x68,
    HeadingDatagram                 = 0x48, ///< TODO: implement!
    PositionDatagram                = 0x50,
    SingleBeamEchoSounderDepth      = 0x45, ///< TODO: implement!

    // Sound speed
    SurfaceSoundSpeedDatagram = 0x47,
    SoundSpeedProfileDatagram = 0x55,

    // Multibeam parameters
    InstallationParameterStart = 0x49,
    InstallationParameterStop  = 0x69,
    RuntimeParameters          = 0x52,
    ExtraParameters            = 0x33,

    // PU information and status
    PuStatusOutput = 0x31,
    PUIDOutput     = 0x30,
    // all = 0
    unspecified = 0
};

// inline std::string datagram_type_to_string(uint8_t value)
// {
//     return tools::helper::int_as_string<em3000_long>(value);
// }

inline std::string datagram_type_to_string(t_EM3000DatagramIdentifier value)
{
    // convert to string using magic enum
    return std::string(magic_enum::enum_name(value));
}

inline t_EM3000DatagramIdentifier EM3000Datagram_type_from_string(std::string_view value)
{
    // convert to datagram type using magic enum
    return magic_enum::enum_cast<t_EM3000DatagramIdentifier>(value).value_or(
        t_EM3000DatagramIdentifier::unspecified);
}

} // namespace em3000

// ----- interface? -----

inline std::string datagram_identifier_to_string(em3000::t_EM3000DatagramIdentifier value)
{
    return em3000::datagram_type_to_string(value);
}

inline std::string datagram_identifier_info(em3000::t_EM3000DatagramIdentifier datagram_type)
{
    return fmt::format("{:x}", uint8_t(datagram_type));
}

} // namespace echosounders
} // namespace themachinethatgoesping
