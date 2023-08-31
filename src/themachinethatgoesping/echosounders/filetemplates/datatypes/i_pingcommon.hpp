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
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/hashhelper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../pingtools/beamsampleselection.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

class I_PingCommon
{
    std::string _name;

  protected:
    const std::string& get_name() const { return _name; }

    // map of features (names) and respective has_feature functions
    std::unordered_map<std::string, std::function<bool()>> _features;

  public:
    I_PingCommon(std::string name)
        : _name(std::move(name))
    {
    }
    virtual ~I_PingCommon() = default;

    bool has_features() const
    {
        for (const auto& [feature_name, has_feature] : _features)
            if (has_feature())
                return true;

        return false;
    }

    void register_feature(std::string feature_name, std::function<bool()> has_feature)
    {
        _features[feature_name] = has_feature;
    }

    std::string feature_string(bool has_features = true) const
    {
        std::string features = "";

        for (const auto& [feature_name, has_feature] : _features)
        {
            if (has_feature() == has_features)
            {
                if (!features.empty())
                    features += ", ";
                features += feature_name;
            }
        }

        return features;
    }

    //------ interface ------//
    virtual void load() { throw not_implemented("load", this->get_name()); }
    virtual void release() { throw not_implemented("release", this->get_name()); }
    virtual bool loaded() { throw not_implemented("load", this->get_name()); }

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
                get_name(),
                function_name,
                feature_name));
        }

        if (!it->second())
        {
            throw std::runtime_error(
                fmt::format("Error[{}::{}]! The following feature is not available: {}",
                            get_name(),
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
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

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