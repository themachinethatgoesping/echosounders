// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
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

#include "../../../themachinethatgoesping/echosounders/simradraw/filedatainterfaces/simradrawotherfiledatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_filedatainterface.hpp"
#include "c_simradrawdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatainterfaces {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, simradraw, filedatainterfaces, SimradRawOtherFileDataInterface

template<typename T_FileStream>
void py_create_class_init_c_simradrawotherfiledatainterfaceperfile(py::module&        m,
                                                                const std::string& CLASS_NAME)
{

    using T_BaseClass =
        filedatainterfaces::init_c_simradrawotherfiledatainterfaceperfile<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass, std::shared_ptr<T_BaseClass>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping,
            echosounders,
            simradraw,
            filedatainterfaces,
            init_c_simradrawotherfiledatainterfaceperfile))

        // .def("get_other_datagram",
        //      &T_BaseClass::get_other_datagram,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          simradraw, filedatainterfaces,
        //          init_c_simradrawotherfiledatainterfaceperfile,
        //          get_other_datagram))

        //
        ;

    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    //----- inherit functions from I_DatagramInterface -----
    py_i_filedatainterface::FileDataInterfacePerFile_add_interface<T_BaseClass>(cls);
    SimradRawDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_init_c_simradrawotherfiledatainterfaceperfile(pybind11::module& m)
{

    py_create_class_init_c_simradrawotherfiledatainterfaceperfile<std::ifstream>(
        m, "init_c_simradrawotherfiledatainterfaceperfile");
    py_create_class_init_c_simradrawotherfiledatainterfaceperfile<datastreams::MappedFileStream>(
        m, "init_c_simradrawotherfiledatainterfaceperfile_mapped");
}

}
}
}
}
}