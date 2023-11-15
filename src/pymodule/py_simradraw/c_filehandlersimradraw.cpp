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

#include "../../themachinethatgoesping/echosounders/simradraw/filehandlersimradraw.hpp"
#include "../../themachinethatgoesping/echosounders/simradraw/simradraw_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simradraw/simradraw_types.hpp"

#include "module.hpp"

#include "../py_filetemplates/i_inputfilehandler.hpp"
#include "../py_filetemplates/py_datacontainers/datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

// #define CLASS_FILEHANDLERSIMRADRAW(FileHandlerSimradRaw<T_FileStream>, CLASS_NAME)
template<typename T_FileStream>
void py_create_class_FileHandlerSimradRaw(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_inputfilehandler and py_datagramcontainer

    // initialize class
    auto cls = py::class_<FileHandlerSimradRaw<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(themachinethatgoesping, echosounders, simradraw, FileHandlerSimradRaw));

    //----- inherit functions from I_InputFileHandler -----
    py_i_inputfilehandler::add_default_constructors<FileHandlerSimradRaw<T_FileStream>>(cls);
    py_i_inputfilehandler::add_open_file_interface<FileHandlerSimradRaw<T_FileStream>>(cls);
    py_i_inputfilehandler::add_default_containers<FileHandlerSimradRaw<T_FileStream>>(cls);
    // py_i_inputfilehandler::add_DatagramReading<FileHandlerSimradRaw<T_FileStream>,
    //                                    datagrams::t_SimradRawDatagramVariant,
    //                                    datagrams::SimradRawDatagramVariant>(cls);

    //----- containers  -----

    //----- iterators via () operator -----
    cls.def_property_readonly(
        "configuration_interface",
        py::overload_cast<>(&FileHandlerSimradRaw<T_FileStream>::configuration_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, FileHandlerSimradRaw, configuration_interface));
    cls.def_property_readonly(
        "navigation_interface",
        py::overload_cast<>(&FileHandlerSimradRaw<T_FileStream>::navigation_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, FileHandlerSimradRaw, navigation_interface));
    cls.def_property_readonly(
        "environment_interface",
        py::overload_cast<>(&FileHandlerSimradRaw<T_FileStream>::environment_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, FileHandlerSimradRaw, environment_interface));
    cls.def_property_readonly(
        "ping_interface",
        py::overload_cast<>(&FileHandlerSimradRaw<T_FileStream>::ping_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, FileHandlerSimradRaw, ping_interface));
    cls.def_property_readonly(
        "annotation_interface",
        py::overload_cast<>(&FileHandlerSimradRaw<T_FileStream>::annotation_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, FileHandlerSimradRaw, annotation_interface));
    cls.def_property_readonly(
        "otherfiledata_interface",
        py::overload_cast<>(&FileHandlerSimradRaw<T_FileStream>::otherfiledata_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, FileHandlerSimradRaw, otherfiledata_interface));

    cls.def("pings",
            py::overload_cast<>(&FileHandlerSimradRaw<T_FileStream>::pings, py::const_),
            DOC(themachinethatgoesping, echosounders, simradraw, FileHandlerSimradRaw, pings));
    cls.def("pings",
            py::overload_cast<const std::string&>(&FileHandlerSimradRaw<T_FileStream>::pings, py::const_),
            DOC(themachinethatgoesping, echosounders, simradraw, FileHandlerSimradRaw, pings_2),
            py::arg("channel_id"));
    cls.def("pings",
            py::overload_cast<const std::vector<std::string>&>(&FileHandlerSimradRaw<T_FileStream>::pings,
                                                               py::const_),
            DOC(themachinethatgoesping, echosounders, simradraw, FileHandlerSimradRaw, pings_3),
            py::arg("channel_ids"));
    cls.def("channel_ids",
            &FileHandlerSimradRaw<T_FileStream>::channel_ids,
            DOC(themachinethatgoesping, echosounders, simradraw, FileHandlerSimradRaw, channel_ids));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(FileHandlerSimradRaw<T_FileStream>);
}

void init_c_filehandlersimradraw(pybind11::module& m)
{
    // add index class
    //py_i_inputfilehandler::add_file_index_types<simradraw::t_SimradRawDatagramIdentifier>(m, "FileInfoData_raw");

    py_create_class_FileHandlerSimradRaw<std::ifstream>(m, "FileHandlerSimradRaw");
    py_create_class_FileHandlerSimradRaw<datastreams::MappedFileStream>(m, "FileHandlerSimradRaw_mapped");
}

}
}
}
}