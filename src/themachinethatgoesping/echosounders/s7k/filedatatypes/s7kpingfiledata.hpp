// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kpingfiledata.doc.hpp"

/* std includes */
#include <memory>

#include <fmt/format.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include "../../filetemplates/datatypes/i_pingfiledata.hpp"
#include "../datagrams.hpp"
#include "../filedatainterfaces/s7kdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {

/**
 * @brief Raw file data of a single s7k ping. Holds the datagram index of the ping (via the
 * S7KDatagramInterface base) and provides raw access to the ping's datagrams.
 *
 * @note The datagram-processing functions are not implemented yet. This class currently only
 * provides the structure so it can be filled in in a later step.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KPingFileData
    : public filetemplates::datatypes::I_PingFileData
    , public filedatainterfaces::S7KDatagramInterface<t_ifstream>
{
    using t_base1 = filetemplates::datatypes::I_PingFileData;
    using t_base2 = filedatainterfaces::S7KDatagramInterface<t_ifstream>;

  protected:
    std::string class_name() const override { return "S7KPingFileData"; }

  public:
    S7KPingFileData()
        : t_base1()
        , t_base2()
    {
    }
    ~S7KPingFileData() = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base1::__printer__(float_precision, superscript_exponents));
        printer.append(t_base2::__printer__(float_precision, superscript_exponents));

        return printer;
    }

    // -- class helper function macros --
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
