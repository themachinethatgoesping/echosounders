/**
 * @brief Interface for all ping watercolumn functions
 *
 * This interface provides functions for accessing and manipulating ping watercolumn data.
 * It includes methods for retrieving beam selection, beam angles, sample intervals, amplitudes,
 * and bottom range samples.
 */
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_pingwatercolumn.doc.hpp"

/* generated doc strings */
#include ".docstrings/i_pingwatercolumn.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>

#include <boost/flyweight.hpp>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>




#include "../../pingtools/beamsampleselection.hpp"
#include "i_pingcommon.hpp"

#include "calibration/multisectorwatercolumncalibration.hpp"
#include "calibration/watercolumncalibration.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

/**
 * @brief Interface for all ping watercolumn functions
 *
 */
/**
 * @class I_PingWatercolumn
 * @brief Interface for watercolumn ping data.
 *
 * This class represents an interface for accessing watercolumn ping data. It inherits from the
 * I_PingCommon class and provides additional functions and variables specific to watercolumn pings.
 */
class I_PingWatercolumn : public I_PingCommon
{
    bool _beam_sample_selection_all_is_initialized = false;
    boost::flyweight<pingtools::BeamSampleSelection> _beam_sample_selection_all;

  protected:
    std::string class_name() const override { return "I_PingWatercolumn"; }

  public:
    using t_base = I_PingCommon;

    std::map<t_pingfeature, std::function<bool()>> primary_feature_functions() const override
    {
        auto features                       = t_base ::primary_feature_functions();
        features[t_pingfeature::amplitudes] = std::bind(&I_PingWatercolumn::has_amplitudes, this);

        return features;
    }
    std::map<t_pingfeature, std::function<bool()>> secondary_feature_functions() const override
    {
        auto features = t_base ::secondary_feature_functions();
        features[t_pingfeature::tx_signal_parameters] =
            std::bind(&I_PingWatercolumn::has_tx_signal_parameters, this);
        features[t_pingfeature::number_of_tx_sectors] =
            std::bind(&I_PingWatercolumn::has_number_of_tx_sectors, this);
        features[t_pingfeature::beam_numbers_per_tx_sector] =
            std::bind(&I_PingWatercolumn::has_beam_numbers_per_tx_sector, this);
        features[t_pingfeature::beam_selection_all] =
            std::bind(&I_PingWatercolumn::has_beam_selection_all, this);
        features[t_pingfeature::number_of_beams] =
            std::bind(&I_PingWatercolumn::has_number_of_beams, this);
        features[t_pingfeature::tx_sector_per_beam] =
            std::bind(&I_PingWatercolumn::has_tx_sector_per_beam, this);

        features[t_pingfeature::beam_crosstrack_angles] =
            std::bind(&I_PingWatercolumn::has_beam_crosstrack_angles, this);
        features[t_pingfeature::bottom_range_samples] =
            std::bind(&I_PingWatercolumn::has_bottom_range_samples, this);
        features[t_pingfeature::amplitudes] = std::bind(&I_PingWatercolumn::has_amplitudes, this);
        features[t_pingfeature::ap]         = std::bind(&I_PingWatercolumn::has_ap, this);
        features[t_pingfeature::av]         = std::bind(&I_PingWatercolumn::has_av, this);
        features[t_pingfeature::power]      = std::bind(&I_PingWatercolumn::has_power, this);
        features[t_pingfeature::rp]         = std::bind(&I_PingWatercolumn::has_rp, this);
        features[t_pingfeature::rv]         = std::bind(&I_PingWatercolumn::has_rv, this);
        features[t_pingfeature::pp]         = std::bind(&I_PingWatercolumn::has_pp, this);
        features[t_pingfeature::pv]         = std::bind(&I_PingWatercolumn::has_pv, this);
        features[t_pingfeature::sp]         = std::bind(&I_PingWatercolumn::has_sp, this);
        features[t_pingfeature::sv]         = std::bind(&I_PingWatercolumn::has_sv, this);
        features[t_pingfeature::watercolumn_calibration] =
            std::bind(&I_PingWatercolumn::has_watercolumn_calibration, this);
        features[t_pingfeature::multisectorwatercolumn_calibration] =
            std::bind(&I_PingWatercolumn::has_multisectorwatercolumn_calibration, this);

        return features;
    }
    std::map<t_pingfeature, std::function<bool()>> feature_group_functions() const override
    {
        return t_base ::feature_group_functions();
    }

    I_PingWatercolumn()          = default;
    virtual ~I_PingWatercolumn() = default;

    // --- has functions ---
    // sectors and beams features
    virtual bool has_tx_signal_parameters() const { return false; }
    virtual bool has_number_of_tx_sectors() const { return false; }
    virtual bool has_beam_numbers_per_tx_sector() const { return false; }
    virtual bool has_tx_sector_per_beam() const { return false; }

    // per beam information
    bool         has_beam_selection_all() const { return has_number_of_beams(); }
    virtual bool has_number_of_beams() const { return false; }
    virtual bool has_beam_crosstrack_angles() const { return false; }

    // water column calibration features
    ///@brief Check this pings has valid power calibration data
    virtual bool has_watercolumn_calibration() const { return false; }

    ///@brief Check this pings has valid power calibration data
    virtual bool has_multisectorwatercolumn_calibration() const { return false; }

    ///@brief Check this pings supports bottom range samples
    virtual bool has_bottom_range_samples() const { return false; }

    // water column amplitude features
    virtual bool has_amplitudes() const { return false; }

    ///@brief Check this pings supports AP data (uncalibrated point scattering)
    bool has_ap() const
    {
        if (get_number_of_tx_sectors() == 1)
            return has_amplitudes() && get_watercolumn_calibration().has_ap_calibration() &&
                   get_watercolumn_calibration().has_valid_absorption_db_m();

        return has_amplitudes() && get_multisectorwatercolumn_calibration().has_ap_calibration() &&
               get_multisectorwatercolumn_calibration().has_valid_absorption_db_m();
    }

    ///@brief Check this pings supports AV data (uncalibrated volume scattering)
    bool has_av() const
    {
        if (get_number_of_tx_sectors() == 1)
            return has_amplitudes() && get_watercolumn_calibration().has_av_calibration() &&
                   get_watercolumn_calibration().has_valid_absorption_db_m();

        return has_amplitudes() && get_multisectorwatercolumn_calibration().has_av_calibration() &&
               get_multisectorwatercolumn_calibration().has_valid_absorption_db_m();
    }

    ///@brief Check this pings supports calibrated power data
    bool has_power() const
    {
        if (get_number_of_tx_sectors() == 1)
            return has_amplitudes() && get_watercolumn_calibration().has_power_calibration();

        return has_amplitudes() && get_multisectorwatercolumn_calibration().has_power_calibration();
    }

    ///@brief Check this pings supports RP data
    bool has_rp() const { return has_power(); }

    ///@brief Check this pings supports RV data
    bool has_rv() const { return has_power(); }

    ///@brief Check this pings supports PP data
    bool has_pp() const
    {
        if (get_number_of_tx_sectors() == 1)
            return has_amplitudes() && get_watercolumn_calibration().has_power_calibration() &&
                   get_watercolumn_calibration().has_valid_absorption_db_m();

        return has_amplitudes() &&
               get_multisectorwatercolumn_calibration().has_power_calibration() &&
               get_multisectorwatercolumn_calibration().has_valid_absorption_db_m();
    }
    ///@brief Check this pings supports PV data
    bool has_pv() const { return has_pp(); }
    ///@brief Check this pings supports calibrated SV data
    bool has_sp() const
    {
        if (get_number_of_tx_sectors() == 1)
            return has_amplitudes() && get_watercolumn_calibration().has_sp_calibration() &&
                   get_watercolumn_calibration().has_valid_absorption_db_m();

        return has_amplitudes() && get_multisectorwatercolumn_calibration().has_sp_calibration() &&
               get_multisectorwatercolumn_calibration().has_valid_absorption_db_m();
    }
    ///@brief Check this pings supports calibrated SV data
    bool has_sv() const
    {
        if (get_number_of_tx_sectors() == 1)
            return has_amplitudes() && get_watercolumn_calibration().has_sv_calibration() &&
                   get_watercolumn_calibration().has_valid_absorption_db_m();

        return has_amplitudes() && get_multisectorwatercolumn_calibration().has_sv_calibration() &&
               get_multisectorwatercolumn_calibration().has_valid_absorption_db_m();
    }

    // --- transmit sector infos ---

    /**
     * @brief Get the transmission signal parameters per sector.
     *
     * @return const std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>&
     */
    virtual std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
    get_tx_signal_parameters() const
    {
        throw not_implemented(__func__, this->class_name());
    }

    /**
     * @brief Get the number of transmission sectors.
     *
     * This function returns the number of transmission sectors for the echosounder.
     *
     * @return The number of transmission sectors.
     */
    virtual size_t get_number_of_tx_sectors() const
    {
        throw not_implemented(__func__, this->class_name());
    }

    virtual const calibration::WaterColumnCalibration& get_watercolumn_calibration() const
    {
        throw not_implemented(__func__, this->class_name());
    }

    const calibration::WaterColumnCalibration& get_watercolumn_calibration(size_t sector_nr) const
    {
        if (get_number_of_tx_sectors() == 1)
            if (sector_nr == 0)
                return get_watercolumn_calibration();

        if (get_multisectorwatercolumn_calibration().get_number_of_sectors() <= sector_nr)
            throw std::runtime_error(fmt::format("Error[{}]: Sector {} out of "
                                                 "range",
                                                 __func__,
                                                 sector_nr));

        return get_multisectorwatercolumn_calibration().calibration_for_sector(sector_nr);
    }

    virtual const calibration::I_MultiSectorCalibration& get_multisectorwatercolumn_calibration()
        const
    {
        throw not_implemented(__func__, this->class_name());
    }

    // --- water column sampling infos ---

    /**
     * @brief Get the sample interval in seconds
     *
     * @return float
     */
    virtual float get_sample_interval() { throw not_implemented(__func__, class_name()); }

    // --- sector infos ---
    xt::xtensor<size_t, 1> get_tx_sector_per_beam()
    {
        return get_tx_sector_per_beam(get_beam_selection_all());
    }

    virtual xt::xtensor<size_t, 1> get_tx_sector_per_beam(
        [[maybe_unused]] const pingtools::BeamSelection& bs)
    {
        throw not_implemented(__func__, class_name());
    }

    std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector()
    {
        return get_beam_numbers_per_tx_sector(get_beam_selection_all());
    }

    virtual std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector(
        [[maybe_unused]] const pingtools::BeamSelection& bs)
    {
        throw not_implemented(__func__, class_name());
    }

    // ---  common variable access ---

    // --- common functions for all ping types ---
    /**
     * @brief Get a beam selection object that selects all beams
     *
     * @return pingtools::BeamSelection
     */
    pingtools::BeamSelection get_beam_selection_all()
    {
        return pingtools::BeamSelection(get_number_of_beams());
    }

    /**
     * @brief Get the number of beams for this ping
     *
     * @return uint32_t
     */
    virtual uint32_t get_number_of_beams() const { throw not_implemented(__func__, class_name()); }

    /**
     * @brief Get the beam crosstrack angles for this ping in °
     *
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 1> get_beam_crosstrack_angles()
    {
        return get_beam_crosstrack_angles(get_beam_selection_all());
    }

    /**
     * @brief Get the beam crosstrack angles for this ping in °
     *
     * @return xt::xtensor<float, 1>
     */
    virtual xt::xtensor<float, 1> get_beam_crosstrack_angles(
        [[maybe_unused]] const pingtools::BeamSelection& bs)
    {
        throw not_implemented(__func__, class_name());
    }

    /**
     * @brief Get the beam alongtrack angles for this ping in °
     *
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 1> get_beam_alongtrack_angles()
    {
        return get_beam_alongtrack_angles(get_beam_selection_all());
    }

    /**
     * @brief Get the beam alongtrack angles for this ping in °
     *
     * @return xt::xtensor<float, 1>
     */
    virtual xt::xtensor<float, 1> get_beam_alongtrack_angles(
        [[maybe_unused]] const pingtools::BeamSelection& bs)
    {
        throw not_implemented(__func__, class_name());
    }

    virtual xt::xtensor<uint32_t, 1> get_first_sample_offset_per_beam()
    {
        throw not_implemented(__func__, class_name());
    }

    xt::xtensor<uint32_t, 1> get_number_of_samples_per_beam()
    {
        return get_number_of_samples_per_beam(get_beam_selection_all());
    }
    virtual xt::xtensor<uint32_t, 1> get_number_of_samples_per_beam(
        [[maybe_unused]] const pingtools::BeamSelection& bs)
    {
        throw not_implemented(__func__, class_name());
    }

    virtual float get_sound_speed_at_transducer() { throw not_implemented(__func__, class_name()); }

    xt::xtensor<float, 1> get_approximate_ranges(const pingtools::BeamSampleSelection& selection)
    {
        return algorithms::amplitudecorrection::functions::approximate_ranges<
            xt::xtensor<float, 1>>(get_sample_interval(),
                                   get_sound_speed_at_transducer(),
                                   selection.get_sample_numbers_ensemble_1d());
    }

    xt::xtensor<float, 1> get_approximate_ranges()
    {
        return get_approximate_ranges(get_beam_sample_selection_all());
    }

    /**
     * @brief Get beam sample selection that selects all beams and samples
     *
     * @return pingtools::BeamSampleSelection
     */
    const pingtools::BeamSampleSelection& get_beam_sample_selection_all()
    {
        if (!_beam_sample_selection_all_is_initialized)
        {
            auto first_sample_offsets = get_first_sample_offset_per_beam();
            auto number_of_samples    = get_number_of_samples_per_beam();

            // build BeamSampleSelection
            auto last_sample_number_per_beam = first_sample_offsets + number_of_samples - 1;

            std::vector<uint32_t> first_snpb(first_sample_offsets.begin(),
                                             first_sample_offsets.end());
            std::vector<uint32_t> last_snpb(last_sample_number_per_beam.begin(),
                                            last_sample_number_per_beam.end());

            _beam_sample_selection_all =
                pingtools::BeamSampleSelection(std::move(first_snpb), std::move(last_snpb));
            _beam_sample_selection_all_is_initialized = true;
        }

        return _beam_sample_selection_all;
    }

    //------ interface / accessors -----
    /**
     * @brief Get tha raw water amplitude data converted to float(32bit)
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_amplitudes(int mp_cores = 1)
    {
        return get_amplitudes(get_beam_sample_selection_all(), mp_cores);
    }

    /**
     * @brief Get the amplitude data converted to AP (uncalibrated point scattering)
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_ap(int mp_cores = 1)
    {
        return get_ap(get_beam_sample_selection_all(), mp_cores);
    }

    /**
     * @brief Get the amplitude data converted to AV (uncalibrated volume scattering)
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_av(int mp_cores = 1)
    {
        return get_av(get_beam_sample_selection_all(), mp_cores);
    }

    /**
     * @brief Get the power data converted to RP (power 40log(R))
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_rp(int mp_cores = 1)
    {
        return get_rp(get_beam_sample_selection_all(), mp_cores);
    }

    /**
     * @brief Get the power data converted to RV (power 20log(R))
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_rv(int mp_cores = 1)
    {
        return get_rv(get_beam_sample_selection_all(), mp_cores);
    }

    /**
     * @brief Get the power data converted to PP (power +2 alpha R + 40log(R))
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_pp(int mp_cores = 1)
    {
        return get_pp(get_beam_sample_selection_all(), mp_cores);
    }

    /**
     * @brief Get the power data converted to PV (power +2 alpha R + 20log(R))
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_pv(int mp_cores = 1)
    {
        return get_pv(get_beam_sample_selection_all(), mp_cores);
    }

    /**
     * @brief Get the amplitude data converted to power
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_power(int mp_cores = 1)
    {
        return get_power(get_beam_sample_selection_all(), mp_cores);
    }

    /**
     * @brief Get the amplitude data converted to SP (calibrated point scattering)
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_sp(int mp_cores = 1)
    {
        return get_sp(get_beam_sample_selection_all(), mp_cores);
    }

    /**
     * @brief Get the amplitude data converted to SV (calibrated volume scattering)
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_sv(int mp_cores = 1)
    {
        return get_sv(get_beam_sample_selection_all(), mp_cores);
    }

    /**
     * @brief Get tha raw water amplitude data converted to float(32bit)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_amplitudes(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection,
        [[maybe_unused]] int                                   mp_cores = 1)
    {
        throw not_implemented(__func__, this->class_name());
    }

    /**
     * @brief Get the power data converted to RP (power + 40log(R))
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_rp(const pingtools::BeamSampleSelection& selection, int mp_cores = 1)
    {
        using t_calibration_type = typename calibration::WaterColumnCalibration::t_calibration_type;
        return this->template get_calibrated_wci<t_calibration_type::rp>(selection, mp_cores);
    }

    /**
     * @brief Get the power data converted to RV (power + 20log(R))
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_rv(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection,
        int                                                    mp_cores = 1)
    {
        using t_calibration_type = typename calibration::WaterColumnCalibration::t_calibration_type;
        return this->template get_calibrated_wci<t_calibration_type::rv>(selection, mp_cores);
    }

    /**
     * @brief Get the power data converted to PP (power +2 alpha R + 40log(R))
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_pp(const pingtools::BeamSampleSelection& selection, int mp_cores = 1)
    {
        using t_calibration_type = typename calibration::WaterColumnCalibration::t_calibration_type;
        return this->template get_calibrated_wci<t_calibration_type::pp>(selection, mp_cores);
    }

    /**
     * @brief Get the power data converted to PV (power +2 alpha R + 20log(R))
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_pv(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection,
        int                                                    mp_cores = 1)
    {
        using t_calibration_type = typename calibration::WaterColumnCalibration::t_calibration_type;
        return this->template get_calibrated_wci<t_calibration_type::pv>(selection, mp_cores);
    }

    /**
     * @brief Get the amplitude data converted to AP (uncalibrated point scattering)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_ap(const pingtools::BeamSampleSelection& selection, int mp_cores = 1)
    {
        using t_calibration_type = typename calibration::WaterColumnCalibration::t_calibration_type;
        return this->template get_calibrated_wci<t_calibration_type::ap>(selection, mp_cores);
    }

    /**
     * @brief Get the amplitude data converted to AV (uncalibrated volume scattering)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_av(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection,
        int                                                    mp_cores = 1)
    {
        using t_calibration_type = typename calibration::WaterColumnCalibration::t_calibration_type;
        return this->template get_calibrated_wci<t_calibration_type::av>(selection, mp_cores);
    }

    /**
     * @brief Get the amplitude data converted to power
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_power(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection,
        int                                                    mp_cores = 1)
    {
        using t_calibration_type = typename calibration::WaterColumnCalibration::t_calibration_type;
        return this->template get_calibrated_wci<t_calibration_type::power>(selection, mp_cores);
    }

    /**
     * @brief Get the amplitude data converted to SP (calibrated point scattering)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_sp(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection,
        int                                                    mp_cores = 1)
    {
        using t_calibration_type = typename calibration::WaterColumnCalibration::t_calibration_type;
        return this->template get_calibrated_wci<t_calibration_type::sp>(selection, mp_cores);
    }

    /**
     * @brief Get the amplitude data converted to SV (calibrated volume scattering)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_sv(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection,
        int                                                    mp_cores = 1)
    {
        using t_calibration_type = typename calibration::WaterColumnCalibration::t_calibration_type;
        return this->template get_calibrated_wci<t_calibration_type::sv>(selection, mp_cores);
    }

    int  _test_mode = 0;
    void set_test_mode(int test_test_mode) { this->_test_mode = test_test_mode; }
    int  get_test_mode() { return this->_test_mode; }

    /**
     * @brief Get the amplitude data converted to AP (uncalibrated point scattering)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    template<calibration::WaterColumnCalibration::t_calibration_type calibration_type>
    xt::xtensor<float, 2> get_calibrated_wci(const pingtools::BeamSampleSelection& selection,
                                             int                                   mp_cores = 1)
    {
        if (this->get_number_of_tx_sectors() == 1)
            switch (_test_mode)
            {
                case 1: {
                    auto amp = get_amplitudes(selection);
                    get_watercolumn_calibration()
                        .template inplace_beam_sample_correction<calibration_type>(
                            amp,
                            get_beam_crosstrack_angles(selection),
                            get_approximate_ranges(selection),
                            mp_cores);
                    return amp;
                }
                default:
                    return get_watercolumn_calibration()
                        .template apply_beam_sample_correction<calibration_type>(
                            get_amplitudes(selection),
                            get_beam_crosstrack_angles(selection),
                            get_approximate_ranges(selection),
                            mp_cores);
            }

        switch (_test_mode)
        {
            case 1:
                return get_multisectorwatercolumn_calibration()
                    .template apply_beam_sample_correction<calibration_type>(
                        get_amplitudes(selection),
                        get_beam_crosstrack_angles(selection),
                        get_approximate_ranges(selection),
                        get_beam_numbers_per_tx_sector(selection),
                        mp_cores);
            case 2:
                return get_watercolumn_calibration(0)
                    .template apply_beam_sample_correction<calibration_type>(
                        get_amplitudes(selection),
                        get_beam_crosstrack_angles(selection),
                        get_approximate_ranges(selection),
                        mp_cores);
            case 3: {
                auto amp = get_amplitudes(selection);
                get_watercolumn_calibration(0)
                    .template inplace_beam_sample_correction<calibration_type>(
                        amp,
                        get_beam_crosstrack_angles(selection),
                        get_approximate_ranges(selection),
                        mp_cores);
                return amp;
            }
            default: {
                auto amp = get_amplitudes(selection);
                get_multisectorwatercolumn_calibration()
                    .template inplace_beam_sample_correction<calibration_type>(
                        amp,
                        get_beam_crosstrack_angles(selection),
                        get_approximate_ranges(selection),
                        get_beam_numbers_per_tx_sector(selection),
                        mp_cores);
                return amp;
            }
        }
    }

    /**
     * @brief Get the sample number of the bottom detection for each beam
     *
     * @return xt::xtensor<uint32_t, 1>
     */
    virtual xt::xtensor<uint32_t, 1> get_bottom_range_samples()
    {
        return get_bottom_range_samples(get_beam_selection_all());
    }

    /**
     * @brief Get the sample number of the bottom detection for each selected beam
     *
     * @param selection Selection of Beams to extract
     * @return xt::xtensor<uint32_t, 1>
     */
    virtual xt::xtensor<uint32_t, 1> get_bottom_range_samples(
        [[maybe_unused]] const pingtools::BeamSelection& selection)
    {
        throw not_implemented(__func__, this->class_name());
    }

    /**
     * @brief Computes the minimum slant sample number from all beams.
     *
     * This function calculates the minimum slant sample number by first obtaining the bottom range samples
     * from the provided beam selection. It then filters out outliers using the Interquartile Range (IQR) method
     * and returns the smallest valid sample number.
     *
     * @return The minimum slant sample number.
     * @throws std::runtime_error If no valid bottom range sample is found.
     */
    uint32_t get_minslant_sample_nr() { return get_minslant_sample_nr(get_beam_selection_all()); }

    /**
     * @brief Computes the minimum slant sample number from the given beam selection.
     *
     * This function calculates the minimum slant sample number by first obtaining the bottom range samples
     * from the provided beam selection. It then filters out outliers using the Interquartile Range (IQR) method
     * and returns the smallest valid sample number.
     *
     * @param selection The beam selection from which to obtain the bottom range samples.
     * @return The minimum slant sample number.
     * @throws std::runtime_error If no valid bottom range sample is found.
     */
    uint32_t get_minslant_sample_nr(const pingtools::BeamSelection& selection)
    {
        auto bottom_range_samples = get_bottom_range_samples(selection);

        if (bottom_range_samples.size() == 0)
            throw std::runtime_error(
                fmt::format("Error[{}]: No valid bottom range sample found", __func__));

        if (bottom_range_samples.size() == 1)
            return bottom_range_samples[0];

        // convert to std::vector
        std::vector<uint32_t> bottom_range_samples_vec(bottom_range_samples.begin(),
                                                       bottom_range_samples.end());

        // outlier filtering
        // compute IQR median using nth_element
        auto median_it = bottom_range_samples_vec.begin() + bottom_range_samples_vec.size() / 2;
        std::nth_element(
            bottom_range_samples_vec.begin(), median_it, bottom_range_samples_vec.end());
        auto median = *median_it;

        // compute IQR
        auto q3_it = bottom_range_samples_vec.begin() + 3 * bottom_range_samples_vec.size() / 4;
        std::nth_element(median_it, q3_it, bottom_range_samples_vec.end());
        auto q3 = *q3_it;

        auto q1_it = bottom_range_samples_vec.begin() + bottom_range_samples_vec.size() / 4;
        std::nth_element(bottom_range_samples_vec.begin(), q1_it, median_it);
        auto q1      = *q1_it;
        auto min_iqr = median - (q3 - q1) * 1.5;

        // sort the elements till q1 (because the minval should be )
        std::sort(bottom_range_samples_vec.begin(), q1_it);
        uint32_t minslant_sample_nr = std::numeric_limits<uint32_t>::max();
        // find the first element that is not an outlier
        for (auto it = bottom_range_samples_vec.begin(); it != bottom_range_samples_vec.end(); ++it)
            if (*it > min_iqr && *it < minslant_sample_nr)
                minslant_sample_nr = *it;

        if (minslant_sample_nr == std::numeric_limits<uint32_t>::max())
            throw std::runtime_error(
                fmt::format("Error[{}]: No valid bottom range sample found", __func__));

        return minslant_sample_nr;
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        // Transducers
        printer.append(I_PingCommon::__printer__(float_precision, superscript_exponents));

        printer.register_section("Watercolumn detection infos");
        auto features     = this->feature_string();
        auto not_features = this->feature_string(false);
        if (!not_features.empty())
            printer.register_string("Features", features, std::string("Not:") + not_features);
        else
            printer.register_string("Features", features);

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