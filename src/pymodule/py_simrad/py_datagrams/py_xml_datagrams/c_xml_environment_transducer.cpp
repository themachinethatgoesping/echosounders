// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0



#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_environment_transducer.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::xml_datagrams::XML_Environment_Transducer;

void init_c_xml_environment_transducer(pybind11::module& m)
{
    py::class_<XML_Environment_Transducer>(m,
                                           "XML_Environment_Transducer",
                                           DOC(themachinethatgoesping,
                                               echosounders,
                                               simrad,
                                               datagrams,
                                               xml_datagrams,
                                               XML_Environment_Transducer))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Environment_Transducer,
                 XML_Environment_Transducer))

        // ----- attributes -----
        .def_readwrite("SoundSpeed",
                       &XML_Environment_Transducer::SoundSpeed,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Environment_Transducer,
                           SoundSpeed))
        .def_readwrite("TransducerName",
                       &XML_Environment_Transducer::TransducerName,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Environment_Transducer,
                           TransducerName))

        .def_readwrite("unknown_children",
                       &XML_Environment_Transducer::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Environment_Transducer,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Environment_Transducer::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Environment_Transducer,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Environment_Transducer::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Environment_Transducer,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Environment_Transducer)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Environment_Transducer)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Environment_Transducer)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}