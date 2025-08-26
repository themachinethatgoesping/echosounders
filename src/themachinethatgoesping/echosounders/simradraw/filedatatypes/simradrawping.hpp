// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawping.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include <themachinethatgoesping/tools/helper/variant.hpp>

#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include "../../filetemplates/datatypes/i_ping.hpp"
#include "../datagrams.hpp"
#include "simradrawpingbottom.hpp"
#include "simradrawpingcommon.hpp"
#include "simradrawpingfiledata.hpp"
#include "simradrawpingwatercolumn.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {

template<typename t_ifstream>
class SimradRawPing
    : public filetemplates::datatypes::I_Ping
    , public SimradRawPingCommon<t_ifstream>
{

    using t_base1 = filetemplates::datatypes::I_Ping;
    using t_base2 = SimradRawPingCommon<t_ifstream>;

    using type_DatagramInfo_ptr = typename SimradRawPingFileData<t_ifstream>::type_DatagramInfo_ptr;

    using t_base2::_file_data;
    std::string class_name() const override { return "SimradRawPing"; }

    SimradRawPingWatercolumn<t_ifstream> _watercolumn;

  public:
    SimradRawPing(const datagrams::RAW3& raw3_datagram)
        : t_base1()
        , t_base2(raw3_datagram)
        , _watercolumn(_file_data)
    //, _file_data(std::move(datagram_info_file_data), std::move(ping_data))
    {
        auto raw_channel_id = raw3_datagram.get_channel_id();
        auto channel_id     = std::string(raw_channel_id.substr(0, raw_channel_id.find('\x00')));
        this->set_channel_id(channel_id);
    }
    virtual ~SimradRawPing() = default;

    // size_t      get_file_nr() const { return _file_data._datagram_info_file_data->get_file_nr();
    // } std::string get_file_path() const
    // {
    //     return _file_data._datagram_info_file_data->get_file_path();
    // }

    // ----- I_Ping interface -----

    // ----- I_Ping interface -----
    using t_base2::file_data;

    void add_datagram_info(const type_DatagramInfo_ptr& datagram_info)
    {
        // update timestamp if it is much smaller or larger than the current one
        if (_timestamp < datagram_info->get_timestamp() - 1000 ||
            _timestamp > datagram_info->get_timestamp())
            _timestamp = datagram_info->get_timestamp();

        file_data().add_datagram_info(datagram_info);
    }

    // ----- bottom -----
    using t_base1::bottom;
    using t_base1::watercolumn;
    // SimradRawPingBottom<t_ifstream>&      bottom() override { return _bottom; }
    SimradRawPingWatercolumn<t_ifstream>& watercolumn() override { return _watercolumn; }

    // /**
    //  * @brief Compute volume backscattering strength (Sv) from raw data.
    //  *
    //  * This function calls: ping.file_data.get_sample_data().get_power(dB)
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
    // xt::xtensor<float, 2> get_sv(bool dB = false) const
    // {
    //     auto                  sample_data = _file_data.get_sample_data();
    //     xt::xtensor<float, 1> sv          = tools::helper::visit_variant(
    //         sample_data, [dB](auto& data) { return data.get_power(dB); });

    //     // convert sv to 2d xtensor and return
    //     return xt::view(sv, xt::newaxis(), xt::all());
    // }

    // /**
    //  * @brief Compute volume backscattering strength (Sv) from raw data.
    //  *
    //  * This function calls: ping.file_data.get_sample_data().get_power(dB)
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
    // xt::xtensor<float, 1> get_sv_stacked(bool dB = false)
    // {
    //     auto                  sample_data = _file_data.get_sample_data();
    //     xt::xtensor<float, 1> sv          = tools::helper::visit_variant(
    //         sample_data, [dB](auto& data) { return data.get_power(dB); });

    //     // convert sv to 2d xtensor and return
    //     return sv;
    // }

    // /**
    //  * @brief Returns the single target detection launch angle for each sample.
    //  *
    //  * This function calls: ping.file_data.get_sample_data().get_angle()
    //  *
    //  * @throws exception-object if angle data is not available for the specific datagram type
    //  *
    //  * @return xt::xtensor<float, 2>
    //  */
    // xt::xtensor<float, 2> get_angle()
    // {
    //     auto                  sample_data = _file_data.get_sample_data();
    //     xt::xtensor<float, 2> angle =
    //         tools::helper::visit_variant(sample_data, [](auto& data) { return data.get_angle();
    //         });

    //     return angle;
    // }

    // bool has_angle() const { return _file_data.has_angle(); }

    // virtual bool has_sv() const { return _file_data.has_power(); }

    // // ----- objectprinter -----
    // tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    // {
    //     tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

    //     printer.append(t_base::__printer__(float_precision, superscript_exponents));

    //     printer.register_section("SimradRaw ping infos");
    //     printer.register_string(
    //         "Sample data type",
    //         std::string(magic_enum::enum_name(_file_data._ping_data.get_data_type())));

    //     printer.register_section("Important members");
    //     printer.register_string("file_data", "SimradRawPingFileData");

    //     return printer;
    // }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping