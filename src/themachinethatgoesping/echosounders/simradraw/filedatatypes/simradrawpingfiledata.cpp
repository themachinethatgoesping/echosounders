// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "simradrawpingfiledata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {

// ----- objectprinter -----
tools::classhelper::ObjectPrinter SimradRawPingFileData::__printer__(unsigned int float_precision,
                                                              bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        this->class_name(), float_precision, superscript_exponents);

    printer.append(t_base1::__printer__(float_precision, superscript_exponents));
    printer.append(t_base2::__printer__(float_precision, superscript_exponents));

    printer.register_section("Raw data infos");

    // // convert _ping_data.get_data_type() to string using magic enum
    // printer.register_string("Raw data type",
    //                         std::string(magic_enum::enum_name(_ping_data.get_data_type())));
    // printer.register_value("Has power", has_power());
    // printer.register_value("Has angle", has_angle());

    // printer.register_section("Important members");
    // printer.register_string("ping_data", "RAW3DataVariant");
    // printer.register_string("get_parameter()", "XML_Parameter_Channel");

    return printer;
}

} // namespace filedatatypes
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
