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

    /* header positions */
    // std::vector<std::ifstream::pos_type> package_headers_all;

    // std::unordered_map<t_DatagramIdentifier, std::vector<std::ifstream::pos_type>>
    //     package_headers_by_type;

    std::vector<std::pair<size_t, std::ifstream::pos_type>> package_headers_all;
    std::unordered_map<t_DatagramIdentifier,
                       std::vector<std::pair<size_t, std::ifstream::pos_type>>>
        package_headers_by_type;
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
    std::vector<std::pair<size_t, std::ifstream::pos_type>> _package_headers_all;
    std::unordered_map<t_DatagramIdentifier,
                       std::vector<std::pair<size_t, std::ifstream::pos_type>>>
        _package_headers_by_type;

  public:
    I_InputFile(const std::string& file_path, bool show_progress = true)
    {
        append_file(file_path, show_progress);
    }
    I_InputFile(const std::string& file_path, tools::progressbars::I_ProgressBar& progress_bar)
    {
        append_file(file_path, progress_bar);
    }

    I_InputFile(const std::vector<std::string>& file_paths, bool show_progress)
    {
        append_files(file_paths, show_progress);
    }
    I_InputFile(const std::vector<std::string>&     file_paths,
                tools::progressbars::I_ProgressBar& progress_bar)
    {
        append_files(file_paths, progress_bar);
    }

    virtual ~I_InputFile() = default;

    void append_files(const std::vector<std::string>& file_paths, bool show_progress = true)
    {
        // defaults to no indicator
        tools::progressbars::ProgressBar progress_bar;

        if (show_progress)
        {
            progress_bar.emplace<tools::progressbars::ProgressIndicator>();
        }

        //auto pbar = tools::progressbars::ProgressIndicator();
        append_files(file_paths, tools::progressbars::get_progress_bar(progress_bar));
    }

    void append_files(const std::vector<std::string>&     file_paths,
                      tools::progressbars::I_ProgressBar& progress_bar)
    {
        // get total file size of all files
        size_t total_file_size = 0;
        size_t packages_old    = _package_headers_all.size();

        for (const auto& file_path : file_paths)
        {
            total_file_size += std::filesystem::file_size(file_path);
        }
        progress_bar.init(0, total_file_size, "indexing files");

        for (const auto& file_path : file_paths)
        {
            // progress_bar.set_postfix with the last 30 characters of the file path
            if (file_path.size() > 23)
                progress_bar.set_postfix(
                    ".." + file_path.substr(file_path.size() - 20) + " (" +
                    std::to_string(int(std::filesystem::file_size(file_path) / 1024 / 1024)) + "/" +
                    std::to_string(int(total_file_size / 1024 / 1024)) + "MB)");
            else
                progress_bar.set_postfix(file_path);
            append_file(file_path, progress_bar);
        }

        progress_bar.close(std::string("Found: ") +
                           std::to_string(_package_headers_all.size() - packages_old) +
                           " packages in " + std::to_string(file_paths.size()) + " files (" +
                           std::to_string(int(total_file_size / 1024 / 1024)) + "MB)");
    }

    void append_file(const std::string& file_path, bool show_progress = true)
    {
        if (!show_progress)
        {
            auto pbar = tools::progressbars::NoIndicator();
            append_file(file_path, pbar);
        }
        else
        {
            auto pbar = tools::progressbars::ProgressIndicator();
            append_file(file_path, pbar);
        }
    }

    void append_file(const std::string& file_path, tools::progressbars::I_ProgressBar& progress_bar)
    {
        std::ifstream ifi(file_path, std::ios_base::binary);

        if (!ifi.is_open())
            throw std::invalid_argument("ERROR(InputFile): Could not open file \"" + file_path +
                                        "\"!");

        // scan for package headers
        DataFileInfo file_info =
            scan_for_packages(file_path, _file_paths.size(), ifi, progress_bar);

        _file_paths.push_back(file_path);
        _input_file_streams.push_back(std::move(ifi));
        _package_headers_all.insert(_package_headers_all.end(),
                                    file_info.package_headers_all.begin(),
                                    file_info.package_headers_all.end());

        for (const auto& [type, headers] : file_info.package_headers_by_type)
        {
            _package_headers_by_type[type].insert(
                _package_headers_by_type[type].end(), headers.begin(), headers.end());
        }
    }

  protected:
    static void reset_stream(std::ifstream& ifs)
    {
        ifs.clear();
        ifs.seekg(0);
    }

    // This function must be called at initialization!
    virtual DataFileInfo<t_DatagramIdentifier> scan_for_packages(
        const std::string&                  file_path,
        size_t                              file_paths_cnt,
        std::ifstream&                      ifs,
        tools::progressbars::I_ProgressBar& progress_bar) const
    {
        /* Initialize internal structures */
        DataFileInfo<t_DatagramIdentifier> file_info;
        file_info.package_headers_all.clear();
        file_info.package_headers_by_type.clear();
        reset_stream(ifs);

        auto fsize = std::filesystem::file_size(file_path);
        bool close_progressbar =
            false; ///< only close the progressbar if it was initialized within this function
        if (!progress_bar.is_initialized())
        {
            progress_bar.init(0, fsize, "indexing file");
            close_progressbar = true;
        }
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
                    // update using tick to allow progressbar that was initialized by append_files
                    // to work
                    auto pos_new = ifs.tellg();
                    progress_bar.tick(pos_new - pos);
                    pos = pos_new;

                    file_info.package_headers_all.push_back(std::make_pair(file_paths_cnt, pos));
                    file_info.package_headers_by_type[header.get_datagram_type()].push_back(
                        std::make_pair(file_paths_cnt, pos));
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

        if (close_progressbar)
            progress_bar.close(std::string("Found: ") +
                               std::to_string(file_info.package_headers_all.size()) + " packages");

        reset_stream(ifs);
        return file_info;
    }
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping