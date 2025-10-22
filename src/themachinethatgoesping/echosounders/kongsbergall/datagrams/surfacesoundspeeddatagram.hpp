// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/surfacesoundspeeddatagram.doc.hpp"

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
    explicit SurfaceSoundSpeedDatagram(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    SurfaceSoundSpeedDatagram();
    ~SurfaceSoundSpeedDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_sound_speed_counter() const;
    uint16_t get_system_serial_number() const;
    uint16_t get_number_of_entries() const;
    uint8_t  get_spare() const;
    uint8_t  get_etx() const;
    uint16_t get_checksum() const;

    // setters
    void set_sound_speed_counter(uint16_t sound_speed_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_number_of_entries(int32_t number_of_entries);
    void set_spare(uint8_t spare);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // substructures
    xt::xtensor<uint16_t, 2>&       times_and_sound_speeds();
    const xt::xtensor<uint16_t, 2>& get_times_and_sound_speeds() const;
    void set_times_and_sound_speeds(xt::xtensor<uint16_t, 2> times_and_sound_speeds);

    // ----- processed data access -----
    /**
     * @brief return the times converted to unix timestamps
     *
     * @return np.array([_number_of_entries], dtype = np.float64)
     */
    xt::xtensor<double, 1> get_sound_speed_timestamps() const;

    /**
     * @brief return sound_speeds in meters by multiplying the surface sound_speed by 0.1
     *
     * @return np.array([_number_of_entries], dtype = np.float32)
     */
    xt::xtensor<float, 1> get_sound_speeds_in_meters_per_second() const;

    // ----- operators -----
    bool operator==(const SurfaceSoundSpeedDatagram& other) const = default;

    //----- to/from stream functions -----
    static SurfaceSoundSpeedDatagram from_stream(std::istream& is, KongsbergAllDatagram header);

    static SurfaceSoundSpeedDatagram from_stream(std::istream& is);

    static SurfaceSoundSpeedDatagram from_stream(std::istream&              is,
                                                 t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SurfaceSoundSpeedDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
