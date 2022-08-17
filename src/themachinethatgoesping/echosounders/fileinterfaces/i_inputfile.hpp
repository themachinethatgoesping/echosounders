// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// #include "i_datagram.h"
// #include "i_datagramcontent.h"
// #include "i_datagramheader.h"

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

// TODO: explicitly derive t_ from i_ using concepts from c++20

template<typename t_DatagramBase, ///< the datagram base class which should contain the header and
                                  ///< functions specified in the DatagramBase interface
         typename t_DatagramIdentifier ///< the identifier of the datagram type. Must be hashable
                                       ///< and comparable with ==
         >
class I_InputFile
{
  protected:
    /* some file information */
    const std::string _file_path;

    /* the actual input file stream */
    std::ifstream _input_file_stream;

    /* header positions */
    std::vector<std::ifstream::pos_type> _package_headers_all;
    std::unordered_map<t_DatagramIdentifier, std::vector<std::ifstream::pos_type>>
        _package_headers_by_type;

  public:
    I_InputFile(const std::string& filepath)
        : _file_path(filepath)
        , _input_file_stream(filepath, std::ios_base::binary)
    {
        if (!_input_file_stream.is_open())
            throw std::invalid_argument("ERROR(InputFile): Could not open file \"" + filepath +
                                        "\"!");

        // scan for package headers
        tools::progressbars::ProgressIndicator pbar;
        scan_for_packages(pbar);
    }

    virtual ~I_InputFile() =  default;


  protected:
    bool good() { return _input_file_stream.good(); }

    void resetStream()
    {
        _input_file_stream.clear();
        _input_file_stream.seekg(0);
    }

    // This function must be called at initialization!
    virtual bool scan_for_packages(tools::progressbars::I_ProgressBar& pbar)
    {
        /* Initialize internal structures */
        _package_headers_all.clear();
        _package_headers_by_type.clear();
        resetStream();

        auto fsize = std::filesystem::file_size(_file_path);
        pbar.init(0, std::filesystem::file_size(_file_path), "indexing file");
        auto pos = _input_file_stream.tellg();

        // try{
        while (pos < signed(fsize))
        {
            // pos = _input_file_stream.tellg();
            //  std::cout << "pos: " << pos << "/" << fsize <<std::endl;

            // std::cout << "pos: " << pos << std::endl;
            //  this function may return nonsense...
            auto header = t_DatagramBase::from_stream(_input_file_stream);
            header.skip(_input_file_stream);

            // this function checks if the package content is senseful
            if (_input_file_stream.good())
            {
                pos = _input_file_stream.tellg();
                pbar.set_progress(pos);

                _package_headers_all.push_back(pos);
                _package_headers_by_type[header.get_datagram_type()].push_back(pos);
            }
            else
            {
                break;
            }
        }
        // }
        // catch(...)
        // {}

        pbar.close(std::string("Found: ") + std::to_string(_package_headers_all.size()) +
                   " packages " + std::to_string(fsize - pos));

        resetStream();
        return _package_headers_all.empty();
    }
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping