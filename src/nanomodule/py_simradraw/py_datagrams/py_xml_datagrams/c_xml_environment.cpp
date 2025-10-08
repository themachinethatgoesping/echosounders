// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/map.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_environment.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Environment;

#define LOCAL_CLASS_DOC_PREFIX                                                                     \
    themachinethatgoesping, echosounders, simradraw, datagrams, xml_datagrams, XML_Environment

void init_c_xml_environment(nanobind::module_& m)
{
    nb::class_<XML_Environment>(m, "XML_Environment", DOC(LOCAL_CLASS_DOC_PREFIX))
        .def(nb::init<>(), DOC(LOCAL_CLASS_DOC_PREFIX, XML_Environment))

        // ----- children -----
        .def_rw(
            "Transducers", &XML_Environment::Transducers, DOC(LOCAL_CLASS_DOC_PREFIX, Transducers))

        // ----- attributes -----
        .def_rw("WaterLevelDraft",
                       &XML_Environment::WaterLevelDraft,
                       DOC(LOCAL_CLASS_DOC_PREFIX, WaterLevelDraft))
        .def_rw("DropKeelOffsetIsManual",
                       &XML_Environment::DropKeelOffsetIsManual,
                       DOC(LOCAL_CLASS_DOC_PREFIX, DropKeelOffsetIsManual))
        .def_rw("DropKeelOffset",
                       &XML_Environment::DropKeelOffset,
                       DOC(LOCAL_CLASS_DOC_PREFIX, DropKeelOffset))
        .def_rw("SoundVelocityProfile",
                       &XML_Environment::SoundVelocityProfile,
                       DOC(LOCAL_CLASS_DOC_PREFIX, SoundVelocityProfile))
        .def_rw("WaterLevelDraftIsManual",
                       &XML_Environment::WaterLevelDraftIsManual,
                       DOC(LOCAL_CLASS_DOC_PREFIX, WaterLevelDraftIsManual))
        .def_rw(
            "Latitude", &XML_Environment::Latitude, DOC(LOCAL_CLASS_DOC_PREFIX, Latitude))
        .def_rw(
            "SoundSpeed", &XML_Environment::SoundSpeed, DOC(LOCAL_CLASS_DOC_PREFIX, SoundSpeed))
        .def_rw(
            "Salinity", &XML_Environment::Salinity, DOC(LOCAL_CLASS_DOC_PREFIX, Salinity))
        .def_rw("SoundVelocitySource",
                       &XML_Environment::SoundVelocitySource,
                       DOC(LOCAL_CLASS_DOC_PREFIX, SoundVelocitySource))
        .def_rw("Acidity", &XML_Environment::Acidity, DOC(LOCAL_CLASS_DOC_PREFIX, Acidity))
        .def_rw(
            "Temperature", &XML_Environment::Temperature, DOC(LOCAL_CLASS_DOC_PREFIX, Temperature))
        .def_rw("Depth", &XML_Environment::Depth, DOC(LOCAL_CLASS_DOC_PREFIX, Depth))

        .def_rw("unknown_children",
                       &XML_Environment::unknown_children,
                       DOC(LOCAL_CLASS_DOC_PREFIX, unknown_children))
        .def_rw("unknown_attributes",
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