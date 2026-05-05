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
void init_c_extradetectionsdetectionclassescontainer(
    nanobind::module_& m); // c_extradetectionsdetectionclassescontainer.cpp
void init_c_extradetectionsextradetections(
    nanobind::module_& m); // c_extradetectionsextradetections.cpp
void init_c_extradetectionsextradetectionscontainer(
    nanobind::module_& m); // c_extradetectionsextradetectionscontainer.cpp
void init_c_rawrangeandangletransmitsector(
    nanobind::module_& m);                                // c_rawrangeandangletransmitsector.cpp
void init_c_rawrangeandangletransmitsectorscontainer(
    nanobind::module_& m); // c_rawrangeandangletransmitsectorscontainer.cpp
void init_c_rawrangeandanglebeam(nanobind::module_& m);   // c_rawrangeandanglebeam.cpp
void init_c_rawrangeandanglebeamscontainer(
    nanobind::module_& m); // c_rawrangeandanglebeamscontainer.cpp
void init_c_seabedimagedatabeam(nanobind::module_& m);    // c_seabedimagedatabeam.cpp
void init_c_seabedimagedatabeamscontainer(
    nanobind::module_& m); // c_seabedimagedatabeamscontainer.cpp
void init_c_sampleamplitudesstructure(nanobind::module_& m); // c_sampleamplitudesstructure.cpp
void init_c_watercolumndatagramtransmitsector(
    nanobind::module_& m); // c_watercolumndatagramtransmitsector.cpp
void init_c_watercolumndatagramtransmitsectorscontainer(
    nanobind::module_& m); // c_watercolumndatagramtransmitsectorscontainer.cpp
void init_c_watercolumndatagrambeam(nanobind::module_& m); // c_watercolumndatagrambeam.cpp
void init_c_watercolumndatagrambeamscontainer(
    nanobind::module_& m); // c_watercolumndatagrambeamscontainer.cpp
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
    init_c_extradetectionsdetectionclassescontainer(subm);
    init_c_extradetectionsextradetections(subm);
    init_c_extradetectionsextradetectionscontainer(subm);
    init_c_rawrangeandangletransmitsector(subm);
    init_c_rawrangeandangletransmitsectorscontainer(subm);
    init_c_rawrangeandanglebeam(subm);
    init_c_rawrangeandanglebeamscontainer(subm);
    init_c_seabedimagedatabeam(subm);
    init_c_seabedimagedatabeamscontainer(subm);
    init_c_sampleamplitudesstructure(subm);
    init_c_watercolumndatagramtransmitsector(subm);
    init_c_watercolumndatagramtransmitsectorscontainer(subm);
    init_c_watercolumndatagrambeam(subm);
    init_c_watercolumndatagrambeamscontainer(subm);
    init_c_attitudedatagramattitude(subm);
    init_c_networkattitudevelocitydatagramattitude(subm);
}

}
}
}
}
}
}
