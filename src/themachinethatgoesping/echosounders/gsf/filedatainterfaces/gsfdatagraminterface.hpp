// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/gsfdatagraminterface.doc.hpp"

/* std includes */
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../../filetemplates/datainterfaces/i_datagraminterface.hpp"
#include "../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace gsf {
namespace filedatainterfaces {

template<typename t_ifstream>
class GSFDatagramInterface
    : public filetemplates::datainterfaces::I_DatagramInterface<t_GSFDatagramIdentifier,
                                                                t_ifstream>
{
  public:
    GSFDatagramInterface(std::string_view name = "GSFDatagramInterface")
        : filetemplates::datainterfaces::I_DatagramInterface<t_GSFDatagramIdentifier,
                                                             t_ifstream>(name)
    {
    }
    virtual ~GSFDatagramInterface() = default;

    /* virtual function implementations */
    // void print_fileinfo(std::ostream& os) const;
    std::string datagram_identifier_to_string(
        t_GSFDatagramIdentifier datagram_identifier) const final
    {
        return std::string(magic_enum::enum_name(datagram_identifier));
    }

    std::string datagram_identifier_info(t_GSFDatagramIdentifier datagram_identifier) const final
    {
        // this should work, but doesn't
        return std::string(magic_enum::enum_name(datagram_identifier));
    }

    // filter types
    std::vector<GSFDatagramInterface<t_ifstream>> per_file() const
    {
        std::vector<GSFDatagramInterface<t_ifstream>> vec;
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

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping