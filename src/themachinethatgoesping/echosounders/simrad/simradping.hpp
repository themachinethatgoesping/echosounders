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
#include <memory>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../fileinterfaces/i_ping.hpp"
#include "simradpinginterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradPingRawData
{
    std::shared_ptr<SimradPingInterface<t_ifstream>> _ping_interface;

    std::shared_ptr<datagrams::xml_datagrams::XML_Parameter_Channel> _ping_parameter;
  public:
    fileinterfaces::PackageInfo<t_SimradDatagramType>
        _package_info_raw; ///< this can be RAW3 (EK80) or RAW0 (EK60)

    datagrams::RAW3
        _ping_data; ///< when implementing EK60, this must become a variant type (RAW3 or RAW0)
        

  public:
    SimradPingRawData(std::shared_ptr<SimradPingInterface<t_ifstream>>  ping_interface,
                      fileinterfaces::PackageInfo<t_SimradDatagramType> package_info_raw,
                      datagrams::RAW3                                   ping_data)
        : _ping_interface(std::move(ping_interface))
        , _package_info_raw(std::move(package_info_raw))
        , _ping_data(std::move(ping_data))
    {
    }
    ~SimradPingRawData() = default;

    void add_parameter(std::shared_ptr<datagrams::xml_datagrams::XML_Parameter_Channel> parameter)
    {
        _ping_parameter = std::move(parameter);
    }

    const datagrams::xml_datagrams::XML_Parameter_Channel& get_parameter() const
    {
        return *_ping_parameter;
    }

    SimradFileData& file_data()
    {
        return *_ping_interface->file_data(_package_info_raw.file_nr);
    }

    // ----- load skipped data -----
    datagrams::RAW3_datatypes::RAW3_DataVariant get_sample_data()
    {
        if (std::holds_alternative<datagrams::RAW3_datatypes::RAW3_DataSkipped>(_ping_data.sample_data()))
            return read_sample_data();
        
        return _ping_data.sample_data();
    }


    datagrams::RAW3_datatypes::RAW3_DataVariant read_sample_data()
    {
        return  _ping_data.read_skipped_sample_data(
            _ping_interface->get_active_stream(_package_info_raw.file_nr),
            _package_info_raw.file_pos);
    }

    void load_data()
    {
        _ping_data.sample_data() =  read_sample_data();
    }

    void release_data ()
    {
        _ping_data.sample_data() = datagrams::RAW3_datatypes::RAW3_DataSkipped();
    }
};

template<typename t_ifstream>
class SimradPing : public fileinterfaces::I_Ping
{
    std::string channel_id;
    double      timestamp;
    //std::string file_path;
    //size_t      ping_number;

    SimradPingRawData<t_ifstream> _raw;

  public:
    SimradPing(std::shared_ptr<SimradPingInterface<t_ifstream>>  ping_interface,
               fileinterfaces::PackageInfo<t_SimradDatagramType> package_info_raw,
               datagrams::RAW3                                   ping_data)
        : fileinterfaces::I_Ping("SimradPing")
        , _raw(std::move(ping_interface), std::move(package_info_raw), std::move(ping_data))
    {
        //substring of channel_id until the first \x00 character
        channel_id = _raw._ping_data.get_channel_id();
        channel_id = channel_id.substr(0, channel_id.find('\x00'));

        timestamp = _raw._package_info_raw.timestamp;
    }
    virtual ~SimradPing() = default;

    SimradPingRawData<t_ifstream>& raw() { return _raw; }

    SimradFileData& file_data()
    {
        return _raw.file_data();
    }

    // ----- accessors -----
    const std::string& get_channel_id() const { return channel_id; }
    double             get_timestamp() const { return timestamp; }
    //const std::string& get_file_path() const { return file_path; }
    //size_t             get_ping_number() const { return ping_number; }


    // ----- I_Ping interface -----
    size_t get_number_of_samples() const final { return _raw._ping_data.get_count(); }

    // void load_data() final { _raw.load_data(); }
    // void release_data() final { _raw.release_data(); }

    xt::xtensor<float, 2> get_sv(bool dB = false) final
    {
        auto                  sample_data = _raw.get_sample_data();
        xt::xtensor<float, 1> sv          = tools::helper::visit_variant(
            sample_data, [dB](auto& data) { return data.get_power(dB); });

        // convert sv to 2d xtensor and return
        return xt::view(sv, xt::newaxis(), xt::all());
    }

    xt::xtensor<float, 1> get_sv_stacked(bool dB = false) final
    {
        auto                  sample_data = _raw.get_sample_data();
        xt::xtensor<float, 1> sv          = tools::helper::visit_variant(
            sample_data, [dB](auto& data) { return data.get_power(dB); });

        // convert sv to 2d xtensor and return
        return sv;
    }

    xt::xtensor<float, 2> get_angle() final
    {
        auto                  sample_data = _raw.get_sample_data();
        xt::xtensor<float, 2> angle =
            tools::helper::visit_variant(sample_data, [](auto& data) { return data.get_angle(); });

        return angle;
    }
    //------ interface ------//
    void load_data() final { _raw.load_data(); }
    void release_data() final { _raw.release_data(); }
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping