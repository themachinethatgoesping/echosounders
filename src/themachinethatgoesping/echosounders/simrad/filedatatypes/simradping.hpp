// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradping.doc.hpp"

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
#include "../simrad_datagrams.hpp"
#include "simradpingrawdata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace filedatatypes {

template<typename t_ifstream>
class SimradPing : public filetemplates::datatypes::I_Ping
{
    SimradPingRawData<t_ifstream> _raw_data;

    using t_base = filetemplates::datatypes::I_Ping;

  public:
    SimradPing(filetemplates::datatypes::DatagramInfo_ptr<t_SimradDatagramIdentifier, t_ifstream>
                               datagram_info_raw_data,
               datagrams::RAW3 ping_data)
        : t_base("SimradPing")
        , _raw_data(std::move(datagram_info_raw_data), std::move(ping_data))
    {

        /* set i_ping parameters */
        // substring of channel_id until the first \x00 character
        this->_channel_id = _raw_data._ping_data.get_channel_id();
        this->_channel_id = this->_channel_id.substr(0, this->_channel_id.find('\x00'));

        this->_timestamp = _raw_data._datagram_info_raw_data->get_timestamp();
    }
    virtual ~SimradPing() = default;

    SimradPingRawData<t_ifstream>& raw_data() { return _raw_data; }

    using t_base::set_geolocation;
    void set_geolocation(navigation::datastructures::GeoLocationLatLon geolocation)
    {
        this->set_geolocation(this->get_channel_id(), std::move(geolocation));
    }

    size_t get_file_nr() const final { return _raw_data._datagram_info_raw_data->get_file_nr(); }
    std::string get_file_path() const final
    {
        return _raw_data._datagram_info_raw_data->get_file_path();
    }

    // ----- I_Ping interface -----
    using t_base::get_number_of_beams;
    using t_base::get_number_of_samples_per_beam;
    using t_base::get_beam_pointing_angles;

    xt::xtensor<uint16_t, 1> get_number_of_samples_per_beam() const final
    {
        return {uint16_t(_raw_data._ping_data.get_count())};
    }
    size_t                get_number_of_beams() const final { return 1; }
    xt::xtensor<float, 1> get_beam_pointing_angles() const final
    {
        return {0};
    }

    // void load_data() final { _raw_data.load_data(); }
    // void release_data() final { _raw_data.release_data(); }

    /**
     * @brief Compute volume backscattering strength (Sv) from raw data.
     *
     * This function calls: ping.raw_data.get_sample_data().get_power(dB)
     *
     * For single beam systems, this function returns the same value as get_sv_stacked (since there
     * is only one beam to stack) However, the return type is a 2D matrix with one column, to be
     * consistent with the multibeam case.
     *
     * @throws exception-object if power data is not available for the specific datagram type
     *
     * @param dB Output Sv in dB if true, or linear if false (default).
     * @return xt::xtensor<float, 2>
     */
    xt::xtensor<float, 2> get_sv(bool dB = false) final
    {
        auto                  sample_data = _raw_data.get_sample_data();
        xt::xtensor<float, 1> sv          = tools::helper::visit_variant(
            sample_data, [dB](auto& data) { return data.get_power(dB); });

        // convert sv to 2d xtensor and return
        return xt::view(sv, xt::newaxis(), xt::all());
    }

    /**
     * @brief Compute volume backscattering strength (Sv) from raw data.
     *
     * This function calls: ping.raw_data.get_sample_data().get_power(dB)
     *
     * For single beam systems, this function returns the same value as get_sv (since there is only
     * one beam to stack) However, the return type is a 1D vector opposed to a one-column 2D matrix
     * returned by get_sv
     *
     * @throws exception-object if power data is not available for the specific datagram type
     *
     * @param dB Output Sv in dB if true, or linear if false (default).
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 1> get_sv_stacked(bool dB = false) final
    {
        auto                  sample_data = _raw_data.get_sample_data();
        xt::xtensor<float, 1> sv          = tools::helper::visit_variant(
            sample_data, [dB](auto& data) { return data.get_power(dB); });

        // convert sv to 2d xtensor and return
        return sv;
    }

    /**
     * @brief Returns the single target detection launch angle for each sample.
     *
     * This function calls: ping.raw_data.get_sample_data().get_angle()
     *
     * @throws exception-object if angle data is not available for the specific datagram type
     *
     * @return xt::xtensor<float, 2>
     */
    xt::xtensor<float, 2> get_angle() final
    {
        auto                  sample_data = _raw_data.get_sample_data();
        xt::xtensor<float, 2> angle =
            tools::helper::visit_variant(sample_data, [](auto& data) { return data.get_angle(); });

        return angle;
    }

    bool has_angle() const final { return _raw_data.has_angle(); }

    virtual bool has_sv() const final { return _raw_data.has_power(); }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));

        printer.register_section("Simrad ping infos");
        printer.register_string(
            "Sample data type",
            std::string(magic_enum::enum_name(_raw_data._ping_data.get_data_type())));

        printer.register_section("Important members");
        printer.register_string("raw_data", "SimradPingRawData");

        return printer;
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping