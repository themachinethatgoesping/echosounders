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

#include "../../../themachinethatgoesping/echosounders/em3000/em3000_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/em3000/em3000_types.hpp"
#include "../../../themachinethatgoesping/echosounders/em3000/filedatatypes/em3000ping.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

#include "../../py_filetemplates/py_datatypes/i_ping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_EM3000Ping(ARG)                                                                        \
    DOC(themachinethatgoesping, echosounders, em3000, filedatatypes, EM3000Ping, ARG)

template<typename T_FileStream>
void py_create_class_em3000ping(py::module& m, const std::string& CLASS_NAME)
{
    using t_EM3000Ping = filedatatypes::EM3000Ping<T_FileStream>;

    auto cls = py::class_<t_EM3000Ping, datatypes::I_Ping, std::shared_ptr<t_EM3000Ping>>(
                   m,
                   CLASS_NAME.c_str(),
                   DOC(themachinethatgoesping, echosounders, em3000, filedatatypes, EM3000Ping))

                   // --- ping interface (with individual documentation) ---
                   // .def("get_angle", &t_EM3000Ping::get_angle, DOC_EM3000Ping(get_angle))
                   // .def("get_sv", &t_EM3000Ping::get_sv, DOC_EM3000Ping(get_sv), py::arg("dB") =
                   // false) .def("get_sv_stacked",
                   //      &t_EM3000Ping::get_sv_stacked,
                   //      DOC_EM3000Ping(get_sv_stacked),
                   //      py::arg("dB") = false)

                   .def("get_transducer_ids",
                        &t_EM3000Ping::get_transducer_ids,
                        DOC_EM3000Ping(get_transducer_ids))

                   .def("load_datagrams",
                        &t_EM3000Ping::load_datagrams,
                        DOC_EM3000Ping(load_datagrams),
                        py::arg("skip_data") = true)

                   // --- ping interface extension ---

                   // --- raw_data data access ---
                   .def("raw_data",
                        py::overload_cast<const std::string&>(&t_EM3000Ping::raw_data),
                        DOC_EM3000Ping(raw_data),
                        py::return_value_policy::reference_internal,
                        py::arg("transducer_id"))
                   .def("raw_data",
                        py::overload_cast<>(&t_EM3000Ping::raw_data),
                        DOC_EM3000Ping(raw_data),
                        py::return_value_policy::reference_internal)

        // --- variable access ---
        //.def("is_dual_rx", &t_EM3000Ping::is_dual_rx, DOC_EM3000Ping(is_dual_rx))

        // ----- operators -----
        // .def("__eq__",
        //      &EM3000Ping::operator==,
        //      DOC(themachinethatgoesping, echosounders, em3000, filedatatypes,  EM3000Ping,
        //      operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        // __PYCLASS_DEFAULT_COPY__(EM3000Ping)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(EM3000Ping)
        // default printing functions
        //__PYCLASS_DEFAULT_PRINTING__(EM3000Ping)
        // end EM3000Ping
        ;

    py_filetemplates::py_datatypes::py_i_ping::add_ping_data_interface<t_EM3000Ping>(cls);
}

void init_c_em3000ping(pybind11::module& m)
{
    py_create_class_em3000ping<std::ifstream>(m, "EM3000Ping");
    py_create_class_em3000ping<datastreams::MappedFileStream>(m, "EM3000Ping_mapped");
}

}
}
}
}
}