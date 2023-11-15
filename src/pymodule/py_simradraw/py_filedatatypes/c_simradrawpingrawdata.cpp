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
#include "../../../themachinethatgoesping/echosounders/simradraw/filedatatypes/simradrawping.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/simradraw_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/simradraw_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_SimradRawPingRawData(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingRawData, ARG)

template<typename T_FileStream>
void py_create_class_simradrawpingrawdata(py::module& m, const std::string& CLASS_NAME)
{
    using t_SimradRawPingRawData = filedatatypes::SimradRawPingRawData<T_FileStream>;

    py::class_<t_SimradRawPingRawData, std::shared_ptr<t_SimradRawPingRawData>>(
        m,
        (CLASS_NAME).c_str(),
        DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingRawData))

        // --- raw_data data access ---
        .def_readonly("ping_data",
                      &t_SimradRawPingRawData::_ping_data,
                      DOC_SimradRawPingRawData(ping_data),
                      py::return_value_policy::reference_internal)
        .def("get_parameter",
             &t_SimradRawPingRawData::get_parameter,
             DOC_SimradRawPingRawData(get_parameter))

        .def("get_sample_data",
             &t_SimradRawPingRawData::get_sample_data,
             DOC_SimradRawPingRawData(get_sample_data))

        .def("has_angle", &t_SimradRawPingRawData::has_angle, DOC_SimradRawPingRawData(has_angle))
        .def("has_power", &t_SimradRawPingRawData::has_power, DOC_SimradRawPingRawData(has_power))

        .def("load", &t_SimradRawPingRawData::load, DOC_SimradRawPingRawData(load))
        .def("load", &t_SimradRawPingRawData::load, DOC_SimradRawPingRawData(load))

        // ----- operators -----
        // .def("__eq__",
        //      &SimradRawPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes,  SimradRawPing,
        //      operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_SimradRawPingRawData)
        // default binary functions
        __PYCLASS_DEFAULT_PRINTING__(t_SimradRawPingRawData)
        // end SimradRawPing
        ;
}

void init_c_simradrawpingrawdata(pybind11::module& m)
{

    py_create_class_simradrawpingrawdata<std::ifstream>(m, "SimradRawPingRawData");
    py_create_class_simradrawpingrawdata<datastreams::MappedFileStream>(m, "SimradRawPingRawData_mapped");
}

}
}
}
}
}