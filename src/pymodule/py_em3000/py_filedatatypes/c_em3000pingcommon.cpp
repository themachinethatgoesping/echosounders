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
#include "../../../themachinethatgoesping/echosounders/em3000/filedatatypes/em3000pingcommon.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_EM3000PingCommon(ARG)                                                                  \
    DOC(themachinethatgoesping, echosounders, em3000, filedatatypes, EM3000PingCommon, ARG)

template<typename T_FileStream>
void py_create_class_em3000pingcommon(py::module& m, const std::string& CLASS_NAME)
{
    using t_EM3000PingCommon = filedatatypes::EM3000PingCommon<T_FileStream>;

    auto cls =
        py::class_<t_EM3000PingCommon,
                   datatypes::I_PingCommon,
                   std::shared_ptr<t_EM3000PingCommon>>(
            m,
            CLASS_NAME.c_str(),
            DOC(themachinethatgoesping, echosounders, em3000, filedatatypes, EM3000PingCommon))

            // --- raw_data data access ---
            .def_property_readonly("raw_data",
                                   py::overload_cast<>(&t_EM3000PingCommon::raw_data),
                                   DOC_EM3000PingCommon(raw_data),
                                   py::return_value_policy::reference_internal)

        // --- variable access ---
        //.def("is_dual_rx", &t_EM3000PingCommon::is_dual_rx, DOC_EM3000PingCommon(is_dual_rx))

        // ----- operators -----
        // .def("__eq__",
        //      &EM3000PingCommon::operator==,
        //      DOC(themachinethatgoesping, echosounders, em3000, filedatatypes,
        //      EM3000PingCommon, operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_EM3000PingCommon)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(EM3000PingCommon)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(EM3000PingCommon)
        // end EM3000PingCommon
        ;
}

void init_c_em3000pingcommon(pybind11::module& m)
{
    py_create_class_em3000pingcommon<std::ifstream>(m, "EM3000PingCommon");
    py_create_class_em3000pingcommon<datastreams::MappedFileStream>(m, "EM3000PingCommon_mapped");
}

}
}
}
}
}