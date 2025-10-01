// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingfiledata.hpp>

#include "i_pingfiledata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_I_PingFileData(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingFileData, ARG)

void init_c_i_pingfiledata(nanobind::module_& m)
{
    namespace nb = nanobind;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls =
        nb::class_<I_PingFileData>(
            m,
            "I_PingFileData",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingFileData));

    py_i_pingfiledata::I_PingFileData_add_interface<I_PingFileData>(cls);
}

}
}
}
}
}