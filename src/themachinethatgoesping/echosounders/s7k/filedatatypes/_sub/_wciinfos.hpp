// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/_wciinfos.doc.hpp"

/* std includes */
#include <cstdint>
#include <string>
#include <string_view>

/* boost includes */
#include <boost/flyweight.hpp>

#include <xxhash.hpp>

#include "../../datagrams/compressedwatercolumn.hpp"
#include "../../datagrams/substructs/compressedwatercolumndatatypes.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {
namespace _sub {

/**
 * @brief Record-wide (not per-beam) information of a 7042 CompressedWaterColumnData record.
 *
 * This is the part of the water column information that is constant for the whole record (sample
 * rate, first sample, beam count and the sample encoding). It is held as a flyweight so that
 * identical configurations (the common case for consecutive pings) are stored only once.
 *
 * Note this is a private substructure and thus not part of the public API or nanobind interface.
 */
class _WCIInfos
{
    // serialized (and hashed) as the first __binary_size bytes -> keep these contiguous & padding
    // free (float/uint32 first, then the single bytes); the trailing struct padding is never used.
    float    _sample_rate          = 0.f; ///< effective sample rate after downsampling (Hz)
    uint32_t _first_sample         = 0;   ///< first sample index (same for every beam)
    uint16_t _number_beams         = 0;   ///< number of beams
    uint8_t  _downsampling_divisor = 1;   ///< downsampling divisor (1 = no downsampling)
    uint8_t  _magnitude_bytes      = 2;   ///< bytes per magnitude sample on disk (1, 2 or 4)
    uint8_t  _has_phase            = 0;   ///< whether the record contains phase data
    uint8_t  _magnitude_is_db      = 0;   ///< whether the 8-bit magnitude is already in dB

  public:
    /// number of logical (padding-free) bytes used for serialization / hashing
    static constexpr std::size_t __binary_size =
        sizeof(float) + sizeof(uint32_t) + sizeof(uint16_t) + 4 * sizeof(uint8_t);

    _WCIInfos() = default;

    explicit _WCIInfos(const datagrams::CompressedWaterColumn& water_column_datagram);

    bool operator==(const _WCIInfos& other) const = default;

    // ----- getters -----
    float    get_sample_rate() const { return _sample_rate; }
    uint32_t get_first_sample() const { return _first_sample; }
    uint16_t get_number_beams() const { return _number_beams; }
    uint8_t  get_downsampling_divisor() const { return _downsampling_divisor; }
    uint8_t  get_magnitude_bytes() const { return _magnitude_bytes; }
    bool     get_has_phase() const { return _has_phase != 0; }
    bool     get_magnitude_is_db() const { return _magnitude_is_db != 0; }

    // ----- derived -----
    bool get_magnitude_is_32bit() const { return _magnitude_bytes == 4; }

    datagrams::substructs::t_CompressedWaterColumnDataType get_data_type() const
    {
        return datagrams::substructs::compressed_water_column_data_type(_magnitude_bytes,
                                                                        _has_phase != 0);
    }

    int get_bytes_per_sample() const
    {
        return datagrams::substructs::compressed_water_column_bytes_per_sample(get_data_type());
    }

    // ----- functions used for PackageCache -----
    static _WCIInfos from_binary(std::string_view buffer);
    std::string      to_binary() const;
};

// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_hash_value
inline std::size_t hash_value(const _WCIInfos& data)
{
    // hash only the logical (padding-free) bytes so it stays consistent with operator==
    return xxh::xxhash3<64>(&data, _WCIInfos::__binary_size);
}

} // namespace _sub
} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
