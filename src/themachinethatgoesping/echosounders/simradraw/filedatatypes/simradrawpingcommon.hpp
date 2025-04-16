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
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

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
class SimradRawPingCommon
{
  protected:
    std::string class_name() const { return "SimradRawPingCommon"; }
    // raw data
    using t_rawdata = SimradRawPingFileData<t_ifstream>;
    std::shared_ptr<t_rawdata> _file_data;

  public:
    SimradRawPingCommon(const datagrams::RAW3& raw3_datagram)
        : _file_data(std::make_shared<t_rawdata>(raw3_datagram))
    {
    }
    SimradRawPingCommon(std::shared_ptr<t_rawdata> file_data)
        : _file_data(std::move(file_data))
    {
    }
    virtual ~SimradRawPingCommon() = default;

    void beam_selection_must_be_one(std::string_view                      method_name,
                                    const pingtools::BeamSampleSelection& selection) const
    {
        if (selection.get_number_of_beams() == 1)
            if (selection.get_beam_numbers()[0] == 0)
                return;

        throw std::runtime_error(fmt::format(
            "{}: SimradRaw functions do not support beam selections yet!", __func__, method_name));
    }

    const t_rawdata& file_data() const { return *_file_data; }
    t_rawdata&       file_data() { return *_file_data; }
    void set_file_data(std::shared_ptr<t_rawdata> file_data) { _file_data = std::move(file_data); }

    // ----- objectprinter -----
    // tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    // {
    //     tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

    //     return printer;
    // }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping