// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "i_pingcommon.hpp"

#include <fmt/core.h>
#include <magic_enum/magic_enum.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

I_PingCommon::I_PingCommon() = default;

std::string I_PingCommon::class_name() const
{
    return "I_PingCommon";
}

std::map<t_pingfeature, std::function<bool()>> I_PingCommon::primary_feature_functions() const
{
    return {};
}

std::map<t_pingfeature, std::function<bool()>> I_PingCommon::secondary_feature_functions() const
{
    return {};
}

std::map<t_pingfeature, std::function<bool()>> I_PingCommon::feature_group_functions() const
{
    return {};
}

bool I_PingCommon::has_features() const
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

bool I_PingCommon::has_any_of_features(const std::vector<o_pingfeature>& features) const
{
    for (const auto& feature : features)
    {
        if (has_feature(feature))
            return true;
    }

    return false;
}

bool I_PingCommon::has_all_of_features(const std::vector<o_pingfeature>& features) const
{
    for (const auto& feature : features)
    {
        if (!has_feature(feature))
            return false;
    }

    return true;
}

bool I_PingCommon::has_primary_features() const
{
    for (const auto& [feature_name, has_feature] : this->primary_feature_functions())
        if (has_feature())
            return true;

    return false;
}

bool I_PingCommon::has_secondary_features() const
{
    for (const auto& [feature_name, has_feature] : this->secondary_feature_functions())
        if (has_feature())
            return true;

    return false;
}

bool I_PingCommon::has_feature_groups() const
{
    for (const auto& [feature_name, has_feature] : this->feature_group_functions())
        if (has_feature())
            return true;

    return false;
}

bool I_PingCommon::has_feature(o_pingfeature feature) const
{
    auto features   = this->primary_feature_functions();
    auto it_primary = features.find(feature.value);
    if (it_primary != features.end())
        return it_primary->second();

    features          = this->secondary_feature_functions();
    auto it_secondary = features.find(feature.value);
    if (it_secondary != features.end())
        return it_secondary->second();

    features      = this->feature_group_functions();
    auto it_group = features.find(feature.value);
    if (it_group != features.end())
        return it_group->second();

    throw std::runtime_error(fmt::format("Error[{}::{}]! The following feature is "
                                         "not registered: {}\n Please report!",
                                         class_name(),
                                         __func__,
                                         magic_enum::enum_name(feature.value)));
}

std::string I_PingCommon::feature_string(bool available, const std::string& prefix) const
{
    std::string features;

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

std::vector<t_pingfeature> I_PingCommon::possible_features()
{
    std::vector<t_pingfeature> features;

    for (const auto& features_map :
         { this->primary_feature_functions(), this->secondary_feature_functions() })
        for (const auto& [feature, has_feature] : features_map)
            features.push_back(feature);

    return features;
}

std::vector<t_pingfeature> I_PingCommon::possible_feature_groups()
{
    std::vector<t_pingfeature> features;

    for (const auto& [feature, has_feature] : this->feature_group_functions())
        features.push_back(feature);

    return features;
}

std::vector<t_pingfeature> I_PingCommon::available_features(bool available)
{
    std::vector<t_pingfeature> features;

    for (const auto& features_map :
         { this->primary_feature_functions(), this->secondary_feature_functions() })
        for (const auto& [feature, has_feature] : features_map)
            if (has_feature() == available)
                features.push_back(feature);

    return features;
}

std::vector<t_pingfeature> I_PingCommon::available_feature_groups(bool available)
{
    std::vector<t_pingfeature> features;

    for (const auto& [feature, has_feature] : this->feature_group_functions())
        if (has_feature() == available)
            features.push_back(feature);

    return features;
}

std::string I_PingCommon::feature_groups_string(bool available, const std::string& prefix) const
{
    std::string features;

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

std::string I_PingCommon::registered_features() const
{
    std::string features = primary_features();

    auto secondary_features_map = this->secondary_feature_functions();
    if (!secondary_features_map.empty())
    {
        if (!features.empty())
            features += ", ";
        features += this->secondary_features();
    }

    return features;
}

std::string I_PingCommon::primary_features() const
{
    std::string features;

    for (const auto& [feature, has_feature] : this->primary_feature_functions())
    {
        if (!features.empty())
            features += ", ";
        features += magic_enum::enum_name(feature);
    }

    return features;
}

std::string I_PingCommon::secondary_features() const
{
    std::string features;

    for (const auto& [feature, has_feature] : this->secondary_feature_functions())
    {
        if (!features.empty())
            features += ", ";
        features += magic_enum::enum_name(feature);
    }

    return features;
}

std::string I_PingCommon::feature_groups() const
{
    std::string features;

    for (const auto& [feature, has_feature] : this->feature_group_functions())
    {
        if (!features.empty())
            features += ", ";
        features += magic_enum::enum_name(feature);
    }

    return features;
}

void I_PingCommon::load([[maybe_unused]] bool force)
{
    throw not_implemented("load", this->class_name());
}

void I_PingCommon::release()
{
    throw not_implemented("release", this->class_name());
}

bool I_PingCommon::loaded()
{
    throw not_implemented("load", this->class_name());
}

I_PingCommon::not_implemented::not_implemented(std::string_view method_name, std::string_view name)
    : std::runtime_error(
          fmt::format("method {} not implemented for ping type '{}'", method_name, name))
{
}

void I_PingCommon::print_features(tools::classhelper::ObjectPrinter& printer,
                                  const std::string&                 prefix) const
{
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

void I_PingCommon::print_feature_groups(tools::classhelper::ObjectPrinter& printer,
                                        const std::string&                 prefix) const
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

tools::classhelper::ObjectPrinter
I_PingCommon::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        this->class_name(), float_precision, superscript_exponents);

    print_features(printer);
    if (!this->feature_group_functions().empty())
        print_feature_groups(printer);

    return printer;
}

} // namespace datatypes
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping

template class themachinethatgoesping::tools::classhelper::Option<
    themachinethatgoesping::echosounders::filetemplates::datatypes::t_pingfeature>;