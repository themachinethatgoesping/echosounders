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

#include "i_pingiterator.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {


template<typename t_Ping>
using PingVector = std::vector<std::shared_ptr<t_Ping>>;

template<typename t_Ping>
class I_PingContainer
{
    std::string _name;

    std::shared_ptr<PingVector<t_Ping>> _pings;

    I_PingIterator<t_Ping> _iterator;

  public:
    I_PingContainer(std::string_view name = "Default")
        : _name(name)
        , _pings(std::make_shared<PingVector<t_Ping>>())
        , _iterator(_pings)
    {
    }
    ~I_PingContainer() = default;

    void add_ping(const std::shared_ptr<t_Ping> ping)
    {
        this->_pings->push_back(ping);
    }

    const std::shared_ptr<PingVector<t_Ping>>& get_pings() const { return _pings; }

    // ----- compute ping information -----
    size_t max_number_of_samples() const
    {
        size_t max_samples = 0;
        auto   len         = long(size());
        for (long i = 0; i < len; ++i)
            max_samples = std::max(max_samples, _iterator.at(i).get_number_of_samples());
        return max_samples;
    }

    // ----- iterator interface -----
    I_PingContainer<t_Ping> operator()(long index_min, long index_max, long index_step) const
    {
        I_PingContainer<t_Ping> slice(*this);
        auto it = slice.get_iterator();
        it.set_slice(index_min, index_max, index_step);

        auto pings = std::make_shared<PingVector<t_Ping>>();

        for (size_t i = 0; i < it.size(); ++i)
        {
            pings->push_back(it.at_ptr(i));
        }

        slice.set_pings(pings);

        return slice;
    }

    const I_PingIterator<t_Ping>& get_iterator()
{
    return _iterator;
}

    void set_pings(std::shared_ptr<PingVector<t_Ping>> pings)
    {
        _pings = pings;
        _iterator = I_PingIterator<t_Ping>(_pings);
    }

    size_t size() const { return _iterator.size(); }

    const t_Ping& at(long index) const { return _iterator.at(index); }
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping