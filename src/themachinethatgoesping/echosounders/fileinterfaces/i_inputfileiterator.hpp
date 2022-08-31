// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>

/* memory mapping */
#include <boost/iostreams/device/mapped_file.hpp> // for mmap
#include <boost/iostreams/stream.hpp>             // for stream

#include <fmt/core.h>
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

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

template<typename t_DatagramIdentifier>
struct PackageInfo
{
    size_t                  file_nr;  ///< file number of this package
    std::ifstream::pos_type file_pos; ///< file position of this package TODO: is this the same for
                                      ///< ifstream and MappedFileStream?
    double               timestamp;   ///< timestamp (unixtime) of this package
    t_DatagramIdentifier datagram_identifier; ///< datagram type of this package
};

template<typename t_DatagramIdentifier>
class PackageInfoPtrByTypeMap
    : public std::unordered_map<t_DatagramIdentifier,
                                std::shared_ptr<std::vector<PackageInfo<t_DatagramIdentifier>>>>
{
  public:
    // use all constructors of the base class
    PackageInfoPtrByTypeMap() = default;

    std::shared_ptr<std::vector<PackageInfo<t_DatagramIdentifier>>>& get(
        const t_DatagramIdentifier& key)
    {
        auto it = this->find(key);

        if (it == this->end())
        {
            this->operator[](key) =
                std::make_shared<std::vector<PackageInfo<t_DatagramIdentifier>>>();

            return this->operator[](key);
        }
        return it->second;
    }

    std::shared_ptr<std::vector<PackageInfo<t_DatagramIdentifier>>> get_const(
        const t_DatagramIdentifier& key) const
    {
        auto it = this->find(key);

        if (it == this->end())
        {
            return std::make_shared<std::vector<PackageInfo<t_DatagramIdentifier>>>();
        }
        return it->second;
    }
};

// TODO: explicitly derive t_ from i_ using concepts from c++20
template<typename t_DatagramIdentifier>
struct DataFileInfo
{

    std::string file_path;
    size_t      file_size;

    /* header positions */
    std::shared_ptr<std::vector<PackageInfo<t_DatagramIdentifier>>> package_infos_all =
        std::make_shared<std::vector<PackageInfo<t_DatagramIdentifier>>>(); ///< all package headers
    PackageInfoPtrByTypeMap<t_DatagramIdentifier>
        package_infos_by_type; ///< package headers sorted by type
};

template<typename t_DatagramType,
         typename t_DatagramIdentifier,
         typename t_ifstream = std::ifstream,
         typename t_DatagramTypeFactory = t_DatagramType>
class I_InputFileIterator
{
  protected:
    const std::vector<std::string> _file_paths;

    /* the opened input file stream */
    std::unique_ptr<t_ifstream> _input_file_stream;
    long                        active_file_nr = -1;

    /* header positions */
    const std::shared_ptr<const std::vector<PackageInfo<t_DatagramIdentifier>>> _package_infos;

    t_ifstream& get_active_stream(size_t file_nr)
    {
        if (long(file_nr) != active_file_nr)
        {

            if (file_nr >= _file_paths.size())
            {
                throw std::runtime_error(fmt::format("file number {} is out of range", file_nr));
            }

            active_file_nr = file_nr;
            _input_file_stream =
                std::make_unique<t_ifstream>(_file_paths[file_nr], std::ios_base::binary);
        }
        return *_input_file_stream;
    }

  public:
    I_InputFileIterator(
        const ::std::vector<std::string>&                               file_paths,
        std::shared_ptr<std::vector<PackageInfo<t_DatagramIdentifier>>> package_infos)
        : _file_paths(file_paths)
        , _package_infos(package_infos)
    {
    }

    size_t number_of_packages() const { return _package_infos->size(); }

    t_DatagramType get_datagram(const long python_index)
    {
        // convert from python index (can be negative) to C++ index
        long index = python_index < 0 ? _package_infos->size() + python_index : python_index;

        if (index < 0)
            throw pybind11::index_error("Negative Index [{}] is larger than length [{}]! " +
                                        (index - _package_infos->size()));

        if (static_cast<size_t>(index) >= _package_infos->size())
            throw pybind11::index_error("Index [{}] is larger than length [{}]! " + index);

        // size_t, t_ifstream::pos_type double, t_DatagramIdentifier
        const auto& package_info = _package_infos->at(index);
        auto&       ifs          = get_active_stream(package_info.file_nr);

        ifs.seekg(package_info.file_pos);

        try
        {
            return t_DatagramTypeFactory::from_stream(ifs, package_info.datagram_identifier);
        }
        catch (std::exception& e)
        {

            auto msg = fmt::format("Error reading datagram header: {}\n", e.what());
            msg += fmt::format("python_index: {}\n", python_index);
            msg += fmt::format("index: {}\n", index);
            msg += fmt::format("__package_infos->size(): {}\n", _package_infos->size());
            msg += fmt::format("pos: {}\n", package_info.file_pos);
            throw std::runtime_error(msg);
        }
    }
};

}
}
}
