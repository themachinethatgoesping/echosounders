// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/watercolumndatagramtransmitsectorscontainer.hpp"

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::WatercolumnDatagramTransmitSectorsContainer;

#define DOC_WCDTSC(ARG)                                                                            \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        datagrams,                                                                                 \
        substructures,                                                                             \
        WatercolumnDatagramTransmitSectorsContainer,                                               \
        ARG)

void init_c_watercolumndatagramtransmitsectorscontainer(nanobind::module_& m)
{
    nb::class_<WatercolumnDatagramTransmitSectorsContainer>(
        m,
        "WatercolumnDatagramTransmitSectorsContainer",
        DOC_WCDTSC(WatercolumnDatagramTransmitSectorsContainer))
        .def(nb::init<>(), DOC_WCDTSC(WatercolumnDatagramTransmitSectorsContainer))

        .def_prop_rw("transmit_sectors",
                     &WatercolumnDatagramTransmitSectorsContainer::transmit_sectors,
                     &WatercolumnDatagramTransmitSectorsContainer::set_transmit_sectors,
                     DOC_WCDTSC(transmit_sectors),
                     nb::rv_policy::reference_internal)
        .def("get_transmit_sectors",
             &WatercolumnDatagramTransmitSectorsContainer::get_transmit_sectors,
             DOC_WCDTSC(get_transmit_sectors))
        .def("set_transmit_sectors",
             &WatercolumnDatagramTransmitSectorsContainer::set_transmit_sectors,
             DOC_WCDTSC(set_transmit_sectors),
             nb::arg("transmit_sectors"))

        // ----- raw fields -----
        .def("get_tilt_angle_tensor",
             &WatercolumnDatagramTransmitSectorsContainer::get_tilt_angle_tensor,
             DOC_WCDTSC(get_tilt_angle_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_center_frequency_tensor",
             &WatercolumnDatagramTransmitSectorsContainer::get_center_frequency_tensor,
             DOC_WCDTSC(get_center_frequency_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_transmit_sector_number_tensor",
             &WatercolumnDatagramTransmitSectorsContainer::get_transmit_sector_number_tensor,
             DOC_WCDTSC(get_transmit_sector_number_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_spare_tensor",
             &WatercolumnDatagramTransmitSectorsContainer::get_spare_tensor,
             DOC_WCDTSC(get_spare_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})

        // ----- processed -----
        .def("get_tilt_angle_in_degrees_tensor",
             &WatercolumnDatagramTransmitSectorsContainer::get_tilt_angle_in_degrees_tensor,
             DOC_WCDTSC(get_tilt_angle_in_degrees_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})
        .def("get_center_frequency_in_hz_tensor",
             &WatercolumnDatagramTransmitSectorsContainer::get_center_frequency_in_hz_tensor,
             DOC_WCDTSC(get_center_frequency_in_hz_tensor),
             nb::arg("sector_numbers") = std::vector<uint32_t>{})

        // ----- size -----
        .def("get_number_of_transmit_sectors",
             &WatercolumnDatagramTransmitSectorsContainer::get_number_of_transmit_sectors,
             DOC_WCDTSC(get_number_of_transmit_sectors))

        // ----- operators -----
        .def("__eq__",
             &WatercolumnDatagramTransmitSectorsContainer::operator==,
             DOC_WCDTSC(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(WatercolumnDatagramTransmitSectorsContainer)
        __PYCLASS_DEFAULT_PRINTING__(WatercolumnDatagramTransmitSectorsContainer)
        ;
}

}
}
}
}
}
}
