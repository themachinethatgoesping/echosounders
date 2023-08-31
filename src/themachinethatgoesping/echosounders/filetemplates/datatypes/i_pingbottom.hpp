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

#include "../../pingtools/beamsampleselection.hpp"
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
        register_feature("two_way_travel_times", [this]() { return this->has_two_way_travel_times(); });
        register_feature("xyz", [this]() { return this->has_xyz(); });
    }
    virtual ~I_PingBottom() = default;

    //------ interface / accessors -----
    // std::shared_ptr<T_Ping> get_ping() const { return _ping; }

    /**
     * @brief Get an XYZ object containing the XYZ position of the bottom detection
     * Note: XYZ is in the local coordinate system of the ping!
     * To convert it use algorithms::geoprocessing::georeferencer class or
     * - Use get_xyz_utm() to get the bottom detection in UTM coordinates
     * - Use get_xyz_latlon() to get the bottom detection in Latitude/Longitude coordinates
     *
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    virtual algorithms::geoprocessing::datastructures::XYZ<1> get_xyz() const
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
     * @param selection structure with selected transducer_ids/beams/samples considered for this
     * function
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    virtual algorithms::geoprocessing::datastructures::XYZ<1> get_xyz(
        [[maybe_unused]] const pingtools::BeamSelection& selection) const
    {
        throw not_implemented(__func__, this->get_name());
    }

    /**
     * @brief Get the two way travel times of the bottom detection samples
     *
     * @return xt::xtensor<float, 1>
     */
    virtual xt::xtensor<float, 1> get_two_way_travel_times() const
    {
        throw not_implemented(__func__, this->get_name());
    }

    /**
     * @brief Get the two way travel times of the bottom detection samples
     *
     * @return xt::xtensor<float, 1>
     */
    virtual xt::xtensor<float, 1> get_two_way_travel_times(
        [[maybe_unused]] const pingtools::BeamSelection& selection) const
    {
        throw not_implemented(__func__, this->get_name());
    }

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
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping