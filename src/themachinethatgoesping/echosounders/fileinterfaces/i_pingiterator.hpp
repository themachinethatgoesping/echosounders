// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

#include <limits>
#include <memory>
#include <vector>

#include <fmt/core.h>
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_Ping>
class I_PingIterator
{
  protected:
    /* header positions */
    std::shared_ptr<std::vector<std::shared_ptr<t_Ping>>> _pings;

    bool   _is_slice   = false;
    size_t _index_min  = 0;
    size_t _index_max  = std::numeric_limits<long>::max();
    long   _index_step = 1;

  public:
    I_PingIterator(std::shared_ptr<std::vector<std::shared_ptr<t_Ping>>> pings)
        : _pings(pings)
        , _is_slice(false)
    {
    }

    I_PingIterator(std::shared_ptr<std::vector<std::shared_ptr<t_Ping>>> pings,
                   long                                                  index_min,
                   long                                                  index_max,
                   long                                                  index_step)
        : _pings(pings)
    {
        set_slice(index_min, index_max, index_step);
    }

    void reset_slice()
    {
        _is_slice   = false;
        _index_min  = 0;
        _index_max  = std::numeric_limits<long>::max();
        _index_step = 1;
    }

    void set_slice(long index_min, long index_max, long index_step)
    {
        if (index_step == 0)
            throw(std::out_of_range("InputFileIterator slice: index_step is zero!"));

        if (index_max == std::numeric_limits<long>::max())
            index_max = _pings->size();

        bool ivn_max = false;
        bool ivn_min = false;
        if (index_max < 0)
        {
            index_max = long(_pings->size()) + index_max;
            ivn_max   = true;
        }

        if (index_min < 0)
        {
            index_min = long(_pings->size()) + index_min;
            ivn_min   = true;
        }

        if (index_min > index_max)
        {
            std::swap(index_min, index_max);
            index_step *= -1;
            ivn_max = ivn_min;
        }

        index_max = index_max - 1 * (!ivn_max);

        if (index_min < 0 || index_min >= long(_pings->size()))
            throw(std::out_of_range("InputFileIterator: index_min is out of bounds!"));
        if (index_max < 0 || index_max >= long(_pings->size()))
            throw(std::out_of_range("InputFileIterator: index_max is out of bounds!"));
        if (index_min >= index_max)
            throw(std::out_of_range("InputFileIterator: _index_min >= _index_max!"));

        _is_slice   = true;
        _index_min  = index_min;
        _index_max  = index_max;
        _index_step = index_step;
    }

    size_t size() const
    {
        if (_is_slice)
            return size_t((_index_max - _index_min) / std::abs(_index_step)) +
                   1; // TODO this needs to be checked
        return _pings->size();
    }

    size_t compute_index(long index) const
    {
        if (_is_slice)
        {
            if (_index_step < 0)
                index += 1;

            // convert index to C++ index using _index_step, _index_min, _index_max
            index *= _index_step;

            if (index < 0)
                index += long(_index_max) + std::abs(_index_step); //_index_max == _pings->size()-1
            else
                index += long(_index_min);

            // TODO: fix error messages
            if (size_t(index) > _index_max)
                throw std::out_of_range(
                    fmt::format("Index [{}] is > max [{}]! ", index - _index_min, _index_max));
        }
        else
        {
            // convert from python index (can be negative) to C++ index
            if (index < 0)
                index += long(_pings->size());
            // index = python_index < 0 ? _pings->size() + python_index : python_index;

            if (size_t(index) >= _pings->size())
                throw std::out_of_range(
                    fmt::format("Index [{}] is >= max [{}]! ", index, _pings->size()));
        }

        if (index < long(_index_min))
            throw std::out_of_range(fmt::format("Index [{}] is < min [{}]! ", index, _index_min));

        return size_t(index);
    }

    const t_Ping& at(long index) const
    {
        // size_t, t_ifstream::pos_type double, t_DatagramIdentifier
        return *(*_pings)[compute_index(index)];
    }
    const std::shared_ptr<t_Ping>& at_ptr(long index) const
    {
        // size_t, t_ifstream::pos_type double, t_DatagramIdentifier
        return (*_pings)[compute_index(index)];
    }
};

}
}
}
