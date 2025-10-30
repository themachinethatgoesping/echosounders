// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <sstream>
#include <tuple>
#include <vector>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

// -- submodule declarations --
void init_c_kmalldatagram(nanobind::module_& m);        // c_kmalldatagram.cpp
void init_c_kmallunknown(nanobind::module_& m);         // c_kmallunknown.cpp

// -- create submodule --
void init_m_kmalldatagrams(nanobind::module_& m)
{
    // module description
    auto subm = m.def_submodule("datagrams", "Kongsberg KMALL (.kmall/.kmwcd) datagram classes");

    // init submodules

    // kmall classes
    init_c_kmalldatagram(subm);
    init_c_kmallunknown(subm);
}

}
}
}
}
}
