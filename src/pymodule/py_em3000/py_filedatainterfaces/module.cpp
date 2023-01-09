// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
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
// void init_c_EM3000ConfigurationDataInterface_PerFile(
//     pybind11::module& m); // c_em3000configurationdatainterface_perfile.cpp
// void init_c_EM3000NavigationDataInterface(
//     pybind11::module& m); // c_em3000navigationdatainterface.cpp
// void init_c_EM3000NavigationDataInterface_PerFile(
//     pybind11::module& m); // c_em3000navigationdatainterface_perfile.cpp
// void init_c_EM3000EnvironmentDataInterface(
//     pybind11::module& m); // c_em3000environmentdatainterface.cpp
// void init_c_EM3000EnvironmentDataInterface_PerFile(
//     pybind11::module& m); // c_em3000environmentdatainterface_perfile.cpp
// void init_c_EM3000PingDataInterface(pybind11::module& m); // c_em3000pingdatainterface.cpp
// void init_c_EM3000PingDataInterface_PerFile(
//     pybind11::module& m); // c_em3000pingdatainterface_perfile.cpp
// void init_c_EM3000AnnotationDataInterface(
//     pybind11::module& m); // c_em3000annotationdatainterface.cpp
// void init_c_EM3000AnnotationDataInterface_PerFile(pybind11::module& m);
// void init_c_EM3000OtherDataInterface(pybind11::module& m); // c_em3000otherdatainterface.cpp
// void init_c_EM3000OtherFileDataInterface_PerFile(
//     pybind11::module& m); // c_em3000otherfiledatainterface_perfile.cpp

// -- create submodule --
void init_m_EM3000FileDataInterfaces(pybind11::module& m)
{
    auto subm = m.def_submodule("filedataInterfaces",
                                "EM3000 (kongsberg .all/.wcd) file data interface classes");

    init_c_EM3000DatagramInterface(subm);
    // init_c_EM3000ConfigurationDataInterface(subm);
    // init_c_EM3000ConfigurationDataInterface_PerFile(subm);
    // init_c_EM3000NavigationDataInterface(subm);
    // init_c_EM3000NavigationDataInterface_PerFile(subm);
    // init_c_EM3000EnvironmentDataInterface(subm);
    // init_c_EM3000EnvironmentDataInterface_PerFile(subm);
    // init_c_EM3000PingDataInterface(subm);
    // init_c_EM3000PingDataInterface_PerFile(subm);
    // init_c_EM3000AnnotationDataInterface(subm);
    // init_c_EM3000AnnotationDataInterface_PerFile(subm);
    // init_c_EM3000OtherDataInterface(subm);
    // init_c_EM3000OtherFileDataInterface_PerFile(subm);
}

}
}
}
}
}
