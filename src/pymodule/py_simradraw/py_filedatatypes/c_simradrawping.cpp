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

#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/filedatatypes/simradrawping.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_SimradRawPing(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPing, ARG)

template<typename T_FileStream>
void py_create_class_simradrawping(py::module& m, const std::string& CLASS_NAME)
{
    using t_SimradRawPing = filedatatypes::SimradRawPing<T_FileStream>;

    auto cls = py::class_<t_SimradRawPing,
                          datatypes::I_Ping,
                          filedatatypes::SimradRawPingCommon<T_FileStream>,
                          std::shared_ptr<t_SimradRawPing>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPing))

        // --- ping interface extension ---

        // --- file_data data access ---
        // .def("file_data",
        //      &t_SimradRawPing::file_data,
        //      DOC_SimradRawPing(file_data),
        //      py::return_value_policy::reference_internal)

        // --- variable access ---

        // ----- operators -----
        // .def("__eq__",
        //      &SimradRawPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes,  SimradRawPing,
        //      operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_SimradRawPing)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(SimradRawPing)
        // default printing functions
        //__PYCLASS_DEFAULT_PRINTING__(SimradRawPing)
        // end SimradRawPing
        ;
}

void init_c_simradrawping(pybind11::module& m)
{
    static const std::string name        = "SimradRawPing";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_simradrawping<std::ifstream>(m, name_stream);
    py_create_class_simradrawping<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}