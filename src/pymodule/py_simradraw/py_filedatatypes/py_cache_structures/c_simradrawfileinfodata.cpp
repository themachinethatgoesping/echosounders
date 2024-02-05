// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include "../../../py_filetemplates/py_datatypes/py_cache_structures/c_i_filepackageindex.hpp"
#include <themachinethatgoesping/echosounders/simradraw/types.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {
namespace py_cache_structures {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates;

void init_c_simradrawfilepackageindex(pybind11::module& m)
{
    // add index class
    py_filetemplates::py_datatypes::py_cache_structures::add_file_index_types<
        datatypes::cache_structures::FilePackageIndex<t_SimradRawDatagramIdentifier>>(
        m, "FilePackageIndex_simradraw");
}

} // namespace py_cache_structures
} // namespace py_filedatatypes
} // namespace py_simraddraw
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping