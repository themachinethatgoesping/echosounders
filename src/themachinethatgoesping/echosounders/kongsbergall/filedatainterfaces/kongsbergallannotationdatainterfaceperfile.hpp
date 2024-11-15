// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallannotationdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_annotationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "kongsbergalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
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
class KongsbergAllAnnotationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_AnnotationDataInterfacePerFile<
          KongsbergAllDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_AnnotationDataInterfacePerFile<
        KongsbergAllDatagramInterface<t_ifstream>>;

  public:
    KongsbergAllAnnotationDataInterfacePerFile()
        : t_base("KongsbergAllAnnotationDataInterfacePerFile")
    {
    }
    ~KongsbergAllAnnotationDataInterfacePerFile() = default;

    // --------------------- kongsbergall specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("KongsbergAllAnnotationDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
