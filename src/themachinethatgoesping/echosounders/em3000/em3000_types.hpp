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
    InstallationParameterStart = 0x49,
    InstallationParameterStop = 0x69,
    WaterColumnDatagram = 0x6b,
    CombinedWaterColumnDatagram,
    MultibeamRuntimeParameters = 0x52,
    SoundspeedProfileDatagram = 0x55,
    PuStatusOutput = 0x31,
    ExternalSensorsPositionDatagram = 0x50,
    DepthPressureOrHeightDatagram = 0x68,
    ExternalSensorsClock = 0x43,
    MultibeamSeabedImageData = 0x59,
    MultibeamRawRangeAndAngle = 0x4e,
    ExternalSensorsAttitudeDatagram = 0x41,
    MultibeamExtraParametersDatagram = 0x33,
    SurfacesoundspeedDatagram = 0x47,
    MultibeamXYZ_88 = 0x58,
    DepthDatagram = 0x44,
    PUIdOutputDatagram = 0x30,
    all = 0,
    unspecified
};

// inline std::string datagram_type_to_string(uint8_t value)
// {
//     return tools::helper::int_as_string<em3000_long>(value);
// }

inline std::string datagram_type_to_string(t_EM3000DatagramIdentifier value)
{
    // convert to string using magic enum
    return magic_enum::enum_name(value);
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
