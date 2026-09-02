// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/beamgeometry.doc.hpp"

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
 * @brief 7k record BeamGeometry: per-beam transmit/receive angles and beam widths.
 */
class BeamGeometry : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::BeamGeometry;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint64_t serial_number; ///< sonar serial number
        uint32_t number_beams;  ///< number of beams

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content); // 12

    // per-beam arrays (length = number_beams), stored as read from disk (structure of arrays)
    xt::xtensor<float, 1> _beam_vertical_angle;   ///< along-track (vertical) angle (rad)
    xt::xtensor<float, 1> _beam_horizontal_angle; ///< across-track (horizontal) angle (rad)
    xt::xtensor<float, 1> _beamwidth_vertical;    ///< along-track (vertical) -3dB width (rad)
    xt::xtensor<float, 1> _beamwidth_horizontal;  ///< across-track (horizontal) -3dB width (rad)
    xt::xtensor<float, 1> _tx_delay;              ///< transmit delay (fractional samples, optional)
    bool                  _has_tx_delay = false;  ///< true if the tx_delay array is present

  public:
    BeamGeometry()  = default;
    ~BeamGeometry() = default;

    // ----- record type header access -----
    uint64_t get_serial_number() const { return _content.serial_number; }
    uint32_t get_number_beams() const { return _content.number_beams; }

    void set_serial_number(uint64_t val) { _content.serial_number = val; }
    void set_number_beams(uint32_t val) { _content.number_beams = val; }

    // ----- per-beam data access -----
    const xt::xtensor<float, 1>& get_beam_vertical_angle() const { return _beam_vertical_angle; }
    const xt::xtensor<float, 1>& get_beam_horizontal_angle() const { return _beam_horizontal_angle; }
    const xt::xtensor<float, 1>& get_beamwidth_vertical() const { return _beamwidth_vertical; }
    const xt::xtensor<float, 1>& get_beamwidth_horizontal() const { return _beamwidth_horizontal; }
    bool                         get_has_tx_delay() const { return _has_tx_delay; }
    const xt::xtensor<float, 1>& get_tx_delay() const { return _tx_delay; }

    void set_beam_vertical_angle(const xt::xtensor<float, 1>& v) { _beam_vertical_angle = v; }
    void set_beam_horizontal_angle(const xt::xtensor<float, 1>& v) { _beam_horizontal_angle = v; }
    void set_beamwidth_vertical(const xt::xtensor<float, 1>& v) { _beamwidth_vertical = v; }
    void set_beamwidth_horizontal(const xt::xtensor<float, 1>& v) { _beamwidth_horizontal = v; }
    void set_tx_delay(const xt::xtensor<float, 1>& v) { _tx_delay = v; }
    void set_has_tx_delay(bool v) { _has_tx_delay = v; }

    // ----- operators -----
    bool operator==(const BeamGeometry& other) const = default;

    //----- to/from stream functions -----
    static BeamGeometry from_stream(std::istream& is, S7KDatagram header);
    static BeamGeometry from_stream(std::istream& is);
    static BeamGeometry from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(BeamGeometry)

  private:
    explicit BeamGeometry(S7KDatagram header)
        : S7KDatagram(std::move(header))
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
