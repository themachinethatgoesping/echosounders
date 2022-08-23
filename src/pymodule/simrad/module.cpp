// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools/pybind11_helpers/enumhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/ek60_types.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

// datagram submodules
#include "datagrams/module.hpp"

namespace py = pybind11;

#include <pybind11/pybind11.h>

// -- submodule declarations --
void init_c_fileraw(pybind11::module& m); // c_fileraw.cpp

// -- create submodule --
void init_m_simrad(pybind11::module& m)
{
    using namespace themachinethatgoesping::echosounders::simrad;
    
    // module description
    auto subm = m.def_submodule(
        "simrad", "Classes related to Simrad EK60 and EK80 data files");

    subm.def("peter", &peter);
    py::enum_<t_EK60_DatagramType>(
        subm,
        "t_EK60_DatagramType",
        DOC(themachinethatgoesping, echosounders, simrad, t_EK60_DatagramType))
        .value("XML0",
               t_EK60_DatagramType::XML0,
               DOC(themachinethatgoesping, echosounders, simrad, t_EK60_DatagramType, XML0))
        .value("FIL1",
               t_EK60_DatagramType::FIL1,
               DOC(themachinethatgoesping, echosounders, simrad, t_EK60_DatagramType, FIL1))
        .value("NME0",
               t_EK60_DatagramType::NME0,
               DOC(themachinethatgoesping, echosounders, simrad, t_EK60_DatagramType, NME0))
        .value("MRU0",
               t_EK60_DatagramType::MRU0,
               DOC(themachinethatgoesping, echosounders, simrad, t_EK60_DatagramType, MRU0))
        .value("RAW3",
               t_EK60_DatagramType::RAW3,
               DOC(themachinethatgoesping, echosounders, simrad, t_EK60_DatagramType, RAW3))
        .export_values()
        // pybind enum helpers
        __PYENUM_FROM_STRING__(t_EK60_DatagramType)
        //
        ;

    py::implicitly_convertible<std::string, t_EK60_DatagramType>();

    subm.def("datagram_type_to_string",
             &datagram_type_to_string,
             DOC(themachinethatgoesping, echosounders, simrad, datagram_type_to_string),
             py::arg("datagram_type"));
    subm.def("ek60_datagram_type_from_string",
             &ek60_datagram_type_from_string,
             DOC(themachinethatgoesping, echosounders, simrad, ek60_datagram_type_from_string),
             py::arg("datagram_type"));

    // datagrams
    init_m_simrad_datagrams(subm);

    // simrad classes
    init_c_fileraw(subm);
}
