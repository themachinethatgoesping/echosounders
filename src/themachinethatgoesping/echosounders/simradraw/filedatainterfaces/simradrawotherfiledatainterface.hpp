// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawotherfiledatainterface.doc.hpp"

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "../datagrams.hpp"
#include "simradrawdatagraminterface.hpp"
#include "simradrawotherfiledatainterfaceperfile.hpp"

#include "../../filetemplates/datainterfaces/i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

/**
 * @brief FileDataInterface (for multiple files) for packages that fit neither of the other
 * FileDataInterfaces (Configuration, Navigation, Annotation, Environment, Ping)
 *
 * No datagram caching is implemented for this interface. Accessed packages are always read from
 * file
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class SimradRawOtherFileDataInterface
    : public filetemplates::datainterfaces::I_FileDataInterface<
          init_c_simradrawotherfiledatainterfaceperfile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_FileDataInterface<
        init_c_simradrawotherfiledatainterfaceperfile<t_ifstream>>;

  public:
    SimradRawOtherFileDataInterface()
        : t_base("SimradRawOtherFileDataInterface")
    {
    }
    ~SimradRawOtherFileDataInterface() = default;

    /**
     * @brief Object printer for this interface
     * @param float_precision Number of decimal places for floating point values
     * @param superscript_exponents Whether to use superscript notation for exponents
     * @return ObjectPrinter instance configured for this object
     */
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents);
};

// ---- Template function implementations ----

template<typename t_ifstream>
tools::classhelper::ObjectPrinter SimradRawOtherFileDataInterface<t_ifstream>::__printer__(unsigned int float_precision, bool superscript_exponents)
{
    tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

    printer.append(t_base::__printer__(float_precision, superscript_exponents));
    return printer;
}

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
