// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <sstream>
#include <tuple>
#include <vector>



#include "module.hpp"
#include "py_substructures/module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

// -- submodule declarations --
void init_c_kongsbergalldatagram(nanobind::module_& m);        // c_kongsbergalldatagram.cpp
void init_c_kongsbergallunknown(nanobind::module_& m);         // c_kongsbergallunknown.cpp
void init_c_xyzdatagram(nanobind::module_& m);           // c_xyzdatagram.cpp
void init_c_extradetections(nanobind::module_& m);       // c_extradetections.cpp
void init_c_rawrangeandangle(nanobind::module_& m);      // c_rawrangeandangle.cpp
void init_c_seabedimagedata(nanobind::module_& m);       // c_seabedimagedata.cpp
void init_c_watercolumndatagram(nanobind::module_& m);   // c_watercolumndatagram.cpp
void init_c_qualityfactordatagram(nanobind::module_& m); // c_qualityfactordatagram.cpp
void init_c_attitudedatagram(nanobind::module_& m);      // c_attitudedatagram.cpp
void init_c_networkattitudevelocitydatagram(
    nanobind::module_& m);                               // c_networkattitudevelocitydatagram.cpp
void init_c_clockdatagram(nanobind::module_& m);         // c_clockdatagram.cpp
void init_c_depthorheightdatagram(nanobind::module_& m); // c_depthorheightdatagram.cpp
void init_c_headingdatagram(nanobind::module_& m);       // c_headingdatagram.cpp
void init_c_positiondatagram(nanobind::module_& m);      // c_positiondatagram.cpp
void init_c_singlebeamechosounderdepth(nanobind::module_& m); // c_singlebeamechosounderdepth.cpp
void init_c_surfacesoundspeeddatagram(nanobind::module_& m);  // c_surfacesoundspeeddatagram.cpp
void init_c_soundspeedprofiledatagram(nanobind::module_& m);  // c_soundspeedprofiledatagram.cpp
void init_c_installationparameters(nanobind::module_& m);     // c_installationparameters.cpp
void init_c_runtimeparameters(nanobind::module_& m);          // c_runtimeparameters.cpp
void init_c_extraparameters(nanobind::module_& m);            // c_extraparameters.cpp
void init_c_pustatusoutput(nanobind::module_& m);             // c_pustatusoutput.cpp
void init_c_puidoutput(nanobind::module_& m);                 // c_puidoutput.cpp

// -- create submodule --
void init_m_kongsbergalldatagrams(nanobind::module_& m)
{
    // module description
    auto subm = m.def_submodule("datagrams", "Kongsberg KongsbergAll (.all/.wcd) EK80 datagram classes");

    // init submodules
    py_substructures::init_m_kongsbergalldatagramsSubstructures(subm);

    // kongsbergall classes
    init_c_kongsbergalldatagram(subm);
    init_c_kongsbergallunknown(subm);
    init_c_xyzdatagram(subm);
    init_c_extradetections(subm);
    init_c_rawrangeandangle(subm);
    init_c_seabedimagedata(subm);
    init_c_watercolumndatagram(subm);
    init_c_qualityfactordatagram(subm);
    init_c_attitudedatagram(subm);
    init_c_networkattitudevelocitydatagram(subm);
    init_c_clockdatagram(subm);
    init_c_depthorheightdatagram(subm);
    init_c_headingdatagram(subm);
    init_c_positiondatagram(subm);
    init_c_singlebeamechosounderdepth(subm);
    init_c_surfacesoundspeeddatagram(subm);
    init_c_soundspeedprofiledatagram(subm);
    init_c_installationparameters(subm);
    init_c_runtimeparameters(subm);
    init_c_extraparameters(subm);
    init_c_pustatusoutput(subm);
    init_c_puidoutput(subm);
}

}
}
}
}
}
