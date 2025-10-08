// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_configuration_transceiver_channel_frequencypar.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel_FrequencyPar;

void init_c_xml_configuration_transceiver_channel_frequencypar(nanobind::module_& m)
{
    nb::class_<XML_Configuration_Transceiver_Channel_FrequencyPar>(
        m,
        "XML_Configuration_Transceiver_Channel_FrequencyPar",
        DOC(themachinethatgoesping,
            echosounders,
            simradraw,
            datagrams,
            xml_datagrams,
            XML_Configuration_Transceiver_Channel_FrequencyPar))
        .def(nb::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Transceiver_Channel_FrequencyPar,
                 XML_Configuration_Transceiver_Channel_FrequencyPar))

        // ----- children -----

        // ----- attributes -----
        .def_rw("Frequency",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::Frequency,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           Frequency))
        .def_rw("Gain",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::Gain,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           Gain))
        .def_rw("Impedance",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::Impedance,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           Impedance))
        .def_rw("Phase",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::Phase,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           Phase))
        .def_rw("BeamWidthAlongship",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::BeamWidthAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           BeamWidthAlongship))
        .def_rw("BeamWidthAthwartship",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::BeamWidthAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           BeamWidthAthwartship))
        .def_rw("AngleOffsetAlongship",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::AngleOffsetAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           AngleOffsetAlongship))
        .def_rw("AngleOffsetAthwartship",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::AngleOffsetAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           AngleOffsetAthwartship))

        .def_rw("unknown_children",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           unknown_children))
        .def_rw("unknown_attributes",
                       &XML_Configuration_Transceiver_Channel_FrequencyPar::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_FrequencyPar,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_Transceiver_Channel_FrequencyPar::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
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