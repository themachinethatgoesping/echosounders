// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

#include "../../py_filetemplates/py_datatypes/py_cache_structures/c_i_filepackageindex.hpp"
#include <themachinethatgoesping/echosounders/kongsbergall/types.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

void init_c_kongsbergallfilepackageindex(nanobind::module_& m)
{
    // add index class
    py_filetemplates::py_datatypes::py_cache_structures::add_file_index_types<
        datatypes::cache_structures::FilePackageIndex<t_KongsbergAllDatagramIdentifier>>(
        m, "FilePackageIndex_kongsbergall");
}

}
}
}
}
}