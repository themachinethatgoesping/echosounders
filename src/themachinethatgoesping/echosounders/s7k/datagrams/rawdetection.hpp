// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/rawdetection.doc.hpp"

// std includes
#include <cstdint>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"

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
        uint64_t serial_number;       ///< sonar serial number
        uint32_t ping_number;         ///< sequential ping number
        uint16_t multi_ping;          ///< 0 = single ping, else multi-ping sequence number
        uint32_t number_beams;        ///< number of detection points (beams)
        uint32_t data_field_size;     ///< size in bytes of each per-beam detection record
        uint8_t  detection_algorithm; ///< detection algorithm (0-7: G1/G2/G3/IF1/PS1/HS1/HS2)
        uint32_t flags;               ///< flags bit field (uncertainty method, multi-detect, ...)
        float    sampling_rate;       ///< sample rate (Hz)
        float    tx_angle;            ///< transmit steering angle (rad)
        float    applied_roll;        ///< roll applied to the data (rad)
        uint32_t reserved[15];        ///< reserved

        bool operator==(const Content& other) const = default;
    } _content;

    /// per-beam raw detection record (data_field_size bytes, first 34 defined below)
    struct BeamDetection
    {
        uint16_t beam_descriptor; ///< beam number
        float    detection_point; ///< detection point (fractional sample number)
        float    rx_angle;        ///< receive steering angle (rad)
        uint32_t flags;           ///< per-beam flags (magnitude/phase detection, quality type, ...)
        uint32_t quality;         ///< per-beam quality (brightness/colinearity filter passed)
        float    uncertainty;     ///< detection uncertainty (normalized to detection point)
        float    signal_strength; ///< detection signal strength
        float    min_limit;       ///< detection gate minimum sample
        float    max_limit;       ///< detection gate maximum sample
    };
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content); // 99

    // per-beam arrays (length = number_beams)
    xt::xtensor<uint16_t, 1> _beam_descriptor;
    xt::xtensor<float, 1>    _detection_point;
    xt::xtensor<float, 1>    _rx_angle;
    xt::xtensor<uint32_t, 1> _beam_flags;
    xt::xtensor<uint32_t, 1> _quality;
    xt::xtensor<float, 1>    _uncertainty;
    xt::xtensor<float, 1>    _signal_strength;
    xt::xtensor<float, 1>    _min_limit;
    xt::xtensor<float, 1>    _max_limit;

  public:
    RawDetection()  = default;
    ~RawDetection() = default;

    // ----- convenient member access (record type header) -----
    uint64_t get_serial_number() const { return _content.serial_number; }
    uint32_t get_ping_number() const { return _content.ping_number; }
    uint16_t get_multi_ping() const { return _content.multi_ping; }
    uint32_t get_number_beams() const { return _content.number_beams; }
    uint32_t get_data_field_size() const { return _content.data_field_size; }
    uint8_t  get_detection_algorithm() const { return _content.detection_algorithm; }
    uint32_t get_flags() const { return _content.flags; }
    float    get_sampling_rate() const { return _content.sampling_rate; }
    float    get_tx_angle() const { return _content.tx_angle; }
    float    get_applied_roll() const { return _content.applied_roll; }

    // ----- per-beam data access -----
    const xt::xtensor<uint16_t, 1>& get_beam_descriptor() const { return _beam_descriptor; }
    const xt::xtensor<float, 1>&    get_detection_point() const { return _detection_point; }
    const xt::xtensor<float, 1>&    get_rx_angle() const { return _rx_angle; }
    const xt::xtensor<uint32_t, 1>& get_beam_flags() const { return _beam_flags; }
    const xt::xtensor<uint32_t, 1>& get_quality() const { return _quality; }
    const xt::xtensor<float, 1>&    get_uncertainty() const { return _uncertainty; }
    const xt::xtensor<float, 1>&    get_signal_strength() const { return _signal_strength; }
    const xt::xtensor<float, 1>&    get_min_limit() const { return _min_limit; }
    const xt::xtensor<float, 1>&    get_max_limit() const { return _max_limit; }

    // ----- operators -----
    bool operator==(const RawDetection& other) const = default;

    //----- to/from stream functions -----
    static RawDetection from_stream(std::istream& is, S7KDatagram header);
    static RawDetection from_stream(std::istream& is);
    static RawDetection from_stream(std::istream& is, t_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(RawDetection)

  private:
    explicit RawDetection(S7KDatagram header)
        : S7KDatagram(std::move(header))
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
