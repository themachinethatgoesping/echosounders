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

#include "../../themachinethatgoesping/echosounders/gsf/types.hpp"
#include "../../themachinethatgoesping/echosounders/gsf/datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/gsf/gsffilehandler.hpp"

#include "module.hpp"

#include "../py_filetemplates/i_inputfilehandler.hpp"
#include "../py_filetemplates/py_datacontainers/datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_gsf {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::gsf;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define DOC_GSFFileHandler(ARG)                                                           \
    DOC(themachinethatgoesping, echosounders, gsf, GSFFileHandler, ARG)

// #define CLASS_GSFFileHandler(GSFFileHandler<T_FileStream>, CLASS_NAME)
template<typename T_FileStream>
void py_create_class_gsffilehandler(nb::module_& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_inputfilehandler and py_datagramcontainer

    // initialize class
    auto cls = nb::class_<GSFFileHandler<T_FileStream>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, gsf, GSFFileHandler));

    //----- inherit functions from I_InputFileHandler -----
    py_i_inputfilehandler::add_default_constructors<GSFFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_open_file_interface<GSFFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_default_containers<GSFFileHandler<T_FileStream>>(cls);

    //----- containers  -----

    //----- iterators via () operator -----
    // cls.def_prop_ro(
    //     "datagramdata_interface",
    //     nb::overload_cast<>(&GSFFileHandler<T_FileStream>::datagramdata_interface),
    //     DOC_GSFFileHandler(datagramdata_interface));
    // cls.def_prop_ro(
    //     "configuration_interface",
    //     nb::overload_cast<>(&GSFFileHandler<T_FileStream>::configuration_interface),
    //     DOC_GSFFileHandler(configuration_interface));
    // cls.def_prop_ro(
    //     "navigation_interface",
    //     nb::overload_cast<>(&GSFFileHandler<T_FileStream>::navigation_interface),
    //     DOC_GSFFileHandler(navigation_interface));
    // cls.def_prop_ro(
    //     "environment_interface",
    //     nb::overload_cast<>(&GSFFileHandler<T_FileStream>::environment_interface),
    //     DOC_GSFFileHandler(environment_interface));
    // cls.def_prop_ro(
    //     "annotation_interface",
    //     nb::overload_cast<>(&GSFFileHandler<T_FileStream>::annotation_interface),
    //     DOC_GSFFileHandler(annotation_interface));
    // cls.def_prop_ro(
    //     "otherfiledata_interface",
    //     nb::overload_cast<>(&GSFFileHandler<T_FileStream>::otherfiledata_interface),
    //     DOC_GSFFileHandler(otherfiledata_interface));
    // cls.def_prop_ro(
    //     "ping_interface",
    //     nb::overload_cast<>(&GSFFileHandler<T_FileStream>::ping_interface),
    //     DOC_GSFFileHandler(ping_interface));

    // cls.def("get_pings",
    //         nb::overload_cast<bool>(&GSFFileHandler<T_FileStream>::get_pings, nb::const_),
    //         nb::arg("sorted_by_time") = true,
    //         DOC_GSFFileHandler(get_pings));
    // cls.def("get_channel_ids",
    //         &GSFFileHandler<T_FileStream>::get_channel_ids,
    //         DOC_GSFFileHandler(get_channel_ids));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(GSFFileHandler<T_FileStream>);
}

void init_c_gsffilehandler(nanobind::module_& m)
{
    static const std::string name        = "GSFFileHandler";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_gsffilehandler<std::ifstream>(m, name_stream);
    py_create_class_gsffilehandler<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}