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

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

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
class I_PingBottom : virtual public I_PingCommon
{
  public:
    using t_base = I_PingCommon;
    using t_base::register_feature;

    I_PingBottom()
        : I_PingCommon("I_PingBottom")
    {
        register_feature("beam_crosstrack_angles",
                         std::bind(&I_PingBottom::has_beam_crosstrack_angles, this));
        register_feature("two_way_travel_times",
                         std::bind(&I_PingBottom::has_two_way_travel_times, this));
        register_feature("xyz", std::bind(&I_PingBottom::has_xyz, this));
    }
    virtual ~I_PingBottom() = default;

    // copy constructor
    I_PingBottom(const I_PingBottom& other)
        : I_PingCommon(other)
    {
        register_feature("beam_crosstrack_angles",
                         std::bind(&I_PingBottom::has_beam_crosstrack_angles, this));
        register_feature("two_way_travel_times",
                         std::bind(&I_PingBottom::has_two_way_travel_times, this));
        register_feature("xyz", std::bind(&I_PingBottom::has_xyz, this));
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
     * @return uint16_t
     */
    virtual uint16_t get_number_of_beams() { throw not_implemented(__func__, get_name()); }

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
        throw not_implemented(__func__, get_name());
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
        throw not_implemented(__func__, this->get_name());
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
        throw not_implemented(__func__, this->get_name());
    }

    /**
     * @brief Check this pings supports the extraction of beam_crosstrack_angles
     *
     * @return true
     * @return false
     */
    virtual bool has_beam_crosstrack_angles() const { return false; }

    /**
     * @brief Check this pings supports the extraction of two_way_travel_times
     *
     * @return true
     * @return false
     */
    virtual bool has_two_way_travel_times() const { return false; }

    /**
     * @brief Check this pings supports XYZ data
     *
     * @return true
     * @return false
     */
    virtual bool has_xyz() const { return false; }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // Transducers
        printer.append(I_PingCommon::__printer__(float_precision));

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

  private:
    // make move constructor private (otherwise this has to be implemented similar to the copy
    // constructor)
    I_PingBottom(I_PingBottom&&) = default;
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping