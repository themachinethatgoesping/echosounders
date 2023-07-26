// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "i_ping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

namespace py = pybind11;

void init_trampoline_i_ping(py::module& m)
{
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls = py::class_<I_Ping>(
        m, "I_Ping", DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping));

    //     auto cls = py::class_<t_EM3000Ping>(
    //                    m,
    //                    CLASS_NAME.c_str(),
    //                    DOC(themachinethatgoesping, echosounders, em3000, filedatatypes,
    //                    EM3000Ping))

    //                    // --- ping interface (with individual documentation) ---
    //                    // .def("get_angle", &t_EM3000Ping::get_angle, DOC_EM3000Ping(get_angle))
    //                    // .def("get_sv", &t_EM3000Ping::get_sv, DOC_EM3000Ping(get_sv),
    //                    py::arg("dB") =
    //                    // false) .def("get_sv_stacked",
    //                    //      &t_EM3000Ping::get_sv_stacked,
    //                    //      DOC_EM3000Ping(get_sv_stacked),
    //                    //      py::arg("dB") = false)

    //                    .def("get_transducer_ids",
    //                         &t_EM3000Ping::get_transducer_ids,
    //                         DOC_EM3000Ping(get_transducer_ids))

    //                    .def("load_datagrams",
    //                         &t_EM3000Ping::load_datagrams,
    //                         DOC_EM3000Ping(load_datagrams),
    //                         py::arg("skip_data") = true)

    //                    // --- ping interface extension ---

    //                    // --- raw_data data access ---
    //                    .def("raw_data",
    //                         py::overload_cast<const std::string&>(&t_EM3000Ping::raw_data),
    //                         DOC_EM3000Ping(raw_data),
    //                         py::return_value_policy::reference_internal,
    //                         py::arg("transducer_id"))
    //                    .def("raw_data",
    //                         py::overload_cast<>(&t_EM3000Ping::raw_data),
    //                         DOC_EM3000Ping(raw_data),
    //                         py::return_value_policy::reference_internal)

    //         // --- variable access ---
    //         //.def("is_dual_rx", &t_EM3000Ping::is_dual_rx, DOC_EM3000Ping(is_dual_rx))

    //         // ----- operators -----
    //         // .def("__eq__",
    //         //      &EM3000Ping::operator==,
    //         //      DOC(themachinethatgoesping, echosounders, em3000, filedatatypes,  EM3000Ping,
    //         //      operator_eq), py::arg("other"))
    //         // ----- pybind macros -----
    //         // default copy functions
    //         // __PYCLASS_DEFAULT_COPY__(EM3000Ping)
    //         // default binary functions
    //         // __PYCLASS_DEFAULT_BINARY__(EM3000Ping)
    //         // default printing functions
    //         //__PYCLASS_DEFAULT_PRINTING__(EM3000Ping)
    //         // end EM3000Ping
    //         ;

    //     py_filetemplates::py_datatypes::py_i_ping::add_ping_data_interface<t_EM3000Ping>(cls);
}

}
}
}
}
}