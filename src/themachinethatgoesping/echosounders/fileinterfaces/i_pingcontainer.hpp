// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {


template<typename t_key, typename t_value>
class DefaultSharedPointerMap : public std::map<t_key, std::shared_ptr<t_value>>
{
  public:
    // use all constructors of the base class
    DefaultSharedPointerMap() = default;

    std::shared_ptr<t_value>& get(const t_key& key)
    {
        auto it = this->find(key);

        if (it == this->end())
        {
            this->operator[](key) = std::make_shared<t_value>();

            return this->operator[](key);
        }
        return it->second;
    }

    std::shared_ptr<t_value> get_const(const t_key& key) const
    {
        auto it = this->find(key);

        if (it == this->end())
        {
            std::make_shared<t_value>();
        }
        return it->second;
    }
};

template<typename t_Ping>
using PingVector = std::vector<std::shared_ptr<t_Ping>>;

template<typename t_Ping>
class I_PingContainer
{
    std::string _name;

    const std::shared_ptr<PingVector<t_Ping>> _pings = std::make_shared<PingVector<t_Ping>>();

    DefaultSharedPointerMap<std::string, PingVector<t_Ping>> _pings_by_channel;

  public:
    I_PingContainer(std::string_view name = "Default")
        : _name(name)
    {
    }
    virtual ~I_PingContainer() = default;

    void add_ping(const std::shared_ptr<t_Ping> ping)
    { 
        _pings->push_back(ping);
        _pings_by_channel.get(ping->get_channel_id())->push_back(ping);
    }

    const std::shared_ptr<PingVector<t_Ping>>& get_pings() const { return _pings; }
    const std::shared_ptr<PingVector<t_Ping>>& get_pings_by_channel(std::string_view channel_id) const
    {
        return _pings_by_channel.get_const(channel_id); 
    }


};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping