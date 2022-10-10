// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

#include <fstream>
#include <limits>
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
         typename t_ifstream            = std::ifstream,
         typename t_DatagramTypeFactory = t_DatagramType>
class I_InputFileIterator
{
  protected:
    const std::shared_ptr<std::vector<std::string>> _file_paths;

    /* the opened input file stream */
    std::unique_ptr<t_ifstream> _input_file_stream;
    long                        active_file_nr = -1;

    /* header positions */
    const std::shared_ptr<const std::vector<PackageInfo<t_DatagramIdentifier>>> _package_infos;

    t_ifstream& get_active_stream(size_t file_nr)
    {
        // TODO: active_file_nr is currently not updated when _file_paths is changed in the master
        if (long(file_nr) != active_file_nr)
        {
            active_file_nr = long(file_nr);
            _input_file_stream =
                std::make_unique<t_ifstream>(_file_paths->at(file_nr), std::ios_base::binary);
        }
        return *_input_file_stream;
    }

    bool   _is_slice   = false;
    size_t _index_min  = 0;
    size_t _index_max  = std::numeric_limits<long>::max();
    long   _index_step = 1;

  public:
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>&
    operator()(long index_min, long index_max, long index_step)
    {

        if (index_step == 0)
            throw(std::out_of_range("InputFileIterator: index_step is zero!"));

        if (index_max == std::numeric_limits<long>::max())
            index_max = _package_infos->size();

        bool ivn_max = false;
        bool ivn_min = false;
        if (index_max < 0)
        {
            index_max = long(_package_infos->size()) + index_max;
            ivn_max   = true;
        }

        if (index_min < 0)
        {
            index_min = long(_package_infos->size()) + index_min;
            ivn_min   = true;
        }

        if (index_min > index_max)
        {
            std::swap(index_min, index_max);
            index_step *= -1;
            ivn_max = ivn_min;
        }

        index_max = index_max - 1 * (!ivn_max);

        if (index_min < 0 || index_min >= long(_package_infos->size()))
            throw(std::out_of_range("InputFileIterator: index_min is out of bounds!"));
        if (index_max < 0 || index_max >= long(_package_infos->size()))
            throw(std::out_of_range("InputFileIterator: index_max is out of bounds!"));
        if (index_min >= index_max)
            throw(std::out_of_range("InputFileIterator: _index_min >= _index_max!"));

        _is_slice   = true;
        _index_min  = index_min;
        _index_max  = index_max;
        _index_step = index_step;

        return *this;
    }

    I_InputFileIterator(
        std::shared_ptr<std::vector<std::string>>                       file_paths,
        std::shared_ptr<std::vector<PackageInfo<t_DatagramIdentifier>>> package_infos)
        : _file_paths(file_paths)
        , _package_infos(package_infos)
        , _is_slice(false)
    {
    }

    I_InputFileIterator(
        std::shared_ptr<std::vector<std::string>>                       file_paths,
        std::shared_ptr<std::vector<PackageInfo<t_DatagramIdentifier>>> package_infos,
        long                                                            index_min,
        long                                                            index_max,
        long                                                            index_step)
        : _file_paths(file_paths)
        , _package_infos(package_infos)
    {
        this->operator()(index_min, index_max, index_step);
    }

    size_t size() const
    {
        if (_is_slice)
            return size_t((_index_max - _index_min + 1) / std::abs(_index_step));
        return _package_infos->size();
    }

    t_DatagramType at(long index)
    {
        if (_is_slice)
        {
            if (_index_step < 0)
                index += 1;

            // convert index to C++ index using _index_step, _index_min, _index_max
            index *= _index_step;

            if (index < 0)
                index +=
                    long(_index_max) + std::abs(_index_step); //_index_max == _package_infos->size()-1
            else
                index += long(_index_min);

            // TODO: fix error messages
            if (size_t(index) > _index_max)
                throw std::out_of_range(
                    fmt::format("Index [{}] is > max [{}]! ", index - _index_min, _index_max));
        }
        else
        {
            // convert from python index (can be negative) to C++ index
            if (index < 0)
                index += long(_package_infos->size());
            // index = python_index < 0 ? _package_infos->size() + python_index : python_index;

            if (size_t(index) >= _package_infos->size())
                throw std::out_of_range(
                    fmt::format("Index [{}] is >= max [{}]! ", index, _package_infos->size()));
        }

        if (index < long(_index_min))
            throw std::out_of_range(fmt::format("Index [{}] is < min [{}]! ", index, _index_min));

        // size_t, t_ifstream::pos_type double, t_DatagramIdentifier

        const auto& package_info = _package_infos->at(index);
        try
        {
            t_ifstream& ifs = get_active_stream(package_info.file_nr);
            ifs.seekg(package_info.file_pos);

            return t_DatagramTypeFactory::from_stream(ifs, package_info.datagram_identifier);
        }
        catch (std::exception& e)
        {

            auto msg = fmt::format("Error reading datagram header: {}\n", e.what());
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
