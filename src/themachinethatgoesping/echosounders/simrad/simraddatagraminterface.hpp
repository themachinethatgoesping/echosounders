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

#include "../filetemplates/i_datagraminterface.hpp"
#include "simrad_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradDatagramInterface
    : public filetemplates::I_DatagramInterface<t_SimradDatagramIdentifier, t_ifstream>
{
  public:
    SimradDatagramInterface(std::string_view name = "SimradDatagramInterface")
        : filetemplates::I_DatagramInterface<t_SimradDatagramIdentifier, t_ifstream>(name)
    {
    }
    virtual ~SimradDatagramInterface() = default;

    /* virtual function implementations */
    // void print_fileinfo(std::ostream& os) const;
    std::string datagram_identifier_to_string(t_SimradDatagramIdentifier datagram_type) const final
    {
        return datagram_type_to_string(datagram_type);
        // return std::string(magic_enum::enum_name(datagram_type));
    }

    std::string datagram_identifier_info(t_SimradDatagramIdentifier datagram_type) const final
    {
        // this should work, but doesn't
        // return magic_enum::enum_contains(datagram_type);

        switch (datagram_type)
        {
            case t_SimradDatagramIdentifier::MRU0:
                return "Motion binary datagram";
            case t_SimradDatagramIdentifier::NME0:
                return "NMEA text datagram";
            case t_SimradDatagramIdentifier::XML0:
                return "XML0 text datagram";
            case t_SimradDatagramIdentifier::TAG0:
                return "Annotation datagram";
            case t_SimradDatagramIdentifier::FIL1:
                return "Filter binary datagram";
            case t_SimradDatagramIdentifier::RAW3:
                return "Sample binary datagram";
            default:
                return "unknown (" + std::to_string(magic_enum::enum_integer(datagram_type)) + ")";
        }
    }
};

} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping