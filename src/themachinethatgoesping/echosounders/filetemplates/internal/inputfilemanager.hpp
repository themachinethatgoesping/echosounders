// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/inputfilemanager.doc.hpp"

/* generated doc strings */
#include ".docstrings/inputfilemanager.doc.hpp"

// #include "i_datagram.h"
// #include "i_datagramcontent.h"
// #include "i_datagramheader.h"

/* std includes */
#include <deque>
#include <filesystem>
#include <fstream>
#include <map>
#include <vector>

#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace internal {

template<typename t_ifstream>
class InputFileManager
{

  protected:
    /* some file information */
    std::shared_ptr<std::vector<std::string>> _file_paths =
        std::make_shared<std::vector<std::string>>();
    size_t _total_file_size = 0;

    /* the actual input file stream */
    const size_t                                  _max_streams_open = 3;
    std::map<size_t, std::unique_ptr<t_ifstream>> _active_file_streams;
    std::deque<size_t>                            _active_file_numbers;

    // std::unique_ptr<t_ifstream> _input_file_stream;
    // int64_t                        active_file_nr = -1;

    // datatypes::DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream>

  public:
    InputFileManager()  = default;
    ~InputFileManager() = default;

    size_t get_total_file_size() const { return _total_file_size; }

    t_ifstream& append_file(const std::string& file_path)
    {
        auto ifi = std::make_unique<t_ifstream>(file_path, std::ios::binary);
        if (!ifi->is_open())
            throw std::runtime_error("Could not open file: " + file_path);

        //_input_file_stream = std::move(ifi);
        // active_file_nr     = _file_paths->size() - 1;

        _total_file_size += std::filesystem::file_size(file_path);
        _file_paths->push_back(file_path);

        return get_active_stream(_file_paths->size() - 1);

        // return *_input_file_stream;
    }

    t_ifstream& get_active_stream(size_t file_nr)
    {
        auto afs_iterator = _active_file_streams.find(file_nr);

        if (afs_iterator != _active_file_streams.end())
        {
            return *afs_iterator->second;
        }

        _active_file_streams[file_nr] =
            std::make_unique<t_ifstream>(_file_paths->at(file_nr), std::ios_base::binary);
        _active_file_numbers.push_back(file_nr);

        while (_active_file_numbers.size() > _max_streams_open)
        {
            _active_file_streams.erase(_active_file_numbers[0]);
            _active_file_numbers.pop_front();
        }

        return *_active_file_streams.at(file_nr);

        //     if (int64_t(file_nr) != active_file_nr)
        //     {
        //         active_file_nr = int64_t(file_nr);
        //         _input_file_stream =
        //             std::make_unique<t_ifstream>(_file_paths->at(file_nr),
        //             std::ios_base::binary);
        //     }
        //     return *_input_file_stream;
    }

    const std::shared_ptr<std::vector<std::string>>& get_file_paths() const { return _file_paths; }
    const std::string& get_file_path(size_t file_nr) const { return _file_paths->at(file_nr); }

    // static void reset_ifstream(t_ifstream& ifs)
    // {
    //     ifs.clear();
    //     ifs.seekg(0);
    // }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "InputFileManager", float_precision, superscript_exponents);

        if (_file_paths->size() > 1)
        {
            // find number of files per file ending in the file_paths vector
            std::map<std::string, size_t> file_ending_counts;
            for (const auto& file_path : *_file_paths)
            {
                auto file_ending = file_path.substr(file_path.find_last_of(".") + 1);
                file_ending_counts[file_ending]++;
            }

            for (const auto& [file_ending, count] : file_ending_counts)
            {
                printer.register_value(fmt::format("Number of loaded .{} files: ", file_ending),
                                       count);
            }
        }
        else // print the file path
        {
            // if size > 40, print only the last 40 characters
            auto file_path = _file_paths->at(0);
            if (file_path.size() > 40)
                file_path = "..." + file_path.substr(file_path.size() - 40);

            printer.register_value("File path", file_path);
        }

        if (_total_file_size > 1024 * 1024 * 1024)
            printer.register_string(
                "Total file size: ",
                fmt::format("{:.2f} GB", _total_file_size / (1024.0 * 1024.0 * 1024.0)));
        else if (_total_file_size > 1024 * 1024)
            printer.register_string("Total file size: ",
                                    fmt::format("{:.2f} MB", _total_file_size / (1024.0 * 1024.0)));
        else if (_total_file_size > 1024)
            printer.register_string("Total file size: ",
                                    fmt::format("{:.2f} KB", _total_file_size / 1024.0));
        else
            printer.register_string("Total file size: ",
                                    fmt::format("{:d} Bytes", _total_file_size));

        return printer;
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping