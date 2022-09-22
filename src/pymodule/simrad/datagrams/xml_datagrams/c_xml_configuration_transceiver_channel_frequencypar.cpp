// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_configuration_transceiver_channel_frequencypar.hpp"
#include "../../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel_FrequencyPar;

void init_c_xml_configuration_transceiver_channel_frequencypar(pybind11::module& m)
{
    py::class_<XML_Configuration_Transceiver_Channel_FrequencyPar>(
        m,
        "XML_Configuration_Transceiver_Channel_FrequencyPar",
        DOC(themachinethatgoesping,
            echosounders,
            simrad,
            datagrams,
            xml_datagrams,
            XML_Configuration_Transceiver_Channel_FrequencyPar))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Transceiver_Channel_FrequencyPar,
                 XML_Configuration_Transceiver_Channel_FrequencyPar))

        // ----- children -----

        // ----- attributes -----
        .def_readwrite("Frequency",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::Frequency,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           Frequency))
        .def_readwrite("Gain",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::Gain,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           Gain))
        .def_readwrite("Impedance",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::Impedance,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           Impedance))
        .def_readwrite("Phase",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::Phase,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           Phase))
        .def_readwrite("BeamWidthAlongship",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::BeamWidthAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           BeamWidthAlongship))
        .def_readwrite("BeamWidthAthwartship",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::BeamWidthAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           BeamWidthAthwartship))
        .def_readwrite("AngleOffsetAlongship",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::AngleOffsetAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           AngleOffsetAlongship))
        .def_readwrite("AngleOffsetAthwartship",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::AngleOffsetAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           AngleOffsetAthwartship))

        .def_readwrite("unknown_children",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_Transceiver_Channel_FrequencyPar::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Transceiver_Channel_FrequencyPar,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Configuration_Transceiver_Channel_FrequencyPar)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Configuration_Transceiver_Channel_FrequencyPar)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Configuration_Transceiver_Channel_FrequencyPar)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}