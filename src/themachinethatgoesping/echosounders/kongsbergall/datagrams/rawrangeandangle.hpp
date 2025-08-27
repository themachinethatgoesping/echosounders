// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/rawrangeandangle.doc.hpp"

// std includes
#include <string>
#include <vector>

// xtensor includes
#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

#include "substructures/rawrangeandanglebeam.hpp"
#include "substructures/rawrangeandangletransmitsector.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief This datagram is used for the models EM 2040, EM 2040C, EM 710, EM 122, EM
302 and ME70BO. All receiver beams are included, check detection info and real time
cleaning for beam status (note 4 and 5).
 */
class RawRangeAndAngle : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::RawRangeAndAngle;

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
    explicit RawRangeAndAngle(KongsbergAllDatagram header)
        : KongsbergAllDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    RawRangeAndAngle()
    {
        _datagram_identifier = t_KongsbergAllDatagramIdentifier::RawRangeAndAngle;
    }
    ~RawRangeAndAngle() = default;

    // ----- convenience functions -----
    /**
     * @brief Read the two way travel times from the RawRangeAndAngle structure
     *
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 1> get_two_way_travel_times() const
    {
        auto twtt = xt::xtensor<float, 1>::from_shape({ _beams.size() });

        for (unsigned int bn = 0; bn < _beams.size(); ++bn)
        {
            twtt.unchecked(bn) = _beams[bn].get_two_way_travel_time();
        }

        return twtt;
    }

    /**
     * @brief Read the two way travel times for given beam_number vector from the RawRangeAndAngle
     * structure Note: if a beam number is not found, the corresponding time value will be NaN
     *
     * @param beam_numbers
     *
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 1> get_two_way_travel_times(const std::vector<uint32_t>& beam_numbers) const
    {
        auto twtt = xt::xtensor<float, 1>::from_shape({ beam_numbers.size() });

        for (const auto bn : beam_numbers)
        {
            if (bn >= _beams.size())
                twtt.unchecked(bn) = std::numeric_limits<float>::quiet_NaN();
            else
                twtt.unchecked(bn) = _beams[bn].get_two_way_travel_time();
        }

        return twtt;
    }
    /**
     * @brief Read the beam crosstrack angles from the RawRangeAndAngle structure
     *
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 1> get_beam_crosstrack_angles() const
    {
        auto bpa = xt::xtensor<float, 1>::from_shape({ _beams.size() });

        for (unsigned int bn = 0; bn < _beams.size(); ++bn)
        {
            bpa.unchecked(bn) = _beams[bn].get_beam_crosstrack_angle();
        }

        return bpa;
    }

    /**
     * @brief Read the two way travel times for given beam_number vector from the RawRangeAndAngle
     * structure Note: if a beam number is not found, the corresponding time value will be NaN
     *
     * @param beam_numbers
     *
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 1> get_beam_crosstrack_angles(
        const std::vector<uint32_t>& beam_numbers) const
    {
        auto angles = xt::xtensor<float, 1>::from_shape({ beam_numbers.size() });

        for (unsigned int i = 0; i < beam_numbers.size(); ++i)
        {
            if (beam_numbers[i] >= _beams.size())
                angles.unchecked(i) = std::numeric_limits<float>::quiet_NaN();
            else
                angles.unchecked(i) = _beams[beam_numbers[i]].get_beam_crosstrack_angle_in_degrees();
        }

        return angles;
    }

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
    float get_sound_speed_at_transducer_in_m_per_s() const
    {
        return _sound_speed_at_transducer * 0.1;
    }

    // ----- operators -----
    bool operator==(const RawRangeAndAngle& other) const = default;

    //----- to/from stream functions -----
    static RawRangeAndAngle from_stream(std::istream& is, KongsbergAllDatagram header);

    static RawRangeAndAngle from_stream(std::istream& is);

    static RawRangeAndAngle from_stream(std::istream&                    is,
                                        t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(RawRangeAndAngle)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
