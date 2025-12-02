// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/bind_vector.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mwcsectorinfo.hpp>

#include "../module.hpp"

NB_MAKE_OPAQUE(
    std::vector<themachinethatgoesping::echosounders::kmall::datagrams::substructs::MWCSectorInfo>);
namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MWCSectorInfo;

#define DOC_MWCSectorInfo(ARG)                                                                         \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, substructs, MWCSectorInfo, ARG)

void init_c_mwcsectorinfo(nanobind::module_& m)
{
    nb::class_<MWCSectorInfo>(m, "MWCSectorInfo", DOC_MWCSectorInfo(MWCSectorInfo))
        .def(nb::init<>(), DOC_MWCSectorInfo(MWCSectorInfo))
        .def("get_tilt_angle_re_tx_deg",
             &MWCSectorInfo::get_tilt_angle_re_tx_deg,
             DOC_MWCSectorInfo(get_tilt_angle_re_tx_deg))
        .def("set_tilt_angle_re_tx_deg",
             &MWCSectorInfo::set_tilt_angle_re_tx_deg,
             DOC_MWCSectorInfo(set_tilt_angle_re_tx_deg),
             nb::arg("val"))
        .def("get_centre_frequency_hz",
             &MWCSectorInfo::get_centre_frequency_hz,
             DOC_MWCSectorInfo(get_centre_frequency_hz))
        .def("set_centre_frequency_hz",
             &MWCSectorInfo::set_centre_frequency_hz,
             DOC_MWCSectorInfo(set_centre_frequency_hz),
             nb::arg("val"))
        .def("get_tx_beam_width_along_deg",
             &MWCSectorInfo::get_tx_beam_width_along_deg,
             DOC_MWCSectorInfo(get_tx_beam_width_along_deg))
        .def("set_tx_beam_width_along_deg",
             &MWCSectorInfo::set_tx_beam_width_along_deg,
             DOC_MWCSectorInfo(set_tx_beam_width_along_deg),
             nb::arg("val"))
        .def("get_tx_sector_number",
             &MWCSectorInfo::get_tx_sector_number,
             DOC_MWCSectorInfo(get_tx_sector_number))
        .def("set_tx_sector_number",
             &MWCSectorInfo::set_tx_sector_number,
             DOC_MWCSectorInfo(set_tx_sector_number),
             nb::arg("val"))
        .def("get_padding", &MWCSectorInfo::get_padding, DOC_MWCSectorInfo(get_padding))
        .def("set_padding",
             &MWCSectorInfo::set_padding,
             DOC_MWCSectorInfo(set_padding),
             nb::arg("val"))
        .def("__eq__",
             &MWCSectorInfo::operator==,
             DOC_MWCSectorInfo(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(MWCSectorInfo)
        __PYCLASS_DEFAULT_PRINTING__(MWCSectorInfo);

    nb::bind_vector<std::vector<MWCSectorInfo>>(m, "MWCSectorInfoVector");
}

}
}
}
}
}
