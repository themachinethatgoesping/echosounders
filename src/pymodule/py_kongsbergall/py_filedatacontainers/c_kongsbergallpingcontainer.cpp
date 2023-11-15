// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/kongsbergall_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/kongsbergall_types.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatacontainers/kongsbergallpingcontainer.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

#include "../../py_filetemplates/py_datacontainers/pingcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatacontainers {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

void init_c_kongsbergallpingcontainer(pybind11::module& m)
{
    using themachinethatgoesping::echosounders::kongsbergall::filedatatypes::KongsbergAllPing;

    py_filetemplates::py_datacontainers::py_pingcontainer::create_PingContainerType<
        KongsbergAllPing<std::ifstream>>(m, "KongsbergAllPingContainer");
    py_filetemplates::py_datacontainers::py_pingcontainer::create_PingContainerType<
        KongsbergAllPing<datastreams::MappedFileStream>>(m, "KongsbergAllPingContainer_mapped");
}

}
}
}
}
}