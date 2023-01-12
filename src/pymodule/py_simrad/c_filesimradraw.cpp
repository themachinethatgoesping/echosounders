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

#include "../../themachinethatgoesping/echosounders/simrad/filesimradraw.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"

#include "module.hpp"

#include "../py_filetemplates/i_inputfile.hpp"
#include "../py_filetemplates/py_datacontainers/datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

// #define CLASS_FILESIMRADRAW(FileSimradRaw<T_FileStream>, CLASS_NAME)
template<typename T_FileStream>
void py_create_class_FileSimradRaw(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_InputFile and py_datagramcontainer

    // initialize class
    auto cls = py::class_<FileSimradRaw<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(themachinethatgoesping, echosounders, simrad, FileSimradRaw));

    //----- inherit functions from I_InputFile -----
    py_i_InputFile::add_DefaultConstructors(cls);
    py_i_InputFile::add_FileOpenInterface<FileSimradRaw<T_FileStream>>(cls);
    py_i_InputFile::add_DefaultContainers<FileSimradRaw<T_FileStream>>(cls);
    // py_i_InputFile::add_DatagramReading<FileSimradRaw<T_FileStream>,
    //                                    datagrams::t_SimradDatagramVariant,
    //                                    datagrams::SimradDatagramVariant>(cls);

    //----- containers  -----

    //----- iterators via () operator -----
    cls.def_property_readonly(
        "configuration_interface",
        py::overload_cast<>(&FileSimradRaw<T_FileStream>::configuration_interface),
        DOC(themachinethatgoesping, echosounders, simrad, FileSimradRaw, configuration_interface));
    cls.def_property_readonly(
        "navigation_interface",
        py::overload_cast<>(&FileSimradRaw<T_FileStream>::navigation_interface),
        DOC(themachinethatgoesping, echosounders, simrad, FileSimradRaw, navigation_interface));
    cls.def_property_readonly(
        "environment_interface",
        py::overload_cast<>(&FileSimradRaw<T_FileStream>::environment_interface),
        DOC(themachinethatgoesping, echosounders, simrad, FileSimradRaw, environment_interface));
    cls.def_property_readonly(
        "ping_interface",
        py::overload_cast<>(&FileSimradRaw<T_FileStream>::ping_interface),
        DOC(themachinethatgoesping, echosounders, simrad, FileSimradRaw, ping_interface));
    cls.def_property_readonly(
        "annotation_interface",
        py::overload_cast<>(&FileSimradRaw<T_FileStream>::annotation_interface),
        DOC(themachinethatgoesping, echosounders, simrad, FileSimradRaw, annotation_interface));
    cls.def_property_readonly(
        "otherdata_interface",
        py::overload_cast<>(&FileSimradRaw<T_FileStream>::otherdata_interface),
        DOC(themachinethatgoesping, echosounders, simrad, FileSimradRaw, otherdata_interface));

    cls.def("pings",
            py::overload_cast<>(&FileSimradRaw<T_FileStream>::pings, py::const_),
            DOC(themachinethatgoesping, echosounders, simrad, FileSimradRaw, pings));
    cls.def("pings",
            py::overload_cast<const std::string&>(&FileSimradRaw<T_FileStream>::pings, py::const_),
            DOC(themachinethatgoesping, echosounders, simrad, FileSimradRaw, pings_2),
            py::arg("channel_id"));
    cls.def("pings",
            py::overload_cast<const std::vector<std::string>&>(&FileSimradRaw<T_FileStream>::pings,
                                                               py::const_),
            DOC(themachinethatgoesping, echosounders, simrad, FileSimradRaw, pings_3),
            py::arg("channel_ids"));
    cls.def("channel_ids",
            &FileSimradRaw<T_FileStream>::channel_ids,
            DOC(themachinethatgoesping, echosounders, simrad, FileSimradRaw, channel_ids));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(FileSimradRaw<T_FileStream>);
}

void init_c_filesimradraw(pybind11::module& m)
{
    py_create_class_FileSimradRaw<std::ifstream>(m, "FileSimradRaw");
    py_create_class_FileSimradRaw<datastreams::MappedFileStream>(m, "FileSimradRaw_mapped");
}

}
}
}
}