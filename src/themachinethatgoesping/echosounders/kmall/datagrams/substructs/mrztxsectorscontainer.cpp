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

    printer.register_section("TxSectors (.tx_sectors)");
    printer.register_value("tx_sectors (vector)",
                           fmt::format("size={}", get_number_of_tx_sectors()),
                           "sectors");

    printer.register_container("tx_sector_number", get_tx_sector_number_tensor());
    printer.register_container("tx_arrary_number", get_tx_arrary_number_tensor());
    printer.register_container("tx_sub_array", get_tx_sub_array_tensor());
    printer.register_container("padding_0", get_padding_0_tensor());
    printer.register_container(
        "sector_transmit_delay_sec", get_sector_transmit_delay_sec_tensor(), "s");
    printer.register_container(
        "tilt_angle_re_tx_deg", get_tilt_angle_re_tx_deg_tensor(), "deg");
    printer.register_container(
        "tx_nominal_source_level_db", get_tx_nominal_source_level_db_tensor(), "dB");
    printer.register_container("tx_focus_range_m", get_tx_focus_range_m_tensor(), "m");
    printer.register_container("centre_frequency_hz", get_centre_frequency_hz_tensor(), "Hz");
    printer.register_container("signal_band_width_hz", get_signal_band_width_hz_tensor(), "Hz");
    printer.register_container(
        "total_signal_length_sec", get_total_signal_length_sec_tensor(), "s");
    printer.register_container("pulse_shading", get_pulse_shading_tensor());
    printer.register_container("signal_wave_form", get_signal_wave_form_tensor());
    printer.register_container("padding_1", get_padding_1_tensor());
    printer.register_container(
        "high_voltage_level_db", get_high_voltage_level_db_tensor(), "dB");
    printer.register_container(
        "sector_tracking_corr_db", get_sector_tracking_corr_db_tensor(), "dB");
    printer.register_container(
        "effective_signal_length_sec", get_effective_signal_length_sec_tensor(), "s");

    printer.register_section("processed");
    printer.register_value("number_of_tx_sectors", get_number_of_tx_sectors());
    printer.register_container("tx_signal_type", get_tx_signal_type_tensor());

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
