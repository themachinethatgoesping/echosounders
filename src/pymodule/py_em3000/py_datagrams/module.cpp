// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "module.hpp"
#include "py_substructures/module.hpp"

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {

// -- submodule declarations --
void init_c_em3000datagram(pybind11::module& m);        // c_em3000datagram.cpp
void init_c_em3000unknown(pybind11::module& m);         // c_em3000unknown.cpp
void init_c_xyzdatagram(pybind11::module& m);           // c_xyzdatagram.cpp
void init_c_extradetections(pybind11::module& m);       // c_extradetections.cpp
void init_c_rawrangeandangle(pybind11::module& m);      // c_rawrangeandangle.cpp
void init_c_seabedimagedata(pybind11::module& m);       // c_seabedimagedata.cpp
void init_c_watercolumndatagram(pybind11::module& m);   // c_watercolumndatagram.cpp
void init_c_qualityfactordatagram(pybind11::module& m); // c_qualityfactordatagram.cpp
void init_c_attitudedatagram(pybind11::module& m);      // c_attitudedatagram.cpp
void init_c_networkattitudevelocitydatagram(
    pybind11::module& m);                               // c_networkattitudevelocitydatagram.cpp
void init_c_clockdatagram(pybind11::module& m);         // c_clockdatagram.cpp
void init_c_depthorheightdatagram(pybind11::module& m); // c_depthorheightdatagram.cpp
void init_c_headingdatagram(pybind11::module& m);       // c_headingdatagram.cpp
void init_c_positiondatagram(pybind11::module& m);      // c_positiondatagram.cpp
void init_c_singlebeamechosounderdepth(pybind11::module& m); // c_singlebeamechosounderdepth.cpp

// -- create submodule --
void init_m_EM3000Datagrams(pybind11::module& m)
{
    // module description
    auto subm = m.def_submodule("datagrams", "Kongsberg EM3000 (.all/.wcd) EK80 datagram classes");

    // init submodules
    py_substructures::init_m_EM3000DatagramsSubstructures(subm);

    // em3000 classes
    init_c_em3000datagram(subm);
    init_c_em3000unknown(subm);
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
}

}
}
}
}
}
