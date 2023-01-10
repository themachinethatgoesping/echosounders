// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../em3000_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {
namespace substructures {
namespace detection_information {

/**
 * @brief The detection_info flag (uint8_t) is used in XYZDatagramBeam and
 * ExtraDectionsExtraDetections to indicate the type of detection.
 *
 */

enum class t_DetectionType : uint8_t
{
    AmplitudeDetect        = 0b00000000, ///< Valid, amplitude detection was used
    PhaseDetect            = 0b00000001, ///< Valid, phase detection was used
    InvalidNormalDetection = 0b10000000, ///< Invalid: Normal detection
    Interpolated           = 0b10000001, ///< Invalid: Therefor interpolated or extrapolated
    Estimated              = 0b10000010, ///< Invalid: Therefor estimated
    Rejected               = 0b10000011, ///< Invalid: Therefor rejected
    NoDetection            = 0b10000100, ///< Invalid: No detection data is available for this beam
    Invalid
};

/**
 * @brief This function evaluates a detection information flag. If the last bit is set to 1,
 * the detection is valid. If the last bit is set to 0, the detection is invalid.
 *
 * @return true
 * @return false
 */
inline bool get_detection_is_valid(uint8_t detection_info)
{
    return (detection_info & 0x01) == 0x00;
}

/**
 * @brief This function evaluates the detection information flag. The first 3 bits indicate the
 * type of detection.
 *
 * @return t_DetectionType
 */
inline t_DetectionType get_detection_type(uint8_t detection_info)
{
    return t_DetectionType(detection_info & 0b11110111);
}

/**
 * @brief This function evaluates the detection information flag. If the 4th bit is set to 1,
 * the detection is compensated for beam incident angle. If the 4th bit is set to 0, the
 * detection is not compensated for beam incident angle.
 *
 * @return true
 * @return false
 */
inline bool get_backscatter_is_compensated(uint8_t detection_info)
{
    return (detection_info & 0b00001000) == 0b00001000;
}

} // namespace detection_information
} // namespace substructures
} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
