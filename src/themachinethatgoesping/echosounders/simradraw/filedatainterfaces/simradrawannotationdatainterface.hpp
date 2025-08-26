// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawannotationdatainterface.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../datagrams.hpp"
#include "../types.hpp"
#include "simradrawannotationdatainterfaceperfile.hpp"
#include "simradrawdatagraminterface.hpp"

#include "../../filetemplates/datainterfaces/i_annotationdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

/**
 * @brief Interface to read SimradRaw annotation data (TAG0) from a file (multiple files)
 *
 * Only sorts the supported datagrams. No caching is done.
 * Gives access to SimradRawAnnotationDataInterfacePerFile using the per_file function.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class SimradRawAnnotationDataInterface
    : public filetemplates::datainterfaces::I_AnnotationDataInterface<
          SimradRawAnnotationDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_AnnotationDataInterface<
        SimradRawAnnotationDataInterfacePerFile<t_ifstream>>;

  public:
    SimradRawAnnotationDataInterface()
        : t_base("SimradRawAnnotationDataInterface")
    {
    }
    ~SimradRawAnnotationDataInterface() = default;

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
tools::classhelper::ObjectPrinter SimradRawAnnotationDataInterface<t_ifstream>::__printer__(unsigned int float_precision, bool superscript_exponents)
{
    tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

    printer.append(t_base::__printer__(float_precision, superscript_exponents));
    return printer;
}

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
