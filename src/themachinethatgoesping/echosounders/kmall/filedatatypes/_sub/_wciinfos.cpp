// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "_wciinfos.hpp"

#include <cstring>

#ifdef PETER

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatatypes {
namespace _sub {

_WCIInfos::_WCIInfos(const datagrams::WatercolumnDatagram& water_column_datagram)
{
    _sound_speed_at_transducer = water_column_datagram.get_sound_speed_m_s();
    _tvg_function_applied      = water_column_datagram.get_tvg_function_applied();
    _tvg_offset_in_db          = water_column_datagram.get_tvg_offset_in_db();
    _sampling_interval         = 1 / water_column_datagram.get_sampling_frequency_in_hz();

    _transmit_sectors           = water_column_datagram.get_transmit_sectors();
    _number_of_transmit_sectors = _transmit_sectors.size();
}

void _WCIInfos::set_sound_speed_at_transducer(float sound_speed_at_transducer)
{
    _sound_speed_at_transducer = sound_speed_at_transducer;
}

void _WCIInfos::set_tvg_function_applied(uint8_t tvg_function_applied)
{
    _tvg_function_applied = tvg_function_applied;
}

void _WCIInfos::set_transmit_sectors(
    const std::vector<datagrams::substructures::WatercolumnDatagramTransmitSector>&
        transmit_sectors)
{
    _transmit_sectors           = transmit_sectors;
    _number_of_transmit_sectors = transmit_sectors.size();
}

_WCIInfos _WCIInfos::from_binary(std::string_view buffer)
{
    static const size_t size_bytes = 2 * sizeof(float) + 2 * sizeof(uint8_t) + sizeof(int8_t);

    _WCIInfos dat;

    std::memcpy(&dat._sound_speed_at_transducer, buffer.data(), size_bytes);
    dat._transmit_sectors.resize(dat._number_of_transmit_sectors);

    std::memcpy(dat._transmit_sectors.data(),
                buffer.data() + size_bytes,
                dat._number_of_transmit_sectors *
                    sizeof(datagrams::substructures::WatercolumnDatagramTransmitSector));

    return dat;
}

std::string _WCIInfos::to_binary() const
{
    static const size_t size_bytes = 2 * sizeof(float) + 2 * sizeof(uint8_t) + sizeof(int8_t);

    std::string buffer;

    buffer.resize(size_bytes +
                  _transmit_sectors.size() *
                      sizeof(datagrams::substructures::WatercolumnDatagramTransmitSector));

    std::memcpy(buffer.data(), this, size_bytes);
    std::memcpy(buffer.data() + size_bytes,
                _transmit_sectors.data(),
                _transmit_sectors.size() *
                    sizeof(datagrams::substructures::WatercolumnDatagramTransmitSector));

    return buffer;
}

const std::vector<datagrams::substructures::WatercolumnDatagramTransmitSector>&
_WCIInfos::get_transmit_sectors() const
{
    return _transmit_sectors;
}

} // namespace _sub
} // namespace filedatatypes
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping

#endif