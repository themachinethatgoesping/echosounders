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
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "i_inputfileiterator.hpp"
#include "i_package_info_types.hpp"
#include "inputfilemanager.hpp"

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
    std::shared_ptr<InputFileManager<t_ifstream>> _input_file_manager =
        std::make_shared<InputFileManager<t_ifstream>>();

    /* header positions */
    std::shared_ptr<std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>>
        _package_infos_all =
            std::make_shared<std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>>();
    tools::helper::DefaultSharedPointerMap<
        t_DatagramIdentifier,
        std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>>
        _package_infos_by_type;

    I_InputFile() = default;

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
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator(t_DatagramIdentifier datagram_identifier) const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(
            _package_infos_by_type.at_const(datagram_identifier));
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator(t_DatagramIdentifier datagram_identifier,
                 long                 index_min,
                 long                 index_max,
                 long                 index_step) const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(
            _package_infos_by_type.at_const(datagram_identifier),
            index_min,
            index_max,
            index_step);
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator() const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(_package_infos_all);
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator(long index_min, long index_max, long index_step) const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>( _package_infos_all,
                                                          index_min,
                                                          index_max,
                                                          index_step);
    }

    size_t size() const { return _package_infos_all->size(); }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    t_DatagramType get_datagram(const long python_index)
    {
        // convert from python index (can be negative) to C++ index
        long index =
            python_index < 0 ? long(_package_infos_all->size()) + python_index : python_index;

        if (index < 0)
            throw pybind11::index_error(
                fmt::format("Negative Index [{}] is larger than length [{}]! ",
                            index,
                            (index - _package_infos_all->size())));

        if (static_cast<size_t>(index) >= _package_infos_all->size())
            throw pybind11::index_error(fmt::format(
                "Index [{}] is larger than length [{}]! ", index, _package_infos_all->size()));

        // size_t, t_ifstream::pos_type double, t_DatagramIdentifier
        const auto& package_info = _package_infos_all->at(index);

        // auto& ifs = _input_file_streams[package_info->file_nr];
        auto& ifs = package_info->get_stream_and_seek();

        try
        {
            // t_DatagramTypeFactory::from_stream must return t_datagramType
            // this allows for defining the static function from_stream in a different class
            // than the datagram type
            return t_DatagramTypeFactory::from_stream(ifs, package_info->get_datagram_identifier());
        }
        catch (std::exception& e)
        {

            auto msg = fmt::format("Error reading datagram header: {}\n", e.what());
            msg += fmt::format("python_index: {}\n", python_index);
            msg += fmt::format("index: {}\n", index);
            msg += fmt::format("_package_infos_all.size(): {}\n", _package_infos_all->size());
            msg += fmt::format("pos: {}\n", package_info->get_file_pos());
            msg += fmt::format("size: {}\n",
                               std::filesystem::file_size(_input_file_manager->get_file_paths()->at(
                                   package_info->get_file_nr())));
            throw std::runtime_error(msg);
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

        progress_bar.init(0., double(file_paths.size()), "indexing files");
        for (unsigned int i = 0; i < file_paths.size(); ++i)
        {
            progress_bar.set_postfix(fmt::format("get file size {}/{}", i + 1, file_paths.size()));
            total_file_size += std::filesystem::file_size(file_paths[i]);
        }

        progress_bar.init(0, double(total_file_size), "indexing files");
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
        auto& ifi = _input_file_manager->append_file(file_path);

        // scan for package headers
        DataFileInfo file_info = scan_for_packages(
            file_path, _input_file_manager->get_file_paths()->size() - 1, ifi, progress_bar);

        auto& package_infos_all     = *(_package_infos_all);
        auto& package_infos_scanned = *(file_info.package_infos_all);

        package_infos_all.insert(
            package_infos_all.end(), package_infos_scanned.begin(), package_infos_scanned.end());

        for (const auto& [type, headers] : file_info.package_infos_by_type)
        {
            auto& package_infos = *(_package_infos_by_type.at(type));

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

    virtual void callback_scan_new_file_begin([[maybe_unused]] const std::string& file_path,
                                              [[maybe_unused]] size_t             file_paths_cnt)
    {
    }
    virtual void callback_scan_new_file_end([[maybe_unused]] const std::string& file_path,
                                            [[maybe_unused]] size_t             file_paths_cnt)
    {
    }
    virtual PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>
    callback_scan_packet(t_ifstream& ifs, typename t_ifstream::pos_type pos, size_t file_paths_cnt)
    {
        auto header = t_DatagramBase::from_stream(ifs);
        header.skip(ifs);

        auto package_info = std::make_shared<PackageInfo<t_DatagramIdentifier, t_ifstream>>(
            file_paths_cnt,
            pos,
            _input_file_manager,
            header.get_timestamp(),
            header.get_datagram_identifier());
        // package_info->file_nr             = file_paths_cnt;
        // package_info->file_pos            = pos;
        // package_info->timestamp           = header.get_timestamp();
        // package_info->datagram_identifier = header.get_datagram_identifier();
        return package_info;
    }

    // This function must be called at initialization!
    virtual DataFileInfo<t_DatagramIdentifier, t_ifstream> scan_for_packages(
        const std::string&                  file_path,
        size_t                              file_paths_cnt,
        t_ifstream&                         ifs,
        tools::progressbars::I_ProgressBar& progress_bar)
    {

        /* Initialize internal structures */
        DataFileInfo<t_DatagramIdentifier, t_ifstream> file_info;
        file_info.package_infos_all->clear();
        file_info.package_infos_by_type.clear();

        auto& package_infos_all = *(file_info.package_infos_all);

        reset_ifstream(ifs);
        callback_scan_new_file_begin(file_path, file_paths_cnt);

        file_info.file_size    = std::filesystem::file_size(file_path);
        bool close_progressbar = false; ///< only close the progressbar if it was
                                        ///< initialized within this function
        if (!progress_bar.is_initialized())
        {
            progress_bar.init(0., double(file_info.file_size), "indexing file");
            close_progressbar = true;
        }
        auto pos = ifs.tellg();

        try
        {
            while (pos < signed(file_info.file_size))
            {
                //  this function may return nonsense...
                // auto header = t_DatagramBase::from_stream(ifs);
                // header.skip(ifs);
                // auto header = callback_scan_packet(ifs);
                auto package_info = callback_scan_packet(ifs, pos, file_paths_cnt);

                // this function checks if the package content is senseful
                if (ifs.good())
                {
                    // update using tick to allow progressbar that was initialized by
                    // append_files to work
                    auto pos_new = ifs.tellg();
                    progress_bar.tick(double(pos_new - pos));

                    package_infos_all.push_back(package_info);
                    auto& package_infos_type =
                        *(file_info.package_infos_by_type.at(package_info->get_datagram_identifier()));

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
            std::cerr << "WARNING(InputFile): File read incompletely. ";
            // print last 100 characters of file_path
            if (file_path.size() > 53)
                std::cerr << fmt::format("[...{}]", file_path.substr(file_path.size() - 50))
                          << std::endl;
            else
                std::cerr << fmt::format("[{}]", file_path) << std::endl;
            double percent = 100.0 * pos / file_info.file_size;
            std::cerr << fmt::format("Stopped after {:.2f} % of the file", percent) << std::endl;
            std::cerr << "Error message: " << e.what() << std::endl;
        }

        if (close_progressbar)
            progress_bar.close(std::string("Found: ") + std::to_string(package_infos_all.size()) +
                               " packages");

        reset_ifstream(ifs);

        callback_scan_new_file_end(file_path, file_paths_cnt);
        return file_info;
    }

  protected:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("I_InputFile", float_precision);

        printer.register_section("File infos");
        printer.append(_input_file_manager->__printer__(float_precision));

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