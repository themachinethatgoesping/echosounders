// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallpingfiledata.doc.hpp"

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
#include "../../filetemplates/datatypes/i_pingfiledata.hpp"
#include "../../pingtools/beamsampleselection.hpp"
#include "../datagrams.hpp"
#include "../filedatainterfaces/kongsbergalldatagraminterface.hpp"

#include "_sub/systeminformation.hpp"
#include "_sub/watercolumninformation.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {

template<typename t_ifstream>
class KongsbergAllPingFileData
    : public filetemplates::datatypes::I_PingFileData
    , public filedatainterfaces::KongsbergAllDatagramInterface<t_ifstream>
{
    using t_base1 = filetemplates::datatypes::I_PingFileData;
    using t_base2 = filedatainterfaces::KongsbergAllDatagramInterface<t_ifstream>;

  private:
    std::shared_ptr<_sub::WaterColumnInformation> _watercolumninformation;
    std::shared_ptr<_sub::SystemInformation>      _systeminformation;

  public:
    void load_wci(bool force = false)
    {
        if (wci_loaded() && !force)
            return;

        _watercolumninformation =
            std::make_shared<_sub::WaterColumnInformation>(read_merged_watercolumndatagram(true));
    }
    void load_sys(bool force = false)
    {
        if (sys_loaded() && !force)
            return;

        if (has_datagram_type<datagrams::RawRangeAndAngle>())
            _systeminformation =
                std::make_shared<_sub::SystemInformation>(read_first_datagram<datagrams::RawRangeAndAngle>());
                
        else if (has_datagram_type<datagrams::WatercolumnDatagram>())
            _systeminformation =
                std::make_shared<_sub::SystemInformation>(get_wcinfos());
    }
    void release_wci() { _watercolumninformation.reset(); }
    void release_sys() { _systeminformation.reset(); }
    bool wci_loaded() { return _watercolumninformation != nullptr; }
    bool sys_loaded() { return _systeminformation != nullptr; }

    const _sub::WaterColumnInformation& get_wcinfos()
    {
        load_wci();

        return *_watercolumninformation;
    }

    const _sub::SystemInformation& get_sysinfos()
    {
        load_sys();

        return *_systeminformation;
    }

  public:

    datagrams::WatercolumnDatagram read_merged_watercolumndatagram(bool skip_data = false)
    {
        auto& datagram_infos =
            this->_datagram_infos_by_type.at(t_KongsbergAllDatagramIdentifier::WatercolumnDatagram);

        if (datagram_infos.empty())
            throw std::runtime_error(fmt::format(
                "Error[KongsbergAllPingFileData::read_merged_watercolumndatagram]: No water "
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

  protected:
    // std::shared_ptr<datagrams::xml_datagrams::XML_Parameter_Channel> _ping_parameter;
    std::string class_name() const override { return "KongsbergAllPingFileData"; }

  public:
    KongsbergAllPingFileData()
        : t_base1()
        , t_base2()
    {
    }

    ~KongsbergAllPingFileData() = default;

    /**
     * @brief Return the filestream associated with the first datagram of the specified type
     *
     * @param datagram_identifier
     * @return std::istream&
     */
    auto& get_ifs(t_KongsbergAllDatagramIdentifier datagram_identifier) const
    {
        return this->_datagram_infos_by_type.at_const(datagram_identifier).at(0)->get_stream();
    }

    template<typename t_datagram>
    auto has_datagram_type()
    {
        auto& datagram_infos = this->_datagram_infos_by_type.at(t_datagram::DatagramIdentifier);

        return !datagram_infos.empty();
    }

    template<typename t_datagram>
    auto read_first_datagram()
    {
        auto& datagram_infos = this->_datagram_infos_by_type.at(t_datagram::DatagramIdentifier);

        if (datagram_infos.empty())
            throw std::runtime_error(fmt::format(
                "Error[KongsbergAllPingFileData::read_datagram]: No {} datagram in ping!",
                datagram_identifier_to_string(t_datagram::DatagramIdentifier)));

        return datagram_infos.at(0)->template read_datagram_from_file<t_datagram>();
    }

    // I_PingBottom functions
    /**
     * @brief read XYZ for the bottom detection datagram
     *
     * @return algorithms::geoprocessing::datastructures::XYZ<1>
     */
    algorithms::geoprocessing::datastructures::XYZ<1> read_xyz()
    {
        auto datagram = read_first_datagram<datagrams::XYZDatagram>();

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
        auto datagram = read_first_datagram<datagrams::XYZDatagram>();

        return datagram.get_xyz(bs.get_beam_numbers());
    }

    // ----- I_PingFileData Interface -----

    std::vector<size_t> get_file_numbers() const final
    {
        std::vector<size_t> fnr     = { get_primary_file_nr() };
        std::set<size_t>    fnr_set = { get_primary_file_nr() };

        for (const auto& datagram_info : this->_datagram_infos_all)
        {
            auto nr = datagram_info->get_file_nr();
            if (!fnr_set.contains(nr))
            {
                fnr.push_back(nr);
                fnr_set.insert(nr);
            }
        }

        return fnr;
    }
    std::string get_primary_file_path() const final
    {
        must_have_datagrams("get_primary_file_path");

        return this->_datagram_infos_all.at(0)->file_nr_to_file_path(get_primary_file_nr());
    }
    std::vector<std::string> get_file_paths() const final
    {
        must_have_datagrams("get_file_paths");

        auto fnrs = get_file_numbers();

        std::vector<std::string> fps;

        for (const auto& fnr : fnrs)
        {
            fps.push_back(this->_datagram_infos_all.at(0)->file_nr_to_file_path(fnr));
        }

        return fps;
    }

    void must_have_datagrams(std::string_view method_name) const
    {
        if (this->_datagram_infos_all.empty())
            throw std::runtime_error(fmt::format(
                "Error[KongsbergAllPingFileData::{}]: No datagram in ping!", method_name));
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        printer.append(t_base1::__printer__(float_precision));
        printer.append(t_base2::__printer__(float_precision));

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