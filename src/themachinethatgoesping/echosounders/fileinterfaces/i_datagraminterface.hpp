// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* std includes */
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

#include "i_datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_DatagramIdentifier, typename t_ifstream>
class I_DatagramInterface
{
  protected:
    std::string _name; ///< name of the datagram container (useful for debugging derived classes)

    /* datagram infos */
    std::vector<DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream>> _datagram_infos_all;

    /* datagram infos (sorted by datagram identifier) */
    tools::helper::DefaultMap<t_DatagramIdentifier,
                              std::vector<DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream>>>
        _datagram_infos_by_type;

  public:
    void add_datagram_info(const DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream>& datagram_info)
    {
        _datagram_infos_all.push_back(datagram_info);
        _datagram_infos_by_type.at(datagram_info->get_datagram_identifier())
            .push_back(datagram_info);
    }

    void add_datagram_infos(
        const std::vector<DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream>>& datagram_infos)
    {
        for (const auto& datagram_info : datagram_infos)
        {
            _datagram_infos_all.push_back(datagram_info);
            _datagram_infos_by_type.at(datagram_info->get_datagram_identifier())
                .push_back(datagram_info);
        }
    }

    void set_datagram_infos(
        std::vector<DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream>> datagram_infos)
    {
        _datagram_infos_all = std::move(datagram_infos);

        for (const auto& datagram_info : _datagram_infos_all)
        {
            _datagram_infos_by_type.at(datagram_info->get_datagram_identifier())
                .push_back(datagram_info);
        }
    }

  public:
    I_DatagramInterface(std::string_view name = "I_DatagramInterface")
        : _name(name)
    {
    }
    virtual ~I_DatagramInterface() = default;

    // ----- direct container access -----
    std::vector<DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream>> get_datagram_infos_all() const
    {
        return _datagram_infos_all;
    }
    const std::vector<DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream>>&
    get_datagram_infos_by_type(t_DatagramIdentifier type) const
    {
        return _datagram_infos_by_type.at(type);
    }

    size_t size() const { return _datagram_infos_all.size(); }
    size_t size(t_DatagramIdentifier type) const { return _datagram_infos_by_type.at(type).size(); }

    // ----- virtual interface -----
    virtual std::string datagram_identifier_to_string(
        t_DatagramIdentifier datagram_identifier) const = 0;
    virtual std::string datagram_identifier_info(
        t_DatagramIdentifier datagram_identifier) const = 0;

    // ----- iterator interface -----
    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_DatagramContainer<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    datagrams() const
    {
        return I_DatagramContainer<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(_datagram_infos_all);
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_DatagramContainer<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    datagrams(t_DatagramIdentifier datagram_identifier) const
    {
        return I_DatagramContainer<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(
            _datagram_infos_by_type.at_const(datagram_identifier));
    }

    // ----- printing interface -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(_name, float_precision);

        printer.register_section("Detected datagrams");
        printer.register_value("Total", _datagram_infos_all.size(), "");
        for (const auto& kv : _datagram_infos_by_type)
        {
            std::string info = datagram_identifier_info(kv.first);

            printer.register_value("Datagrams [" + datagram_identifier_to_string(kv.first) + "]",
                                   kv.second.size(),
                                   info);
        }

        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping