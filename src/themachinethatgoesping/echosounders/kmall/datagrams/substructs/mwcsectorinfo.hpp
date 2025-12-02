// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mwcsectorinfo.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

#pragma pack(push, 4) // force 4-byte alignment
class MWCSectorInfo
{
    float    _tilt_angle_re_tx_deg;
    float    _centre_frequency_hz;
    float    _tx_beam_width_along_deg;
    uint16_t _tx_sector_number;
    int16_t  _padding;

  public:
    MWCSectorInfo()  = default;
    ~MWCSectorInfo() = default;

    float    get_tilt_angle_re_tx_deg() const { return _tilt_angle_re_tx_deg; }
    float    get_centre_frequency_hz() const { return _centre_frequency_hz; }
    float    get_tx_beam_width_along_deg() const { return _tx_beam_width_along_deg; }
    uint16_t get_tx_sector_number() const { return _tx_sector_number; }
    int16_t  get_padding() const { return _padding; }

    void set_tilt_angle_re_tx_deg(float val) { _tilt_angle_re_tx_deg = val; }
    void set_centre_frequency_hz(float val) { _centre_frequency_hz = val; }
    void set_tx_beam_width_along_deg(float val) { _tx_beam_width_along_deg = val; }
    void set_tx_sector_number(uint16_t val) { _tx_sector_number = val; }
    void set_padding(int16_t val) { _padding = val; }

    bool operator==(const MWCSectorInfo& other) const;

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};
#pragma pack(pop)

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping

