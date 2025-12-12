// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallpingfiledata.doc.hpp"

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
#include <xtensor/containers/xadapt.hpp>

#include <xtensor/views/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datatypes/calibration/multisectorwatercolumncalibration.hpp"
#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include "../../filetemplates/datatypes/i_ping.hpp"
#include "../../filetemplates/datatypes/i_pingfiledata.hpp"
#include "../../pingtools/beamsampleselection.hpp"
#include "../datagrams.hpp"
#include "../filedatainterfaces/kongsbergalldatagraminterface.hpp"
#include "../filedatatypes/calibration/kongsbergallwatercolumncalibration.hpp"

#include "_sub/systeminformation.hpp"
#include "_sub/watercolumninformation.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {

template<typename t_ifstream>
class KongsbergAllPingFileData
    : public filetemplates::datatypes::I_PingFileData
    , public filedatainterfaces::KongsbergAllDatagramInterface<t_ifstream>
{
    using t_base1 = filetemplates::datatypes::I_PingFileData;
    using t_base2 = filedatainterfaces::KongsbergAllDatagramInterface<t_ifstream>;

    // parameters (read when adding datagram infos)
    std::unique_ptr<boost::flyweight<datagrams::RuntimeParameters>> _runtime_parameters;
    std::unique_ptr<boost::flyweight<calibration::KongsbergAllMultiSectorWaterColumnCalibration>>
        _multisector_calibration;

  private:
    std::unique_ptr<_sub::WaterColumnInformation> _watercolumninformation;
    std::unique_ptr<_sub::SystemInformation>      _systeminformation;

  public:
    void init_watercolumn_calibration(bool force = false)
    {
        if (_multisector_calibration && !force)
            return;

        // const auto& runtime_parameters = get_runtime_parameters();

        // TODO: use sound velocity profile
        auto        sound_velocity = this->get_wcinfos().get_sound_speed_at_transducer();
        const auto& signal_parameters =
            this->get_sysinfos().get_tx_signal_parameters(); // this is a vector that represents the
                                                             // number of sectors
        const auto& absorptions_db_m =
            this->get_sysinfos()
                .get_mean_absorption_coefficient_in_dB_per_m(); // this is a vector that represents
                                                                // the number of sectors
        auto tvg_offset = this->get_wcinfos().get_tvg_offset_in_db();
        auto tvg_factor = this->get_wcinfos().get_tvg_factor_applied();

        std::vector<calibration::KongsbergAllWaterColumnCalibration> calibrations;
        for (size_t sector_nr = 0; sector_nr < signal_parameters.size(); ++sector_nr)
        {
            const auto& signal_param = signal_parameters.at(sector_nr);

            calibrations.push_back(calibration::KongsbergAllWaterColumnCalibration(
                sound_velocity,
                std::visit([](const auto& param) { return param.get_effective_pulse_duration(); },
                           signal_param),
                tvg_offset,
                absorptions_db_m(sector_nr),
                tvg_factor));
        }

        _multisector_calibration = std::make_unique<
            boost::flyweight<calibration::KongsbergAllMultiSectorWaterColumnCalibration>>(
            std::move(calibrations));
    }
    bool has_watercolumn_calibration() const { return bool(_multisector_calibration); }
    const calibration::KongsbergAllMultiSectorWaterColumnCalibration& get_multisector_calibration()
        const
    {
        if (!_multisector_calibration)
            throw std::runtime_error(
                "Error[KongsbergAllPingFileData::get_watercolumn_calibration]: "
                "Calibration not initialized!");

        return _multisector_calibration->get();
    }

    void update_calibration(
        boost::flyweight<calibration::KongsbergAllMultiSectorWaterColumnCalibration> calibration)
    {
        if (calibration.get().get_number_of_sectors() !=
            get_sysinfos().get_tx_signal_parameters().size())
            throw std::runtime_error(
                "Error[KongsbergAllPingFileData::update_calibration]: Calibration size does not "
                "match number of transmit sectors!");

        _multisector_calibration = std::make_unique<
            boost::flyweight<calibration::KongsbergAllMultiSectorWaterColumnCalibration>>(
            calibration);
    }

    void set_multisector_calibration(
        const calibration::KongsbergAllMultiSectorWaterColumnCalibration& multisector_calibration)
    {
        if (multisector_calibration.get_number_of_sectors() !=
            get_sysinfos().get_tx_signal_parameters().size())
            throw std::runtime_error(
                "Error[KongsbergAllPingFileData::set_watercolumn_calibration]: Calibration size "
                "does not match number of transmit sectors!");

        _multisector_calibration = std::make_unique<
            boost::flyweight<calibration::KongsbergAllMultiSectorWaterColumnCalibration>>(
            multisector_calibration);
    }

    const calibration::KongsbergAllWaterColumnCalibration& get_watercolumn_calibration(
        size_t tx_sector) const
    {
        if (!_multisector_calibration)
            throw std::runtime_error(
                "Error[KongsbergAllPingFileData::get_watercolumn_calibration]: "
                "Calibration not initialized!");

        if (get_multisector_calibration().get_number_of_sectors() <= tx_sector)
            throw std::runtime_error(fmt::format(
                "Error[KongsbergAllPingFileData::get_watercolumn_calibration]: Sector {} out of "
                "range",
                tx_sector));

        return get_multisector_calibration().calibration_for_sector(tx_sector);
    }

    const calibration::KongsbergAllWaterColumnCalibration& get_watercolumn_calibration() const
    {
        if (!_multisector_calibration)
            throw std::runtime_error(
                "Error[KongsbergAllPingFileData::get_watercolumn_calibration]: "
                "Calibration not initialized!");

        if (get_multisector_calibration().get_number_of_sectors() != 1)
            throw std::runtime_error("Error[KongsbergAllPingFileData::get_watercolumn_"
                                     "calibration]: Multiple transmit "
                                     "sectors available, but no sector specified!");

        return get_watercolumn_calibration(0);
    }

    void set_watercolumn_calibration(
        const calibration::KongsbergAllWaterColumnCalibration& calibration)
    {
        if (get_sysinfos().get_tx_signal_parameters().size() != 1)
            throw std::runtime_error("Error[KongsbergAllPingFileData::get_watercolumn_"
                                     "calibration]: Multiple transmit "
                                     "sectors available, but only one supplied!");

        _multisector_calibration = std::make_unique<
            boost::flyweight<calibration::KongsbergAllMultiSectorWaterColumnCalibration>>(
            calibration::KongsbergAllMultiSectorWaterColumnCalibration({ calibration }));
    }
    void set_watercolumn_calibration(
        const std::vector<calibration::KongsbergAllWaterColumnCalibration>& calibrations)
    {
        if (get_sysinfos().get_tx_signal_parameters().size() != calibrations.size())
            throw std::runtime_error(fmt::format(
                "Error[KongsbergAllPingFileData::get_watercolumn_calibration]: Calibration size "
                "does not match number of transmit sectors! ({} != {})",
                calibrations.size(),
                get_sysinfos().get_tx_signal_parameters().size()));

        _multisector_calibration = std::make_unique<
            boost::flyweight<calibration::KongsbergAllMultiSectorWaterColumnCalibration>>(
            calibrations);
    }

    void set_watercolumninformation(std::unique_ptr<_sub::WaterColumnInformation> wci)
    {
        _watercolumninformation = std::move(wci);
    }
    void set_systeminformation(std::unique_ptr<_sub::SystemInformation> syi)
    {
        _systeminformation = std::move(syi);
    }

    void load_wci(bool force = false)
    {
        if (wci_loaded() && !force)
            return;

        _watercolumninformation =
            std::make_unique<_sub::WaterColumnInformation>(read_merged_watercolumndatagram(true));
    }
    void load_sys(bool force = false)
    {
        if (sys_loaded() && !force)
            return;

        if (has_datagram_type<datagrams::RawRangeAndAngle>())
        {
            _systeminformation = std::make_unique<_sub::SystemInformation>(
                read_first_datagram<datagrams::RawRangeAndAngle>());
        }
        else if (has_datagram_type<datagrams::WatercolumnDatagram>())
        {
            _systeminformation = std::make_unique<_sub::SystemInformation>(get_wcinfos());
        }
    }
    void release_wci() { _watercolumninformation.reset(); }
    void release_sys() { _systeminformation.reset(); }
    void release_multisector_calibration() { _multisector_calibration.reset(); }
    bool wci_loaded() const { return _watercolumninformation != nullptr; }
    bool sys_loaded() const { return _systeminformation != nullptr; }
    bool multisector_calibration_loaded() const { return _multisector_calibration != nullptr; }

    const _sub::WaterColumnInformation& get_wcinfos()
    {
        load_wci();

        return *_watercolumninformation;
    }

    const _sub::SystemInformation& get_sysinfos()
    {
        load_sys();

        return *_systeminformation;
    }

    const _sub::WaterColumnInformation& get_wcinfos_const() const
    {
        if (!wci_loaded())
            throw std::runtime_error("Error[KongsbergAllPingFileData::get_wcinfos_const]: "
                                     "Watercolumn information not loaded!");

        return *_watercolumninformation;
    }

    const _sub::SystemInformation& get_sysinfos_const() const
    {
        if (!sys_loaded())
            throw std::runtime_error("Error[KongsbergAllPingFileData::get_sysinfos_const]: System "
                                     "information not loaded!");

        return *_systeminformation;
    }

  public:
    bool has_runtime_parameters() const { return bool(_runtime_parameters); }

    void set_runtime_parameters(boost::flyweight<datagrams::RuntimeParameters> arg)
    {
        _runtime_parameters = std::make_unique<boost::flyweight<datagrams::RuntimeParameters>>(arg);
    }
    const datagrams::RuntimeParameters& get_runtime_parameters() const
    {
        if (!_runtime_parameters)
            throw std::runtime_error(
                "Error[KongsbergAllPingFileData::get_runtime_parameters]: No runtime parameters "
                "available!");

        return _runtime_parameters->get();
    }

    bool has_datagram_type(t_KongsbergAllDatagramIdentifier datagram_identifier) const
    {
        return this->_datagram_infos_by_type.at_const(datagram_identifier).size() > 0;
    }

    bool has_any_of_datagram_types(
        const std::vector<t_KongsbergAllDatagramIdentifier>& datagram_identifiers) const
    {
        for (const auto& datagram_identifier : datagram_identifiers)
        {
            if (this->has_datagram_type(datagram_identifier))
                return true;
        }

        return false;
    }

    auto& get_datagram_infos(t_KongsbergAllDatagramIdentifier datagram_identifier)
    {
        auto& datagram_infos = this->_datagram_infos_by_type.at(datagram_identifier);

        return datagram_infos;
    }

    datagrams::WatercolumnDatagram read_merged_watercolumndatagram(bool skip_data = false)
    {
        auto& datagram_infos =
            get_datagram_infos(t_KongsbergAllDatagramIdentifier::WatercolumnDatagram);

        if (datagram_infos.empty())
            throw std::runtime_error(fmt::format(
                "Error[KongsbergAllPingFileData::read_merged_watercolumndatagram]: No {} datagram "
                "in ping!",
                datagram_type_to_string(t_KongsbergAllDatagramIdentifier::WatercolumnDatagram)));

        auto datagram =
            datagram_infos.at(0)->template read_datagram_from_file<datagrams::WatercolumnDatagram>(
                skip_data);

        for (size_t i = 1; i < datagram_infos.size(); ++i)
        {
            datagram.append_from_stream(datagram_infos[i]->get_stream_and_seek());
        }

        return datagram;
    }

  protected:
    // std::shared_ptr<datagrams::xml_datagrams::XML_Parameter_Channel> _ping_parameter;
    std::string class_name() const override { return "KongsbergAllPingFileData"; }

  public:
    KongsbergAllPingFileData()
        : t_base1()
        , t_base2()
    {
    }

    ~KongsbergAllPingFileData() = default;

    KongsbergAllPingFileData(const KongsbergAllPingFileData& other)
        : t_base1(other)
        , t_base2(other)
    {
        _runtime_parameters =
            other._runtime_parameters
                ? std::make_unique<boost::flyweight<datagrams::RuntimeParameters>>(
                      *other._runtime_parameters)
                : nullptr;
        _multisector_calibration =
            other._multisector_calibration
                ? std::make_unique<
                      boost::flyweight<calibration::KongsbergAllMultiSectorWaterColumnCalibration>>(
                      *other._multisector_calibration)
                : nullptr;
        _watercolumninformation =
            other._watercolumninformation
                ? std::make_unique<_sub::WaterColumnInformation>(*other._watercolumninformation)
                : nullptr;
        _systeminformation =
            other._systeminformation
                ? std::make_unique<_sub::SystemInformation>(*other._systeminformation)
                : nullptr;
    }

    /**
     * @brief Return the filestream associated with the first datagram of the specified type
     *
     * @param datagram_identifier
     * @return std::istream&
     */
    auto& get_ifs(t_KongsbergAllDatagramIdentifier datagram_identifier) const
    {
        return this->_datagram_infos_by_type.at_const(datagram_identifier).at(0)->get_stream();
    }

    template<typename t_datagram>
    auto has_datagram_type()
    {
        auto& datagram_infos = this->_datagram_infos_by_type.at(t_datagram::DatagramIdentifier);

        return !datagram_infos.empty();
    }

    template<typename t_datagram>
    auto read_first_datagram()
    {
        auto& datagram_infos = this->_datagram_infos_by_type.at(t_datagram::DatagramIdentifier);

        if (datagram_infos.empty())
            throw std::runtime_error(fmt::format(
                "Error[KongsbergAllPingFileData::read_datagram]: No {} datagram in ping!",
                datagram_identifier_to_string(t_datagram::DatagramIdentifier)));

        return datagram_infos.at(0)->template read_datagram_from_file<t_datagram>();
    }

    // I_PingBottom functions
    /**
     * @brief read XYZ for the bottom detection datagram
     *
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    algorithms::geoprocessing::datastructures::XYZ<1> read_xyz()
    {
        auto datagram = read_first_datagram<datagrams::XYZDatagram>();

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
    algorithms::geoprocessing::datastructures::XYZ<1> read_xyz(const pingtools::BeamSelection& bs)
    {
        auto datagram = read_first_datagram<datagrams::XYZDatagram>();

        return datagram.get_xyz(bs.get_beam_numbers());
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