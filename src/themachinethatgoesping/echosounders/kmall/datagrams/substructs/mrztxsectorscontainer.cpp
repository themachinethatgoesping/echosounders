// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mrztxsectorscontainer.hpp"

#include <fmt/core.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

const std::vector<MRZSectorInfo>& MRZTxSectorsContainer::get_tx_sectors() const
{
    return _tx_sectors;
}

std::vector<MRZSectorInfo>& MRZTxSectorsContainer::tx_sectors() { return _tx_sectors; }

void MRZTxSectorsContainer::set_tx_sectors(const std::vector<MRZSectorInfo>& sectors)
{
    _tx_sectors = sectors;
}

#define _MRZ_TXS_GETTER(NAME, TYPE)                                                                \
    xt::xtensor<TYPE, 1> MRZTxSectorsContainer::get_##NAME##_tensor(                               \
        const std::vector<uint32_t>& indices) const                                                \
    {                                                                                              \
        return build_tensor<TYPE>([](const MRZSectorInfo& s) { return s.get_##NAME(); }, indices); \
    }

_MRZ_TXS_GETTER(tx_sector_number, uint8_t)
_MRZ_TXS_GETTER(tx_arrary_number, uint8_t)
_MRZ_TXS_GETTER(tx_sub_array, uint8_t)
_MRZ_TXS_GETTER(padding_0, uint8_t)
_MRZ_TXS_GETTER(sector_transmit_delay_sec, float)
_MRZ_TXS_GETTER(tilt_angle_re_tx_deg, float)
_MRZ_TXS_GETTER(tx_nominal_source_level_db, float)
_MRZ_TXS_GETTER(tx_focus_range_m, float)
_MRZ_TXS_GETTER(centre_frequency_hz, float)
_MRZ_TXS_GETTER(signal_band_width_hz, float)
_MRZ_TXS_GETTER(total_signal_length_sec, float)
_MRZ_TXS_GETTER(pulse_shading, uint8_t)
_MRZ_TXS_GETTER(signal_wave_form, uint8_t)
_MRZ_TXS_GETTER(padding_1, uint16_t)
_MRZ_TXS_GETTER(high_voltage_level_db, float)
_MRZ_TXS_GETTER(sector_tracking_corr_db, float)
_MRZ_TXS_GETTER(effective_signal_length_sec, float)

#undef _MRZ_TXS_GETTER

xt::xtensor<uint8_t, 1> MRZTxSectorsContainer::get_tx_signal_type_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<uint8_t>(
        [](const MRZSectorInfo& s) { return static_cast<uint8_t>(s.get_tx_signal_type()); },
        indices);
}

size_t MRZTxSectorsContainer::get_number_of_tx_sectors() const { return _tx_sectors.size(); }

tools::classhelper::ObjectPrinter MRZTxSectorsContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MRZTxSectorsContainer", float_precision, superscript_exponents);
    printer.register_value("number_of_tx_sectors", _tx_sectors.size());
    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
