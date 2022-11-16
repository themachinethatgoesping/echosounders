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
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_Ping>
using PingVector = std::vector<std::shared_ptr<t_Ping>>;

template<typename t_Ping>
class I_PingContainer
{
    std::string _name;

    PingVector<t_Ping>         _pings;
    tools::pyhelper::PyIndexer _pyindexer;

  public:
    I_PingContainer(std::string_view name = "Default")
        : _name(name)
        , _pyindexer(0)
    {
    }
    I_PingContainer(PingVector<t_Ping> pings, std::string_view name = "Default")
        : _name(name)
        , _pings(std::move(pings))
        , _pyindexer(_pings.size())
    {
    }
    ~I_PingContainer() = default;

    void add_ping(std::shared_ptr<t_Ping> ping)
    {
        this->_pings.push_back(std::move(ping));
        this->_pyindexer.reset(this->_pings.size());
    }

    const PingVector<t_Ping>& get_pings() const { return _pings; }

    // ----- compute ping information -----
    size_t max_number_of_samples() const
    {
        size_t max_samples = 0;
        for (size_t i : _pyindexer)
            max_samples = std::max(max_samples, _pings[i]->get_number_of_samples());

        return max_samples;
    }

    // ----- iterator interface -----
    I_PingContainer<t_Ping> operator()(const tools::pyhelper::PyIndexer::Slice& slice) const
    {
        I_PingContainer<t_Ping> ping_container(*this);

        tools::pyhelper::PyIndexer pyindexer(_pings.size(), slice);

        PingVector<t_Ping> pings;
        pings.reserve(pyindexer.size());

        for (size_t i : pyindexer)
        {
            pings.push_back(_pings[i]);
        }

        ping_container.set_pings(std::move(pings));

        return ping_container;
    }

    I_PingContainer<t_Ping> reversed() const
    {
        return this->operator()(_pyindexer.reversed().to_slice());
    }

    I_PingContainer<t_Ping> operator()(long start, long end, long step) const
    {
        return this->operator()(tools::pyhelper::PyIndexer::Slice(start, end, step));
    }

    I_PingContainer<t_Ping> operator()(const std::string& channel_id) const
    {
        I_PingContainer<t_Ping> filtered(*this);

        PingVector<t_Ping> pings;

        for (const auto& ping : _pings)
        {
            if (ping->get_channel_id() == channel_id)
                pings.push_back(ping);
        }

        filtered.set_pings(std::move(pings));

        return filtered;
    }

    I_PingContainer<t_Ping> filter_by_channel_ids(const std::vector<std::string>& channel_ids)
    {
        I_PingContainer<t_Ping> filtered(*this);

        PingVector<t_Ping> pings;

        for (const auto& ping : _pings)
        {
            if (std::find(channel_ids.begin(), channel_ids.end(), ping->get_channel_id()) !=
                channel_ids.end())
                pings.push_back(ping);
        }

        filtered.set_pings(std::move(pings));

        return filtered;
    }

    std::vector<std::string> find_channel_ids()
    {
        std::set<std::string> channel_ids;

        for (const auto& ping : _pings)
        {
            channel_ids.insert(ping->get_channel_id());
        }

        std::vector<std::string> vec;
        std::copy(channel_ids.begin(), channel_ids.end(), std::back_inserter(vec));
        return vec;
    }

    std::vector<I_PingContainer<t_Ping>> break_by_time_diff(double max_time_diff_seconds)
    {
        std::vector<I_PingContainer<t_Ping>> containers;

        PingVector<t_Ping> pings;

        for (const auto& ping : _pings)
        {
            if (!pings.empty())
            {
                if (ping->get_timestamp() - pings.back()->get_timestamp() > max_time_diff_seconds)
                {
                    containers.push_back(I_PingContainer<t_Ping>(pings));
                    pings = PingVector<t_Ping>();
                }
            }
            pings.push_back(ping);
        }

        containers.push_back(I_PingContainer<t_Ping>(pings));

        return containers;
    }

    // sort _datagram_infos_all by timestamp in _datagram_timestamps
    I_PingContainer<t_Ping> get_sorted_by_time()
    {
        I_PingContainer<t_Ping> sorted(*this);
        // Your function
        auto& pings = sorted._pings;
        // sort _datagram_infos_all by  time, then file_pos then file number
        // TODO: this is faster than std sort, but python sorting (timsort?) seems
        // to be 10x faster for this use case
        boost::sort::pdqsort(pings.begin(), pings.end(), [](const auto& lhs, const auto& rhs) {
            if (lhs->get_timestamp() < rhs->get_timestamp())
                return true;
            return false;
        });

        return sorted;
    }

    void set_pings(PingVector<t_Ping> pings)
    {
        _pings = std::move(pings);
        _pyindexer.reset(_pings.size());
    }

    size_t size() const { return _pyindexer.size(); }

    const t_Ping& at(long index) const { return *_pings[_pyindexer(index)]; }
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping