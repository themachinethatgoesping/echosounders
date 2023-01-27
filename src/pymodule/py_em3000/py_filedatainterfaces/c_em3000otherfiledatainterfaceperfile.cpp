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

#include "../../../themachinethatgoesping/echosounders/em3000/filedatainterfaces/em3000otherfiledatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_filedatainterface.hpp"
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
    themachinethatgoesping, echosounders, em3000, filedatainterfaces, EM3000OtherFileDataInterface

template<typename T_FileStream>
void py_create_class_EM3000OtherFileDataInterfacePerFile(py::module&        m,
                                                         const std::string& CLASS_NAME)
{

    using T_BaseClass = filedatainterfaces::EM3000OtherFileDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass>(m,
                                       CLASS_NAME.c_str(),
                                       DOC(themachinethatgoesping,
                                           echosounders,
                                           em3000,
                                           filedatainterfaces,
                                           EM3000OtherFileDataInterfacePerFile))

        // .def("get_other_datagram",
        //      &T_BaseClass::get_other_datagram,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          em3000, filedatainterfaces,
        //          EM3000OtherFileDataInterfacePerFile,
        //          get_other_datagram))

        //
        ;

    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    //----- inherit functions from I_DatagramInterface -----
    py_i_filedatainterface::FileDataInterfacePerFile_add_interface<T_BaseClass>(cls);
    EM3000DatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_em3000otherFileDataInterfacePerFile(pybind11::module& m)
{

    py_create_class_EM3000OtherFileDataInterfacePerFile<std::ifstream>(
        m, "EM3000OtherFileDataInterfacePerFile");
    py_create_class_EM3000OtherFileDataInterfacePerFile<datastreams::MappedFileStream>(
        m, "EM3000OtherFileDataInterfacePerFile_mapped");
}

}
}
}
}
}