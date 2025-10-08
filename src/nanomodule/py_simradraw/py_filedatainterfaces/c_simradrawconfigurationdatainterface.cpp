// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>

#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings
          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/filedatainterfaces/simradrawconfigurationdatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_configurationdatainterface.hpp"
#include "c_simradrawdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatainterfaces {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, simradraw, filedatainterfaces,                              \
        SimradRawConfigurationDataInterface

template<typename T_FileStream>
void py_create_class_SimradRawConfigurationDataInterface(nb::module_& m, const std::string& CLASS_NAME)
{
    using py_filetemplates::py_datainterfaces::py_i_configurationdatainterface::
        ConfigurationDataInterface_add_interface;

    using T_BaseClass = filedatainterfaces::SimradRawConfigurationDataInterface<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX));

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

void init_c_simradrawconfigurationdatainterface(nanobind::module_& m)
{
    static const std::string name        = "SimradRawConfigurationDataInterface";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_SimradRawConfigurationDataInterface<std::ifstream>(
        m, name_stream);
    py_create_class_SimradRawConfigurationDataInterface<datastreams::MappedFileStream>(
        m, name_mapped);
}

}
}
}
}
}