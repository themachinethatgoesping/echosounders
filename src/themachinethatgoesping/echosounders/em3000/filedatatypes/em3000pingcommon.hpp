// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/em3000pingcommon.doc.hpp"

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
#include <themachinethatgoesping/tools/helper/defaultsharedpointermap.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include "../../filetemplates/datatypes/i_pingcommon.hpp"
#include "../em3000_datagrams.hpp"

#include "em3000pingrawdata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatatypes {

template<typename t_ifstream>
class EM3000PingCommon : virtual public filetemplates::datatypes::I_PingCommon
{
  protected:
    // raw data
    using t_rawdatamap                      = std::map<std::string, EM3000PingRawData<t_ifstream>>;
    std::shared_ptr<t_rawdatamap> _raw_data = std::make_shared<t_rawdatamap>();

  public:
    using t_base = filetemplates::datatypes::I_PingCommon;
    EM3000PingCommon()
        : t_base("EM3000PingCommon")
    {
    }
    EM3000PingCommon(std::shared_ptr<t_rawdatamap> raw_Data)
        : t_base("EM3000PingCommon")
        , _raw_data(std::move(raw_Data))
    {
    }
    virtual ~EM3000PingCommon() = default;

    // explicit copy constructor and assignment operators
    EM3000PingCommon(const EM3000PingCommon& other)
        : t_base(other)
        , _raw_data(std::make_shared<t_rawdatamap>(*other._raw_data))
    {
    }
    EM3000PingCommon& operator=(const EM3000PingCommon& other)
    {
        t_base::operator=(other);
        _raw_data = std::make_shared<t_rawdatamap>(*other._raw_data);
        return *this;
    }

    EM3000PingRawData<t_ifstream>& raw_data(const std::string& transducer_id)
    {
        auto it = _raw_data->find(transducer_id);
        if (it == _raw_data->end())
            throw std::runtime_error(fmt::format("Transducer ID '{}' not found", transducer_id));

        return it->second;
    }

    const t_rawdatamap& raw_data() { return *_raw_data; }

    const EM3000PingRawData<t_ifstream>& get_raw_data(const std::string& transducer_id) const
    {
        auto it = _raw_data->find(transducer_id);
        if (it == _raw_data->end())
            throw std::runtime_error(fmt::format("Transducer ID '{}' not found", transducer_id));

        return it->second;
    }

    const EM3000PingRawData<t_ifstream>& get_raw_data() const
    {
        return get_raw_data(get_transducer_id());
    }

    std::vector<std::string> get_transducer_ids() const override
    {
        std::vector<std::string> transducer_ids;

        /* return the keys from _raw_data */
        for (const auto& [k, v] : *_raw_data)
            transducer_ids.push_back(k);

        return transducer_ids;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));

        return printer;
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping