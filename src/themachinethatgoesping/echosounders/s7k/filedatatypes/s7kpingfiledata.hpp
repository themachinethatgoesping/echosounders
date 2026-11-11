// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kpingfiledata.doc.hpp"

/* std includes */
#include <cmath>
#include <limits>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include <boost/flyweight.hpp>
#include <fmt/format.h>

// xtensor includes
#include <xtensor/containers/xtensor.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include <themachinethatgoesping/pingprocessing/datatypes/i_pingfiledata.hpp>
#include "../datagrams.hpp"
#include "../filedatainterfaces/s7kdatagraminterface.hpp"
#include "calibration/s7kwatercolumncalibration.hpp"

#include "_sub/detectioninformation.hpp"
#include "_sub/systeminformation.hpp"
#include "_sub/watercolumninformation.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {

/**
 * @brief Raw file data of a single s7k ping. Holds the datagram index of the ping (via the
 * S7KDatagramInterface base) and provides raw access to the ping's datagrams.
 *
 * @note The datagram-processing functions are not implemented yet. This class currently only
 * provides the structure so it can be filled in in a later step.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KPingFileData
    : public pingprocessing::datatypes::I_PingFileData
    , public filedatainterfaces::S7KDatagramInterface<t_ifstream>
{
    using t_base1 = pingprocessing::datatypes::I_PingFileData;
    using t_base2 = filedatainterfaces::S7KDatagramInterface<t_ifstream>;

  protected:
    std::string class_name() const override { return "S7KPingFileData"; }

  public:
    S7KPingFileData()
        : t_base1()
        , t_base2()
    {
    }
    ~S7KPingFileData() = default;

    // deep-copy the lazily cached information / calibration (unique_ptr members are not copyable)
    S7KPingFileData(const S7KPingFileData& other)
        : t_base1(other)
        , t_base2(other)
    {
        _watercolumninformation =
            other._watercolumninformation
                ? std::make_unique<_sub::WaterColumnInformation>(*other._watercolumninformation)
                : nullptr;
        _detectioninformation =
            other._detectioninformation
                ? std::make_unique<_sub::DetectionInformation>(*other._detectioninformation)
                : nullptr;
        _systeminformation =
            other._systeminformation
                ? std::make_unique<_sub::SystemInformation>(*other._systeminformation)
                : nullptr;
        _multisector_calibration =
            other._multisector_calibration
                ? std::make_unique<
                      boost::flyweight<calibration::S7KMultiSectorWaterColumnCalibration>>(
                      *other._multisector_calibration)
                : nullptr;
    }

    // ----- I_PingFileData interface -----
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

        std::vector<std::string> fps;
        for (const auto& fnr : get_file_numbers())
            fps.push_back(this->_datagram_infos_all.at(0)->file_nr_to_file_path(fnr));

        return fps;
    }

    void must_have_datagrams(std::string_view method_name) const
    {
        if (this->_datagram_infos_all.empty())
            throw std::runtime_error(fmt::format("{}: No datagram in ping!", method_name));
    }

    // ----- ping datagram access -----
    template<typename t_datagram>
    bool has_datagram_type() const
    {
        return !this->get_datagram_infos_by_type(t_datagram::DatagramIdentifier).empty();
    }

    template<typename t_datagram, bool skip_data = false>
    auto read_first_datagram() const
    {
        const auto datagram_infos =
            this->get_datagram_infos_by_type(t_datagram::DatagramIdentifier);

        if (datagram_infos.empty())
            throw std::runtime_error(
                fmt::format("Error[S7KPingFileData::read_first_datagram]: No {} datagram in ping!",
                            std::to_string(uint32_t(t_datagram::DatagramIdentifier))));

        if constexpr (skip_data)
            return datagram_infos.at(0)->template read_datagram_from_file<t_datagram>(skip_data);
        else
            return datagram_infos.at(0)->template read_datagram_from_file<t_datagram>();
    }

    bool has_sonar_settings() const { return has_datagram_type<datagrams::SonarSettings>(); }
    bool has_raw_detection() const { return has_datagram_type<datagrams::RawDetection>(); }
    bool has_water_column() const { return has_datagram_type<datagrams::CompressedWaterColumn>(); }
    bool has_match_filter() const { return has_datagram_type<datagrams::MatchFilter>(); }

    /**
     * @brief Input stream of the first datagram of the given type (for lazy, on-demand reads).
     */
    auto& get_ifs(t_S7KDatagramIdentifier datagram_identifier) const
    {
        return this->get_datagram_infos_by_type(datagram_identifier).at(0)->get_stream();
    }

    // ----- water column information (7042; lazily built, samples read on demand, not stored) -----
    /**
     * @brief Lightweight water-column information (per-beam sample counts + file positions + the
     * record-wide encoding). The water-column samples themselves are NOT loaded here - they are read
     * on demand per beam via S7KPingWatercolumn. Reading metadata therefore no longer pulls the
     * whole 7042 record into memory.
     */
    void load_wci(bool force = false)
    {
        if (wci_loaded() && !force)
            return;
        if (has_water_column())
            _watercolumninformation = std::make_unique<_sub::WaterColumnInformation>(
                read_first_datagram<datagrams::CompressedWaterColumn, true>());
    }
    void release_wci() { _watercolumninformation.reset(); }
    bool wci_loaded() const { return _watercolumninformation != nullptr; }

    void set_watercolumninformation(std::unique_ptr<_sub::WaterColumnInformation> wci)
    {
        _watercolumninformation = std::move(wci);
    }

    const _sub::WaterColumnInformation& get_wcinfos()
    {
        load_wci();
        return *_watercolumninformation;
    }
    const _sub::WaterColumnInformation& get_wcinfos_const() const
    {
        if (!wci_loaded())
            throw std::runtime_error("Error[S7KPingFileData::get_wcinfos_const]: Water column "
                                     "information not loaded!");
        return *_watercolumninformation;
    }

    // ----- detection information (7027; reduced per-beam arrays, full record not retained) -----
    void load_detection(bool force = false)
    {
        if (detection_loaded() && !force)
            return;
        if (has_raw_detection())
            _detectioninformation = std::make_unique<_sub::DetectionInformation>(
                read_first_datagram<datagrams::RawDetection>());
    }
    void release_detection() { _detectioninformation.reset(); }
    bool detection_loaded() const { return _detectioninformation != nullptr; }

    void set_detectioninformation(std::unique_ptr<_sub::DetectionInformation> detection)
    {
        _detectioninformation = std::move(detection);
    }

    const _sub::DetectionInformation& get_detectioninfos()
    {
        load_detection();
        return *_detectioninformation;
    }
    const _sub::DetectionInformation& get_detectioninfos_const() const
    {
        if (!detection_loaded())
            throw std::runtime_error("Error[S7KPingFileData::get_detectioninfos_const]: Detection "
                                     "information not loaded!");
        return *_detectioninformation;
    }

    // ----- system information (7000; tx parameters + calibration inputs, record not retained) -----
    void load_sys(bool force = false)
    {
        if (sys_loaded() && !force)
            return;
        if (has_sonar_settings())
            _systeminformation = std::make_unique<_sub::SystemInformation>(
                read_first_datagram<datagrams::SonarSettings>());
    }
    void release_sys() { _systeminformation.reset(); }
    bool sys_loaded() const { return _systeminformation != nullptr; }

    void set_systeminformation(std::unique_ptr<_sub::SystemInformation> sys)
    {
        _systeminformation = std::move(sys);
    }

    const _sub::SystemInformation& get_sysinfos()
    {
        load_sys();
        return *_systeminformation;
    }
    const _sub::SystemInformation& get_sysinfos_const() const
    {
        if (!sys_loaded())
            throw std::runtime_error("Error[S7KPingFileData::get_sysinfos_const]: System "
                                     "information not loaded!");
        return *_systeminformation;
    }

    // ----- per-beam-number detection values (reduced from the 7027 RawDetection) -----
    /// receive steering angle (degrees) per beam number (nudged strictly increasing)
    const xt::xtensor<float, 1>& get_rx_angle_in_degrees_per_beam_number()
    {
        return get_detectioninfos().get_rx_angle_in_degrees_per_beam_number();
    }
    /// detected bottom sample number (fractional) per beam number
    const xt::xtensor<float, 1>& get_detection_point_per_beam_number()
    {
        return get_detectioninfos().get_detection_point_per_beam_number();
    }

    // ----- water column calibration -----
    void init_watercolumn_calibration(bool force = false)
    {
        if (_multisector_calibration && !force)
            return;

        // s7k transmits a single sector per ping (for now), so one calibration is enough. The
        // parameters come from the 7000 SonarSettings; if it is missing (e.g. an incomplete leading
        // ping) the calibration is still built (power works, av does not).
        float sound_velocity           = std::numeric_limits<float>::quiet_NaN();
        float effective_pulse_duration = std::numeric_limits<float>::quiet_NaN();
        float system_gain_offset       = 0.f; // uncalibrated passthrough if 7000 is missing
        float tvg_factor               = 0.f; // TVG log-factor applied
        float absorption_db_m  = std::numeric_limits<float>::quiet_NaN(); // absorption to (un)apply
        bool  is_fm            = false;                                   // CW unless 7000 says FM
        if (has_sonar_settings())
        {
            const auto& sysinfos = get_sysinfos();
            sound_velocity       = sysinfos.get_sound_velocity();
            is_fm                = sysinfos.is_fm();
            // effective pulse duration: CW -> nominal tx pulse width; FM (chirp) -> matched-filter
            // compressed duration (~ 1 / bandwidth), because the water column is the compressed
            // envelope and the ensonified volume scales with the compressed, not the transmit, pulse
            effective_pulse_duration = sysinfos.get_effective_pulse_duration();
            // system gain offset = source level (power selection) + receiver gain (gain selection).
            // This removes the per-ping power/gain settings; the remaining fixed calibration constant
            // (beam pattern, equivalent beam angle, electronics) still has to be added for a true Sv.
            system_gain_offset = sysinfos.get_system_gain_offset();
            // "spreading" is the TVG log-range factor already applied to the recorded data (0/20/40)
            tvg_factor = sysinfos.get_tvg_factor();
            // 7000 absorption is in dB/km -> dB/m (converted inside SystemInformation)
            absorption_db_m = sysinfos.get_absorption_db_m();

            // If a 7002 MatchFilter record is present it carries the authoritative effective pulse
            // width (it accounts for the pulse shape and the FM match-filter compression), so prefer
            // it over the 1/bandwidth approximation. 7k sonar source <= 5.9.0.1 does not compute it
            // and writes a large negative placeholder, so only use finite positive values.
            if (has_match_filter())
            {
                const float mf_effective_pulse_width =
                    read_first_datagram<datagrams::MatchFilter>().get_effective_pulse_width();
                if (std::isfinite(mf_effective_pulse_width) && mf_effective_pulse_width > 0.f)
                    effective_pulse_duration = mf_effective_pulse_width;
            }
        }

        // tvg_absorption_db_m (applied) == absorption to apply -> absorption is a no-op change and av
        // only corrects the log-range TVG (20 log r for volume) vs the applied "spreading" factor
        calibration::S7KWaterColumnCalibration cal(sound_velocity,
                                                   effective_pulse_duration,
                                                   system_gain_offset,
                                                   absorption_db_m,
                                                   tvg_factor,
                                                   is_fm);
        cal.set_absorption_db_m(absorption_db_m); // makes av/sv available (has_valid_absorption_db_m)

        std::vector<calibration::S7KWaterColumnCalibration> calibrations;
        calibrations.push_back(std::move(cal));

        _multisector_calibration =
            std::make_unique<boost::flyweight<calibration::S7KMultiSectorWaterColumnCalibration>>(
                std::move(calibrations));
    }
    bool has_watercolumn_calibration() const { return bool(_multisector_calibration); }
    const calibration::S7KMultiSectorWaterColumnCalibration& get_multisector_calibration() const
    {
        if (!_multisector_calibration)
            throw std::runtime_error("Error[S7KPingFileData::get_multisector_calibration]: "
                                     "Calibration not initialized!");
        return _multisector_calibration->get();
    }

    const calibration::S7KWaterColumnCalibration& get_watercolumn_calibration(size_t tx_sector) const
    {
        if (get_multisector_calibration().get_number_of_sectors() <= tx_sector)
            throw std::runtime_error(fmt::format(
                "Error[S7KPingFileData::get_watercolumn_calibration]: Sector {} out of range",
                tx_sector));

        return get_multisector_calibration().calibration_for_sector(tx_sector);
    }

    const calibration::S7KWaterColumnCalibration& get_watercolumn_calibration() const
    {
        if (get_multisector_calibration().get_number_of_sectors() != 1)
            throw std::runtime_error("Error[S7KPingFileData::get_watercolumn_calibration]: "
                                     "Multiple transmit sectors available, but no sector "
                                     "specified!");

        return get_watercolumn_calibration(0);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base1::__printer__(float_precision, superscript_exponents));
        printer.append(t_base2::__printer__(float_precision, superscript_exponents));

        return printer;
    }

    // -- class helper function macros --
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    // lazily built, lightweight per-ping information + calibration (deep-copied by the copy
    // constructor). None of these hold the water-column samples - those are read on demand.
    std::unique_ptr<_sub::WaterColumnInformation> _watercolumninformation;
    std::unique_ptr<_sub::DetectionInformation>   _detectioninformation;
    std::unique_ptr<_sub::SystemInformation>      _systeminformation;
    std::unique_ptr<boost::flyweight<calibration::S7KMultiSectorWaterColumnCalibration>>
        _multisector_calibration;
};

} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
