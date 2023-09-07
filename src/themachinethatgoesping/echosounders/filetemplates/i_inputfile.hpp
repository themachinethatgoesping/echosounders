// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_inputfile.doc.hpp"

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
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "datacontainers/datagramcontainer.hpp"
#include "datainterfaces/i_datagraminterface.hpp"
#include "datainterfaces/i_filedatainterface.hpp"
#include "datatypes/datagraminfo.hpp"
#include "internal/inputfilemanager.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {

template<typename t_DatagramBase, ///< the datagram base class which should
                                  ///< contain the header and functions
                                  ///< specified in the DatagramBase interface
         typename t_DatagramInterface>
class I_InputFile
{
  public:
    // member types
    using t_DatagramIdentifier = typename t_DatagramInterface::type_DatagramIdentifier;
    using t_ifstream           = typename t_DatagramInterface::type_ifstream;
    // using t_FileDataInterface  = typename datainterfaces::I_FileDataInterface<
    //     datainterfaces::I_FileDataInterfacePerFile<t_DatagramInterface>>;

    struct FileInfos;
    struct FileInfoData;

  protected:
    std::shared_ptr<internal::InputFileManager<t_ifstream>> _input_file_manager =
        std::make_shared<internal::InputFileManager<t_ifstream>>();

    std::map<std::string, FileInfoData> _cached_index_per_file_path;

    /* datagram container */
    t_DatagramInterface _datagram_interface;

    // // ----- file data interfaces -----
    // std::shared_ptr<t_FileDataInterface> _filedata_interface =
    //     std::make_shared<t_FileDataInterface>();

    I_InputFile() = default;

    I_InputFile(const std::map<std::string, FileInfoData>& cached_index)
        : _cached_index_per_file_path(cached_index)
    {
    }

  public:
    I_InputFile(const std::string&                         file_path,
                const std::map<std::string, FileInfoData>& cached_index =
                    std::map<std::string, FileInfoData>(),
                bool init          = true,
                bool show_progress = true)
        : _cached_index_per_file_path(cached_index)
    {
        append_file(file_path, show_progress);
        if (init)
            init_interfaces(false, show_progress);
    }
    I_InputFile(const std::string&                         file_path,
                const std::map<std::string, FileInfoData>& cached_index,
                bool                                       init,
                tools::progressbars::I_ProgressBar&        progress_bar)
        : _cached_index_per_file_path(cached_index)
    {
        append_file(file_path, progress_bar);
        if (init)
            init_interfaces(false, progress_bar);
    }

    I_InputFile(const std::vector<std::string>&            file_paths,
                const std::map<std::string, FileInfoData>& cached_index =
                    std::map<std::string, FileInfoData>(),
                bool init          = true,
                bool show_progress = true)
        : _cached_index_per_file_path(cached_index)
    {
        append_files(file_paths, show_progress);
        if (init)
            init_interfaces(false, show_progress);
    }
    I_InputFile(const std::vector<std::string>&            file_paths,
                const std::map<std::string, FileInfoData>& cached_index,
                bool                                       init,
                tools::progressbars::I_ProgressBar&        progress_bar)
        : _cached_index_per_file_path(cached_index)
    {
        append_files(file_paths, progress_bar);
        if (init)
            init_interfaces(false, progress_bar);
    }

    virtual ~I_InputFile() = default;

    void init_interfaces(bool force = false, bool show_progress = true)
    {
        tools::progressbars::ProgressBarChooser progress_bar(show_progress);
        this->init_interfaces(force, progress_bar.get());
    }

    virtual void init_interfaces(bool force, tools::progressbars::I_ProgressBar& progress_bar) = 0;

    /* access containers */
    const auto& datagram_interface() const { return _datagram_interface; }
    // auto& filedata_interface() { return _filedata_interface; }

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
        size_t datagrams_old   = _datagram_interface.size();

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
                           std::to_string(_datagram_interface.size() - datagrams_old) +
                           " datagrams in " + std::to_string(file_paths.size()) + " files (" +
                           std::to_string(int(total_file_size / 1024 / 1024)) + "MB)");
    }

    void append_file(const std::string& file_path, bool show_progress = true)
    {

        tools::progressbars::ProgressBarChooser progress_bar(show_progress);

        append_file(file_path, progress_bar.get());
    }

    void append_file(const std::string& file_path, tools::progressbars::I_ProgressBar& progress_bar)
    {
        _input_file_manager->append_file(file_path);
        auto file_nr = _input_file_manager->get_file_paths()->size() - 1;

        // check if file exists in index
        auto it = _cached_index_per_file_path.find(file_path);

        if (it == _cached_index_per_file_path.end())
        {
            // scan for datagram headers
            FileInfos file_info = scan_for_datagrams(file_path, file_nr, progress_bar);

            _cached_index_per_file_path[file_path] = FileInfoData(file_info);
            _datagram_interface.add_datagram_infos(file_info.datagram_infos);
        }
        else
        {
            // load datagram infos from index
            FileInfos file_info(file_nr, _input_file_manager, it->second);

            bool close_progressbar = false; ///< only close the progressbar if it was
                                            ///< initialized within this function
            if (!progress_bar.is_initialized())
            {
                progress_bar.init(0., double(file_info.file_size), "indexing file");
                close_progressbar = true;
            }
            callback_scan_new_file_begin(file_path, file_nr);

            _datagram_interface.add_datagram_infos(file_info.datagram_infos);

            double pos = 0.;
            // call callback functions
            for (auto& datagram_info : file_info.datagram_infos)
            {
                datagram_info = callback_scan_packet(datagram_info);

                double pos_new = double(datagram_info->get_file_pos());

                progress_bar.tick(pos_new - pos);

                pos = pos_new;
            }
            callback_scan_new_file_end(file_path, file_nr);

            //_cached_index_per_file_path[file_path] = FileInfoData(file_info);

            if (close_progressbar)
                progress_bar.close(std::string("Found: ") +
                                   std::to_string(file_info.datagram_infos.size()) + " datagrams");
        }
    }

    auto get_cached_file_index() const
    {
        std::map<std::string, FileInfoData> file_infos_per_file_path;

        for (auto& [file_path, file_info] : _cached_index_per_file_path)
        {
            file_infos_per_file_path[file_path] = FileInfoData(file_info);
        }

        return file_infos_per_file_path;
    }

    struct FileInfoData
    {
        std::string file_path;
        size_t      file_size;

        /* header positions */
        std::vector<datatypes::DatagramInfoData<t_DatagramIdentifier>>
            datagram_infos; ///< all datagrams

        FileInfoData() = default;
        FileInfoData(const FileInfos& file_info)
            : file_path(file_info.file_path)
            , file_size(file_info.file_size)
        {
            for (auto& datagram_info : file_info.datagram_infos)
            {
                datagram_infos.push_back(*datagram_info);
            }
        }
        bool operator==(const FileInfoData&) const = default;

        // ----- to/from stream interface -----
        static FileInfoData from_stream(std::istream& is)
        {
            FileInfoData data;

            data.file_path = tools::classhelper::stream::container_from_stream<std::string>(is);
            is.read(reinterpret_cast<char*>(&data.file_size), sizeof(size_t));

            size_t size;
            is.read(reinterpret_cast<char*>(&size), sizeof(size_t));
            data.datagram_infos.resize(size);
            for (size_t i = 0; i < size; ++i)
            {
                data.datagram_infos[i] =
                    datatypes::DatagramInfoData<t_DatagramIdentifier>::from_stream(is);
            }

            return data;
        }

        void to_stream(std::ostream& os) const
        {
            tools::classhelper::stream::container_to_stream<std::string>(os, file_path);
            os.write(reinterpret_cast<const char*>(&file_size), sizeof(size_t));

            size_t size = datagram_infos.size();
            os.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
            for (size_t i = 0; i < size; ++i)
            {
                datagram_infos[i].to_stream(os);
            }
        }

        // ----- objectprinter -----
        tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
        {
            tools::classhelper::ObjectPrinter printer("DatagramInfoData", float_precision);

            // raw values
            printer.register_string("file_path", file_path);
            printer.register_value("file_size", size_t(file_size));

            printer.register_value("datagrams", datagram_infos.size());

            return printer;
        }

        // ----- class helper macros -----
        __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
        __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(FileInfoData)
    };

    /**
     * @brief struct for storing the file infos (returned by scan_for_datagrams)
     *
     */
    struct FileInfos
    {
        std::string file_path;
        size_t      file_size;

        /* header positions */
        std::vector<datatypes::DatagramInfo_ptr<t_DatagramIdentifier,
                                                t_ifstream>>
            datagram_infos; ///< all datagrams

        FileInfos() = default;
        FileInfos(size_t                                                  file_nr,
                  std::shared_ptr<internal::InputFileManager<t_ifstream>> input_file_manager,
                  const FileInfoData&                                     file_info_data)
            : file_path(file_info_data.file_path)
            , file_size(file_info_data.file_size)
        {
            for (auto& datagram_info : file_info_data.datagram_infos)
            {
                datagram_infos.push_back(
                    std::make_shared<datatypes::DatagramInfo<t_DatagramIdentifier, t_ifstream>>(
                        file_nr, input_file_manager, datagram_info));
            }
        }
    };

    // // ----- iterator interface -----
    // template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    // datacontainers::
    //     DatagramContainer<t_DatagramType, t_DatagramIdentifier, t_ifstream,
    //     t_DatagramTypeFactory> datagrams() const
    // {
    //     this->_datagram_interface->template datagrams<t_DatagramType, t_DatagramTypeFactory>();
    // }

    // template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    // datacontainers::
    //     DatagramContainer<t_DatagramType, t_DatagramIdentifier, t_ifstream,
    //     t_DatagramTypeFactory> datagrams(t_DatagramIdentifier datagram_identifier) const
    // {
    //     this->_datagram_interface->template datagrams<t_DatagramType, t_DatagramTypeFactory>(
    //         datagram_identifier);
    // }

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
    virtual datatypes::DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream> callback_scan_packet(
        [[maybe_unused]] const datatypes::DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream>&
                    datagram_info)
    {
        return datagram_info;
    }

    // This function must be called at initialization!
    virtual FileInfos scan_for_datagrams(const std::string&                  file_path,
                                         size_t                              file_paths_cnt,
                                         tools::progressbars::I_ProgressBar& progress_bar)
    {
        /* open stream */
        // do not use ifs from _input_file_manager, because this might be changed by the callback
        // functions
        t_ifstream ifs(file_path, std::ios::binary);

        /* Initialize internal structures */
        FileInfos file_info;
        file_info.datagram_infos.clear();

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
            while (size_t(pos) < file_info.file_size)
            {
                auto header = t_DatagramBase::from_stream(ifs);
                header.skip(ifs);

                auto datagram_info =
                    std::make_shared<datatypes::DatagramInfo<t_DatagramIdentifier, t_ifstream>>(
                        file_paths_cnt,
                        pos,
                        _input_file_manager,
                        header.get_timestamp(),
                        header.get_datagram_identifier());

                datagram_info = callback_scan_packet(datagram_info);

                // this function checks if the datagram content is senseful
                if (ifs.good())
                {
                    // update using tick to allow progressbar that was initialized by
                    // append_files to work
                    auto pos_new = ifs.tellg();
                    progress_bar.tick(double(pos_new - pos));

                    file_info.datagram_infos.push_back(std::move(datagram_info));

                    pos = pos_new;
                }
                else
                {
                    if (size_t(pos) < file_info.file_size)
                        throw std::runtime_error("File read incompletely.");
                    else
                        break;
                }
            }
        }
        catch (std::runtime_error& e)
        {
            std::cerr << fmt::format("WARNING(InputFile): File [{}] read incompletely. ",
                                     file_paths_cnt);
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

        callback_scan_new_file_end(file_path, file_paths_cnt);

        if (close_progressbar)
            progress_bar.close(std::string("Found: ") +
                               std::to_string(file_info.datagram_infos.size()) + " datagrams");

        return file_info;
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("I_InputFile", float_precision);

        printer.register_section("File infos");
        printer.append(_input_file_manager->__printer__(float_precision));

        printer.register_section("Detected datagrams", '^');
        printer.append(_datagram_interface.__printer__(float_precision), true);
        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  public:
};

} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping