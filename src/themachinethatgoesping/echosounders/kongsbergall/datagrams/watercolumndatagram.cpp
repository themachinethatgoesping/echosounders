// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "watercolumndatagram.hpp"

#include <fmt/core.h>
#include <stdexcept>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

WatercolumnDatagram WatercolumnDatagram::from_stream(std::istream&        is,
                                                     KongsbergAllDatagram header,
                                                     bool                 skip_data)
{
    WatercolumnDatagram datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::WatercolumnDatagram)
        throw std::runtime_error(fmt::format(
            "WatercolumnDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
            uint8_t(t_KongsbergAllDatagramIdentifier::WatercolumnDatagram),
            uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 28 * sizeof(uint8_t));

    // read the transmit_sectors
    datagram._transmit_sectors.resize(datagram._number_of_transmit_sectors);
    is.read(reinterpret_cast<char*>(datagram._transmit_sectors.data()),
            datagram._number_of_transmit_sectors *
                sizeof(substructures::WatercolumnDatagramTransmitSector));

    // read the beams
    datagram._beams.reserve(datagram._number_of_beams_in_datagram);
    for (auto i = 0; i < datagram._number_of_beams_in_datagram; ++i)
        datagram._beams.push_back(
            substructures::WatercolumnDatagramBeam::from_stream(is, skip_data));

    // read the rest of the datagram
    is.read(reinterpret_cast<char*>(&(datagram._spare_byte)), 4 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "WatercolumnDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

WatercolumnDatagram WatercolumnDatagram::from_stream(std::istream& is, bool skip_data)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is), skip_data);
}

WatercolumnDatagram WatercolumnDatagram::from_stream(std::istream&                    is,
                                                     t_KongsbergAllDatagramIdentifier datagram_identifier,
                                                     bool                             skip_data)
{
    return from_stream(
        is, KongsbergAllDatagram::from_stream(is, datagram_identifier), skip_data);
}

void WatercolumnDatagram::append_from_stream(std::istream& is)
{
    bool skip_data = _beams.at(0).get_samples_are_skipped();

    /* skip header + ping_counter - number of datagrams*/
    is.seekg(22, std::ios_base::cur);

    /* read important variables */
    struct
    {
        uint16_t datagram_number;
        uint16_t number_of_transmit_sectors;
        uint16_t total_no_of_receive_beams;
        uint16_t number_of_beams_in_datagram;
    } data;

    is.read(reinterpret_cast<char*>(&data.datagram_number), sizeof(data));

    /* check if number of beams makes sense */
    if (_number_of_beams_in_datagram + data.number_of_beams_in_datagram >
        _total_no_of_receive_beams)
        throw std::runtime_error(
            fmt::format("ERROR[WatercolumnDatagram::append_from_stream]: number of append "
                        "beams [{}] exceeds total number of beams [{}/{}]",
                        data.number_of_beams_in_datagram,
                        _number_of_beams_in_datagram,
                        _total_no_of_receive_beams));

    /* sanity checks */
    if (data.datagram_number > _number_of_datagrams)
        throw std::runtime_error(
            fmt::format("ERROR[WatercolumnDatagram::append_from_stream]: datagram number "
                        "exceeds number of datagrams [{}/{}]",
                        data.datagram_number,
                        _number_of_datagrams));
    if (data.number_of_transmit_sectors != _number_of_transmit_sectors)
        throw std::runtime_error(fmt::format("ERROR[WatercolumnDatagram::append_from_stream]: "
                                             "number_of_transmit_sectors missmatch [{}/{}]",
                                             data.number_of_transmit_sectors,
                                             _number_of_transmit_sectors));
    if (data.total_no_of_receive_beams != _total_no_of_receive_beams)
        throw std::runtime_error(fmt::format("ERROR[WatercolumnDatagram::append_from_stream]: "
                                             "total_no_of_receive_beams missmatch [{}/{}]",
                                             data.total_no_of_receive_beams,
                                             _total_no_of_receive_beams));

    /* skip the rest of the data and the transmit sectors */
    is.seekg(14 + data.number_of_transmit_sectors *
                      sizeof(substructures::WatercolumnDatagramTransmitSector),
             std::ios_base::cur);

    /* update new number of beams in datagram */
    _number_of_beams_in_datagram += data.number_of_beams_in_datagram;

    // read the additional beams
    _beams.reserve(_total_no_of_receive_beams);
    for (auto i = 0; i < data.number_of_beams_in_datagram; ++i)
        _beams.push_back(substructures::WatercolumnDatagramBeam::from_stream(is, skip_data));

    // read the rest of the datagram
    is.read(reinterpret_cast<char*>(&(_spare_byte)), 4 * sizeof(uint8_t));

    if (_etx != 0x03)
        throw std::runtime_error(
            fmt::format("WatercolumnDatagram: end identifier is not 0x03, but 0x{:x}", _etx));
}

void WatercolumnDatagram::to_stream(std::ostream& os)
{
    KongsbergAllDatagram::to_stream(os);
    _number_of_transmit_sectors  = _transmit_sectors.size();
    _number_of_beams_in_datagram = _beams.size();

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_ping_counter)), 28 * sizeof(uint8_t));

    // write the transmit sector
    os.write(reinterpret_cast<const char*>(_transmit_sectors.data()),
             _number_of_transmit_sectors *
                 sizeof(substructures::WatercolumnDatagramTransmitSector));

    // write the beams
    for (auto beam : _beams)
        beam.to_stream(os);

    // write the rest of the datagram
    os.write(reinterpret_cast<const char*>(&(_spare_byte)), 4 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter WatercolumnDatagram::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("WatercolumnDatagram", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("ping_counter", _ping_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("number_of_datagrams", _number_of_datagrams);
    printer.register_value("datagram_number", _datagram_number);
    printer.register_value("number_of_transmit_sectors", _number_of_transmit_sectors);
    printer.register_value("total_no_of_receive_beams", _total_no_of_receive_beams);
    printer.register_value("number_of_beams_in_datagram", _number_of_beams_in_datagram);
    printer.register_value("sound_speed", _sound_speed, "0.1 m/s");
    printer.register_value("sampling_frequency", _sampling_frequency, "0.01 Hz");
    printer.register_value("tx_time_heave", _tx_time_heave, "cm");
    printer.register_value("tvg_function_applied", _tvg_function_applied);
    printer.register_value("tvg_offset_in_db", _tvg_offset_in_db);
    printer.register_string("scanning_info", fmt::format("0b{:08b}", _scanning_info));
    printer.register_string("spare",
                            fmt::format("0x{:1x}{:1x}{:1x}", _spare[0], _spare[1], _spare[2]));
    printer.register_value("spare_byte", _spare_byte);

    printer.register_section("processed");
    printer.register_value("sound_speed", get_sound_speed_m_s(), "m/s");
    printer.register_value("sampling_frequency", get_sampling_frequency_in_hz(), "Hz");
    printer.register_value("tx_time_heave", get_tx_time_heave_in_m(), "m");

    printer.register_section("substructures");
    printer.register_value(
        "transmit_sectors", _transmit_sectors.size(), "WatercolumnDatagramTransmitSector");
    printer.register_value("beams", _beams.size(), "WatercolumnDatagramBeams");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
