// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "flag_detection_information.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {
namespace detection_information {

bool get_detection_is_valid(uint8_t detection_info)
{
    return (detection_info & 0b10000000) == 0b00000000;
}

t_DetectionType get_detection_type(uint8_t detection_info)
{
    return t_DetectionType(detection_info & 0b11110111);
}

bool get_backscatter_is_compensated(uint8_t detection_info)
{
    return (detection_info & 0b00001000) == 0b00001000;
}

} // namespace detection_information
} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping

template class themachinethatgoesping::tools::classhelper::Option<
    themachinethatgoesping::echosounders::kongsbergall::datagrams::substructures::
        detection_information::t_DetectionType>;