// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/mappedfilestream.doc.hpp"

#include <fstream>

/* memory mapping */
#include <boost/iostreams/device/mapped_file.hpp> // for mmap
#include <boost/iostreams/stream.hpp>             // for stream

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datastreams {

class MappedFileStream : public boost::iostreams::stream<boost::iostreams::mapped_file_source>
{
  public:
    MappedFileStream(const std::string&      file_path,
                     std::ios_base::openmode mode = std::ios_base::binary)
        : boost::iostreams::stream<boost::iostreams::mapped_file_source>(
              boost::iostreams::mapped_file_source(file_path),
              mode)
    {
    }
};

}
}
}
}
