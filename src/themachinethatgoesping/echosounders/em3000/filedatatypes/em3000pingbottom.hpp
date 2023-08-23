// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/em3000pingbottom.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <memory>
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

#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include "../../filetemplates/datatypes/i_pingbottom.hpp"
#include "../em3000_datagrams.hpp"
#include "../em3000_types.hpp"
#include "em3000pingrawdata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatatypes {

template<typename t_ifstream>
class EM3000PingBottom : public filetemplates::datatypes::I_PingBottom
{
    // raw data
    std::shared_ptr<std::map<std::string, EM3000PingRawData<t_ifstream>>> _raw_data;

    using t_base                = filetemplates::datatypes::I_PingBottom;
    using type_DatagramInfo_ptr = typename EM3000PingRawData<t_ifstream>::type_DatagramInfo_ptr;

  public:
    EM3000PingBottom(std::shared_ptr<std::map<std::string, EM3000PingRawData<t_ifstream>>> raw_data)
        : t_base("EM3000PingBottom")
        , _raw_data(std::move(raw_data))
    {
    }
    virtual ~EM3000PingBottom() = default;

    EM3000PingRawData<t_ifstream>& raw_data(const std::string& transducer_id)
    {
        auto it = _raw_data->find(transducer_id);
        if (it == _raw_data->end())
            throw std::runtime_error(fmt::format("Transducer ID '{}' not found", transducer_id));

        return it->second;
    }

    const std::map<std::string, EM3000PingRawData<t_ifstream>>& raw_data() { return *_raw_data; }

    const EM3000PingRawData<t_ifstream>& get_raw_data(const std::string& transducer_id) const
    {
        auto it = _raw_data->find(transducer_id);
        if (it == _raw_data->end())
            throw std::runtime_error(fmt::format("Transducer ID '{}' not found", transducer_id));

        return it->second;
    }

    // ----- I_PingBottom interface -----
    using t_base::has_xyz;

    bool has_xyz(const std::string& transducer_id) const
    {
        return get_raw_data(transducer_id)
                   .get_datagram_infos_by_type(t_EM3000DatagramIdentifier::XYZDatagram)
                   .size() > 0;
    }

    bool has_xyz() const override
    {
        for (const auto& [transducer_id, raw_data] : *_raw_data)
            if (has_xyz(transducer_id))
                return true;

        return false;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));

        // printer.register_section("EM3000 ping infos");

        // printer.register_string(
        //     "Sample data type",
        //     std::string(magic_enum::enum_name(_raw_data->_ping_data.get_data_type())));

        // printer.register_section("Important members");
        // printer.register_string("raw_data", "EM3000PingRawData");

        return printer;
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping