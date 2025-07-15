// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/filedatatypes/simradrawping.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/types.hpp"

#include "../../py_filetemplates/py_datacontainers/pingcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatacontainers {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates;

void init_c_simradrawpingcontainer(pybind11::module& m)
{
    static const std::string name        = "SimradRawPingContainer";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    using themachinethatgoesping::echosounders::simradraw::filedatatypes::SimradRawPing;

    py_filetemplates::py_datacontainers::py_pingcontainer::create_PingContainerType<
        SimradRawPing<std::ifstream>>(m, name_stream);
    py_filetemplates::py_datacontainers::py_pingcontainer::create_PingContainerType<
        SimradRawPing<datastreams::MappedFileStream>>(m, name_mapped);
}

}
}
}
}
}