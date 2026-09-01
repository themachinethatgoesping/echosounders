// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/s7kdatagraminterface.doc.hpp"

/* std includes */
#include <fstream>
#include <string>
#include <vector>

#include <fmt/format.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"

#include "../../filetemplates/datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatainterfaces {

/**
 * @brief Datagram interface for the .s7k (7k) data format. Holds the datagram index (position,
 * timestamp and record type of every datagram) and provides access to the raw datagrams.
 */
template<typename t_ifstream>
class S7KDatagramInterface
    : public filetemplates::datainterfaces::I_DatagramInterface<t_S7KDatagramIdentifier, t_ifstream>
{
  public:
    S7KDatagramInterface(std::string_view name = "S7KDatagramInterface")
        : filetemplates::datainterfaces::I_DatagramInterface<t_S7KDatagramIdentifier, t_ifstream>(
              name)
    {
    }
    virtual ~S7KDatagramInterface() = default;

    /* virtual function implementations */
    // IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_datagram_identifier_to_string
    std::string datagram_identifier_to_string(
        t_S7KDatagramIdentifier datagram_identifier) const final
    {
        // the record type number is the natural, always-available "code" for a 7k record
        return std::to_string(uint32_t(datagram_identifier));
    }

    // IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_datagram_identifier_info
    std::string datagram_identifier_info(t_S7KDatagramIdentifier datagram_identifier) const final
    {
        return s7k::datagram_type_to_string(datagram_identifier);
    }

    // filter types
    std::vector<S7KDatagramInterface<t_ifstream>> per_file() const
    {
        std::vector<S7KDatagramInterface<t_ifstream>> vec;
        for (const auto& datagram_info : this->_datagram_infos_all)
        {
            size_t file_nr = datagram_info->get_file_nr();
            if (vec.size() <= file_nr)
                vec.resize(file_nr + 1);

            vec[file_nr].add_datagram_info(datagram_info);
        }
        return vec;
    }
};

} // namespace filedatainterfaces
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
