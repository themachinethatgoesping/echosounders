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

#include <themachinethatgoesping/echosounders/kmall/filedatainterfaces/kmallpingdatainterface.hpp>

#include "../../py_filetemplates/py_datainterfaces/i_pingdatainterface.hpp"
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

#define DOC_KMALLPingDataInterfacePerFile(ARG)                                              \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                              \
        filedatainterfaces,                                                                        \
        KMALLPingDataInterfacePerFile,                                                      \
        ARG)

template<typename T_FileStream>
void py_create_class_kmallpingdatainterfacePerFile(nanobind::module_& m,
                                                          const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_DatagramInterface and
                                      // py_i_DatagramInterface

    using T_BaseClass = filedatainterfaces::KMALLPingDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping,
            echosounders,
            kmall,
            filedatainterfaces,
            KMALLPingDataInterfacePerFile))

        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_filetemplates::py_datainterfaces::py_i_pingdatainterface::
        PingDataInterfacePerFile_add_interface<T_BaseClass>(cls);
    KMALLDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_kmallpingdatainterfaceperfile(nanobind::module_& m)
{
    static const std::string name        = "KMALLPingDataInterfacePerFile";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kmallpingdatainterfacePerFile<std::ifstream>(m, name_stream);
    py_create_class_kmallpingdatainterfacePerFile<datastreams::MappedFileStream>(
        m, name_mapped);
}

}
}
}
}
}