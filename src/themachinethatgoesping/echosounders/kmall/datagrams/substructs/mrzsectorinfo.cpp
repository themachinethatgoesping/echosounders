// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mrzsectorinfo.hpp"

#include <fmt/format.h>

#include <limits>

#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

bool MRZSectorInfo::operator==(const MRZSectorInfo& other) const
{
    using themachinethatgoesping::tools::helper::float_equals;
    return _tx_sector_number == other._tx_sector_number &&
           _tx_arrary_number == other._tx_arrary_number && _tx_sub_array == other._tx_sub_array &&
           _padding_0 == other._padding_0 &&
           float_equals(_sector_transmit_delay_sec, other._sector_transmit_delay_sec) &&
           float_equals(_tilt_angle_re_tx_deg, other._tilt_angle_re_tx_deg) &&
           float_equals(_tx_nominal_source_level_db, other._tx_nominal_source_level_db) &&
           float_equals(_tx_focus_range_m, other._tx_focus_range_m) &&
           float_equals(_centre_frequency_hz, other._centre_frequency_hz) &&
           float_equals(_signal_band_width_hz, other._signal_band_width_hz) &&
           float_equals(_total_signal_length_sec, other._total_signal_length_sec) &&
           _pulse_shading == other._pulse_shading && _signal_wave_form == other._signal_wave_form &&
           _padding_1 == other._padding_1 &&
           float_equals(_high_voltage_level_db, other._high_voltage_level_db) &&
           float_equals(_sector_tracking_corr_db, other._sector_tracking_corr_db) &&
           float_equals(_effective_signal_length_sec, other._effective_signal_length_sec);
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MRZSectorInfo::__printer__(unsigned int float_precision,
                                                             bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MRZSectorInfo", float_precision, superscript_exponents);

    printer.register_value("tx_sector_number", _tx_sector_number);
    printer.register_value("tx_arrary_number", _tx_arrary_number);
    printer.register_value("tx_sub_array", _tx_sub_array);
    printer.register_value("padding_0", _padding_0);
    printer.register_value("sector_transmit_delay_sec", _sector_transmit_delay_sec, "s");
    printer.register_value("tilt_angle_re_tx_deg", _tilt_angle_re_tx_deg, "deg");
    printer.register_value("tx_nominal_source_level_db", _tx_nominal_source_level_db, "dB");
    printer.register_value("tx_focus_range_m", _tx_focus_range_m, "m");
    printer.register_value("centre_frequency_hz", _centre_frequency_hz, "Hz");
    printer.register_value("signal_band_width_hz", _signal_band_width_hz, "Hz");
    printer.register_value("total_signal_length_sec", _total_signal_length_sec, "s");
    printer.register_value("pulse_shading", _pulse_shading);
    printer.register_value("signal_wave_form", _signal_wave_form);
    printer.register_value("padding_1", _padding_1);
    printer.register_value("high_voltage_level_db", _high_voltage_level_db, "dB");
    printer.register_value("sector_tracking_corr_db", _sector_tracking_corr_db, "dB");
    printer.register_value("effective_signal_length_sec", _effective_signal_length_sec, "s");

    return printer;
}

MRZSectorInfo MRZSectorInfo::__read_version_0__(std::istream& is)
{
    static constexpr size_t size_v0 =
        4 * sizeof(uint8_t) + 7 * sizeof(float) + 2 * sizeof(uint8_t) + sizeof(uint16_t);
    MRZSectorInfo info;
    is.read(reinterpret_cast<char*>(&info._tx_sector_number), size_v0);
    info._high_voltage_level_db       = std::numeric_limits<float>::quiet_NaN();
    info._sector_tracking_corr_db     = std::numeric_limits<float>::quiet_NaN();
    info._effective_signal_length_sec = std::numeric_limits<float>::quiet_NaN();
    return info;
}

void MRZSectorInfo::__write_version_0__(std::ostream& os) const
{
    static constexpr size_t size_v0 =
        4 * sizeof(uint8_t) + 7 * sizeof(float) + 2 * sizeof(uint8_t) + sizeof(uint16_t);
    os.write(reinterpret_cast<const char*>(&_tx_sector_number), size_v0);
}

}
}
}
}
}
