// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
//#define FORCE_IMPORT_ARRAY
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/fileraw.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simradping.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_ping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using namespace themachinethatgoesping::echosounders::fileinterfaces;

template<typename T_FileStream>
void py_create_class_SimradPing(py::module& m, const std::string& CLASS_NAME)
{
    using t_SimradPingRawData = SimradPingRawData<T_FileStream>;
    using t_SimradPing        = SimradPing<T_FileStream>;

    py::class_<t_SimradPingRawData>(
        m,
        (CLASS_NAME + "_RawData").c_str(),
        DOC(themachinethatgoesping, echosounders, simrad, SimradPingRawData))

        // --- raw data access ---
        .def_readonly(
            "ping_data",
            &t_SimradPingRawData::_ping_data,
            DOC(themachinethatgoesping, echosounders, simrad, SimradPingRawData, ping_data),
            py::return_value_policy::reference_internal)
        .def("get_parameter",
             &t_SimradPingRawData::get_parameter,
             DOC(themachinethatgoesping, echosounders, simrad, SimradPingRawData, get_parameter))
        .def_property_readonly(
            "file_data",
            &t_SimradPingRawData::file_data,
            DOC(themachinethatgoesping, echosounders, simrad, SimradPingRawData, file_data),
            py::return_value_policy::reference_internal)

        .def("get_sample_data",
             &t_SimradPingRawData::get_sample_data,
             DOC(themachinethatgoesping, echosounders, simrad, SimradPingRawData, get_sample_data))

        .def("load_data",
             &t_SimradPingRawData::load_data,
             DOC(themachinethatgoesping, echosounders, simrad, SimradPingRawData, load_data))
        .def("release_data",
             &t_SimradPingRawData::release_data,
             DOC(themachinethatgoesping, echosounders, simrad, SimradPingRawData, release_data))

        // ----- operators -----
        // .def("__eq__",
        //      &SimradPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, simrad, SimradPing, operator_eq),
        //      py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        // __PYCLASS_DEFAULT_COPY__(SimradPing)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(SimradPing)
        // default printing functions
        //__PYCLASS_DEFAULT_PRINTING__(SimradPing)
        // end SimradPing
        ;

    auto cls =
        py::class_<t_SimradPing>(
            m, CLASS_NAME.c_str(), DOC(themachinethatgoesping, echosounders, simrad, SimradPing))

            // --- ping interface (with individual documentation) ---
            .def("get_angle",
                 &t_SimradPing::get_angle,
                 DOC(themachinethatgoesping, echosounders, simrad, SimradPing, get_angle))
            .def("get_sv",
                 &t_SimradPing::get_sv,
                 DOC(themachinethatgoesping, echosounders, simrad, SimradPing, get_sv),
                 py::arg("dB") = false)
            .def("get_sv_stacked",
                 &t_SimradPing::get_sv_stacked,
                 DOC(themachinethatgoesping, echosounders, simrad, SimradPing, get_sv_stacked),
                 py::arg("dB") = false)

            // --- raw data access ---
            .def("raw",
                 &t_SimradPing::raw,
                 DOC(themachinethatgoesping, echosounders, simrad, SimradPing, raw),
                 py::return_value_policy::reference_internal)
            .def("file_data",
                 &t_SimradPing::file_data,
                 DOC(themachinethatgoesping, echosounders, simrad, SimradPing, file_data),
                 py::return_value_policy::reference_internal)

            // --- variable access ---

            // --- variable access ---
            .def("get_channel_id",
                 &t_SimradPing::get_channel_id,
                 DOC(themachinethatgoesping, echosounders, simrad, SimradPing, get_channel_id),
                 py::return_value_policy::reference_internal)
            .def("get_timestamp",
                 &t_SimradPing::get_timestamp,
                 DOC(themachinethatgoesping, echosounders, simrad, SimradPing, get_timestamp),
                 py::return_value_policy::reference_internal)
        //   .def(
        //      "get_file_path",
        //      &t_SimradPing::get_file_path,
        //      DOC(themachinethatgoesping, echosounders, simrad, SimradPing, get_file_path),
        //        py::return_value_policy::reference_internal)
        //   .def(
        //      "get_ping_number",
        //      &t_SimradPing::get_ping_number,
        //      DOC(themachinethatgoesping, echosounders, simrad, SimradPing, get_ping_number),
        //        py::return_value_policy::reference_internal)

        // ----- operators -----
        // .def("__eq__",
        //      &SimradPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, simrad, SimradPing, operator_eq),
        //      py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        // __PYCLASS_DEFAULT_COPY__(SimradPing)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(SimradPing)
        // default printing functions
        //__PYCLASS_DEFAULT_PRINTING__(SimradPing)
        // end SimradPing
        ;

    py_fileinterfaces::py_i_Ping::add_ping_data_interface<t_SimradPing>(cls);
}

void init_c_SimradPing(pybind11::module& m)
{

    py_create_class_SimradPing<std::ifstream>(m, "SimradPing");
    py_create_class_SimradPing<MappedFileStream>(m, "SimradPing_mapped");
}

}
}
}
}