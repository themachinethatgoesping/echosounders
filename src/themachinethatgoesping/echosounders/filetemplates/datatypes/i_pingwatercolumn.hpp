/**
 * @brief Interface for all ping watercolumn functions
 *
 * This interface provides functions for accessing and manipulating ping watercolumn data.
 * It includes methods for retrieving beam selection, beam angles, sample intervals, amplitudes,
 * and bottom range samples.
 */
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
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
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/hashhelper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../pingtools/beamsampleselection.hpp"
#include "i_pingcommon.hpp"

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
            std::bind(&I_PingWatercolumn::has_tx_sector_information, this);
        features[t_pingfeature::beam_crosstrack_angles] =
            std::bind(&I_PingWatercolumn::has_beam_crosstrack_angles, this);
        features[t_pingfeature::bottom_range_samples] =
            std::bind(&I_PingWatercolumn::has_bottom_range_samples, this);
        features[t_pingfeature::amplitudes] = std::bind(&I_PingWatercolumn::has_amplitudes, this);
        features[t_pingfeature::ap]         = std::bind(&I_PingWatercolumn::has_ap, this);
        features[t_pingfeature::av]         = std::bind(&I_PingWatercolumn::has_av, this);
        features[t_pingfeature::power]      = std::bind(&I_PingWatercolumn::has_power, this);
        features[t_pingfeature::sp]         = std::bind(&I_PingWatercolumn::has_sp, this);
        features[t_pingfeature::sv]         = std::bind(&I_PingWatercolumn::has_sv, this);
        features[t_pingfeature::watercolumn_calibration] =
            std::bind(&I_PingWatercolumn::has_watercolumn_calibration, this);

        return features;
    }
    std::map<t_pingfeature, std::function<bool()>> feature_group_functions() const override
    {
        return t_base ::feature_group_functions();
    }

    I_PingWatercolumn()          = default;
    virtual ~I_PingWatercolumn() = default;

    // --- transmit sector infos ---

    /**
     * @brief Get the transmission signal parameters per sector.
     *
     * @return const std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>&
     */
    virtual std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
    get_tx_signal_parameters()
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
    virtual size_t get_number_of_tx_sectors()
    {
        throw not_implemented(__func__, this->class_name());
    }

    virtual bool has_tx_signal_parameters() const { return false; }
    virtual bool has_tx_sector_information() const { return false; }

    virtual const calibration::WaterColumnCalibration& get_watercolumn_calibration() const
    {
        throw not_implemented(__func__, this->class_name());
    }
    virtual void set_watercolumn_calibration(
        boost::flyweight<calibration::WaterColumnCalibration> calibration)
    {
        throw not_implemented(__func__, this->class_name());
    }

    void set_watercolumn_calibration(const calibration::WaterColumnCalibration& calibration)
    {
        set_watercolumn_calibration(
            boost::flyweight<calibration::WaterColumnCalibration>(calibration));
    }

    // --- water column sampling infos ---

    /**
     * @brief Get the sample interval in seconds
     *
     * @return float
     */
    virtual float get_sample_interval() { throw not_implemented(__func__, class_name()); }

    // --- sector infos ---
    virtual xt::xtensor<size_t, 1> get_tx_sector_per_beam()
    {
        throw not_implemented(__func__, class_name());
    }

    virtual std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector()
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
    virtual uint32_t get_number_of_beams() { throw not_implemented(__func__, class_name()); }

    /**
     * @brief Check this pings supports the extraction of beam_crosstrack_angles
     *
     * @return true
     * @return false
     */
    virtual bool has_beam_crosstrack_angles() const { return false; }

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
    xt::xtensor<float, 2> get_amplitudes()
    {
        return get_amplitudes(get_beam_sample_selection_all());
    }

    /**
     * @brief Get the amplitude data converted to AP (uncalibrated point scattering)
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_ap() { return get_ap(get_beam_sample_selection_all()); }

    /**
     * @brief Get the amplitude data converted to AV (uncalibrated volume scattering)
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_av() { return get_av(get_beam_sample_selection_all()); }

    /**
     * @brief Get the amplitude data converted to power
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_power() { return get_power(get_beam_sample_selection_all()); }

    /**
     * @brief Get the amplitude data converted to SP (calibrated point scattering)
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_sp() { return get_sp(get_beam_sample_selection_all()); }

    /**
     * @brief Get the amplitude data converted to SV (calibrated volume scattering)
     *
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_sv() { return get_sv(get_beam_sample_selection_all()); }

    /**
     * @brief Get tha raw water amplitude data converted to float(32bit)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_amplitudes(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection)
    {
        throw not_implemented(__func__, this->class_name());
    }

    /**
     * @brief Get the amplitude data converted to AP (uncalibrated point scattering)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    xt::xtensor<float, 2> get_ap(const pingtools::BeamSampleSelection& selection)
    {
        return get_watercolumn_calibration().apply_beam_sample_correction_ap(
            get_amplitudes(selection),
            get_beam_crosstrack_angles(selection),
            get_approximate_ranges(selection));
    }

    /**
     * @brief Get the amplitude data converted to AV (uncalibrated volume scattering)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_av(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection)
    {
        return get_watercolumn_calibration().apply_beam_sample_correction_av(
            get_amplitudes(selection),
            get_beam_crosstrack_angles(selection),
            get_approximate_ranges(selection));
    }

    /**
     * @brief Get the amplitude data converted to power
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_power(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection)
    {
        return get_watercolumn_calibration().apply_beam_sample_correction_power(
            get_amplitudes(selection),
            get_beam_crosstrack_angles(selection),
            get_approximate_ranges(selection));
    }

    /**
     * @brief Get the amplitude data converted to SP (calibrated point scattering)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_sp(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection)
    {
        return get_watercolumn_calibration().apply_beam_sample_correction_sp(
            get_amplitudes(selection),
            get_beam_crosstrack_angles(selection),
            get_approximate_ranges(selection));
    }

    /**
     * @brief Get the amplitude data converted to SV (calibrated volume scattering)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xtensor<float, 2> get_sv(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection)
    {
        return get_watercolumn_calibration().apply_beam_sample_correction_sv(
            get_amplitudes(selection),
            get_beam_crosstrack_angles(selection),
            get_approximate_ranges(selection));
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
     * @brief Check this pings supports AMPLITUDES data
     *
     * @return true
     * @return false
     */
    virtual bool has_amplitudes() const { return false; }

    /**
     * @brief Check this pings supports AP data (uncalibrated point scattering)
     *
     * @return true
     * @return false
     */
    bool has_ap() const
    {
        return has_amplitudes() && get_watercolumn_calibration().has_ap_calibration();
    }

    /**
     * @brief Check this pings supports AV data (uncalibrated volume scattering)
     *
     * @return true
     * @return false
     */
    bool has_av() const
    {
        return has_amplitudes() && get_watercolumn_calibration().has_av_calibration();
    }

    /**
     * @brief Check this pings supports calibrated power data
     *
     * @return true
     * @return false
     */
    bool has_power() const
    {
        return has_amplitudes() && get_watercolumn_calibration().has_power_calibration();
    }
    /**
     * @brief Check this pings supports calibrated SV data
     *
     * @return true
     * @return false
     */
    bool has_sp() const
    {
        return has_amplitudes() && get_watercolumn_calibration().has_sp_calibration();
    }
    /**
     * @brief Check this pings supports calibrated SV data
     *
     * @return true
     * @return false
     */
    bool has_sv() const
    {
        return has_amplitudes() && get_watercolumn_calibration().has_sv_calibration();
    }

    /**
     * @brief Check this pings has valid power calibration data
     *
     * @return true
     * @return false
     */
    bool has_watercolumn_calibration() const
    {
        try
        {
            return get_watercolumn_calibration().initialized();
        }
        catch (...)
        {
            return false;
        }
    }

    /**
     * @brief Check this pings supports bottom range samples
     *
     * @return true
     * @return false
     */
    virtual bool has_bottom_range_samples() const { return false; }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

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