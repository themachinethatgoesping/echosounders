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

    // parameters (read when adding datagram infos)
    std::shared_ptr<datagrams::RuntimeParameters> _runtime_parameters =
        std::make_shared<datagrams::RuntimeParameters>();

    std::shared_ptr<datagrams::WaterColumnDatagram> _water_column_datagram =
        std::make_shared<datagrams::WaterColumnDatagram>();

  public:
    // filetemplates::datatypes::DatagramInfo_ptr<t_EM3000DatagramIdentifier, t_ifstream>
    //     _datagram_info_raw_data; ///< this can be RAW3 (EK80) or RAW0 (EK60)

    void set_runtime_parameters(std::shared_ptr<datagrams::RuntimeParameters> arg)
    {
        _runtime_parameters = std::move(arg);
    }
    const datagrams::RuntimeParameters& get_runtime_parameters() const
    {
        return *_runtime_parameters;
    }

    // datagrams::RAW3
    //     _ping_data; ///< when implementing EK60, this must become a variant type (RAW3 or RAW0)
    datagrams::WaterColumnDatagram read_merged_watercolumndatagram(bool skip_data = false)
    {
        auto& datagram_infos =
            this->_datagram_infos_by_type.at(t_EM3000DatagramIdentifier::WaterColumnDatagram);

        if (datagram_infos.empty())
            throw std::runtime_error(
                fmt::format("Error[EM3000PingRawData::read_merged_watercolumndatagram]: No water "
                            "column datagram in ping!"));

        auto datagram =
            datagram_infos.at(0)->template read_datagram_from_file<datagrams::WaterColumnDatagram>(
                skip_data);

        for (size_t i = 1; i < datagram_infos.size(); ++i)
        {
            datagram.append_from_stream(datagram_infos[i]->get_stream_and_seek());
        }

        return datagram;
    }

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

    // ----- load datagrams -----
    std::vector<float>                  _beam_pointing_angles;
    std::vector<uint16_t>               _start_range_sample_numbers;
    std::vector<uint16_t>               _number_of_samples;
    std::vector<uint16_t>               _detected_range_in_samples;
    std::vector<uint8_t>                _transmit_sector_number;
    std::vector<uint8_t>                _beam_number;
    std::vector<std::istream::pos_type> _sample_positions;
    void                                load_datagrams(bool skip_data = true)
    {
        _beam_pointing_angles.clear();
        _start_range_sample_numbers.clear();
        _number_of_samples.clear();
        _detected_range_in_samples.clear();
        _transmit_sector_number.clear();
        _beam_number.clear();
        _sample_positions.clear();

        auto water_column_datagram = read_merged_watercolumndatagram(skip_data);

        for (const auto& b : water_column_datagram.beams())
        {
            _beam_pointing_angles.push_back(b.get_beam_pointing_angle_in_degrees());
            _start_range_sample_numbers.push_back(b.get_start_range_sample_number());
            _number_of_samples.push_back(b.get_number_of_samples());
            _detected_range_in_samples.push_back(b.get_detected_range_in_samples());
            _transmit_sector_number.push_back(b.get_transmit_sector_number());
            _beam_number.push_back(b.get_beam_number());
            _sample_positions.push_back(b.get_sample_position());
        }

        _water_column_datagram =
            std::make_shared<datagrams::WaterColumnDatagram>(water_column_datagram.without_beams());
    }

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

        printer.append(t_base::__printer__(float_precision));

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