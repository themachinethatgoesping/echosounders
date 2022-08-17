// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "../fileinterfaces/i_inputfile.hpp"

#include "ek60_types.hpp"
#include "datagrams/ek60_datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

class FileRaw : public fileinterfaces::I_InputFile<datagrams::EK60_Datagram, ek60_long>
{
  public:
    FileRaw(const std::string& filepath)
        : fileinterfaces::I_InputFile<datagrams::EK60_Datagram, ek60_long>(filepath)
    {
    }

    ~FileRaw() =  default;

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
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping