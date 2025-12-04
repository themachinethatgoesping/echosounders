// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
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

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

template<typename t_datagraminterface>
class I_FileDataInterfacePerFile : public t_datagraminterface
{
    using t_base = t_datagraminterface;

    size_t      _file_nr   = std::numeric_limits<size_t>::max();
    std::string _file_path = "not registered";

    std::weak_ptr<I_FileDataInterfacePerFile> _linked_secondary_file;
    std::weak_ptr<I_FileDataInterfacePerFile> _linked_primary_file;

    std::set<typename t_base::type_DatagramIdentifier> _used_extension_datagram_identifiers;
    std::set<typename t_base::type_DatagramIdentifier> _ignored_extension_datagram_identifiers;

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

        size_t number_of_extra_datagrams = 0;
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
                    file_interface_main->_ignored_extension_datagram_identifiers.insert(key);
                    continue;
                }
            }

            // key does not exist in main file -> add to extension datagram identifiers
            file_interface_main->_used_extension_datagram_identifiers.insert(key);
            file_interface_main->_datagram_infos_by_type[key] = datagrams;
            number_of_extra_datagrams += datagrams.size();
        }

        // add datagrams to datagram_infos_all, sort by timestamp
        std::vector<typename t_base::type_DatagramInfo_ptr> datagram_infos_combined;
        datagram_infos_combined.resize(file_interface_main->_datagram_infos_all.size() +
                                       number_of_extra_datagrams);

        for (size_t i = 0, i_main = 0, i_ext = 0; i < datagram_infos_combined.size(); ++i)
        {
            // skip datagram types that are in the main file
            while (i_ext < file_interface_extension->_datagram_infos_all.size())
            {
                if (file_interface_main->_used_extension_datagram_identifiers.contains(
                        file_interface_extension->_datagram_infos_all[i_ext]
                            ->get_datagram_identifier()))
                    break;

                ++i_ext;
            }

            if (i_main < file_interface_main->_datagram_infos_all.size())
            {
                double t_main = file_interface_main->_datagram_infos_all[i_main]->get_timestamp();
                if (i_ext < file_interface_extension->_datagram_infos_all.size())
                {
                    double t_ext =
                        file_interface_extension->_datagram_infos_all[i_ext]->get_timestamp();
                    if (t_main > t_ext)
                    {
                        datagram_infos_combined[i] =
                            file_interface_extension->_datagram_infos_all[i_ext];
                        ++i_ext;
                        continue;
                    }
                    else
                    {
                        datagram_infos_combined[i] =
                            file_interface_main->_datagram_infos_all[i_main];
                        ++i_main;
                        continue;
                    }
                }
                else
                {
                    datagram_infos_combined[i] = file_interface_main->_datagram_infos_all[i_main];
                    ++i_main;
                    continue;
                }
            }
            if (i_ext < file_interface_extension->_datagram_infos_all.size())
            {
                datagram_infos_combined[i] = file_interface_extension->_datagram_infos_all[i_ext];
                ++i_ext;
                continue;
            }
            throw std::runtime_error(
                fmt::format("link_file_interfaces should never reach this point. Please report!\n- "
                            "i_main={}/{}, i_ext={}/{}, i={}/{}",
                            i_main,
                            file_interface_main->_datagram_infos_all.size(),
                            i_ext,
                            file_interface_extension->_datagram_infos_all.size(),
                            i,
                            datagram_infos_combined.size()));
        }

        file_interface_main->_datagram_infos_all = std::move(datagram_infos_combined);
    }

    virtual void init_from_file([[maybe_unused]] const std::string& index_path,
                                [[maybe_unused]] bool               force = false)
    {
        // this file does not need to be is_initialized
        return;
    }

    virtual void deinitialize()
    {
        // this file does not need to be deis_initialized
        return;
    }

    virtual bool is_initialized() const
    {
        // this file is always is_initialized
        return true;
    }

    virtual void add_file_information(size_t file_nr, std::string_view file_path)
    {
        _file_nr   = file_nr;
        _file_path = std::string(file_path);
    }

    /**
     * @brief Get the file nr
     * This function assumes that the file nr is the same for all datagrams in the file
     *
     * @return size_t
     */
    size_t get_file_nr() const { return _file_nr; }

    /**
     * @brief Get the file nr of the linked file
     *
     * @return size_t
     */
    size_t get_linked_file_nr() const { return get_linked_file()->get_file_nr(); }

    /**
     * @brief Get the file name
     * This function assumes that the file name is the same for_linked_file all datagrams in the
     * file
     *
     * @return std::string
     */
    std::string get_file_path() const { return _file_path; }

    std::string get_file_name() const
    {
        return std::filesystem::path(get_file_path()).filename().string();
    }

    size_t get_file_size() const { return std::filesystem::file_size(get_file_path()); }

    bool is_primary_file() const { return !is_secondary_file(); }
    bool is_secondary_file() const
    {
        if (_linked_primary_file.lock())
            return true;

        return false;
    }
    bool has_linked_file() const
    {
        if (_linked_secondary_file.lock())
            return true;

        if (_linked_primary_file.lock())
            return true;

        return false;
    }
    std::shared_ptr<I_FileDataInterfacePerFile> get_linked_file() const
    {
        auto ptr = _linked_secondary_file.lock();
        if (ptr)
            return ptr;

        ptr = _linked_primary_file.lock();
        if (ptr)
            return ptr;

        throw std::runtime_error("get_linked_file: no linked file");
    }

    /**
     * @brief Get the file name of the linked file
     *
     * @return std::string
     */
    std::string get_linked_file_path() const { return get_linked_file()->get_file_path(); }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

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

                // these are defined in 'types.hpp' for eache chosounder format
                printer.register_container(
                    "Used", datagram_identifiers_to_string(_used_extension_datagram_identifiers));
                printer.register_container(
                    "Ignored",
                    datagram_identifiers_to_string(_ignored_extension_datagram_identifiers));
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