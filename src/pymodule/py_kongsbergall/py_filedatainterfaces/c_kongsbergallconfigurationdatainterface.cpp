// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pytensor.hpp> // Numpy bindings
#include <xtensor/xmath.hpp>          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatainterfaces/kongsbergallconfigurationdatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_configurationdatainterface.hpp"
#include "c_kongsbergalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatainterfaces {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, kongsbergall, filedatainterfaces,                              \
        KongsbergAllConfigurationDataInterface

template<typename T_FileStream>
void py_create_class_KongsbergAllConfigurationDataInterface(py::module& m, const std::string& CLASS_NAME)
{
    using py_filetemplates::py_datainterfaces::py_i_configurationdatainterface::
        ConfigurationDataInterface_add_interface;

    using T_BaseClass = filedatainterfaces::KongsbergAllConfigurationDataInterface<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass>(m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX));

    //----- inherit functions from I_ConfigurationDataInterface -----
    ConfigurationDataInterface_add_interface<T_BaseClass>(cls);

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    // cls __PYCLASS_DEFAULT_PRINTING__(T_BaseClass);
}

void init_c_kongsbergallconfigurationdatainterface(pybind11::module& m)
{
    static const std::string name        = "KongsbergAllConfigurationDataInterface";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_KongsbergAllConfigurationDataInterface<std::ifstream>(
        m, name_stream);
    py_create_class_KongsbergAllConfigurationDataInterface<datastreams::MappedFileStream>(
        m, name_mapped);
}

}
}
}
}
}