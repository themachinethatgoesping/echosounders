// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

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
#include "../em3000_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatainterfaces {

template<typename t_ifstream>
class EM3000DatagramInterface
    : public filetemplates::datainterfaces::I_DatagramInterface<t_EM3000DatagramIdentifier,
                                                                t_ifstream>
{
  public:
    EM3000DatagramInterface(std::string_view name = "EM3000DatagramInterface")
        : filetemplates::datainterfaces::I_DatagramInterface<t_EM3000DatagramIdentifier,
                                                             t_ifstream>(name)
    {
    }
    virtual ~EM3000DatagramInterface() = default;

    /* virtual function implementations */
    // void print_fileinfo(std::ostream& os) const;
    std::string datagram_identifier_to_string(t_EM3000DatagramIdentifier datagram_identifier) const final
    {
        return datagram_type_to_string(datagram_identifier);
        // return std::string(magic_enum::enum_name(datagram_identifier));
    }

    std::string datagram_identifier_info(t_EM3000DatagramIdentifier datagram_identifier) const final
    {
        // this should work, but doesn't
        // return magic_enum::enum_contains(datagram_identifier);

        switch (datagram_identifier)
        {
            // case t_EM3000DatagramIdentifier::MRU0:
            //     return "Motion binary datagram";
            default:
                return fmt::format("Unknown datagram type: {:x}", uint8_t(datagram_identifier));
        }
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping