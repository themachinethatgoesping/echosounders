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
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
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

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>
#include <themachinethatgoesping/algorithms/signalprocessing/types.hpp>
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/hashhelper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

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

class I_PingCommon
{
  protected:
    virtual std::string class_name() const { return "I_PingCommon"; }

    // map of features (names) and respective has_feature functions
    std::unordered_map<std::string, std::function<bool()>> _features;

    /**
     * @brief Register a feature
     *
     * @param feature_name
     * @param has_feature
     */
    void register_feature(std::string feature_name, std::function<bool()> has_feature)
    {
        _features[feature_name] = has_feature;
    }

  public:
    I_PingCommon()
    {
        register_feature("tx_signal_parameters",
                         std::bind(&I_PingCommon::has_tx_signal_parameters, this));
        register_feature("number_of_tx_sectors",
                         std::bind(&I_PingCommon::has_tx_sector_information, this));
    }
    virtual ~I_PingCommon() = default;

    // ----- interface functions -----
    /**
     * @brief Get the transmission signal parameters per sector.
     *  
     * @return const std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>&
     */
    virtual const std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>&
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

    // ----- generic features functions -----

    /**
     * @brief Check if any of the registered features is available
     *
     * @return true
     * @return false
     */
    bool has_features() const
    {
        for (const auto& [feature_name, has_feature] : _features)
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
    bool has_feature(const std::string& feature_name) const { return _features.at(feature_name)(); }

    /**
     * @brief Get a string of all registered features that are available or not available
     *
     * @param available if True (default) return available features, else return not available
     * features
     * @return std::string
     */
    std::string feature_string(bool available = true) const
    {
        std::string features = "";

        for (const auto& [feature_name, has_feature] : _features)
        {
            if (has_feature() == available)
            {
                if (!features.empty())
                    features += ", ";
                features += feature_name;
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
        std::string features = "";

        for (const auto& [feature_name, has_feature] : _features)
        {
            if (!features.empty())
                features += ", ";
            features += feature_name;
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
    // a function that calls a specified function (templated) that returns a boolean
    // if this boolean is false, throw an exception
    void check_feature(std::string_view feature_name, std::string_view function_name) const
    {
        auto it = _features.find(feature_name.data());
        if (it == _features.end())
        {
            throw std::runtime_error(fmt::format(
                "Error[{}::{}]! The following feature is not registered: {}\n Please report!",
                class_name(),
                function_name,
                feature_name));
        }

        if (!((it->second)()))
        {
            throw std::runtime_error(
                fmt::format("Error[{}::{}]! The following feature is not available: {}",
                            class_name(),
                            function_name,
                            feature_name));
        }
    }
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
        auto features     = feature_string();
        auto not_features = feature_string(false);
        if (!not_features.empty())
            printer.register_string(
                prefix + "-Features", features, std::string("Not:") + not_features);
        else
            printer.register_string(prefix + "-Features", features);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        print_features(printer);

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