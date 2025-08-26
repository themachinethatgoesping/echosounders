// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawenvironmentdatainterface.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "simradrawconfigurationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "simradrawdatagraminterface.hpp"
#include "simradrawenvironmentdatainterfaceperfile.hpp"
#include "simradrawnavigationdatainterface.hpp"

#include "../../filetemplates/datainterfaces/i_environmentdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradRawEnvironmentDataInterface
    : public filetemplates::datainterfaces::I_EnvironmentDataInterface<
          SimradRawEnvironmentDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_EnvironmentDataInterface<
        SimradRawEnvironmentDataInterfacePerFile<t_ifstream>>;

  public:
    SimradRawEnvironmentDataInterface(
        std::shared_ptr<SimradRawNavigationDataInterface<t_ifstream>> navigation_data_interface)
        : t_base(std::move(navigation_data_interface), "SimradRawEnvironmentDataInterface")
    {
    }
    ~SimradRawEnvironmentDataInterface() = default;

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
tools::classhelper::ObjectPrinter SimradRawEnvironmentDataInterface<t_ifstream>::__printer__(unsigned int float_precision, bool superscript_exponents)
{
    tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

    printer.append(t_base::__printer__(float_precision, superscript_exponents));
    return printer;
}

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
