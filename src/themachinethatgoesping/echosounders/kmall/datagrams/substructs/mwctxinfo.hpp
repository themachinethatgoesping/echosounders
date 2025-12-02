// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mwctxinfo.doc.hpp"

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
class MWCTxInfo
{
    uint16_t _num_bytes_tx_info;
    uint16_t _num_tx_sectors;
    uint16_t _num_bytes_per_tx_sector;
    int16_t  _padding;
    float    _heave_m;

  public:
    MWCTxInfo()  = default;
    ~MWCTxInfo() = default;

    uint16_t get_num_bytes_tx_info() const { return _num_bytes_tx_info; }
    uint16_t get_num_tx_sectors() const { return _num_tx_sectors; }
    uint16_t get_num_bytes_per_tx_sector() const { return _num_bytes_per_tx_sector; }
    int16_t  get_padding() const { return _padding; }
    float    get_heave_m() const { return _heave_m; }

    void set_num_bytes_tx_info(uint16_t val) { _num_bytes_tx_info = val; }
    void set_num_tx_sectors(uint16_t val) { _num_tx_sectors = val; }
    void set_num_bytes_per_tx_sector(uint16_t val) { _num_bytes_per_tx_sector = val; }
    void set_padding(int16_t val) { _padding = val; }
    void set_heave_m(float val) { _heave_m = val; }

    bool operator==(const MWCTxInfo& other) const = default;

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
