// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_filedatainterfaceperfile.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

// TODO: this should be a c++20 concept
template<typename t_datagraminterface>
class I_FileDataInterfacePerFile : public t_datagraminterface
{
    using t_base = t_datagraminterface;

    size_t      _file_nr   = std::numeric_limits<size_t>::max();
    std::string _file_path = "not registered";

    std::shared_ptr<I_FileDataInterfacePerFile> _linked_secondary_file;
    std::weak_ptr<I_FileDataInterfacePerFile>   _linked_primary_file;

    std::vector<typename t_base::type_DatagramIdentifier> _used_extension_datagram_identifiers;
    std::vector<typename t_base::type_DatagramIdentifier> _ignored_extension_datagram_identifiers;

  public:
    using type_DatagramInterface = t_datagraminterface;

  public:
    I_FileDataInterfacePerFile(std::string_view name = "I_FileDataInterfacePerFile")
        : t_base(name)
    {
    }
    virtual ~I_FileDataInterfacePerFile() = default;

    static void link_file_interfaces(
        std::shared_ptr<I_FileDataInterfacePerFile> file_interface_main,
        std::shared_ptr<I_FileDataInterfacePerFile> file_interface_extension)
    {
        if (file_interface_main->has_linked_file())
            throw std::runtime_error(
                fmt::format("Main {} [{}] '{}' cannot be linked to [{}] '{}' because "
                            "it is already linked "
                            "to file_interface_extension: [{}] '{}'",
                            file_interface_main->class_name(),
                            file_interface_main->get_file_nr(),
                            file_interface_main->get_file_path(),
                            file_interface_extension->get_file_nr(),
                            file_interface_extension->get_file_path(),
                            file_interface_main->get_linked_file()->get_file_nr(),
                            file_interface_main->get_linked_file()->get_file_path()));

        if (file_interface_extension->has_linked_file())
            throw std::runtime_error(
                fmt::format("Extension {} [{}] '{}' cannot be linked to [{}] '{}' "
                            "because it is already linked "
                            "linked to file_interface_main: [{}] '{}'",
                            file_interface_extension->class_name(),
                            file_interface_extension->get_file_nr(),
                            file_interface_extension->get_file_path(),
                            file_interface_main->get_file_nr(),
                            file_interface_main->get_file_path(),
                            file_interface_extension->get_linked_file()->get_file_nr(),
                            file_interface_extension->get_linked_file()->get_file_path()));

        file_interface_main->_linked_secondary_file    = file_interface_extension;
        file_interface_extension->_linked_primary_file = file_interface_main;

        // check which datagram_identifiers in the extension file do not exist in the main file
        for (const auto& [key, datagrams] : file_interface_extension->_datagram_infos_by_type)
        {
            if (datagrams.empty())
                continue;

            // key exists in main file and the related vector is not empty -> continue
            const auto& kv_main = file_interface_main->_datagram_infos_by_type.find(key);
            if (kv_main != file_interface_main->_datagram_infos_by_type.end())
            {
                if (!kv_main->second.empty())
                {
                    file_interface_main->_ignored_extension_datagram_identifiers.push_back(key);
                    continue;
                }
            }

            // key does not exist in main file -> add to extension datagram identifiers
            file_interface_main->_used_extension_datagram_identifiers.push_back(key);
            file_interface_main->_datagram_infos_by_type[key] = datagrams;
        }
    }

    virtual void init_from_file([[maybe_unused]] bool force = false)
    {
        // this file does not need to be initialized
        return;
    }

    virtual void deinitialize()
    {
        // this file does not need to be deinitialized
        return;
    }

    virtual bool initialized() const
    {
        // this file is always initialized
        return true;
    }

    virtual void add_file_information(size_t file_nr, std::string file_path)
    {
        _file_nr   = file_nr;
        _file_path = std::move(file_path);
    }

    /**
     * @brief Get the file nr
     * This function assumes that the file nr is the same for all datagrams in the file
     *
     * @return size_t
     */
    size_t get_file_nr() const
    {
        if (this->_datagram_infos_all.empty())
            return _file_nr;
        // throw std::runtime_error("get_file_nr: no datagrams in file");

        if (this->_datagram_infos_all[0]->get_file_nr() != _file_nr)
            throw std::runtime_error(fmt::format(
                "get_file_nr: file nr mismatch: file nr of first package is {} but should be {}",
                this->_datagram_infos_all[0]->get_file_nr(),
                _file_nr));

        return _file_nr;
    }

    /**
     * @brief Get the file nr of the linked file
     *
     * @return size_t
     */
    size_t get_linked_file_nr() const
    {

        if (has_linked_file())
            return _linked_secondary_file->get_file_nr();

        throw std::runtime_error("get_linked_file_nr: no linked file");
    }

    /**
     * @brief Get the file name
     * This function assumes that the file name is the same for_linked_file all datagrams in the
     * file
     *
     * @return std::string
     */
    std::string get_file_path() const
    {
        if (this->_datagram_infos_all.empty())
            return _file_path;

        if (this->_datagram_infos_all[0]->get_file_path() != _file_path)
            throw std::runtime_error(fmt::format("get_file_path: file path mismatch: file path of "
                                                 "first package is {} but should be {}",
                                                 this->_datagram_infos_all[0]->get_file_path(),
                                                 _file_path));

        return _file_path;
    }

    bool is_primary_file() const { return !is_secondary_file(); }
    bool is_secondary_file() const
    {
        if (_linked_primary_file.lock())
            return true;

        return false;
    }
    bool has_linked_file() const
    {
        if (_linked_secondary_file)
            return true;

        if (_linked_primary_file.lock())
            return true;

        return false;
    }
    std::shared_ptr<I_FileDataInterfacePerFile> get_linked_file() const
    {
        if (_linked_secondary_file)
            return _linked_secondary_file;

        auto ptr = _linked_primary_file.lock();
        if (ptr)
            return ptr;

        throw std::runtime_error("get_linked_file: no linked file");
    }

    /**
     * @brief Get the file name of the linked file
     *
     * @return std::string
     */
    std::string get_linked_file_path() const
    {
        if (has_linked_file())
            return get_linked_file()->get_file_path();

        throw std::runtime_error("get_linked_file_path: no linked file");
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("File infos");
        // if _linked_file is set
        if (this->has_linked_file())
        {
            // if this is not main, the other file will be main
            std::string type_self   = is_primary_file() ? "main" : "extension";
            std::string type_linked = is_primary_file() ? "extension" : "main";

            printer.register_string(fmt::format("File [{}]", type_self),
                                    this->get_file_path(),
                                    std::to_string(this->get_file_nr()));
            printer.register_string(fmt::format("Linked file [{}]", type_linked),
                                    this->get_linked_file_path(),
                                    std::to_string(get_linked_file_nr()));

            if (this->is_primary_file())
            {
                printer.register_section("Extension file infos");
                printer.register_container("Used", _used_extension_datagram_identifiers);
                printer.register_container("Ignored", _ignored_extension_datagram_identifiers);
            }
        }
        else
        {
            printer.register_string(
                "File", this->get_file_path(), std::to_string(this->get_file_nr()));
        }

        return printer;
    }
};
// void add_datagram(datatypes::DatagramInfo_ptr<t_Datagram

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping