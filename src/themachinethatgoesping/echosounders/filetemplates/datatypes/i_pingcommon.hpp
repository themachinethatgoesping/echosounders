/**
 * @file i_pingcommon.hpp
 * @brief This file contains the declaration of the I_PingCommon class.
 *
 * The I_PingCommon class is an abstract base class that represents a common interface for ping data
 * types. It provides functionality to register and check features, load and release data, and
 * retrieve information about the available features.
 *
 * @author Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
 * @author Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
 * @author Peter Urban, Ghent University
 *
 * SPDX-License-Identifier: MPL-2.0
 */
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_pingcommon.doc.hpp"

/* std includes */
#include <cstdint>
#include <functional>
#include <map>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/option.hpp>

/**
 * @namespace themachinethatgoesping
 * @brief Namespace for the machine that goes ping.
 * This namespace contains classes and functions related to the machine that goes ping.
 */
namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

enum class t_pingfeature : uint8_t
{
    /* I_Ping features */
    timestamp,
    datetime,
    channel_id,
    sensor_configuration,
    navigation_interpolator_latlon,
    sensor_data_latlon,
    geolocation,

    /* I_Ping feature groups */
    file_data,
    bottom,
    watercolumn,

    /* I_PingBottom and I_PingWatercolumn */
    tx_signal_parameters,
    number_of_tx_sectors,

    beam_numbers_per_tx_sector,
    beam_selection_all,
    number_of_beams,
    tx_sector_per_beam,

    /* I_PingBottom */
    beam_crosstrack_angles,
    two_way_travel_times,
    xyz,

    /* I_PingWatercolumn */
    bottom_range_samples,
    amplitudes,
    rp,
    rv,
    pp,
    pv,
    ap,
    av,
    power,
    sp,
    sv,

    /* Calobration */
    watercolumn_calibration,
    multisectorwatercolumn_calibration
};

using o_pingfeature = themachinethatgoesping::tools::classhelper::Option<t_pingfeature>;

class I_PingCommon
{
  protected:
    virtual std::string class_name() const;
    virtual std::map<t_pingfeature, std::function<bool()>> primary_feature_functions() const;
    virtual std::map<t_pingfeature, std::function<bool()>> secondary_feature_functions() const;
    virtual std::map<t_pingfeature, std::function<bool()>> feature_group_functions() const;

  public:
    I_PingCommon();
    virtual ~I_PingCommon() = default;

    // ----- interface functions -----

    // ----- generic features functions -----

    /**
     * @brief Check if any of the registered features is available
     *
     * @return true
     * @return false
     */
    bool has_features() const;

    /**
     * @brief Check if any of the specified features is available
     *
     * @return true
     * @return false
     */
    bool has_any_of_features(const std::vector<o_pingfeature>& features) const;

    /**
     * @brief Check if all of the specified features are available
     *
     * @return true
     * @return false
     */
    bool has_all_of_features(const std::vector<o_pingfeature>& features) const;

    /**
     * @brief Check if any of the registered main features is available
     *
     * @return true
     * @return false
     */
    bool has_primary_features() const;

    bool has_secondary_features() const;

    bool has_feature_groups() const;

    /**
     * @brief Check if any of the registered features is available
     *
     * @return true
     * @return false
     */
    bool has_feature(o_pingfeature feature) const;

    /**
     * @brief Get a string of all registered features that are available or not available
     *
     * @param available if True (default) return available features, else return not available
     * features
     * @return std::string
     */
    std::string feature_string(bool available = true, const std::string& prefix = "") const;

    std::vector<t_pingfeature> possible_features();

    std::vector<t_pingfeature> possible_feature_groups();

    std::vector<t_pingfeature> available_features(bool available = true);

    std::vector<t_pingfeature> available_feature_groups(bool available = true);

    /**
     * @brief Get a string of all registered feature groups that are available or not available
     *
     * @param available if True (default) return available features, else return not available
     * features
     * @return std::string
     */
    std::string feature_groups_string(bool available = true,
                                      const std::string& prefix = "") const;

    /**
     * @brief Get a string of all registered features for this ping class
     *
     * @return std::string
     */
    std::string registered_features() const;

    /**
     * @brief Get a string of all registered primary features for this ping class
     *
     * @return std::string
     */
    std::string primary_features() const;

    /**
     * @brief Get a string of all registered secondary features for this ping class
     *
     * @return std::string
     */
    std::string secondary_features() const;

    /**
     * @brief Get a string of all registered feature groups for this ping class
     *
     * @return std::string
     */
    std::string feature_groups() const;
    //------ interface ------//
    virtual void load([[maybe_unused]] bool force = false);
    virtual void release();
    virtual bool loaded();

  protected:
    struct not_implemented : public std::runtime_error
    {
        not_implemented(std::string_view method_name, std::string_view name);
    };

  public:
    void print_features(tools::classhelper::ObjectPrinter& printer,
                        const std::string&                 prefix = "") const;

    void print_feature_groups(tools::classhelper::ObjectPrinter& printer,
                              const std::string&                 prefix = "") const;

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

extern template class themachinethatgoesping::tools::classhelper::Option<
    themachinethatgoesping::echosounders::filetemplates::datatypes::t_pingfeature>;