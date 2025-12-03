// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mwcrxinfo.doc.hpp"

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
class MWCRxInfo
{
    uint16_t _bytes_content;
    uint16_t _number_of_beams;
    uint8_t  _number_bytes_per_beam_entry;
    uint8_t  _phase_flag;
    uint8_t  _tvg_function_applied;
    int8_t   _tvg_offset_db;
    float    _sample_freq_hz;
    float    _sound_velocity_m_per_sec;

  public:
    MWCRxInfo()  = default;
    ~MWCRxInfo() = default;

    uint16_t get_bytes_content() const { return _bytes_content; }
    uint16_t get_number_of_beams() const { return _number_of_beams; }
    uint8_t  get_number_bytes_per_beam_entry() const { return _number_bytes_per_beam_entry; }
    uint8_t  get_phase_flag() const { return _phase_flag; }
    uint8_t  get_tvg_function_applied() const { return _tvg_function_applied; }
    int8_t   get_tvg_offset_db() const { return _tvg_offset_db; }
    float    get_sample_freq_hz() const { return _sample_freq_hz; }
    float    get_sound_velocity_m_per_sec() const { return _sound_velocity_m_per_sec; }

    void set_bytes_content(uint16_t val) { _bytes_content = val; }
    void set_number_of_beams(uint16_t val) { _number_of_beams = val; }
    void set_number_bytes_per_beam_entry(uint8_t val) { _number_bytes_per_beam_entry = val; }
    void set_phase_flag(uint8_t val) { _phase_flag = val; }
    void set_tvg_function_applied(uint8_t val) { _tvg_function_applied = val; }
    void set_tvg_offset_db(int8_t val) { _tvg_offset_db = val; }
    void set_sample_freq_hz(float val) { _sample_freq_hz = val; }
    void set_sound_velocity_m_per_sec(float val) { _sound_velocity_m_per_sec = val; }

    bool operator==(const MWCRxInfo& other) const = default;

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

