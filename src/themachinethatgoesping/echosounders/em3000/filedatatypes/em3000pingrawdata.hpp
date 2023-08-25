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
#include "../../pingtools/substructures/beamsampleselection.hpp"
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
    xt::xtensor<float, 1>        get_beam_pointing_angles(
               const pingtools::substructures::BeamSampleSelection& selection) const
    {
        const auto beam_numbers = selection.get_beam_numbers();

        auto beam_pointing_angles = xt::xtensor<float, 1>::from_shape({ beam_numbers.size() });

        for (unsigned int nr = 0; nr < beam_numbers.size(); ++nr)
        {
            if (beam_numbers[nr] >= get_beam_pointing_angles().size())
                beam_pointing_angles.unchecked(nr) = std::numeric_limits<float>::quiet_NaN();
            else
                beam_pointing_angles.unchecked(nr) =
                    get_beam_pointing_angles().unchecked(beam_numbers[nr]);
        }

        return beam_pointing_angles;
    }

    const xt::xtensor<uint16_t, 1>& get_start_range_sample_numbers() const
    {
        return _start_range_sample_numbers;
    }
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
    const xt::xtensor<size_t, 1>& get_sample_positions() const { return _sample_positions; }

    uint16_t get_number_of_beams() const
    {
        return _water_column_datagram->get_number_of_beams_in_datagram();
    }

    const auto& get_water_column_datagram() const { return *_water_column_datagram; }

    // ----- load datagrams -----
    boost::flyweights::flyweight<xt::xtensor<float, 1>>    _beam_pointing_angles;
    boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>> _start_range_sample_numbers;
    boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>> _number_of_samples_per_beam;
    xt::xtensor<uint16_t, 1>                               _detected_range_in_samples;
    boost::flyweights::flyweight<xt::xtensor<uint8_t, 1>>  _transmit_sector_numbers;
    xt::xtensor<size_t, 1>                                 _sample_positions;

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
        auto sample_positions           = xt::xtensor<size_t, 1>::from_shape({ nbeams });

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
    //  * @brief read all selected samples from the selected beams and convert them to float
    //  * @return xt::xtensor<float, 2>
    //  */
    xt::xtensor<float, 2> read_all_samples() const
    {
        return read_selected_samples(get_beam_sample_selection_all());
    }

    auto get_beam_sample_selection_all() const
    {
        const auto& start_range_sample_numbers = get_start_range_sample_numbers();
        const auto& number_of_samples_per_beam = get_number_of_samples_per_beam();

        // build BeamSampleSelection
        auto last_sample_number_per_beam =
            start_range_sample_numbers + number_of_samples_per_beam - 1;

        std::vector<uint16_t> first_snpb(start_range_sample_numbers.begin(),
                                         start_range_sample_numbers.end());
        std::vector<uint16_t> last_snpb(last_sample_number_per_beam.begin(),
                                        last_sample_number_per_beam.end());

        return pingtools::substructures::BeamSampleSelection(std::move(first_snpb),
                                                             std::move(last_snpb));
    }

    auto& get_wci_ifs() const
    {
        return this->_datagram_infos_by_type
            .at_const(t_EM3000DatagramIdentifier::WaterColumnDatagram)
            .at(0)
            ->get_stream();
    }

    auto read_beam_samples(uint16_t                                         bn,
                           const pingtools::substructures::ReadSampleRange& rsr,
                           t_ifstream&                                      ifs) const
    {
        // auto& ifs =
        //     this->_datagram_infos_by_type.at_const(t_EM3000DatagramIdentifier::WaterColumnDatagram)
        //         .at(0)
        //         ->get_stream();

        return datagrams::substructures::WaterColumnDatagramBeam::read_samples(
            ifs,
            _sample_positions.unchecked(bn),
            rsr.get_first_sample_to_read(),
            rsr.get_number_of_samples_to_read(),
            get_number_of_samples_per_beam().unchecked(bn));
    }

    // /**
    //  * @brief read the selected samples from the selected beams and convert them to float
    //  * @return xt::xtensor<float, 2>
    //  */
    xt::xtensor<float, 2> read_selected_samples(
        const pingtools::substructures::BeamSampleSelection& bss) const
    {
        auto samples = xt::xtensor<float, 2>::from_shape(
            { bss.get_number_of_beams(), bss.get_number_of_samples_ensemble() });

        // here we assume that all beams / water column datagrams originate from the same file /
        // file stream
        auto& ifs = get_wci_ifs();

        size_t bn_counter = 0; // counter for the selected beams
        for (const auto bn : bss.get_beam_numbers())
        {
            // of beam number does not exist fill beam with nan
            if (bn >= get_number_of_beams())
            {
                xt::view(samples, bn_counter, xt::all())
                    .fill(std::numeric_limits<float>::quiet_NaN());
                ++bn_counter;
                continue;
            }

            // read samples
            auto readsamplerange =
                bss.get_read_sample_range(bn_counter,
                                          get_start_range_sample_numbers().unchecked(bn),
                                          get_number_of_samples_per_beam().unchecked(bn));

            xt::xtensor<int8_t, 1> beam_samples = read_beam_samples(bn, readsamplerange, ifs);

            // assign samples to output
            xt::view(samples,
                     bn_counter,
                     xt::range(readsamplerange.get_first_read_sample_offset(),
                               readsamplerange.get_last_read_sample_offset() + 1)) =
                xt::cast<float>(beam_samples);

            // assign nan to samples that were not read
            xt::view(
                samples, bn_counter, xt::range(0, readsamplerange.get_first_read_sample_offset()))
                .fill(std::numeric_limits<float>::quiet_NaN());

            using namespace xt::placeholders;
            xt::view(samples,
                     bn_counter,
                     xt::range(readsamplerange.get_last_read_sample_offset() + 1, _))
                .fill(std::numeric_limits<float>::quiet_NaN());

            ++bn_counter;
        }

        return samples;
    }

    // I_PingBottom functions
    /**
     * @brief read XYZ for the bottom detection datagram
     *
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    algorithms::geoprocessing::datastructures::XYZ<1> read_xyz()
    {
        auto& datagram_infos =
            this->_datagram_infos_by_type.at(t_EM3000DatagramIdentifier::XYZDatagram);

        if (datagram_infos.empty())
            throw std::runtime_error(
                fmt::format("Error[EM3000PingRawData::read_xyz]: No XYZDatagram in ping!"));

        if (datagram_infos.size() > 1)
            throw std::runtime_error(
                fmt::format("Error[EM3000PingRawData::read_xyz]: More than one XYZDatagram in "
                            "ping!"));
        auto datagram =
            datagram_infos.at(0)->template read_datagram_from_file<datagrams::XYZDatagram>();

        return datagram.get_xyz();
    }

    /**
     * @brief read XYZ for the specified beams from the bottom detection datagram
     * Note: if the beam numbers from the beam selection exceed the number of beams in the
     * datagram, the corresponding XYZ values will be NaN
     *
     * @param bs beam selection
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    algorithms::geoprocessing::datastructures::XYZ<1> read_xyz(
        const pingtools::substructures::BeamSelection& bs)
    {
        auto& datagram_infos =
            this->_datagram_infos_by_type.at(t_EM3000DatagramIdentifier::XYZDatagram);

        if (datagram_infos.empty())
            throw std::runtime_error(
                fmt::format("Error[EM3000PingRawData::read_xyz]: No XYZDatagram in ping!"));

        if (datagram_infos.size() > 1)
            throw std::runtime_error(
                fmt::format("Error[EM3000PingRawData::read_xyz]: More than one XYZDatagram in "
                            "ping!"));
        auto datagram =
            datagram_infos.at(0)->template read_datagram_from_file<datagrams::XYZDatagram>();

        return datagram.get_xyz(bs.get_beam_numbers());
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