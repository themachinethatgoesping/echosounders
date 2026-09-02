// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/attitude.doc.hpp"

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
 * @brief 7k record Attitude: a set of attitude samples (roll, pitch, heave, heading) with a
 * time offset relative to the record timestamp. Used by modern systems (e.g. R2Sonic) instead of
 * separate 1012/1013 records.
 */
class Attitude : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::Attitude;

  protected:
#pragma pack(push, 1)
    struct AttitudeSample
    {
        uint16_t delta_time; ///< time offset from the record timestamp (ms)
        float    roll;       ///< roll (rad)
        float    pitch;      ///< pitch (rad)
        float    heave;      ///< heave (m)
        float    heading;    ///< heading (rad)
    };
#pragma pack(pop)

    static constexpr size_t __sample_size = sizeof(AttitudeSample); // 18

    uint8_t _number_of_samples = 0;

    // per-sample arrays (length = number_of_samples)
    xt::xtensor<uint16_t, 1> _delta_time;
    xt::xtensor<float, 1>    _roll;
    xt::xtensor<float, 1>    _pitch;
    xt::xtensor<float, 1>    _heave;
    xt::xtensor<float, 1>    _heading;

  public:
    Attitude()  = default;
    ~Attitude() = default;

    // ----- record type header access -----
    uint8_t get_number_of_samples() const { return _number_of_samples; }

    // ----- per-sample data access -----
    const xt::xtensor<uint16_t, 1>& get_delta_time() const { return _delta_time; }
    const xt::xtensor<float, 1>&    get_roll() const { return _roll; }
    const xt::xtensor<float, 1>&    get_pitch() const { return _pitch; }
    const xt::xtensor<float, 1>&    get_heave() const { return _heave; }
    const xt::xtensor<float, 1>&    get_heading() const { return _heading; }

    // ----- operators -----
    bool operator==(const Attitude& other) const = default;

    //----- to/from stream functions -----
    static Attitude from_stream(std::istream& is, S7KDatagram header);
    static Attitude from_stream(std::istream& is);
    static Attitude from_stream(std::istream& is, t_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(Attitude)

  private:
    explicit Attitude(S7KDatagram header)
        : S7KDatagram(std::move(header))
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
