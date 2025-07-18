// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp>                 // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../../themachinethatgoesping/echosounders/simradraw/filedatatypes/simradrawping.hpp"
#include "../../../../themachinethatgoesping/echosounders/simradraw/types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {
namespace py_sub {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_transceiverinformation(ARG)                                                            \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                 \
        filedatatypes,                                                                             \
        sub,                                                                                       \
        TransceiverInformation,                                                                    \
        ARG)

void init_c_transceiverinformation(pybind11::module& m)
{
    using t_TransceiverInformation      = filedatatypes::_sub::TransceiverInformation;
    static const std::string CLASS_NAME = "TransceiverInformation";

    auto cls =
        py::class_<t_TransceiverInformation, std::shared_ptr<t_TransceiverInformation>>(
            m,
            (CLASS_NAME).c_str(),
            DOC(themachinethatgoesping,
                echosounders,
                simradraw,
                filedatatypes,
                sub,
                TransceiverInformation))
            .def(py::init<const datagrams::xml_datagrams::XML_Configuration_Transceiver&,
                          const datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel&>(),
                 DOC_transceiverinformation(TransceiverInformation_2),
                 py::arg("ping_transceiver"),
                 py::arg("ping_transceiver_channel"))

            // --- transceiver information ---
            .def("get_transceiver",
                 &t_TransceiverInformation::get_transceiver,
                 DOC_transceiverinformation(get_transceiver))
            .def("get_transceiver_channel",
                 &t_TransceiverInformation::get_transceiver_channel,
                 DOC_transceiverinformation(get_transceiver_channel))
            .def("get_transducer",
                 &t_TransceiverInformation::get_transducer,
                 DOC_transceiverinformation(get_transducer))
            .def("is_initialized",
                 &t_TransceiverInformation::is_initialized,
                 DOC_transceiverinformation(is_initialized))
            .def("get_impedance_factor",
                 &t_TransceiverInformation::get_impedance_factor,
                 DOC_transceiverinformation(get_impedance_factor))
            .def_static("compute_impedance_factor",
                        &t_TransceiverInformation::compute_impedance_factor,
                        DOC_transceiverinformation(compute_impedance_factor),
                        py::arg("transceiver_impedance"),
                        py::arg("transducer_impedance") = 75)
            .def("get_pulse_duration_index",
                 py::overload_cast<const datagrams::xml_datagrams::XML_Parameter_Channel&>(
                     &t_TransceiverInformation::get_pulse_duration_index, py::const_),
                 DOC_transceiverinformation(get_pulse_duration_index),
                 py::arg("xml_parameter_datagram"))
            .def("get_pulse_duration_index",
                 py::overload_cast<float, bool>(&t_TransceiverInformation::get_pulse_duration_index,
                                                py::const_),
                 DOC_transceiverinformation(get_pulse_duration_index),
                 py::arg("pulse_duration"),
                 py::arg("fm"))
            .def("get_pulse_duration_index_optional",
                 py::overload_cast<const datagrams::xml_datagrams::XML_Parameter_Channel&>(
                     &t_TransceiverInformation::get_pulse_duration_index, py::const_),
                 DOC_transceiverinformation(get_pulse_duration_index),
                 py::arg("xml_parameter_datagram"))
            .def("get_pulse_duration_index_optional",
                 py::overload_cast<float, bool>(&t_TransceiverInformation::get_pulse_duration_index,
                                                py::const_),
                 DOC_transceiverinformation(get_pulse_duration_index),
                 py::arg("pulse_duration"),
                 py::arg("fm"))

            // ----- operators -----
            .def("__eq__",
                 &t_TransceiverInformation::operator==,
                 DOC_transceiverinformation(operator_eq),
                 py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_TransceiverInformation)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(t_TransceiverInformation)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(t_TransceiverInformation)
        // end t_TransceiverInformation
        ;
}

}
}
}
}
}
}