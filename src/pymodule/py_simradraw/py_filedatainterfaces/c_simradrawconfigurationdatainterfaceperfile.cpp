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

#include "../../../themachinethatgoesping/echosounders/simradraw/filedatainterfaces/simradrawconfigurationdatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_configurationdatainterface.hpp"
#include "c_simradrawdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatainterfaces {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, simradraw, filedatainterfaces,                              \
        SimradRawConfigurationDataInterface

template<typename T_FileStream>
void py_create_class_SimradRawConfigurationDataInterfacePerFile(py::module&        m,
                                                             const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    using T_BaseClass = filedatainterfaces::SimradRawConfigurationDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass, std::shared_ptr<T_BaseClass>>(
                   m,
                   CLASS_NAME.c_str(),
                   DOC(themachinethatgoesping,
                       echosounders,
                       simradraw,
                       filedatainterfaces,
                       SimradRawConfigurationDataInterfacePerFile))

                   .def("get_configuration_datagram",
                        &T_BaseClass::get_configuration_datagram,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simradraw,
                            filedatainterfaces,
                            SimradRawConfigurationDataInterfacePerFile,
                            get_configuration_datagram))
                   .def("get_position_sources",
                        &T_BaseClass::get_position_sources,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simradraw,
                            filedatainterfaces,
                            SimradRawConfigurationDataInterfacePerFile,
                            get_position_sources))
                   .def("get_depth_sources",
                        &T_BaseClass::get_depth_sources,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simradraw,
                            filedatainterfaces,
                            SimradRawConfigurationDataInterfacePerFile,
                            get_depth_sources))
                   .def("get_attitude_sources",
                        &T_BaseClass::get_attitude_sources,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simradraw,
                            filedatainterfaces,
                            SimradRawConfigurationDataInterfacePerFile,
                            get_attitude_sources))
                   .def("get_heading_sources",
                        &T_BaseClass::get_heading_sources,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simradraw,
                            filedatainterfaces,
                            SimradRawConfigurationDataInterfacePerFile,
                            get_heading_sources))
        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_i_configurationdatainterface::ConfigurationDataInterfacePerFile_add_interface<T_BaseClass>(
        cls);
    SimradRawDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_simradrawconfigurationdatainterfaceperfile(pybind11::module& m)
{

    py_create_class_SimradRawConfigurationDataInterfacePerFile<std::ifstream>(
        m, "SimradRawConfigurationDataInterfacePerFile");
    py_create_class_SimradRawConfigurationDataInterfacePerFile<datastreams::MappedFileStream>(
        m, "SimradRawConfigurationDataInterfacePerFile_mapped");
}

}
}
}
}
}