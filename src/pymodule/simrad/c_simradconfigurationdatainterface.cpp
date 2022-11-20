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

#include "../../themachinethatgoesping/echosounders/simrad/simradconfigurationdatainterface.hpp"

#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_configurationdatainterface.hpp"
#include "c_simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, simrad, SimradConfigurationDataInterface

template<typename T_FileStream>
void py_create_class_SimradConfigurationDataCollection(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_fileinterfaces; // this holds py_i_DatagramInterface and
                                       // py_i_DatagramInterface

    // initialize class
    auto cls = py::class_<SimradConfigurationDataCollection<T_FileStream>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simrad, SimradConfigurationDataCollection));

    //----- inherit functions from I_DatagramInterface -----
    py_i_ConfigurationDataInterface::ConfigurationDataCollection_add_interface<
        SimradConfigurationDataCollection<T_FileStream>>(cls);
    SimradDatagramInterface_add_interface_functions<SimradConfigurationDataCollection<T_FileStream>>(cls);
}

template<typename T_FileStream>
void py_create_class_SimradConfigurationDataInterface(py::module& m, const std::string& CLASS_NAME)
{
    using py_fileinterfaces::py_i_ConfigurationDataInterface::
        ConfigurationDataInterface_add_interface;

    // initialize class
    auto cls = py::class_<SimradConfigurationDataInterface<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX));

    //----- inherit functions from I_ConfigurationDataInterface -----
    ConfigurationDataInterface_add_interface<SimradConfigurationDataInterface<T_FileStream>>(cls);

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    // cls __PYCLASS_DEFAULT_PRINTING__(SimradConfigurationDataInterface<T_FileStream>);
}

void init_c_SimradConfigurationDataInterface(pybind11::module& m)
{

    py_create_class_SimradConfigurationDataCollection<std::ifstream>(
        m, "SimradConfigurationDataCollection");
    py_create_class_SimradConfigurationDataCollection<MappedFileStream>(
        m, "SimradConfigurationDataCollection_mapped");

    py_create_class_SimradConfigurationDataInterface<std::ifstream>(
        m, "SimradConfigurationDataInterface");
    py_create_class_SimradConfigurationDataInterface<MappedFileStream>(
        m, "SimradConfigurationDataInterface_mapped");
}

}
}
}
}