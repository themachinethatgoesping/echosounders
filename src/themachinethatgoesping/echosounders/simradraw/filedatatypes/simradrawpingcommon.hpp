// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawpingcommon.doc.hpp"

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
#include "../../filetemplates/datatypes/i_pingcommon.hpp"
#include "../datagrams.hpp"

#include "simradrawpingfiledata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {

template<typename t_ifstream>
class SimradRawPingCommon : virtual public filetemplates::datatypes::I_PingCommon
{
  protected:
    std::string class_name() const override { return "SimradRawPingCommon"; }
    // raw data
    using t_rawdata                       = SimradRawPingFileData<t_ifstream>;
    std::shared_ptr<t_rawdata> _file_data = std::make_shared<t_rawdata>();

  public:
    using t_base = filetemplates::datatypes::I_PingCommon;

    SimradRawPingCommon()
        : t_base()
    {
    }
    SimradRawPingCommon(std::shared_ptr<t_rawdata> file_data)
        : t_base()
        , _file_data(std::move(file_data))
    {
    }
    virtual ~SimradRawPingCommon() = default;

    // ----- i_pingcommon interface -----
    // bool has_tx_signal_parameters() const override
    // {
    //     return _file_data->has_any_of_datagram_types(
    //         { t_SimradRawDatagramIdentifier::RawRangeAndAngle,
    //           t_SimradRawDatagramIdentifier::WatercolumnDatagram });
    // }
    // bool has_tx_sector_information() const override
    // {
    //     return has_tx_signal_parameters();
    // }

    // const std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>&
    // get_tx_signal_parameters() override
    // {
    //     return file_data().get_sysinfos().get_tx_signal_parameters();
    // }

    // size_t get_number_of_tx_sectors() override
    // {
    //     return 1;
    // }

    const t_rawdata& file_data() const { return *_file_data; }
    t_rawdata&       file_data() { return *_file_data; }
    void set_file_data(std::shared_ptr<t_rawdata> file_data) { _file_data = std::move(file_data); }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));

        return printer;
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping