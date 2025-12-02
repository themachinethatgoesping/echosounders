// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/bind_vector.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/mwatercolumn.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::MWaterColumn;

#define DOC_MWaterColumn(ARG)                                                                    \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, MWaterColumn, ARG)

void init_c_mwatercolumn(nanobind::module_& m)
{
    nb::class_<MWaterColumn, datagrams::KMALLMultibeamDatagram>(
        m,
        "MWaterColumn",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, MWaterColumn))
        .def(nb::init<>(), DOC_MWaterColumn(MWaterColumn))

        // --- convenient data access ---
        .def_prop_rw("tx_info",
                     &MWaterColumn::tx_info,
                     &MWaterColumn::set_tx_info,
                     DOC_MWaterColumn(tx_info),
                     nb::rv_policy::reference_internal)
     //    .def_prop_rw("rx_info",
     //                 &MWaterColumn::rx_info,
     //                 &MWaterColumn::set_rx_info,
     //                 DOC_MWaterColumn(rx_info),
     //                 nb::rv_policy::reference_internal)

     //    // ----- sectors etc. -----
        .def_prop_rw("tx_sectors",
                     &MWaterColumn::tx_sectors,
                     &MWaterColumn::set_tx_sectors,
                     DOC_MWaterColumn(tx_sectors),
                     nb::rv_policy::reference_internal)

     //    .def_prop_rw("extra_det_class_info",
     //                 &MWaterColumn::extra_det_class_info,
     //                 &MWaterColumn::set_extra_det_class_info,
     //                 DOC_MWaterColumn(extra_det_class_info),
     //                 nb::rv_policy::reference_internal)

     //    .def_prop_rw("soundings",
     //                 &MWaterColumn::soundings,
     //                 &MWaterColumn::set_soundings,
     //                 DOC_MWaterColumn(soundings),
     //                 nb::rv_policy::reference_internal)

     //    .def("get_seabed_image_samples_dezi_db",
     //         &MWaterColumn::get_seabed_image_samples_dezi_db,
     //         DOC_MWaterColumn(get_seabed_image_samples_dezi_db))
     //    .def("set_seabed_image_samples_dezi_db",
     //         &MWaterColumn::set_seabed_image_samples_dezi_db,
     //         DOC_MWaterColumn(set_seabed_image_samples_dezi_db),
     //         nb::arg("samples"))
     //    .def("get_seabed_image_samples_db",
     //         &MWaterColumn::get_seabed_image_samples_db,
     //         DOC_MWaterColumn(get_seabed_image_samples_db))
     //    .def("set_seabed_image_samples_db",
     //         &MWaterColumn::set_seabed_image_samples_db,
     //         DOC_MWaterColumn(set_seabed_image_samples_db),
     //         nb::arg("samples"))

        // ----- processed -----

        // ----- operators -----
        .def("__eq__",
             &MWaterColumn::operator==,
             DOC_MWaterColumn(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(MWaterColumn)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(MWaterColumn)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(MWaterColumn)
        // end LinearInterpolator
        ;
}
}
}
}
}
}