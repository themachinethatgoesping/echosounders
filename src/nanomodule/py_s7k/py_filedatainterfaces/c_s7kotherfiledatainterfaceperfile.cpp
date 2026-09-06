// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/variant.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/types.hpp>

#include <themachinethatgoesping/echosounders/s7k/filedatainterfaces/s7kotherfiledatainterfaceperfile.hpp>

#include "../../py_filetemplates/py_datainterfaces/i_filedatainterfaceperfile.hpp"
#include "c_s7kdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatainterfaces {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::s7k;

#define LOCAL_DOC_PREFIX                                                                            \
    themachinethatgoesping, echosounders, s7k, filedatainterfaces, S7KOtherFileDataInterfacePerFile

template<typename T_FileStream>
void py_create_class_S7KOtherFileDataInterfacePerFile(nanobind::module_& m,
                                                      const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces;

    using T_BaseClass = filedatainterfaces::S7KOtherFileDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX));

    //----- inherit functions from I_FileDataInterfacePerFile / I_DatagramInterface -----
    py_i_filedatainterface::FileDataInterfacePerFile_add_interface<T_BaseClass>(cls);
    S7KDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_s7kotherfiledatainterfaceperfile(nanobind::module_& m)
{
    static const std::string name        = "S7KOtherFileDataInterfacePerFile";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_S7KOtherFileDataInterfacePerFile<std::ifstream>(m, name_stream);
    py_create_class_S7KOtherFileDataInterfacePerFile<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}
