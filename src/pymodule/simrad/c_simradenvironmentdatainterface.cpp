// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pyarray.hpp> // Numpy bindings
#include <xtensor/xmath.hpp>          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/simradenvironmentdatainterface.hpp"

#include "../docstrings.hpp"
#include "module.hpp"

#include "../filetemplates/i_environmentdatainterface.hpp"
#include "c_simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, simrad, SimradEnvironmentDataInterface

template<typename T_FileStream>
void py_create_class_SimradEnvironmentPerFileDataInterface(py::module&        m,
                                                           const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_DatagramInterface and
                                       // py_i_DatagramInterface

    using T_BaseClass = SimradEnvironmentPerFileDataInterface<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simrad, SimradEnvironmentPerFileDataInterface))

        // .def("get_environment_datagram",
        //      &T_BaseClass::get_environment_datagram,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          simrad,
        //          SimradEnvironmentPerFileDataInterface,
        //          get_environment_datagram))

        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_i_EnvironmentDataInterface::EnvironmentPerFileDataInterface_add_interface<
        SimradEnvironmentPerFileDataInterface<T_FileStream>>(cls);
    SimradDatagramInterface_add_interface_functions<
        SimradEnvironmentPerFileDataInterface<T_FileStream>>(cls);
}

template<typename T_FileStream>
void py_create_class_SimradEnvironmentDataInterface(py::module& m, const std::string& CLASS_NAME)
{
    using py_filetemplates::py_i_EnvironmentDataInterface::EnvironmentDataInterface_add_interface;

    // initialize class
    auto cls = py::class_<SimradEnvironmentDataInterface<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX));

    //----- inherit functions from I_EnvironmentDataInterface -----
    EnvironmentDataInterface_add_interface<SimradEnvironmentDataInterface<T_FileStream>>(cls);

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    // cls __PYCLASS_DEFAULT_PRINTING__(SimradEnvironmentDataInterface<T_FileStream>);
}

void init_c_SimradEnvironmentDataInterface(pybind11::module& m)
{

    py_create_class_SimradEnvironmentPerFileDataInterface<std::ifstream>(
        m, "SimradEnvironmentPerFileDataInterface");
    py_create_class_SimradEnvironmentPerFileDataInterface<MappedFileStream>(
        m, "SimradEnvironmentPerFileDataInterface_mapped");

    py_create_class_SimradEnvironmentDataInterface<std::ifstream>(m,
                                                                  "SimradEnvironmentDataInterface");
    py_create_class_SimradEnvironmentDataInterface<MappedFileStream>(
        m, "SimradEnvironmentDataInterface_mapped");
}

}
}
}
}