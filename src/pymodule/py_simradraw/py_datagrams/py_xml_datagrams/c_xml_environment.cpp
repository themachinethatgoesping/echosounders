// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_environment.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Environment;

#define LOCAL_CLASS_DOC_PREFIX                                                                     \
    themachinethatgoesping, echosounders, simradraw, datagrams, xml_datagrams, XML_Environment

void init_c_xml_environment(pybind11::module& m)
{
    py::class_<XML_Environment>(m, "XML_Environment", DOC(LOCAL_CLASS_DOC_PREFIX))
        .def(py::init<>(), DOC(LOCAL_CLASS_DOC_PREFIX, XML_Environment))

        // ----- children -----
        .def_readwrite(
            "Transducers", &XML_Environment::Transducers, DOC(LOCAL_CLASS_DOC_PREFIX, Transducers))

        // ----- attributes -----
        .def_readwrite("WaterLevelDraft",
                       &XML_Environment::WaterLevelDraft,
                       DOC(LOCAL_CLASS_DOC_PREFIX, WaterLevelDraft))
        .def_readwrite("DropKeelOffsetIsManual",
                       &XML_Environment::DropKeelOffsetIsManual,
                       DOC(LOCAL_CLASS_DOC_PREFIX, DropKeelOffsetIsManual))
        .def_readwrite("DropKeelOffset",
                       &XML_Environment::DropKeelOffset,
                       DOC(LOCAL_CLASS_DOC_PREFIX, DropKeelOffset))
        .def_readwrite("SoundVelocityProfile",
                       &XML_Environment::SoundVelocityProfile,
                       DOC(LOCAL_CLASS_DOC_PREFIX, SoundVelocityProfile))
        .def_readwrite("WaterLevelDraftIsManual",
                       &XML_Environment::WaterLevelDraftIsManual,
                       DOC(LOCAL_CLASS_DOC_PREFIX, WaterLevelDraftIsManual))
        .def_readwrite(
            "Latitude", &XML_Environment::Latitude, DOC(LOCAL_CLASS_DOC_PREFIX, Latitude))
        .def_readwrite(
            "SoundSpeed", &XML_Environment::SoundSpeed, DOC(LOCAL_CLASS_DOC_PREFIX, SoundSpeed))
        .def_readwrite(
            "Salinity", &XML_Environment::Salinity, DOC(LOCAL_CLASS_DOC_PREFIX, Salinity))
        .def_readwrite("SoundVelocitySource",
                       &XML_Environment::SoundVelocitySource,
                       DOC(LOCAL_CLASS_DOC_PREFIX, SoundVelocitySource))
        .def_readwrite("Acidity", &XML_Environment::Acidity, DOC(LOCAL_CLASS_DOC_PREFIX, Acidity))
        .def_readwrite(
            "Temperature", &XML_Environment::Temperature, DOC(LOCAL_CLASS_DOC_PREFIX, Temperature))
        .def_readwrite("Depth", &XML_Environment::Depth, DOC(LOCAL_CLASS_DOC_PREFIX, Depth))

        .def_readwrite("unknown_children",
                       &XML_Environment::unknown_children,
                       DOC(LOCAL_CLASS_DOC_PREFIX, unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Environment::unknown_attributes,
                       DOC(LOCAL_CLASS_DOC_PREFIX, unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Environment::parsed_completely,
             DOC(LOCAL_CLASS_DOC_PREFIX, parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Environment)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Environment)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Environment)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}