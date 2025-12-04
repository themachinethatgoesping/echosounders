// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/unordered_map.h>
#include <nanobind/stl/vector.h>

#include <chrono>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/kmall/types.hpp"
#include "../../themachinethatgoesping/echosounders/kmall/datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/kmall/kmallfilehandler.hpp"

#include "module.hpp"

#include "../py_filetemplates/i_inputfilehandler.hpp"
#include "../py_filetemplates/py_datacontainers/datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::kmall;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define DOC_KMALLFileHandler(ARG)                                                           \
    DOC(themachinethatgoesping, echosounders, kmall, KMALLFileHandler, ARG)

// #define CLASS_KMALLFileHandler(KMALLFileHandler<T_FileStream>, CLASS_NAME)
template<typename T_FileStream>
void py_create_class_kmallfilehandler(nb::module_& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_inputfilehandler and py_datagramcontainer

    // initialize class
    auto cls = nb::class_<KMALLFileHandler<T_FileStream>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, kmall, KMALLFileHandler));

    //----- inherit functions from I_InputFileHandler -----
    py_i_inputfilehandler::add_default_constructors<KMALLFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_open_file_interface<KMALLFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_default_containers<KMALLFileHandler<T_FileStream>>(cls);

    //----- containers  -----

    //----- iterators via () operator -----
    // cls.def_prop_ro(
    //     "datagramdata_interface",
    //     nb::overload_cast<>(&KMALLFileHandler<T_FileStream>::datagramdata_interface),
    //     DOC_KMALLFileHandler(datagramdata_interface));
    // cls.def_prop_ro(
    //     "configuration_interface",
    //     nb::overload_cast<>(&KMALLFileHandler<T_FileStream>::configuration_interface),
    //     DOC_KMALLFileHandler(configuration_interface));
    // cls.def_prop_ro(
    //     "navigation_interface",
    //     nb::overload_cast<>(&KMALLFileHandler<T_FileStream>::navigation_interface),
    //     DOC_KMALLFileHandler(navigation_interface));
    // cls.def_prop_ro(
    //     "environment_interface",
    //     nb::overload_cast<>(&KMALLFileHandler<T_FileStream>::environment_interface),
    //     DOC_KMALLFileHandler(environment_interface));
    // cls.def_prop_ro(
    //     "otherfiledata_interface",
    //     nb::overload_cast<>(&KMALLFileHandler<T_FileStream>::otherfiledata_interface),
    //     DOC_KMALLFileHandler(otherfiledata_interface));
    // cls.def_prop_ro(
    //     "ping_interface",
    //     nb::overload_cast<>(&KMALLFileHandler<T_FileStream>::ping_interface),
    //     DOC_KMALLFileHandler(ping_interface));

    // cls.def("get_pings",
    //         nb::overload_cast<bool>(&KMALLFileHandler<T_FileStream>::get_pings, nb::const_),
    //         nb::arg("sorted_by_time") = true,
    //         DOC_KMALLFileHandler(get_pings));
    // cls.def("get_channel_ids",
    //         &KMALLFileHandler<T_FileStream>::get_channel_ids,
    //         DOC_KMALLFileHandler(get_channel_ids));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(KMALLFileHandler<T_FileStream>);
}

void init_c_kmallfilehandler(nanobind::module_& m)
{
    static const std::string name        = "KMALLFileHandler";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kmallfilehandler<std::ifstream>(m, name_stream);
    py_create_class_kmallfilehandler<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}