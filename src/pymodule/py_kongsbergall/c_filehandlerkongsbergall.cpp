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

#include "../../themachinethatgoesping/echosounders/kongsbergall/kongsbergall_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/kongsbergall/kongsbergall_types.hpp"
#include "../../themachinethatgoesping/echosounders/kongsbergall/filehandlerkongsbergall.hpp"

#include "module.hpp"

#include "../py_filetemplates/i_inputfilehandler.hpp"
#include "../py_filetemplates/py_datacontainers/datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define DOC_FileHandlerKongsbergAll(ARG) DOC(themachinethatgoesping, echosounders, kongsbergall, FileHandlerKongsbergAll, ARG)

// #define CLASS_FileHandlerKongsbergAll(FileHandlerKongsbergAll<T_FileStream>, CLASS_NAME)
template<typename T_FileStream>
void py_create_class_filehandlerkongsbergall(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_inputfilehandler and py_datagramcontainer

    // initialize class
    auto cls = py::class_<FileHandlerKongsbergAll<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(themachinethatgoesping, echosounders, kongsbergall, FileHandlerKongsbergAll));

    //----- inherit functions from I_InputFileHandler -----
    py_i_inputfilehandler::add_default_constructors<FileHandlerKongsbergAll<T_FileStream>>(cls);
    py_i_inputfilehandler::add_open_file_interface<FileHandlerKongsbergAll<T_FileStream>>(cls);
    py_i_inputfilehandler::add_default_containers<FileHandlerKongsbergAll<T_FileStream>>(cls);

    //----- containers  -----

    //----- iterators via () operator -----
    cls.def_property_readonly(
        "datagramdata_interface",
        py::overload_cast<>(&FileHandlerKongsbergAll<T_FileStream>::datagramdata_interface),
        DOC_FileHandlerKongsbergAll(datagramdata_interface));
    cls.def_property_readonly(
        "configuration_interface",
        py::overload_cast<>(&FileHandlerKongsbergAll<T_FileStream>::configuration_interface),
        DOC_FileHandlerKongsbergAll(configuration_interface));
    cls.def_property_readonly("navigation_interface",
                              py::overload_cast<>(&FileHandlerKongsbergAll<T_FileStream>::navigation_interface),
                              DOC_FileHandlerKongsbergAll(navigation_interface));
    cls.def_property_readonly("environment_interface",
                              py::overload_cast<>(&FileHandlerKongsbergAll<T_FileStream>::environment_interface),
                              DOC_FileHandlerKongsbergAll(environment_interface));
    cls.def_property_readonly("annotation_interface",
                              py::overload_cast<>(&FileHandlerKongsbergAll<T_FileStream>::annotation_interface),
                              DOC_FileHandlerKongsbergAll(annotation_interface));
    cls.def_property_readonly(
        "otherfiledata_interface",
        py::overload_cast<>(&FileHandlerKongsbergAll<T_FileStream>::otherfiledata_interface),
        DOC_FileHandlerKongsbergAll(otherfiledata_interface));
    cls.def_property_readonly("ping_interface",
                              py::overload_cast<>(&FileHandlerKongsbergAll<T_FileStream>::ping_interface),
                              DOC_FileHandlerKongsbergAll(ping_interface));

    cls.def("pings",
            py::overload_cast<>(&FileHandlerKongsbergAll<T_FileStream>::pings, py::const_),
            DOC_FileHandlerKongsbergAll(pings));
    cls.def("pings",
            py::overload_cast<const std::string&>(&FileHandlerKongsbergAll<T_FileStream>::pings, py::const_),
            DOC_FileHandlerKongsbergAll(pings_2),
            py::arg("channel_id"));
    cls.def("pings",
            py::overload_cast<const std::vector<std::string>&>(&FileHandlerKongsbergAll<T_FileStream>::pings,
                                                               py::const_),
            DOC_FileHandlerKongsbergAll(pings_3),
            py::arg("channel_ids"));
    cls.def("channel_ids", &FileHandlerKongsbergAll<T_FileStream>::channel_ids, DOC_FileHandlerKongsbergAll(channel_ids));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(FileHandlerKongsbergAll<T_FileStream>);
}

void init_c_filehandlerkongsbergall(pybind11::module& m)
{
    py_create_class_filehandlerkongsbergall<std::ifstream>(m, "FileHandlerKongsbergAll");
    py_create_class_filehandlerkongsbergall<datastreams::MappedFileStream>(m, "FileHandlerKongsbergAll_mapped");
}

}
}
}
}