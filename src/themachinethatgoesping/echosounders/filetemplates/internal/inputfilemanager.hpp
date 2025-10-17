// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

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
#include <memory>
#include <string>
#include <vector>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace internal {

class InputFileManagerBase
{
    protected:
        InputFileManagerBase();

        std::shared_ptr<std::vector<std::string>> _file_paths;
        size_t                                    _total_file_size;

    public:
        virtual ~InputFileManagerBase() = default;

        size_t get_total_file_size() const;

        const std::shared_ptr<std::vector<std::string>>& get_file_paths() const;
        const std::string& get_file_path(size_t file_nr) const;

        tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                                                                    bool         superscript_exponents) const;
};

template<typename t_ifstream>
class InputFileManager : public InputFileManagerBase
{

    protected:
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

    // static void reset_ifstream(t_ifstream& ifs)
    // {
    //     ifs.clear();
    //     ifs.seekg(0);
    // }

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        return InputFileManagerBase::__printer__(float_precision, superscript_exponents);
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping