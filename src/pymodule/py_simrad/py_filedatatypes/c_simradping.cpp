// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
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
#include "../../../themachinethatgoesping/echosounders/simrad/filedatatypes/simradping.hpp"
#include "../../../themachinethatgoesping/echosounders/simrad/filesimradraw.hpp"
#include "../../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../../docstrings.hpp"

#include "../../py_filetemplates/py_datatypes/i_ping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using namespace themachinethatgoesping::echosounders::filetemplates;

template<typename T_FileStream>
void py_create_class_SimradPing(py::module& m, const std::string& CLASS_NAME)
{
    using t_SimradPingRawData = filedatatypes::SimradPingRawData<T_FileStream>;
    using t_SimradPing        = filedatatypes::SimradPing<T_FileStream>;

    py::class_<t_SimradPingRawData>(
        m,
        (CLASS_NAME + "_RawData").c_str(),
        DOC(themachinethatgoesping, echosounders, simrad, filedatatypes, SimradPingRawData))

        // --- raw_data data access ---
        .def_readonly("ping_data",
                      &t_SimradPingRawData::_ping_data,
                      DOC(themachinethatgoesping,
                          echosounders,
                          simrad,
                          filedatatypes,
                          SimradPingRawData,
                          ping_data),
                      py::return_value_policy::reference_internal)
        .def("get_parameter",
             &t_SimradPingRawData::get_parameter,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 filedatatypes,
                 SimradPingRawData,
                 get_parameter))

        .def("get_sample_data",
             &t_SimradPingRawData::get_sample_data,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 filedatatypes,
                 SimradPingRawData,
                 get_sample_data))

        .def("has_angle",
             &t_SimradPingRawData::has_angle,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 filedatatypes,
                 SimradPingRawData,
                 has_angle))
        .def("has_power",
             &t_SimradPingRawData::has_power,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 filedatatypes,
                 SimradPingRawData,
                 has_power))

        .def("load_data",
             &t_SimradPingRawData::load_data,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 filedatatypes,
                 SimradPingRawData,
                 load_data))
        .def("release_data",
             &t_SimradPingRawData::release_data,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 filedatatypes,
                 SimradPingRawData,
                 release_data))

        // ----- operators -----
        // .def("__eq__",
        //      &SimradPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, simrad, filedatatypes,  SimradPing,
        //      operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_SimradPingRawData)
        // default binary functions
        __PYCLASS_DEFAULT_PRINTING__(t_SimradPingRawData)
        // end SimradPing
        ;

    auto cls = py::class_<t_SimradPing>(
                   m,
                   CLASS_NAME.c_str(),
                   DOC(themachinethatgoesping, echosounders, simrad, filedatatypes, SimradPing))

                   // --- ping interface (with individual documentation) ---
                   .def("get_angle",
                        &t_SimradPing::get_angle,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simrad,
                            filedatatypes,
                            SimradPing,
                            get_angle))
                   .def("get_sv",
                        &t_SimradPing::get_sv,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simrad,
                            filedatatypes,
                            SimradPing,
                            get_sv),
                        py::arg("dB") = false)
                   .def("get_sv_stacked",
                        &t_SimradPing::get_sv_stacked,
                        DOC(themachinethatgoesping,
                            echosounders,
                            simrad,
                            filedatatypes,
                            SimradPing,
                            get_sv_stacked),
                        py::arg("dB") = false)

                   // --- raw_data data access ---
                   .def_property_readonly("raw_data",
                                          &t_SimradPing::raw_data,
                                          DOC(themachinethatgoesping,
                                              echosounders,
                                              simrad,
                                              filedatatypes,
                                              SimradPing,
                                              raw_data),
                                          py::return_value_policy::reference_internal)

        // --- variable access ---

        // ----- operators -----
        // .def("__eq__",
        //      &SimradPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, simrad, filedatatypes,  SimradPing,
        //      operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        // __PYCLASS_DEFAULT_COPY__(SimradPing)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(SimradPing)
        // default printing functions
        //__PYCLASS_DEFAULT_PRINTING__(SimradPing)
        // end SimradPing
        ;

    py_filetemplates::py_datatypes::py_i_ping::add_ping_data_interface<t_SimradPing>(cls);
}

void init_c_SimradPing(pybind11::module& m)
{

    py_create_class_SimradPing<std::ifstream>(m, "SimradPing");
    py_create_class_SimradPing<datastreams::MappedFileStream>(m, "SimradPing_mapped");
}

}
}
}
}
}