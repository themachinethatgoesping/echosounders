// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mrzrxinfo.doc.hpp"

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
class MRZRxInfo
{
    uint16_t _bytes_content;
    uint16_t _number_of_soundings_max_main;
    uint16_t _number_of_soundings_valid_main;
    uint16_t _number_of_bytes_per_sounding;
    float    _wc_sample_rate;
    float    _seabed_image_sample_rate;
    float    _bs_normal_db;
    float    _bs_oblique_db;
    uint16_t _extra_detection_alarm_flag;
    uint16_t _number_of_extra_detections;
    uint16_t _number_of_extra_detection_classes;
    uint16_t _number_of_bytes_per_class;

  public:
    MRZRxInfo()  = default;
    ~MRZRxInfo() = default;

    uint16_t get_bytes_content() const { return _bytes_content; }
    uint16_t get_number_of_soundings_max_main() const
    {
        return _number_of_soundings_max_main;
    }
    uint16_t get_number_of_soundings_valid_main() const
    {
        return _number_of_soundings_valid_main;
    }
    uint16_t get_number_of_bytes_per_sounding() const
    {
        return _number_of_bytes_per_sounding;
    }
    float get_wc_sample_rate() const { return _wc_sample_rate; }
    float get_seabed_image_sample_rate() const { return _seabed_image_sample_rate; }
    float get_bs_normal_db() const { return _bs_normal_db; }
    float get_bs_oblique_db() const { return _bs_oblique_db; }
    uint16_t get_extra_detection_alarm_flag() const { return _extra_detection_alarm_flag; }
    uint16_t get_number_of_extra_detections() const { return _number_of_extra_detections; }
    uint16_t get_number_of_extra_detection_classes() const
    {
        return _number_of_extra_detection_classes;
    }
    uint16_t get_number_of_bytes_per_class() const { return _number_of_bytes_per_class; }

    void set_bytes_content(uint16_t val) { _bytes_content = val; }
    void set_number_of_soundings_max_main(uint16_t val) { _number_of_soundings_max_main = val; }
    void set_number_of_soundings_valid_main(uint16_t val) { _number_of_soundings_valid_main = val; }
    void set_number_of_bytes_per_sounding(uint16_t val) { _number_of_bytes_per_sounding = val; }
    void set_wc_sample_rate(float val) { _wc_sample_rate = val; }
    void set_seabed_image_sample_rate(float val) { _seabed_image_sample_rate = val; }
    void set_bs_normal_db(float val) { _bs_normal_db = val; }
    void set_bs_oblique_db(float val) { _bs_oblique_db = val; }
    void set_extra_detection_alarm_flag(uint16_t val) { _extra_detection_alarm_flag = val; }
    void set_number_of_extra_detections(uint16_t val) { _number_of_extra_detections = val; }
    void set_number_of_extra_detection_classes(uint16_t val)
    {
        _number_of_extra_detection_classes = val;
    }
    void set_number_of_bytes_per_class(uint16_t val) { _number_of_bytes_per_class = val; }

    bool operator==(const MRZRxInfo& other) const;

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
