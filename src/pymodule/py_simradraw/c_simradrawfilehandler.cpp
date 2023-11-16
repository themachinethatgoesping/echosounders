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

#include "../../themachinethatgoesping/echosounders/simradraw/simradrawfilehandler.hpp"
#include "../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simradraw/types.hpp"

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

// #define CLASS_SIMRADRAWFILEHANDLER(SimradRawFileHandler<T_FileStream>, CLASS_NAME)
template<typename T_FileStream>
void py_create_class_SimradRawFileHandler(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_inputfilehandler and py_datagramcontainer

    // initialize class
    auto cls = py::class_<SimradRawFileHandler<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(themachinethatgoesping, echosounders, simradraw, SimradRawFileHandler));

    //----- inherit functions from I_InputFileHandler -----
    py_i_inputfilehandler::add_default_constructors<SimradRawFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_open_file_interface<SimradRawFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_default_containers<SimradRawFileHandler<T_FileStream>>(cls);
    // py_i_inputfilehandler::add_DatagramReading<SimradRawFileHandler<T_FileStream>,
    //                                    datagrams::t_SimradRawDatagramVariant,
    //                                    datagrams::SimradRawDatagramVariant>(cls);

    //----- containers  -----

    //----- iterators via () operator -----
    cls.def_property_readonly(
        "configuration_interface",
        py::overload_cast<>(&SimradRawFileHandler<T_FileStream>::configuration_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, SimradRawFileHandler, configuration_interface));
    cls.def_property_readonly(
        "navigation_interface",
        py::overload_cast<>(&SimradRawFileHandler<T_FileStream>::navigation_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, SimradRawFileHandler, navigation_interface));
    cls.def_property_readonly(
        "environment_interface",
        py::overload_cast<>(&SimradRawFileHandler<T_FileStream>::environment_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, SimradRawFileHandler, environment_interface));
    cls.def_property_readonly(
        "ping_interface",
        py::overload_cast<>(&SimradRawFileHandler<T_FileStream>::ping_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, SimradRawFileHandler, ping_interface));
    cls.def_property_readonly(
        "annotation_interface",
        py::overload_cast<>(&SimradRawFileHandler<T_FileStream>::annotation_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, SimradRawFileHandler, annotation_interface));
    cls.def_property_readonly(
        "otherfiledata_interface",
        py::overload_cast<>(&SimradRawFileHandler<T_FileStream>::otherfiledata_interface),
        DOC(themachinethatgoesping, echosounders, simradraw, SimradRawFileHandler, otherfiledata_interface));

    cls.def("pings",
            py::overload_cast<bool>(&SimradRawFileHandler<T_FileStream>::pings, py::const_),
            py::arg("sorted_by_time") = true,
            DOC(themachinethatgoesping, echosounders, simradraw, SimradRawFileHandler, pings));
            
    cls.def("channel_ids",
            &SimradRawFileHandler<T_FileStream>::channel_ids,
            DOC(themachinethatgoesping, echosounders, simradraw, SimradRawFileHandler, channel_ids));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(SimradRawFileHandler<T_FileStream>);
}

void init_c_simradrawfilehandler(pybind11::module& m)
{
    // add index class
    //py_i_inputfilehandler::add_file_index_types<simradraw::t_SimradRawDatagramIdentifier>(m, "FileInfoData_raw");

    py_create_class_SimradRawFileHandler<std::ifstream>(m, "SimradRawFileHandler");
    py_create_class_SimradRawFileHandler<datastreams::MappedFileStream>(m, "SimradRawFileHandler_mapped");
}

}
}
}
}