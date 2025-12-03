// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mwcrxinfo.hpp"

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MWCRxInfo::__printer__(unsigned int float_precision,
                                                         bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MWCRxInfo", float_precision, superscript_exponents);

    printer.register_value("bytes_content", _bytes_content, "bytes");
    printer.register_value("number_of_beams", _number_of_beams);
    printer.register_value("number_bytes_per_beam_entry", _number_bytes_per_beam_entry, "bytes");
    printer.register_value("phase_flag", _phase_flag);
    printer.register_value("tvg_function_applied", _tvg_function_applied);
    printer.register_value("tvg_offset_db", _tvg_offset_db, "dB");
    printer.register_value("sample_freq_hz", _sample_freq_hz, "Hz");
    printer.register_value("sound_velocity_m_per_sec", _sound_velocity_m_per_sec, "m/s");

    return printer;
}

}
}
}
}
}
