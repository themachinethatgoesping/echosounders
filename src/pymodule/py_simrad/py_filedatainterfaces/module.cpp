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

void init_c_SimradConfigurationDataInterface(
    pybind11::module& m); // c_simradconfigurationdatainterface.cpp
void init_c_SimradConfigurationDataInterfacePerFile(
    pybind11::module& m); // c_simradconfigurationdatainterfaceperfile.cpp
void init_c_SimradNavigationDataInterface(
    pybind11::module& m); // c_simradnavigationdatainterface.cpp
void init_c_SimradNavigationDataInterfacePerFile(
    pybind11::module& m); // c_simradnavigationdatainterfaceperfile.cpp
void init_c_SimradEnvironmentDataInterface(
    pybind11::module& m); // c_simradenvironmentdatainterface.cpp
void init_c_SimradEnvironmentDataInterfacePerFile(
    pybind11::module& m); // c_simradenvironmentdatainterfaceperfile.cpp
void init_c_SimradPingDataInterface(pybind11::module& m); // c_simradpingdatainterface.cpp
void init_c_SimradPingDataInterfacePerFile(
    pybind11::module& m); // c_simradpingdatainterfaceperfile.cpp
void init_c_simradannotationdatainterface(
    pybind11::module& m); // c_simradannotationdatainterface.cpp
void init_c_simradannotationdatainterfaceperfile(pybind11::module& m);
void init_c_simradotherfiledatainterface(pybind11::module& m); // c_simradotherfiledatainterface.cpp
void init_c_init_c_simradotherfiledatainterfaceperfile(
    pybind11::module& m); // c_init_c_simradotherfiledatainterfaceperfile.cpp

// -- create submodule --
void init_m_SimradFileDataInterfaces(pybind11::module& m)
{
    auto subm =
        m.def_submodule("filedataInterfaces", "Simrad EK60 and EK80 file data interface classes");

    init_c_SimradDatagramInterface(subm);
    init_c_SimradConfigurationDataInterface(subm);
    init_c_SimradConfigurationDataInterfacePerFile(subm);
    init_c_SimradNavigationDataInterface(subm);
    init_c_SimradNavigationDataInterfacePerFile(subm);
    init_c_SimradEnvironmentDataInterface(subm);
    init_c_SimradEnvironmentDataInterfacePerFile(subm);
    init_c_SimradPingDataInterface(subm);
    init_c_SimradPingDataInterfacePerFile(subm);
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
