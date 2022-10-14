// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
//#define FORCE_IMPORT_ARRAY
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/fileraw.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simradfiledata.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_ping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using namespace themachinethatgoesping::echosounders::fileinterfaces;

void init_c_SimradFileData(pybind11::module& m)
{
    py::class_<SimradFileData>(
        m, "SimradFileData", DOC(themachinethatgoesping, echosounders, simrad, SimradFileData))

        // --- raw data access ---
        .def("FIL1",
             &SimradFileData::FIL1,
             DOC(themachinethatgoesping, echosounders, simrad, SimradFileData, FIL1),
             py::return_value_policy::reference_internal)
        .def("TAG0",
             &SimradFileData::TAG0,
             DOC(themachinethatgoesping, echosounders, simrad, SimradFileData, TAG0),
             py::return_value_policy::reference_internal)
        .def("XML0_Configuration",
             &SimradFileData::XML0_Configuration,
             DOC(themachinethatgoesping, echosounders, simrad, SimradFileData, XML0_Configuration),
             py::return_value_policy::reference_internal)
        .def("XML0_Environment",
             &SimradFileData::XML0_Environment,
             DOC(themachinethatgoesping, echosounders, simrad, SimradFileData, XML0_Environment),
             py::return_value_policy::reference_internal)
        .def("XML0_InitialParameter",
             &SimradFileData::XML0_InitialParameter,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 SimradFileData,
                 XML0_InitialParameter),
             py::return_value_policy::reference_internal)
        .def("XML0_Other",
             &SimradFileData::XML0_Other,
             DOC(themachinethatgoesping, echosounders, simrad, SimradFileData, XML0_Other),
             py::return_value_policy::reference_internal)

        // ----- operators -----
        // .def("__eq__",
        //      &SimradFileData::operator==,
        //      DOC(themachinethatgoesping, echosounders, simrad, SimradFileData, operator_eq),
        //      py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        // __PYCLASS_DEFAULT_COPY__(SimradFileData)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(SimradFileData)
        // default printing functions
        //__PYCLASS_DEFAULT_PRINTING__(SimradFileData)
        // end SimradFileData
        ;
}

}
}
}
}