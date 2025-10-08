// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings
          // xtensor import for the C++ universal functions

#include <fstream>
#include <string>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simradraw/simradrawfilehandler.hpp"
#include "../../themachinethatgoesping/echosounders/simradraw/types.hpp"

#include "module.hpp"

#include "../py_filetemplates/i_inputfilehandler.hpp"
#include "../py_filetemplates/py_datacontainers/datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define DOC_SimradRawFileHandler(ARG)                                                              \
    DOC(themachinethatgoesping, echosounders, simradraw, SimradRawFileHandler, ARG)

// #define CLASS_SIMRADRAWFILEHANDLER(SimradRawFileHandler<T_FileStream>, CLASS_NAME)
template<typename T_FileStream>
void py_create_class_SimradRawFileHandler(nb::module_& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_inputfilehandler and py_datagramcontainer

    // initialize class
    auto cls = nb::class_<SimradRawFileHandler<T_FileStream>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simradraw, SimradRawFileHandler));

    //----- inherit functions from I_InputFileHandler -----
    py_i_inputfilehandler::add_default_constructors<SimradRawFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_open_file_interface<SimradRawFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_default_containers<SimradRawFileHandler<T_FileStream>>(cls);
    // py_i_inputfilehandler::add_DatagramReading<SimradRawFileHandler<T_FileStream>,
    //                                    datagrams::t_SimradRawDatagramVariant,
    //                                    datagrams::SimradRawDatagramVariant>(cls);

    //----- containers  -----

    //----- iterators via () operator -----
    cls.def_prop_ro(
        "datagramdata_interface",
        nb::overload_cast<>(&SimradRawFileHandler<T_FileStream>::datagramdata_interface),
        DOC_SimradRawFileHandler(datagramdata_interface));
    cls.def_prop_ro(
        "configuration_interface",
        nb::overload_cast<>(&SimradRawFileHandler<T_FileStream>::configuration_interface),
        DOC_SimradRawFileHandler(configuration_interface));
    cls.def_prop_ro(
        "navigation_interface",
        nb::overload_cast<>(&SimradRawFileHandler<T_FileStream>::navigation_interface),
        DOC_SimradRawFileHandler(navigation_interface));
    cls.def_prop_ro(
        "environment_interface",
        nb::overload_cast<>(&SimradRawFileHandler<T_FileStream>::environment_interface),
        DOC_SimradRawFileHandler(environment_interface));
    cls.def_prop_ro(
        "ping_interface",
        nb::overload_cast<>(&SimradRawFileHandler<T_FileStream>::ping_interface),
        DOC_SimradRawFileHandler(ping_interface));
    cls.def_prop_ro(
        "annotation_interface",
        nb::overload_cast<>(&SimradRawFileHandler<T_FileStream>::annotation_interface),
        DOC_SimradRawFileHandler(annotation_interface));
    cls.def_prop_ro(
        "otherfiledata_interface",
        nb::overload_cast<>(&SimradRawFileHandler<T_FileStream>::otherfiledata_interface),
        DOC_SimradRawFileHandler(otherfiledata_interface));

    cls.def("get_pings",
            nb::overload_cast<bool>(&SimradRawFileHandler<T_FileStream>::get_pings, nb::const_),
            nb::arg("sorted_by_time") = true,
            DOC_SimradRawFileHandler(get_pings));

    cls.def("get_channel_ids",
            &SimradRawFileHandler<T_FileStream>::get_channel_ids,
            DOC_SimradRawFileHandler(get_channel_ids));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(SimradRawFileHandler<T_FileStream>);
}

void init_c_simradrawfilehandler(nanobind::module_& m)
{
    static const std::string name        = "SimradRawFileHandler";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_SimradRawFileHandler<std::ifstream>(m, name_stream);
    py_create_class_SimradRawFileHandler<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}