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
#include "../../../themachinethatgoesping/echosounders/em3000/filedatatypes/em3000pingbottom.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_EM3000Ping(ARG)                                                                        \
    DOC(themachinethatgoesping, echosounders, em3000, filedatatypes, EM3000PingBottom, ARG)

template<typename T_FileStream>
void py_create_class_em3000pingbottom(py::module& m, const std::string& CLASS_NAME)
{
    using t_EM3000PingBottom = filedatatypes::EM3000PingBottom<T_FileStream>;

    auto cls =
        py::class_<t_EM3000PingBottom,
                   datatypes::I_PingBottom,
                   filedatatypes::EM3000PingCommon<T_FileStream>,
                   std::shared_ptr<t_EM3000PingBottom>>(
            m,
            CLASS_NAME.c_str(),
            DOC(themachinethatgoesping, echosounders, em3000, filedatatypes, EM3000PingBottom))

            // --- pingbottom interface extension ---

        // --- variable access ---
        //.def("is_dual_rx", &t_EM3000PingBottom::is_dual_rx, DOC_EM3000Ping(is_dual_rx))

        // ----- operators -----
        // .def("__eq__",
        //      &EM3000PingBottom::operator==,
        //      DOC(themachinethatgoesping, echosounders, em3000, filedatatypes,  EM3000PingBottom,
        //      operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_EM3000PingBottom)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(EM3000PingBottom)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(EM3000PingBottom)
        // end EM3000PingBottom
        ;
}

void init_c_em3000pingbottom(pybind11::module& m)
{
    py_create_class_em3000pingbottom<std::ifstream>(m, "EM3000PingBottom");
    py_create_class_em3000pingbottom<datastreams::MappedFileStream>(m, "EM3000PingBottom_mapped");
}

}
}
}
}
}