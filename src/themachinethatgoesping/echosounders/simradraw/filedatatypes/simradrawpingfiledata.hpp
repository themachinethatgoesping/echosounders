// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawpingfiledata.doc.hpp"

/* generated doc strings */
#include ".docstrings/simradrawping.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>

#include <boost/flyweight.hpp>
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
#include "../../filetemplates/datatypes/i_pingfiledata.hpp"
#include "../datagrams.hpp"
#include "../filedatainterfaces/simradrawdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {

template<typename t_ifstream>
class SimradRawPingFileData
    : public filetemplates::datatypes::I_PingFileData
    , public filedatainterfaces::SimradRawDatagramInterface<t_ifstream>
{
    using t_base1 = filetemplates::datatypes::I_PingFileData;
    using t_base2 = filedatainterfaces::SimradRawDatagramInterface<t_ifstream>;

    boost::flyweight<datagrams::xml_datagrams::XML_Parameter_Channel> _ping_parameter;
    std::string class_name() const override { return "SimradRawPingFileData"; }

  public:
    // filetemplates::datatypes::DatagramInfo_ptr<t_SimradRawDatagramIdentifier, t_ifstream>
    //     _datagram_info_file_data; ///< this can be RAW3 (EK80) or RAW0 (EK60)

    // datagrams::RAW3
    //     _ping_data; ///< when implementing EK60, this must become a variant type (RAW3 or RAW0)

  public:
    SimradRawPingFileData()
        : t_base1()
        , t_base2()
    {
    }

    // SimradRawPingFileData(
    //     filetemplates::datatypes::DatagramInfo_ptr<t_SimradRawDatagramIdentifier, t_ifstream>
    //                     datagram_info_file_data,
    //     datagrams::RAW3 ping_data)
    //     : t_base1()
    //     , t_base2()
    //     , _datagram_info_file_data(std::move(datagram_info_file_data))
    //     , _ping_data(std::move(ping_data))
    // {
    // }
    ~SimradRawPingFileData() = default;

    void add_parameter(boost::flyweight<datagrams::xml_datagrams::XML_Parameter_Channel> parameter)
    {
        _ping_parameter = parameter;
    }

    const datagrams::xml_datagrams::XML_Parameter_Channel& get_parameter() const
    {
        return _ping_parameter.get();
    }

    // ----- load skipped data -----
    datagrams::raw3datatypes::RAW3DataVariant get_sample_data() const
    {
        // if (std::holds_alternative<datagrams::raw3datatypes::RAW3DataSkipped>(
        //         _ping_data.sample_data()))
        //     return read_sample_data();

        // return _ping_data.sample_data();
    }

    datagrams::raw3datatypes::RAW3DataVariant read_sample_data() const
    {
        // return _ping_data.read_skipped_sample_data(_datagram_info_file_data->get_stream(),
        //                                           _datagram_info_file_data->get_file_pos());
    }

    void load()
    { //_ping_data.sample_data() = read_sample_data();
    }

    void release()
    { //_ping_data.sample_data() = datagrams::raw3datatypes::RAW3DataSkipped();
    }

    // ----- i_RAW3Data interface -----
    bool has_power() const
    {
        // using namespace datagrams::raw3datatypes;

        // switch (_ping_data.get_data_type())
        // {
        //     case t_RAW3DataType::Angle:
        //         return false;
        //     case t_RAW3DataType::Power:
        //         [[fallthrough]];
        //     case t_RAW3DataType::ComplexFloat32:
        //         [[fallthrough]];
        //     case t_RAW3DataType::PowerAndAngle:
        //         [[fallthrough]];
        //     case t_RAW3DataType::ComplexFloat16:
        //         return true;
        //     default:
        //         throw std::runtime_error("Unknown data type");
        // }
    }

    bool has_angle() const
    {
        // using namespace datagrams::raw3datatypes;

        // switch (_ping_data.get_data_type())
        // {
        //     case t_RAW3DataType::Power:
        //         return false;
        //     case t_RAW3DataType::Angle:
        //         [[fallthrough]];
        //     case t_RAW3DataType::ComplexFloat32:
        //         [[fallthrough]];
        //     case t_RAW3DataType::PowerAndAngle:
        //         [[fallthrough]];
        //     case t_RAW3DataType::ComplexFloat16:
        //         return true;
        //     default:
        //         throw std::runtime_error("Unknown data type");
        // }
    }

    // ----- I_PingFileData Interface -----
    std::vector<size_t> get_file_numbers() const final
    {
        std::vector<size_t> fnr     = { get_primary_file_nr() };
        std::set<size_t>    fnr_set = { get_primary_file_nr() };

        for (const auto& datagram_info : this->_datagram_infos_all)
        {
            auto nr = datagram_info->get_file_nr();
            if (!fnr_set.contains(nr))
            {
                fnr.push_back(nr);
                fnr_set.insert(nr);
            }
        }

        return fnr;
    }
    std::string get_primary_file_path() const final
    {
        must_have_datagrams("get_primary_file_path");

        return this->_datagram_infos_all.at(0)->file_nr_to_file_path(get_primary_file_nr());
    }
    std::vector<std::string> get_file_paths() const final
    {
        must_have_datagrams("get_file_paths");

        auto fnrs = get_file_numbers();

        std::vector<std::string> fps;

        for (const auto& fnr : fnrs)
        {
            fps.push_back(this->_datagram_infos_all.at(0)->file_nr_to_file_path(fnr));
        }

        return fps;
    }

    void must_have_datagrams(std::string_view method_name) const
    {
        if (this->_datagram_infos_all.empty())
            throw std::runtime_error(
                fmt::format("{}: No datagram in ping!", __func__, method_name));
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        printer.append(t_base1::__printer__(float_precision));
        printer.append(t_base2::__printer__(float_precision));

        printer.register_section("Raw data infos");

        // // convert _ping_data.get_data_type() to string using magic enum
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