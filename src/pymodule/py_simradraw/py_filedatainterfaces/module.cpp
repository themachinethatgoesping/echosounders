// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatainterfaces {

namespace py = pybind11;

// -- submodule declarations --
void init_c_SimradRawDatagramInterface(py::module& m); // c_simradrawdatagraminterface.cpp

void init_c_simradrawdatagramdatainterface(
    pybind11::module& m); // c_simradrawdatagramdatainterface.cpp
void init_c_simradrawdatagramdatainterfaceperfile(
    pybind11::module& m); // c_simradrawdatagramdatainterfaceperfile.cpp
void init_c_simradrawconfigurationdatainterface(
    pybind11::module& m); // c_simradrawdatagramdatainterface.cpp
void init_c_simradrawconfigurationdatainterfaceperfile(
    pybind11::module& m); // c_simradrawconfigurationdatainterfaceperfile.cpp
void init_c_simradrawnavigationdatainterface(
    pybind11::module& m); // c_simradrawnavigationdatainterface.cpp
void init_c_simradrawnavigationdatainterfaceperfile(
    pybind11::module& m); // c_simradrawnavigationdatainterfaceperfile.cpp
void init_c_simradrawenvironmentdatainterface(
    pybind11::module& m); // c_simradrawenvironmentdatainterface.cpp
void init_c_simradrawenvironmentdatainterfaceperfile(
    pybind11::module& m); // c_simradrawenvironmentdatainterfaceperfile.cpp
void init_c_simradrawpingdatainterface(pybind11::module& m); // c_simradrawpingdatainterface.cpp
void init_c_simradrawpingdatainterfaceperfile(
    pybind11::module& m); // c_simradrawpingdatainterfaceperfile.cpp
void init_c_simradrawannotationdatainterface(
    pybind11::module& m); // c_simradrawannotationdatainterface.cpp
void init_c_simradrawannotationdatainterfaceperfile(pybind11::module& m);
void init_c_simradrawotherfiledatainterface(pybind11::module& m); // c_simradrawotherfiledatainterface.cpp
void init_c_init_c_simradrawotherfiledatainterfaceperfile(
    pybind11::module& m); // c_init_c_simradrawotherfiledatainterfaceperfile.cpp

// -- create submodule --
void init_m_simradrawfiledatainterfaces(pybind11::module& m)
{
    auto subm =
        m.def_submodule("filedatainterfaces", "SimradRaw EK60 and EK80 file data interface classes");

    init_c_SimradRawDatagramInterface(subm);
    init_c_simradrawdatagramdatainterface(subm);
    init_c_simradrawdatagramdatainterfaceperfile(subm);
    init_c_simradrawconfigurationdatainterface(subm);
    init_c_simradrawconfigurationdatainterfaceperfile(subm);
    init_c_simradrawnavigationdatainterface(subm);
    init_c_simradrawnavigationdatainterfaceperfile(subm);
    init_c_simradrawenvironmentdatainterface(subm);
    init_c_simradrawenvironmentdatainterfaceperfile(subm);
    init_c_simradrawpingdatainterface(subm);
    init_c_simradrawpingdatainterfaceperfile(subm);
    init_c_simradrawannotationdatainterface(subm);
    init_c_simradrawannotationdatainterfaceperfile(subm);
    init_c_simradrawotherfiledatainterface(subm);
    init_c_init_c_simradrawotherfiledatainterfaceperfile(subm);
}

}
}
}
}
}
