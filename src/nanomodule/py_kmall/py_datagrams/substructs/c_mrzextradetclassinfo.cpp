// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/bind_vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzextradetclassinfo.hpp>

#include "../module.hpp"

NB_MAKE_OPAQUE(std::vector<themachinethatgoesping::echosounders::kmall::datagrams::substructs::MRZExtraDetClassInfo>);

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MRZExtraDetClassInfo;

#define DOC_MRZExtraDetClassInfo(ARG)                                                              \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, substructs, MRZExtraDetClassInfo, ARG)

void init_c_mrzextradetclassinfo(nanobind::module_& m)
{
    nb::class_<MRZExtraDetClassInfo>(m, "MRZExtraDetClassInfo", DOC_MRZExtraDetClassInfo(MRZExtraDetClassInfo))
        .def(nb::init<>(), DOC_MRZExtraDetClassInfo(MRZExtraDetClassInfo))
        .def("get_num_extra_det_in_class",
             &MRZExtraDetClassInfo::get_num_extra_det_in_class,
             DOC_MRZExtraDetClassInfo(get_num_extra_det_in_class))
        .def("set_num_extra_det_in_class",
             &MRZExtraDetClassInfo::set_num_extra_det_in_class,
             DOC_MRZExtraDetClassInfo(set_num_extra_det_in_class),
             nb::arg("val"))
        .def("get_padding",
             &MRZExtraDetClassInfo::get_padding,
             DOC_MRZExtraDetClassInfo(get_padding))
        .def("set_padding",
             &MRZExtraDetClassInfo::set_padding,
             DOC_MRZExtraDetClassInfo(set_padding),
             nb::arg("val"))
        .def("get_alarm_flag",
             &MRZExtraDetClassInfo::get_alarm_flag,
             DOC_MRZExtraDetClassInfo(get_alarm_flag))
        .def("set_alarm_flag",
             &MRZExtraDetClassInfo::set_alarm_flag,
             DOC_MRZExtraDetClassInfo(set_alarm_flag),
             nb::arg("val"))

        // ----- operators -----
        .def("__eq__",
             &MRZExtraDetClassInfo::operator==,
             DOC_MRZExtraDetClassInfo(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        __PYCLASS_DEFAULT_COPY__(MRZExtraDetClassInfo)
        __PYCLASS_DEFAULT_PRINTING__(MRZExtraDetClassInfo)
        ;


    nb::bind_vector<std::vector<MRZExtraDetClassInfo>>(m, "MRZExtraDetClassInfoVector");
}

}
}
}
}
}
