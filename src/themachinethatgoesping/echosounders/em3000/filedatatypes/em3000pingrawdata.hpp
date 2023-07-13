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
    const std::vector<float>& get_beam_pointing_angles() const { return _beam_pointing_angles; }
    std::vector<float>        get_selected_beam_pointing_angles() const
    {
        std::vector<float> selected_beam_pointing_angles;
        selected_beam_pointing_angles.reserve(_selected_beam_numbers.get().size());
        for (const auto& bn : _selected_beam_numbers.get())
            selected_beam_pointing_angles.push_back(_beam_pointing_angles.get().at(bn));
        return selected_beam_pointing_angles;
    }
    const std::vector<uint16_t>& get_start_range_sample_numbers() const
    {
        return _start_range_sample_numbers;
    }
    const std::vector<uint16_t>& get_number_of_samples_per_beam() const
    {
        return _number_of_samples_per_beam;
    }
    const std::vector<uint16_t>& get_detected_range_in_samples() const
    {
        return _detected_range_in_samples;
    }
    const std::vector<uint8_t>& get_transmit_sector_number() const
    {
        return _transmit_sector_number;
    }
    const std::vector<std::istream::pos_type>& get_sample_positions() const
    {
        return _sample_positions;
    }
    const std::vector<uint16_t>& get_selected_beam_numbers() const
    {
        return _selected_beam_numbers;
    }
    const std::vector<uint16_t>& get_selected_first_sample_per_beam() const
    {
        return _selected_first_sample_per_beam;
    }
    const std::vector<uint16_t>& get_selected_number_of_samples_per_beam() const
    {
        return _selected_number_of_samples_per_beam;
    }
    uint16_t get_number_of_selected_beams() const { return _selected_beam_numbers.get().size(); }
    uint16_t get_number_of_beams() const
    {
        return _water_column_datagram->get_number_of_beams_in_datagram();
    }
    std::vector<uint16_t> get_beam_numbers() const
    {
        // return a vector from 0 to get_number_of_beams()-1
        static std::vector<uint16_t> beam_numbers;
        beam_numbers.resize(get_number_of_beams());
        std::iota(beam_numbers.begin(), beam_numbers.end(), 0);
        return beam_numbers;
    }

    uint16_t get_first_sample_ensemble() const { return _first_sample_ensemble; }
    uint16_t get_number_of_samples_ensemble() const { return _number_of_samples_ensemble; }

    // ----- load datagrams -----
    boost::flyweights::flyweight<std::vector<float>>    _beam_pointing_angles;
    boost::flyweights::flyweight<std::vector<uint16_t>> _start_range_sample_numbers;
    boost::flyweights::flyweight<std::vector<uint16_t>> _number_of_samples_per_beam;
    boost::flyweights::flyweight<std::vector<uint16_t>> _detected_range_in_samples;
    boost::flyweights::flyweight<std::vector<uint8_t>>  _transmit_sector_number;
    std::vector<std::istream::pos_type>                 _sample_positions;

    boost::flyweights::flyweight<std::vector<uint16_t>> _selected_beam_numbers;
    boost::flyweights::flyweight<std::vector<uint16_t>> _selected_first_sample_per_beam;
    boost::flyweights::flyweight<std::vector<uint16_t>> _selected_number_of_samples_per_beam;
    uint16_t                                            _first_sample_ensemble;
    uint16_t                                            _number_of_samples_ensemble;

    void load_datagrams(bool skip_data = true)
    {
        _sample_positions.clear();

        std::vector<float>    beam_pointing_angles;
        std::vector<uint16_t> start_range_sample_numbers;
        std::vector<uint16_t> number_of_samples_per_beam;
        std::vector<uint16_t> detected_range_in_samples;
        std::vector<uint8_t>  transmit_sector_number;

        std::vector<uint16_t> selected_beam_numbers;
        std::vector<uint16_t> selected_first_sample_per_beam;
        std::vector<uint16_t> selected_number_of_samples_per_beam;

        auto water_column_datagram = read_merged_watercolumndatagram(skip_data);

        beam_pointing_angles.reserve(water_column_datagram.beams().size());
        start_range_sample_numbers.reserve(water_column_datagram.beams().size());
        number_of_samples_per_beam.reserve(water_column_datagram.beams().size());
        detected_range_in_samples.reserve(water_column_datagram.beams().size());
        transmit_sector_number.reserve(water_column_datagram.beams().size());

        selected_beam_numbers.reserve(water_column_datagram.beams().size());
        selected_first_sample_per_beam.reserve(water_column_datagram.beams().size());
        selected_number_of_samples_per_beam.reserve(water_column_datagram.beams().size());

        unsigned int counter = 0;
        for (const auto& b : water_column_datagram.beams())
        {
            _sample_positions.push_back(b.get_sample_position());

            beam_pointing_angles.push_back(b.get_beam_pointing_angle_in_degrees());
            detected_range_in_samples.push_back(b.get_detected_range_in_samples());
            start_range_sample_numbers.push_back(b.get_start_range_sample_number());
            number_of_samples_per_beam.push_back(b.get_number_of_samples());
            transmit_sector_number.push_back(b.get_transmit_sector_number());

            selected_beam_numbers.push_back(counter);
            selected_first_sample_per_beam.push_back(0);
            selected_number_of_samples_per_beam.push_back(b.get_number_of_samples());
        }

        _beam_pointing_angles                = beam_pointing_angles;
        _start_range_sample_numbers          = start_range_sample_numbers;
        _number_of_samples_per_beam          = number_of_samples_per_beam;
        _detected_range_in_samples           = detected_range_in_samples;
        _transmit_sector_number              = transmit_sector_number;
        _selected_beam_numbers               = selected_beam_numbers;
        _selected_first_sample_per_beam      = selected_first_sample_per_beam;
        _selected_number_of_samples_per_beam = selected_number_of_samples_per_beam;

        init_beam_sample_selection();

        _water_column_datagram =
            std::make_shared<datagrams::WaterColumnDatagram>(water_column_datagram.without_beams());
    }

    void init_beam_sample_selection()
    {
        const auto& selected_beam_numbers          = _selected_beam_numbers.get();
        const auto& selected_first_sample_per_beam = _selected_first_sample_per_beam.get();
        const auto& selected_number_of_samples_per_beam =
            _selected_number_of_samples_per_beam.get();

        if (selected_beam_numbers.empty())
            return;

        _first_sample_ensemble      = selected_first_sample_per_beam[selected_beam_numbers.at(0)];
        _number_of_samples_ensemble = 0;

        for (const auto bn : selected_beam_numbers)
        {
            _first_sample_ensemble =
                std::min(_first_sample_ensemble, selected_first_sample_per_beam[bn]);
        }

        for (const auto bn : selected_beam_numbers)
        {
            _number_of_samples_ensemble =
                std::max(_number_of_samples_ensemble,
                         uint16_t(selected_number_of_samples_per_beam[bn] - _first_sample_ensemble +
                                  selected_first_sample_per_beam[bn]));
        }
    }

    /**
     * @brief select the beams to be read from the water column datagram
     *
     * @param selected_beam_numbers
     */
    void select_beams_by_number(const std::vector<uint16_t>& selected_beam_numbers)
    {
        _selected_beam_numbers = selected_beam_numbers;
        init_beam_sample_selection();
    }

    /**
     * @brief select the samples to be read from the water column datagram
     *
     * @param first_sample First sample number in the datagram
     * @param number_of_samples Number of samples to read
     */
    void select_samples_by_range(uint16_t first_sample, uint16_t number_of_samples)
    {
        std::vector<uint16_t> selected_first_sample_per_beam;
        std::vector<uint16_t> selected_number_of_samples_per_beam;

        selected_first_sample_per_beam.reserve(_selected_number_of_samples_per_beam.get().size());
        selected_number_of_samples_per_beam.reserve(
            _selected_number_of_samples_per_beam.get().size());

        for (size_t bn = 0; bn < selected_number_of_samples_per_beam.size(); ++bn)
        {
            selected_first_sample_per_beam[bn]      = first_sample;
            selected_number_of_samples_per_beam[bn] = number_of_samples;
        }

        _selected_first_sample_per_beam      = selected_first_sample_per_beam;
        _selected_number_of_samples_per_beam = selected_number_of_samples_per_beam;

        init_beam_sample_selection();
    }

    /**
     * @brief select the samples to be read from the water column datagram
     *
     * @param first_sample first sample number in the datagram
     * @param last_sample last sample number in the datagram
     */
    void select_samples_by_first_last(uint16_t first_sample, uint16_t last_sample)
    {
        select_samples_by_range(first_sample, last_sample - first_sample + 1);
    }

    /**
     * @brief select the beams to be read from the water column datagram
     *
     * @param min_beam_angle Minimum beam angle in degrees
     * @param max_beam_angle Maximum beam angle in degrees
     */
    void select_beams_by_angle(float min_beam_angle, float max_beam_angle)
    {
        const auto& beam_pointing_angles = _beam_pointing_angles.get();

        std::vector<uint16_t> selected_beam_numbers;
        selected_beam_numbers.reserve(beam_pointing_angles.size());

        for (size_t bn = 0; bn < beam_pointing_angles.size(); ++bn)
        {
            if ((beam_pointing_angles[bn] >= min_beam_angle) &&
                (beam_pointing_angles[bn] <= max_beam_angle))
            {
                selected_beam_numbers.push_back(bn);
            }
        }

        _selected_beam_numbers = selected_beam_numbers;
        init_beam_sample_selection();
    }

    /**
     * @brief read the selected samples from the selected beams and convert them to float
     * @return xt::xtensor<float, 2>
     */
    xt::xtensor<float, 2> read_selected_samples()
    {
        const auto& selected_beam_numbers          = _selected_beam_numbers.get();
        const auto& selected_first_sample_per_beam = _selected_first_sample_per_beam.get();
        const auto& selected_number_of_samples_per_beam =
            _selected_number_of_samples_per_beam.get();
        const auto& number_of_samples_per_beam = _number_of_samples_per_beam.get();

        xt::xtensor<float, 2> samples = xt::empty<float>(xt::xtensor<float, 2>::shape_type(
            { selected_beam_numbers.size(), _number_of_samples_ensemble }));

        // here we assume that all beams / water column datagrams originate from the same file /
        // file stream
        auto& ifs =
            this->_datagram_infos_by_type.at(t_EM3000DatagramIdentifier::WaterColumnDatagram)
                .at(0)
                ->get_stream();

        size_t bn_counter = 0; // counter for the selected beams
        for (const auto bn : selected_beam_numbers)
        {
            size_t number_of_samples_to_read = selected_number_of_samples_per_beam.at(bn);
            size_t sample_offset             = selected_first_sample_per_beam.at(bn) -
                                   _first_sample_ensemble; // offset from ensemble start

            if (number_of_samples_to_read + selected_first_sample_per_beam[bn] >
                number_of_samples_per_beam.at(bn))
            {
                if (selected_first_sample_per_beam[bn] >= number_of_samples_per_beam[bn])
                    number_of_samples_to_read = 0;
                else
                    // read only the samples that are available
                    number_of_samples_to_read =
                        number_of_samples_per_beam[bn] - selected_first_sample_per_beam[bn];
            }

            xt::xtensor<int8_t, 1> beam_samples =
                datagrams::substructures::WaterColumnDatagramBeam::read_samples(
                    ifs,
                    _sample_positions.at(bn),
                    selected_first_sample_per_beam[bn],
                    number_of_samples_to_read,
                    number_of_samples_per_beam[bn]);

            // // beamsamples *= 0.5f;
            // // beamsamples -= _tvg_offset_in_db;

            using xt::placeholders::_;
            try
            {
                xt ::view(samples, bn_counter, xt ::range(_, sample_offset)) =
                    std::numeric_limits<float>::quiet_NaN();
            }
            catch (std::exception& e)
            {
                throw std::runtime_error(fmt::format("Exception[{}]: {}\n", 1, e.what()));
            }

            try
            {
                xt::view(samples,
                         bn_counter,
                         xt ::range(sample_offset, sample_offset + number_of_samples_to_read)) =
                    beam_samples;
            }
            catch (std::exception& e)
            {
                throw std::runtime_error(fmt::format("Exception[{}, {}, {}, {}, {}]: {}\n",
                                                     2,
                                                     sample_offset,
                                                     number_of_samples_to_read,
                                                     _number_of_samples_ensemble,
                                                     _first_sample_ensemble,
                                                     e.what()));
            }

            try
            {
                xt::view(
                    samples, bn_counter, xt ::range(sample_offset + number_of_samples_to_read, _)) =
                    std::numeric_limits<float>::quiet_NaN();
            }
            catch (std::exception& e)
            {
                throw std::runtime_error(fmt::format("Exception[{}]: {}\n", 3, e.what()));
            }

            ++bn_counter;
        }

        return samples;
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

        printer.register_section("Selection infos");
        printer.register_container("beam_pointing_angles", _beam_pointing_angles.get());
        printer.register_container("start_range_sample_numbers", _start_range_sample_numbers.get());
        printer.register_container("number_of_samples_per_bean", _number_of_samples_per_beam.get());
        printer.register_container("detected_range_in_samples", _detected_range_in_samples.get());
        printer.register_container("transmit_sector_number", _transmit_sector_number.get());

        printer.register_container("selected_beam_numbers", _selected_beam_numbers.get());
        printer.register_container("selected_first_sample_per_beam",
                                   _selected_first_sample_per_beam.get());
        printer.register_container("selected_number_of_samples_per_beam",
                                   _selected_number_of_samples_per_beam.get());
        printer.register_value("first_sample_ensemble", _first_sample_ensemble);
        printer.register_value("number_of_samples_ensemble", _number_of_samples_ensemble);

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