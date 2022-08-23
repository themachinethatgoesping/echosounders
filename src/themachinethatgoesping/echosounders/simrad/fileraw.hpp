// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../fileinterfaces/i_inputfile.hpp"

#include "datagrams/ek60_datagram.hpp"
#include "ek60_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

class FileRaw : public fileinterfaces::I_InputFile<datagrams::EK60_Datagram, t_EK60_DatagramType>
{
  public:
    // inherit constructors
    using fileinterfaces::I_InputFile<datagrams::EK60_Datagram, t_EK60_DatagramType>::I_InputFile;
    ~FileRaw() = default;

    // using fileinterfaces::I_InputFile<datagrams::EK60_Datagram, ek60_long>::append_file;
    // using fileinterfaces::I_InputFile<datagrams::EK60_Datagram, ek60_long>::append_files;

    // std::vector<FileDatagramEntry> GetDatagramEntries() const;

    // void                                         ScanFileStream(std::ifstream& stream);
    // const Ek60::Datagram                         GetConfigurationDatagram(std::ifstream& stream);
    // const std::shared_ptr<ConfigurationDatagram> GetConfiguration(std::ifstream& stream);
    // bool FindFirstDatagramEntryForTime(unsigned long      highdate,
    //                                    unsigned long      lowdate,
    //                                    FileDatagramEntry& entry);
    // bool FindNextSmallerDatagramEntryForTime(unsigned long      highdate,
    //                                          unsigned long      lowdate,
    //                                          FileDatagramEntry& entry);
    // bool FindNextBiggerDatagramEntryForTime(unsigned long      highdate,
    //                                         unsigned long      lowdate,
    //                                         FileDatagramEntry& entry);
    // bool FindDatagramEntryForPosition(unsigned int position, FileDatagramEntry& entry);

    // void print_fileinfo(std::ostream& os) const;
    std::string datagram_identifier_to_string(t_EK60_DatagramType datagram_type) const final
    {
        return datagram_type_to_string(ek60_long(datagram_type));
        // return std::string(magic_enum::enum_name(datagram_type));
    }

    std::string datagram_identifier_info(t_EK60_DatagramType datagram_type) const final
    {
        // this should work, but doesn't
        // return magic_enum::enum_contains(datagram_type);

        switch (datagram_type)
        {
            case t_EK60_DatagramType::XML0:
                [[fallthrough]];
            case t_EK60_DatagramType::FIL1:
                [[fallthrough]];
            case t_EK60_DatagramType::NME0:
                [[fallthrough]];
            case t_EK60_DatagramType::MRU0:
                [[fallthrough]];
            case t_EK60_DatagramType::RAW3:
                return "known / not implemented";
            default:
                return "unknown (" + std::to_string(magic_enum::enum_integer(datagram_type)) + ")";
        }
    }

  public:
    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("FileSimradRaw", float_precision);

        if (_file_paths.size() > 1)
            printer.register_container("file paths", _file_paths, "");
        else
            printer.register_string("file path", _file_paths[0], "");

        printer.register_value("Packages", _package_headers_all.size(), "");
        for (const auto& kv : _package_headers_by_type)
        {
            std::string info = datagram_identifier_info(kv.first);

            printer.register_value("Packages [" + datagram_identifier_to_string(kv.first) + "]",
                                   kv.second.size(),
                                   info);
        }

        // printer.append(GeoLocation::__printer__(float_precision));

        return printer;
    }

  public:
    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoespingction macros --

