// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xmlconfigurationtransceiverchanneltransducer.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XMLConfigurationTransceiverChannelTransducer;

void init_c_xmlconfigurationtransceiverchanneltransducer(pybind11::module& m)
{
    py::classh<XMLConfigurationTransceiverChannelTransducer>(
        m,
        "XMLConfigurationTransceiverChannelTransducer",
        DOC(themachinethatgoesping,
            echosounders,
            simradraw,
            datagrams,
            xml_datagrams,
            XMLConfigurationTransceiverChannelTransducer))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XMLConfigurationTransceiverChannelTransducer,
                 XMLConfigurationTransceiverChannelTransducer))

        // ----- children -----
        .def_readwrite("FrequencyPars",
                       &XMLConfigurationTransceiverChannelTransducer::FrequencyPars,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           FrequencyPars))

        // ----- attributes -----
        .def_readwrite("TransducerName",
                       &XMLConfigurationTransceiverChannelTransducer::TransducerName,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           TransducerName))
        .def_readwrite("ArticleNumber",
                       &XMLConfigurationTransceiverChannelTransducer::ArticleNumber,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           ArticleNumber))
        .def_readwrite("Gain",
                       &XMLConfigurationTransceiverChannelTransducer::Gain,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           Gain))
        .def_readwrite("SaCorrection",
                       &XMLConfigurationTransceiverChannelTransducer::SaCorrection,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           SaCorrection))
        .def_readwrite("SerialNumber",
                       &XMLConfigurationTransceiverChannelTransducer::SerialNumber,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           SerialNumber))
        .def_readwrite("BeamType",
                       &XMLConfigurationTransceiverChannelTransducer::BeamType,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           BeamType))
        .def_readwrite("Frequency",
                       &XMLConfigurationTransceiverChannelTransducer::Frequency,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           Frequency))
        .def_readwrite("FrequencyMinimum",
                       &XMLConfigurationTransceiverChannelTransducer::FrequencyMinimum,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           FrequencyMinimum))
        .def_readwrite("FrequencyMaximum",
                       &XMLConfigurationTransceiverChannelTransducer::FrequencyMaximum,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           FrequencyMaximum))
        .def_readwrite("EquivalentBeamAngle",
                       &XMLConfigurationTransceiverChannelTransducer::EquivalentBeamAngle,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           EquivalentBeamAngle))
        .def_readwrite("MaxTxPowerTransducer",
                       &XMLConfigurationTransceiverChannelTransducer::MaxTxPowerTransducer,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           MaxTxPowerTransducer))
        .def_readwrite("BeamWidthAlongship",
                       &XMLConfigurationTransceiverChannelTransducer::BeamWidthAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           BeamWidthAlongship))
        .def_readwrite("BeamWidthAthwartship",
                       &XMLConfigurationTransceiverChannelTransducer::BeamWidthAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           BeamWidthAthwartship))
        .def_readwrite("AngleSensitivityAlongship",
                       &XMLConfigurationTransceiverChannelTransducer::AngleSensitivityAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           AngleSensitivityAlongship))
        .def_readwrite("AngleSensitivityAthwartship",
                       &XMLConfigurationTransceiverChannelTransducer::AngleSensitivityAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           AngleSensitivityAthwartship))
        .def_readwrite("AngleOffsetAlongship",
                       &XMLConfigurationTransceiverChannelTransducer::AngleOffsetAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           AngleOffsetAlongship))
        .def_readwrite("AngleOffsetAthwartship",
                       &XMLConfigurationTransceiverChannelTransducer::AngleOffsetAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           AngleOffsetAthwartship))
        .def_readwrite("DirectivityDropAt2XBeamWidth",
                       &XMLConfigurationTransceiverChannelTransducer::DirectivityDropAt2XBeamWidth,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           DirectivityDropAt2XBeamWidth))

        .def_readwrite("unknown_children",
                       &XMLConfigurationTransceiverChannelTransducer::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XMLConfigurationTransceiverChannelTransducer::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XMLConfigurationTransceiverChannelTransducer::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XMLConfigurationTransceiverChannelTransducer,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XMLConfigurationTransceiverChannelTransducer)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XMLConfigurationTransceiverChannelTransducer)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XMLConfigurationTransceiverChannelTransducer)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}