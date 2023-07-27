// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/em3000pingrawdata.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>

/* external library includes */
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

    // ----- getter/setters -----
    const xt::xtensor<float, 1>& get_beam_pointing_angles() const { return _beam_pointing_angles; }

    const xt::xtensor<uint16_t, 1>& get_number_of_samples_per_beam() const
    {
        return _number_of_samples_per_beam;
    }
    const xt::xtensor<uint16_t, 1>& get_detected_range_in_samples() const
    {
        return _detected_range_in_samples;
    }
    const xt::xtensor<uint8_t, 1>& get_transmit_sector_numbers() const
    {
        return _transmit_sector_numbers;
    }
    const xt::xtensor<std::istream::pos_type, 1>& get_sample_positions() const
    {
        return _sample_positions;
    }

    uint16_t get_number_of_beams() const
    {
        return _water_column_datagram->get_number_of_beams_in_datagram();
    }

    // ----- load datagrams -----
    boost::flyweights::flyweight<xt::xtensor<float, 1>>    _beam_pointing_angles;
    boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>> _start_range_sample_numbers;
    boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>> _number_of_samples_per_beam;
    xt::xtensor<uint16_t, 1>                               _detected_range_in_samples;
    boost::flyweights::flyweight<xt::xtensor<uint8_t, 1>>  _transmit_sector_numbers;
    xt::xtensor<std::istream::pos_type, 1>                 _sample_positions;

    void load_datagrams(bool skip_data = true)
    {
        auto water_column_datagram = read_merged_watercolumndatagram(skip_data);
        auto nbeams                = water_column_datagram.beams().size();

        // initialize arrays using from shape function
        auto beam_pointing_angles       = xt::xtensor<float, 1>::from_shape({ nbeams });
        auto start_range_sample_numbers = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
        auto number_of_samples_per_beam = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
        auto detected_range_in_samples  = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
        auto transmit_sector_numbers    = xt::xtensor<uint8_t, 1>::from_shape({ nbeams });
        auto sample_positions = xt::xtensor<std::istream::pos_type, 1>::from_shape({ nbeams });

        size_t bn = 0;
        for (const auto& b : water_column_datagram.beams())
        {
            sample_positions.unchecked(bn) = b.get_sample_position();

            beam_pointing_angles.unchecked(bn)       = b.get_beam_pointing_angle_in_degrees();
            detected_range_in_samples.unchecked(bn)  = b.get_detected_range_in_samples();
            start_range_sample_numbers.unchecked(bn) = b.get_start_range_sample_number();
            number_of_samples_per_beam.unchecked(bn) = b.get_number_of_samples();
            transmit_sector_numbers.unchecked(bn)    = b.get_transmit_sector_number();

            ++bn;
        }

        _sample_positions           = std::move(sample_positions);
        _beam_pointing_angles       = std::move(beam_pointing_angles);
        _start_range_sample_numbers = std::move(start_range_sample_numbers);
        _number_of_samples_per_beam = std::move(number_of_samples_per_beam);
        _detected_range_in_samples  = std::move(detected_range_in_samples);
        _transmit_sector_numbers    = std::move(transmit_sector_numbers);

        _water_column_datagram =
            std::make_shared<datagrams::WaterColumnDatagram>(water_column_datagram.without_beams());
    }

    // /**
    //  * @brief read the selected samples from the selected beams and convert them to float
    //  * @return xt::xtensor<float, 2>
    //  */
    xt::xtensor<float, 2> read_selected_samples()
    {
        // const auto& selected_beam_numbers          = _selected_beam_numbers.get();
        // const auto& selected_first_sample_per_beam = _selected_first_sample_per_beam.get();
        // const auto& selected_number_of_samples_per_beam =
        //     _selected_number_of_samples_per_beam.get();
        // const auto& number_of_samples_per_beam = _number_of_samples_per_beam.get();

        // xt::xtensor<float, 2> samples = xt::empty<float>(xt::xtensor<float, 2>::shape_type(
        //     { selected_beam_numbers.size(), _number_of_samples_ensemble }));

        // // here we assume that all beams / water column datagrams originate from the same file /
        // // file stream
        // auto& ifs =
        //     this->_datagram_infos_by_type.at(t_EM3000DatagramIdentifier::WaterColumnDatagram)
        //         .at(0)
        //         ->get_stream();

        // size_t bn_counter = 0; // counter for the selected beams
        // for (const auto bn : selected_beam_numbers)
        // {
        //     size_t number_of_samples_to_read = selected_number_of_samples_per_beam.at(bn);
        //     size_t sample_offset             = selected_first_sample_per_beam.at(bn) -
        //                            _first_sample_ensemble; // offset from ensemble start

        //     if (number_of_samples_to_read + selected_first_sample_per_beam[bn] >
        //         number_of_samples_per_beam.at(bn))
        //     {
        //         if (selected_first_sample_per_beam[bn] >= number_of_samples_per_beam[bn])
        //             number_of_samples_to_read = 0;
        //         else
        //             // read only the samples that are available
        //             number_of_samples_to_read =
        //                 number_of_samples_per_beam[bn] - selected_first_sample_per_beam[bn];
        //     }

        //     xt::xtensor<int8_t, 1> beam_samples =
        //         datagrams::substructures::WaterColumnDatagramBeam::read_samples(
        //             ifs,
        //             _sample_positions.at(bn),
        //             selected_first_sample_per_beam[bn],
        //             number_of_samples_to_read,
        //             number_of_samples_per_beam[bn]);

        //     // // beamsamples *= 0.5f;
        //     // // beamsamples -= _tvg_offset_in_db;

        //     using xt::placeholders::_;
        //     try
        //     {
        //         xt ::view(samples, bn_counter, xt ::range(_, sample_offset)) =
        //             std::numeric_limits<float>::quiet_NaN();
        //     }
        //     catch (std::exception& e)
        //     {
        //         throw std::runtime_error(fmt::format("Exception[{}]: {}\n", 1, e.what()));
        //     }

        //     try
        //     {
        //         xt::view(samples,
        //                  bn_counter,
        //                  xt ::range(sample_offset, sample_offset + number_of_samples_to_read)) =
        //             beam_samples;
        //     }
        //     catch (std::exception& e)
        //     {
        //         throw std::runtime_error(fmt::format("Exception[{}, {}, {}, {}, {}]: {}\n",
        //                                              2,
        //                                              sample_offset,
        //                                              number_of_samples_to_read,
        //                                              _number_of_samples_ensemble,
        //                                              _first_sample_ensemble,
        //                                              e.what()));
        //     }

        //     try
        //     {
        //         xt::view(
        //             samples, bn_counter, xt ::range(sample_offset + number_of_samples_to_read,
        //             _)) = std::numeric_limits<float>::quiet_NaN();
        //     }
        //     catch (std::exception& e)
        //     {
        //         throw std::runtime_error(fmt::format("Exception[{}]: {}\n", 3, e.what()));
        //     }

        //     ++bn_counter;
        // }

        // return samples;
        return xt::xtensor<float, 2>();
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));

        printer.register_section("Raw data infos");

        printer.register_container("beam_pointing_angles", _beam_pointing_angles.get());
        printer.register_container("start_range_sample_numbers", _start_range_sample_numbers.get());
        printer.register_container("number_of_samples_per_bean", _number_of_samples_per_beam.get());
        printer.register_container("detected_range_in_samples", _detected_range_in_samples);
        printer.register_container("transmit_sector_numbers", _transmit_sector_numbers.get());

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