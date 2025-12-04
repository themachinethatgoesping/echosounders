// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/types.hpp>

#include <themachinethatgoesping/echosounders/kmall/filedatainterfaces/kmallenvironmentdatainterface.hpp>

#include "../../py_filetemplates/py_datainterfaces/i_environmentdatainterface.hpp"
#include "c_kmalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatainterfaces {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::kmall;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, kmall, filedatainterfaces,                        \
        KMALLEnvironmentDataInterface

template<typename T_FileStream>
void py_create_class_KMALLEnvironmentDataInterfacePerFile(nanobind::module_& m,
                                                                 const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    using T_BaseClass =
        filedatainterfaces::KMALLEnvironmentDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping,
            echosounders,
            kmall,
            filedatainterfaces,
            KMALLEnvironmentDataInterfacePerFile))

        // .def("get_environment_datagram",
        //      &T_BaseClass::get_environment_datagram,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          kmall, filedatainterfaces,
        //          KMALLEnvironmentDataInterfacePerFile,
        //          get_environment_datagram))

        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_filetemplates::py_datainterfaces::py_i_environmentdatainterface::
        EnvironmentDataInterfacePerFile_add_interface<T_BaseClass>(cls);
    KMALLDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_kmallenvironmentdatainterfaceperfile(nanobind::module_& m)
{
    static const std::string name        = "KMALLEnvironmentDataInterfacePerFile";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_KMALLEnvironmentDataInterfacePerFile<std::ifstream>(m, name_stream);
    py_create_class_KMALLEnvironmentDataInterfacePerFile<datastreams::MappedFileStream>(
        m, name_mapped);
}

}
}
}
}
}