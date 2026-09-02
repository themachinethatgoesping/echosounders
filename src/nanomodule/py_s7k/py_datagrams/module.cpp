// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

// -- submodule declarations --
void init_c_s7kdatagram(nanobind::module_& m); // c_s7kdatagram.cpp
void init_c_s7kunknown(nanobind::module_& m);  // c_s7kunknown.cpp

void init_c_referencepoint(nanobind::module_& m);       // c_referencepoint.cpp
void init_c_position(nanobind::module_& m);             // c_position.cpp
void init_c_rollpitchheave(nanobind::module_& m);       // c_rollpitchheave.cpp
void init_c_heading(nanobind::module_& m);              // c_heading.cpp
void init_c_navigation(nanobind::module_& m);           // c_navigation.cpp
void init_c_sonarsettings(nanobind::module_& m);        // c_sonarsettings.cpp
void init_c_matchfilter(nanobind::module_& m);          // c_matchfilter.cpp
void init_c_soundvelocity(nanobind::module_& m);        // c_soundvelocity.cpp
void init_c_absorptionloss(nanobind::module_& m);       // c_absorptionloss.cpp
void init_c_spreadingloss(nanobind::module_& m);        // c_spreadingloss.cpp

void init_c_rawdetection(nanobind::module_& m);          // c_rawdetection.cpp
void init_c_snippet(nanobind::module_& m);               // c_snippet.cpp
void init_c_compressedwatercolumn(nanobind::module_& m); // c_compressedwatercolumn.cpp
void init_c_beamgeometry(nanobind::module_& m);          // c_beamgeometry.cpp
void init_c_attitude(nanobind::module_& m);              // c_attitude.cpp
void init_c_fileheader(nanobind::module_& m);            // c_fileheader.cpp

// -- create submodule --
void init_m_s7kdatagrams(nanobind::module_& m)
{
    // module description
    auto subm =
        m.def_submodule("datagrams", "Teledyne RESON .s7k (7k) datagram (record) classes");

    // s7k classes
    init_c_s7kdatagram(subm);
    init_c_s7kunknown(subm);

    init_c_referencepoint(subm);
    init_c_position(subm);
    init_c_rollpitchheave(subm);
    init_c_heading(subm);
    init_c_navigation(subm);
    init_c_sonarsettings(subm);
    init_c_matchfilter(subm);
    init_c_soundvelocity(subm);
    init_c_absorptionloss(subm);
    init_c_spreadingloss(subm);

    init_c_rawdetection(subm);
    init_c_snippet(subm);
    init_c_compressedwatercolumn(subm);
    init_c_beamgeometry(subm);
    init_c_attitude(subm);
    init_c_fileheader(subm);
}

}
}
}
}
}
