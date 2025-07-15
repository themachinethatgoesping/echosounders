// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawdatagraminterface.doc.hpp"

/* std includes */
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

#include "../types.hpp"

#include "../../filetemplates/datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradRawDatagramInterface
    : public filetemplates::datainterfaces::I_DatagramInterface<t_SimradRawDatagramIdentifier,
                                                                t_ifstream>
{
  public:
    SimradRawDatagramInterface(std::string_view name = "SimradRawDatagramInterface")
        : filetemplates::datainterfaces::I_DatagramInterface<t_SimradRawDatagramIdentifier,
                                                             t_ifstream>(name)
    {
    }
    virtual ~SimradRawDatagramInterface() = default;

    /* virtual function implementations */
    // void print_fileinfo(std::ostream& os) const;
    std::string datagram_identifier_to_string(t_SimradRawDatagramIdentifier datagram_type) const final
    {
        return datagram_type_to_string(datagram_type);
        // return std::string(magic_enum::enum_name(datagram_type));
    }

    std::string datagram_identifier_info(t_SimradRawDatagramIdentifier datagram_type) const final
    {
        // this should work, but doesn't
        // return magic_enum::enum_contains(datagram_type);

        switch (datagram_type)
        {
            case t_SimradRawDatagramIdentifier::MRU0:
                return "Motion binary datagram";
            case t_SimradRawDatagramIdentifier::NME0:
                return "NMEA text datagram";
            case t_SimradRawDatagramIdentifier::XML0:
                return "XML0 text datagram";
            case t_SimradRawDatagramIdentifier::TAG0:
                return "Annotation datagram";
            case t_SimradRawDatagramIdentifier::FIL1:
                return "Filter binary datagram";
            case t_SimradRawDatagramIdentifier::RAW3:
                return "Sample binary datagram";
            default:
                return "unknown (" + std::to_string(magic_enum::enum_integer(datagram_type)) + ")";
        }
    }

    // filter types
    std::vector<SimradRawDatagramInterface<t_ifstream>> per_file() const
    {
        std::vector<SimradRawDatagramInterface<t_ifstream>> vec;
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