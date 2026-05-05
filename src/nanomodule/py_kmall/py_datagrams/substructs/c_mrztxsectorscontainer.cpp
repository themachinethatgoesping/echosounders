// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrztxsectorscontainer.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MRZSectorInfo;
using datagrams::substructs::MRZTxSectorsContainer;

#define DOC_MRZTxSectorsContainer(ARG)                                                             \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                                     \
        datagrams,                                                                                 \
        substructs,                                                                                \
        MRZTxSectorsContainer,                                                                     \
        ARG)

#define DEF_TENSOR(NAME)                                                                           \
    .def("get_" #NAME "_tensor",                                                                   \
         &MRZTxSectorsContainer::get_##NAME##_tensor,                                              \
         DOC_MRZTxSectorsContainer(get_##NAME##_tensor),                                           \
         nb::arg("indices") = std::vector<uint32_t>{})

void init_c_mrztxsectorscontainer(nanobind::module_& m)
{
    nb::class_<MRZTxSectorsContainer>(
        m, "MRZTxSectorsContainer", DOC_MRZTxSectorsContainer(MRZTxSectorsContainer))
        .def(nb::init<>(), DOC_MRZTxSectorsContainer(MRZTxSectorsContainer))

        .def_prop_rw("tx_sectors",
                     &MRZTxSectorsContainer::tx_sectors,
                     &MRZTxSectorsContainer::set_tx_sectors,
                     DOC_MRZTxSectorsContainer(tx_sectors),
                     nb::rv_policy::reference_internal)
        .def("get_tx_sectors",
             &MRZTxSectorsContainer::get_tx_sectors,
             DOC_MRZTxSectorsContainer(get_tx_sectors))
        .def("set_tx_sectors",
             &MRZTxSectorsContainer::set_tx_sectors,
             DOC_MRZTxSectorsContainer(set_tx_sectors),
             nb::arg("tx_sectors"))

        // ----- raw fields -----
        DEF_TENSOR(tx_sector_number)
        DEF_TENSOR(tx_arrary_number)
        DEF_TENSOR(tx_sub_array)
        DEF_TENSOR(padding_0)
        DEF_TENSOR(sector_transmit_delay_sec)
        DEF_TENSOR(tilt_angle_re_tx_deg)
        DEF_TENSOR(tx_nominal_source_level_db)
        DEF_TENSOR(tx_focus_range_m)
        DEF_TENSOR(centre_frequency_hz)
        DEF_TENSOR(signal_band_width_hz)
        DEF_TENSOR(total_signal_length_sec)
        DEF_TENSOR(pulse_shading)
        DEF_TENSOR(signal_wave_form)
        DEF_TENSOR(padding_1)
        DEF_TENSOR(high_voltage_level_db)
        DEF_TENSOR(sector_tracking_corr_db)
        DEF_TENSOR(effective_signal_length_sec)

        // ----- processed -----
        DEF_TENSOR(tx_signal_type)

        // ----- size -----
        .def("get_number_of_tx_sectors",
             &MRZTxSectorsContainer::get_number_of_tx_sectors,
             DOC_MRZTxSectorsContainer(get_number_of_tx_sectors))

        // ----- operators -----
        .def("__eq__",
             &MRZTxSectorsContainer::operator==,
             DOC_MRZTxSectorsContainer(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(MRZTxSectorsContainer)
        __PYCLASS_DEFAULT_PRINTING__(MRZTxSectorsContainer)
        ;
}

#undef DEF_TENSOR

}
}
}
}
}
