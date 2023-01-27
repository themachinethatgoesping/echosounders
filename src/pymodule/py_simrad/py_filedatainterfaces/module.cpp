// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_filedatainterfaces {

namespace py = pybind11;

// -- submodule declarations --
void init_c_SimradDatagramInterface(py::module& m); // c_simraddatagraminterface.cpp

void init_c_simradconfigurationdatainterface(
    pybind11::module& m); // c_simradconfigurationdatainterface.cpp
void init_c_simradconfigurationdatainterfaceperfile(
    pybind11::module& m); // c_simradconfigurationdatainterfaceperfile.cpp
void init_c_simradnavigationdatainterface(
    pybind11::module& m); // c_simradnavigationdatainterface.cpp
void init_c_simradnavigationdatainterfaceperfile(
    pybind11::module& m); // c_simradnavigationdatainterfaceperfile.cpp
void init_c_simradenvironmentdatainterface(
    pybind11::module& m); // c_simradenvironmentdatainterface.cpp
void init_c_simradenvironmentdatainterfaceperfile(
    pybind11::module& m); // c_simradenvironmentdatainterfaceperfile.cpp
void init_c_simradpingdatainterface(pybind11::module& m); // c_simradpingdatainterface.cpp
void init_c_simradpingdatainterfaceperfile(
    pybind11::module& m); // c_simradpingdatainterfaceperfile.cpp
void init_c_simradannotationdatainterface(
    pybind11::module& m); // c_simradannotationdatainterface.cpp
void init_c_simradannotationdatainterfaceperfile(pybind11::module& m);
void init_c_simradotherfiledatainterface(pybind11::module& m); // c_simradotherfiledatainterface.cpp
void init_c_init_c_simradotherfiledatainterfaceperfile(
    pybind11::module& m); // c_init_c_simradotherfiledatainterfaceperfile.cpp

// -- create submodule --
void init_m_simradfiledatainterfaces(pybind11::module& m)
{
    auto subm =
        m.def_submodule("filedataInterfaces", "Simrad EK60 and EK80 file data interface classes");

    init_c_SimradDatagramInterface(subm);
    init_c_simradconfigurationdatainterface(subm);
    init_c_simradconfigurationdatainterfaceperfile(subm);
    init_c_simradnavigationdatainterface(subm);
    init_c_simradnavigationdatainterfaceperfile(subm);
    init_c_simradenvironmentdatainterface(subm);
    init_c_simradenvironmentdatainterfaceperfile(subm);
    init_c_simradpingdatainterface(subm);
    init_c_simradpingdatainterfaceperfile(subm);
    init_c_simradannotationdatainterface(subm);
    init_c_simradannotationdatainterfaceperfile(subm);
    init_c_simradotherfiledatainterface(subm);
    init_c_init_c_simradotherfiledatainterfaceperfile(subm);
}

}
}
}
}
}
