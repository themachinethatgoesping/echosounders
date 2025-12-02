// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mwctxinfo.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MWCTxInfo;

#define DOC_MWCTxInfo(ARG)                                                                           \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, substructs, MWCTxInfo, ARG)

void init_c_mwctxinfo(nanobind::module_& m)
{
    nb::class_<MWCTxInfo>(m, "MWCTxInfo", DOC_MWCTxInfo(MWCTxInfo))
        .def(nb::init<>(), DOC_MWCTxInfo(MWCTxInfo))
        .def("get_num_bytes_tx_info",
             &MWCTxInfo::get_num_bytes_tx_info,
             DOC_MWCTxInfo(get_num_bytes_tx_info))
        .def("set_num_bytes_tx_info",
             &MWCTxInfo::set_num_bytes_tx_info,
             DOC_MWCTxInfo(set_num_bytes_tx_info),
             nb::arg("val"))
        .def("get_num_tx_sectors",
             &MWCTxInfo::get_num_tx_sectors,
             DOC_MWCTxInfo(get_num_tx_sectors))
        .def("set_num_tx_sectors",
             &MWCTxInfo::set_num_tx_sectors,
             DOC_MWCTxInfo(set_num_tx_sectors),
             nb::arg("val"))
        .def("get_num_bytes_per_tx_sector",
             &MWCTxInfo::get_num_bytes_per_tx_sector,
             DOC_MWCTxInfo(get_num_bytes_per_tx_sector))
        .def("set_num_bytes_per_tx_sector",
             &MWCTxInfo::set_num_bytes_per_tx_sector,
             DOC_MWCTxInfo(set_num_bytes_per_tx_sector),
             nb::arg("val"))
        .def("get_padding",
             &MWCTxInfo::get_padding,
             DOC_MWCTxInfo(get_padding))
        .def("set_padding",
             &MWCTxInfo::set_padding,
             DOC_MWCTxInfo(set_padding),
             nb::arg("val"))
        .def("get_heave_m",
             &MWCTxInfo::get_heave_m,
             DOC_MWCTxInfo(get_heave_m))
        .def("set_heave_m",
             &MWCTxInfo::set_heave_m,
             DOC_MWCTxInfo(set_heave_m),
             nb::arg("val"))
        .def("__eq__",
             &MWCTxInfo::operator==,
             DOC_MWCTxInfo(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(MWCTxInfo)
        __PYCLASS_DEFAULT_PRINTING__(MWCTxInfo);
}

}
}
}
}
}
