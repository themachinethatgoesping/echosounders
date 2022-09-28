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

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream = std::ifstream>
class FileRaw
    : public fileinterfaces::
          I_InputFile<datagrams::SimradDatagram, t_SimradDatagramType, t_ifstream>
{
  public:
    // inherit constructors
    using fileinterfaces::I_InputFile<datagrams::SimradDatagram, t_SimradDatagramType, t_ifstream>::
        I_InputFile;
    ~FileRaw() = default;

    // using fileinterfaces::I_InputFile<datagrams::SimradDatagram, simrad_long>::append_file;
    // using fileinterfaces::I_InputFile<datagrams::SimradDatagram, simrad_long>::append_files;

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
    std::string datagram_identifier_to_string(t_SimradDatagramType datagram_type) const final
    {
        return datagram_type_to_string(simrad_long(datagram_type));
        // return std::string(magic_enum::enum_name(datagram_type));
    }

    std::string datagram_identifier_info(t_SimradDatagramType datagram_type) const final
    {
        // this should work, but doesn't
        // return magic_enum::enum_contains(datagram_type);

        switch (datagram_type)
        {
            case t_SimradDatagramType::MRU0:
                return "Motion binary datagram";
            case t_SimradDatagramType::NME0:
                return "NMEA text datagram";
            case t_SimradDatagramType::XML0:
                return "XML0 text datagram";
            case t_SimradDatagramType::TAG0:
                return "Annotation datagram";
            case t_SimradDatagramType::FIL1:
                return "Filter binary datagram";
            case t_SimradDatagramType::RAW3:
                return "Sample binary datagram";
            default:
                return "unknown (" + std::to_string(magic_enum::enum_integer(datagram_type)) + ")";
        }
    }

  protected:
    struct
    {
        datagrams::xml_datagrams::XML_Configuration configuration;
        std::vector<datagrams::NME0>                nme0_packets;
        std::vector<datagrams::MRU0>                mru0_packets;

    } _packet_buffer;

    void callback_scan_new_file_begin([[maybe_unused]] const std::string& file_path,
                                      [[maybe_unused]] size_t             file_paths_cnt) final
    {
    }
    void callback_scan_new_file_end([[maybe_unused]] const std::string& file_path,
                                    [[maybe_unused]] size_t             file_paths_cnt) final
    {
    }

    datagrams::SimradDatagram callback_scan_packet(t_ifstream& ifs) final
    {
        auto header = datagrams::SimradDatagram::from_stream(ifs);
        auto type   = header.get_datagram_identifier();

        switch (type)
        {
            case t_SimradDatagramType::NME0: {
                _packet_buffer.nme0_packets.emplace_back(datagrams::NME0::from_stream(ifs, header));
                break;
            }
            case t_SimradDatagramType::MRU0: {
                _packet_buffer.mru0_packets.emplace_back(datagrams::MRU0::from_stream(ifs, header));
                break;
            }
            case t_SimradDatagramType::XML0: {
                auto xml      = datagrams::XML0::from_stream(ifs, header);
                auto xml_type = xml.get_xml_datagram_type();

                if (xml_type == "Configuration")
                    _packet_buffer.configuration =
                        std::get<datagrams::xml_datagrams::XML_Configuration>(xml.decode());
                break;
            }
            default: {
                header.skip(ifs);
                break;
            }
        }
        return header;
    }

  public:
    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("FileSimradRaw", float_precision);

        auto interface_printer =
            fileinterfaces::I_InputFile<datagrams::SimradDatagram,
                                        t_SimradDatagramType,
                                        t_ifstream>::__printer__(float_precision);

        printer.append(interface_printer);

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
