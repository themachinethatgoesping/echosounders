// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawpingbottom.doc.hpp"

/* std includes */
#include <memory>
#include <vector>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../../filetemplates/datatypes/i_pingbottom.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"

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
    /// TODO: these functions should react on the BeamSelection ..
    xt::xtensor<size_t, 1> get_tx_sector_per_beam(
        [[maybe_unused]] const pingtools::BeamSelection& selection) override;

    std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector(
       [[maybe_unused]] const pingtools::BeamSelection& selection) override;

    // ----- I_PingCommon interface -----

    uint32_t get_number_of_beams() override;

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
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping