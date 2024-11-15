// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pytensor.hpp> // Numpy bindings
#include <xtensor/xmath.hpp>          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatainterfaces/kongsbergallannotationdatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_annotationdatainterface.hpp"

#include "c_kongsbergalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatainterfaces {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, kongsbergall, filedatainterfaces, KongsbergAllAnnotationDataInterface

template<typename T_FileStream>
void py_create_class_KongsbergAllAnnotationDataInterfacePerFile(py::module&        m,
                                                          const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    using T_BaseClass = filedatainterfaces::KongsbergAllAnnotationDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass, std::shared_ptr<T_BaseClass>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping,
            echosounders,
            kongsbergall,
            filedatainterfaces,
            KongsbergAllAnnotationDataInterfacePerFile))

        // .def("get_annotation_datagram",
        //      &T_BaseClass::get_annotation_datagram,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          kongsbergall, filedatainterfaces,
        //          KongsbergAllAnnotationDataInterfacePerFile,
        //          get_annotation_datagram))

        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_i_annotationdatainterface::AnnotationDataInterfacePerFile_add_interface<T_BaseClass>(cls);
    KongsbergAllDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_kongsbergallannotationdatainterfaceperfile(pybind11::module& m)
{
    static const std::string name        = "KongsbergAllAnnotationDataInterfacePerFile";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_KongsbergAllAnnotationDataInterfacePerFile<std::ifstream>(
        m, name_stream);
    py_create_class_KongsbergAllAnnotationDataInterfacePerFile<datastreams::MappedFileStream>(
        m, name_mapped);
}

}
}
}
}
}