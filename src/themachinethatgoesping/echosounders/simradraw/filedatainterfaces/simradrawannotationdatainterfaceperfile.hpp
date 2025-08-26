// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawannotationdatainterfaceperfile.doc.hpp"

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../types.hpp"
#include "../datagrams.hpp"
#include "simradrawdatagraminterface.hpp"

#include "../../filetemplates/datainterfaces/i_annotationdatainterface.hpp"
namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {
/**
 * @brief Interface to read annotation data (TAG0)
 * from a file (per file)
 *
 * This class can be accessed using the per_file function of the AnnotationDataInterface.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class SimradRawAnnotationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_AnnotationDataInterfacePerFile<
          SimradRawDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_AnnotationDataInterfacePerFile<
        SimradRawDatagramInterface<t_ifstream>>;

  public:
    SimradRawAnnotationDataInterfacePerFile()
        : t_base("SimradRawAnnotationDataInterfacePerFile")
    {
    }
    ~SimradRawAnnotationDataInterfacePerFile() = default;

    // --------------------- simradraw specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("SimradRawAnnotationDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
