// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/em3000pingrawdata.doc.hpp"

/* generated doc strings */
#include ".docstrings/em3000ping.doc.hpp"

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
#include "../../filetemplates/datatypes/i_ping.hpp"
#include "../em3000_datagrams.hpp"
#include "../filedatainterfaces/em3000datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatatypes {

template<typename t_ifstream>
class EM3000PingRawData : public filedatainterfaces::EM3000DatagramInterface<t_ifstream>
{
    using t_base = filedatainterfaces::EM3000DatagramInterface<t_ifstream>;
    // std::shared_ptr<datagrams::xml_datagrams::XML_Parameter_Channel> _ping_parameter;
    std::string_view get_name() const { return "EM3000PingRawData"; }

  public:
    // filetemplates::datatypes::DatagramInfo_ptr<t_EM3000DatagramIdentifier, t_ifstream>
    //     _datagram_info_raw_data; ///< this can be RAW3 (EK80) or RAW0 (EK60)

    // datagrams::RAW3
    //     _ping_data; ///< when implementing EK60, this must become a variant type (RAW3 or RAW0)

  public:
    EM3000PingRawData()
        : t_base("EM3000PingRawData")
    {
    }
    // EM3000PingRawData(filetemplates::datatypes::DatagramInfo_ptr<t_EM3000DatagramIdentifier,
    //                                                              t_ifstream>
    //                                                              datagram_info_raw_data,
    //                   datagrams::RAW3                                        ping_data)
    //     : _datagram_info_raw_data(std::move(datagram_info_raw_data))
    //     , _ping_data(std::move(ping_data))
    // {
    // }
    ~EM3000PingRawData() = default;

    // void add_parameter(std::shared_ptr<datagrams::xml_datagrams::XML_Parameter_Channel>
    // parameter)
    // {
    //     _ping_parameter = std::move(parameter);
    // }

    // const datagrams::xml_datagrams::XML_Parameter_Channel& get_parameter() const
    // {
    //     return *_ping_parameter;
    // }

    // ----- load skipped data -----
    // datagrams::raw3datatypes::RAW3DataVariant get_sample_data()
    // {
    //     if (std::holds_alternative<datagrams::raw3datatypes::RAW3DataSkipped>(
    //             _ping_data.sample_data()))
    //         return read_sample_data();

    //     return _ping_data.sample_data();
    // }

    // datagrams::raw3datatypes::RAW3DataVariant read_sample_data()
    // {
    //     return _ping_data.read_skipped_sample_data(_datagram_info_raw_data->get_stream(),
    //                                                _datagram_info_raw_data->get_file_pos());
    // }

    // void load_data() { _ping_data.sample_data() = read_sample_data(); }

    // void release_data() { _ping_data.sample_data() = datagrams::raw3datatypes::RAW3DataSkipped();
    // }

    // ----- i_RAW3Data interface -----
    // bool has_power() const
    // {
    //     using namespace datagrams::raw3datatypes;

    //     switch (_ping_data.get_data_type())
    //     {
    //         case t_RAW3DataType::Angle:
    //             return false;
    //         case t_RAW3DataType::Power:
    //             [[fallthrough]];
    //         case t_RAW3DataType::ComplexFloat32:
    //             [[fallthrough]];
    //         case t_RAW3DataType::PowerAndAngle:
    //             [[fallthrough]];
    //         case t_RAW3DataType::ComplexFloat16:
    //             return true;
    //         default:
    //             throw std::runtime_error("Unknown data type");
    //     }
    // }

    // bool has_angle() const
    // {
    //     using namespace datagrams::raw3datatypes;

    //     switch (_ping_data.get_data_type())
    //     {
    //         case t_RAW3DataType::Power:
    //             return false;
    //         case t_RAW3DataType::Angle:
    //             [[fallthrough]];
    //         case t_RAW3DataType::ComplexFloat32:
    //             [[fallthrough]];
    //         case t_RAW3DataType::PowerAndAngle:
    //             [[fallthrough]];
    //         case t_RAW3DataType::ComplexFloat16:
    //             return true;
    //         default:
    //             throw std::runtime_error("Unknown data type");
    //     }
    // }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.register_section("Raw data infos");

        // convert _ping_data.get_data_type() to string using magic enum
        // printer.register_string("Raw data type",
        //                         std::string(magic_enum::enum_name(_ping_data.get_data_type())));
        // printer.register_value("Has power", has_power());
        // printer.register_value("Has angle", has_angle());

        // printer.register_section("Important members");
        // printer.register_string("ping_data", "RAW3DataVariant");
        // printer.register_string("get_parameter()", "XML_Parameter_Channel");

        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping