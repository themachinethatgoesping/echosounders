// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingfiledata.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_I_PingFileData(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingFileData, ARG)

void init_c_i_PingFileData(pybind11::module& m)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls =
        py::class_<I_PingFileData, std::shared_ptr<I_PingFileData>>(
            m,
            "I_PingFileData",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingFileData))

            // --- ping info access ---
            .def("get_file_numbers",
                 &I_PingFileData::get_file_numbers,
                 DOC_I_PingFileData(get_file_numbers))
            .def("get_primary_file_path",
                 &I_PingFileData::get_primary_file_path,
                 DOC_I_PingFileData(get_primary_file_path))
            .def(
                "get_file_paths", &I_PingFileData::get_file_paths, DOC_I_PingFileData(get_file_paths))

            .def("get_primary_file_nr",
                 &I_PingFileData::get_primary_file_nr,
                 DOC_I_PingFileData(get_primary_file_nr))
            .def("set_primary_file_nr",
                 &I_PingFileData::set_primary_file_nr,
                 DOC_I_PingFileData(set_primary_file_nr),
                 py::arg("file_nr"))
            .def("get_file_ping_counter",
                 &I_PingFileData::get_file_ping_counter,
                 DOC_I_PingFileData(get_file_ping_counter))
            .def("set_file_ping_counter",
                 &I_PingFileData::set_file_ping_counter,
                 DOC_I_PingFileData(set_file_ping_counter),
                 py::arg("file_ping_counter"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(I_PingFileData)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(I_PingFileData);
}

}
}
}
}
}