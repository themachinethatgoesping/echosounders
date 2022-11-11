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
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_Ping>
class I_PingIterator
{
  protected:
    /* header positions */
    std::shared_ptr<std::vector<std::shared_ptr<t_Ping>>> _pings;

    tools::pyhelper::PyIndexer _pyindexer;

  public:
    I_PingIterator(std::shared_ptr<std::vector<std::shared_ptr<t_Ping>>> pings)
        : _pings(pings)
        , _pyindexer(pings->size())
    {
    }

    I_PingIterator(std::shared_ptr<std::vector<std::shared_ptr<t_Ping>>> pings,
                   long                                                  start,
                   long                                                  end,
                   long                                                  step)
        : _pings(pings)
        , _pyindexer(pings->size(), start, end, step)
    {
    }

    void reset_slice() { _pyindexer.reset(_pings->size()); }

    void set_slice(long start, long end, long step)
    {
        _pyindexer.set_slice_indexing(start, end, step);
    }

    size_t size() const { return _pyindexer.size(); }

    const t_Ping& at(long index) const
    {
        // size_t, t_ifstream::pos_type double, t_DatagramIdentifier
        return *(*_pings)[_pyindexer(index)];
    }
    const std::shared_ptr<t_Ping>& at_ptr(long index) const
    {
        // size_t, t_ifstream::pos_type double, t_DatagramIdentifier
        return (*_pings)[_pyindexer(index)];
    }
};

}
}
}
