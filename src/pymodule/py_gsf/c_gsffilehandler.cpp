// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pytensor.hpp> // Numpy bindings
          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

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

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::gsf;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define DOC_GSFFileHandler(ARG)                                                           \
    DOC(themachinethatgoesping, echosounders, gsf, GSFFileHandler, ARG)

// #define CLASS_GSFFileHandler(GSFFileHandler<T_FileStream>, CLASS_NAME)
template<typename T_FileStream>
void py_create_class_gsffilehandler(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_inputfilehandler and py_datagramcontainer

    // initialize class
    auto cls = py::class_<GSFFileHandler<T_FileStream>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, gsf, GSFFileHandler));

    //----- inherit functions from I_InputFileHandler -----
    py_i_inputfilehandler::add_default_constructors<GSFFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_open_file_interface<GSFFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_default_containers<GSFFileHandler<T_FileStream>>(cls);

    //----- containers  -----

    //----- iterators via () operator -----
    // cls.def_property_readonly(
    //     "datagramdata_interface",
    //     py::overload_cast<>(&GSFFileHandler<T_FileStream>::datagramdata_interface),
    //     DOC_GSFFileHandler(datagramdata_interface));
    // cls.def_property_readonly(
    //     "configuration_interface",
    //     py::overload_cast<>(&GSFFileHandler<T_FileStream>::configuration_interface),
    //     DOC_GSFFileHandler(configuration_interface));
    // cls.def_property_readonly(
    //     "navigation_interface",
    //     py::overload_cast<>(&GSFFileHandler<T_FileStream>::navigation_interface),
    //     DOC_GSFFileHandler(navigation_interface));
    // cls.def_property_readonly(
    //     "environment_interface",
    //     py::overload_cast<>(&GSFFileHandler<T_FileStream>::environment_interface),
    //     DOC_GSFFileHandler(environment_interface));
    // cls.def_property_readonly(
    //     "annotation_interface",
    //     py::overload_cast<>(&GSFFileHandler<T_FileStream>::annotation_interface),
    //     DOC_GSFFileHandler(annotation_interface));
    // cls.def_property_readonly(
    //     "otherfiledata_interface",
    //     py::overload_cast<>(&GSFFileHandler<T_FileStream>::otherfiledata_interface),
    //     DOC_GSFFileHandler(otherfiledata_interface));
    // cls.def_property_readonly(
    //     "ping_interface",
    //     py::overload_cast<>(&GSFFileHandler<T_FileStream>::ping_interface),
    //     DOC_GSFFileHandler(ping_interface));

    // cls.def("get_pings",
    //         py::overload_cast<bool>(&GSFFileHandler<T_FileStream>::get_pings, py::const_),
    //         py::arg("sorted_by_time") = true,
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

void init_c_gsffilehandler(pybind11::module& m)
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