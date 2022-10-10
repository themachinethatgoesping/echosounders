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
#include "../../themachinethatgoesping/echosounders/simrad/simradping.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_inputfile.hpp"
#include "../fileinterfaces/i_inputfileiterator.hpp"


namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using namespace themachinethatgoesping::echosounders::fileinterfaces;

template<typename T_FileStream>
void py_create_class_SimradPing(py::module& m, const std::string& CLASS_NAME)
{
    using t_SimradPingRawData = SimradPingRawData<T_FileStream>;
    using t_SimradPing = SimradPing<T_FileStream>;

    py::class_<t_SimradPingRawData>(
        m, (CLASS_NAME + "_RawData").c_str(), DOC(themachinethatgoesping, echosounders, simrad, SimradPingRawData))

        // --- raw data access ---
        .def_readonly(
            "ping_data",
            &t_SimradPingRawData::_ping_data,
            DOC(themachinethatgoesping, echosounders, simrad, SimradPingRawData, ping_data),
            py::return_value_policy::reference_internal)

        // ----- operators -----
        // .def("__eq__",
        //      &SimradPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, simrad, SimradPing, operator_eq),
        //      py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        // __PYCLASS_DEFAULT_COPY__(SimradPing)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(SimradPing)
        // default printing functions
        //__PYCLASS_DEFAULT_PRINTING__(SimradPing)
        // end SimradPing
        ;


    py::class_<t_SimradPing>(
        m, CLASS_NAME.c_str(), DOC(themachinethatgoesping, echosounders, simrad, SimradPing))

        // --- raw data access ---
        .def(
            "raw",
            &t_SimradPing::raw,
            DOC(themachinethatgoesping, echosounders, simrad, SimradPing, raw),
            py::return_value_policy::reference_internal)

        // ----- operators -----
        // .def("__eq__",
        //      &SimradPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, simrad, SimradPing, operator_eq),
        //      py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        // __PYCLASS_DEFAULT_COPY__(SimradPing)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(SimradPing)
        // default printing functions
        //__PYCLASS_DEFAULT_PRINTING__(SimradPing)
        // end SimradPing
        ;

}

void init_c_SimradPing(pybind11::module& m)
{

    py_create_class_SimradPing<std::ifstream>(m, "SimradPing");
    py_create_class_SimradPing<MappedFileStream>(m, "SimradPing_mapped");
    

}

}
}
}
}