// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/em3000/em3000_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/em3000/em3000_types.hpp"
#include "../../../themachinethatgoesping/echosounders/em3000/filedatatypes/em3000ping.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

#include "../py_filedatainterfaces/c_em3000datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_EM3000PingRawData(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, em3000, filedatatypes, EM3000PingRawData, ARG)

template<typename T_FileStream>
void py_create_class_em3000pingrawdata(py::module& m, const std::string& CLASS_NAME)
{
    using t_EM3000PingRawData = filedatatypes::EM3000PingRawData<T_FileStream>;

    auto cls =
        py::class_<t_EM3000PingRawData, std::shared_ptr<t_EM3000PingRawData>>(
            m,
            (CLASS_NAME).c_str(),
            DOC(themachinethatgoesping, echosounders, em3000, filedatatypes, EM3000PingRawData))

            // --- substructure access ---
            .def("get_runtime_parameters",
                 &t_EM3000PingRawData::get_runtime_parameters,
                 DOC_EM3000PingRawData(get_runtime_parameters))

            // --- raw_data data access ---
            .def("read_merged_watercolumndatagram",
                 &t_EM3000PingRawData::read_merged_watercolumndatagram,
                 DOC_EM3000PingRawData(read_merged_watercolumndatagram),
                 py::arg("skip_data") = false)

            .def("read_all_samples",
                 &t_EM3000PingRawData::read_all_samples,
                 DOC_EM3000PingRawData(read_all_samples))
            .def("read_selected_samples",
                 &t_EM3000PingRawData::read_selected_samples,
                 DOC_EM3000PingRawData(read_selected_samples),
                 py::arg("selection"))

            // --- getter/setter ---
            .def("get_beam_pointing_angles",
                 py::overload_cast<>(&t_EM3000PingRawData::get_beam_pointing_angles, py::const_),
                 DOC_EM3000PingRawData(get_beam_pointing_angles))
            .def("get_beam_pointing_angles",
                 py::overload_cast<const pingtools::substructures::BeamSampleSelection&>(
                     &t_EM3000PingRawData::get_beam_pointing_angles, py::const_),
                 DOC_EM3000PingRawData(get_beam_pointing_angles_2),
                 py::arg("selection"))

            .def("get_start_range_sample_numbers",
                 py::overload_cast<>(&t_EM3000PingRawData::get_start_range_sample_numbers,
                                     py::const_),
                 DOC_EM3000PingRawData(get_start_range_sample_numbers))
            .def("get_number_of_samples_per_beam",
                 py::overload_cast<>(&t_EM3000PingRawData::get_number_of_samples_per_beam,
                                     py::const_),
                 DOC_EM3000PingRawData(get_number_of_samples_per_beam))

            .def("get_detected_range_in_samples",
                 &t_EM3000PingRawData::get_detected_range_in_samples,
                 DOC_EM3000PingRawData(get_detected_range_in_samples))
            .def("get_transmit_sector_numbers",
                 &t_EM3000PingRawData::get_transmit_sector_numbers,
                 DOC_EM3000PingRawData(get_transmit_sector_numbers))
            .def("get_number_of_beams",
                 &t_EM3000PingRawData::get_number_of_beams,
                 DOC_EM3000PingRawData(get_number_of_beams))
            .def("get_water_column_datagram",
                 &t_EM3000PingRawData::get_water_column_datagram,
                 DOC_EM3000PingRawData(get_water_column_datagram),
                 py::return_value_policy::reference_internal)

            // --- load data ---
            .def("load_datagrams",
                 &t_EM3000PingRawData::load_datagrams,
                 DOC_EM3000PingRawData(load_datagrams),
                 py::arg("skip_data") = true)

        // .def_readonly("ping_data",
        //               &t_EM3000PingRawData::_ping_data,
        //               DOC_EM3000PingRawData(ping_data),
        //               py::return_value_policy::reference_internal)
        // .def("get_parameter",
        //      &t_EM3000PingRawData::get_parameter,
        //      DOC_EM3000PingRawData(get_parameter))

        // .def("get_sample_data",
        //      &t_EM3000PingRawData::get_sample_data,
        //      DOC_EM3000PingRawData(get_sample_data))

        // .def("has_angle", &t_EM3000PingRawData::has_angle, DOC_EM3000PingRawData(has_angle))
        // .def("has_power", &t_EM3000PingRawData::has_power, DOC_EM3000PingRawData(has_power))

        // .def("load_data", &t_EM3000PingRawData::load_data, DOC_EM3000PingRawData(load_data))
        // .def(
        //     "release_data", &t_EM3000PingRawData::release_data,
        //     DOC_EM3000PingRawData(release_data))

        // ----- this is also commented out in simrad equivalent-----
        // ----- operators -----
        // .def("__eq__",
        //      &EM3000Ping::operator==,
        //      DOC(themachinethatgoesping, echosounders, em3000, filedatatypes,  EM3000Ping,
        //      operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_EM3000PingRawData)
        // default binary functions
        __PYCLASS_DEFAULT_PRINTING__(t_EM3000PingRawData)
        // end EM3000Ping
        ;

    // inherit from EM3000DatagramInterface
    py_filedatainterfaces::EM3000DatagramInterface_add_interface_functions<t_EM3000PingRawData>(
        cls);
    // py_i_datagraminterface::add_InterfaceFunctions<t_EM3000PingRawData>(cls);
}

void init_c_em3000pingrawdata(pybind11::module& m)
{

    py_create_class_em3000pingrawdata<std::ifstream>(m, "EM3000PingRawData");
    py_create_class_em3000pingrawdata<datastreams::MappedFileStream>(m, "EM3000PingRawData_mapped");
}

}
}
}
}
}