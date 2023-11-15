// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_pingsequence.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_PingSequence;

void init_c_xml_pingsequence(pybind11::module& m)
{
    py::class_<XML_PingSequence>(m,
                                 "XML_PingSequence",
                                 DOC(themachinethatgoesping,
                                     echosounders,
                                     simradraw,
                                     datagrams,
                                     xml_datagrams,
                                     XML_PingSequence))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_PingSequence,
                 XML_PingSequence))

        // ----- children -----
        .def_readwrite("Pings",
                       &XML_PingSequence::Pings,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_PingSequence,
                           Pings))

        .def_readwrite("unknown_children",
                       &XML_PingSequence::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_PingSequence,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_PingSequence::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_PingSequence,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_PingSequence::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_PingSequence,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_PingSequence)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_PingSequence)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_PingSequence)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}