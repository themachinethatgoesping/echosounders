// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_pingbottom.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/algorithms/geoprocessing/datastructures/xyz.hpp>
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/hashhelper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../pingtools/beamselection.hpp"
#include "i_pingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

/**
 * @brief Interface for all ping bottom detection functions
 *
 */
class I_PingBottom : public I_PingCommon
{
  protected:
    std::string class_name() const override { return "I_PingBottom"; }

  public:
    using t_base = I_PingCommon;

    std::map<t_pingfeature, std::function<bool()>> primary_feature_functions() const override
    {
        auto features = t_base ::primary_feature_functions();
        features[t_pingfeature::two_way_travel_times] =
            std::bind(&I_PingBottom::has_two_way_travel_times, this);
        features[t_pingfeature::xyz] = std::bind(&I_PingBottom::has_xyz, this);

        // to be implemented
        // features[t_pingfeature::beam_numbers_per_tx_sector] =
        //     std::bind(&I_PingWatercolumn::has_beam_numbers_per_tx_sector, this);
        // features[t_pingfeature::beam_selection_all] =
        //     std::bind(&I_PingWatercolumn::has_beam_selection_all, this);
        // features[t_pingfeature::number_of_beams] =
        //     std::bind(&I_PingWatercolumn::has_number_of_beams, this);
        // features[t_pingfeature::tx_sector_per_beam] =
        //     std::bind(&I_PingWatercolumn::has_tx_sector_per_beam, this);
        // features[t_pingfeature::tx_sector_information] =
        //     std::bind(&I_PingWatercolumn::has_tx_sector_information, this);

        return features;
    }
    std::map<t_pingfeature, std::function<bool()>> secondary_feature_functions() const override

    {
        auto features = t_base ::secondary_feature_functions();
        features[t_pingfeature::tx_signal_parameters] =
            std::bind(&I_PingBottom::has_tx_signal_parameters, this);
        features[t_pingfeature::number_of_tx_sectors] =
            std::bind(&I_PingBottom::has_number_of_tx_sectors, this);
        features[t_pingfeature::beam_crosstrack_angles] =
            std::bind(&I_PingBottom::has_beam_crosstrack_angles, this);
        return features;
    }
    std::map<t_pingfeature, std::function<bool()>> feature_group_functions() const override
    {
        return t_base ::feature_group_functions();
    }

    I_PingBottom()          = default;
    virtual ~I_PingBottom() = default;

    // ----- has feature functions -----
    // sectors and beams features
    virtual bool has_tx_signal_parameters() const { return false; }
    virtual bool has_number_of_tx_sectors() const { return false; }
    virtual bool has_beam_numbers_per_tx_sector() const { return false; }    
    virtual bool has_tx_sector_per_beam() const { return false; }

    // per beam information
    bool         has_beam_selection_all() const { return has_number_of_beams(); }
    virtual bool has_number_of_beams() const { return false; }
    virtual bool has_beam_crosstrack_angles() const { return false; }

    // bottom detection features
    virtual bool has_two_way_travel_times() const { return false; }
    virtual bool has_xyz() const { return false; }

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

    //------ interface / accessors -----
    // std::shared_ptr<T_Ping> get_ping() const { return _ping; }

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
     * @brief Get an XYZ object containing the XYZ position of the bottom detection
     * Note: XYZ is in the local coordinate system of the ping!
     * To convert it use algorithms::geoprocessing::georeferencer class or
     * - Use get_xyz_utm() to get the bottom detection in UTM coordinates
     * - Use get_xyz_latlon() to get the bottom detection in Latitude/Longitude coordinates
     *
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    algorithms::geoprocessing::datastructures::XYZ<1> get_xyz()
    {
        return get_xyz(get_beam_selection_all());
    }

    /**
     * @brief Get an XYZ object containing the XYZ position of the bottom detection
     * Note: XYZ is in the local coordinate system of the ping!
     * To convert it use algorithms::geoprocessing::georeferencer class or
     * - Use get_xyz_utm() to get the bottom detection in UTM coordinates
     * - Use get_xyz_latlon() to get the bottom detection in Latitude/Longitude coordinates
     *
     * @param selection structure with selected transducer_ids/beams/samples considered for this
     * function
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    virtual algorithms::geoprocessing::datastructures::XYZ<1> get_xyz(
        [[maybe_unused]] const pingtools::BeamSelection& selection)
    {
        throw not_implemented(__func__, this->class_name());
    }

    /**
     * @brief Get the two way travel times of the bottom detection samples
     *
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 1> get_two_way_travel_times()
    {
        return get_two_way_travel_times(get_beam_selection_all());
    }

    /**
     * @brief Get the two way travel times of the bottom detection samples
     *
     * @return xt::xtensor<float, 1>
     */
    virtual xt::xtensor<float, 1> get_two_way_travel_times(
        [[maybe_unused]] const pingtools::BeamSelection& selection)
    {
        throw not_implemented(__func__, this->class_name());
    }


  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        // Transducers
        printer.append(I_PingCommon::__printer__(float_precision, superscript_exponents));

        printer.register_section("Bottom detection infos");
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