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

#include "../../themachinethatgoesping/echosounders/simrad/simradenvironmentdatainterface.hpp"

#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_environmentdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, simrad, SimradEnvironmentDataInterface

template<typename T_FileStream>
void py_create_class_SimradEnvironmentDataInterface(py::module& m, const std::string& CLASS_NAME)
{
    using py_fileinterfaces::py_i_EnvironmentDataInterface::EnvironmentDataInterface_add_interface;

    // initialize class
    auto cls = py::class_<SimradEnvironmentDataInterface<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX));

    //----- inherit functions from I_EnvironmentDataInterface -----
    EnvironmentDataInterface_add_interface<SimradEnvironmentDataInterface<T_FileStream>>(cls);

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    // cls __PYCLASS_DEFAULT_PRINTING__(SimradEnvironmentDataInterface<T_FileStream>);
}

void init_c_SimradEnvironmentDataInterface(pybind11::module& m)
{

    py_create_class_SimradEnvironmentDataInterface<std::ifstream>(m,
                                                                  "SimradEnvironmentDataInterface");
    py_create_class_SimradEnvironmentDataInterface<MappedFileStream>(
        m, "SimradEnvironmentDataInterface_mapped");
}

}
}
}
}