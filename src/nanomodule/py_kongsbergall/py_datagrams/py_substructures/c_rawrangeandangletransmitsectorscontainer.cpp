// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/rawrangeandangletransmitsectorscontainer.hpp"

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::RawRangeAndAngleTransmitSectorsContainer;

#define DOC_RawRangeAndAngleTransmitSectorsContainer(ARG)                                          \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        datagrams,                                                                                 \
        substructures,                                                                             \
        RawRangeAndAngleTransmitSectorsContainer,                                                  \
        ARG)

void init_c_rawrangeandangletransmitsectorscontainer(nanobind::module_& m)
{
    nb::class_<RawRangeAndAngleTransmitSectorsContainer>(
        m,
        "RawRangeAndAngleTransmitSectorsContainer",
        DOC_RawRangeAndAngleTransmitSectorsContainer(RawRangeAndAngleTransmitSectorsContainer))
        .def(nb::init<>(),
             DOC_RawRangeAndAngleTransmitSectorsContainer(RawRangeAndAngleTransmitSectorsContainer))

        .def_prop_rw("transmit_sectors",
                     &RawRangeAndAngleTransmitSectorsContainer::transmit_sectors,
                     &RawRangeAndAngleTransmitSectorsContainer::set_transmit_sectors,
                     DOC_RawRangeAndAngleTransmitSectorsContainer(transmit_sectors),
                     nb::rv_policy::reference_internal)
        .def("get_transmit_sectors",
             &RawRangeAndAngleTransmitSectorsContainer::get_transmit_sectors,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_transmit_sectors))
        .def("set_transmit_sectors",
             &RawRangeAndAngleTransmitSectorsContainer::set_transmit_sectors,
             DOC_RawRangeAndAngleTransmitSectorsContainer(set_transmit_sectors),
             nb::arg("sectors"))

        // ----- raw fields -----
        .def("get_tilt_angle_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_tilt_angle_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_tilt_angle_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_focus_range_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_focus_range_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_focus_range_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_signal_length_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_signal_length_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_signal_length_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_sector_transmit_delay_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_sector_transmit_delay_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_sector_transmit_delay_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_center_frequency_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_center_frequency_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_center_frequency_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_mean_absorption_coefficient_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_mean_absorption_coefficient_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_mean_absorption_coefficient_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_signal_waveform_identifier_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_signal_waveform_identifier_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_signal_waveform_identifier_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_transmit_sector_number_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_transmit_sector_number_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_transmit_sector_number_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_signal_bandwidth_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_signal_bandwidth_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_signal_bandwidth_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})

        // ----- processed -----
        .def("get_tilt_angle_in_degrees_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_tilt_angle_in_degrees_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_tilt_angle_in_degrees_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_focus_range_in_m_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_focus_range_in_m_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_focus_range_in_m_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_mean_absorption_coefficient_in_dB_per_m_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::
                 get_mean_absorption_coefficient_in_dB_per_m_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(
                 get_mean_absorption_coefficient_in_dB_per_m_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_tx_signal_type_tensor",
             &RawRangeAndAngleTransmitSectorsContainer::get_tx_signal_type_tensor,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_tx_signal_type_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})

        // ----- size -----
        .def("get_number_of_transmit_sectors",
             &RawRangeAndAngleTransmitSectorsContainer::get_number_of_transmit_sectors,
             DOC_RawRangeAndAngleTransmitSectorsContainer(get_number_of_transmit_sectors))

        // ----- operators -----
        .def("__eq__",
             &RawRangeAndAngleTransmitSectorsContainer::operator==,
             DOC_RawRangeAndAngleTransmitSectorsContainer(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        __PYCLASS_DEFAULT_COPY__(RawRangeAndAngleTransmitSectorsContainer)
        __PYCLASS_DEFAULT_PRINTING__(RawRangeAndAngleTransmitSectorsContainer)
        ;
}

}
}
}
}
}
}
