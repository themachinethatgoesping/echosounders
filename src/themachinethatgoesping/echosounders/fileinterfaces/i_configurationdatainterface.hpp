// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

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

/* themachinethatgoesping navigation includes */
#include <themachinethatgoesping/navigation/sensorconfiguration.hpp>

#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

// TODO: this should be a c++20 concept
template<typename t_datagraminterface>
class I_ConfigurationDataCollection : public t_datagraminterface
{
    using t_base = t_datagraminterface;

    navigation::SensorConfiguration _sensor_configuration;

  public:
    I_ConfigurationDataCollection(std::string_view name = "I_ConfigurationDataCollection")
        : t_base(name)
    {
    }
    virtual ~I_ConfigurationDataCollection() = default;

    virtual void read_sensor_configuration()
    {
        throw std::runtime_error(
            fmt::format("read_sensor_configuration not implemented for {}", this->get_name()));
    }

    navigation::SensorConfiguration& sensor_configuration() { return _sensor_configuration; }

    /**
     * @brief Get the file nr
     * This function assumes that the file nr is the same for all datagrams in the file
     *
     * @return size_t
     */
    size_t get_file_nr() const
    {
        if (this->_datagram_infos_all.empty())
            throw std::runtime_error("get_file_nr: no datagrams in file");

        return this->_datagram_infos_all[0]->get_file_nr();
    }

    /**
     * @brief Get the file name
     * This function assumes that the file name is the same for all datagrams in the file
     *
     * @return std::string
     */
    std::string get_file_path() const
    {
        if (this->_datagram_infos_all.empty())
            throw std::runtime_error("get_file_name: no datagrams in file");
        return this->_datagram_infos_all[0]->get_file_path();
    }
};
// void add_datagram(DatagramInfo_ptr<t_Datagram

template<typename t_configurationdatagraminterface>
class I_ConfigurationDataInterface : public I_FileDataInterface<t_configurationdatagraminterface>
{
    using t_base = I_FileDataInterface<t_configurationdatagraminterface>;

  public:
    I_ConfigurationDataInterface(std::string_view name = "I_ConfigurationDataInterface")
        : t_base(name)
    {
    }
    virtual ~I_ConfigurationDataInterface() = default;

    // void add_datagram_info(DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream> datagram)
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping