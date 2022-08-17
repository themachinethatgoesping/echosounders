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

#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

// TODO: explicitly derive t_ from i_ using concepts from c++20

template<typename t_DatagramIdentifier>
struct DataFileInfo
{
    std::string file_path;

    std::ifstream::pos_type package_header_position;

    std::unordered_map<t_DatagramIdentifier, std::ifstream::pos_type>
        package_header_positions_by_type;
};

template<typename t_DatagramBase, ///< the datagram base class which should contain the header and
                                  ///< functions specified in the DatagramBase interface
         typename t_DatagramIdentifier ///< the identifier of the datagram type. Must be hashable
                                       ///< and comparable with ==
         >
class I_InputFile
{
  protected:
    /* some file information */
    std::vector<std::string> _file_paths;

    /* the actual input file stream */
    std::vector<std::ifstream> _input_file_streams;

    /* header positions */
    std::vector<std::ifstream::pos_type> _package_headers_all;
    std::unordered_map<t_DatagramIdentifier, std::vector<std::ifstream::pos_type>>
        _package_headers_by_type;

  public:
    I_InputFile(const std::string& file_path) { append_file(file_path); }

    virtual ~I_InputFile() = default;

    void append_file(const std::string& file_path)
    {
        std::ifstream ifi(file_path, std::ios_base::binary);

        if (!ifi.is_open())
            throw std::invalid_argument("ERROR(InputFile): Could not open file \"" + file_path +
                                        "\"!");

        // scan for package headers
        tools::progressbars::ProgressIndicator pbar;
        scan_for_packages(file_path, ifi, pbar);

        _file_paths.push_back(file_path);
        _input_file_streams.push_back(std::move(ifi));
    }

  protected:
    static void reset_stream(std::ifstream& ifs)
    {
        ifs.clear();
        ifs.seekg(0);
    }

    // This function must be called at initialization!
    virtual void scan_for_packages(const std::string&                  file_path,
                                   std::ifstream&                      ifs,
                                   tools::progressbars::I_ProgressBar& pbar)
    {
        /* Initialize internal structures */
        _package_headers_all.clear();
        _package_headers_by_type.clear();
        reset_stream(ifs);

        auto fsize = std::filesystem::file_size(file_path);
        pbar.init(0, fsize, "indexing file");
        auto pos = ifs.tellg();

        try
        {
            while (pos < signed(fsize))
            {
                //  this function may return nonsense...
                auto header = t_DatagramBase::from_stream(ifs);
                header.skip(ifs);

                // this function checks if the package content ifs senseful
                if (ifs.good())
                {
                    pos = ifs.tellg();
                    pbar.set_progress(pos);

                    _package_headers_all.push_back(pos);
                    _package_headers_by_type[header.get_datagram_type()].push_back(pos);
                }
                else
                {
                    break;
                }
            }
        }
        catch (std::runtime_error& e)
        {
            std::cerr << "WARNING(InputFile): could not read the file entirely." << std::endl;
            double percent = 100.0 * pos / fsize;
            std::cerr << fmt::format("Stopped after {:.2f} % of the file", percent) << std::endl;
            std::cerr << "Error message: " << e.what() << std::endl;
        }

        pbar.close(std::string("Found: ") + std::to_string(_package_headers_all.size()) +
                   " packages");

        reset_stream(ifs);
    }
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping