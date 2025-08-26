// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawpingfiledata.doc.hpp"

/* std includes */
#include <memory>
#include <string_view>
#include <vector>

#include <boost/flyweight.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

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
    boost::flyweight<std::pair<datagrams::FIL1, datagrams::FIL1>>     _filter_stages;

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
        , _filter_stages(other._filter_stages)
    {
        _watercolumn_calibration =
            other._watercolumn_calibration
                ? std::make_unique<boost::flyweight<calibration::SimradRawWaterColumnCalibration>>(
                      *other._watercolumn_calibration)
                : nullptr;
    }

    void init_watercolumn_calibration(bool force = false);
    void release_watercolumn_calibration() { _watercolumn_calibration.reset(); }

    bool has_watercolumn_calibration() const { return bool(_watercolumn_calibration); }

    const auto& get_watercolumn_calibration() const
    {
        if (!has_watercolumn_calibration())
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
    size_t get_pulse_duration_index() const;

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

    void set_filter_stages(
        boost::flyweight<std::pair<datagrams::FIL1, datagrams::FIL1>> filter_stages)
    {
        _filter_stages = filter_stages;
    }

    const std::pair<datagrams::FIL1, datagrams::FIL1>& get_filter_stages() const
    {
        return _filter_stages.get();
    }

    const datagrams::RAW3 get_ping_data() const { return _ping_data; }

    // ----- load skipped data -----
    // TODO: add function to only read samples within a specific range
    xt::xtensor<float, 1> read_sample_data(bool dB = false);

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
    bool has_power() const;

    bool has_angle() const;

    // ----- I_PingFileData Interface -----
    std::vector<size_t> get_file_numbers() const final;
    std::string get_primary_file_path() const final;
    std::vector<std::string> get_file_paths() const final;

    void must_have_datagrams(std::string_view method_name) const;

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping