// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

// #include "i_datagram.h"
// #include "i_datagramcontent.h"
// #include "i_datagramheader.h"

/* std includes */
#include <unordered_map>
#include <memory>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace helper {
    
template<typename t_datagram>
class DeduplicateBuffer
{
    std::unordered_map<std::string, std::shared_ptr<t_datagram>> _last_datagram_per_channel_id;
    std::unordered_map<t_datagram, std::shared_ptr<t_datagram>>  _datagrams;

  public:
    DeduplicateBuffer() = default;

    void add(const t_datagram& datagram, const std::string& channel_id)
    {
        // add channel_ptr if channel is not in in channel_parameters
        // keys
        auto it = _datagrams.find(datagram);
        if (it == _datagrams.end())
        {
            auto datagram_ptr                         = std::make_shared<t_datagram>(datagram);
            _datagrams[datagram]                      = datagram_ptr;
            _last_datagram_per_channel_id[channel_id] = datagram_ptr;
        }
        else
        {
            _last_datagram_per_channel_id[channel_id] = it->second;
        }
    }

    std::shared_ptr<t_datagram> get(const std::string& channel_id)
    {
        return _last_datagram_per_channel_id[channel_id];
    }

    std::unordered_map<t_datagram, t_datagram> get_all()
    {
        std::unordered_map<t_datagram, t_datagram> datagrams;
        for (auto& [key, value] : _datagrams)
        {
            datagrams[key] = *value;
        }
        return datagrams;
    }
};

} // namespace helper
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping