// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <chrono>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/types.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams.hpp>
#include <themachinethatgoesping/echosounders/kmall/filedatainterfaces/kmallconfigurationdatainterfaceperfile.hpp>

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_configurationdatainterfaceperfile.hpp"
#include "c_kmalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatainterfaces {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::kmall;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define DOC_KMALLConfigurationDataInterfacePerFile(ARG)                                     \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                              \
        filedatainterfaces,                                                                        \
        KMALLConfigurationDataInterfacePerFile,                                             \
        ARG)

template<typename T_FileStream>
void py_create_class_KMALLConfigurationDataInterfacePerFile(nanobind::module_& m,
                                                                   const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    using T_BaseClass =
        filedatainterfaces::KMALLConfigurationDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls =
        nb::class_<T_BaseClass>(
            m,
            CLASS_NAME.c_str(),
            DOC(themachinethatgoesping,
                echosounders,
                kmall,
                filedatainterfaces,
                KMALLConfigurationDataInterfacePerFile))

            .def("read_installation_parameters",
                 &T_BaseClass::read_installation_parameters,
                 DOC_KMALLConfigurationDataInterfacePerFile(read_installation_parameters))

            // ----- runtime parameters -----
            .def("init_runtime_parameters",
                 &T_BaseClass::init_runtime_parameters,
                 DOC_KMALLConfigurationDataInterfacePerFile(init_runtime_parameters))
            .def(
                "get_runtime_parameters",
                [](T_BaseClass& self, int pu_serial_number, double ping_time, size_t last_index) {
                    return self
                        .get_runtime_parameters(
                            pu_serial_number, ping_time, std::make_shared<size_t>(last_index))
                        .get();
                },
                DOC_KMALLConfigurationDataInterfacePerFile(get_runtime_parameters),
                nb::arg("pu_serial_number"),
                nb::arg("ping_time"),
                nb::arg("last_index") = 0)

            // ----- getters -----
            .def("get_active_position_system_number",
                 &T_BaseClass::get_active_position_system_number,
                 DOC_KMALLConfigurationDataInterfacePerFile(get_active_position_system_number))
            .def("get_active_attitude_sensor_number",
                 &T_BaseClass::get_active_attitude_sensor_number,
                 DOC_KMALLConfigurationDataInterfacePerFile(get_active_attitude_sensor_number))

            // ----- setters -----
            .def("set_active_position_system_number",
                 &T_BaseClass::set_active_position_system_number,
                 DOC_KMALLConfigurationDataInterfacePerFile(set_active_position_system_number),
                 nb::arg("number"))
            .def("set_active_attitude_sensor_number",
                 &T_BaseClass::set_active_attitude_sensor_number,
                 DOC_KMALLConfigurationDataInterfacePerFile(set_active_attitude_sensor_number),
                 nb::arg("number"))

        ;

    //----- inherit functions from I_DatagramInterface -----
    py_i_configurationdatainterface::ConfigurationDataInterfacePerFile_add_interface<T_BaseClass>(
        cls);
    KMALLDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_kmallconfigurationdatainterfaceperfile(nanobind::module_& m)
{
    static const std::string name        = "KMALLConfigurationDataInterfacePerFile";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_KMALLConfigurationDataInterfacePerFile<std::ifstream>(m, name_stream);
    py_create_class_KMALLConfigurationDataInterfacePerFile<datastreams::MappedFileStream>(
        m, name_mapped);
}

}
}
}
}
}