// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/kmallmultibeamdatagram.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::KMALLMultibeamDatagram;

#define DOC_KMALLMultibeamDatagram(ARG)                                                            \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, KMALLMultibeamDatagram, ARG)

void init_c_kmallmultibeamdatagram(nanobind::module_& m)
{
    nb::class_<KMALLMultibeamDatagram, datagrams::KMALLDatagram>(
        m,
        "KMALLMultibeamDatagram",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, KMALLMultibeamDatagram))

        // --- convenient data access ---
        .def("get_bytes_content",
             &KMALLMultibeamDatagram::get_bytes_content,
             DOC_KMALLMultibeamDatagram(get_bytes_content))
        .def("get_ping_count",
             &KMALLMultibeamDatagram::get_ping_count,
             DOC_KMALLMultibeamDatagram(get_ping_count))
        .def("get_rx_fans_per_ping",
             &KMALLMultibeamDatagram::get_rx_fans_per_ping,
             DOC_KMALLMultibeamDatagram(get_rx_fans_per_ping))
        .def("get_rx_fan_index",
             &KMALLMultibeamDatagram::get_rx_fan_index,
             DOC_KMALLMultibeamDatagram(get_rx_fan_index))
        .def("get_swaths_per_ping",
             &KMALLMultibeamDatagram::get_swaths_per_ping,
             DOC_KMALLMultibeamDatagram(get_swaths_per_ping))
        .def("get_swath_along_position",
             &KMALLMultibeamDatagram::get_swath_along_position,
             DOC_KMALLMultibeamDatagram(get_swath_along_position))
        .def("get_tx_transducer_ind",
             &KMALLMultibeamDatagram::get_tx_transducer_ind,
             DOC_KMALLMultibeamDatagram(get_tx_transducer_ind))
        .def("get_rx_transducer_ind",
             &KMALLMultibeamDatagram::get_rx_transducer_ind,
             DOC_KMALLMultibeamDatagram(get_rx_transducer_ind))
        .def("get_number_of_rx_transducers",
             &KMALLMultibeamDatagram::get_number_of_rx_transducers,
             DOC_KMALLMultibeamDatagram(get_number_of_rx_transducers))
        .def("get_algorithm_type",
             &KMALLMultibeamDatagram::get_algorithm_type,
             DOC_KMALLMultibeamDatagram(get_algorithm_type))

        .def("set_bytes_content",
             &KMALLMultibeamDatagram::set_bytes_content,
             DOC_KMALLMultibeamDatagram(set_bytes_content),
             nb::arg("value"))
        .def("set_ping_count",
             &KMALLMultibeamDatagram::set_ping_count,
             DOC_KMALLMultibeamDatagram(set_ping_count),
             nb::arg("value"))
        .def("set_rx_fans_per_ping",
             &KMALLMultibeamDatagram::set_rx_fans_per_ping,
             DOC_KMALLMultibeamDatagram(set_rx_fans_per_ping),
             nb::arg("value"))
        .def("set_rx_fan_index",
             &KMALLMultibeamDatagram::set_rx_fan_index,
             DOC_KMALLMultibeamDatagram(set_rx_fan_index),
             nb::arg("value"))
        .def("set_swaths_per_ping",
             &KMALLMultibeamDatagram::set_swaths_per_ping,
             DOC_KMALLMultibeamDatagram(set_swaths_per_ping),
             nb::arg("value"))
        .def("set_swath_along_position",
             &KMALLMultibeamDatagram::set_swath_along_position,
             DOC_KMALLMultibeamDatagram(set_swath_along_position),
             nb::arg("value"))
        .def("set_tx_transducer_ind",
             &KMALLMultibeamDatagram::set_tx_transducer_ind,
             DOC_KMALLMultibeamDatagram(set_tx_transducer_ind),
             nb::arg("value"))
        .def("set_rx_transducer_ind",
             &KMALLMultibeamDatagram::set_rx_transducer_ind,
             DOC_KMALLMultibeamDatagram(set_rx_transducer_ind),
             nb::arg("value"))
        .def("set_number_of_rx_transducers",
             &KMALLMultibeamDatagram::set_number_of_rx_transducers,
             DOC_KMALLMultibeamDatagram(set_number_of_rx_transducers),
             nb::arg("value"))
        .def("set_algorithm_type",
             &KMALLMultibeamDatagram::set_algorithm_type,
             DOC_KMALLMultibeamDatagram(set_algorithm_type),
             nb::arg("value"))

        // ----- operators -----
        .def("__eq__",
             &KMALLMultibeamDatagram::operator==,
             DOC_KMALLMultibeamDatagram(operator_eq),
             nb::arg("other"));
}
}
}
}
}
}