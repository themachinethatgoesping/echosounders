// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mwctxinfo.hpp"

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MWCTxInfo::__printer__(unsigned int float_precision,
                                                         bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MWCTxInfo", float_precision, superscript_exponents);

    printer.register_value("bytes_content", _bytes_content, "bytes");
    printer.register_value("number_of_tx_sectors", _number_of_tx_sectors);
    printer.register_value("num_bytes_per_tx_sector", _num_bytes_per_tx_sector, "bytes");
    printer.register_value("padding", _padding);
    printer.register_value("heave_m", _heave_m, "m");

    return printer;
}

}
}
}
}
}
