// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include "../../docstrings.hpp"
#include <themachinethatgoesping/tools/pybind11_helpers/enumhelpers.hpp>

#include "module.hpp"
#include "xml_datagrams/module.hpp"

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

// -- submodule declarations --
void init_c_ek60_datagram(pybind11::module& m); // c_ek60_datagram.cpp
void init_c_ek60_unknown(pybind11::module& m);  // c_ek60_unknown.cpp
void init_c_ek80_MRU0(pybind11::module& m);  // c_EK80_MRU0.cpp
void init_c_ek60_NME0(pybind11::module& m);  // c_ek60_nme0.cpp
void init_c_ek80_XML0(pybind11::module& m);  // c_ek80_xml0.cpp
void init_c_ek80_TAG0(pybind11::module& m);  // c_ek80_TAG0.cpp

// -- create submodule --
void init_m_simrad_datagrams(pybind11::module& m)
{
    // module description
    auto subm = m.def_submodule("datagrams", "Simrad EK60 and EK80 datagram classes");

    py_datagrams_xml::init_m_simrad_datagrams_xml(subm);

    // simrad classes
    init_c_ek60_datagram(subm);
    init_c_ek60_unknown(subm);
    init_c_ek80_MRU0(subm);
    init_c_ek60_NME0(subm);
    init_c_ek80_XML0(subm);
    init_c_ek80_TAG0(subm);
}

}
}
}
}
}
