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
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper/defaultsharedpointermap.hpp>


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
    KongsbergAllPingBottom<t_ifstream>      _bottom;
    KongsbergAllPingWatercolumn<t_ifstream> _watercolumn;

  public:
    using t_base1 = filetemplates::datatypes::I_Ping;
    using t_base2 = KongsbergAllPingCommon<t_ifstream>;
    using type_DatagramInfo_ptr =
        typename KongsbergAllPingFileData<t_ifstream>::type_DatagramInfo_ptr;

  protected:
    std::string class_name() const override { return "KongsbergAllPing"; }
    using t_base2::_file_data;
    using typename t_base2::t_rawdata;

  public:
    KongsbergAllPing(const datagrams::InstallationParameters& param)
        : t_base1()
        , t_base2()
        , _bottom(_file_data)
        , _watercolumn(_file_data)
    {
        /* set i_ping parameters */
        set_channel_id(param.build_channel_id());
    }
    virtual ~KongsbergAllPing() = default;

    /**
     * @brief Provide a deep copy of the ping object (deep copy file_data shared pointer)
     *
     * @param other
     * @return KongsbergAllPing<t_ifstream>
     */
    KongsbergAllPing<t_ifstream> deep_copy()
    {
        KongsbergAllPing<t_ifstream> ping = *this;

        // copy the file_data shared pointer and set it in the bottom and watercolumn objects
        ping.set_file_data(std::make_shared<t_rawdata>(*_file_data));
        ping.bottom().set_file_data(ping._file_data);
        ping.watercolumn().set_file_data(ping._file_data);

        return ping;
    }

    void add_datagram_info(const type_DatagramInfo_ptr& datagram_info)
    {
        // update timestamp if it is much smaller or larger than the current one
        if (_timestamp < datagram_info->get_timestamp() - 1000 ||
            _timestamp > datagram_info->get_timestamp())
            _timestamp = datagram_info->get_timestamp();

        _file_data->add_datagram_info(datagram_info);
    }

    // ----- I_Ping interface -----
    using t_base2::file_data;

    // ----- bottom -----
    using t_base1::bottom;
    using t_base1::watercolumn;
    KongsbergAllPingBottom<t_ifstream>&      bottom() override { return _bottom; }
    KongsbergAllPingWatercolumn<t_ifstream>& watercolumn() override { return _watercolumn; }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base1::__printer__(float_precision, superscript_exponents));
        // printer.append(t_base1::__printer__(float_precision, superscript_exponents));

        // printer.register_section("KongsbergAll ping infos");

        // printer.register_string(
        //     "Sample data type",
        //     std::string(magic_enum::enum_name(_file_data->_ping_data.get_data_type())));

        // printer.register_section("Important members");
        // printer.register_string("file_data", "KongsbergAllPingFileData");

        return printer;
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping