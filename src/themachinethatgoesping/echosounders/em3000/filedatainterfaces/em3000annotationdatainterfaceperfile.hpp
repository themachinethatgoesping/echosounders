// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000annotationdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_annotationdatainterface.hpp"

#include "../em3000_datagrams.hpp"
#include "../em3000_types.hpp"
#include "em3000datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatainterfaces {

/**
 * @brief Interface to read annotation data (no kongsberg datagram is currently supported)
 * from a file (per file)
 *
 * This class can be accessed using the per_file function of the AnnotationDataInterface.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class EM3000AnnotationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_AnnotationDataInterfacePerFile<
          EM3000DatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_AnnotationDataInterfacePerFile<
        EM3000DatagramInterface<t_ifstream>>;

  public:
    EM3000AnnotationDataInterfacePerFile()
        : t_base("EM3000AnnotationDataInterfacePerFile")
    {
    }
    ~EM3000AnnotationDataInterfacePerFile() = default;

    // --------------------- em3000 specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("EM3000AnnotationDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
