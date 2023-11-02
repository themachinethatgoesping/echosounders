// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatainterfaces {

namespace py = pybind11;

// -- submodule declarations --
void init_c_EM3000DatagramInterface(py::module& m); // c_em3000datagraminterface.cpp

void init_c_em3000datagramdatainterface(pybind11::module& m); // c_em3000datagramdatainterface.cpp
void init_c_em3000datagramdatainterfaceperfile(
    pybind11::module& m); // c_em3000datagramdatainterfaceperfile.cpp
void init_c_em3000configurationdatainterface(
    pybind11::module& m); // c_em3000configurationdatainterface.cpp
void init_c_em3000configurationdatainterfaceperfile(
    pybind11::module& m); // c_em3000configurationdatainterfaceperfile.cpp
void init_c_em3000navigationdatainterface(
    pybind11::module& m); // c_em3000navigationdatainterface.cpp
void init_c_em3000navigationdatainterfaceperfile(
    pybind11::module& m); // c_em3000navigationdatainterfaceperfile.cpp
void init_c_em3000environmentdatainterface(
    pybind11::module& m); // c_em3000environmentdatainterface.cpp
void init_c_em3000environmentdatainterfaceperfile(
    pybind11::module& m); // c_em3000environmentdatainterfaceperfile.cpp
void init_c_em3000annotationdatainterface(
    pybind11::module& m); // c_em3000annotationdatainterface.cpp
void init_c_em3000annotationdatainterfaceperfile(pybind11::module& m);
void init_c_em3000otherfiledatainterface(pybind11::module& m); // c_em3000otherfiledatainterface.cpp
void init_c_em3000otherfiledatainterfaceperfile(
    pybind11::module& m); // c_em3000otherfiledatainterfaceperfile.cpp
void init_c_em3000pingdatainterface(pybind11::module& m); // c_em3000pingdatainterface.cpp
void init_c_em3000pingdatainterfaceperfile(
    pybind11::module& m); // c_em3000pingdatainterfaceperfile.cpp

// -- create submodule --
void init_m_em3000filedatainterfaces(pybind11::module& m)
{
    auto subm = m.def_submodule("filedatainterfaces",
                                "EM3000 (kongsberg .all/.wcd) file data interface classes");

    init_c_EM3000DatagramInterface(subm);
    init_c_em3000datagramdatainterface(subm);
    init_c_em3000datagramdatainterfaceperfile(subm);
    init_c_em3000configurationdatainterface(subm);
    init_c_em3000configurationdatainterfaceperfile(subm);
    init_c_em3000navigationdatainterface(subm);
    init_c_em3000navigationdatainterfaceperfile(subm);
    init_c_em3000environmentdatainterface(subm);
    init_c_em3000environmentdatainterfaceperfile(subm);
    init_c_em3000annotationdatainterface(subm);
    init_c_em3000annotationdatainterfaceperfile(subm);
    init_c_em3000otherfiledatainterface(subm);
    init_c_em3000otherfiledatainterfaceperfile(subm);

    init_c_em3000pingdatainterface(subm);
    init_c_em3000pingdatainterfaceperfile(subm);
}

}
}
}
}
}
