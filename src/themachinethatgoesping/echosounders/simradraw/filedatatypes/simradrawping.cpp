// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "simradrawping.hpp"

// Include stream headers for template instantiations
#include <fstream>
#include "../../filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {

// ----- SimradRawPing implementation -----

template<typename t_ifstream>
void SimradRawPing<t_ifstream>::add_datagram_info(const type_DatagramInfo_ptr& datagram_info)
{
    // update timestamp if it is much smaller or larger than the current one
    if (this->_timestamp < datagram_info->get_timestamp() - 1000 ||
        this->_timestamp > datagram_info->get_timestamp())
        this->_timestamp = datagram_info->get_timestamp();

    this->file_data().add_datagram_info(datagram_info);
}

// ----- Explicit template instantiations -----
template class SimradRawPing<std::ifstream>;
template class SimradRawPing<filetemplates::datastreams::MappedFileStream>;

} // namespace filedatatypes
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
