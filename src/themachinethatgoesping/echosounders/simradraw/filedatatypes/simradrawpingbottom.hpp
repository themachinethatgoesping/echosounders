// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawpingbottom.doc.hpp"

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

#include "../../filetemplates/datatypes/i_pingbottom.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"

#include "simradrawpingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {

template<typename t_ifstream>
class SimradRawPingBottom
    : public filetemplates::datatypes::I_PingBottom
    , public SimradRawPingCommon<t_ifstream>
{
  public:
    using t_base1 = filetemplates::datatypes::I_PingBottom;
    using t_base2 = SimradRawPingCommon<t_ifstream>;

    using t_base2::_file_data;
    using typename t_base2::t_rawdata;

  protected:
    std::string class_name() const override { return "SimradRawPingBottom"; }

  public:
    SimradRawPingBottom(std::shared_ptr<t_rawdata> file_data)
        : t_base1()
        , t_base2(std::move(file_data))
    {
    }
    virtual ~SimradRawPingBottom() = default;

    // --- sector infos ---
    xt::xtensor<size_t, 1> get_tx_sector_per_beam() override
    {
        throw not_implemented(__func__, class_name());
    }

    std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector() override
    {
        throw not_implemented(__func__, class_name());
    }

    // ----- I_PingCommon interface -----

    uint32_t get_number_of_beams() override
    {
        if (has_xyz())
            return 1;

        if (has_two_way_travel_times())
            return 1;

        return 0;
    }

    // ----- I_PingBottom interface -----
    // using t_base1::has_xyz;
    using t_base2::file_data;

    bool has_beam_crosstrack_angles() const override { return has_two_way_travel_times(); }

    bool has_xyz() const override { return false; }

    virtual bool has_two_way_travel_times() const { return false; }

    // Not yet implemented
    // algorithms::geoprocessing::datastructures::XYZ<1> get_xyz(
    //     const pingtools::BeamSelection& selection) override
    // {
    //     return _file_data->read_xyz(selection);
    // }

    // Not yet implemented
    // xt::xtensor<float, 1> get_two_way_travel_times(
    //     [[maybe_unused]] const pingtools::BeamSelection& selection) override
    // {
    // }

    // Not yet implemented
    // xt::xtensor<float, 1> get_beam_crosstrack_angles(
    //     const pingtools::BeamSelection& selection) override
    // {
    //     auto datagram = file_data().template read_first_datagram<datagrams::RawRangeAndAngle>();

    //     return datagram.get_beam_crosstrack_angles(selection.get_beam_numbers());
    // }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        printer.append(t_base1::__printer__(float_precision));

        // printer.register_section("SimradRaw ping infos");

        // printer.register_string(
        //     "Sample data type",
        //     std::string(magic_enum::enum_name(_file_data->_ping_data.get_data_type())));

        // printer.register_section("Important members");
        // printer.register_string("file_data", "SimradRawPingFileData");

        return printer;
    }
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping