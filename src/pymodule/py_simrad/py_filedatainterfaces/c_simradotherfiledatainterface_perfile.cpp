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

#include "../../../themachinethatgoesping/echosounders/simrad/filedatainterfaces/simradotherfiledatainterface.hpp"

#include "../../docstrings.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_filedatainterface.hpp"
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
    themachinethatgoesping, echosounders, simrad, filedatainterfaces, SimradOtherDataInterface

template<typename T_FileStream>
void py_create_class_SimradOtherFileDataInterface_PerFile(py::module&        m,
                                                          const std::string& CLASS_NAME)
{

    using T_BaseClass = filedatainterfaces::SimradOtherFileDataInterface_PerFile<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass>(m,
                                       CLASS_NAME.c_str(),
                                       DOC(themachinethatgoesping,
                                           echosounders,
                                           simrad,
                                           filedatainterfaces,
                                           SimradOtherFileDataInterface_PerFile))

        // .def("get_other_datagram",
        //      &T_BaseClass::get_other_datagram,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          simrad, filedatainterfaces,
        //          SimradOtherFileDataInterface_PerFile,
        //          get_other_datagram))

        //
        ;

    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    //----- inherit functions from I_DatagramInterface -----
    py_i_filedatainterface::FileDataInterface_PerFile_add_interface<T_BaseClass>(cls);
    SimradDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_SimradOtherFileDataInterface_PerFile(pybind11::module& m)
{

    py_create_class_SimradOtherFileDataInterface_PerFile<std::ifstream>(
        m, "SimradOtherFileDataInterface_PerFile");
    py_create_class_SimradOtherFileDataInterface_PerFile<datastreams::MappedFileStream>(
        m, "SimradOtherFileDataInterface_PerFile_mapped");
}

}
}
}
}
}