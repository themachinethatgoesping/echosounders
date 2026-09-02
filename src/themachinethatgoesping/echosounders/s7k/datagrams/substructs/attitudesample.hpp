// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/attitudesample.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Single attitude sample of a 1016 Attitude record.
 *
 * The samples are stored as one contiguous block and read as a single bulk read.
 */
#pragma pack(push, 1)
class AttitudeSample
{
    uint16_t _delta_time = 0;   ///< time offset from the record timestamp (ms)
    float    _roll       = 0.f; ///< roll (rad)
    float    _pitch      = 0.f; ///< pitch (rad)
    float    _heave      = 0.f; ///< heave (m)
    float    _heading    = 0.f; ///< heading (rad)

  public:
    AttitudeSample()  = default;
    ~AttitudeSample() = default;

    // ----- convenient member access -----
    uint16_t get_delta_time() const { return _delta_time; }
    float    get_roll() const { return _roll; }
    float    get_pitch() const { return _pitch; }
    float    get_heave() const { return _heave; }
    float    get_heading() const { return _heading; }

    void set_delta_time(uint16_t val) { _delta_time = val; }
    void set_roll(float val) { _roll = val; }
    void set_pitch(float val) { _pitch = val; }
    void set_heave(float val) { _heave = val; }
    void set_heading(float val) { _heading = val; }

    // ----- operators -----
    bool operator==(const AttitudeSample& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "AttitudeSample", float_precision, superscript_exponents);

        printer.register_value("delta_time", _delta_time, "ms");
        printer.register_value("roll", _roll, "rad");
        printer.register_value("pitch", _pitch, "rad");
        printer.register_value("heave", _heave, "m");
        printer.register_value("heading", _heading, "rad");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};
#pragma pack(pop)

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
