// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "module.hpp"

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

// -- submodule declarations --
void init_enum_detectiontype(pybind11::module& m); // enum_detectiontype.cpp
void init_c_xyzdatagrambeam(pybind11::module& m);  // c_xyzdatagrambeam.cpp
void init_c_extradetectionsdetectionclasses(
    pybind11::module& m); // c_extradetectionsdetectionclasses.cpp
void init_c_extradetectionsextradetections(
    pybind11::module& m); // c_extradetectionsextradetections.cpp
void init_c_rawrangeandangletransmitsector(
    pybind11::module& m);                                   // c_rawrangeandangletransmitsector.cpp
void init_c_rawrangeandanglebeam(pybind11::module& m);      // c_rawrangeandanglebeam.cpp
void init_c_seabedimagedatabeam(pybind11::module& m);       // c_seabedimagedatabeam.cpp
void init_c_sampleamplitudesstructure(pybind11::module& m); // c_sampleamplitudesstructure.cpp
void init_c_watercolumndatagramtransmitsector(
    pybind11::module& m);                                 // c_watercolumndatagramtransmitsector.cpp
void init_c_watercolumndatagrambeam(pybind11::module& m); // c_watercolumndatagrambeam.cpp
void init_c_attitudedatagramattitude(pybind11::module& m); // c_attitudedatagramattitude.cpp
void init_c_networkattitudevelocitydatagramattitude(
    pybind11::module& m); // c_networkattitudevelocitydatagramattitude.cpp

// -- create submodule --
void init_m_kongsbergalldatagramsSubstructures(pybind11::module& m)
{
    // module description
    auto subm = m.def_submodule("substructures",
                                "Kongsberg KongsbergAll datagram substructures. These are substuctures "
                                "of existing datagrams (repeated cycles, e.g. beams)");

    // init submodules

    // kongsbergall substructures
    init_enum_detectiontype(subm);
    init_c_xyzdatagrambeam(subm);
    init_c_extradetectionsdetectionclasses(subm);
    init_c_extradetectionsextradetections(subm);
    init_c_rawrangeandangletransmitsector(subm);
    init_c_rawrangeandanglebeam(subm);
    init_c_seabedimagedatabeam(subm);
    init_c_sampleamplitudesstructure(subm);
    init_c_watercolumndatagramtransmitsector(subm);
    init_c_watercolumndatagrambeam(subm);
    init_c_attitudedatagramattitude(subm);
    init_c_networkattitudevelocitydatagramattitude(subm);
}

}
}
}
}
}
}
