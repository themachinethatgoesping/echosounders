// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp>
#include <themachinethatgoesping/echosounders/s7k/datagrams.hpp>
#include <themachinethatgoesping/echosounders/s7k/filedatacontainers/s7kpingcontainer.hpp>
#include <themachinethatgoesping/echosounders/s7k/types.hpp>

#include "../../py_filetemplates/py_datacontainers/pingcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatacontainers {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::filetemplates;

void init_c_s7kpingcontainer(nanobind::module_& m)
{
    static const std::string name        = "S7KPingContainer";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    using themachinethatgoesping::echosounders::s7k::filedatatypes::S7KPing;

    py_filetemplates::py_datacontainers::py_pingcontainer::create_PingContainerType<
        S7KPing<std::ifstream>>(m, name_stream);
    py_filetemplates::py_datacontainers::py_pingcontainer::create_PingContainerType<
        S7KPing<datastreams::MappedFileStream>>(m, name_mapped);
}

}
}
}
}
}
