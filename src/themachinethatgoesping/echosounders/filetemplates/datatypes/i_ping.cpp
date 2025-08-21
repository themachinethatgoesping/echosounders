// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "i_ping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

bool               I_Ping::has_channel_id() const
{
    return !_channel_id.get().empty();
}
const std::string& I_Ping::get_channel_id() const
{
    return _channel_id.get();
}
bool I_Ping::has_sensor_configuration() const
{
    return _sensor_configuration_set;
}
bool I_Ping::has_navigation_interpolator_latlon() const
{
    return _navigation_interpolator_set;
}
bool I_Ping::has_sensor_data_latlon() const
{
    return has_navigation_interpolator_latlon();
}
I_PingBottom& I_Ping::bottom()
{
    throw not_implemented("bottom", this->class_name());
}
const I_PingBottom&   I_Ping::bottom() const
{
    return const_cast<I_Ping*>(this)->bottom();
}

} // namespace filetemplates
} // namespace datatypes
} // namespace echosounders
} // namespace themachinethatgoesping
