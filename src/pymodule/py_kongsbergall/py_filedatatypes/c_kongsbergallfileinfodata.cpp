// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include "../../../themachinethatgoesping/echosounders/kongsbergall/kongsbergall_types.hpp"
#include "../../py_filetemplates/py_datatypes/c_i_fileinfodata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

void init_c_kongsbergallfileinfodata(pybind11::module& m)
{
    // add index class
    py_filetemplates::py_datatypes::add_file_index_types<
        datatypes::FileInfoData<t_KongsbergAllDatagramIdentifier>>(m, "FileInfoData_kongsbergall");
}

}
}
}
}
}