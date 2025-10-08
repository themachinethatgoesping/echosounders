// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xmlconfigurationtransceiverchanneltransducer.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XMLConfigurationTransceiverChannelTransducer;

void init_c_xmlconfigurationtransceiverchanneltransducer(nanobind::module_& m)
{
    nb::class_<XMLConfigurationTransceiverChannelTransducer>(
        m,
        "XMLConfigurationTransceiverChannelTransducer",
        DOC(themachinethatgoesping,
            echosounders,
            simradraw,
            datagrams,
            xml_datagrams,
            XMLConfigurationTransceiverChannelTransducer))
        .def(nb::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XMLConfigurationTransceiverChannelTransducer,
                 XMLConfigurationTransceiverChannelTransducer))

        // ----- children -----
        .def_rw("FrequencyPars",
                       &XMLConfigurationTransceiverChannelTransducer::FrequencyPars,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           FrequencyPars))

        // ----- attributes -----
        .def_rw("TransducerName",
                       &XMLConfigurationTransceiverChannelTransducer::TransducerName,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           TransducerName))
        .def_rw("ArticleNumber",
                       &XMLConfigurationTransceiverChannelTransducer::ArticleNumber,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           ArticleNumber))
        .def_rw("Gain",
                       &XMLConfigurationTransceiverChannelTransducer::Gain,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           Gain))
        .def_rw("SaCorrection",
                       &XMLConfigurationTransceiverChannelTransducer::SaCorrection,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           SaCorrection))
        .def_rw("SerialNumber",
                       &XMLConfigurationTransceiverChannelTransducer::SerialNumber,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           SerialNumber))
        .def_rw("BeamType",
                       &XMLConfigurationTransceiverChannelTransducer::BeamType,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           BeamType))
        .def_rw("Frequency",
                       &XMLConfigurationTransceiverChannelTransducer::Frequency,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           Frequency))
        .def_rw("FrequencyMinimum",
                       &XMLConfigurationTransceiverChannelTransducer::FrequencyMinimum,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           FrequencyMinimum))
        .def_rw("FrequencyMaximum",
                       &XMLConfigurationTransceiverChannelTransducer::FrequencyMaximum,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           FrequencyMaximum))
        .def_rw("EquivalentBeamAngle",
                       &XMLConfigurationTransceiverChannelTransducer::EquivalentBeamAngle,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           EquivalentBeamAngle))
        .def_rw("MaxTxPowerTransducer",
                       &XMLConfigurationTransceiverChannelTransducer::MaxTxPowerTransducer,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           MaxTxPowerTransducer))
        .def_rw("BeamWidthAlongship",
                       &XMLConfigurationTransceiverChannelTransducer::BeamWidthAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           BeamWidthAlongship))
        .def_rw("BeamWidthAthwartship",
                       &XMLConfigurationTransceiverChannelTransducer::BeamWidthAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           BeamWidthAthwartship))
        .def_rw("AngleSensitivityAlongship",
                       &XMLConfigurationTransceiverChannelTransducer::AngleSensitivityAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           AngleSensitivityAlongship))
        .def_rw("AngleSensitivityAthwartship",
                       &XMLConfigurationTransceiverChannelTransducer::AngleSensitivityAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           AngleSensitivityAthwartship))
        .def_rw("AngleOffsetAlongship",
                       &XMLConfigurationTransceiverChannelTransducer::AngleOffsetAlongship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           AngleOffsetAlongship))
        .def_rw("AngleOffsetAthwartship",
                       &XMLConfigurationTransceiverChannelTransducer::AngleOffsetAthwartship,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           AngleOffsetAthwartship))
        .def_rw("DirectivityDropAt2XBeamWidth",
                       &XMLConfigurationTransceiverChannelTransducer::DirectivityDropAt2XBeamWidth,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           DirectivityDropAt2XBeamWidth))

        .def_rw("unknown_children",
                       &XMLConfigurationTransceiverChannelTransducer::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationTransceiverChannelTransducer,
                           unknown_children))
        .def_rw("unknown_attributes",
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