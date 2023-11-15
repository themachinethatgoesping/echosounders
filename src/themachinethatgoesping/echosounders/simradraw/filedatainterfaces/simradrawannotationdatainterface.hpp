// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawannotationdatainterface.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_annotationdatainterface.hpp"

#include "../simradraw_datagrams.hpp"
#include "../simradraw_types.hpp"
#include "simradrawannotationdatainterfaceperfile.hpp"
#include "simradrawdatagraminterface.hpp"

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

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));
        return printer;
    }
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
