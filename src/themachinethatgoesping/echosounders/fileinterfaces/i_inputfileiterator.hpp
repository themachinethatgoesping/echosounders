// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

#include <fmt/core.h>
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>


namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_DatagramIdentifier>
struct PackageInfo
{
    size_t                  file_nr;             ///< file number of this package
    std::ifstream::pos_type file_pos;            ///< file position of this package
    double                  timestamp;           ///< timestamp (unixtime) of this package
    t_DatagramIdentifier    datagram_identifier; ///< datagram type of this package
};

// TODO: explicitly derive t_ from i_ using concepts from c++20
template<typename t_DatagramIdentifier>
struct DataFileInfo
{

    std::string file_path;
    size_t      file_size;

    /* header positions */
    std::vector<PackageInfo<t_DatagramIdentifier>> package_infos_all; ///< all package headers
    std::unordered_map<t_DatagramIdentifier, std::vector<PackageInfo<t_DatagramIdentifier>>>
        package_infos_by_type; ///< package headers sorted by type
};

template<typename t_Datagram, typename t_DatagramIdentifier>
class I_InputFileIterator
{
    /* some file information */
    std::vector<std::string> _file_paths;

    /* the actual input file stream */
    std::vector<std::ifstream> _input_file_streams;

    /* header positions */
    const std::vector<PackageInfo<t_DatagramIdentifier>> _package_infos;

public:
    I_InputFileIterator(
        const std::vector<std::string> file_paths,
    const std::vector<PackageInfo<t_DatagramIdentifier>>& package_infos)
    : _file_paths(file_paths),
        _package_infos(package_infos)
        {
            _input_file_streams.reserve(_file_paths.size());
            /* open all input files */
            for (const auto& file_path : _file_paths)
            {
                _input_file_streams.emplace_back(file_path, std::ios::binary);

                if (!_input_file_streams.back().is_open())
                    throw std::invalid_argument("ERROR(InputFileIterator): Could not open file \"" + file_path +
                                                "\"!");
            }
        }


    size_t __len__() const
    {
        return _file_paths.size();
    }

    t_Datagram __getitem__(const long python_index)
    {
        // convert from python index (can be negative) to C++ index
        long index = python_index < 0 ? _package_infos.size() + python_index : python_index;

        if (index < 0)
            throw pybind11::index_error("Negative Index [{}] is larger than length [{}]! " +
                                        (index - _package_infos.size()));

        if (static_cast<size_t>(index) >= _package_infos.size())
            throw pybind11::index_error("Index [{}] is larger than length [{}]! " + index);

        const auto& package_info = _package_infos[index];
        _input_file_streams[package_info.file_nr(index)].seekg(package_info.file_pos(index));
        return t_Datagram::from_stream(_input_file_streams, package_info.datagram_identifier);
    }

};

}
}
}

