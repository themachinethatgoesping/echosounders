// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mrzrxinfo.hpp"

#include <fmt/format.h>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MRZRxInfo::__printer__(unsigned int float_precision,
                                                         bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MRZRxInfo", float_precision, superscript_exponents);

    printer.register_value("bytes_content", _bytes_content, "bytes");
    printer.register_value("number_of_soundings_max_main", _number_of_soundings_max_main);
    printer.register_value("number_of_soundings_valid_main", _number_of_soundings_valid_main);
    printer.register_value(
        "number_of_bytes_per_sounding", _number_of_bytes_per_sounding, "bytes");
    printer.register_value("wc_sample_rate", _wc_sample_rate, "Hz");
    printer.register_value("seabed_image_sample_rate", _seabed_image_sample_rate, "Hz");
    printer.register_value("bs_normal_db", _bs_normal_db, "dB");
    printer.register_value("bs_oblique_db", _bs_oblique_db, "dB");
    printer.register_value("extra_detection_alarm_flag", _extra_detection_alarm_flag);
    printer.register_value("number_of_extra_detections", _number_of_extra_detections);
    printer.register_value("number_of_extra_detection_classes", _number_of_extra_detection_classes);
    printer.register_value("number_of_bytes_per_class", _number_of_bytes_per_class, "bytes");

    return printer;
}

}
}
}
}
}
