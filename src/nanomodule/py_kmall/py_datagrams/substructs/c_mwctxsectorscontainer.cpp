// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mwctxsectorscontainer.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MWCSectorInfo;
using datagrams::substructs::MWCTxSectorsContainer;

#define DOC_MWCTxSectorsContainer(ARG)                                                             \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                                     \
        datagrams,                                                                                 \
        substructs,                                                                                \
        MWCTxSectorsContainer,                                                                     \
        ARG)

#define DEF_TENSOR(NAME)                                                                           \
    .def("get_" #NAME "_tensor",                                                                   \
         &MWCTxSectorsContainer::get_##NAME##_tensor,                                              \
         DOC_MWCTxSectorsContainer(get_##NAME##_tensor),                                           \
         nb::arg("indices") = std::vector<uint32_t>{})

void init_c_mwctxsectorscontainer(nanobind::module_& m)
{
    nb::class_<MWCTxSectorsContainer>(
        m, "MWCTxSectorsContainer", DOC_MWCTxSectorsContainer(MWCTxSectorsContainer))
        .def(nb::init<>(), DOC_MWCTxSectorsContainer(MWCTxSectorsContainer))

        .def_prop_rw("tx_sectors",
                     &MWCTxSectorsContainer::tx_sectors,
                     &MWCTxSectorsContainer::set_tx_sectors,
                     DOC_MWCTxSectorsContainer(tx_sectors),
                     nb::rv_policy::reference_internal)
        .def("get_tx_sectors",
             &MWCTxSectorsContainer::get_tx_sectors,
             DOC_MWCTxSectorsContainer(get_tx_sectors))
        .def("set_tx_sectors",
             &MWCTxSectorsContainer::set_tx_sectors,
             DOC_MWCTxSectorsContainer(set_tx_sectors),
             nb::arg("tx_sectors"))

        // ----- raw fields -----
        DEF_TENSOR(tilt_angle_re_tx_deg)
        DEF_TENSOR(centre_frequency_hz)
        DEF_TENSOR(tx_beam_width_along_deg)
        DEF_TENSOR(tx_sector_number)
        DEF_TENSOR(padding)

        // ----- size -----
        .def("get_number_of_tx_sectors",
             &MWCTxSectorsContainer::get_number_of_tx_sectors,
             DOC_MWCTxSectorsContainer(get_number_of_tx_sectors))

        // ----- operators -----
        .def("__eq__",
             &MWCTxSectorsContainer::operator==,
             DOC_MWCTxSectorsContainer(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(MWCTxSectorsContainer)
        __PYCLASS_DEFAULT_PRINTING__(MWCTxSectorsContainer)
        ;
}

#undef DEF_TENSOR

}
}
}
}
}
