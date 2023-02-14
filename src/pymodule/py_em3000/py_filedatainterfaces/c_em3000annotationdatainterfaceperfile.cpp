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

#include "../../../themachinethatgoesping/echosounders/em3000/filedatainterfaces/em3000annotationdatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_annotationdatainterface.hpp"

#include "c_em3000datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatainterfaces {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::em3000;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, em3000, filedatainterfaces, EM3000AnnotationDataInterface

template<typename T_FileStream>
void py_create_class_EM3000AnnotationDataInterfacePerFile(py::module&        m,
                                                          const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    using T_BaseClass = filedatainterfaces::EM3000AnnotationDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass, std::shared_ptr<T_BaseClass>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping,
            echosounders,
            em3000,
            filedatainterfaces,
            EM3000AnnotationDataInterfacePerFile))

        // .def("get_annotation_datagram",
        //      &T_BaseClass::get_annotation_datagram,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          em3000, filedatainterfaces,
        //          EM3000AnnotationDataInterfacePerFile,
        //          get_annotation_datagram))

        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_i_annotationdatainterface::AnnotationDataInterfacePerFile_add_interface<T_BaseClass>(cls);
    EM3000DatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_em3000annotationdatainterfaceperfile(pybind11::module& m)
{

    py_create_class_EM3000AnnotationDataInterfacePerFile<std::ifstream>(
        m, "EM3000AnnotationDataInterfacePerFile");
    py_create_class_EM3000AnnotationDataInterfacePerFile<datastreams::MappedFileStream>(
        m, "EM3000AnnotationDataInterfacePerFile_mapped");
}

}
}
}
}
}