// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
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

#define DOC_KongsbergAllConfigurationDataInterfacePerFile(ARG)                                     \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        filedatainterfaces,                                                                        \
        KongsbergAllConfigurationDataInterfacePerFile,                                             \
        ARG)

template<typename T_FileStream>
void py_create_class_KongsbergAllConfigurationDataInterfacePerFile(py::module&        m,
                                                                   const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface

    using T_BaseClass =
        filedatainterfaces::KongsbergAllConfigurationDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls =
        py::class_<T_BaseClass, std::shared_ptr<T_BaseClass>>(
            m,
            CLASS_NAME.c_str(),
            DOC(themachinethatgoesping,
                echosounders,
                kongsbergall,
                filedatainterfaces,
                KongsbergAllConfigurationDataInterfacePerFile))

            .def("read_installation_parameters",
                 &T_BaseClass::read_installation_parameters,
                 DOC_KongsbergAllConfigurationDataInterfacePerFile(read_installation_parameters))

            // ----- runtime parameters -----
            .def("init_runtime_parameters",
                 &T_BaseClass::init_runtime_parameters,
                 DOC_KongsbergAllConfigurationDataInterfacePerFile(init_runtime_parameters))
            .def(
                "get_runtime_parameters",
                [](T_BaseClass& self,
                   uint16_t     system_serial_number,
                   size_t       ping_counter,
                   double       ping_time,
                   size_t       last_index) {
                    return self
                        .get_runtime_parameters(system_serial_number,
                                               ping_counter,
                                               ping_time,
                                               std::make_shared<size_t>(last_index))
                        .get();
                },
                DOC_KongsbergAllConfigurationDataInterfacePerFile(get_runtime_parameters),
                py::arg("system_serial_number"),
                py::arg("ping_counter"),
                py::arg("ping_time"),
                py::arg("last_index") = 0)

            // ----- getters -----
            .def("get_active_position_system_number",
                 &T_BaseClass::get_active_position_system_number,
                 DOC_KongsbergAllConfigurationDataInterfacePerFile(
                     get_active_position_system_number))
            .def("get_active_pitch_roll_sensor",
                 &T_BaseClass::get_active_pitch_roll_sensor,
                 DOC_KongsbergAllConfigurationDataInterfacePerFile(get_active_pitch_roll_sensor))
            .def("get_active_heave_sensor",
                 &T_BaseClass::get_active_heave_sensor,
                 DOC_KongsbergAllConfigurationDataInterfacePerFile(get_active_heave_sensor))
            .def("get_active_heading_sensor",
                 &T_BaseClass::get_active_heading_sensor,
                 DOC_KongsbergAllConfigurationDataInterfacePerFile(get_active_heading_sensor))

            // ----- setters -----
            .def("set_active_position_system_number",
                 &T_BaseClass::set_active_position_system_number,
                 DOC_KongsbergAllConfigurationDataInterfacePerFile(
                     set_active_position_system_number),
                 py::arg("number"))
            .def("set_active_pitch_roll_sensor",
                 &T_BaseClass::set_active_pitch_roll_sensor,
                 DOC_KongsbergAllConfigurationDataInterfacePerFile(set_active_pitch_roll_sensor),
                 py::arg("sensor"))
            .def("set_active_heave_sensor",
                 &T_BaseClass::set_active_heave_sensor,
                 DOC_KongsbergAllConfigurationDataInterfacePerFile(set_active_heave_sensor),
                 py::arg("sensor"))
            .def("set_active_heading_sensor",
                 &T_BaseClass::set_active_heading_sensor,
                 DOC_KongsbergAllConfigurationDataInterfacePerFile(set_active_heading_sensor),
                 py::arg("sensor"))

        ;

    //----- inherit functions from I_DatagramInterface -----
    py_i_configurationdatainterface::ConfigurationDataInterfacePerFile_add_interface<T_BaseClass>(
        cls);
    KongsbergAllDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_kongsbergallconfigurationdatainterfaceperfile(pybind11::module& m)
{
    static const std::string name        = "KongsbergAllConfigurationDataInterfacePerFile";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_KongsbergAllConfigurationDataInterfacePerFile<std::ifstream>(m, name_stream);
    py_create_class_KongsbergAllConfigurationDataInterfacePerFile<datastreams::MappedFileStream>(
        m, name_mapped);
}

}
}
}
}
}