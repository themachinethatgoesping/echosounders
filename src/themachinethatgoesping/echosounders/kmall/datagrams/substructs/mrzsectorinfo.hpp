// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mrzsectorinfo.doc.hpp"

// std includes
#include <cstdint>
#include <istream>
#include <ostream>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

#pragma pack(push, 4) // force 4-byte alignment
class MRZSectorInfo
{
    uint8_t  _tx_sector_number;
    uint8_t  _tx_arrary_number;
    uint8_t  _tx_sub_array;
    uint8_t  _padding_0;
    float    _sector_transmit_delay_sec;
    float    _tilt_angle_re_tx_deg;
    float    _tx_nominal_source_level_db;
    float    _tx_focus_range_m;
    float    _centre_frequency_hz;
    float    _signal_band_width_hz;
    float    _total_signal_length_sec;
    uint8_t  _pulse_shading;
    uint8_t  _signal_wave_form;
    uint16_t _padding_1;

    // Additional parameters #MRZ Version 1
    float _high_voltage_level_db;
    float _sector_tracking_corr_db;
    float _effective_signal_length_sec;

  public:
    MRZSectorInfo()  = default;
    ~MRZSectorInfo() = default;

    uint8_t get_tx_sector_number() const { return _tx_sector_number; }
    uint8_t get_tx_arrary_number() const { return _tx_arrary_number; }
    uint8_t get_tx_sub_array() const { return _tx_sub_array; }
    uint8_t get_padding_0() const { return _padding_0; }
    float   get_sector_transmit_delay_sec() const { return _sector_transmit_delay_sec; }
    float   get_tilt_angle_re_tx_deg() const { return _tilt_angle_re_tx_deg; }
    float   get_tx_nominal_source_level_db() const { return _tx_nominal_source_level_db; }
    float   get_tx_focus_range_m() const { return _tx_focus_range_m; }
    float   get_centre_frequency_hz() const { return _centre_frequency_hz; }
    float   get_signal_band_width_hz() const { return _signal_band_width_hz; }
    float   get_total_signal_length_sec() const { return _total_signal_length_sec; }
    uint8_t get_pulse_shading() const { return _pulse_shading; }
    uint8_t get_signal_wave_form() const { return _signal_wave_form; }
    uint16_t get_padding_1() const { return _padding_1; }
    float    get_high_voltage_level_db() const { return _high_voltage_level_db; }
    float    get_sector_tracking_corr_db() const { return _sector_tracking_corr_db; }
    float    get_effective_signal_length_sec() const { return _effective_signal_length_sec; }

    void set_tx_sector_number(uint8_t val) { _tx_sector_number = val; }
    void set_tx_arrary_number(uint8_t val) { _tx_arrary_number = val; }
    void set_tx_sub_array(uint8_t val) { _tx_sub_array = val; }
    void set_padding_0(uint8_t val) { _padding_0 = val; }
    void set_sector_transmit_delay_sec(float val) { _sector_transmit_delay_sec = val; }
    void set_tilt_angle_re_tx_deg(float val) { _tilt_angle_re_tx_deg = val; }
    void set_tx_nominal_source_level_db(float val) { _tx_nominal_source_level_db = val; }
    void set_tx_focus_range_m(float val) { _tx_focus_range_m = val; }
    void set_centre_frequency_hz(float val) { _centre_frequency_hz = val; }
    void set_signal_band_width_hz(float val) { _signal_band_width_hz = val; }
    void set_total_signal_length_sec(float val) { _total_signal_length_sec = val; }
    void set_pulse_shading(uint8_t val) { _pulse_shading = val; }
    void set_signal_wave_form(uint8_t val) { _signal_wave_form = val; }
    void set_padding_1(uint16_t val) { _padding_1 = val; }
    void set_high_voltage_level_db(float val) { _high_voltage_level_db = val; }
    void set_sector_tracking_corr_db(float val) { _sector_tracking_corr_db = val; }
    void set_effective_signal_length_sec(float val) { _effective_signal_length_sec = val; }

    bool operator==(const MRZSectorInfo& other) const;

    static MRZSectorInfo __read_version_0__(std::istream& is);
    void                 __write_version_0__(std::ostream& os) const;

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
