// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingbottom.hpp"
#include "i_pingbottom.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_I_PingBottom(ARG)                                                                      \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingBottom, ARG)

void init_c_i_pingbottom(nanobind::module_& m)
{
    namespace nb = nanobind;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls =
        nb::class_<I_PingBottom, I_PingCommon>(
            m,
            "I_PingBottom",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingBottom));

    py_i_pingbottom::I_PingBottom_add_interface<I_PingBottom>(cls);

    cls __PYCLASS_DEFAULT_COPY__(I_PingBottom);
}

}
}
}
}
}