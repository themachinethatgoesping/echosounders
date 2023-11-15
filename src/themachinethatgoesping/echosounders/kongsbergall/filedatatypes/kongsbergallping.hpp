// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallping.doc.hpp"

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
#include "../../filetemplates/datatypes/i_ping.hpp"
#include "../datagrams.hpp"

#include "kongsbergallpingbottom.hpp"
#include "kongsbergallpingcommon.hpp"
#include "kongsbergallpingwatercolumn.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {

template<typename t_ifstream>
class KongsbergAllPing
    : public filetemplates::datatypes::I_Ping
    , public KongsbergAllPingCommon<t_ifstream>
{
    // file nr and path of primary file
    size_t      _file_nr;
    std::string _file_path;

    KongsbergAllPingBottom<t_ifstream>      _bottom;
    KongsbergAllPingWatercolumn<t_ifstream> _watercolumn;

  public:
    using t_base0 =
        filetemplates::datatypes::I_PingCommon; // this is the common ancestor which is virtually
                                                // inherited by base1 and base2
    using t_base1               = filetemplates::datatypes::I_Ping;
    using t_base2               = KongsbergAllPingCommon<t_ifstream>;
    using type_DatagramInfo_ptr = typename KongsbergAllPingRawData<t_ifstream>::type_DatagramInfo_ptr;

    // select virtual overrides
    using t_base1::set_channel_id;

  protected:
    using t_base0::register_feature;
    using t_base2::_raw_data;
    using typename t_base2::t_rawdata;

  public:
    KongsbergAllPing(size_t                                   file_nr,
               std::string                              file_path,
               const datagrams::InstallationParameters& param)
        : t_base0("KongsbergAllPing")
        , t_base1()
        , t_base2()
        , _file_nr(file_nr)
        , _file_path(std::move(file_path))
        , _bottom(_raw_data)
        , _watercolumn(_raw_data)
    {
        /* set i_ping parameters */
        set_channel_id(param.build_channel_id());
    }
    virtual ~KongsbergAllPing() = default;

    /**
     * @brief Provide a deep copy of the ping object (deep copy raw_data shared pointer)
     *
     * @param other
     * @return KongsbergAllPing<t_ifstream>
     */
    KongsbergAllPing<t_ifstream> deep_copy()
    {
        KongsbergAllPing<t_ifstream> ping = *this;

        // copy the raw_data shared pointer and set it in the bottom and watercolumn objects
        ping.set_raw_data(std::make_shared<t_rawdata>(*_raw_data));
        ping.bottom().set_raw_data(ping._raw_data);
        ping.watercolumn().set_raw_data(ping._raw_data);

        return ping;
    }

    size_t      get_file_nr() const final { return _file_nr; }
    std::string get_file_path() const final { return _file_path; }

    void add_datagram_info(const type_DatagramInfo_ptr& datagram_info)
    {
        // update timestamp if it is much smaller or larger than the current one
        if (_timestamp < datagram_info->get_timestamp() - 1000 ||
            _timestamp > datagram_info->get_timestamp())
            _timestamp = datagram_info->get_timestamp();

        _raw_data->add_datagram_info(datagram_info);
    }

    void set_runtime_parameters(std::shared_ptr<datagrams::RuntimeParameters> runtime_parameters)
    {
        _raw_data->set_runtime_parameters(runtime_parameters);
    }

    // ----- I_Ping interface -----
    using t_base2::raw_data;
    using t_base1::get_file_ping_counter;
    using t_base1::set_file_ping_counter;

    // ----- bottom -----
    using t_base1::bottom;
    using t_base1::watercolumn;
    KongsbergAllPingBottom<t_ifstream>&      bottom() override { return _bottom; }
    KongsbergAllPingWatercolumn<t_ifstream>& watercolumn() override { return _watercolumn; }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base1::__printer__(float_precision));
        // printer.append(t_base1::__printer__(float_precision));

        // printer.register_section("KongsbergAll ping infos");

        // printer.register_string(
        //     "Sample data type",
        //     std::string(magic_enum::enum_name(_raw_data->_ping_data.get_data_type())));

        // printer.register_section("Important members");
        // printer.register_string("raw_data", "KongsbergAllPingRawData");

        return printer;
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping