// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pytensor.hpp> // Numpy bindings
          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kongsbergall/types.hpp>

#include <themachinethatgoesping/echosounders/kongsbergall/filedatainterfaces/kongsbergallenvironmentdatainterface.hpp>

#include "../../py_filetemplates/py_datainterfaces/i_environmentdatainterface.hpp"
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
    themachinethatgoesping, echosounders, kongsbergall, filedatainterfaces,                        \
        KongsbergAllEnvironmentDataInterface

template<typename T_FileStream>
void py_create_class_KongsbergAllEnvironmentDataInterface(py::module&        m,
                                                          const std::string& CLASS_NAME)
{
    using py_filetemplates::py_datainterfaces::py_i_environmentdatainterface::
        EnvironmentDataInterface_add_interface;

    using T_BaseClass = filedatainterfaces::KongsbergAllEnvironmentDataInterface<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass>(m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX));

    //----- inherit functions from I_EnvironmentDataInterface -----
    EnvironmentDataInterface_add_interface<T_BaseClass>(cls);

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    // cls __PYCLASS_DEFAULT_PRINTING__(T_BaseClass);
}

void init_c_kongsbergallenvironmentdatainterface(pybind11::module& m)
{
    static const std::string name        = "KongsbergAllEnvironmentDataInterface";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_KongsbergAllEnvironmentDataInterface<std::ifstream>(m, name_stream);
    py_create_class_KongsbergAllEnvironmentDataInterface<datastreams::MappedFileStream>(
        m, name_mapped);
}

}
}
}
}
}