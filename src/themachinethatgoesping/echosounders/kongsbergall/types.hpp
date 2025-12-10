// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/types.doc.hpp"

#include <complex>
#include <set>
#include <vector>

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
namespace kongsbergall {

enum class t_KongsbergAllDatagramIdentifier : uint8_t
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
    WatercolumnDatagram                = 0x6b,
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
    InstallationParametersStart             = 0x49,
    InstallationParametersStop              = 0x69,
    RuntimeParameters                       = 0x52,
    MechanicalTransducerTilt_NotImplemented = 0x4A, ///< not yet implemented
    ExtraParameters                         = 0x33,

    // PU information and status
    PUIDOutput         = 0x30,
    PUStatusOutput     = 0x31,
    PUBISTResultOutput = 0x42, ///< not yet implemented
    unspecified        = 0
};

using o_KongsbergAllDatagramIdentifier =
    themachinethatgoesping::tools::classhelper::Option<t_KongsbergAllDatagramIdentifier>;

// ----- other enums -----
/**
 * @brief This enum is used to identify the active sensor in the InstallationParameters datagram
 *
 */
enum class t_KongsbergAllActiveSensor : int8_t
{
    PositionSystem3 = 0, ///< UDP2 or COM4
    PositionSystem1 = 1, ///< COM1
    PositionSystem2 =
        32, ///< COM3 (it is not clear how this case is separated from 3 (attitude sensor 2))
    MotionSensor1           = 2, ///< COM2
    MotionSensor2           = 3, ///< COM3
    MultiCast1              = 5, ///<
    MultiCast2              = 6, ///<
    MultiCast3              = 7, ///<
    AttitudeVelocitySensor1 = 8, ///< UDP5
    AttitudeVelocitySensor2 = 9, ///< UDP6
    NotSet                  = -1 ///< this is not a valid value
};

using o_KongsbergAllActiveSensor =
    themachinethatgoesping::tools::classhelper::Option<t_KongsbergAllActiveSensor>;

/**
 * @brief This enum is used to identify the transducer configuration (STC field) in the
 * InstallationParameters datagram
 *
 */
enum class t_KongsbergAllSystemTransducerConfiguration : uint8_t
{
    SingleTXSingleRX   = 0, ///< EM122, EM302, EM710, EM2040 Single
    SingleHead         = 1, ///< EM3002 Single Head, EM2040C Single Head
    DualHead           = 2, ///< EM3002 Dual Head, EM2040C Dual Head
    SingleTXDualRX     = 3, ///< EM2040 Dual RX
    DualTXDualRX       = 4, ///< EM2040 Dual TX
    PortableSingleHead = 5, ///< EM2040P
    Modular            = 6  ///< EM2040M
};


using o_KongsbergAllSystemTransducerConfiguration =
    themachinethatgoesping::tools::classhelper::Option<t_KongsbergAllSystemTransducerConfiguration>;

/**
 * @brief Convert a t_KongsbergAllActiveSensor to an attitude sensor number
 * 0: the enum value is not an attitude sensor
 * 1-2: attitude sensor number
 *
 * @param value
 * @return int
 */
int t_KongsbergAllActiveSensor_to_attitude_sensor_number(t_KongsbergAllActiveSensor value);

// inline std::string datagram_type_to_string(uint8_t value)
// {
//     return tools::helper::int_as_string<kongsbergall_long>(value);
// }

std::string datagram_type_to_string(t_KongsbergAllDatagramIdentifier value);

t_KongsbergAllDatagramIdentifier KongsbergAllDatagram_type_from_string(std::string_view value);

} // namespace kongsbergall

// ----- interface? -----

std::string datagram_identifier_to_string(kongsbergall::t_KongsbergAllDatagramIdentifier value);

// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_datagram_identifier_info
std::string datagram_identifier_info(kongsbergall::t_KongsbergAllDatagramIdentifier datagram_type);

// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_datagram_identifiers_to_string
std::vector<std::string> datagram_identifiers_to_string(
    const std::vector<kongsbergall::t_KongsbergAllDatagramIdentifier>& values);

// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_datagram_identifiers_to_string_2
std::vector<std::string> datagram_identifiers_to_string(
    const std::set<kongsbergall::t_KongsbergAllDatagramIdentifier>& values);

} // namespace echosounders
} // namespace themachinethatgoesping


extern template class themachinethatgoesping::tools::classhelper::Option<
    themachinethatgoesping::echosounders::kongsbergall::t_KongsbergAllDatagramIdentifier>;

extern template class themachinethatgoesping::tools::classhelper::Option<
    themachinethatgoesping::echosounders::kongsbergall::t_KongsbergAllActiveSensor>;

extern template class themachinethatgoesping::tools::classhelper::Option<
    themachinethatgoesping::echosounders::kongsbergall::t_KongsbergAllSystemTransducerConfiguration>;
