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
    themachinethatgoesping, echosounders, simradraw, filedatainterfaces,                           \
        SimradRawConfigurationDataInterface

template<typename T_FileStream>
void py_create_class_SimradRawConfigurationDataInterfacePerFile(nb::module_&        m,
                                                                const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    using T_BaseClass =
        filedatainterfaces::SimradRawConfigurationDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(
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
                //    .def("read_fil1_datagrams",
                //         &T_BaseClass::read_fil1_datagrams,
                //         DOC(themachinethatgoesping,
                //             echosounders,
                //             simradraw,
                //             filedatainterfaces,
                //             SimradRawConfigurationDataInterfacePerFile,
                //             read_fil1_datagrams))
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

void init_c_simradrawconfigurationdatainterfaceperfile(nanobind::module_& m)
{
    static const std::string name        = "SimradRawConfigurationDataInterfacePerFile";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_SimradRawConfigurationDataInterfacePerFile<std::ifstream>(m, name_stream);
    py_create_class_SimradRawConfigurationDataInterfacePerFile<datastreams::MappedFileStream>(
        m, name_mapped);
}

}
}
}
}
}