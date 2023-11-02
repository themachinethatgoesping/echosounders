// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_datagraminterface.doc.hpp"

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

#include "../datacontainers/datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

template<typename t_DatagramIdentifier, typename t_ifstream>
class I_DatagramInterface
{
    using t_base = I_DatagramInterface<t_DatagramIdentifier, t_ifstream>;

  public:
    // member types
    using type_DatagramIdentifier = t_DatagramIdentifier;
    using type_ifstream           = t_ifstream;
    using type_DatagramInfo_ptr   = datatypes::DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream>;

  private:
    std::string_view
        _name; ///< name of the datagram container (useful for debugging derived classes)

    double _timestamp_first = 0; ///< smallest timestamp (>0) of all registered datagrams
    double _timestamp_last  = 0; ///< largest timestamp (>0) of all registered datagrams

  protected:
    std::string_view get_name() const { return _name; }

    /* datagram infos */
    std::vector<type_DatagramInfo_ptr> _datagram_infos_all;

    /* datagram infos (sorted by datagram identifier) */
    tools::helper::DefaultMap<t_DatagramIdentifier, std::vector<type_DatagramInfo_ptr>>
        _datagram_infos_by_type;

  public:
    // // filter types
    // std::vector<t_base> per_file() const
    // {
    //     std::vector<t_base> vec;
    //     for (const auto& datagram_info : _datagram_infos_all)
    //     {
    //         size_t file_nr = datagram_info->get_file_nr();
    //         // if (vec.size() <= file_nr)
    //         //     vec.resize(file_nr + 1);

    //         // vec[file_nr].add_datagram_info(datagram_info);
    //     }
    //     return vec;
    // }

  public:
    double                    get_timestamp_first() const { return _timestamp_first; }
    double                    get_timestamp_last() const { return _timestamp_first; }
    std::pair<double, double> get_timestamp_range() const
    {
        return std::make_pair(_timestamp_first, _timestamp_last);
    }
    // /**
    //  * @brief This functions allows derived classes to add custom functionality
    //  *
    //  * @param datagram_info
    //  */
    // virtual void add_datagram_info_callback(
    //     [[maybe_unused]] const type_DatagramInfo_ptr& datagram_info)
    // {
    // }

    void add_datagram_info(const type_DatagramInfo_ptr& datagram_info)
    {
        _datagram_infos_all.push_back(datagram_info);
        _datagram_infos_by_type.at(datagram_info->get_datagram_identifier())
            .push_back(datagram_info);

        auto timestamp = datagram_info->get_timestamp();

        if (timestamp > 0)
        {
            if (timestamp < _timestamp_first || _timestamp_first == 0)
                _timestamp_first = timestamp;

            if (timestamp > _timestamp_last || _timestamp_last == 0)
                _timestamp_last = timestamp;
        }

        // add_datagram_info_callback(datagram_info);
    }

    void add_datagram_infos(const std::vector<type_DatagramInfo_ptr>& datagram_infos)
    {
        for (const auto& datagram_info : datagram_infos)
        {
            add_datagram_info(datagram_info);
        }
    }

    void set_datagram_infos(std::vector<type_DatagramInfo_ptr> datagram_infos)
    {
        _datagram_infos_all = std::move(datagram_infos);

        for (const auto& datagram_info : _datagram_infos_all)
        {
            _datagram_infos_by_type.at(datagram_info->get_datagram_identifier())
                .push_back(datagram_info);

            auto timestamp = datagram_info->get_timestamp();

            if (timestamp > 0)
            {
                if (timestamp < _timestamp_first || _timestamp_first == 0)
                    _timestamp_first = timestamp;

                if (timestamp > _timestamp_last || _timestamp_last == 0)
                    _timestamp_last = timestamp;
            }
        }
    }

  public:
    I_DatagramInterface(std::string_view name = "I_DatagramInterface")
        : _name(name)
    {
    }
    virtual ~I_DatagramInterface() = default;

    // void init_from_file() {};

    // ----- direct container access -----
    const std::vector<type_DatagramInfo_ptr>& get_datagram_infos_all() const
    {
        return _datagram_infos_all;
    }
    std::vector<type_DatagramInfo_ptr> get_datagram_infos_by_type(t_DatagramIdentifier type) const
    {
        return _datagram_infos_by_type.at_const(type);
    }

    size_t size() const { return _datagram_infos_all.size(); }
    size_t size(t_DatagramIdentifier type) const { return _datagram_infos_by_type.at(type).size(); }
    bool   empty() const { return _datagram_infos_all.empty(); }
    bool empty(t_DatagramIdentifier type) const { return _datagram_infos_by_type.at(type).empty(); }
    auto keys() const { return _datagram_infos_by_type.keys(); }

    // ----- virtual interface -----
    virtual std::string datagram_identifier_to_string(
        t_DatagramIdentifier datagram_identifier) const = 0;
    virtual std::string datagram_identifier_info(
        t_DatagramIdentifier datagram_identifier) const = 0;

    // ----- iterator interface -----
    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    datacontainers::
        DatagramContainer<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
        datagrams() const
    {
        return datacontainers::DatagramContainer<t_DatagramType,
                                                 t_DatagramIdentifier,
                                                 t_ifstream,
                                                 t_DatagramTypeFactory>(_datagram_infos_all);
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    datacontainers::
        DatagramContainer<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
        datagrams(t_DatagramIdentifier datagram_identifier) const
    {
        return datacontainers::DatagramContainer<t_DatagramType,
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
        std::string time_str_0 =
            tools::timeconv::unixtime_to_datestring(_timestamp_first, 2, "%d/%m/%Y %H:%M:%S");
        std::string time_str_1 =
            tools::timeconv::unixtime_to_datestring(_timestamp_last, 2, "%d/%m/%Y %H:%M:%S");
        printer.register_string("timestamp_first", time_str_0);
        printer.register_string("timestamp_last", time_str_1);
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

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping