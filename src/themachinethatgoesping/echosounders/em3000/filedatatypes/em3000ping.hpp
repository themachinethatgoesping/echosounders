// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/em3000ping.doc.hpp"

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
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include "../../filetemplates/datatypes/i_ping.hpp"
#include "../em3000_datagrams.hpp"
#include "em3000pingrawdata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatatypes {

template<typename t_ifstream>
class EM3000Ping : public filetemplates::datatypes::I_Ping
{
    // file nr and path of primary file
    size_t      _file_nr;
    std::string _file_path;

    // flags

    // raw data
    // key = transducer_id ("TRX-'system_serial_number'")
    std::map<std::string, EM3000PingRawData<t_ifstream>> _raw_data;

    using t_base                = filetemplates::datatypes::I_Ping;
    using type_DatagramInfo_ptr = typename EM3000PingRawData<t_ifstream>::type_DatagramInfo_ptr;

  public:
    EM3000Ping(size_t                                   file_nr,
               std::string                              file_path,
               const datagrams::InstallationParameters& param)
        : t_base("EM3000Ping")
        , _file_nr(file_nr)
        , _file_path(std::move(file_path))
    //, _raw_data(std::move(datagram_info_raw_data), std::move(ping_data))
    {
        /* set i_ping parameters */
        set_channel_id(param.build_channel_id());

        // this->_timestamp = _raw_data._datagram_info_raw_data->get_timestamp();
    }
    virtual ~EM3000Ping() = default;

    EM3000PingRawData<t_ifstream>& raw_data(const std::string& transducer_id)
    {
        auto it = _raw_data.find(transducer_id);
        if (it == _raw_data.end())
            throw std::runtime_error(fmt::format("Transducer ID '{}' not found", transducer_id));

        return it->second;
    }

    EM3000PingRawData<t_ifstream>& raw_data() { return raw_data(get_transducer_id()); }

    const EM3000PingRawData<t_ifstream>& get_raw_data(const std::string& transducer_id) const
    {
        auto it = _raw_data.find(transducer_id);
        if (it == _raw_data.end())
            throw std::runtime_error(fmt::format("Transducer ID '{}' not found", transducer_id));

        return it->second;
    }

    const EM3000PingRawData<t_ifstream>& get_raw_data() const
    {
        return get_raw_data(get_transducer_id());
    }

    size_t      get_file_nr() const final { return _file_nr; }
    std::string get_file_path() const final { return _file_path; }

    void add_datagram_info(const type_DatagramInfo_ptr& datagram_info,
                           uint16_t                     system_serial_number)
    {
        // update timestamp if it is much smaller or larger than the current one
        if (_timestamp < datagram_info->get_timestamp() - 1000 ||
            _timestamp > datagram_info->get_timestamp())
            _timestamp = datagram_info->get_timestamp();

        _raw_data[fmt::format("TRX-{}", system_serial_number)].add_datagram_info(datagram_info);
    }

    void add_datagram_info(const type_DatagramInfo_ptr& datagram_info)
    {
        // update timestamp if it is much smaller or larger than the current one
        if (_timestamp < datagram_info->get_timestamp() - 1000 ||
            _timestamp > datagram_info->get_timestamp())
            _timestamp = datagram_info->get_timestamp();

        for (auto& [k, v] : _raw_data)
            v.add_datagram_info(datagram_info);
    }

    void set_runtime_parameters(std::shared_ptr<datagrams::RuntimeParameters> runtime_parameters)
    {
        for (auto& [k, v] : _raw_data)
        {
            v.set_runtime_parameters(runtime_parameters);
        }
    }

    void load_datagrams(bool skip_data = true)
    {
        for (auto& [key, raw] : _raw_data)
            raw.load_datagrams(skip_data);
    }

    std::set<std::string> get_transducer_ids() const override
    {
        std::set<std::string> transducer_ids;

        /* return the keys from _geolocations */
        for (const auto& [k, v] : _raw_data)
            transducer_ids.insert(k);

        return transducer_ids;
    }

    // ----- I_Ping interface -----
    using t_base::get_beam_pointing_angles;
    using t_base::get_number_of_beams;
    using t_base::get_number_of_samples_per_beam;
    using t_base::get_sv;
    using t_base::get_sv_stacked;

    size_t get_number_of_beams() const final
    {
        size_t number_of_beams = 0;
        for (const auto& [k, v] : _raw_data)
            number_of_beams += v.get_number_of_beams();

        return number_of_beams;
    }
    size_t get_number_of_beams(const std::string& transducer_id) const final
    {
        return get_raw_data(transducer_id).get_beam_pointing_angles().size();
    }

    xt::xtensor<float, 1> get_beam_pointing_angles() const final
    {
        auto   beam_pointing_angles = xt::xtensor<float, 1>::from_shape({ get_number_of_beams() });
        size_t bn                   = 0;

        for (const auto& [k, v] : _raw_data)
        {
            size_t bn_end                                         = bn + v.get_number_of_beams();
            xt::view(beam_pointing_angles, xt::range(bn, bn_end)) = v.get_beam_pointing_angles();
            bn                                                    = bn_end;
        }

        return beam_pointing_angles;
    }
    xt::xtensor<float, 1> get_beam_pointing_angles(const std::string& transducer_id) const final
    {
        return get_raw_data(transducer_id).get_beam_pointing_angles();
    }
    xt::xtensor<float, 1> get_beam_pointing_angles(
        const pingtools::PingSampleSelection& selection) const final
    {
        auto beam_pointing_angles =
            xt::xtensor<float, 1>::from_shape({ selection.get_number_of_beams() });
        size_t bn = 0;

        for (const auto& [transducer_id, bss] : selection.get_sample_selections())
        {
            size_t bn_end = bn + bss.get_number_of_beams();

            auto it = _raw_data.find(transducer_id);
            if (it != _raw_data.end())
            {
                xt::view(beam_pointing_angles, xt::range(bn, bn_end)) =
                    it->second.get_beam_pointing_angles(bss);
            }
            else
            {
                xt::view(beam_pointing_angles, xt::range(bn, bn_end))
                    .fill(std::numeric_limits<float>::quiet_NaN());
            }

            bn = bn_end;
        }

        return beam_pointing_angles;
    }

    xt::xtensor<uint16_t, 1> get_number_of_samples_per_beam(
        const std::string& transducer_id) const final
    {
        return get_raw_data(transducer_id).get_number_of_samples_per_beam();
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));

        // printer.register_section("EM3000 ping infos");

        // printer.register_string(
        //     "Sample data type",
        //     std::string(magic_enum::enum_name(_raw_data._ping_data.get_data_type())));

        // printer.register_section("Important members");
        // printer.register_string("raw_data", "EM3000PingRawData");

        return printer;
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping