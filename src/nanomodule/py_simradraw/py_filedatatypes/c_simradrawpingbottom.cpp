// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/complex.h>
#include <nanobind/stl/string.h>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/filedatatypes/simradrawpingbottom.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_SimradRawPing(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingBottom, ARG)

template<typename T_FileStream>
void py_create_class_simradrawpingbottom(nb::module_& m, const std::string& CLASS_NAME)
{
    using t_SimradRawPingBottom = filedatatypes::SimradRawPingBottom<T_FileStream>;

    auto cls = nb::class_<t_SimradRawPingBottom, datatypes::I_PingBottom>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingBottom))

        // --- pingbottom interface extension ---

        // --- variable access ---
        //.def("is_dual_rx", &t_SimradRawPingBottom::is_dual_rx, DOC_SimradRawPing(is_dual_rx))

        // ----- operators -----
        // .def("__eq__",
        //      &SimradRawPingBottom::operator==,
        //      DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes,
        //      SimradRawPingBottom, operator_eq), nb::arg("other"))
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

void init_c_simradrawpingbottom(nanobind::module_& m)
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