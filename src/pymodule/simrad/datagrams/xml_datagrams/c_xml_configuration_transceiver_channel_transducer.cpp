// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_configuration_transceiver_channel_transducer.hpp"
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
using datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel_Transducer;

void init_c_xml_configuration_transceiver_channel_transducer(pybind11::module& m)
{
    py::class_<XML_Configuration_Transceiver_Channel_Transducer>(
        m,
        "XML_Configuration_Transceiver_Channel_Transducer",
        DOC(themachinethatgoesping,
            echosounders,
            simrad,
            datagrams,
            xml_datagrams,
            XML_Configuration_Transceiver_Channel_Transducer))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Transceiver_Channel_Transducer,
                 XML_Configuration_Transceiver_Channel_Transducer))

        // ----- children -----
        .def_readwrite("FrequencyPars",
                       &XML_Configuration_Transceiver_Channel_Transducer::FrequencyPars,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           FrequencyPars))

        // ----- attributes -----
        .def_readwrite("TransducerName",
                       &XML_Configuration_Transceiver_Channel_Transducer::TransducerName,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           TransducerName))
        .def_readwrite("ArticleNumber",
                       &XML_Configuration_Transceiver_Channel_Transducer::ArticleNumber,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           ArticleNumber))
        .def_readwrite("Gain",
                       &XML_Configuration_Transceiver_Channel_Transducer::Gain,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           Gain))
        .def_readwrite("SaCorrection",
                       &XML_Configuration_Transceiver_Channel_Transducer::SaCorrection,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           SaCorrection))
        .def_readwrite("SerialNumber",
                       &XML_Configuration_Transceiver_Channel_Transducer::SerialNumber,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           SerialNumber))
        .def_readwrite("BeamType",
                       &XML_Configuration_Transceiver_Channel_Transducer::BeamType,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           BeamType))
        .def_readwrite("Frequency",
                       &XML_Configuration_Transceiver_Channel_Transducer::Frequency,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           Frequency))
        .def_readwrite("FrequencyMinimum",
                       &XML_Configuration_Transceiver_Channel_Transducer::FrequencyMinimum,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           FrequencyMinimum))
        .def_readwrite("FrequencyMaximum",
                       &XML_Configuration_Transceiver_Channel_Transducer::FrequencyMaximum,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           FrequencyMaximum))
        .def_readwrite("EquivalentBeamAngle",
                       &XML_Configuration_Transceiver_Channel_Transducer::EquivalentBeamAngle,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           EquivalentBeamAngle))
        .def_readwrite("MaxTxPowerTransducer",
                       &XML_Configuration_Transceiver_Channel_Transducer::MaxTxPowerTransducer,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           MaxTxPowerTransducer))
        .def_readwrite("BeamWidthAlongship",
                       &XML_Configuration_Transceiver_Channel_Transducer::BeamWidthAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           BeamWidthAlongship))
        .def_readwrite("BeamWidthAthwartship",
                       &XML_Configuration_Transceiver_Channel_Transducer::BeamWidthAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           BeamWidthAthwartship))
        .def_readwrite("AngleSensitivityAlongship",
                       &XML_Configuration_Transceiver_Channel_Transducer::AngleSensitivityAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           AngleSensitivityAlongship))
        .def_readwrite(
            "AngleSensitivityAthwartship",
            &XML_Configuration_Transceiver_Channel_Transducer::AngleSensitivityAthwartship,
            DOC(themachinethatgoesping,
                echosounders,
                simrad,
                datagrams,
                xml_datagrams,
                XML_Configuration_Transceiver_Channel_Transducer,
                AngleSensitivityAthwartship))
        .def_readwrite("AngleOffsetAlongship",
                       &XML_Configuration_Transceiver_Channel_Transducer::AngleOffsetAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           AngleOffsetAlongship))
        .def_readwrite("AngleOffsetAthwartship",
                       &XML_Configuration_Transceiver_Channel_Transducer::AngleOffsetAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           AngleOffsetAthwartship))
        .def_readwrite(
            "DirectivityDropAt2XBeamWidth",
            &XML_Configuration_Transceiver_Channel_Transducer::DirectivityDropAt2XBeamWidth,
            DOC(themachinethatgoesping,
                echosounders,
                simrad,
                datagrams,
                xml_datagrams,
                XML_Configuration_Transceiver_Channel_Transducer,
                DirectivityDropAt2XBeamWidth))

        .def_readwrite("unknown_children",
                       &XML_Configuration_Transceiver_Channel_Transducer::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Configuration_Transceiver_Channel_Transducer::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel_Transducer,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_Transceiver_Channel_Transducer::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Transceiver_Channel_Transducer,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Configuration_Transceiver_Channel_Transducer)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Configuration_Transceiver_Channel_Transducer)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Configuration_Transceiver_Channel_Transducer)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}