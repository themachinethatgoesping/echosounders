// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatacontainers/kongsbergallpingcontainer.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/types.hpp"

#include "../../py_filetemplates/py_datacontainers/pingcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatacontainers {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

void init_c_kongsbergallpingcontainer(nanobind::module_& m)
{
    static const std::string name        = "KongsbergAllPingContainer";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    using themachinethatgoesping::echosounders::kongsbergall::filedatatypes::KongsbergAllPing;

    py_filetemplates::py_datacontainers::py_pingcontainer::create_PingContainerType<
    KongsbergAllPing<std::ifstream>>(m, name_stream);
    py_filetemplates::py_datacontainers::py_pingcontainer::create_PingContainerType<
        KongsbergAllPing<datastreams::MappedFileStream>>(m, name_mapped);
}

}
}
}
}
}