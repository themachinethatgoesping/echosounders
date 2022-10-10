// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

#include <fstream>
#include <limits>
#include <memory>
#include <unordered_map>
#include <vector>

/* memory mapping */
#include <boost/iostreams/device/mapped_file.hpp> // for mmap
#include <boost/iostreams/stream.hpp>             // for stream

#include <fmt/core.h>
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "i_inputfileiterator.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_PingType, typename t_ifstream >
class I_PingIterator
{
  protected:
    const std::shared_ptr<std::vector<std::string>> _file_paths;

    /* the opened input file stream */
    std::shared_ptr<t_ifstream> _input_file_stream;
    long                        active_file_nr = -1;

    /* header positions */
    const std::shared_ptr<const std::vector<t_PingType>> _pings;

    t_ifstream& get_active_stream(size_t file_nr)
    {
        // TODO: active_file_nr is currently not updated when _file_paths is changed in the master
        if (long(file_nr) != active_file_nr)
        {
            active_file_nr = long(file_nr);
            _input_file_stream =
                std::make_unique<t_ifstream>(_file_paths->at(file_nr), std::ios_base::binary);
        }
        return *_input_file_stream;
    }

    bool   _is_slice   = false;
    size_t _index_min  = 0;
    size_t _index_max  = std::numeric_limits<long>::max();
    long   _index_step = 1;

  public:
    I_PingIterator<t_PingType, t_ifstream>& operator()(long index_min,
                                                       long index_max,
                                                       long index_step)
    {

        if (index_step == 0)
            throw(std::out_of_range("InputFileIterator: index_step is zero!"));

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

        return *this;
    }

    I_PingIterator(std::shared_ptr<std::vector<std::string>> file_paths,
                   std::shared_ptr<std::vector<t_PingType>>  pings)
        : _file_paths(file_paths)
        , _pings(pings)
        , _is_slice(false)
    {
    }

    I_PingIterator(std::shared_ptr<std::vector<std::string>> file_paths,
                   std::shared_ptr<std::vector<t_PingType>>  pings,
                   long                                      index_min,
                   long                                      index_max,
                   long                                      index_step)
        : _file_paths(file_paths)
        , _pings(pings)
    {
        this->operator()(index_min, index_max, index_step);
    }

    size_t size() const
    {
        if (_is_slice)
            return size_t((_index_max - _index_min) / std::abs(_index_step)) + 1; //TODO this needs to be checked
        return _pings->size();
    }

    size_t max_number_of_samples() const
    {
        size_t max_samples = 0;
        for (const auto& ping : *_pings)
            max_samples = std::max(max_samples, ping.get_number_of_samples());
        return max_samples;
    }

    t_PingType at(long index)
    {
        if (_is_slice)
        {
            if (_index_step < 0)
                index += 1;

            // convert index to C++ index using _index_step, _index_min, _index_max
            index *= _index_step;

            if (index < 0)
                index += long(_index_max) +
                         std::abs(_index_step); //_index_max == _pings->size()-1
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

        // size_t, t_ifstream::pos_type double, t_DatagramIdentifier
        return _pings->at(index);
    }
};

}
}
}
