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
void init_c_mrzpinginfo(nanobind::module_& m);   // substructs/c_mrzpinginfo.cpp
void init_c_mrzrxinfo(nanobind::module_& m);     // substructs/c_mrzrxinfo.cpp
void init_c_mrzsectorinfo(nanobind::module_& m); // substructs/c_mrzsectorinfo.cpp

void init_c_kmalldatagram(nanobind::module_& m); // c_kmalldatagram.cpp
void init_c_kmallunknown(nanobind::module_& m);  // c_kmallunknown.cpp

void init_c_iinstallationparam(nanobind::module_& m); // c_iinstallationparam.cpp
void init_c_iopruntime(nanobind::module_& m);         // c_iopruntime.cpp

void init_c_kmallsensordatagram(nanobind::module_& m);    // c_kmallsensordatagram.cpp
void init_c_kmallmultibeamdatagram(nanobind::module_& m); // c_kmallmultibeamdatagram.cpp

void init_c_sposition(nanobind::module_& m);      // c_sposition.cpp
void init_c_spositionerror(nanobind::module_& m); // c_spositionerror.cpp
void init_c_sclock(nanobind::module_& m);         // c_sclock.cpp

void init_c_ssoundvelocityprofile(nanobind::module_& m);    // c_soundvelocityprofile.cpp
void init_c_ssoundvelocitytransducer(nanobind::module_& m); // c_soundvelocitytransducer.cpp
void init_c_skmbinary(nanobind::module_& m);                // c_skmbinary.cpp

void init_c_cposition(nanobind::module_& m); // c_cposition.cpp
void init_c_cheave(nanobind::module_& m);    // c_cheave.cpp

void init_c_mrangeanddepth(nanobind::module_& m); // c_mrangeanddepth.cpp

// -- create submodule --
void init_m_kmalldatagrams(nanobind::module_& m)
{
    // module description
    auto subm = m.def_submodule("datagrams", "Kongsberg KMALL (.kmall/.kmwcd) datagram classes");

    // init submodules

    // substructs
    init_c_mrzpinginfo(subm);
    init_c_mrzrxinfo(subm);
    init_c_mrzsectorinfo(subm);

    // kmall classes
    init_c_kmalldatagram(subm);
    init_c_kmallunknown(subm);

    init_c_iinstallationparam(subm);
    init_c_iopruntime(subm);

    init_c_kmallsensordatagram(subm);
    init_c_kmallmultibeamdatagram(subm);

    init_c_sposition(subm);
    init_c_spositionerror(subm);
    init_c_sclock(subm);

    init_c_ssoundvelocityprofile(subm);
    init_c_ssoundvelocitytransducer(subm);
    init_c_skmbinary(subm);

    init_c_cposition(subm);
    init_c_cheave(subm);

    init_c_mrangeanddepth(subm);
}

}
}
}
}
}
