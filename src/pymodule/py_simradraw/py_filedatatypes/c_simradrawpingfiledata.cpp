// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/filedatatypes/simradrawping.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/types.hpp"

#include "../py_filedatainterfaces/c_simradrawdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_simradrawpingfiledata(ARG)                                                             \
    DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingFileData, ARG)

template<typename T_FileStream>
void py_create_class_simradrawPingFileData(py::module& m, const std::string& CLASS_NAME)
{
    using t_SimradRawPingFileData = filedatatypes::SimradRawPingFileData<T_FileStream>;

    auto cls = py::class_<t_SimradRawPingFileData,
                          datatypes::I_PingFileData,
                          std::shared_ptr<t_SimradRawPingFileData>>(m,
                                                                    (CLASS_NAME).c_str(),
                                                                    DOC(themachinethatgoesping,
                                                                        echosounders,
                                                                        simradraw,
                                                                        filedatatypes,
                                                                        SimradRawPingFileData))

                   // --- file_data data access ---
                   .def("get_ping_data",
                        &t_SimradRawPingFileData::get_ping_data,
                        DOC_simradrawpingfiledata(get_ping_data))
                   .def("get_parameter",
                        &t_SimradRawPingFileData::get_parameter,
                        DOC_simradrawpingfiledata(get_parameter))
                   .def("get_environment",
                        &t_SimradRawPingFileData::get_environment,
                        DOC_simradrawpingfiledata(get_environment))

                   .def("read_sample_data",
                        &t_SimradRawPingFileData::read_sample_data,
                        DOC_simradrawpingfiledata(read_sample_data),
                        py::arg("dB") = true)

                   // --- transceiver information ---
                   .def_property_readonly("transceiver_information",
                                          &t_SimradRawPingFileData::get_transceiver_information,
                                          DOC_simradrawpingfiledata(get_transceiver_information),
                                          py::return_value_policy::reference_internal)

               // .def("has_angle", &t_SimradRawPingFileData::has_angle,
               // DOC_simradrawpingfiledata(has_angle)) .def("has_power",
               // &t_SimradRawPingFileData::has_power, DOC_simradrawpingfiledata(has_power))

               // .def("load", &t_SimradRawPingFileData::load, DOC_simradrawpingfiledata(load))
               // .def("load", &t_SimradRawPingFileData::load, DOC_simradrawpingfiledata(load))

               // ----- operators -----
               // .def("__eq__",
               //      &SimradRawPing::operator==,
               //      DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes,
               //      SimradRawPing, operator_eq), py::arg("other"))
               // ----- pybind macros -----
               // default copy functions
               __PYCLASS_DEFAULT_COPY__(t_SimradRawPingFileData)
               // default binary functions
               __PYCLASS_DEFAULT_PRINTING__(t_SimradRawPingFileData)
        // end SimradRawPing
        ;

    // inherit from SimradRawDatagramInterface
    py_filedatainterfaces::SimradRawDatagramInterface_add_interface_functions<
        t_SimradRawPingFileData>(cls);
}

void init_c_simradrawpingfiledata(pybind11::module& m)
{
    static const std::string name        = "SimradRawPingFileData";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_simradrawPingFileData<std::ifstream>(m, name_stream);
    py_create_class_simradrawPingFileData<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}