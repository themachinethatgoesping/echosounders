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
#include "../../../themachinethatgoesping/echosounders/em3000/filedatatypes/em3000ping.hpp"
#include "../../../themachinethatgoesping/echosounders/em3000/fileem3000.hpp"
#include "../../../themachinethatgoesping/echosounders/em3000/em3000_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/em3000/em3000_types.hpp"

#include "../../py_filetemplates/py_datatypes/i_ping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_EM3000PingRawData(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, em3000, filedatatypes, EM3000PingRawData, ARG)

template<typename T_FileStream>
void py_create_class_em3000pingrawdata(py::module& m, const std::string& CLASS_NAME)
{
    using t_EM3000PingRawData = filedatatypes::EM3000PingRawData<T_FileStream>;

    py::class_<t_EM3000PingRawData>(
        m,
        (CLASS_NAME).c_str(),
        DOC(themachinethatgoesping, echosounders, em3000, filedatatypes, EM3000PingRawData))

        // --- raw_data data access ---
        // .def_readonly("ping_data",
        //               &t_EM3000PingRawData::_ping_data,
        //               DOC_EM3000PingRawData(ping_data),
        //               py::return_value_policy::reference_internal)
        // .def("get_parameter",
        //      &t_EM3000PingRawData::get_parameter,
        //      DOC_EM3000PingRawData(get_parameter))

        // .def("get_sample_data",
        //      &t_EM3000PingRawData::get_sample_data,
        //      DOC_EM3000PingRawData(get_sample_data))

        // .def("has_angle", &t_EM3000PingRawData::has_angle, DOC_EM3000PingRawData(has_angle))
        // .def("has_power", &t_EM3000PingRawData::has_power, DOC_EM3000PingRawData(has_power))

        // .def("load_data", &t_EM3000PingRawData::load_data, DOC_EM3000PingRawData(load_data))
        // .def(
        //     "release_data", &t_EM3000PingRawData::release_data, DOC_EM3000PingRawData(release_data))


        // ----- this is also commented out in simrad equivalent-----
        // ----- operators -----
        // .def("__eq__",
        //      &EM3000Ping::operator==,
        //      DOC(themachinethatgoesping, echosounders, em3000, filedatatypes,  EM3000Ping,
        //      operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_EM3000PingRawData)
        // default binary functions
        __PYCLASS_DEFAULT_PRINTING__(t_EM3000PingRawData)
        // end EM3000Ping
        ;
}

void init_c_em3000pingrawdata(pybind11::module& m)
{

    py_create_class_em3000pingrawdata<std::ifstream>(m, "EM3000PingRawData");
    py_create_class_em3000pingrawdata<datastreams::MappedFileStream>(m, "EM3000PingRawData_mapped");
}

}
}
}
}
}