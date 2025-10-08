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

#include "../../../themachinethatgoesping/echosounders/simradraw/filedatainterfaces/simradrawnavigationdatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_navigationdatainterface.hpp"
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
    themachinethatgoesping, echosounders, simradraw, filedatainterfaces,                           \
        SimradRawNavigationDataInterface

template<typename T_FileStream>
void py_create_class_SimradRawNavigationDataInterface(nb::module_& m, const std::string& CLASS_NAME)
{
    using py_filetemplates::py_datainterfaces::py_i_navigationdatainterface::
        NavigationDataInterface_add_interface;
    using T_BaseClass = filedatainterfaces::SimradRawNavigationDataInterface<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX))
                   .def("set_min_gga_quality",
                        &T_BaseClass::set_min_gga_quality,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simradraw,
                            filedatainterfaces,
                            SimradRawNavigationDataInterface,
                            set_min_gga_quality),
                        nb::arg("min_gga_quality"))
                   .def("set_max_gga_quality",
                        &T_BaseClass::set_max_gga_quality,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simradraw,
                            filedatainterfaces,
                            SimradRawNavigationDataInterface,
                            set_max_gga_quality),
                        nb::arg("max_gga_quality"))
        //
        ;

    //----- inherit functions from I_NavigationDataInterface -----
    NavigationDataInterface_add_interface<T_BaseClass>(cls);
}

void init_c_simradrawnavigationdatainterface(nanobind::module_& m)
{
    static const std::string name        = "SimradRawNavigationDataInterface";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_SimradRawNavigationDataInterface<std::ifstream>(m, name_stream);
    py_create_class_SimradRawNavigationDataInterface<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}