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
#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_SimradRawPingFileData(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingFileData, ARG)

template<typename T_FileStream>
void py_create_class_simradrawPingFileData(py::module& m, const std::string& CLASS_NAME)
{
    using t_SimradRawPingFileData = filedatatypes::SimradRawPingFileData<T_FileStream>;

    py::class_<t_SimradRawPingFileData, std::shared_ptr<t_SimradRawPingFileData>>(
        m,
        (CLASS_NAME).c_str(),
        DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingFileData))

        // --- file_data data access ---
        .def_readonly("ping_data",
                      &t_SimradRawPingFileData::_ping_data,
                      DOC_SimradRawPingFileData(ping_data),
                      py::return_value_policy::reference_internal)
        .def("get_parameter",
             &t_SimradRawPingFileData::get_parameter,
             DOC_SimradRawPingFileData(get_parameter))

        .def("get_sample_data",
             &t_SimradRawPingFileData::get_sample_data,
             DOC_SimradRawPingFileData(get_sample_data))

        .def("has_angle", &t_SimradRawPingFileData::has_angle, DOC_SimradRawPingFileData(has_angle))
        .def("has_power", &t_SimradRawPingFileData::has_power, DOC_SimradRawPingFileData(has_power))

        .def("load", &t_SimradRawPingFileData::load, DOC_SimradRawPingFileData(load))
        .def("load", &t_SimradRawPingFileData::load, DOC_SimradRawPingFileData(load))

        // ----- operators -----
        // .def("__eq__",
        //      &SimradRawPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes,  SimradRawPing,
        //      operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_SimradRawPingFileData)
        // default binary functions
        __PYCLASS_DEFAULT_PRINTING__(t_SimradRawPingFileData)
        // end SimradRawPing
        ;
}

void init_c_simradrawPingFileData(pybind11::module& m)
{

    py_create_class_simradrawPingFileData<std::ifstream>(m, "SimradRawPingFileData");
    py_create_class_simradrawPingFileData<datastreams::MappedFileStream>(m, "SimradRawPingFileData_mapped");
}

}
}
}
}
}