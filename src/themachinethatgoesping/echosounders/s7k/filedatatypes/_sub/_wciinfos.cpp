// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "_wciinfos.hpp"

#include <cstring>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {
namespace _sub {

_WCIInfos::_WCIInfos(const datagrams::CompressedWaterColumn& water_column_datagram)
{
    _sample_rate          = water_column_datagram.get_sample_rate();
    _first_sample         = water_column_datagram.get_first_sample();
    _number_beams         = water_column_datagram.get_number_beams();
    _downsampling_divisor = water_column_datagram.get_downsampling_divisor();
    _magnitude_bytes      = uint8_t(water_column_datagram.get_magnitude_bytes());
    _has_phase            = water_column_datagram.get_has_phase() ? 1 : 0;
    _magnitude_is_db      = water_column_datagram.get_magnitude_is_db() ? 1 : 0;
}

_WCIInfos _WCIInfos::from_binary(std::string_view buffer)
{
    _WCIInfos dat;
    // copy into the first member (a scalar pointer), not &dat: the members are a padding-free
    // 14-byte block, but sizeof(_WCIInfos) is padded to 16, so memcpy'ing into the class object
    // would trip -Wclass-memaccess ("leaves 2 bytes unchanged"). Same idiom as kmall's _WCIInfos.
    std::memcpy(&dat._sample_rate, buffer.data(), __binary_size);
    return dat;
}

std::string _WCIInfos::to_binary() const
{
    std::string buffer;
    buffer.resize(__binary_size);
    std::memcpy(buffer.data(), &_sample_rate, __binary_size);
    return buffer;
}

} // namespace _sub
} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
