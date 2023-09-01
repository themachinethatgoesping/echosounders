// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0



#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingwatercolumn.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_I_PingWatercolumn(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingWatercolumn, ARG)

void init_c_i_pingwatercolumn(pybind11::module& m)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls =
        py::class_<I_PingWatercolumn, I_PingCommon, std::shared_ptr<I_PingWatercolumn>>(
            m,
            "I_PingWatercolumn",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingWatercolumn))

            // ----- features -----
            .def("has_amplitudes",
                 py::overload_cast<>(&I_PingWatercolumn::has_amplitudes, py::const_),
                 DOC_I_PingWatercolumn(has_amplitudes))
            .def("get_amplitudes",
                 py::overload_cast<>(&I_PingWatercolumn::get_amplitudes),
                 DOC_I_PingWatercolumn(get_amplitudes))
            .def("get_amplitudes",
                 py::overload_cast<const pingtools::BeamSampleSelection&>(
                     &I_PingWatercolumn::get_amplitudes),
                 DOC_I_PingWatercolumn(get_amplitudes),
                 py::arg("beam_selection"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(I_PingWatercolumn)
        // default printing functions
        // cls __PYCLASS_DEFAULT_PRINTING__(I_PingWatercolumn);
        ;
}

}
}
}
}
}