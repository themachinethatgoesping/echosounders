// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/em3000pingrawdata.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>

/* external library includes */
#include <boost/flyweight.hpp>
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
#include "../../pingtools/beamsampleselection.hpp"
#include "../em3000_datagrams.hpp"
#include "../filedatainterfaces/em3000datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatatypes {

template<typename t_ifstream>
class EM3000PingRawData : public filedatainterfaces::EM3000DatagramInterface<t_ifstream>
{
    using t_base = filedatainterfaces::EM3000DatagramInterface<t_ifstream>;
    // std::shared_ptr<datagrams::xml_datagrams::XML_Parameter_Channel> _ping_parameter;
    std::string_view get_name() const { return "EM3000PingRawData"; }

    // parameters (read when adding datagram infos)
    std::shared_ptr<datagrams::RuntimeParameters> _runtime_parameters =
        std::make_shared<datagrams::RuntimeParameters>();

  public:
    // filetemplates::datatypes::DatagramInfo_ptr<t_EM3000DatagramIdentifier, t_ifstream>
    //     _datagram_info_raw_data; ///< this can be RAW3 (EK80) or RAW0 (EK60)

    void set_runtime_parameters(std::shared_ptr<datagrams::RuntimeParameters> arg)
    {
        _runtime_parameters = std::move(arg);
    }
    const datagrams::RuntimeParameters& get_runtime_parameters() const
    {
        return *_runtime_parameters;
    }

    datagrams::WatercolumnDatagram read_merged_watercolumndatagram(bool skip_data = false)
    {
        auto& datagram_infos =
            this->_datagram_infos_by_type.at(t_EM3000DatagramIdentifier::WatercolumnDatagram);

        if (datagram_infos.empty())
            throw std::runtime_error(
                fmt::format("Error[EM3000PingRawData::read_merged_watercolumndatagram]: No water "
                            "column datagram in ping!"));

        auto datagram =
            datagram_infos.at(0)->template read_datagram_from_file<datagrams::WatercolumnDatagram>(
                skip_data);

        for (size_t i = 1; i < datagram_infos.size(); ++i)
        {
            datagram.append_from_stream(datagram_infos[i]->get_stream_and_seek());
        }

        return datagram;
    }

  public:
    EM3000PingRawData()
        : t_base("EM3000PingRawData")
    {
    }
    // EM3000PingRawData(filetemplates::datatypes::DatagramInfo_ptr<t_EM3000DatagramIdentifier,
    //                                                              t_ifstream>
    //                                                              datagram_info_raw_data,
    //                   datagrams::RAW3                                        ping_data)
    //     : _datagram_info_raw_data(std::move(datagram_info_raw_data))
    //     , _ping_data(std::move(ping_data))
    // {
    // }
    ~EM3000PingRawData() = default;

    /**
     * @brief Return the filestream associated with the first datagram of the specified type
     *
     * @param datagram_identifier
     * @return std::istream&
     */
    auto& get_ifs(t_EM3000DatagramIdentifier datagram_identifier) const
    {
        return this->_datagram_infos_by_type.at_const(datagram_identifier).at(0)->get_stream();
    }

    // I_PingBottom functions
    /**
     * @brief read XYZ for the bottom detection datagram
     *
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    algorithms::geoprocessing::datastructures::XYZ<1> read_xyz()
    {
        auto& datagram_infos =
            this->_datagram_infos_by_type.at(t_EM3000DatagramIdentifier::XYZDatagram);

        if (datagram_infos.empty())
            throw std::runtime_error(
                fmt::format("Error[EM3000PingRawData::read_xyz]: No XYZDatagram in ping!"));

        if (datagram_infos.size() > 1)
            throw std::runtime_error(
                fmt::format("Error[EM3000PingRawData::read_xyz]: More than one XYZDatagram in "
                            "ping!"));
        auto datagram =
            datagram_infos.at(0)->template read_datagram_from_file<datagrams::XYZDatagram>();

        return datagram.get_xyz();
    }

    /**
     * @brief read XYZ for the specified beams from the bottom detection datagram
     * Note: if the beam numbers from the beam selection exceed the number of beams in the
     * datagram, the corresponding XYZ values will be NaN
     *
     * @param bs beam selection
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    algorithms::geoprocessing::datastructures::XYZ<1> read_xyz(const pingtools::BeamSelection& bs)
    {
        auto& datagram_infos =
            this->_datagram_infos_by_type.at(t_EM3000DatagramIdentifier::XYZDatagram);

        if (datagram_infos.empty())
            throw std::runtime_error(
                fmt::format("Error[EM3000PingRawData::read_xyz]: No XYZDatagram in ping!"));

        if (datagram_infos.size() > 1)
            throw std::runtime_error(
                fmt::format("Error[EM3000PingRawData::read_xyz]: More than one XYZDatagram in "
                            "ping!"));
        auto datagram =
            datagram_infos.at(0)->template read_datagram_from_file<datagrams::XYZDatagram>();

        return datagram.get_xyz(bs.get_beam_numbers());
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));

        printer.register_section("Raw data infos");



        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping