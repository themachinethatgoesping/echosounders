// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kping.doc.hpp"

/* std includes */
#include <memory>

#include <fmt/format.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include "../../filetemplates/datatypes/i_ping.hpp"
#include "../datagrams.hpp"

#include "s7kpingbottom.hpp"
#include "s7kpingcommon.hpp"
#include "s7kpingwatercolumn.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {

/**
 * @brief A single ping of an s7k file. Groups all datagrams (sonar settings, bathymetry, water
 * column) that belong to the same ping and exposes them via the bottom() and watercolumn()
 * sub-objects.
 *
 * @note The datagram-processing functions are not implemented yet. This class currently only
 * provides the structure so the ping can be filled in in a later step.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KPing
    : public filetemplates::datatypes::I_Ping
    , public S7KPingCommon<t_ifstream>
{
    S7KPingBottom<t_ifstream>      _bottom;
    S7KPingWatercolumn<t_ifstream> _watercolumn;

  public:
    using t_base1               = filetemplates::datatypes::I_Ping;
    using t_base2               = S7KPingCommon<t_ifstream>;
    using type_DatagramInfo_ptr = typename S7KPingFileData<t_ifstream>::type_DatagramInfo_ptr;

  protected:
    std::string class_name() const override { return "S7KPing"; }
    using t_base2::_file_data;
    using typename t_base2::t_rawdata;

  public:
    S7KPing()
        : t_base1()
        , t_base2()
        , _bottom(_file_data)
        , _watercolumn(_file_data)
    {
    }
    virtual ~S7KPing() = default;

    /**
     * @brief Provide a deep copy of the ping object (deep copy file_data shared pointer)
     *
     * @param other
     * @return S7KPing<t_ifstream>
     */
    S7KPing<t_ifstream> deep_copy()
    {
        S7KPing<t_ifstream> ping = *this;

        // copy the file_data shared pointer and set it in the bottom and watercolumn objects
        ping.set_file_data(std::make_shared<t_rawdata>(*_file_data));
        ping.bottom().set_file_data(ping._file_data);
        ping.watercolumn().set_file_data(ping._file_data);

        return ping;
    }

    void add_datagram_info(const type_DatagramInfo_ptr& datagram_info)
    {
        // update timestamp if it is much smaller or larger than the current one
        if (_timestamp < datagram_info->get_timestamp() - 1000 ||
            _timestamp > datagram_info->get_timestamp())
            _timestamp = datagram_info->get_timestamp();

        _file_data->add_datagram_info(datagram_info);
    }

    // ----- I_Ping interface -----
    using t_base2::file_data;

    // ----- bottom / watercolumn -----
    using t_base1::bottom;
    using t_base1::watercolumn;
    S7KPingBottom<t_ifstream>&      bottom() override { return _bottom; }
    S7KPingWatercolumn<t_ifstream>& watercolumn() override { return _watercolumn; }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base1::__printer__(float_precision, superscript_exponents));

        return printer;
    }
};

} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
