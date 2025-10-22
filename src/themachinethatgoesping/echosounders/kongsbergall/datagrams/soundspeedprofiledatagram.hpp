// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/soundspeedprofiledatagram.doc.hpp"

// std includes
#include <cstdint>
#include <string>

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
    explicit SoundSpeedProfileDatagram(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    SoundSpeedProfileDatagram();
    ~SoundSpeedProfileDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_profile_counter() const;
    uint16_t get_system_serial_number() const;
    uint32_t get_profile_date() const;
    uint32_t get_profile_time_since_midnight() const;
    uint16_t get_number_of_entries() const;
    uint16_t get_depth_resolution() const;

    uint8_t  get_spare() const;
    uint8_t  get_etx() const;
    uint16_t get_checksum() const;

    // setters
    void set_profile_counter(uint16_t profile_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_profile_date(uint32_t profile_date);
    void set_profile_time_since_midnight(uint32_t profile_time_since_midnight);
    void set_number_of_entries(int32_t number_of_entries);
    void set_depth_resolution(uint16_t depth_resolution);
    void set_spare(uint8_t spare);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // substructures
    xt::xtensor<uint32_t, 2>&       depths_and_sound_speeds();
    const xt::xtensor<uint32_t, 2>& get_depths_and_sound_speeds() const;
    void set_depths_and_sound_speeds(const xt::xtensor<uint32_t, 2>& depths_and_sound_speeds);

    // ----- processed data access -----
    /**
     * @brief return the depths in meters
     *
     * @return _depth_resolution * 0.01 (float)
     */
    float get_depth_resolution_in_meters() const;

    /**
     * @brief return the depths in meters by multiplying the depths by 0.01
     *
     * @return np.array([_number_of_entries], dtype = np.float64)
     */
    xt::xtensor<double, 1> get_depths_in_meters() const;

    /**
     * @brief return sound speeds in meter per second by multiplying the sound_speeds by 0.1
     *
     * @return np.array([_number_of_entries], dtype = np.float32)
     */
    xt::xtensor<float, 1> get_sound_speeds_in_meters_per_second() const;

    /**
     * @brief convert the profile date and time_since_midnight field to a unix timestamp
     *
     * @return unixtime as double
     */
    double get_profile_timestamp() const;

    /**
     * @brief Get the profile time as string
     *
     * @param fractionalSecondsDigits
     * @param format
     * @return std::string
     */
    std::string get_profile_date_string(unsigned int       fractionalSecondsDigits = 2,
                                        const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const;

    // ----- operators -----
    bool operator==(const SoundSpeedProfileDatagram& other) const = default;

    //----- to/from stream functions -----
    static SoundSpeedProfileDatagram from_stream(std::istream& is, KongsbergAllDatagram header);

    static SoundSpeedProfileDatagram from_stream(std::istream& is);

    static SoundSpeedProfileDatagram from_stream(std::istream&              is,
                                                 t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SoundSpeedProfileDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
