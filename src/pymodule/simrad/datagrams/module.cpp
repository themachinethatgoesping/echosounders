// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools/pybind11_helpers/enumhelpers.hpp>
#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/ek60_datagram.hpp"
#include "../../docstrings.hpp"

#include "module.hpp"

namespace py = pybind11;

#include <pybind11/pybind11.h>

// -- submodule declarations --
void init_c_ek60_datagram(pybind11::module& m); // init_c_ek60_datagram.cpp

// -- create submodule --
void init_m_simrad_datagrams(pybind11::module& m)
{

    using namespace themachinethatgoesping::echosounders::simrad::datagrams;

    // module description
    auto subm = m.def_submodule("datagrams", "Simrad EK60 and EK80 datagram classes");
    subm.def("peter", &peter);
    py::enum_<t_EK60_Datagram_Type>(
        subm,
        "t_EK60_Datagram_Type",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, t_EK60_Datagram_Type))
        .value("XML0", t_EK60_Datagram_Type::XML0)
        .value("FIL1", t_EK60_Datagram_Type::FIL1)
        .value("NME0", t_EK60_Datagram_Type::NME0)
        .value("MRU0", t_EK60_Datagram_Type::MRU0)
        .value("RAW3", t_EK60_Datagram_Type::RAW3)
        .export_values()
        // pybind enum helpers
        __PYENUM_FROM_STRING__(t_EK60_Datagram_Type)
        //
        ;

    // simrad classes
    init_c_ek60_datagram(subm);
}
