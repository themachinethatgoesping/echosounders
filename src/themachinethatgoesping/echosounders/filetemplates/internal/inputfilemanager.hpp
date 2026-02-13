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
#include <thread>
#include <unordered_map>
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
        /* Max open streams in the LRU cache (per-thread) */
        const size_t _max_streams_open = 3;

        /* Thread ID of the thread that created this InputFileManager.
         * Streams on this thread use the fast member-variable path (original
         * proven behaviour).  Worker threads spawned by std::async get their
         * own thread_local stream pools — no mutex needed. */
        std::thread::id _owning_thread_id;

        /* Member-variable stream pool — used ONLY by the owning thread */
        std::map<size_t, std::unique_ptr<t_ifstream>> _active_file_streams;
        std::deque<size_t>                            _active_file_numbers;

        /* Thread-local stream pool for worker threads */
        struct StreamPool
        {
            std::map<size_t, std::unique_ptr<t_ifstream>> streams;
            std::deque<size_t>                            numbers;
        };

        static auto& tl_pools()
        {
            static thread_local std::unordered_map<const InputFileManager*, StreamPool> pools;
            return pools;
        }

  public:
    InputFileManager()
        : _owning_thread_id(std::this_thread::get_id())
    {
    }

    ~InputFileManager() = default;

    t_ifstream& append_file(const std::string& file_path)
    {
        auto ifi = std::make_unique<t_ifstream>(file_path, std::ios::binary);
        if (!ifi->is_open())
            throw std::runtime_error("Could not open file: " + file_path);

        _total_file_size += std::filesystem::file_size(file_path);
        _file_paths->push_back(file_path);

        return get_active_stream(_file_paths->size() - 1);
    }

    t_ifstream& get_active_stream(size_t file_nr)
    {
        if (std::this_thread::get_id() == _owning_thread_id)
            return get_active_stream_member(file_nr);
        else
            return get_active_stream_tl(file_nr);
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

  private:
    /* Fast path: owning thread uses member variables (original behaviour) */
    t_ifstream& get_active_stream_member(size_t file_nr)
    {
        auto it = _active_file_streams.find(file_nr);
        if (it != _active_file_streams.end())
            return *it->second;

        _active_file_streams[file_nr] =
            std::make_unique<t_ifstream>(_file_paths->at(file_nr), std::ios_base::binary);
        _active_file_numbers.push_back(file_nr);

        while (_active_file_numbers.size() > _max_streams_open)
        {
            _active_file_streams.erase(_active_file_numbers[0]);
            _active_file_numbers.pop_front();
        }

        return *_active_file_streams.at(file_nr);
    }

    /* Worker-thread path: each thread gets its own stream pool via thread_local.
     * The pool is automatically destroyed when the thread exits. */
    t_ifstream& get_active_stream_tl(size_t file_nr)
    {
        auto& pool = tl_pools()[this];

        auto it = pool.streams.find(file_nr);
        if (it != pool.streams.end())
            return *it->second;

        pool.streams[file_nr] =
            std::make_unique<t_ifstream>(_file_paths->at(file_nr), std::ios_base::binary);
        pool.numbers.push_back(file_nr);

        while (pool.numbers.size() > _max_streams_open)
        {
            pool.streams.erase(pool.numbers[0]);
            pool.numbers.pop_front();
        }

        return *pool.streams.at(file_nr);
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping