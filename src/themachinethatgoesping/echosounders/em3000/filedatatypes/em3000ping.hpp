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
        return _raw_data.at(transducer_id);
    }

    std::map<std::string, EM3000PingRawData<t_ifstream>>& raw_data() { return _raw_data; }

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
        for (auto& [key,raw] : _raw_data)
            raw.load_datagrams(skip_data);
    }

    std::vector<std::string> get_transducer_ids() const override
    {
        std::vector<std::string> transducer_ids;

        /* return the keys from _geolocations */
        for (const auto& [k, v] : _raw_data)
            transducer_ids.push_back(k);

        return transducer_ids;
    }

    // ----- I_Ping interface -----
    // size_t get_number_of_samples() const final { return _raw_data._ping_data.get_count(); }

    // void load_data() final { _raw_data.load_data(); }
    // void release_data() final { _raw_data.release_data(); }

    // /**
    //  * @brief Compute volume backscattering strength (Sv) from raw data.
    //  *
    //  * This function calls: ping.raw_data.get_sample_data().get_power(dB)
    //  *
    //  * For single beam systems, this function returns the same value as get_sv_stacked (since
    //  there
    //  * is only one beam to stack) However, the return type is a 2D matrix with one column, to be
    //  * consistent with the multibeam case.
    //  *
    //  * @throws exception-object if power data is not available for the specific datagram type
    //  *
    //  * @param dB Output Sv in dB if true, or linear if false (default).
    //  * @return xt::xtensor<float, 2>
    //  */
    // xt::xtensor<float, 2> get_sv(bool dB = false) final
    // {
    //     auto                  sample_data = _raw_data.get_sample_data();
    //     xt::xtensor<float, 1> sv          = tools::helper::visit_variant(
    //         sample_data, [dB](auto& data) { return data.get_power(dB); });

    //     // convert sv to 2d xtensor and return
    //     return xt::view(sv, xt::newaxis(), xt::all());
    // }

    // /**
    //  * @brief Compute volume backscattering strength (Sv) from raw data.
    //  *
    //  * This function calls: ping.raw_data.get_sample_data().get_power(dB)
    //  *
    //  * For single beam systems, this function returns the same value as get_sv (since there is
    //  only
    //  * one beam to stack) However, the return type is a 1D vector opposed to a one-column 2D
    //  matrix
    //  * returned by get_sv
    //  *
    //  * @throws exception-object if power data is not available for the specific datagram type
    //  *
    //  * @param dB Output Sv in dB if true, or linear if false (default).
    //  * @return xt::xtensor<float, 1>
    //  */
    // xt::xtensor<float, 1> get_sv_stacked(bool dB = false) final
    // {
    //     auto                  sample_data = _raw_data.get_sample_data();
    //     xt::xtensor<float, 1> sv          = tools::helper::visit_variant(
    //         sample_data, [dB](auto& data) { return data.get_power(dB); });

    //     // convert sv to 2d xtensor and return
    //     return sv;
    // }

    // /**
    //  * @brief Returns the single target detection launch angle for each sample.
    //  *
    //  * This function calls: ping.raw_data.get_sample_data().get_angle()
    //  *
    //  * @throws exception-object if angle data is not available for the specific datagram type
    //  *
    //  * @return xt::xtensor<float, 2>
    //  */
    // xt::xtensor<float, 2> get_angle() final
    // {
    //     auto                  sample_data = _raw_data.get_sample_data();
    //     xt::xtensor<float, 2> angle =
    //         tools::helper::visit_variant(sample_data, [](auto& data) { return data.get_angle();
    //         });

    //     return angle;
    // }

    // bool has_angle() const final { return _raw_data.has_angle(); }

    // virtual bool has_sv() const final { return _raw_data.has_power(); }

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