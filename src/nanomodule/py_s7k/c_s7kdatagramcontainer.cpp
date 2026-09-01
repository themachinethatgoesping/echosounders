// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/s7k/datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/s7k/types.hpp"

#include "../py_filetemplates/py_datacontainers/datagramcontainer.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::s7k;

void init_c_s7kdatagramcontainer(nanobind::module_& m)
{
    using namespace py_filetemplates::py_datacontainers;
    // S7KDATAGRAMTYPEAREA

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::S7KDatagram,
                                                        t_S7KDatagramIdentifier>(
        m, "S7KDatagramContainer_Header");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::S7KUnknown,
                                                        t_S7KDatagramIdentifier>(
        m, "S7KDatagramContainer_Unknown");
}

}
}
}
}
