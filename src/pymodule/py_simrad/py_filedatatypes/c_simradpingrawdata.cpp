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
#include "../../../themachinethatgoesping/echosounders/simrad/filedatatypes/simradping.hpp"
#include "../../../themachinethatgoesping/echosounders/simrad/filesimradraw.hpp"
#include "../../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"

#include "../../py_filetemplates/py_datatypes/i_ping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_SimradPingRawData(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, simrad, filedatatypes, SimradPingRawData, ARG)

template<typename T_FileStream>
void py_create_class_simradpingrawdata(py::module& m, const std::string& CLASS_NAME)
{
    using t_SimradPingRawData = filedatatypes::SimradPingRawData<T_FileStream>;

    py::class_<t_SimradPingRawData>(
        m,
        (CLASS_NAME).c_str(),
        DOC(themachinethatgoesping, echosounders, simrad, filedatatypes, SimradPingRawData))

        // --- raw_data data access ---
        .def_readonly("ping_data",
                      &t_SimradPingRawData::_ping_data,
                      DOC_SimradPingRawData(ping_data),
                      py::return_value_policy::reference_internal)
        .def("get_parameter",
             &t_SimradPingRawData::get_parameter,
             DOC_SimradPingRawData(get_parameter))

        .def("get_sample_data",
             &t_SimradPingRawData::get_sample_data,
             DOC_SimradPingRawData(get_sample_data))

        .def("has_angle", &t_SimradPingRawData::has_angle, DOC_SimradPingRawData(has_angle))
        .def("has_power", &t_SimradPingRawData::has_power, DOC_SimradPingRawData(has_power))

        .def("load_data", &t_SimradPingRawData::load_data, DOC_SimradPingRawData(load_data))
        .def(
            "release_data", &t_SimradPingRawData::release_data, DOC_SimradPingRawData(release_data))

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
}

void init_c_simradpingrawdata(pybind11::module& m)
{

    py_create_class_simradpingrawdata<std::ifstream>(m, "SimradPingRawData");
    py_create_class_simradpingrawdata<datastreams::MappedFileStream>(m, "SimradPingRawData_mapped");
}

}
}
}
}
}