// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kmalldatagraminterface.doc.hpp"

/* std includes */
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"

#include "../../filetemplates/datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KMALLDatagramInterface
    : public filetemplates::datainterfaces::I_DatagramInterface<t_KMALLDatagramIdentifier,
                                                                t_ifstream>
{
  public:
    KMALLDatagramInterface(std::string_view name = "KMALLDatagramInterface")
        : filetemplates::datainterfaces::I_DatagramInterface<t_KMALLDatagramIdentifier, t_ifstream>(
              name)
    {
    }
    virtual ~KMALLDatagramInterface() = default;

    /* virtual function implementations */
    // void print_fileinfo(std::ostream& os) const;
    std::string datagram_identifier_to_string(
        t_KMALLDatagramIdentifier datagram_identifier) const final
    {
        return std::string(o_KMALLDatagramIdentifier(datagram_identifier).name());
    }

    std::string datagram_identifier_info(t_KMALLDatagramIdentifier datagram_identifier) const final
    {
        // this should work, but doesn't
        return std::string(o_KMALLDatagramIdentifier(datagram_identifier).name());
    }

    // filter types
    std::vector<KMALLDatagramInterface<t_ifstream>> per_file() const
    {
        std::vector<KMALLDatagramInterface<t_ifstream>> vec;
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