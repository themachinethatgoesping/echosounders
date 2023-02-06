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

#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../themachinethatgoesping/echosounders/simrad/filedatatypes/simradping.hpp"
#include "../../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"

#include "../../py_filetemplates/py_datacontainers/pingcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_filedatacontainers {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using namespace themachinethatgoesping::echosounders::filetemplates;

void init_c_simradpingcontainer(pybind11::module& m)
{
    using themachinethatgoesping::echosounders::simrad::filedatatypes::SimradPing;

    py_filetemplates::py_datacontainers::py_pingcontainer::create_PingContainerType<
        SimradPing<std::ifstream>>(m, "SimradPingContainer");
    py_filetemplates::py_datacontainers::py_pingcontainer::create_PingContainerType<
        SimradPing<datastreams::MappedFileStream>>(m, "SimradPingContainer_mapped");
}

}
}
}
}
}