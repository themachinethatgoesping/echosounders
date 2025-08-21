// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "i_filedatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

size_t I_FileDataInterfacePerFile::get_linked_file_nr() const
{
    return get_linked_file()->get_file_nr();
}
size_t I_FileDataInterfacePerFile::get_file_size() const
{
    return std::filesystem::file_size(get_file_path());
}
bool I_FileDataInterfacePerFile::is_primary_file() const
{
    return !is_secondary_file();
}
std::string I_FileDataInterfacePerFile::get_linked_file_path() const
{
    return get_linked_file()->get_file_path();
}

} // namespace filetemplates
} // namespace datainterfaces
} // namespace echosounders
} // namespace themachinethatgoesping
