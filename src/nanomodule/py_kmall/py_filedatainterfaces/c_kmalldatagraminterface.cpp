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

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/types.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams.hpp>
#include <themachinethatgoesping/echosounders/kmall/filedatainterfaces/kmalldatagraminterface.hpp>

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"
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

template<typename T_FileStream>
void py_create_class_KMALLDatagramInterface(nanobind::module_& m,
                                                   const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface
    using T_BaseClass = filedatainterfaces::KMALLDatagramInterface<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(m,
                                       CLASS_NAME.c_str(),
                                       DOC(themachinethatgoesping,
                                           echosounders,
                                           kmall,
                                           filedatainterfaces,
                                           KMALLDatagramInterface));

    //----- inherit functions from I_DatagramInterface -----
    KMALLDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_KMALLDatagramInterface(nanobind::module_& m)
{
    static const std::string name        = "KMALLDatagramInterface";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_KMALLDatagramInterface<std::ifstream>(m, name_stream);
    py_create_class_KMALLDatagramInterface<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}