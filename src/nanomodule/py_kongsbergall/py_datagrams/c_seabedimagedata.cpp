// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>


#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/seabedimagedata.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::SeabedImageData;

#define DOC_SeabedImageData(ARG)                                                                   \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, SeabedImageData, ARG)

void init_c_seabedimagedata(nanobind::module_& m)
{
     nb::class_<SeabedImageData, datagrams::KongsbergAllDatagram>(
        m,
        "SeabedImageData",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, SeabedImageData))
     .def(nb::init<>(), DOC_SeabedImageData(SeabedImageData))
        // --- convenient data access ---
        .def("set_ping_counter",
             &SeabedImageData::set_ping_counter,
             DOC_SeabedImageData(ping_counter))
        .def("get_ping_counter",
             &SeabedImageData::get_ping_counter,
             DOC_SeabedImageData(ping_counter))
        .def("set_system_serial_number",
             &SeabedImageData::set_system_serial_number,
             DOC_SeabedImageData(system_serial_number))
        .def("get_system_serial_number",
             &SeabedImageData::get_system_serial_number,
             DOC_SeabedImageData(system_serial_number))
        .def("set_sampling_frequency",
             &SeabedImageData::set_sampling_frequency,
             DOC_SeabedImageData(sampling_frequency))
        .def("get_sampling_frequency",
             &SeabedImageData::get_sampling_frequency,
             DOC_SeabedImageData(sampling_frequency))
        .def("set_range_to_normal_incidence",
             &SeabedImageData::set_range_to_normal_incidence,
             DOC_SeabedImageData(range_to_normal_incidence))
        .def("get_range_to_normal_incidence",
             &SeabedImageData::get_range_to_normal_incidence,
             DOC_SeabedImageData(range_to_normal_incidence))
        .def("set_normal_incidence_backscatter",
             &SeabedImageData::set_normal_incidence_backscatter,
             DOC_SeabedImageData(normal_incidence_backscatter))
        .def("get_normal_incidence_backscatter",
             &SeabedImageData::get_normal_incidence_backscatter,
             DOC_SeabedImageData(normal_incidence_backscatter))
        .def("set_oblique_backscatter",
             &SeabedImageData::set_oblique_backscatter,
             DOC_SeabedImageData(oblique_backscatter))
        .def("get_oblique_backscatter",
             &SeabedImageData::get_oblique_backscatter,
             DOC_SeabedImageData(oblique_backscatter))
        .def("set_tx_beamwidth_along",
             &SeabedImageData::set_tx_beamwidth_along,
             DOC_SeabedImageData(tx_beamwidth_along))
        .def("get_tx_beamwidth_along",
             &SeabedImageData::get_tx_beamwidth_along,
             DOC_SeabedImageData(tx_beamwidth_along))
        .def("set_tvg_law_crossover_angle",
             &SeabedImageData::set_tvg_law_crossover_angle,
             DOC_SeabedImageData(tvg_law_crossover_angle))
        .def("get_tvg_law_crossover_angle",
             &SeabedImageData::get_tvg_law_crossover_angle,
             DOC_SeabedImageData(tvg_law_crossover_angle))
        .def("set_number_of_valid_beams",
             &SeabedImageData::set_number_of_valid_beams,
             DOC_SeabedImageData(number_of_valid_beams))
        .def("get_number_of_valid_beams",
             &SeabedImageData::get_number_of_valid_beams,
             DOC_SeabedImageData(number_of_valid_beams))
        .def("set_spare_byte", &SeabedImageData::set_spare_byte, DOC_SeabedImageData(spare_byte))
        .def("get_spare_byte", &SeabedImageData::get_spare_byte, DOC_SeabedImageData(spare_byte))

        // --- data structure access ---
        .def("get_beams",
             &SeabedImageData::get_beams,
             DOC_SeabedImageData(beams),
             nb::rv_policy::reference_internal)
        .def("set_beams", &SeabedImageData::set_beams, DOC_SeabedImageData(beams))
        .def("beams",
             &SeabedImageData::beams,
             DOC_SeabedImageData(beams),
             nb::rv_policy::reference_internal)
        .def("get_sample_amplitudes",
             &SeabedImageData::get_sample_amplitudes,
             DOC_SeabedImageData(sample_amplitudes),
             nb::rv_policy::reference_internal)
        .def("set_sample_amplitudes",
             &SeabedImageData::set_sample_amplitudes,
             DOC_SeabedImageData(sample_amplitudes))
        .def("sample_amplitudes",
             &SeabedImageData::sample_amplitudes,
             DOC_SeabedImageData(sample_amplitudes),
             nb::rv_policy::reference_internal)

        // --- processed member access ---
        .def("get_normal_incidence_backscatter_in_db",
             &SeabedImageData::get_normal_incidence_backscatter_in_db,
             DOC_SeabedImageData(get_normal_incidence_backscatter_in_db))
        .def("get_oblique_backscatter_in_db",
             &SeabedImageData::get_oblique_backscatter_in_db,
             DOC_SeabedImageData(get_oblique_backscatter_in_db))
        .def("get_tx_beamwidth_along_in_degrees",
             &SeabedImageData::get_tx_beamwidth_along_in_degrees,
             DOC_SeabedImageData(get_tx_beamwidth_along_in_degrees))
        .def("get_tvg_law_crossover_angle_in_degrees",
             &SeabedImageData::get_tvg_law_crossover_angle_in_degrees,
             DOC_SeabedImageData(get_tvg_law_crossover_angle_in_degrees))

        // --- checksum access ---
        .def("get_etx", &SeabedImageData::get_etx, DOC_SeabedImageData(etx))
        .def("set_etx", &SeabedImageData::set_etx, DOC_SeabedImageData(etx))
        .def("get_checksum", &SeabedImageData::get_checksum, DOC_SeabedImageData(checksum))
        .def("set_checksum", &SeabedImageData::set_checksum, DOC_SeabedImageData(checksum))

        // ----- operators -----
        .def("__eq__",
             &SeabedImageData::operator==,
             DOC_SeabedImageData(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SeabedImageData)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SeabedImageData)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SeabedImageData)
        // end LinearInterpolator
        ;
}
}
}
}
}
}