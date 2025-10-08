// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/stl/string.h>

#include <sstream>
#include <tuple>
#include <vector>



#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams/raw3datatypes/raw3datatypes.hpp"

#include "module.hpp"
#include "py_raw3datatypes/module.hpp"
#include "py_xml_datagrams/module.hpp"

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {

// -- submodule declarations --
void init_c_SimradRawDatagram(nanobind::module_& m); // c_SimradRawDatagram.cpp
void init_c_simradrawunknown(nanobind::module_& m);  // c_simradrawunknown.cpp
void init_c_NME0(nanobind::module_& m);           // c_NME0.cpp
void init_c_MRU0(nanobind::module_& m);           // c_MRU0.cpp
void init_c_XML0(nanobind::module_& m);           // c_XML0.cpp
void init_c_TAG0(nanobind::module_& m);           // c_TAG0.cpp
void init_c_FIL1(nanobind::module_& m);           // c_FIL1.cpp
void init_c_RAW3(nanobind::module_& m);           // c_RAW3.cpp

// -- create submodule --
void init_m_simradrawdatagrams(nanobind::module_& m)
{
    // module description
    auto subm = m.def_submodule("datagrams", "SimradRaw EK60 and EK80 datagram classes");

    // init submodules
    py_datagrams_xml::init_m_datagrams_xml(subm);
    py_raw3_datatypes::init_m_raw3datatypes(subm);

    // simradraw classes
    init_c_SimradRawDatagram(subm);
    init_c_simradrawunknown(subm);
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
