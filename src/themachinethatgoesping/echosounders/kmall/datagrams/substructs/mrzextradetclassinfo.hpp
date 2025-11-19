// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mrzextradetclassinfo.doc.hpp"

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
class MRZExtraDetClassInfo
{
    uint16_t _num_extra_det_in_class;
    int8_t   _padding;
    uint8_t  _alarm_flag;

  public:
    MRZExtraDetClassInfo()  = default;
    ~MRZExtraDetClassInfo() = default;

    uint16_t get_num_extra_det_in_class() const { return _num_extra_det_in_class; }
    int8_t   get_padding() const { return _padding; }
    uint8_t  get_alarm_flag() const { return _alarm_flag; }

    void set_num_extra_det_in_class(uint16_t val) { _num_extra_det_in_class = val; }
    void set_padding(int8_t val) { _padding = val; }
    void set_alarm_flag(uint8_t val) { _alarm_flag = val; }

    bool operator==(const MRZExtraDetClassInfo& other) const = default;

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

