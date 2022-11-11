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

#include "i_inputfileiterator.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_DatagramIdentifier, typename t_ifstream>
class I_PackageContainer
{
    std::string _name; ///< name of the package container (useful for debugging derived classes)

    /* pyiterator access */
    tools::pyhelper::PyIndexer _pyindexer = tools::pyhelper::PyIndexer(0);

    /* package infos */
    std::shared_ptr<std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>>
        _package_infos_all =
            std::make_shared<std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>>();

    /* package infos (sorted by datagram identifier) */
    tools::helper::DefaultSharedPointerMap<
        t_DatagramIdentifier,
        std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>>
        _package_infos_by_type;

  public:
    void add_package_info(const PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>& package_info)
    {
        _package_infos_all->push_back(package_info);
        _package_infos_by_type.at(package_info->get_datagram_identifier())->push_back(package_info);
        _pyindexer.reset(_package_infos_all->size());
    }

    void add_package_infos(
        const std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>& package_info)
    {
        for (const auto& package_info : package_info)
        {
            _package_infos_all->push_back(package_info);
            _package_infos_by_type.at(package_info->get_datagram_identifier())
                ->push_back(package_info);
        }

        _pyindexer.reset(_package_infos_all->size());
    }

    void add_package_infos(const DataFileInfo<t_DatagramIdentifier, t_ifstream>& file_info)
    {
        for (const auto& package_info : *file_info.package_infos)
        {
            _package_infos_all->push_back(package_info);
            _package_infos_by_type.at(package_info->get_datagram_identifier())
                ->push_back(package_info);
        }

        _pyindexer.reset(_package_infos_all->size());
    }

  public:
    I_PackageContainer(std::string_view name = "Default")
        : _name(name)
    {
    }
    virtual ~I_PackageContainer() = default;

    // ----- container access -----
    std::shared_ptr<std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>>
    get_package_infos_all() const
    {
        return _package_infos_all;
    }
    const std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>& get_package_infos_by_type(
        t_DatagramIdentifier type) const
    {
        return _package_infos_by_type.at(type);
    }

    size_t size() const { return _package_infos_all->size(); }
    size_t size(t_DatagramIdentifier type) const { return _package_infos_by_type.at(type)->size(); }

    // ----- virtual interface -----
    virtual std::string datagram_identifier_to_string(
        t_DatagramIdentifier datagram_identifier) const = 0;
    virtual std::string datagram_identifier_info(
        t_DatagramIdentifier datagram_identifier) const = 0;

    // ----- iterator interface -----
    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator(t_DatagramIdentifier datagram_identifier) const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(
            _package_infos_by_type.at_const(datagram_identifier));
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator(t_DatagramIdentifier datagram_identifier, long start, long end, long step) const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(
            _package_infos_by_type.at_const(datagram_identifier), start, end, step);
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator() const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(_package_infos_all);
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator(long start, long end, long step) const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(_package_infos_all, start, end, step);
    }

    // ----- printing interface -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("I_PackageContainer", float_precision);

        printer.register_section("Datagrams");
        printer.register_value("Total", _package_infos_all->size(), "");
        for (const auto& kv : _package_infos_by_type)
        {
            std::string info = datagram_identifier_info(kv.first);

            printer.register_value("Packages [" + datagram_identifier_to_string(kv.first) + "]",
                                   kv.second->size(),
                                   info);
        }

        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASShelper_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping