// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/types.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/filedatatypes/simradrawpingbottom.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_SimradRawPing(ARG)                                                                        \
    DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingBottom, ARG)

template<typename T_FileStream>
void py_create_class_simradrawpingbottom(py::module& m, const std::string& CLASS_NAME)
{
    using t_SimradRawPingBottom = filedatatypes::SimradRawPingBottom<T_FileStream>;

    auto cls = py::classh<t_SimradRawPingBottom,
                          datatypes::I_PingBottom,
                          filedatatypes::SimradRawPingCommon<T_FileStream>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingBottom))

        // --- pingbottom interface extension ---

        // --- variable access ---
        //.def("is_dual_rx", &t_SimradRawPingBottom::is_dual_rx, DOC_SimradRawPing(is_dual_rx))

        // ----- operators -----
        // .def("__eq__",
        //      &SimradRawPingBottom::operator==,
        //      DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes,  SimradRawPingBottom,
        //      operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_SimradRawPingBottom)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(SimradRawPingBottom)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(SimradRawPingBottom)
        // end SimradRawPingBottom
        ;
}

void init_c_simradrawpingbottom(pybind11::module& m)
{
    static const std::string name        = "SimradRawPingBottom";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_simradrawpingbottom<std::ifstream>(m, name_stream);
    py_create_class_simradrawpingbottom<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}