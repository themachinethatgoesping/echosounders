// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000_types.doc.hpp"

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
    DepthDatagram_NotImplemented        = 0x44, ///< not yet implemented
    CentralBeamsEchogram_NotImplemented = 0x4b, ///< not yet implemented

    XYZDatagram = 0x58,
    ExtraDetections =
        0x6c, ///< TODO: fix reading raw_amplitudes (sometimes the number seems incorrect)
    RawRangeAndAngle_F_NotImplemented  = 0x46, ///< not yet implemented
    RawRangeAndAngle_f_NotImplemented  = 0x66, ///< not yet implemented
    RawRangeAndAngle                   = 0x4e,
    SeabedImageDatagram_NotImplemented = 0x53, ///< not yet implemented
    SeabedImageData                    = 0x59,
    WaterColumnDatagram                = 0x6b,
    QualityFactorDatagram              = 0x4f,

    // External sensors
    AttitudeDatagram                = 0x41,
    NetworkAttitudeVelocityDatagram = 0x6e,
    ClockDatagram                   = 0x43,
    DepthOrHeightDatagram           = 0x68,
    HeadingDatagram                 = 0x48,
    PositionDatagram                = 0x50,
    SingleBeamEchoSounderDepth      = 0x45,
    TideDatagram_NotImplemented     = 0x54, ///< not yet implemented

    // Sound speed
    SurfaceSoundSpeedDatagram = 0x47,
    SoundSpeedProfileDatagram = 0x55,

    // Multibeam parameters
    InstallationParametersStart = 0x49,
    InstallationParametersStop  = 0x69,
    RuntimeParameters           = 0x52,
    MechanicalTransducerTilt    = 0x4A, ///< not yet implemented
    ExtraParameters             = 0x33,

    // PU information and status
    PUIDOutput     = 0x30, ///< TODO: implement!
    PUStatusOutput = 0x31,
    unspecified    = 0
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
