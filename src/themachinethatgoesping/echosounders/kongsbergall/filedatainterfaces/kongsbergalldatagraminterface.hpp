// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergalldatagraminterface.doc.hpp"

/* std includes */
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

#include "../../filetemplates/datainterfaces/i_datagraminterface.hpp"
#include "../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KongsbergAllDatagramInterface
    : public filetemplates::datainterfaces::I_DatagramInterface<t_KongsbergAllDatagramIdentifier,
                                                                t_ifstream>
{
  public:
    KongsbergAllDatagramInterface(std::string_view name = "KongsbergAllDatagramInterface")
        : filetemplates::datainterfaces::I_DatagramInterface<t_KongsbergAllDatagramIdentifier,
                                                             t_ifstream>(name)
    {
    }
    virtual ~KongsbergAllDatagramInterface() = default;

    /* virtual function implementations */
    // void print_fileinfo(std::ostream& os) const;
    std::string datagram_identifier_to_string(
        t_KongsbergAllDatagramIdentifier datagram_identifier) const final
    {
        return fmt::format("0x{:02x}", uint8_t(datagram_identifier));
    }

    std::string datagram_identifier_info(t_KongsbergAllDatagramIdentifier datagram_identifier) const final
    {
        // this should work, but doesn't
        return std::string(magic_enum::enum_name(datagram_identifier));
    }

    // filter types
    std::vector<KongsbergAllDatagramInterface<t_ifstream>> per_file() const
    {
        std::vector<KongsbergAllDatagramInterface<t_ifstream>> vec;
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