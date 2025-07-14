// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/soundspeedprofiledatagram.doc.hpp"

// std includes
#include <string>
#include <vector>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>


#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief This datagram will contain the profile actually used in the real time raybending
 * calculations to convert range and angle to xyz data. It will usually be issued together with the
 * installation parameter datagram.
 */
class SoundSpeedProfileDatagram : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier =
        t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram;

  protected:
    uint16_t _profile_counter; ///< Sequential Number
    uint16_t _system_serial_number;
    uint32_t _profile_date; ///< year*10000 + month*100 + day (when profile was taken)
    uint32_t _profile_time_since_midnight; ///< time since midnight in milliseconds (when profile
                                           ///< was taken)
    uint16_t _number_of_entries = 0;       ///< N
    uint16_t _depth_resolution;            ///< in cm

    xt::xtensor<uint32_t, 2>
        _depths_and_sound_speeds; ///< 2xN array of depth in cm and sound speed in dm/s

    uint8_t  _spare;
    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit SoundSpeedProfileDatagram(KongsbergAllDatagram header)
        : KongsbergAllDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    SoundSpeedProfileDatagram()
    {
        _datagram_identifier = t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram;
    }
    ~SoundSpeedProfileDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_profile_counter() const { return _profile_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint32_t get_profile_date() const { return _profile_date; }
    uint32_t get_profile_time_since_midnight() const { return _profile_time_since_midnight; }
    uint16_t get_number_of_entries() const { return _number_of_entries; }
    uint16_t get_depth_resolution() const { return _depth_resolution; }

    uint8_t  get_spare() const { return _spare; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_profile_counter(uint16_t profile_counter) { _profile_counter = profile_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_profile_date(uint32_t profile_date) { _profile_date = profile_date; }
    void set_profile_time_since_midnight(uint32_t profile_time_since_midnight)
    {
        _profile_time_since_midnight = profile_time_since_midnight;
    }
    void set_number_of_entries(int32_t number_of_entries)
    {
        _number_of_entries = number_of_entries;
    }
    void set_depth_resolution(uint16_t depth_resolution) { _depth_resolution = depth_resolution; }
    void set_spare(uint8_t spare) { _spare = spare; }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // substructures
    xt::xtensor<uint32_t, 2>&       depths_and_sound_speeds() { return _depths_and_sound_speeds; }
    const xt::xtensor<uint32_t, 2>& get_depths_and_sound_speeds() const
    {
        return _depths_and_sound_speeds;
    }
    void set_depths_and_sound_speeds(const xt::xtensor<uint32_t, 2>& depths_and_sound_speeds)
    {
        _depths_and_sound_speeds = depths_and_sound_speeds;
    }

    // ----- processed data access -----
    /**
     * @brief return the depths in meters
     *
     * @return _depth_resolution * 0.01 (float)
     */
    float get_depth_resolution_in_meters() const { return _depth_resolution * 0.01; }

    /**
     * @brief return the depths in meters by multiplying the depths by 0.01
     *
     * @return np.array([_number_of_entries], dtype = np.float64)
     */
    xt::xtensor<double, 1> get_depths_in_meters() const
    {
        // the output timestamp is the timestamp of the datagram plus the time of the entry
        return xt::view(_depths_and_sound_speeds, xt::all(), 0) * 0.01;
    }

    /**
     * @brief return sound speeds in meter per second by multiplying the sound_speeds by 0.1
     *
     * @return np.array([_number_of_entries], dtype = np.float32)
     */
    xt::xtensor<float, 1> get_sound_speeds_in_meters_per_second() const
    {
        return xt::view(_depths_and_sound_speeds, xt::all(), 1) * 0.1;
    }

    /**
     * @brief convert the profile date and time_since_midnight field to a unix timestamp
     *
     * @return unixtime as double
     */
    double get_profile_timestamp() const
    {
        int y = int(_profile_date / 10000);
        int m = int(_profile_date / 100) - y * 100;
        int d = int(_profile_date) - y * 10000 - m * 100;

        return tools::timeconv::year_month_day_to_unixtime(
            y, m, d, uint64_t(_profile_time_since_midnight) * 1000);
    }

    /**
     * @brief Get the profile time as string
     *
     * @param fractionalSecondsDigits
     * @param format
     * @return std::string
     */
    std::string get_profile_date_string(unsigned int       fractionalSecondsDigits = 2,
                                        const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const
    {
        return tools::timeconv::unixtime_to_datestring(
            get_profile_timestamp(), fractionalSecondsDigits, format);
    }

    // ----- operators -----
    bool operator==(const SoundSpeedProfileDatagram& other) const = default;

    //----- to/from stream functions -----
    static SoundSpeedProfileDatagram from_stream(std::istream& is, KongsbergAllDatagram header)
    {
        SoundSpeedProfileDatagram datagram(std::move(header));

        if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram)
            throw std::runtime_error(fmt::format(
                "SoundSpeedProfileDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                uint8_t(t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram),
                uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._profile_counter)), 16 * sizeof(uint8_t));

        // read the depths and sound speeds
        if (datagram._number_of_entries > 0)
        {
            datagram._depths_and_sound_speeds = xt::empty<uint16_t>(
                xt::xtensor<uint32_t, 2>::shape_type({ datagram._number_of_entries, 2 }));

            is.read(reinterpret_cast<char*>(datagram._depths_and_sound_speeds.data()),
                    datagram._depths_and_sound_speeds.size() * sizeof(uint32_t));
        }

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._spare)), 4 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(
                fmt::format("SoundSpeedProfileDatagram: end identifier is not 0x03, but 0x{:x}",
                            datagram._etx));

        return datagram;
    }

    static SoundSpeedProfileDatagram from_stream(std::istream& is)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is));
    }

    static SoundSpeedProfileDatagram from_stream(std::istream&              is,
                                                 t_KongsbergAllDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
    }

    void to_stream(std::ostream& os) const
    {
        if (_number_of_entries != _depths_and_sound_speeds.shape()[0])
            throw std::runtime_error(fmt::format(
                "SoundSpeedProfileDatagram: number of entries ({}) does not match the size of "
                "the depths_and_sound_speeds array ({})",
                _number_of_entries,
                _depths_and_sound_speeds.shape()[0]));

        KongsbergAllDatagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_profile_counter)), 16 * sizeof(uint8_t));

        // write the depths and sound speeds
        os.write(reinterpret_cast<const char*>(_depths_and_sound_speeds.data()),
                 _depths_and_sound_speeds.size() * sizeof(uint32_t));

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_spare)), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        using tools::timeconv::unixtime_to_datestring;

        static const std::string format_date("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        auto                     timestamp = get_profile_timestamp();

        auto date = unixtime_to_datestring(timestamp, 0, format_date);
        auto time = unixtime_to_datestring(timestamp, 3, format_time);

        tools::classhelper::ObjectPrinter printer("SoundSpeedProfileDatagram", float_precision, superscript_exponents);

        printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
        printer.register_section("datagram content");
        printer.register_value("profile_counter", _profile_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("number_of_entries", _number_of_entries);
        printer.register_value("depth_resolution", _depth_resolution, "cm");

        printer.register_section("processed");
        printer.register_value("profile_timestamp", timestamp, "s");
        printer.register_string("profile_date", date, "MM/DD/YYYY");
        printer.register_string("profile_time", time, "HH:MM:SS");
        printer.register_value("depth_resolution", get_depth_resolution_in_meters(), "m");
        printer.register_container("meters", get_depths_in_meters(), "s");
        printer.register_container("sound_speeds", get_sound_speeds_in_meters_per_second(), "°");

        printer.register_section("substructures");
        printer.register_container("depths_and_sound_speeds", _depths_and_sound_speeds);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SoundSpeedProfileDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
