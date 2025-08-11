// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/surfacesoundspeeddatagram.doc.hpp"

// std includes
#include <string>
#include <vector>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief Sound_speed datagrams
 */
class SurfaceSoundSpeedDatagram : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier =
        t_KongsbergAllDatagramIdentifier::SurfaceSoundSpeedDatagram;

  protected:
    uint16_t _sound_speed_counter; ///< Sequential Number
    uint16_t _system_serial_number;
    uint16_t _number_of_entries = 0; ///< N

    xt::xtensor<uint16_t, 2> _times_and_sound_speeds; ///< 2xN array of time in ms since record
                                                      ///< start and sound_speed in dm/s

    uint8_t  _spare;
    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit SurfaceSoundSpeedDatagram(KongsbergAllDatagram header)
        : KongsbergAllDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    SurfaceSoundSpeedDatagram()
    {
        _datagram_identifier = t_KongsbergAllDatagramIdentifier::SurfaceSoundSpeedDatagram;
    }
    ~SurfaceSoundSpeedDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_sound_speed_counter() const { return _sound_speed_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_number_of_entries() const { return _number_of_entries; }
    uint8_t  get_spare() const { return _spare; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_sound_speed_counter(uint16_t sound_speed_counter)
    {
        _sound_speed_counter = sound_speed_counter;
    }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_number_of_entries(int32_t number_of_entries)
    {
        _number_of_entries = number_of_entries;
    }
    void set_spare(uint8_t spare) { _spare = spare; }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // substructures
    xt::xtensor<uint16_t, 2>&       times_and_sound_speeds() { return _times_and_sound_speeds; }
    const xt::xtensor<uint16_t, 2>& get_times_and_sound_speeds() const
    {
        return _times_and_sound_speeds;
    }
    void set_times_and_sound_speeds(xt::xtensor<uint16_t, 2> times_and_sound_speeds)
    {
        _times_and_sound_speeds = std::move(times_and_sound_speeds);
    }

    // ----- processed data access -----
    /**
     * @brief return the times converted to unix timestamps
     *
     * @return np.array([_number_of_entries], dtype = np.float64)
     */
    xt::xtensor<double, 1> get_sound_speed_timestamps() const
    {
        double timestamp = get_timestamp();

        // the output timestamp is the timestamp of the datagram plus the time of the entry
        return xt::view(_times_and_sound_speeds, xt::all(), 0) * 0.001 + timestamp;
    }

    /**
     * @brief return sound_speeds in meters by multiplying the surface sound_speed by 0.1
     *
     * @return np.array([_number_of_entries], dtype = np.float32)
     */
    xt::xtensor<float, 1> get_sound_speeds_in_meters_per_second() const
    {
        return xt::view(_times_and_sound_speeds, xt::all(), 1) * 0.1;
    }

    // ----- operators -----
    bool operator==(const SurfaceSoundSpeedDatagram& other) const = default;

    //----- to/from stream functions -----
    static SurfaceSoundSpeedDatagram from_stream(std::istream& is, KongsbergAllDatagram header)
    {
        SurfaceSoundSpeedDatagram datagram(std::move(header));

        if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::SurfaceSoundSpeedDatagram)
            throw std::runtime_error(fmt::format(
                "SurfaceSoundSpeedDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                uint8_t(t_KongsbergAllDatagramIdentifier::SurfaceSoundSpeedDatagram),
                uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._sound_speed_counter)), 6 * sizeof(uint8_t));

        // read the times and sound_speeds
        if (datagram._number_of_entries > 0)
        {
            datagram._times_and_sound_speeds = xt::empty<uint16_t>(
                xt::xtensor<uint16_t, 2>::shape_type({ datagram._number_of_entries, 2 }));

            is.read(reinterpret_cast<char*>(datagram._times_and_sound_speeds.data()),
                    datagram._times_and_sound_speeds.size() * sizeof(uint16_t));
        }

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._spare)), 4 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(
                fmt::format("SurfaceSoundSpeedDatagram: end identifier is not 0x03, but 0x{:x}",
                            datagram._etx));

        return datagram;
    }

    static SurfaceSoundSpeedDatagram from_stream(std::istream& is)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is));
    }

    static SurfaceSoundSpeedDatagram from_stream(std::istream&              is,
                                                 t_KongsbergAllDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
    }

    void to_stream(std::ostream& os) const
    {
        if (_number_of_entries != _times_and_sound_speeds.shape()[0])
            throw std::runtime_error(fmt::format(
                "SurfaceSoundSpeedDatagram: number of entries ({}) does not match the size of "
                "the times_and_sound_speeds array ({})",
                _number_of_entries,
                _times_and_sound_speeds.shape()[0]));

        KongsbergAllDatagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_sound_speed_counter)), 6 * sizeof(uint8_t));

        // write the times and sound_speeds
        os.write(reinterpret_cast<const char*>(_times_and_sound_speeds.data()),
                 _times_and_sound_speeds.size() * sizeof(uint16_t));

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_spare)), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("SurfaceSoundSpeedDatagram", float_precision, superscript_exponents);

        printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
        printer.register_section("datagram content");
        printer.register_value("sound_speed_counter", _sound_speed_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("number_of_entries", _number_of_entries);

        printer.register_section("processed");
        printer.register_container("sound_speed_timestamps", get_sound_speed_timestamps(), "s");
        printer.register_container("sound_speeds", get_sound_speeds_in_meters_per_second(), "m");

        printer.register_section("substructures");
        printer.register_container("times_and_sound_speeds", _times_and_sound_speeds);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SurfaceSoundSpeedDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
