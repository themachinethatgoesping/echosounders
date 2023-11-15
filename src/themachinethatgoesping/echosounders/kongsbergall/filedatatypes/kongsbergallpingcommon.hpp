// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallpingcommon.doc.hpp"

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
#include "../kongsbergall_datagrams.hpp"

#include "kongsbergallpingrawdata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {

template<typename t_ifstream>
class KongsbergAllPingCommon : virtual public filetemplates::datatypes::I_PingCommon
{
  protected:
    // raw data
    using t_rawdata                      = KongsbergAllPingRawData<t_ifstream>;
    std::shared_ptr<t_rawdata> _raw_data = std::make_shared<t_rawdata>();

  public:
    using t_base = filetemplates::datatypes::I_PingCommon;
    KongsbergAllPingCommon()
        : t_base("KongsbergAllPingCommon")
    {
    }
    KongsbergAllPingCommon(std::shared_ptr<t_rawdata> raw_Data)
        : t_base("KongsbergAllPingCommon")
        , _raw_data(std::move(raw_Data))
    {
    }
    virtual ~KongsbergAllPingCommon() = default;

    // // explicit copy constructor and assignment operators
    // KongsbergAllPingCommon(const KongsbergAllPingCommon& other)
    //     : t_base(other)
    //     , _raw_data(std::make_shared<t_rawdata>(*other._raw_data))
    // {
    // }
    // KongsbergAllPingCommon& operator=(const KongsbergAllPingCommon& other)
    // {
    //     t_base::operator=(other);
    //     _raw_data = std::make_shared<t_rawdata>(*other._raw_data);
    //     return *this;
    // }

    const t_rawdata& raw_data() const { return *_raw_data; }
    t_rawdata&       raw_data() { return *_raw_data; }
    void set_raw_data(std::shared_ptr<t_rawdata> raw_data) { _raw_data = std::move(raw_data); }

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