// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000configurationdatainterface.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_configurationdatainterface.hpp"

#include "../em3000_datagrams.hpp"
#include "../em3000_types.hpp"
#include "em3000configurationdatainterfaceperfile.hpp"
#include "em3000datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatainterfaces {

template<typename t_ifstream>
class EM3000ConfigurationDataInterface
    : public filetemplates::datainterfaces::I_ConfigurationDataInterface<
          EM3000ConfigurationDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_ConfigurationDataInterface<
        EM3000ConfigurationDataInterfacePerFile<t_ifstream>>;

  public:
    EM3000ConfigurationDataInterface()
        : t_base("EM3000ConfigurationDataInterface")
    {
    }
    ~EM3000ConfigurationDataInterface() = default;

    // ----- read specific packages -----
    void add_runtime_parameters(size_t                                        file_nr,
                                double                                        timestamp,
                                std::shared_ptr<datagrams::RuntimeParameters> runtime_parameters)
    {
        this->add_file_interface(file_nr);

        this->_interface_per_file[file_nr]->add_runtime_parameters(timestamp, std::move(runtime_parameters));
        this->deinitialize();
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));
        return printer;
    }
};

}
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
