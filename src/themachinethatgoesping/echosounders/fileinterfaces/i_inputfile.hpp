// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

// #include "i_datagram.h"
// #include "i_datagramcontent.h"
// #include "i_datagramheader.h"

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <boost/sort/sort.hpp>
#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "i_inputfileiterator.hpp"
namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_DatagramBase,       ///< the datagram base class which should
                                        ///< contain the header and functions
                                        ///< specified in the DatagramBase interface
         typename t_DatagramIdentifier, ///< the identifier of the datagram type.
                                        ///< Must be hashable and comparable with
                                        ///< ==
         typename t_ifstream>
class I_InputFile
{

  protected:
    /* some file information */
    std::shared_ptr<std::vector<std::string>> _file_paths = std::make_shared<std::vector<std::string>>();
    size_t                   _total_file_size = 0;

    /* the actual input file stream */
    std::unique_ptr<t_ifstream> _input_file_stream;
    long                        active_file_nr = -1;

    t_ifstream& get_active_stream(size_t file_nr)
    {
        if (long(file_nr) != active_file_nr)
        {
            active_file_nr = file_nr;
            _input_file_stream =
                std::make_unique<t_ifstream>(_file_paths->at(file_nr), std::ios_base::binary);
        }
        return *_input_file_stream;
    }

    /* header positions */
    std::shared_ptr<std::vector<PackageInfo<t_DatagramIdentifier>>> _package_infos_all =
        std::make_shared<std::vector<PackageInfo<t_DatagramIdentifier>>>();
    PackageInfoPtrByTypeMap<t_DatagramIdentifier> _package_infos_by_type;

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

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory> get_iterator(
        t_DatagramIdentifier datagram_identifier) const
    {
        return I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>(
            _file_paths, _package_infos_by_type.get_const(datagram_identifier));
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory> get_iterator() const
    {
        return I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>(
            _file_paths, _package_infos_all);
    }

    size_t size() const { return _package_infos_all->size(); }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    t_DatagramType get_datagram(const long python_index)
    {
        // convert from python index (can be negative) to C++ index
        long index = python_index < 0 ? _package_infos_all->size() + python_index : python_index;

        if (index < 0)
            throw pybind11::index_error("Negative Index [{}] is larger than length [{}]! " +
                                        (index - _package_infos_all->size()));

        if (static_cast<size_t>(index) >= _package_infos_all->size())
            throw pybind11::index_error("Index [{}] is larger than length [{}]! " + index);

        // size_t, t_ifstream::pos_type double, t_DatagramIdentifier
        const auto& package_info = _package_infos_all->at(index);

        // auto& ifs = _input_file_streams[package_info.file_nr];
        auto& ifs = get_active_stream(package_info.file_nr);

        ifs.seekg(package_info.file_pos);

        try
        {
            // t_DatagramTypeFactory::from_stream must return t_datagramType
            // this allows for defining the static function from_stream in a different class
            // than the datagram type
            return t_DatagramTypeFactory::from_stream(ifs, package_info.datagram_identifier);
        }
        catch (std::exception& e)
        {

            auto msg = fmt::format("Error reading datagram header: {}\n", e.what());
            msg += fmt::format("python_index: {}\n", python_index);
            msg += fmt::format("index: {}\n", index);
            msg += fmt::format("_package_infos_all.size(): {}\n", _package_infos_all->size());
            msg += fmt::format("pos: {}\n", package_info.file_pos);
            msg += fmt::format("size: {}\n",
                               std::filesystem::file_size(_file_paths->at(package_info.file_nr)));
            throw std::runtime_error(msg);
        }
    }

    // sort _package_infos_all by timestamp in _package_timestamps
    void sort_packages_by_time()
    {
        auto& package_infos = *(_package_infos_all);
        // sort _package_infos_all by  time, then file_pos then file number
        // TODO: this is faster than std sort, but python sorting (timsort?) seems
        // to be 10x faster for this use case
        boost::sort::pdqsort(
            package_infos.begin(), package_infos.end(), [](const auto& lhs, const auto& rhs) {
                if (lhs.timestamp < rhs.timestamp)
                    return true;
                if (lhs.timestamp > rhs.timestamp)
                    return false;
                if (lhs.file_pos < rhs.file_pos)
                    return true;
                if (lhs.file_pos > rhs.file_pos)
                    return false;
                if (lhs.file_nr < rhs.file_nr)
                    return true;
                return false;
            });

        // reset _package_infos_by_type using the sorted _package_infos_all
        _package_infos_by_type.clear();
        std::unordered_map<t_DatagramIdentifier, std::vector<PackageInfo<t_DatagramIdentifier>>>
            package_infos_by_type;

        for (const auto& package_info : package_infos)
        {
            package_infos_by_type[package_info.datagram_identifier].push_back(package_info);
        }

        for (const auto& [datagram_identifier, package_infos] : package_infos_by_type)
        {
            _package_infos_by_type[datagram_identifier] =
                std::make_shared<std::vector<PackageInfo<t_DatagramIdentifier>>>(
                    std::move(package_infos));
        }
    }

    void append_files(const std::vector<std::string>& file_paths, bool show_progress = true)
    {
        // defaults to no indicator
        tools::progressbars::ProgressBarChooser progress_bar(show_progress);

        // auto pbar = tools::progressbars::ProgressIndicator();
        append_files(file_paths, progress_bar.get());
    }

    void append_files(const std::vector<std::string>&     file_paths,
                      tools::progressbars::I_ProgressBar& progress_bar)
    {
        // get total file size of all files
        size_t total_file_size = 0;
        size_t packages_old    = _package_infos_all->size();
        active_file_nr = -1; 

        progress_bar.init(0, total_file_size, "indexing files");
        for (unsigned int i = 0; i < file_paths.size(); ++i)
        {
            progress_bar.set_postfix(fmt::format("get file size {}/{}", i + 1, file_paths.size()));
            total_file_size += std::filesystem::file_size(file_paths[i]);
        }

        progress_bar.init(0, total_file_size, "indexing files");
        for (unsigned int i = 0; i < file_paths.size(); ++i)
        {
            // progress_bar.set_postfix with the last 30 characters of the file path
            auto fp = file_paths[i];
            if (fp.size() > 23)
                fp = ".." + fp.substr(fp.size() - 20);

            progress_bar.set_postfix(fmt::format("{} ({}/{})", fp, i + 1, file_paths.size()));

            append_file(file_paths[i], progress_bar);
        }

        progress_bar.close(std::string("Found: ") +
                           std::to_string(_package_infos_all->size() - packages_old) +
                           " packages in " + std::to_string(file_paths.size()) + " files (" +
                           std::to_string(int(total_file_size / 1024 / 1024)) + "MB)");
    }

    void append_file(const std::string& file_path, bool show_progress = true)
    {

        tools::progressbars::ProgressBarChooser progress_bar(show_progress);

        append_file(file_path, progress_bar.get());
    }

    void append_file(const std::string& file_path, tools::progressbars::I_ProgressBar& progress_bar)
    {
        auto ifi = std::make_unique<t_ifstream>(file_path, std::ios::binary);
        if (!ifi->is_open())
            throw std::runtime_error("Could not open file: " + file_path);

        // scan for package headers
        DataFileInfo file_info =
            scan_for_packages(file_path, _file_paths->size(), *ifi, progress_bar);

        _total_file_size += file_info.file_size;
        _file_paths->push_back(file_path);

        // ifi is not be valid anymore after this point
        _input_file_stream = std::move(ifi);

        auto& package_infos_all     = *(_package_infos_all);
        auto& package_infos_scanned = *(file_info.package_infos_all);

        package_infos_all.insert(
            package_infos_all.end(), package_infos_scanned.begin(), package_infos_scanned.end());

        for (const auto& [type, headers] : file_info.package_infos_by_type)
        {
            auto& package_infos = *(_package_infos_by_type.get(type));

            auto& package_infos_scanned = *(headers);

            package_infos.insert(
                package_infos.end(), package_infos_scanned.begin(), package_infos_scanned.end());
        }
    }

    virtual std::string datagram_identifier_to_string(
        t_DatagramIdentifier datagram_identifier) const = 0;
    virtual std::string datagram_identifier_info(
        t_DatagramIdentifier datagram_identifier) const = 0;

  protected:
    static void reset_ifstream(t_ifstream& ifs)
    {
        ifs.clear();
        ifs.seekg(0);
    }

    // This function must be called at initialization!
    virtual DataFileInfo<t_DatagramIdentifier> scan_for_packages(
        const std::string&                  file_path,
        size_t                              file_paths_cnt,
        t_ifstream&                         ifs,
        tools::progressbars::I_ProgressBar& progress_bar) const
    {

        /* Initialize internal structures */
        DataFileInfo<t_DatagramIdentifier> file_info;
        file_info.package_infos_all->clear();
        file_info.package_infos_by_type.clear();

        auto& package_infos_all = *(file_info.package_infos_all);

        reset_ifstream(ifs);

        file_info.file_size    = std::filesystem::file_size(file_path);
        bool close_progressbar = false; ///< only close the progressbar if it was
                                        ///< initialized within this function
        if (!progress_bar.is_initialized())
        {
            progress_bar.init(0, file_info.file_size, "indexing file");
            close_progressbar = true;
        }
        auto pos = ifs.tellg();

        try
        {
            while (pos < signed(file_info.file_size))
            {
                //  this function may return nonsense...
                // auto header = t_DatagramBase::from_stream(ifs);
                auto header = t_DatagramBase::from_stream(ifs);
                header.skip(ifs);

                // this function checks if the package content ifs senseful
                if (ifs.good())
                {
                    // update using tick to allow progressbar that was initialized by
                    // append_files to work
                    auto pos_new = ifs.tellg();
                    progress_bar.tick(pos_new - pos);

                    PackageInfo<t_DatagramIdentifier> package_info;
                    package_info.file_nr             = file_paths_cnt;
                    package_info.file_pos            = pos;
                    package_info.timestamp           = header.get_timestamp();
                    package_info.datagram_identifier = header.get_datagram_identifier();

                    package_infos_all.push_back(package_info);
                    auto& package_infos_type =
                        *(file_info.package_infos_by_type.get(package_info.datagram_identifier));

                    package_infos_type.push_back(package_info);

                    pos = pos_new;
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
            double percent = 100.0 * pos / file_info.file_size;
            std::cerr << fmt::format("Stopped after {:.2f} % of the file", percent) << std::endl;
            std::cerr << "Error message: " << e.what() << std::endl;
        }

        if (close_progressbar)
            progress_bar.close(std::string("Found: ") + std::to_string(package_infos_all.size()) +
                               " packages");

        reset_ifstream(ifs);
        return file_info;
    }

  protected:
    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("I_InputFile", float_precision);

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

        printer.register_section("Detected datagrams");
        printer.register_value("Total", _package_infos_all->size(), "");
        for (const auto& kv : _package_infos_by_type)
        {
            std::string info = datagram_identifier_info(kv.first);

            printer.register_value("Packages [" + datagram_identifier_to_string(kv.first) + "]",
                                   kv.second->size(),
                                   info);
        }
        return printer;
    }
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping