// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_configuration_transducer.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Configuration_Transducer;

#define LOCAL_CLASS_DOC_PREFIX                                                                     \
    themachinethatgoesping, echosounders, simradraw, datagrams, xml_datagrams,                        \
        XML_Configuration_Transducer

void init_c_xml_configuration_transducer(nanobind::module_& m)
{
    nb::class_<XML_Configuration_Transducer>(
        m, "XML_Configuration_Transducer", DOC(LOCAL_CLASS_DOC_PREFIX))
        .def(nb::init<>(), DOC(LOCAL_CLASS_DOC_PREFIX, XML_Configuration_Transducer))

        // ----- methods -----
        .def("get_sensor_offsets",
             &XML_Configuration_Transducer::get_sensor_offsets,
             DOC(LOCAL_CLASS_DOC_PREFIX, get_sensor_offsets))

        // ----- children -----

        // ----- attributes -----
        .def_rw("TransducerAlphaX",
                       &XML_Configuration_Transducer::TransducerAlphaX,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerAlphaX))
        .def_rw("TransducerAlphaY",
                       &XML_Configuration_Transducer::TransducerAlphaY,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerAlphaY))
        .def_rw("TransducerAlphaZ",
                       &XML_Configuration_Transducer::TransducerAlphaZ,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerAlphaZ))
        .def_rw("TransducerOffsetX",
                       &XML_Configuration_Transducer::TransducerOffsetX,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerOffsetX))
        .def_rw("TransducerOffsetY",
                       &XML_Configuration_Transducer::TransducerOffsetY,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerOffsetY))
        .def_rw("TransducerOffsetZ",
                       &XML_Configuration_Transducer::TransducerOffsetZ,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerOffsetZ))
        .def_rw("HeadingQuickCalibration",
                       &XML_Configuration_Transducer::HeadingQuickCalibration,
                       DOC(LOCAL_CLASS_DOC_PREFIX, HeadingQuickCalibration))
        .def_rw("TransducerSerialNumber",
                       &XML_Configuration_Transducer::TransducerSerialNumber,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerSerialNumber))
        .def_rw("TransducerMounting",
                       &XML_Configuration_Transducer::TransducerMounting,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerMounting))
        .def_rw("TransducerName",
                       &XML_Configuration_Transducer::TransducerName,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerName))
        .def_rw("TransducerCustomName",
                       &XML_Configuration_Transducer::TransducerCustomName,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerCustomName))

        .def_rw("unknown_children",
                       &XML_Configuration_Transducer::unknown_children,
                       DOC(LOCAL_CLASS_DOC_PREFIX, unknown_children))
        .def_rw("unknown_attributes",
                       &XML_Configuration_Transducer::unknown_attributes,
                       DOC(LOCAL_CLASS_DOC_PREFIX, unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_Transducer::parsed_completely,
             DOC(LOCAL_CLASS_DOC_PREFIX, parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Configuration_Transducer)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Configuration_Transducer)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Configuration_Transducer)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}