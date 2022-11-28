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

#include "../../../themachinethatgoesping/echosounders/simrad/filedatainterfaces/simradnavigationdatainterface.hpp"

#include "../../docstrings.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_navigationdatainterface.hpp"
#include "c_simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_filedatainterfaces {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, simrad, filedatainterfaces, SimradNavigationDataInterface

template<typename T_FileStream>
void py_create_class_SimradNavigationPerFileDataInterface(py::module&        m,
                                                          const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    using T_BaseClass = filedatainterfaces::SimradNavigationPerFileDataInterface<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass>(m,
                                       CLASS_NAME.c_str(),
                                       DOC(themachinethatgoesping,
                                           echosounders,
                                           simrad,
                                           filedatainterfaces,
                                           SimradNavigationPerFileDataInterface))

                   .def("set_min_gga_quality",
                        &T_BaseClass::set_min_gga_quality,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simrad,
                            filedatainterfaces,
                            SimradNavigationPerFileDataInterface,
                            set_min_gga_quality),
                        py::arg("min_gga_quality"))
                   .def("set_max_gga_quality",
                        &T_BaseClass::set_max_gga_quality,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simrad,
                            filedatainterfaces,
                            SimradNavigationPerFileDataInterface,
                            set_max_gga_quality),
                        py::arg("max_gga_quality"))
                   .def("get_min_gga_quality",
                        &T_BaseClass::get_min_gga_quality,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simrad,
                            filedatainterfaces,
                            SimradNavigationPerFileDataInterface,
                            get_min_gga_quality))
                   .def("get_max_gga_quality",
                        &T_BaseClass::get_max_gga_quality,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simrad,
                            filedatainterfaces,
                            SimradNavigationPerFileDataInterface,
                            get_max_gga_quality))

        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_filetemplates::py_datainterfaces::py_i_navigationdatainterface::
        NavigationPerFileDataInterface_add_interface<T_BaseClass>(cls);
    SimradDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}


void init_c_SimradNavigationPerFileDataInterface(pybind11::module& m)
{

    py_create_class_SimradNavigationPerFileDataInterface<std::ifstream>(
        m, "SimradNavigationPerFileDataInterface");
    py_create_class_SimradNavigationPerFileDataInterface<datastreams::MappedFileStream>(
        m, "SimradNavigationPerFileDataInterface_mapped");

}

}
}
}
}
}