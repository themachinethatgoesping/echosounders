// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mrzextradetclassinfo.hpp"

#include <fmt/format.h>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MRZExtraDetClassInfo::__printer__(unsigned int float_precision,
                                                                    bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MRZExtraDetClassInfo", float_precision, superscript_exponents);

    printer.register_value("num_extra_det_in_class", _num_extra_det_in_class);
    printer.register_value("padding", _padding);
    printer.register_value("alarm_flag", _alarm_flag);

    return printer;
}

}
}
}
}
}
