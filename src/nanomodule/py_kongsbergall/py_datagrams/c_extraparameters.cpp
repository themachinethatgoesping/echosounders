// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/extraparameters.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::ExtraParameters;

#define DOC_ExtraParameters(ARG)                                                                   \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, ExtraParameters, ARG)
#define DOC_ContentIdentifier(ARG)                                                                 \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        datagrams,                                                                                 \
        ExtraParameters,                                                                           \
        t_ContentIdentifier,                                                                       \
        ARG)

void init_c_extraparameters(nanobind::module_& m)
{
    // first add enum
    nb::enum_<ExtraParameters::t_ContentIdentifier>(
        m, "ExtraParameters_t_ContentIdentifier", DOC_ExtraParameters(t_ContentIdentifier))
        // Multibeam data
        .value("CalibTxt",
               ExtraParameters::t_ContentIdentifier::CalibTxt,
               DOC_ContentIdentifier(CalibTxt))
        .value("LogAllHeights",
               ExtraParameters::t_ContentIdentifier::LogAllHeights,
               DOC_ContentIdentifier(LogAllHeights))
        .value("SoundVelocityAtTransducer",
               ExtraParameters::t_ContentIdentifier::SoundVelocityAtTransducer,
               DOC_ContentIdentifier(SoundVelocityAtTransducer))
        .value("SoundVelocityProfile",
               ExtraParameters::t_ContentIdentifier::SoundVelocityProfile,
               DOC_ContentIdentifier(SoundVelocityProfile))
        .value("MultiCastInputStatus",
               ExtraParameters::t_ContentIdentifier::MultiCastInputStatus,
               DOC_ContentIdentifier(MultiCastInputStatus))
        .value(
            "Bscorr", ExtraParameters::t_ContentIdentifier::Bscorr, DOC_ContentIdentifier(Bscorr))
        //
        ;

    themachinethatgoesping::tools::nanobind_helper::make_option_class<
        ExtraParameters::o_ContentIdentifier>(m, "o_ExtraParameters_t_ContentIdentifier");

    // then add class
    nb::class_<ExtraParameters, datagrams::KongsbergAllDatagram>(
        m,
        "ExtraParameters",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, ExtraParameters))
        .def(nb::init<>(), DOC_ExtraParameters(ExtraParameters))
        // --- convenient data access ---
        .def("set_ping_counter",
             &ExtraParameters::set_ping_counter,
             DOC_ExtraParameters(ping_counter))
        .def("get_ping_counter",
             &ExtraParameters::get_ping_counter,
             DOC_ExtraParameters(ping_counter))
        .def("set_system_serial_number",
             &ExtraParameters::set_system_serial_number,
             DOC_ExtraParameters(system_serial_number))
        .def("get_system_serial_number",
             &ExtraParameters::get_system_serial_number,
             DOC_ExtraParameters(system_serial_number))
        .def("set_content_identifier",
             &ExtraParameters::set_content_identifier,
             DOC_ExtraParameters(content_identifier))
        .def("get_content_identifier",
             &ExtraParameters::get_content_identifier,
             DOC_ExtraParameters(content_identifier))
        .def("set_raw_content", &ExtraParameters::set_raw_content, DOC_ExtraParameters(raw_content))
        .def("get_raw_content", &ExtraParameters::get_raw_content, DOC_ExtraParameters(raw_content))

        // --- data structure access ---

        // --- processed member access ---

        // --- checksum access ---
        .def("get_spare", &ExtraParameters::get_spare, DOC_ExtraParameters(spare))
        .def("set_spare", &ExtraParameters::set_spare, DOC_ExtraParameters(spare))
        .def("get_etx", &ExtraParameters::get_etx, DOC_ExtraParameters(etx))
        .def("set_etx", &ExtraParameters::set_etx, DOC_ExtraParameters(etx))
        .def("get_checksum", &ExtraParameters::get_checksum, DOC_ExtraParameters(checksum))
        .def("set_checksum", &ExtraParameters::set_checksum, DOC_ExtraParameters(checksum))

        // ----- operators -----
        .def("__eq__",
             &ExtraParameters::operator==,
             DOC_ExtraParameters(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(ExtraParameters)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(ExtraParameters)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(ExtraParameters)
        // end LinearInterpolator
        ;
}
}
}
}
}
}