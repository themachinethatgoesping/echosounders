// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/datagraminfo.doc.hpp"

#include <fstream>
#include <limits>
#include <memory>
#include <unordered_map>
#include <vector>

/* memory mapping */
#include <boost/iostreams/device/mapped_file.hpp> // for mmap
#include <boost/iostreams/stream.hpp>             // for stream

#include <fmt/core.h>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../internal/inputfilemanager.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

template<typename t_DatagramIdentifier, typename t_ifstream>
class DatagramInfo
{
    size_t                        _file_nr;  ///< file number of this datagram
    typename t_ifstream::pos_type _file_pos; ///< file position of this datagram TODO: is this the
                                             ///< same for ifstream and MappedFileStream?
    std::shared_ptr<internal::InputFileManager<t_ifstream>>
        _input_file_manager; ///< input file manager

    double               _timestamp;           ///< timestamp (unixtime) of this datagram
    t_DatagramIdentifier _datagram_identifier; ///< datagram type of this datagram

  public:
    // member types
    using type_DatagramIdentifier = t_DatagramIdentifier;
    using type_ifstream           = t_ifstream;

  public:
    DatagramInfo(size_t                                                  file_nr,
                 typename t_ifstream::pos_type                           file_pos,
                 std::shared_ptr<internal::InputFileManager<t_ifstream>> input_file_manager,
                 double                                                  timestamp,
                 t_DatagramIdentifier                                    datagram_identifier)
        : _file_nr(file_nr)
        , _file_pos(file_pos)
        , _input_file_manager(input_file_manager)
        , _timestamp(timestamp)
        , _datagram_identifier(datagram_identifier)
    {
    }

    size_t             get_file_nr() const { return _file_nr; }
    const std::string& get_file_path() const
    {
        return _input_file_manager->get_file_path(_file_nr);
    }
    t_ifstream& get_stream()
    {
        auto& ifs = _input_file_manager->get_active_stream(_file_nr);

        return ifs;
    }
    t_ifstream& get_stream_and_seek(std::istream::pos_type offset = 0)
    {
        auto& ifs = get_stream();
        ifs.seekg(_file_pos + offset);

        return ifs;
    }
    double                        get_timestamp() const { return _timestamp; }
    t_DatagramIdentifier          get_datagram_identifier() const { return _datagram_identifier; }
    typename t_ifstream::pos_type get_file_pos() const { return _file_pos; }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    t_DatagramType read_datagram_from_file()
    {
        auto& ifs = this->get_stream_and_seek();

        return t_DatagramTypeFactory::from_stream(ifs, this->get_datagram_identifier());
    }

    /**
     * @brief same as above, but this function provides the skip data option (which is not avaliable
     * for all datagram types)
     *
     * @tparam t_DatagramType
     * @tparam t_DatagramTypeFactory
     * @param skip_data
     * @return t_DatagramType
     */
    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    t_DatagramType read_datagram_from_file(bool skip_data)
    {
        auto& ifs = this->get_stream_and_seek();

        return t_DatagramTypeFactory::from_stream(ifs, this->get_datagram_identifier(), skip_data);
    }
};

template<typename t_DatagramIdentifier, typename t_ifstream>
using DatagramInfo_ptr = std::shared_ptr<DatagramInfo<t_DatagramIdentifier, t_ifstream>>;

}
}
}
}
