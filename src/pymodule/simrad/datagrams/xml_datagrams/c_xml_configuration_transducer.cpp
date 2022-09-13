// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_configuration_transducer.hpp"
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
using datagrams::xml_datagrams::XML_Configuration_Transducer;

void init_c_xml_configuration_transducer(pybind11::module& m)
{
    py::class_<XML_Configuration_Transducer>(m,
                                      "XML_Configuration_Transducer",
                                      DOC(themachinethatgoesping,
                                          echosounders,
                                          simrad,
                                          datagrams,
                                          xml_datagrams,
                                          XML_Configuration_Transducer))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Transducer,
                 XML_Configuration_Transducer))

        // ----- children -----


        // ----- attributes -----
        .def_readwrite("TransducerAlphaX",
                       &XML_Configuration_Transducer::TransducerAlphaX,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           TransducerAlphaX))
        .def_readwrite("TransducerAlphaY",
                       &XML_Configuration_Transducer::TransducerAlphaY,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           TransducerAlphaY))
        .def_readwrite("TransducerAlphaZ",
                       &XML_Configuration_Transducer::TransducerAlphaZ,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           TransducerAlphaZ))
        .def_readwrite("TransducerOffsetX",
                       &XML_Configuration_Transducer::TransducerOffsetX,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           TransducerOffsetX))
        .def_readwrite("TransducerOffsetY",
                       &XML_Configuration_Transducer::TransducerOffsetY,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           TransducerOffsetY))
        .def_readwrite("TransducerOffsetZ",
                       &XML_Configuration_Transducer::TransducerOffsetZ,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           TransducerOffsetZ))
        .def_readwrite("TransducerSerialNumber",
                       &XML_Configuration_Transducer::TransducerSerialNumber,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           TransducerSerialNumber))
        .def_readwrite("TransducerMounting",
                       &XML_Configuration_Transducer::TransducerMounting,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           TransducerMounting))
        .def_readwrite("TransducerName",
                       &XML_Configuration_Transducer::TransducerName,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           TransducerName))
        .def_readwrite("TransducerCustomName",
                       &XML_Configuration_Transducer::TransducerCustomName,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           TransducerCustomName))        
        
        .def_readwrite("unknown_children",
                       &XML_Configuration_Transducer::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Configuration_Transducer::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transducer,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_Transducer::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Transducer,
                 parsed_completely))

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