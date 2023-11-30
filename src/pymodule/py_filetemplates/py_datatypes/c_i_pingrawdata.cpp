// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingrawdata.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_I_PingRawData(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingRawData, ARG)

void init_c_i_pingrawdata(pybind11::module& m)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls =
        py::class_<I_PingRawData, std::shared_ptr<I_PingRawData>>(
            m,
            "I_PingRawData",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingRawData))

            // --- ping info access ---
            .def("get_file_numbers",
                 &I_PingRawData::get_file_numbers,
                 DOC_I_PingRawData(get_file_numbers))
            .def("get_primary_file_path",
                 &I_PingRawData::get_primary_file_path,
                 DOC_I_PingRawData(get_primary_file_path))
            .def(
                "get_file_paths", &I_PingRawData::get_file_paths, DOC_I_PingRawData(get_file_paths))

            .def("get_primary_file_nr",
                 &I_PingRawData::get_primary_file_nr,
                 DOC_I_PingRawData(get_primary_file_nr))
            .def("set_primary_file_nr",
                 &I_PingRawData::set_primary_file_nr,
                 DOC_I_PingRawData(set_primary_file_nr),
                 py::arg("file_nr"))
            .def("get_file_ping_counter",
                 &I_PingRawData::get_file_ping_counter,
                 DOC_I_PingRawData(get_file_ping_counter))
            .def("set_file_ping_counter",
                 &I_PingRawData::set_file_ping_counter,
                 DOC_I_PingRawData(set_file_ping_counter),
                 py::arg("file_ping_counter"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(I_PingRawData)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(I_PingRawData);
}

}
}
}
}
}