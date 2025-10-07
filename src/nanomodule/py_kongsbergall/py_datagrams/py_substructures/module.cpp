// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

#include <sstream>
#include <tuple>
#include <vector>



#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

// -- submodule declarations --
void init_enum_detectiontype(nanobind::module_& m); // enum_detectiontype.cpp
void init_c_xyzdatagrambeam(nanobind::module_& m);  // c_xyzdatagrambeam.cpp
void init_c_extradetectionsdetectionclasses(
    nanobind::module_& m); // c_extradetectionsdetectionclasses.cpp
void init_c_extradetectionsextradetections(
    nanobind::module_& m); // c_extradetectionsextradetections.cpp
void init_c_rawrangeandangletransmitsector(
    nanobind::module_& m);                                // c_rawrangeandangletransmitsector.cpp
void init_c_rawrangeandanglebeam(nanobind::module_& m);   // c_rawrangeandanglebeam.cpp
void init_c_seabedimagedatabeam(nanobind::module_& m);    // c_seabedimagedatabeam.cpp
void init_c_sampleamplitudesstructure(nanobind::module_& m); // c_sampleamplitudesstructure.cpp
void init_c_watercolumndatagramtransmitsector(
    nanobind::module_& m); // c_watercolumndatagramtransmitsector.cpp
void init_c_watercolumndatagrambeam(nanobind::module_& m); // c_watercolumndatagrambeam.cpp
void init_c_attitudedatagramattitude(nanobind::module_& m); // c_attitudedatagramattitude.cpp
void init_c_networkattitudevelocitydatagramattitude(
    nanobind::module_& m); // c_networkattitudevelocitydatagramattitude.cpp

// -- create submodule --
void init_m_kongsbergalldatagramsSubstructures(nanobind::module_& m)
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
