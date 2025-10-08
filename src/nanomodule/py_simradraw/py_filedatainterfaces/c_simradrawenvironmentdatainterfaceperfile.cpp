// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>

#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings
          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/filedatainterfaces/simradrawenvironmentdatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_environmentdatainterface.hpp"
#include "c_simradrawdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatainterfaces {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, simradraw, filedatainterfaces,                           \
        SimradRawEnvironmentDataInterface

template<typename T_FileStream>
void py_create_class_SimradRawEnvironmentDataInterfacePerFile(nb::module_&        m,
                                                              const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    using T_BaseClass = filedatainterfaces::SimradRawEnvironmentDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping,
            echosounders,
            simradraw,
            filedatainterfaces,
            SimradRawEnvironmentDataInterfacePerFile))

        // .def("get_environment_datagram",
        //      &T_BaseClass::get_environment_datagram,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          simradraw, filedatainterfaces,
        //          SimradRawEnvironmentDataInterfacePerFile,
        //          get_environment_datagram))

        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_filetemplates::py_datainterfaces::py_i_environmentdatainterface::
        EnvironmentDataInterfacePerFile_add_interface<T_BaseClass>(cls);
    SimradRawDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_simradrawenvironmentdatainterfaceperfile(nanobind::module_& m)
{
    static const std::string name        = "SimradRawEnvironmentDataInterfacePerFile";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_SimradRawEnvironmentDataInterfacePerFile<std::ifstream>(m, name_stream);
    py_create_class_SimradRawEnvironmentDataInterfacePerFile<datastreams::MappedFileStream>(
        m, name_mapped);
}

}
}
}
}
}