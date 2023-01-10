// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include "../../docstrings.hpp"
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/RAW3_datatypes/RAW3_datatypes.hpp"

#include "module.hpp"
#include "py_RAW3_datatypes/module.hpp"
#include "py_xml_datagrams/module.hpp"

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

// -- submodule declarations --
void init_c_SimradDatagram(pybind11::module& m); // c_SimradDatagram.cpp
void init_c_simradunknown(pybind11::module& m);  // c_simradunknown.cpp
void init_c_NME0(pybind11::module& m);           // c_NME0.cpp
void init_c_MRU0(pybind11::module& m);           // c_MRU0.cpp
void init_c_XML0(pybind11::module& m);           // c_XML0.cpp
void init_c_TAG0(pybind11::module& m);           // c_TAG0.cpp
void init_c_FIL1(pybind11::module& m);           // c_FIL1.cpp
void init_c_RAW3(pybind11::module& m);           // c_RAW3.cpp

// -- create submodule --
void init_m_SimradDatagrams(pybind11::module& m)
{
    // module description
    auto subm = m.def_submodule("datagrams", "Simrad EK60 and EK80 datagram classes");

    // init submodules
    py_datagrams_xml::init_m_datagrams_xml(subm);
    py_raw3_datatypes::init_m_RAW3_datatypes(subm);

    // simrad classes
    init_c_SimradDatagram(subm);
    init_c_simradunknown(subm);
    init_c_NME0(subm);
    init_c_MRU0(subm);
    init_c_XML0(subm);
    init_c_TAG0(subm);
    init_c_FIL1(subm);
    init_c_RAW3(subm);
}

}
}
}
}
}
