// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawpingfiledata.doc.hpp"

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
#include "calibration/simradrawwatercolumncalibration.hpp"
#include "sub/transceiverinformation.hpp"

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

    std::string class_name() const override { return "SimradRawPingFileData"; }

    datagrams::RAW3
        _ping_data; ///< when implementing EK60, this must become a variant type (RAW3 or RAW0)
    boost::flyweight<datagrams::xml_datagrams::XML_Parameter_Channel> _ping_parameter;
    boost::flyweight<datagrams::xml_datagrams::XML_Environment>       _ping_environment;
    boost::flyweight<_sub::TransceiverInformation>                    _transceiver_information;

    std::unique_ptr<boost::flyweight<calibration::SimradRawWaterColumnCalibration>>
        _watercolumn_calibration;

  public:
    // filetemplates::datatypes::DatagramInfo_ptr<t_SimradRawDatagramIdentifier, t_ifstream>
    //     _datagram_info_file_data; ///< this can be RAW3 (EK80) or RAW0 (EK60)

  public:
    SimradRawPingFileData(const datagrams::RAW3& raw3_datagram)
        : t_base1()
        , t_base2()
        , _ping_data(raw3_datagram)
    {
    }

    SimradRawPingFileData(const SimradRawPingFileData& other)
        : t_base1(other)
        , t_base2(other)
        , _ping_data(other._ping_data)
        , _ping_parameter(other._ping_parameter)
        , _ping_environment(other._ping_environment)
        , _transceiver_information(other._transceiver_information)
    {
        _watercolumn_calibration = other._watercolumn_calibration
                                       ? std::make_unique<boost::flyweight<calibration::SimradRawWaterColumnCalibration>>(
                                             *other._watercolumn_calibration)
                                       : nullptr;
    }

    void init_watercolumn_calibration(bool force = false)
    {
        using datagrams::raw3datatypes::t_RAW3DataType;

        if (_watercolumn_calibration && !force)
            return;

        size_t n_complex_samples = 0;
        switch (_ping_data.get_data_type())
        {
            case t_RAW3DataType::ComplexFloat32:
                n_complex_samples = _ping_data.get_number_of_complex_samples();
                break;
            case t_RAW3DataType::PowerAndAngle:
                [[fallthrough]];
            case t_RAW3DataType::Power:
                [[fallthrough]];
            case t_RAW3DataType::Angle:
                n_complex_samples = 0;
                break;
            default:
                throw std::runtime_error(
                    "Error[SimradRawPingFileData::init_watercolumn_calibration]: "
                    "Unsupported data type!");
        }

        _watercolumn_calibration =
            std::make_unique<boost::flyweight<calibration::SimradRawWaterColumnCalibration>>(
                _ping_environment.get(),
                _ping_parameter.get(),
                _transceiver_information.get(),
                n_complex_samples);
    }
    void release_watercolumn_calibration() { _watercolumn_calibration.reset(); }

    bool has_watercolumn_calibration() const { return bool(_watercolumn_calibration); }

    const auto& get_watercolumn_calibration() const
    {
        if (!watercolumn_calibration_loaded())
            throw std::runtime_error("Error[SimradRawPingFileData::get_watercolumn_calibration]: "
                                     "Calibration not initialized!");

        return _watercolumn_calibration->get();
    }

    void set_watercolumn_calibration(
        const calibration::SimradRawWaterColumnCalibration& calibration)
    {
        _watercolumn_calibration =
            std::make_unique<boost::flyweight<calibration::SimradRawWaterColumnCalibration>>(
                calibration);
    }

    const _sub::TransceiverInformation& get_transceiver_information() const
    {
        return _transceiver_information.get();
    }

    ~SimradRawPingFileData() = default;

    void set_transceiver_information(
        boost::flyweight<_sub::TransceiverInformation> transceiver_information)
    {
        _transceiver_information = transceiver_information;
    }

    /**
     * @brief Get the pulse duration index
     * This index is used to look up the correct sa correction / gain value in the transceiver
     * Is determined by the index of the used pulse duration in the transceiver configuration
     *
     * @return size_t
     */
    size_t get_pulse_duration_index() const
    {
        const auto& param = get_parameter();
        return _transceiver_information.get().get_pulse_duration_index(
            param.get_pulse_duration(), param.get_pulse_form_is_fm());
    }

    // // EK80 calibration information
    // float get_sa_correction() const
    // {
    //     auto pd_index = get_pulse_duration_index();

    //     return get_parameter().get_sa_correction().at(pd_index);
    // }

    // // EK80 calibration information
    // float get_transmitted_power() const
    // {
    //     auto pd_index = get_pulse_duration_index();

    //     return get_parameter().get_transmitted_power().at(pd_index);
    // }

    void set_parameter(boost::flyweight<datagrams::xml_datagrams::XML_Parameter_Channel> parameter)
    {
        _ping_parameter = parameter;
    }

    void set_environment(boost::flyweight<datagrams::xml_datagrams::XML_Environment> environment)
    {
        _ping_environment = environment;
    }

    const datagrams::xml_datagrams::XML_Parameter_Channel& get_parameter() const
    {
        return _ping_parameter.get();
    }

    const datagrams::xml_datagrams::XML_Environment& get_environment() const
    {
        return _ping_environment.get();
    }

    const datagrams::RAW3 get_ping_data() const { return _ping_data; }

    // ----- load skipped data -----
    // TODO: add function to only read samples within a specific range
    xt::xtensor<float, 1> read_sample_data(bool dB = false)
    {
        if (this->_datagram_infos_by_type.at(t_SimradRawDatagramIdentifier::RAW3).empty())
            throw std::runtime_error("No RAW3 datagram in ping!");

        // this assumes that there is exactly one RAW3 datagram saved for this ping
        const auto& datagram_info =
            this->_datagram_infos_by_type.at(t_SimradRawDatagramIdentifier::RAW3).at(0);

        auto sample_data = _ping_data.read_skipped_sample_data(datagram_info->get_stream(),
                                                               datagram_info->get_file_pos());

        return tools::helper::visit_variant(
            sample_data,
            [dB, this](datagrams::raw3datatypes::RAW3DataComplexFloat32& data) {
                float conv_factor = this->get_transceiver_information().get_impedance_factor() /
                                    data._complex_samples.shape()[1];
                if (dB)
                {
                    conv_factor = 10 * std::log10(conv_factor);
                    return xt::xtensor<float, 1>(data.get_power(dB) + conv_factor);
                }
                return xt::xtensor<float, 1>(data.get_power(dB) * conv_factor);
            },
            [dB](auto& data) { return data.get_power(dB); });
    }

    // float get_impedance_factor() const
    // {
    //     def compute_impedance_factor(ping, tdi)
    //         : tci = fh.configuration_interface.per_file()[ping.file_data.get_primary_file_nr()]
    //                     .get_configuration_datagram()
    //                     .get_transceiver(ping.get_channel_id())
    //                     .Impedance return 10 *
    //                 np.log10(((tci + tdi) / tci) * *2 / tdi)
    //     , ((tci + tdi) / tci) * *2 / tdi

    //     // return get_parameter().get_impedance_factor();
    // }

    bool watercolumn_calibration_loaded() const
    {
        return _watercolumn_calibration && _watercolumn_calibration->get().initialized();
    }

    // ----- i_RAW3Data interface -----
    bool has_power() const
    {
        using namespace datagrams::raw3datatypes;

        switch (_ping_data.get_data_type())
        {
            case t_RAW3DataType::Angle:
                return false;
            case t_RAW3DataType::Power:
                [[fallthrough]];
            case t_RAW3DataType::PowerAndAngle:
                [[fallthrough]];
            case t_RAW3DataType::ComplexFloat16:
                return true;
            case t_RAW3DataType::ComplexFloat32:
                return get_transceiver_information().is_initialized();
            default:
                throw std::runtime_error("Unknown data type");
        }
    }

    bool has_angle() const
    {
        using namespace datagrams::raw3datatypes;

        switch (_ping_data.get_data_type())
        {
            case t_RAW3DataType::Power:
                return false;
            case t_RAW3DataType::Angle:
                [[fallthrough]];
            case t_RAW3DataType::ComplexFloat32:
                [[fallthrough]];
            case t_RAW3DataType::PowerAndAngle:
                [[fallthrough]];
            case t_RAW3DataType::ComplexFloat16:
                return true;
            default:
                throw std::runtime_error("Unknown data type");
        }
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
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base1::__printer__(float_precision, superscript_exponents));
        printer.append(t_base2::__printer__(float_precision, superscript_exponents));

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