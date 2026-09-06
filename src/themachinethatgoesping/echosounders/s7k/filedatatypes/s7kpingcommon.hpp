// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kpingcommon.doc.hpp"

/* std includes */
#include <memory>

#include <fmt/format.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include "../datagrams.hpp"

#include "s7kpingfiledata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {

/**
 * @brief Common base for the s7k ping (and its bottom / watercolumn sub-objects). Holds the shared
 * S7KPingFileData (the raw file data / datagram index of the ping).
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KPingCommon
{
  protected:
    std::string class_name() const { return "S7KPingCommon"; }

    // raw data
    using t_rawdata                       = S7KPingFileData<t_ifstream>;
    std::shared_ptr<t_rawdata> _file_data = std::make_shared<t_rawdata>();

  public:
    S7KPingCommon() = default;
    S7KPingCommon(std::shared_ptr<t_rawdata> file_data)
        : _file_data(std::move(file_data))
    {
    }
    virtual ~S7KPingCommon() = default;

    const t_rawdata& file_data() const { return *_file_data; }
    t_rawdata&       file_data() { return *_file_data; }
    void set_file_data(std::shared_ptr<t_rawdata> file_data) { _file_data = std::move(file_data); }
};

} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
