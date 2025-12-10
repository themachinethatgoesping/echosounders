// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/_wciinfos.doc.hpp"

/* generated doc strings */
#include ".docstrings/watercolumninformation.doc.hpp"

/* boost includes */
#include <boost/flyweight.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

#include "../../datagrams.hpp"
#include "../../types.hpp"

#include "../../../pingtools/readsamplerange.hpp"


namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {
namespace _sub {

class _WCIInfos
{
    float   _sound_speed_at_transducer  = 0.0f;
    float   _sampling_interval          = 0.0f;
    uint8_t _tvg_function_applied       = 0;
    int8_t  _tvg_offset_in_db           = 0;
    uint8_t _number_of_transmit_sectors = 0;
    std::vector<datagrams::substructures::WatercolumnDatagramTransmitSector> _transmit_sectors;

  public:
    _WCIInfos() = default;

    _WCIInfos(const datagrams::WatercolumnDatagram& water_column_datagram);

    bool operator==(_WCIInfos const& other) const = default;

    // getters and setters
    float   get_sound_speed_at_transducer() const { return _sound_speed_at_transducer; }
    uint8_t get_tvg_function_applied() const { return _tvg_function_applied; }
    int8_t  get_tvg_offset_in_db() const { return _tvg_offset_in_db; }
    float   get_sampling_interval() const { return _sampling_interval; }
    uint8_t get_number_of_transmit_sectors() const { return _transmit_sectors.size(); }
    const std::vector<datagrams::substructures::WatercolumnDatagramTransmitSector>&
    get_transmit_sectors() const;

    void set_sound_speed_at_transducer(float sound_speed_at_transducer);
    void set_tvg_function_applied(uint8_t tvg_function_applied);
    void set_tvg_offset_in_db(int8_t tvg_offset_in_db) { _tvg_offset_in_db = tvg_offset_in_db; }
    void set_sampling_interval(float sampling_interval) { _sampling_interval = sampling_interval; }
    void set_transmit_sectors(
        const std::vector<datagrams::substructures::WatercolumnDatagramTransmitSector>&
            transmit_sectors);

    // ----- functions used for PackageCache -----
    static _WCIInfos from_binary(std::string_view buffer);

    std::string to_binary() const;
};

// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_sub_hash_value
inline std::size_t hash_value(const _WCIInfos& data)
{
    xxh::hash3_state_t<64>               hash;
    boost::iostreams::stream<XXHashSink> stream(hash);

    stream.write(reinterpret_cast<const char*>(&data),
                 sizeof(float) + sizeof(uint8_t) + sizeof(uint8_t) + sizeof(int8_t) +
                     sizeof(float));

    stream.write(reinterpret_cast<const char*>(data.get_transmit_sectors().data()),
                 data.get_transmit_sectors().size() *
                     sizeof(datagrams::substructures::WatercolumnDatagramTransmitSector));
    stream.flush();
    return hash.digest();
}


} // namespace _sub
} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping