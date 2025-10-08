// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/complex.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/filedatatypes/simradrawpingwatercolumn.hpp"
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
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                 \
        filedatatypes,                                                                             \
        SimradRawPingWatercolumn,                                                                  \
        ARG)

#define DOC_I_PingWatercolumn(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingWatercolumn, ARG)

#define DOC_SimradRawPingCommon(ARG)                                                               \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                 \
        filedatatypes,                                                                             \
        SimradRawPingCommon,                                                                       \
        ARG)

template<typename T_FileStream>
void py_create_class_simradrawpingwatercolumn(nb::module_& m, const std::string& CLASS_NAME)
{
    using t_SimradRawPingWatercolumn = filedatatypes::SimradRawPingWatercolumn<T_FileStream>;

    auto cls = nb::class_<t_SimradRawPingWatercolumn, datatypes::I_PingWatercolumn>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingWatercolumn))

            // --- interface overwrites (necessary when type is changes) ---
            .def("get_watercolumn_calibration",
                 nb::overload_cast<>(&t_SimradRawPingWatercolumn::get_watercolumn_calibration,
                                     nb::const_),
                 DOC_I_PingWatercolumn(get_watercolumn_calibration))
                 
        // --- pingwatercolumn interface extension ---
        // --- variable access ---

        // ----- operators -----
        // .def("__eq__",
        //      &SimradRawPingWatercolumn::operator==,
        //      DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes,
        //      SimradRawPingWatercolumn, operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_SimradRawPingWatercolumn)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(SimradRawPingWatercolumn)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(SimradRawPingWatercolumn)
        // end SimradRawPingWatercolumn
        ;

}

void init_c_simradrawpingwatercolumn(nanobind::module_& m)
{
    static const std::string name        = "SimradRawPingWatercolumn";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_simradrawpingwatercolumn<std::ifstream>(m, name_stream);
    py_create_class_simradrawpingwatercolumn<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}