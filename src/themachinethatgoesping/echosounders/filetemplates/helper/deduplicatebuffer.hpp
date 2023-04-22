// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/deduplicatebuffer.doc.hpp"

// #include "i_datagram.h"
// #include "i_datagramcontent.h"
// #include "i_datagramheader.h"

/* std includes */
#include <memory>
#include <unordered_map>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace helper {

template<typename t_datagram>
struct SlowHash
{
    size_t operator()(const t_datagram& arg) const { return arg.slow_hash(); }
    size_t operator()(const std::shared_ptr<t_datagram>& arg) const { return arg->slow_hash(); }
};

template<typename t_datagram>
struct ContentOnlyHash
{
    size_t operator()(const t_datagram& arg) const { return arg.hash_content_only(); }
    size_t operator()(const std::shared_ptr<t_datagram>& arg) const
    {
        return arg->hash_content_only();
    }
};

template<typename t_datagram, template<typename> typename t_KeyHasher = SlowHash>
class DeduplicateBuffer
{
    t_KeyHasher<t_datagram> KeyHasher;

    std::unordered_map<std::string, std::shared_ptr<t_datagram>> _last_datagram_per_channel_id;
    std::unordered_map<size_t, std::shared_ptr<t_datagram>>      _datagrams;

  public:
    DeduplicateBuffer() = default;

    void add(std::shared_ptr<t_datagram> datagram_ptr, const std::string& channel_id)
    {
        // add channel_ptr if channel is not in in channel_parameters
        // keys
        auto it = _datagrams.find(KeyHasher(datagram_ptr));
        if (it == _datagrams.end())
        {
            _datagrams[KeyHasher(datagram_ptr)]       = datagram_ptr;
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

    std::vector<t_datagram> get_all()
    {
        std::vector<t_datagram> datagrams;
        for (auto& [key, value] : _datagrams)
        {
            datagrams.push_back(*value);
        }
        return datagrams;
    }
};

} // namespace helper
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping