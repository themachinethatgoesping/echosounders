// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include "../../../themachinethatgoesping/echosounders/em3000/em3000_types.hpp"
#include "../../py_filetemplates/py_datatypes/c_i_fileinfodata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::filetemplates;

void init_c_em3000fileinfodata(pybind11::module& m)
{
    // add index class
    py_filetemplates::py_datatypes::add_file_index_types<
        datatypes::FileInfoData<t_EM3000DatagramIdentifier>>(m, "FileInfoData_em3000");
}

}
}
}
}
}