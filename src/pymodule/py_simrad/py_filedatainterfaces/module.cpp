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
void init_c_SimradConfigurationDataInterface_PerFile(
    pybind11::module& m); // c_simradconfigurationdatainterface_perfile.cpp
void init_c_SimradNavigationDataInterface(
    pybind11::module& m); // c_simradnavigationdatainterface.cpp
void init_c_SimradNavigationDataInterface_PerFile(
    pybind11::module& m); // c_simradnavigationdatainterface_perfile.cpp
void init_c_SimradEnvironmentDataInterface(
    pybind11::module& m); // c_simradenvironmentdatainterface.cpp
void init_c_SimradEnvironmentDataInterface_PerFile(
    pybind11::module& m); // c_simradenvironmentdatainterface_perfile.cpp
void init_c_SimradPingDataInterface(pybind11::module& m); // c_simradpingdatainterface.cpp
void init_c_SimradPingDataInterface_PerFile(
    pybind11::module& m); // c_simradpingdatainterface_perfile.cpp
void init_c_SimradAnnotationDataInterface(
    pybind11::module& m); // c_simradannotationdatainterface.cpp
void init_c_SimradAnnotationDataInterface_PerFile(pybind11::module& m);
void init_c_SimradOtherDataInterface(pybind11::module& m); // c_simradotherdatainterface.cpp
void init_c_SimradOtherFileDataInterface_PerFile(
    pybind11::module& m); // c_simradotherfiledatainterface_perfile.cpp

// -- create submodule --
void init_m_SimradFileDataInterfaces(pybind11::module& m)
{
    auto subm =
        m.def_submodule("filedataInterfaces", "Simrad EK60 and EK80 file data interface classes");

    init_c_SimradDatagramInterface(subm);
    init_c_SimradConfigurationDataInterface(subm);
    init_c_SimradConfigurationDataInterface_PerFile(subm);
    init_c_SimradNavigationDataInterface(subm);
    init_c_SimradNavigationDataInterface_PerFile(subm);
    init_c_SimradEnvironmentDataInterface(subm);
    init_c_SimradEnvironmentDataInterface_PerFile(subm);
    init_c_SimradPingDataInterface(subm);
    init_c_SimradPingDataInterface_PerFile(subm);
    init_c_SimradAnnotationDataInterface(subm);
    init_c_SimradAnnotationDataInterface_PerFile(subm);
    init_c_SimradOtherDataInterface(subm);
    init_c_SimradOtherFileDataInterface_PerFile(subm);
}

}
}
}
}
}
