// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/variant.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams.hpp>
#include <themachinethatgoesping/echosounders/s7k/filedatatypes/s7kpingfiledata.hpp>
#include <themachinethatgoesping/echosounders/s7k/types.hpp>

#include "../py_filedatainterfaces/c_s7kdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_S7KPingFileData(ARG)                                                                   \
    DOC(themachinethatgoesping, echosounders, s7k, filedatatypes, S7KPingFileData, ARG)

template<typename T_FileStream>
void py_create_class_s7kpingfiledata(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_S7KPingFileData = filedatatypes::S7KPingFileData<T_FileStream>;

    auto cls = nb::class_<t_S7KPingFileData, datatypes::I_PingFileData>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, s7k, filedatatypes, S7KPingFileData))

        // ----- nanobind macros -----
        __PYCLASS_DEFAULT_COPY__(t_S7KPingFileData)
            __PYCLASS_DEFAULT_PRINTING__(t_S7KPingFileData)
        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_filedatainterfaces::S7KDatagramInterface_add_interface_functions<t_S7KPingFileData>(cls);
}

void init_c_s7kpingfiledata(nanobind::module_& m)
{
    static const std::string name        = "S7KPingFileData";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_s7kpingfiledata<std::ifstream>(m, name_stream);
    py_create_class_s7kpingfiledata<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}
