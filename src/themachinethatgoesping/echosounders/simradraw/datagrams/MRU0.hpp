// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/MRU0.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper/approx.hpp>

#include "../types.hpp"
#include "simradrawdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

/**
 * @brief Motion binary datagram (MRU0)
 * This datagram contains heave, roll, pitch and heading as float values.
 * Conveniently, these values can be used directly in themachinethatgoesping navigation processing
 * because they are defined in the default coordinate system / value range.
 *
 */
class MRU0 : public SimradRawDatagram
{
    // ----- datagram content -----
    simradraw_float _heave   = NAN; ///< Heave in m, positive up
    simradraw_float _roll    = NAN; ///< Roll in degrees, positive port up
    simradraw_float _pitch   = NAN; ///< Pitch in degrees, positive nose up
    simradraw_float _heading = NAN; ///< Heading in degrees, 0° north, 90° east

  private:
    // ----- public constructors -----
    explicit MRU0(SimradRawDatagram header)
        : SimradRawDatagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    MRU0()
        : SimradRawDatagram(12 + 4 * sizeof(simradraw_float),
                            simradraw_long(t_SimradRawDatagramIdentifier::MRU0))
    {
    }
    ~MRU0() = default;

    // ----- operators -----
    bool operator==(const MRU0& other) const;
    bool operator!=(const MRU0& other) const { return !operator==(other); }

    // ----- getter setter -----
    float get_heave() const { return _heave; }
    float get_roll() const { return _roll; }
    float get_pitch() const { return _pitch; }
    float get_heading() const { return _heading; }
    void  set_heave(float value) { _heave = value; }
    void  set_roll(float value) { _roll = value; }
    void  set_pitch(float value) { _pitch = value; }
    void  set_heading(float value) { _heading = value; }

    // ----- file I/O -----
    static MRU0 from_stream(std::istream& is, SimradRawDatagram header);
    static MRU0 from_stream(std::istream& is);
    static MRU0 from_stream(std::istream& is, t_SimradRawDatagramIdentifier type);
    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(MRU0)
};

}
}
}
}