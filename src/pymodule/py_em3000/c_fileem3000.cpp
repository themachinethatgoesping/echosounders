// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
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

#include "../../themachinethatgoesping/echosounders/em3000/em3000_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/em3000/em3000_types.hpp"
#include "../../themachinethatgoesping/echosounders/em3000/fileem3000.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../py_filetemplates/i_inputfile.hpp"
#include "../py_filetemplates/py_datacontainers/datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::em3000;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

// #define CLASS_FILEEM3000(FileEM3000<T_FileStream>, CLASS_NAME)
template<typename T_FileStream>
void py_create_class_FileEM3000(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_InputFile and py_datagramcontainer

    // initialize class
    auto cls = py::class_<FileEM3000<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(themachinethatgoesping, echosounders, em3000, FileEM3000));

    //----- inherit functions from I_InputFile -----
    py_i_InputFile::add_DefaultConstructors(cls);
    py_i_InputFile::add_FileOpenInterface<FileEM3000<T_FileStream>>(cls);
    py_i_InputFile::add_DefaultContainers<FileEM3000<T_FileStream>>(cls);

    //----- containers  -----

    //----- iterators via () operator -----
    // cls.def_property_readonly(
    //     "configuration_interface",
    //     py::overload_cast<>(&FileEM3000<T_FileStream>::configuration_interface),
    //     DOC(themachinethatgoesping, echosounders, em3000, FileEM3000, configuration_interface));
    // cls.def_property_readonly(
    //     "navigation_interface",
    //     py::overload_cast<>(&FileEM3000<T_FileStream>::navigation_interface),
    //     DOC(themachinethatgoesping, echosounders, em3000, FileEM3000, navigation_interface));
    // cls.def_property_readonly(
    //     "environment_interface",
    //     py::overload_cast<>(&FileEM3000<T_FileStream>::environment_interface),
    //     DOC(themachinethatgoesping, echosounders, em3000, FileEM3000, environment_interface));
    // cls.def_property_readonly(
    //     "ping_interface",
    //     py::overload_cast<>(&FileEM3000<T_FileStream>::ping_interface),
    //     DOC(themachinethatgoesping, echosounders, em3000, FileEM3000, ping_interface));
    // cls.def_property_readonly(
    //     "annotation_interface",
    //     py::overload_cast<>(&FileEM3000<T_FileStream>::annotation_interface),
    //     DOC(themachinethatgoesping, echosounders, em3000, FileEM3000, annotation_interface));
    // cls.def_property_readonly(
    //     "otherdata_interface",
    //     py::overload_cast<>(&FileEM3000<T_FileStream>::otherdata_interface),
    //     DOC(themachinethatgoesping, echosounders, em3000, FileEM3000, otherdata_interface));

    // cls.def("pings",
    //         py::overload_cast<>(&FileEM3000<T_FileStream>::pings, py::const_),
    //         DOC(themachinethatgoesping, echosounders, em3000, FileEM3000, pings));
    // cls.def("pings",
    //         py::overload_cast<const std::string&>(&FileEM3000<T_FileStream>::pings, py::const_),
    //         DOC(themachinethatgoesping, echosounders, em3000, FileEM3000, pings_2),
    //         py::arg("channel_id"));
    // cls.def("pings",
    //         py::overload_cast<const std::vector<std::string>&>(&FileEM3000<T_FileStream>::pings,
    //                                                            py::const_),
    //         DOC(themachinethatgoesping, echosounders, em3000, FileEM3000, pings_3),
    //         py::arg("channel_ids"));
    // cls.def("channel_ids",
    //         &FileEM3000<T_FileStream>::channel_ids,
    //         DOC(themachinethatgoesping, echosounders, em3000, FileEM3000, channel_ids));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(FileEM3000<T_FileStream>);
}

void init_c_fileem3000(pybind11::module& m)
{
    py_create_class_FileEM3000<std::ifstream>(m, "FileEM3000");
    py_create_class_FileEM3000<datastreams::MappedFileStream>(m, "FileEM3000_mapped");
}

}
}
}
}