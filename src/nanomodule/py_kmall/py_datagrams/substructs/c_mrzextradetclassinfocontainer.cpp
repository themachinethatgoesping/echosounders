// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzextradetclassinfocontainer.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MRZExtraDetClassInfo;
using datagrams::substructs::MRZExtraDetClassInfoContainer;

#define DOC_MRZEDCIC(ARG)                                                                          \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                                     \
        datagrams,                                                                                 \
        substructs,                                                                                \
        MRZExtraDetClassInfoContainer,                                                             \
        ARG)

void init_c_mrzextradetclassinfocontainer(nanobind::module_& m)
{
    nb::class_<MRZExtraDetClassInfoContainer>(
        m, "MRZExtraDetClassInfoContainer", DOC_MRZEDCIC(MRZExtraDetClassInfoContainer))
        .def(nb::init<>(), DOC_MRZEDCIC(MRZExtraDetClassInfoContainer))

        .def_prop_rw("extra_det_class_info",
                     &MRZExtraDetClassInfoContainer::extra_det_class_info,
                     &MRZExtraDetClassInfoContainer::set_extra_det_class_info,
                     DOC_MRZEDCIC(extra_det_class_info),
                     nb::rv_policy::reference_internal)
        .def("get_extra_det_class_info",
             &MRZExtraDetClassInfoContainer::get_extra_det_class_info,
             DOC_MRZEDCIC(get_extra_det_class_info))
        .def("set_extra_det_class_info",
             &MRZExtraDetClassInfoContainer::set_extra_det_class_info,
             DOC_MRZEDCIC(set_extra_det_class_info),
             nb::arg("extra_det_class_info"))

        // ----- raw fields -----
        .def("get_num_extra_det_in_class_tensor",
             &MRZExtraDetClassInfoContainer::get_num_extra_det_in_class_tensor,
             DOC_MRZEDCIC(get_num_extra_det_in_class_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_padding_tensor",
             &MRZExtraDetClassInfoContainer::get_padding_tensor,
             DOC_MRZEDCIC(get_padding_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_alarm_flag_tensor",
             &MRZExtraDetClassInfoContainer::get_alarm_flag_tensor,
             DOC_MRZEDCIC(get_alarm_flag_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})

        // ----- size -----
        .def("get_number_of_extra_det_class_info",
             &MRZExtraDetClassInfoContainer::get_number_of_extra_det_class_info,
             DOC_MRZEDCIC(get_number_of_extra_det_class_info))

        // ----- operators -----
        .def("__eq__",
             &MRZExtraDetClassInfoContainer::operator==,
             DOC_MRZEDCIC(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(MRZExtraDetClassInfoContainer)
        __PYCLASS_DEFAULT_PRINTING__(MRZExtraDetClassInfoContainer)
        ;
}

}
}
}
}
}
