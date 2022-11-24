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

#include "../../themachinethatgoesping/echosounders/simrad/simradpingdatainterface.hpp"

#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_pingdatainterface.hpp"
#include "c_simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX themachinethatgoesping, echosounders, simrad, SimradPingDataInterface

template<typename T_FileStream>
void py_create_class_SimradPingPerFileDataInterface(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_fileinterfaces; // this holds py_i_DatagramInterface and
                                       // py_i_DatagramInterface

    using T_BaseClass = SimradPingPerFileDataInterface<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simrad, SimradPingPerFileDataInterface))

        // .def("get_ping_datagram",
        //      &T_BaseClass::get_ping_datagram,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          simrad,
        //          SimradPingPerFileDataInterface,
        //          get_ping_datagram))

        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_i_PingDataInterface::PingPerFileDataInterface_add_interface<
        SimradPingPerFileDataInterface<T_FileStream>>(cls);
    SimradDatagramInterface_add_interface_functions<SimradPingPerFileDataInterface<T_FileStream>>(
        cls);
}

template<typename T_FileStream>
void py_create_class_SimradPingDataInterface(py::module& m, const std::string& CLASS_NAME)
{
    using py_fileinterfaces::py_i_PingDataInterface::PingDataInterface_add_interface;
    using T_BaseClass = SimradPingDataInterface<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass>(m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX))

                   .def("get_deduplicated",
                        &T_BaseClass::get_deduplicated,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simrad,
                            SimradPingDataInterface,
                            get_deduplicated))
        //
        ;

    //----- inherit functions from I_PingDataInterface -----
    PingDataInterface_add_interface<T_BaseClass>(cls);

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    // cls __PYCLASS_DEFAULT_PRINTING__(T_BaseClass);
}

void init_c_SimradPingDataInterface(pybind11::module& m)
{

    py_create_class_SimradPingPerFileDataInterface<std::ifstream>(m,
                                                                  "SimradPingPerFileDataInterface");
    py_create_class_SimradPingPerFileDataInterface<MappedFileStream>(
        m, "SimradPingPerFileDataInterface_mapped");

    py_create_class_SimradPingDataInterface<std::ifstream>(m, "SimradPingDataInterface");
    py_create_class_SimradPingDataInterface<MappedFileStream>(m, "SimradPingDataInterface_mapped");
}

}
}
}
}