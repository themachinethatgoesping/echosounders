// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumndatagram.doc.hpp"

// std includes
#include <array>
#include <cstdint>
#include <iosfwd>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include <xtensor/containers/xtensor.hpp>

#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

#include "substructures/watercolumndatagrambeam.hpp"
#include "substructures/watercolumndatagramtransmitsector.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief Used for EM 122, EM 302, EM 710, EM 2040, EM 3002.
 * The receiver beams are roll stabilized.
 */
class WatercolumnDatagram : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier =
        t_KongsbergAllDatagramIdentifier::WatercolumnDatagram;

  protected:
    uint16_t               _ping_counter;
    uint16_t               _system_serial_number;
    uint16_t               _number_of_datagrams;
    uint16_t               _datagram_number;
    uint16_t               _number_of_transmit_sectors; ///< Transmit_sector vector of 2 elements
    uint16_t               _total_no_of_receive_beams;
    uint16_t               _number_of_beams_in_datagram; ///< Beam vector of 2 elements
    uint16_t               _sound_speed;                 ///< in 0.1 m/s
    uint32_t               _sampling_frequency;          //// in 0.01 Hz resolution
    int16_t                _tx_time_heave;               ///< in cm
    uint8_t                _tvg_function_applied;
    int8_t                 _tvg_offset_in_db;
    uint8_t                _scanning_info;
    std::array<uint8_t, 3> _spare;
    std::vector<substructures::WatercolumnDatagramTransmitSector> _transmit_sectors;
    std::vector<substructures::WatercolumnDatagramBeam>           _beams;

    uint8_t  _spare_byte = 0;
    uint8_t  _etx        = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit WatercolumnDatagram(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    WatercolumnDatagram();
    virtual ~WatercolumnDatagram() = default;

    // ----- convinient processing -----
    size_t get_max_number_of_samples() const;

    // ----- processed data access -----
    xt::xtensor<int8_t, 2> read_samples(std::istream& ifs) const;

    xt::xtensor<float, 2> get_samples() const;

    // ----- convenient data access -----
    // getters
    uint16_t              get_ping_counter() const;
    uint16_t              get_system_serial_number() const;
    uint16_t              get_number_of_datagrams() const;
    uint16_t              get_datagram_number() const;
    uint16_t              get_number_of_transmit_sectors() const;
    uint16_t              get_total_no_of_receive_beams() const;
    uint16_t              get_number_of_beams_in_datagram() const;
    uint16_t              get_sound_speed() const;
    uint32_t              get_sampling_frequency() const;
    int16_t               get_tx_time_heave() const;
    uint8_t               get_tvg_function_applied() const;
    int8_t                get_tvg_offset_in_db() const;
    uint8_t               get_scanning_info() const;
    std::array<uint8_t, 3> get_spare() const;
    uint8_t               get_spare_byte() const;
    uint8_t               get_etx() const;
    uint16_t              get_checksum() const;

    // setters
    void set_ping_counter(uint16_t ping_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_number_of_datagrams(uint16_t number_of_datagrams);
    void set_datagram_number(uint16_t datagram_number);
    void set_number_of_transmit_sectors(uint16_t number_of_transmit_sectors);
    void set_total_no_of_receive_beams(uint16_t total_no_of_receive_beams);
    void set_number_of_beams_in_datagram(uint16_t number_of_beams_in_datagram);
    void set_sound_speed(uint16_t sound_speed);
    void set_sampling_frequency(uint32_t sampling_frequency);
    void set_tx_time_heave(int16_t tx_time_heave);
    void set_tvg_function_applied(uint8_t tvg_function_applied);
    void set_tvg_offset_in_db(int8_t tvg_offset_in_db);
    void set_scanning_info(uint8_t scanning_info);
    void set_spare(std::array<uint8_t, 3> spare);

    void set_spare_byte(uint8_t spare_byte);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // ----- substructure access -----
    const std::vector<substructures::WatercolumnDatagramTransmitSector>& get_transmit_sectors()
        const;
    std::vector<substructures::WatercolumnDatagramTransmitSector>& transmit_sectors();
    void set_transmit_sectors(
        std::vector<substructures::WatercolumnDatagramTransmitSector> transmit_sectors);

    const std::vector<substructures::WatercolumnDatagramBeam>& get_beams() const;
    std::vector<substructures::WatercolumnDatagramBeam>&       beams();
    void set_beams(std::vector<substructures::WatercolumnDatagramBeam> beams);

    // ----- processed data access -----
    /**
     * @brief Get the sound speed in m/s
     *
     * @return _sound_speed * 0.1 m/s (float)
     */
    float get_sound_speed_m_s() const;

    /**
     * @brief Get the sampling frequency in Hz
     *
     * @return _sampling_frequency * 0.01 Hz (float)
     */
    float get_sampling_frequency_in_hz() const;

    /**
     * @brief Get the transmit time heave in m
     *
     * @return _tx_time_heave * 0.01 m (float)
     */
    float get_tx_time_heave_in_m() const;

    // ----- operators -----
    bool operator==(const WatercolumnDatagram& other) const = default;

    //----- to/from stream functions -----
    static WatercolumnDatagram from_stream(std::istream&        is,
                                           KongsbergAllDatagram header,
                                           bool                 skip_data = false);

    static WatercolumnDatagram from_stream(std::istream& is, bool skip_data = false);

    static WatercolumnDatagram from_stream(std::istream&                    is,
                                           t_KongsbergAllDatagramIdentifier datagram_identifier,
                                           bool                             skip_data = false);

    void append_from_stream(std::istream& is);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(WatercolumnDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
