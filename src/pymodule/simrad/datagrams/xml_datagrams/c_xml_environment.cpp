// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_environment.hpp"
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
using datagrams::xml_datagrams::XML_Environment;

void init_c_xml_environment(pybind11::module& m)
{
    py::class_<XML_Environment>(m,
                                      "XML_Environment",
                                      DOC(themachinethatgoesping,
                                          echosounders,
                                          simrad,
                                          datagrams,
                                          xml_datagrams,
                                          XML_Environment))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Environment,
                 XML_Environment))
                 

        // ----- children -----
        .def_readwrite("Transducer",
                       &XML_Environment::Transducer,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Environment,
                           Transducer))

        // ----- attributes -----
        .def_readwrite("WaterLevelDraft",
                       &XML_Environment::WaterLevelDraft,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Environment,
                           WaterLevelDraft))
        .def_readwrite("DropKeelOffsetIsManual",
                          &XML_Environment::DropKeelOffsetIsManual,
                          DOC(themachinethatgoesping,
                            echosounders,
                            simrad,
                            datagrams,
                            xml_datagrams,
                            XML_Environment,
                            DropKeelOffsetIsManual))
        .def_readwrite("DropKeelOffset",
                            &XML_Environment::DropKeelOffset,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Environment,
                                DropKeelOffset))
        .def_readwrite("SoundVelocityProfile",
                            &XML_Environment::SoundVelocityProfile,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Environment,
                                SoundVelocityProfile))
        .def_readwrite("WaterLevelDraftIsManual",
                            &XML_Environment::WaterLevelDraftIsManual,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Environment,
                                WaterLevelDraftIsManual))
        .def_readwrite("Latitude",
                            &XML_Environment::Latitude,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Environment,
                                Latitude))
        .def_readwrite("SoundSpeed",
                            &XML_Environment::SoundSpeed,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Environment,
                                SoundSpeed))
        .def_readwrite("Salinity",
                            &XML_Environment::Salinity,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Environment,
                                Salinity))
        .def_readwrite("SoundVelocitySource",
                            &XML_Environment::SoundVelocitySource,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Environment,
                                SoundVelocitySource))
        .def_readwrite("Acidity",
                            &XML_Environment::Acidity,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Environment,
                                Acidity))
        .def_readwrite("Temperature",
                            &XML_Environment::Temperature,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Environment,
                                Temperature))
        .def_readwrite("Depth",
                            &XML_Environment::Depth,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Environment,
                                Depth))

        
        .def_readwrite("unknown_children",
                       &XML_Environment::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Environment,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Environment::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Environment,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Environment::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Environment,
                 parsed_completely))

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