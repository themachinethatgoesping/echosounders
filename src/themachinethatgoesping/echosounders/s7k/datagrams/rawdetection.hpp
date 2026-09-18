// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/rawdetection.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"
#include "substructs/rawdetectionbeamcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief 7k record RawDetectionData: raw bottom detections (bathymetry) per beam.
 *
 * This is the preferred bathymetry record (replaces the deprecated 7006). It holds, per beam, the
 * detection point (fractional sample number), the receive steering angle and detection quality.
 */
class RawDetection : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::RawDetectionData;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint64_t _serial_number       = 0;   ///< sonar serial number
        uint32_t _ping_number         = 0;   ///< sequential ping number
        uint16_t _multi_ping          = 0;   ///< 0 = single ping, else multi-ping sequence number
        uint32_t _number_beams        = 0;   ///< number of detection points (beams)
        uint32_t _data_field_size     = 0;   ///< size in bytes of each per-beam detection record
        uint8_t  _detection_algorithm = 0;   ///< detection algorithm (0-7: G1/G2/G3/IF1/PS1/HS1/HS2)
        uint32_t _flags               = 0;   ///< flags bit field (uncertainty method, multi-detect)
        float    _sampling_rate       = 0.f; ///< sample rate (Hz)
        float    _tx_angle            = 0.f; ///< transmit steering angle (rad)
        float    _applied_roll        = 0.f; ///< roll applied to the data (rad)
        uint32_t _reserved[15]        = {};  ///< reserved

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content); // 99

    substructs::RawDetectionBeamContainer _beams; ///< per-beam raw detections

    uint32_t _checksum = 0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

  public:
    RawDetection();
    ~RawDetection() = default;

    // ----- convenient member access (record type header) -----
    uint64_t get_serial_number() const;
    uint32_t get_ping_number() const;
    uint16_t get_multi_ping() const;
    uint32_t get_number_beams() const;
    uint32_t get_data_field_size() const;
    uint8_t  get_detection_algorithm() const;
    uint32_t get_flags() const;
    float    get_sampling_rate() const;
    float    get_tx_angle() const;
    float    get_applied_roll() const;
    uint32_t get_checksum() const;

    void set_serial_number(uint64_t val);
    void set_ping_number(uint32_t val);
    void set_multi_ping(uint16_t val);
    void set_number_beams(uint32_t val);
    void set_data_field_size(uint32_t val);
    void set_detection_algorithm(uint8_t val);
    void set_flags(uint32_t val);
    void set_sampling_rate(float val);
    void set_tx_angle(float val);
    void set_applied_roll(float val);
    void set_checksum(uint32_t val);

    // ----- processed data access -----
    /// @brief Get the transmit steering angle in degrees (converted from radians).
    float get_tx_angle_in_degrees() const;
    /// @brief Get the roll applied to the data in degrees (converted from radians).
    float get_applied_roll_in_degrees() const;

    // ----- substructure access -----
    const substructs::RawDetectionBeamContainer& get_beams() const;
    substructs::RawDetectionBeamContainer&        beams();
    void set_beams(const substructs::RawDetectionBeamContainer& beams);

    // ----- operators -----
    bool operator==(const RawDetection& other) const = default;

    //----- to/from stream functions -----
    static RawDetection from_stream(std::istream& is, S7KDatagram header);
    static RawDetection from_stream(std::istream& is);
    static RawDetection from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(RawDetection)

  private:
    explicit RawDetection(S7KDatagram header);
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
