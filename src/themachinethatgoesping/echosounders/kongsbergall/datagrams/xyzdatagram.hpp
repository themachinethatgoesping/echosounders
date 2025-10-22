// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xyzdatagram.doc.hpp"

// std includes
#include <array>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include <themachinethatgoesping/algorithms/geoprocessing/datastructures/xyz.hpp>

#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

#include "substructures/xyzdatagrambeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief This datagram is used for the models EM 2040, EM 2040C, EM 710, EM 122, EM
302 and ME70BO. All receiver beams are included, check detection info and real time
cleaning for beam status (note 4 and 5).
 */
class XYZDatagram : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::XYZDatagram;
    using t_XYZ                              = algorithms::geoprocessing::datastructures::XYZ<1>;

  protected:
    uint16_t _ping_counter;              ///< 0-65535 ping number (in this file)
    uint16_t _system_serial_number;      ///< 100 -
    uint16_t _heading;                   ///< (at TX time) in 0.01 degree
    uint16_t _sound_speed;               ///< at transducer in dm/s
    float    _transmit_transducer_depth; ///< in meter relative water level at time of ping
    uint16_t _number_of_beams;           ///< in Datagram
    uint16_t _number_of_valid_detections;
    float    _sampling_frequency; ///< in Hz
    uint8_t  _scanning_info;      ///< only used by em2040. 0 means scanning is not used.
    std::array<uint8_t, 3>                      _spare_bytes = { 0, 0, 0 };
    std::vector<substructures::XYZDatagramBeam> _beams; ///< beam detection information
    uint8_t                                     _spare_byte = 0;
    uint8_t                                     _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t                                    _checksum;

  private:
    // ----- private constructors -----
    explicit XYZDatagram(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    XYZDatagram();
    ~XYZDatagram() = default;

    // ----- convenience functions -----
    /**
     * @brief Convert the XYZDatagramBeams to a XYZ structure
     *
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    t_XYZ get_xyz() const;

    /**
     * @brief Convert the XYZDatagramBeams for a given beam_number vector to a XYZ structure
     * Note: if a beam number is not found, the corresponding XYZ value will be NaN
     *
     * @param beam_numbers
     *
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    t_XYZ get_xyz(const std::vector<uint32_t>& beam_numbers) const;

    // ----- convenient data access -----
    // getters
    uint16_t                     get_ping_counter() const;
    uint16_t                     get_system_serial_number() const;
    uint16_t                     get_heading() const;
    uint16_t                     get_sound_speed() const;
    float                        get_transmit_transducer_depth() const;
    uint16_t                     get_number_of_beams() const;
    uint16_t                     get_number_of_valid_detections() const;
    float                        get_sampling_frequency() const;
    uint8_t                      get_scanning_info() const;
    const std::array<uint8_t, 3>& get_spare_bytes() const;
    uint8_t                      get_spare_byte() const;
    uint8_t                      get_etx() const;
    uint16_t                     get_checksum() const;

    // setters
    void set_ping_counter(uint16_t ping_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_heading(uint16_t heading);
    void set_sound_speed(uint16_t sound_speed);
    void set_transmit_transducer_depth(float transmit_transducer_depth);
    void set_number_of_beams(uint16_t number_of_beams);
    void set_number_of_valid_detections(uint16_t number_of_valid_detections);
    void set_sampling_frequency(float sampling_frequency);
    void set_scanning_info(uint8_t scanning_info);
    void set_spare_bytes(std::array<uint8_t, 3> spare_bytes);
    void set_spare_byte(uint8_t spare_byte);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // substructure access
    std::vector<substructures::XYZDatagramBeam>&       beams();
    const std::vector<substructures::XYZDatagramBeam>& get_beams() const;
    void set_beams(std::vector<substructures::XYZDatagramBeam> beams);

    // ----- processed data access -----
    /**
     * @brief Get the vessel heading in degrees
     *
     * @return heading * 0.01 degrees (double)
     */
    double get_heading_in_degrees() const;

    /**
     * @brief Get the sound speed in meters per seconds
     *
     * @return sound_speed * 0.1 meters per seconds (double)
     */
    double get_sound_speed_in_m_per_s() const;

    // ----- operators -----
    bool operator==(const XYZDatagram& other) const;

    //----- to/from stream functions -----
    static XYZDatagram from_stream(std::istream& is, KongsbergAllDatagram header);

    static XYZDatagram from_stream(std::istream& is);

    static XYZDatagram from_stream(std::istream&                    is,
                                   t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(XYZDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
