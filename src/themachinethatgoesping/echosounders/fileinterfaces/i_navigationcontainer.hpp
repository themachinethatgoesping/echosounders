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
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>

#include "i_pingiterator.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

using NavInterpolator_ptr = std::shared_ptr<navigation::NavigationInterpolatorLatLon>;

class I_NavigationContainer
{
    std::string _name;

    std::shared_ptr<NavigationVector> _navinterpolators_per_file;
    std::shared_ptr<NavigationVector> _navinterpolators_per_file;

    I_PingIterator<navigation::NavigationInterpolatorLatLon> _iterator;

  public:
    I_NavigationContainer(std::string_view name = "Default")
        : _name(name)
        , _pings(std::make_shared<NavigationVector>())
        , _iterator(_pings)
    {
    }
    I_NavigationContainer(std::shared_ptr<NavigationVector> pings, std::string_view name = "Default")
        : _name(name)
        , _pings(pings)
        , _iterator(_pings)
    {
    }
    ~I_NavigationContainer() = default;

    void add_ping(const std::shared_ptr<t_Ping> ping) { this->_pings->push_back(ping); }

    const std::shared_ptr<NavigationVector>& get_pings() const { return _pings; }

    // ----- compute ping information -----

    // ----- iterator interface -----
    I_NavigationContainer operator()(long index_min, long index_max, long index_step) const
    {
        I_NavigationContainer slice(*this);
        auto                    it = slice.get_iterator();
        it.set_slice(index_min, index_max, index_step);

        auto pings = std::make_shared<NavigationVector>();

        for (size_t i = 0; i < it.size(); ++i)
        {
            pings->push_back(it.at_ptr(i));
        }

        slice.set_pings(pings);

        return slice;
    }

    I_NavigationContainer operator()(const std::string& channel_id) const
    {
        I_NavigationContainer filtered(*this);

        auto pings = std::make_shared<NavigationVector>();

        for (const auto& ping : *_pings)
        {
            if (ping->get_channel_id() == channel_id)
                pings->push_back(ping);
        }

        filtered.set_pings(pings);

        return filtered;
    }

    I_NavigationContainer filter_by_channel_ids(const std::vector<std::string>& channel_ids)
    {
        I_NavigationContainer filtered(*this);

        auto pings = std::make_shared<NavigationVector>();

        for (const auto& ping : *_pings)
        {
            if (std::find(channel_ids.begin(), channel_ids.end(), ping->get_channel_id()) !=
                channel_ids.end())
                pings->push_back(ping);
        }

        filtered.set_pings(pings);

        return filtered;
    }

    std::vector<std::string> find_channel_ids()
    {
        std::set<std::string> channel_ids;

        for (const auto& ping : *_pings)
        {
            channel_ids.insert(ping->get_channel_id());
        }

        std::vector<std::string> vec;
        std::copy(channel_ids.begin(), channel_ids.end(), std::back_inserter(vec));
        return vec;
    }

    std::vector<I_NavigationContainer> break_by_time_diff(double max_time_diff_seconds)
    {
        std::vector<I_NavigationContainer> containers;

        auto pings = std::make_shared<NavigationVector>();

        for (const auto& ping : *_pings)
        {
            if (!pings->empty())
            {
                if (ping->get_timestamp() - pings->back()->get_timestamp() > max_time_diff_seconds)
                {
                    containers.push_back(I_NavigationContainer(pings));
                    pings = std::make_shared<NavigationVector>();
                }
            }
            pings->push_back(ping);
        }

        containers.push_back(I_NavigationContainer(pings));

        return containers;
    }

    const I_PingIterator<t_Ping>& get_iterator() { return _iterator; }

    void set_pings(std::shared_ptr<NavigationVector> pings)
    {
        _pings    = pings;
        _iterator = I_PingIterator<t_Ping>(_pings);
    }

    size_t size() const { return _iterator.size(); }

    const t_Ping& at(long index) const { return _iterator.at(index); }
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping