// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_datagraminterface>
class I_ConfigurationDataInterface : public I_FileDataInterface<t_datagraminterface>
{

  public:
    I_ConfigurationDataInterface(std::string_view name = "I_ConfigurationDataInterface")
        : I_FileDataInterface<t_datagraminterface>(name)
    {
    }
    virtual ~I_ConfigurationDataInterface() = default;

    // void add_datagram_info(DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream> datagram)
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping