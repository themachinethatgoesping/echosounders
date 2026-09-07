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
#include "../../filetemplates/datatypes/i_pingfiledata.hpp"
#include "../datagrams.hpp"
#include "../filedatainterfaces/s7kdatagraminterface.hpp"
#include "calibration/s7kwatercolumncalibration.hpp"

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
    : public filetemplates::datatypes::I_PingFileData
    , public filedatainterfaces::S7KDatagramInterface<t_ifstream>
{
    using t_base1 = filetemplates::datatypes::I_PingFileData;
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

    // deep-copy the lazily cached datagrams / calibration (unique_ptr members are not copyable)
    S7KPingFileData(const S7KPingFileData& other)
        : t_base1(other)
        , t_base2(other)
    {
        _sonar_settings =
            other._sonar_settings
                ? std::make_unique<datagrams::SonarSettings>(*other._sonar_settings)
                : nullptr;
        _raw_detection =
            other._raw_detection
                ? std::make_unique<datagrams::RawDetection>(*other._raw_detection)
                : nullptr;
        _water_column =
            other._water_column
                ? std::make_unique<datagrams::CompressedWaterColumn>(*other._water_column)
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

    /// 7000 SonarSettings of the ping (cached; small fixed record)
    const datagrams::SonarSettings& get_sonar_settings()
    {
        if (!_sonar_settings)
            _sonar_settings = std::make_unique<datagrams::SonarSettings>(
                read_first_datagram<datagrams::SonarSettings>());
        return *_sonar_settings;
    }

    /// 7027 RawDetection of the ping (cached; carries the per-beam receive angles and detections)
    const datagrams::RawDetection& get_raw_detection()
    {
        if (!_raw_detection)
            _raw_detection = std::make_unique<datagrams::RawDetection>(
                read_first_datagram<datagrams::RawDetection>());
        return *_raw_detection;
    }

    /// 7042 CompressedWaterColumn of the ping (loaded on demand, can be released again)
    datagrams::CompressedWaterColumn& get_water_column()
    {
        load_wci();
        return *_water_column;
    }
    void load_wci(bool force = false)
    {
        if (_water_column && !force)
            return;
        _water_column = std::make_unique<datagrams::CompressedWaterColumn>(
            read_first_datagram<datagrams::CompressedWaterColumn>());
    }
    void release_wci() { _water_column.reset(); }
    bool wci_loaded() const { return _water_column != nullptr; }

    // ----- per-beam-number detection values -----
    // The 7027 RawDetection may hold several detections per beam (multi-detect), keyed by the
    // per-row beam_descriptor. These helpers reduce the rows to one value per beam number (the first
    // detection of each beam) so they can be indexed by beam number like the water-column beams.
    /// receive steering angle (degrees) per beam number
    xt::xtensor<float, 1> get_rx_angle_in_degrees_per_beam_number()
    {
        auto angles = detection_value_per_beam_number(
            [](const auto& beams) { return beams.get_rx_angle_in_degrees_tensor(); });

        // the recorded receive angles are quantized and repeat for adjacent (outer) beams; nudge
        // the duplicates so the per-beam angles are strictly increasing (the water-column image
        // interpolator requires strictly ascending beam angles). The drift is < 0.1 deg.
        constexpr float epsilon = 1e-3f;
        for (size_t bn = 1; bn < angles.size(); ++bn)
            if (std::isfinite(angles.unchecked(bn)) && std::isfinite(angles.unchecked(bn - 1)) &&
                angles.unchecked(bn) <= angles.unchecked(bn - 1))
                angles.unchecked(bn) = angles.unchecked(bn - 1) + epsilon;

        return angles;
    }
    /// detected bottom sample number (fractional) per beam number
    xt::xtensor<float, 1> get_detection_point_per_beam_number()
    {
        return detection_value_per_beam_number(
            [](const auto& beams) { return beams.get_detection_point_tensor(); });
    }

    // ----- water column calibration -----
    void init_watercolumn_calibration(bool force = false)
    {
        if (_multisector_calibration && !force)
            return;

        // s7k transmits a single sector per ping (for now), so one calibration is enough. The
        // parameters come from the 7000 SonarSettings; if it is missing (e.g. an incomplete leading
        // ping) the calibration is still built (power works, av does not).
        float sound_velocity   = std::numeric_limits<float>::quiet_NaN();
        float pulse_duration   = std::numeric_limits<float>::quiet_NaN();
        float tvg_factor       = 0.f;                                     // TVG log-factor applied
        float absorption_db_m  = std::numeric_limits<float>::quiet_NaN(); // absorption to (un)apply
        if (has_sonar_settings())
        {
            const auto& sonar_settings = get_sonar_settings();
            sound_velocity             = sonar_settings.get_sound_velocity();
            pulse_duration             = sonar_settings.get_tx_pulse_width();
            // "spreading" is the TVG log-range factor already applied to the recorded data (0/20/40)
            tvg_factor = sonar_settings.get_spreading();
            // 7000 absorption is in dB/km -> dB/m
            absorption_db_m = sonar_settings.get_absorption() * 0.001f;
        }

        // tvg_absorption_db_m (applied) == absorption to apply -> absorption is a no-op change and av
        // only corrects the log-range TVG (20 log r for volume) vs the applied "spreading" factor
        calibration::S7KWaterColumnCalibration cal(sound_velocity,
                                                   pulse_duration,
                                                   0.f, // system gain offset (uncalibrated)
                                                   absorption_db_m,
                                                   tvg_factor);
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
    // reduce the (possibly multi-detect) raw detection rows to one value per beam number
    template<typename t_getter>
    xt::xtensor<float, 1> detection_value_per_beam_number(t_getter&& get_value_tensor)
    {
        const auto& detection_beams = get_raw_detection().get_beams();
        const auto  descriptors     = detection_beams.get_beam_descriptor_tensor();
        const auto  values          = get_value_tensor(detection_beams);

        uint16_t max_beam_number = 0;
        for (size_t row = 0; row < descriptors.size(); ++row)
            max_beam_number = std::max<uint16_t>(max_beam_number, descriptors.unchecked(row));

        auto result = xt::xtensor<float, 1>::from_shape({ size_t(max_beam_number) + 1 });
        result.fill(std::numeric_limits<float>::quiet_NaN());
        for (size_t row = 0; row < descriptors.size(); ++row)
        {
            auto beam_number = descriptors.unchecked(row);
            if (std::isnan(result.unchecked(beam_number))) // keep the first detection of each beam
                result.unchecked(beam_number) = float(values.unchecked(row));
        }
        return result;
    }

    // lazily cached ping datagrams + calibration (deep-copied by the copy constructor)
    std::unique_ptr<datagrams::SonarSettings>         _sonar_settings;
    std::unique_ptr<datagrams::RawDetection>          _raw_detection;
    std::unique_ptr<datagrams::CompressedWaterColumn> _water_column;
    std::unique_ptr<boost::flyweight<calibration::S7KMultiSectorWaterColumnCalibration>>
        _multisector_calibration;
};

} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
