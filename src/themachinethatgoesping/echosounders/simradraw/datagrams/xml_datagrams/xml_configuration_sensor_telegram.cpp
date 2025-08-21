// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_configuration_sensor_telegram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

XML_Configuration_Sensor_Telegram::XML_Configuration_Sensor_Telegram(const pugi::xml_node& node)
{
    initialize(node);
}
bool XML_Configuration_Sensor_Telegram::parsed_completely() const
{
    return unknown_children == 0 && unknown_attributes == 0;
}

} // namespace simradraw
} // namespace datagrams
} // namespace xml_datagrams
} // namespace echosounders
} // namespace themachinethatgoesping
