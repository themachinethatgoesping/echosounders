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
#include <filesystem>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>

#include <boost/flyweight.hpp>
#include <fmt/core.h>
#include <magic_enum/magic_enum.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>
#include <themachinethatgoesping/algorithms/signalprocessing/types.hpp>
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>




#include "../../pingtools/beamsampleselection.hpp"

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

static const std::vector<t_pingfeature> __empty_features__ = {};

class I_PingCommon
{
  protected:
    virtual std::string class_name() const { return "I_PingCommon"; }

    virtual std::map<t_pingfeature, std::function<bool()>> primary_feature_functions() const
    {
        return std::map<t_pingfeature, std::function<bool()>>();
    }
    virtual std::map<t_pingfeature, std::function<bool()>> secondary_feature_functions() const
    {
        return std::map<t_pingfeature, std::function<bool()>>();
    }
    virtual std::map<t_pingfeature, std::function<bool()>> feature_group_functions() const
    {
        return std::map<t_pingfeature, std::function<bool()>>();
    }

  public:
    I_PingCommon() {}
    virtual ~I_PingCommon() = default;

    // ----- interface functions -----

    // ----- generic features functions -----

    /**
     * @brief Check if any of the registered features is available
     *
     * @return true
     * @return false
     */
    bool has_features() const
    {
        for (const auto& [feature_name, has_feature] : this->primary_feature_functions())
            if (has_feature())
                return true;

        for (const auto& [feature_name, has_feature] : this->secondary_feature_functions())
            if (has_feature())
                return true;

        for (const auto& [feature_name, has_feature] : this->feature_group_functions())
            if (has_feature())
                return true;

        return false;
    }

    /**
     * @brief Check if any of the specified features is available
     *
     * @return true
     * @return false
     */
    bool has_any_of_features(const std::vector<t_pingfeature>& features) const
    {
        for (const auto& feature : features)
        {
            if (has_feature(feature))
                return true;
        }

        return false;
    }

    /**
     * @brief Check if all of the specified features are available
     *
     * @return true
     * @return false
     */
    bool has_all_of_features(const std::vector<t_pingfeature>& features) const
    {
        for (const auto& feature : features)
        {
            if (!has_feature(feature))
                return false;
        }

        return true;
    }

    /**
     * @brief Check if any of the registered main features is available
     *
     * @return true
     * @return false
     */
    bool has_primary_features() const
    {
        for (const auto& [feature_name, has_feature] : this->primary_feature_functions())
            if (has_feature())
                return true;

        return false;
    }

    bool has_secondary_features() const
    {
        for (const auto& [feature_name, has_feature] : this->secondary_feature_functions())
            if (has_feature())
                return true;

        return false;
    }

    bool has_feature_groups() const
    {
        for (const auto& [feature_name, has_feature] : this->feature_group_functions())
            if (has_feature())
                return true;

        return false;
    }

    /**
     * @brief Check if any of the registered features is available
     *
     * @return true
     * @return false
     */
    bool has_feature(t_pingfeature feature) const
    {
        auto features   = this->primary_feature_functions();
        auto it_primary = features.find(feature);
        if (it_primary != features.end())
            return it_primary->second();

        features          = this->secondary_feature_functions();
        auto it_secondary = features.find(feature);
        if (it_secondary != features.end())
            return it_secondary->second();

        features      = this->feature_group_functions();
        auto it_group = features.find(feature);
        if (it_group != features.end())
            return it_group->second();

        throw std::runtime_error(fmt::format("Error[{}::{}]! The following feature is "
                                             "not registered: {}\n Please report!",
                                             class_name(),
                                             __func__,
                                             magic_enum::enum_name(feature)));
    }

    /**
     * @brief Get a string of all registered features that are available or not available
     *
     * @param available if True (default) return available features, else return not available
     * features
     * @return std::string
     */
    std::string feature_string(bool available = true, const std::string& prefix = "") const
    {
        std::string features = "";

        for (const auto& features_map :
             { this->primary_feature_functions(), this->secondary_feature_functions() })
            for (const auto& [feature, has_feature] : features_map)
            {
                if (has_feature() == available)
                {
                    if (!features.empty())
                        features += ", ";
                    features += prefix;
                    features += magic_enum::enum_name(feature);
                }
            }

        return features;
    }

    std::vector<t_pingfeature> possible_features()
    {
        std::vector<t_pingfeature> features;

        for (const auto& features_map :
             { this->primary_feature_functions(), this->secondary_feature_functions() })
            for (const auto& [feature, has_feature] : features_map)
                features.push_back(feature);

        return features;
    }

    std::vector<t_pingfeature> possible_feature_groups()
    {
        std::vector<t_pingfeature> features;

        for (const auto& [feature, has_feature] : this->feature_group_functions())
            features.push_back(feature);

        return features;
    }

    std::vector<t_pingfeature> available_features(bool available = true)
    {
        std::vector<t_pingfeature> features;

        for (const auto& features_map :
             { this->primary_feature_functions(), this->secondary_feature_functions() })
            for (const auto& [feature, has_feature] : features_map)
                if (has_feature() == available)
                    features.push_back(feature);

        return features;
    }

    std::vector<t_pingfeature> available_feature_groups(bool available = true)
    {
        std::vector<t_pingfeature> features;

        for (const auto& [feature, has_feature] : this->feature_group_functions())
            if (has_feature() == available)
                features.push_back(feature);

        return features;
    }

    /**
     * @brief Get a string of all registered feature groups that are available or not available
     *
     * @param available if True (default) return available features, else return not available
     * features
     * @return std::string
     */
    std::string feature_groups_string(bool available = true, const std::string& prefix = "") const
    {
        std::string features = "";

        for (const auto& [feature, has_feature] : this->feature_group_functions())
        {
            if (has_feature() == available)
            {
                if (!features.empty())
                    features += ", ";
                features += prefix;
                features += magic_enum::enum_name(feature);
            }
        }

        return features;
    }

    /**
     * @brief Get a string of all registered features for this ping class
     *
     * @return std::string
     */
    std::string registered_features() const
    {
        std::string features = primary_features();

        auto secondary_features = this->secondary_feature_functions();
        if (!secondary_features.empty())
        {
            if (!features.empty())
                features += ", ";
            features += this->secondary_features();
        }

        return features;
    }

    /**
     * @brief Get a string of all registered primary features for this ping class
     *
     * @return std::string
     */
    std::string primary_features() const
    {
        std::string features = "";

        for (const auto& [feature, has_feature] : this->primary_feature_functions())
        {
            if (!features.empty())
                features += ", ";
            features += magic_enum::enum_name(feature);
        }

        return features;
    }

    /**
     * @brief Get a string of all registered secondary features for this ping class
     *
     * @return std::string
     */
    std::string secondary_features() const
    {
        std::string features = "";

        for (const auto& [feature, has_feature] : this->secondary_feature_functions())
        {
            if (!features.empty())
                features += ", ";
            features += magic_enum::enum_name(feature);
        }

        return features;
    }

    /**
     * @brief Get a string of all registered feature groups for this ping class
     *
     * @return std::string
     */
    std::string feature_groups() const
    {
        std::string features = "";

        for (const auto& [feature, has_feature] : this->feature_group_functions())
        {
            if (!features.empty())
                features += ", ";
            features += magic_enum::enum_name(feature);
        }

        return features;
    }
    //------ interface ------//
    virtual void load([[maybe_unused]] bool force = false)
    {
        throw not_implemented("load", this->class_name());
    }
    virtual void release() { throw not_implemented("release", this->class_name()); }
    virtual bool loaded() { throw not_implemented("load", this->class_name()); }

  protected:
    struct not_implemented : public std::runtime_error
    {
        not_implemented(std::string_view method_name, std::string_view name)
            : std::runtime_error(
                  fmt::format("method {} not implemented for ping type '{}'", method_name, name))
        {
        }
    };

  public:
    void print_features(tools::classhelper::ObjectPrinter& printer,
                        const std::string&                 prefix = "") const
    {
        // std::string prefix_with_points = prefix.empty() ? ".get_" + prefix : ".get_" + prefix +
        // ".";
        std::string prefix_with_points = ".get_";
        std::string feature_header =
            prefix.empty() ? "Features" : fmt::format("Features(.{})", prefix);

        auto features     = feature_string(true, prefix_with_points);
        auto not_features = feature_string(false, prefix_with_points);

        if (!prefix.empty())
            features = "." + prefix + " : " + features;

        if (!not_features.empty())
        {
            printer.register_string(feature_header, features, std::string("Not:") + not_features);
        }
        else
        {
            printer.register_string(feature_header, features);
        }
    }

    void print_feature_groups(tools::classhelper::ObjectPrinter& printer,
                              const std::string&                 prefix = "") const
    {
        std::string prefix_with_points = prefix.empty() ? "." + prefix : "." + prefix + ".";
        std::string feature_header =
            prefix.empty() ? "Feature groups" : fmt::format("Feature groups(.{})", prefix);

        auto features     = feature_groups_string(true, prefix_with_points);
        auto not_features = feature_groups_string(false, prefix_with_points);
        if (!not_features.empty())
            printer.register_string(feature_header, features, std::string("Not:") + not_features);
        else
            printer.register_string(feature_header, features);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        print_features(printer);
        if (!this->feature_group_functions().empty())
            print_feature_groups(printer);

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