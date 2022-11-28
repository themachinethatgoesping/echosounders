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

#include "../../themachinethatgoesping/echosounders/simrad/simradannotationdatainterface.hpp"

#include "../docstrings.hpp"
#include "module.hpp"

#include "../filetemplates/i_annotationdatainterface.hpp"
#include "c_simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX themachinethatgoesping, echosounders, simrad, SimradAnnotationDataInterface

template<typename T_FileStream>
void py_create_class_SimradAnnotationPerFileDataInterface(py::module&        m,
                                                          const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_DatagramInterface and
                                       // py_i_DatagramInterface

    using T_BaseClass = SimradAnnotationPerFileDataInterface<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simrad, SimradAnnotationPerFileDataInterface))

        // .def("get_annotation_datagram",
        //      &T_BaseClass::get_annotation_datagram,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          simrad,
        //          SimradAnnotationPerFileDataInterface,
        //          get_annotation_datagram))

        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_i_AnnotationDataInterface::AnnotationPerFileDataInterface_add_interface<
        SimradAnnotationPerFileDataInterface<T_FileStream>>(cls);
    SimradDatagramInterface_add_interface_functions<
        SimradAnnotationPerFileDataInterface<T_FileStream>>(cls);
}

template<typename T_FileStream>
void py_create_class_SimradAnnotationDataInterface(py::module& m, const std::string& CLASS_NAME)
{
    using py_filetemplates::py_i_AnnotationDataInterface::AnnotationDataInterface_add_interface;

    // initialize class
    auto cls = py::class_<SimradAnnotationDataInterface<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX));

    //----- inherit functions from I_AnnotationDataInterface -----
    AnnotationDataInterface_add_interface<SimradAnnotationDataInterface<T_FileStream>>(cls);

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    // cls __PYCLASS_DEFAULT_PRINTING__(SimradAnnotationDataInterface<T_FileStream>);
}

void init_c_SimradAnnotationDataInterface(pybind11::module& m)
{

    py_create_class_SimradAnnotationPerFileDataInterface<std::ifstream>(
        m, "SimradAnnotationPerFileDataInterface");
    py_create_class_SimradAnnotationPerFileDataInterface<MappedFileStream>(
        m, "SimradAnnotationPerFileDataInterface_mapped");

    py_create_class_SimradAnnotationDataInterface<std::ifstream>(m,
                                                                 "SimradAnnotationDataInterface");
    py_create_class_SimradAnnotationDataInterface<MappedFileStream>(
        m, "SimradAnnotationDataInterface_mapped");
}

}
}
}
}