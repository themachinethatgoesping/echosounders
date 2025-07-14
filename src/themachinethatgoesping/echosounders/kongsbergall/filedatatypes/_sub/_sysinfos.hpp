// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/_sysinfos.doc.hpp"

/* generated doc strings */
#include ".docstrings/systeminformation.doc.hpp"

/* boost includes */
#include <boost/flyweight.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>
#include <themachinethatgoesping/algorithms/signalprocessing/types.hpp>
#include <themachinethatgoesping/tools/classhelper/xxhashhelper.hpp>
#include <themachinethatgoesping/tools/hashhelper.hpp>

#include "../../datagrams.hpp"
#include "../../types.hpp"
#include "watercolumninformation.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {
namespace _sub {

struct _SYSInfos
{
    // float sampling_frequency_in_hz = 0.0f;

    _SYSInfos() = default;

    bool operator==(_SYSInfos const& other) const = default;
};

// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_sub_hash_value
inline std::size_t hash_value([[maybe_unused]] const _SYSInfos& data)
{
    xxh::hash3_state_t<64>               hash;
    boost::iostreams::stream<XXHashSink> stream(hash);

    // stream.write(reinterpret_cast<const char*>(&data.sampling_frequency_in_hz), sizeof(float));

    stream.flush();
    return hash.digest();
}


} // namespace substructures
} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping