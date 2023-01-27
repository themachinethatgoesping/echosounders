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

// void init_c_EM3000ConfigurationDataInterface(
//     pybind11::module& m); // c_em3000configurationdatainterface.cpp
// void init_c_EM3000ConfigurationDataInterfacePerFile(
//     pybind11::module& m); // c_em3000configurationdatainterfaceperfile.cpp
// void init_c_EM3000NavigationDataInterface(
//     pybind11::module& m); // c_em3000navigationdatainterface.cpp
// void init_c_EM3000NavigationDataInterfacePerFile(
//     pybind11::module& m); // c_em3000navigationdatainterfaceperfile.cpp
// void init_c_EM3000EnvironmentDataInterface(
//     pybind11::module& m); // c_em3000environmentdatainterface.cpp
// void init_c_EM3000EnvironmentDataInterfacePerFile(
//     pybind11::module& m); // c_em3000environmentdatainterfaceperfile.cpp
// void init_c_EM3000PingDataInterface(pybind11::module& m); // c_em3000pingdatainterface.cpp
// void init_c_EM3000PingDataInterfacePerFile(
//     pybind11::module& m); // c_em3000pingdatainterfaceperfile.cpp
// void init_c_EM3000AnnotationDataInterface(
//     pybind11::module& m); // c_em3000annotationdatainterface.cpp
// void init_c_EM3000AnnotationDataInterfacePerFile(pybind11::module& m);
void init_c_em3000otherfiledatainterface(pybind11::module& m); // c_em3000otherdatainterface.cpp
void init_c_em3000otherFileDataInterfacePerFile(
    pybind11::module& m); // c_em3000otherfiledatainterfaceperfile.cpp

// -- create submodule --
void init_m_EM3000FileDataInterfaces(pybind11::module& m)
{
    auto subm = m.def_submodule("filedatainterfaces",
                                "EM3000 (kongsberg .all/.wcd) file data interface classes");

    init_c_EM3000DatagramInterface(subm);
    // init_c_EM3000ConfigurationDataInterface(subm);
    // init_c_EM3000ConfigurationDataInterfacePerFile(subm);
    // init_c_EM3000NavigationDataInterface(subm);
    // init_c_EM3000NavigationDataInterfacePerFile(subm);
    // init_c_EM3000EnvironmentDataInterface(subm);
    // init_c_EM3000EnvironmentDataInterfacePerFile(subm);
    // init_c_EM3000PingDataInterface(subm);
    // init_c_EM3000PingDataInterfacePerFile(subm);
    // init_c_EM3000AnnotationDataInterface(subm);
    // init_c_EM3000AnnotationDataInterfacePerFile(subm);
    init_c_em3000otherfiledatainterface(subm);
    init_c_em3000otherFileDataInterfacePerFile(subm);
}

}
}
}
}
}
