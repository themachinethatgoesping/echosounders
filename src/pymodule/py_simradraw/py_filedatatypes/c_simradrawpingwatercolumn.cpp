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

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/types.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/filedatatypes/simradrawpingwatercolumn.hpp"
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
    DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingWatercolumn, ARG)

template<typename T_FileStream>
void py_create_class_simradrawpingwatercolumn(py::module& m, const std::string& CLASS_NAME)
{
    using t_SimradRawPingWatercolumn = filedatatypes::SimradRawPingWatercolumn<T_FileStream>;

    auto cls = py::class_<t_SimradRawPingWatercolumn,
                          datatypes::I_PingWatercolumn,
                          filedatatypes::SimradRawPingCommon<T_FileStream>,
                          std::shared_ptr<t_SimradRawPingWatercolumn>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingWatercolumn))

        // --- pingwatercolumn interface extension ---

        // --- variable access ---

        // ----- operators -----
        // .def("__eq__",
        //      &SimradRawPingWatercolumn::operator==,
        //      DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes,
        //      SimradRawPingWatercolumn, operator_eq), py::arg("other"))
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

void init_c_simradrawpingwatercolumn(pybind11::module& m)
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