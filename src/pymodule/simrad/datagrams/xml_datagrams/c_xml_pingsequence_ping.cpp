// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_pingsequence_ping.hpp"
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
using datagrams::xml_datagrams::XML_PingSequence_Ping;

void init_c_xml_pingsequence_ping(pybind11::module& m)
{
    py::class_<XML_PingSequence_Ping>(m,
                                      "XML_PingSequence_Ping",
                                      DOC(themachinethatgoesping,
                                          echosounders,
                                          simrad,
                                          datagrams,
                                          xml_datagrams,
                                          XML_PingSequence_Ping))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_PingSequence_Ping,
                 XML_PingSequence_Ping))

        // ----- attributes -----
        .def_readwrite("ChannelID",
                       &XML_PingSequence_Ping::ChannelID,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_PingSequence_Ping,
                           ChannelID))
        
        .def_readwrite("unknown_children",
                       &XML_PingSequence_Ping::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_PingSequence_Ping,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_PingSequence_Ping::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_PingSequence_Ping,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_PingSequence_Ping::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_PingSequence_Ping,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_PingSequence_Ping)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_PingSequence_Ping)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_PingSequence_Ping)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}