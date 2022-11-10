// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

class SimradFileData
{
    std::string_view _file_path;

    datagrams::xml_datagrams::XML_Configuration _configuration_datagram;
    std::vector<datagrams::FIL1>                _fil1_datagrams;

    std::vector<datagrams::xml_datagrams::XML_Environment>      _environment_datagrams;
    std::vector<datagrams::xml_datagrams::XML_InitialParameter> _initial_paramater_datagrams;

    std::vector<datagrams::TAG0>                        _tag0_datagrams;
    std::map<std::string, std::vector<datagrams::XML0>> _other_xml0_datagrams;

  public:
    SimradFileData()  = default;
    ~SimradFileData() = default;

    const datagrams::xml_datagrams::XML_Configuration& XML0_Configuration() const
    {
        return _configuration_datagram;
    }
    const std::vector<datagrams::xml_datagrams::XML_Environment>& XML0_Environment() const
    {
        return _environment_datagrams;
    }
    const std::vector<datagrams::xml_datagrams::XML_InitialParameter>& XML0_InitialParameter() const
    {
        return _initial_paramater_datagrams;
    }
    const std::vector<datagrams::FIL1>& FIL1() const { return _fil1_datagrams; }
    const std::vector<datagrams::TAG0>& TAG0() const { return _tag0_datagrams; }
    const std::map<std::string, std::vector<datagrams::XML0>>& XML0_Other() const
    {
        return _other_xml0_datagrams;
    }

    void add_datagram(const datagrams::FIL1& datagram) { _fil1_datagrams.push_back(datagram); }
    void add_datagram(const datagrams::TAG0& datagram) { _tag0_datagrams.push_back(datagram); }
    void add_datagram(const datagrams::XML0& xml)
    {
        auto xml_type = xml.get_xml_datagram_type();

        if (xml_type == "Parameter")
        {
            // do nothing (these are handled per ping)
        }
        else if (xml_type == "InitialParameter")
        {
            _initial_paramater_datagrams.push_back(
                std::get<datagrams::xml_datagrams::XML_InitialParameter>(xml.decode()));
        }
        else if (xml_type == "Environment")
        {
            _environment_datagrams.push_back(
                std::get<datagrams::xml_datagrams::XML_Environment>(xml.decode()));
        }
        else if (xml_type == "Configuration")
        {
            _configuration_datagram =
                std::get<datagrams::xml_datagrams::XML_Configuration>(xml.decode());
        }
        else if (xml_type == "InitialParameter")
        {
            _environment_datagrams.push_back(
                std::get<datagrams::xml_datagrams::XML_Environment>(xml.decode()));
        }
        else
        {
            _other_xml0_datagrams[xml_type].push_back(xml);
        }
    }
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoespingction macros --
