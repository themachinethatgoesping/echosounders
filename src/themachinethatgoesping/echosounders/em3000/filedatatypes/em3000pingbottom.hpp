// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/em3000pingbottom.doc.hpp"

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

#include "../em3000_datagrams.hpp"
#include "../em3000_types.hpp"

#include "em3000pingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatatypes {

template<typename t_ifstream>
class EM3000PingBottom
    : public filetemplates::datatypes::I_PingBottom
    , public EM3000PingCommon<t_ifstream>
{
  public:
    using t_base0 = filetemplates::datatypes::I_PingCommon;
    using t_base1 = filetemplates::datatypes::I_PingBottom;
    using t_base2 = EM3000PingCommon<t_ifstream>;

    using t_base2::_raw_data;
    using typename t_base2::t_rawdata;

  public:
    EM3000PingBottom(std::shared_ptr<t_rawdata> raw_data)
        : t_base0("EM3000PingBottom") // necessary because of virtual inheritance
        //, t_base1("EM3000PingBottom"),
        , t_base2(std::move(raw_data))
    {
    }
    virtual ~EM3000PingBottom() = default;

    // ----- I_PingBottom interface -----
    using t_base1::has_xyz;
    using t_base2::raw_data;

    bool has_xyz() const override
    {
        return raw_data()
                   .get_datagram_infos_by_type(t_EM3000DatagramIdentifier::XYZDatagram)
                   .size() > 0;
    }

    virtual bool has_two_way_travel_times() const
    {
        return raw_data()
                   .get_datagram_infos_by_type(t_EM3000DatagramIdentifier::WaterColumnDatagram)
                   .size() > 0;
    }

    algorithms::geoprocessing::datastructures::XYZ<1> get_xyz() const override
    {
        return _raw_data->read_xyz();
    }

    algorithms::geoprocessing::datastructures::XYZ<1> get_xyz(
        const pingtools::BeamSampleSelection& selection) const override
    {
        return _raw_data->read_xyz(selection);
    }
    /**
     * @brief Get the two way travel times of the bottom detection samples
     *
     * @return xt::xtensor<float, 1>
     */
    virtual xt::xtensor<float, 1> get_two_way_travel_times() const
    {
        xt::xtensor<float, 1> twtt = _raw_data->get_detected_range_in_samples();

        twtt *= _raw_data->get_sample_interval();
    }

    /**
     * @brief Get the two way travel times of the bottom detection samples
     *
     * @return xt::xtensor<float, 1>
     */
    virtual xt::xtensor<float, 1> get_two_way_travel_times(
        [[maybe_unused]] const pingtools::BeamSelection& selection) const
    {
        throw not_implemented(__func__, this->get_name());
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base1::__printer__(float_precision));

        // printer.register_section("EM3000 ping infos");

        // printer.register_string(
        //     "Sample data type",
        //     std::string(magic_enum::enum_name(_raw_data->_ping_data.get_data_type())));

        // printer.register_section("Important members");
        // printer.register_string("raw_data", "EM3000PingRawData");

        return printer;
    }
};

}
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping