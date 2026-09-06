// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kpingwatercolumn.doc.hpp"

/* std includes */
#include <memory>

#include <fmt/format.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datatypes/i_pingwatercolumn.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"

#include "s7kpingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {

/**
 * @brief Water column accessor of an s7k ping.
 *
 * @note The water-column processing functions are not implemented yet; they inherit the base
 * I_PingWatercolumn "not implemented" behavior. This class currently only provides the structure so
 * it can be filled in in a later step.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KPingWatercolumn
    : public filetemplates::datatypes::I_PingWatercolumn
    , public S7KPingCommon<t_ifstream>
{
  public:
    using t_base1 = filetemplates::datatypes::I_PingWatercolumn;
    using t_base2 = S7KPingCommon<t_ifstream>;

    using t_base2::_file_data;
    using typename t_base2::t_rawdata;

  protected:
    std::string class_name() const override { return "S7KPingWatercolumn"; }

  public:
    S7KPingWatercolumn(std::shared_ptr<t_rawdata> file_data)
        : t_base1()
        , t_base2(std::move(file_data))
    {
    }
    virtual ~S7KPingWatercolumn() = default;

    // TODO: implement the water-column accessors (get_number_of_beams, get_amplitudes,
    // get_beam_crosstrack_angles, ...).

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        // Do NOT append the I_PingWatercolumn base printer here: it queries the water-column
        // accessors (get_number_of_tx_sectors, ...) which are not implemented yet and would throw.
        printer.register_string("status", "not implemented yet");

        return printer;
    }
};

} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
