// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "kongsbergallpingfiledata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {

template<typename t_ifstream>
tools::classhelper::ObjectPrinter KongsbergAllPingFileData<t_ifstream>::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        this->class_name(), float_precision, superscript_exponents);

    printer.append(t_base1::__printer__(float_precision, superscript_exponents));
    printer.append(t_base2::__printer__(float_precision, superscript_exponents));

    printer.register_section("Raw data infos");

    return printer;
}

// Explicit template instantiation for common stream types
template class KongsbergAllPingFileData<std::ifstream>;

} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
