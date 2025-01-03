// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallpingbottom.doc.hpp"

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
#include <xtensor/xindex_view.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datatypes/i_pingbottom.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"

#include "kongsbergallpingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {

template<typename t_ifstream>
class KongsbergAllPingBottom
    : public filetemplates::datatypes::I_PingBottom
    , public KongsbergAllPingCommon<t_ifstream>
{
  public:
    using t_base1 = filetemplates::datatypes::I_PingBottom;
    using t_base2 = KongsbergAllPingCommon<t_ifstream>;

    using t_base2::_file_data;
    using typename t_base2::t_rawdata;

  protected:
    std::string class_name() const override { return "KongsbergAllPingBottom"; }

  public:
    KongsbergAllPingBottom(std::shared_ptr<t_rawdata> file_data)
        : t_base1()
        , t_base2(std::move(file_data))
    {
    }
    virtual ~KongsbergAllPingBottom() = default;

    // --- sector infos ---
    bool has_tx_signal_parameters() const override
    {
        return _file_data->has_any_of_datagram_types(
            { t_KongsbergAllDatagramIdentifier::RawRangeAndAngle,
              t_KongsbergAllDatagramIdentifier::WatercolumnDatagram });
    }
    bool has_number_of_tx_sectors() const override { return has_tx_signal_parameters(); }

    std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
    get_tx_signal_parameters() override
    {
        return file_data().get_sysinfos().get_tx_signal_parameters();
    }

    size_t get_number_of_tx_sectors() override
    {
        return file_data().get_sysinfos().get_tx_signal_parameters().size();
    }

    xt::xtensor<size_t, 1> get_tx_sector_per_beam(
        const pingtools::BeamSelection& selection) override
    {
        return xt::index_view(file_data().get_wcinfos().get_transmit_sector_numbers(),
                              selection.get_beam_numbers());
    }

    std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector(
        const pingtools::BeamSelection& selection) override
    {
        std::vector<std::vector<size_t>> beam_numbers_per_tx_sector;
        beam_numbers_per_tx_sector.resize(get_number_of_tx_sectors());

        auto sector_per_beam = get_tx_sector_per_beam(selection);

        for (unsigned int i = 0; i < sector_per_beam.size(); ++i)
        {
            if (sector_per_beam[i] >= beam_numbers_per_tx_sector.size())
                throw std::runtime_error(
                    fmt::format("Invalid transmit sector number: {}", sector_per_beam[i]));

            beam_numbers_per_tx_sector[sector_per_beam[i]].push_back(i);
        }

        return beam_numbers_per_tx_sector;
    }

    // ----- I_PingCommon interface -----
    void load(bool force = false) override { _file_data->load_sys(force); }
    void release() override { _file_data->release_sys(); }
    bool loaded() override { return _file_data->sys_loaded(); }

    uint32_t get_number_of_beams() override
    {
        if (has_xyz())
            return file_data()
                .template read_first_datagram<datagrams::XYZDatagram>()
                .get_number_of_beams();

        if (has_two_way_travel_times())
            return file_data()
                .template read_first_datagram<datagrams::RawRangeAndAngle>()
                .get_number_of_receiver_beams();

        return 0;
    }

    // ----- I_PingBottom interface -----
    // using t_base1::has_xyz;
    using t_base2::file_data;

    bool has_beam_crosstrack_angles() const override { return has_two_way_travel_times(); }

    bool has_xyz() const override
    {
        return file_data()
                   .get_datagram_infos_by_type(t_KongsbergAllDatagramIdentifier::XYZDatagram)
                   .size() > 0;
    }

    virtual bool has_two_way_travel_times() const
    {
        return file_data()
                   .get_datagram_infos_by_type(t_KongsbergAllDatagramIdentifier::RawRangeAndAngle)
                   .size() > 0;
    }

    algorithms::geoprocessing::datastructures::XYZ<1> get_xyz(
        const pingtools::BeamSelection& selection) override
    {
        auto xyz = _file_data->read_xyz(selection);
    }

    algorithms::geoprocessing::datastructures::XYZ<1> get_xyz_raw(
        const pingtools::BeamSelection& selection) override
    {
        return _file_data->read_xyz(selection);
    }


    algorithms::geoprocessing::datastructures::XYZ<1> get_xyz_raw()
    {
        return get_xyz_raw(get_beam_selection_all());
    }

    xt::xtensor<float, 1> get_two_way_travel_times(
        [[maybe_unused]] const pingtools::BeamSelection& selection) override
    {
        auto datagram = file_data().template read_first_datagram<datagrams::RawRangeAndAngle>();

        return datagram.get_two_way_travel_times(selection.get_beam_numbers());
    }

    xt::xtensor<float, 1> get_beam_crosstrack_angles(
        const pingtools::BeamSelection& selection) override
    {
        auto datagram = file_data().template read_first_datagram<datagrams::RawRangeAndAngle>();

        return datagram.get_beam_crosstrack_angles(selection.get_beam_numbers());
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base1::__printer__(float_precision, superscript_exponents));

        // printer.register_section("KongsbergAll ping infos");

        // printer.register_string(
        //     "Sample data type",
        //     std::string(magic_enum::enum_name(_file_data->_ping_data.get_data_type())));

        // printer.register_section("Important members");
        // printer.register_string("file_data", "KongsbergAllPingFileData");

        return printer;
    }
};

}
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping