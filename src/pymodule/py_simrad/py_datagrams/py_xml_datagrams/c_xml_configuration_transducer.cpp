// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../docstrings.hpp"
#include "module.hpp"
#include <themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_configuration_transducer.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::xml_datagrams::XML_Configuration_Transducer;

#define LOCAL_CLASS_DOC_PREFIX                                                                     \
    themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams,                        \
        XML_Configuration_Transducer

void init_c_xml_configuration_transducer(pybind11::module& m)
{
    py::class_<XML_Configuration_Transducer>(
        m, "XML_Configuration_Transducer", DOC(LOCAL_CLASS_DOC_PREFIX))
        .def(py::init<>(), DOC(LOCAL_CLASS_DOC_PREFIX, XML_Configuration_Transducer))

        // ----- methods -----
        .def("get_sensor_offsets",
             &XML_Configuration_Transducer::get_sensor_offsets,
             DOC(LOCAL_CLASS_DOC_PREFIX, get_sensor_offsets))

        // ----- children -----

        // ----- attributes -----
        .def_readwrite("TransducerAlphaX",
                       &XML_Configuration_Transducer::TransducerAlphaX,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerAlphaX))
        .def_readwrite("TransducerAlphaY",
                       &XML_Configuration_Transducer::TransducerAlphaY,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerAlphaY))
        .def_readwrite("TransducerAlphaZ",
                       &XML_Configuration_Transducer::TransducerAlphaZ,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerAlphaZ))
        .def_readwrite("TransducerOffsetX",
                       &XML_Configuration_Transducer::TransducerOffsetX,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerOffsetX))
        .def_readwrite("TransducerOffsetY",
                       &XML_Configuration_Transducer::TransducerOffsetY,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerOffsetY))
        .def_readwrite("TransducerOffsetZ",
                       &XML_Configuration_Transducer::TransducerOffsetZ,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerOffsetZ))
        .def_readwrite("HeadingQuickCalibration",
                       &XML_Configuration_Transducer::HeadingQuickCalibration,
                       DOC(LOCAL_CLASS_DOC_PREFIX, HeadingQuickCalibration))
        .def_readwrite("TransducerSerialNumber",
                       &XML_Configuration_Transducer::TransducerSerialNumber,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerSerialNumber))
        .def_readwrite("TransducerMounting",
                       &XML_Configuration_Transducer::TransducerMounting,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerMounting))
        .def_readwrite("TransducerName",
                       &XML_Configuration_Transducer::TransducerName,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerName))
        .def_readwrite("TransducerCustomName",
                       &XML_Configuration_Transducer::TransducerCustomName,
                       DOC(LOCAL_CLASS_DOC_PREFIX, TransducerCustomName))

        .def_readwrite("unknown_children",
                       &XML_Configuration_Transducer::unknown_children,
                       DOC(LOCAL_CLASS_DOC_PREFIX, unknown_children))
        .def_readwrite("unknown_attributes",
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