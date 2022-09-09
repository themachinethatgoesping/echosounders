// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_pingsequence.hpp"
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
using datagrams::xml_datagrams::XML_PingSequence;

void init_c_xml_pingsequence(pybind11::module& m)
{
    py::class_<XML_PingSequence>(m,
                                      "XML_PingSequence",
                                      DOC(themachinethatgoesping,
                                          echosounders,
                                          simrad,
                                          datagrams,
                                          xml_datagrams,
                                          XML_PingSequence))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_PingSequence,
                 XML_PingSequence))

        // ----- attributes -----
        .def_readwrite("ChannelID",
                       &XML_PingSequence::ChannelID,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_PingSequence,
                           ChannelID))
        
        .def_readwrite("unknown_children",
                       &XML_PingSequence::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_PingSequence,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_PingSequence::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_PingSequence,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_PingSequence::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
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