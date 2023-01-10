// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

#include "substructures/rawrangeandanglebeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

/**
 * @brief This datagram is used for the models EM 2040, EM 2040C, EM 710, EM 122, EM
302 and ME70BO. All receiver beams are included, check detection info and real time
cleaning for beam status (note 4 and 5).
 */
class RawRangeAndAngle : public EM3000Datagram
{
  protected:
    uint16_t _ping_counter; ///< sequential number
    uint16_t _system_serial_number;
    uint16_t _sound_speed_at_transducer;  ///< in 0.1 m/s
    uint16_t _number_of_transmit_sectors; ///< ntx
    uint16_t _number_of_receiver_beams;   ///< in Datagram nrx
    uint16_t _number_of_valid_detections;
    float    _sampling_frequency;
    uint32_t _d_scale;

    std::vector<substructures::RawRangeAndAngleTransmitSector> _transmit_sectors;
    std::vector<substructures::RawRangeAndAngleBeam>           _beams;

    uint8_t  _spare = 0;
    uint8_t  _etx   = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit RawRangeAndAngle(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    RawRangeAndAngle() { _datagram_identifier = t_EM3000DatagramIdentifier::RawRangeAndAngle; }
    ~RawRangeAndAngle() = default;

    // ----- convenient data access -----
    uint16_t get_ping_counter() const { return _ping_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_sound_speed_at_transducer() const { return _sound_speed_at_transducer; }
    uint16_t get_number_of_transmit_sectors() const { return _number_of_transmit_sectors; }
    uint16_t get_number_of_receiver_beams() const { return _number_of_receiver_beams; }
    uint16_t get_number_of_valid_detections() const { return _number_of_valid_detections; }
    float    get_sampling_frequency() const { return _sampling_frequency; }
    uint32_t get_d_scale() const { return _d_scale; }

    const std::vector<substructures::RawRangeAndAngleTransmitSector>& get_transmit_sectors() const
    {
        return _transmit_sectors;
    }
    const std::vector<substructures::RawRangeAndAngleBeam>& get_beams() const { return _beams; }

    uint8_t  get_spare() const { return _spare; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // read/write access to structures
    std::vector<substructures::RawRangeAndAngleTransmitSector>& transmit_sectors()
    {
        return _transmit_sectors;
    }
    std::vector<substructures::RawRangeAndAngleBeam>& beams() { return _beams; }

    // set
    void set_ping_counter(uint16_t ping_counter) { _ping_counter = ping_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_sound_speed_at_transducer(uint16_t sound_speed_at_transducer)
    {
        _sound_speed_at_transducer = sound_speed_at_transducer;
    }
    void set_number_of_transmit_sectors(uint16_t number_of_transmit_sectors)
    {
        _number_of_transmit_sectors = number_of_transmit_sectors;
    }
    void set_number_of_receiver_beams(uint16_t number_of_receiver_beams)
    {
        _number_of_receiver_beams = number_of_receiver_beams;
    }
    void set_number_of_valid_detections(uint16_t number_of_valid_detections)
    {
        _number_of_valid_detections = number_of_valid_detections;
    }
    void set_sampling_frequency(float sampling_frequency)
    {
        _sampling_frequency = sampling_frequency;
    }
    void set_d_scale(uint32_t d_scale) { _d_scale = d_scale; }

    void set_transmit_sectors(
        const std::vector<substructures::RawRangeAndAngleTransmitSector>& transmit_sector)
    {
        _transmit_sectors = transmit_sector;
    }
    void set_beams(const std::vector<substructures::RawRangeAndAngleBeam>& beams)
    {
        _beams = beams;
    }

    void set_spare(uint8_t spare) { _spare = spare; }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- processed data access -----
    /**
     * @brief Get the sound speed at the transducerin meters per seconds
     *
     * @return _sound_speed_at_transducer * 0.1 meters per seconds (float)
     */
    float get_sound_speed_at_transducer_in_m_per_s() const { return _sound_speed * 0.1; }

    // ----- operators -----
    bool operator==(const RawRangeAndAngle& other) const
    {
        return _datagram_identifier == other._datagram_identifier &&
               _datagram_size == other._datagram_size && _ping_counter == other._ping_counter &&
               _system_serial_number == other._system_serial_number &&
               _sound_speed == other._sound_speed &&
               _number_of_transmit_sectors == other._number_of_transmit_sectors &&
               _number_of_receiver_beams == other._number_of_receiver_beams &&
               _number_of_valid_detections == other._number_of_valid_detections &&
               _sampling_frequency == other._sampling_frequency && _d_scale == other._d_scale &&
               _transmit_sectors == other._transmit_sectors && _beams == other._beams &&
               _spare == other._spare && _etx == other._etx && _checksum == other._checksum;
    }
    bool operator!=(const RawRangeAndAngle& other) const { return !operator==(other); }

    //----- to/from stream functions -----
    static RawRangeAndAngle from_stream(std::istream& is, EM3000Datagram header)
    {
        RawRangeAndAngle datagram(std::move(header));

        if (datagram._datagram_identifier != t_EM3000DatagramIdentifier::RawRangeAndAngle)
            throw std::runtime_error(
                fmt::format("RawRangeAndAngle: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                            uint8_t(t_EM3000DatagramIdentifier::RawRangeAndAngle),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first transmit sector)
        is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 20 * sizeof(uint8_t));

        // read the transmit sectors
        datagram._transmit_sectors.resize(datagram._number_of_transmit_sectors);
        is.read(reinterpret_cast<char*>(datagram._transmit_sectors.data()),
                datagram._number_of_transmit_sectors *
                    sizeof(substructures::RawRangeAndAngleTransmitSector));

        // read the beams
        datagram._beams.resize(datagram._number_of_receiver_beams);
        is.read(reinterpret_cast<char*>(datagram._beams.data()),
                datagram._number_of_receiver_beams * sizeof(substructures::RawRangeAndAngleBeam));

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._spare)), 4 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "RawRangeAndAngle: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static RawRangeAndAngle from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static RawRangeAndAngle from_stream(std::istream&              is,
                                        t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os)
    {
        EM3000Datagram::to_stream(os);
        _number_of_transmit_sectors = _transmit_sectors.size();
        _number_of_receiver_beams   = _beams.size();

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_ping_counter)), 20 * sizeof(uint8_t));

        // write the transmit sectors
        os.write(reinterpret_cast<const char*>(_transmit_sectors.data()),
                 _number_of_transmit_sectors *
                     sizeof(substructures::RawRangeAndAngleTransmitSector));

        // write the beams
        os.write(reinterpret_cast<const char*>(_beams.data()),
                 _number_of_receiver_beams * sizeof(substructures::RawRangeAndAngleBeam));

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_spare)), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("RawRangeAndAngle", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("ping_counter", _ping_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("sound_speed_at_transducer", _sound_speed_at_transducer, "0.1 m/s");
        printer.register_value("number_of_transmit_sectors", _number_of_transmit_sectors, "ntx");
        printer.register_value("number_of_receiver_beams", _number_of_receiver_beams, "nrx");
        printer.register_value("number_of_valid_detections", _number_of_valid_detections);
        printer.register_value("sampling_frequency", _sampling_frequency);
        printer.register_value("d_scale", _d_scale);
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        printer.register_section("processed");
        printer.register_value(
            "sound_speed_at_transducer", get_sound_speed_at_transducer_in_m_per_s(), "m/s");

        printer.register_section("substructures");
        printer.register_value("RawRangeAndAngleBeams", _beams.size(), "structures");
        printer.register_value(
            "RawRangeAndAngleTransmitSectors", _transmit_sectors.size(), "structures");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(RawRangeAndAngle)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
