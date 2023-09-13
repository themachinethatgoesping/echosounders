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
#include <themachinethatgoesping/tools/helper/defaultsharedpointermap.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include "../../filetemplates/datatypes/i_ping.hpp"
#include "../em3000_datagrams.hpp"

#include "em3000pingbottom.hpp"
#include "em3000pingcommon.hpp"
#include "em3000pingwatercolumn.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatatypes {

template<typename t_ifstream>
class EM3000Ping
    : public filetemplates::datatypes::I_Ping
    , public EM3000PingCommon<t_ifstream>
{
    // file nr and path of primary file
    size_t      _file_nr;
    std::string _file_path;

    EM3000PingBottom<t_ifstream>      _bottom;
    EM3000PingWatercolumn<t_ifstream> _watercolumn;

  public:
    using t_base0 =
        filetemplates::datatypes::I_PingCommon; // this is the common ancestor which is virtually
                                                // inherited by base1 and base2
    using t_base1               = filetemplates::datatypes::I_Ping;
    using t_base2               = EM3000PingCommon<t_ifstream>;
    using type_DatagramInfo_ptr = typename EM3000PingRawData<t_ifstream>::type_DatagramInfo_ptr;

    // select virtual overrides
    using t_base1::set_channel_id;

  protected:
    using t_base0::register_feature;
    using t_base2::_raw_data;
    using typename t_base2::t_rawdata;

  public:
    EM3000Ping(size_t                                   file_nr,
               std::string                              file_path,
               const datagrams::InstallationParameters& param)
        : t_base0("EM3000Ping")
        , t_base1()
        , t_base2()
        , _file_nr(file_nr)
        , _file_path(std::move(file_path))
        , _bottom(_raw_data)
        , _watercolumn(_raw_data)
    {
        /* set i_ping parameters */
        set_channel_id(param.build_channel_id());
    }
    virtual ~EM3000Ping() = default;

    /**
     * @brief Provide a deep copy of the ping object (deep copy raw_data shared pointer)
     *
     * @param other
     * @return EM3000Ping<t_ifstream>
     */
    EM3000Ping<t_ifstream> deep_copy()
    {
        EM3000Ping<t_ifstream> ping = *this;

        // copy the raw_data shared pointer and set it in the bottom and watercolumn objects
        ping.set_raw_data(std::make_shared<t_rawdata>(*_raw_data));
        ping.bottom().set_raw_data(ping._raw_data);
        ping.watercolumn().set_raw_data(ping._raw_data);

        return ping;
    }

    size_t      get_file_nr() const final { return _file_nr; }
    std::string get_file_path() const final { return _file_path; }

    void add_datagram_info(const type_DatagramInfo_ptr& datagram_info)
    {
        // update timestamp if it is much smaller or larger than the current one
        if (_timestamp < datagram_info->get_timestamp() - 1000 ||
            _timestamp > datagram_info->get_timestamp())
            _timestamp = datagram_info->get_timestamp();

        _raw_data->add_datagram_info(datagram_info);
    }

    void set_runtime_parameters(std::shared_ptr<datagrams::RuntimeParameters> runtime_parameters)
    {
        _raw_data->set_runtime_parameters(runtime_parameters);
    }

    // ----- I_Ping interface -----
    using t_base2::raw_data;

    // size_t get_number_of_beams() const final {
    //     return _raw_data->get_number_of_beams();
    // }

    // xt::xtensor<float, 1> get_beam_crosstrack_angles() const final
    // {
    //     return raw_data().get_beam_crosstrack_angles();
    // }

    // xt::xtensor<float, 1> get_beam_crosstrack_angles(
    //     const pingtools::BeamSampleSelection& selection) const final
    // {
    //     return raw_data().get_beam_crosstrack_angles(selection);
    // }

    // xt::xtensor<uint16_t, 1> get_number_of_samples_per_beam() const final
    // {
    //     return _raw_data->get_number_of_samples_per_beam();
    // }
    // xt::xtensor<uint16_t, 1> get_number_of_samples_per_beam(
    //     const pingtools::BeamSampleSelection& selection)
    // {
    //     return _raw_data->get_number_of_samples_per_beam(selection);
    // }

    // ----- bottom -----
    using t_base1::bottom;
    using t_base1::watercolumn;
    EM3000PingBottom<t_ifstream>&      bottom() override { return _bottom; }
    EM3000PingWatercolumn<t_ifstream>& watercolumn() override { return _watercolumn; }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base1::__printer__(float_precision));
        // printer.append(t_base1::__printer__(float_precision));

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
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping