// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
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
void init_c_SimradConfigurationPerFileDataInterface(
    pybind11::module& m); // c_simradconfigurationperfiledatainterface.cpp
void init_c_SimradNavigationDataInterface(
    pybind11::module& m); // c_simradnavigationdatainterface.cpp
void init_c_SimradNavigationPerFileDataInterface(
    pybind11::module& m); // c_simradnavigationperfiledatainterface.cpp
void init_c_SimradEnvironmentDataInterface(
    pybind11::module& m); // c_simradenvironmentdatainterface.cpp
void init_c_SimradEnvironmentPerFileDataInterface(
    pybind11::module& m); // c_simradenvironmentperfiledatainterface.cpp
void init_c_SimradPingDataInterface(pybind11::module& m); // c_simradpingdatainterface.cpp
void init_c_SimradPingPerFileDataInterface(
    pybind11::module& m); // c_simradpingperfiledatainterface.cpp
void init_c_SimradAnnotationDataInterface(
    pybind11::module& m); // c_simradannotationdatainterface.cpp
void init_c_SimradAnnotationPerFileDataInterface(pybind11::module& m);
void init_c_SimradOtherDataInterface(pybind11::module& m); // c_simradotherdatainterface.cpp
void init_c_SimradOtherPerFileDataInterface(
    pybind11::module& m); // c_simradotherperfiledatainterface.cpp

// -- create submodule --
void init_m_SimradFileDataInterfaces(pybind11::module& m)
{
    auto subm =
        m.def_submodule("filedataInterfaces", "Simrad EK60 and EK80 file data interface classes");

    init_c_SimradDatagramInterface(subm);
    init_c_SimradConfigurationDataInterface(subm);
    init_c_SimradConfigurationPerFileDataInterface(subm);
    init_c_SimradNavigationDataInterface(subm);
    init_c_SimradNavigationPerFileDataInterface(subm);
    init_c_SimradEnvironmentDataInterface(subm);
    init_c_SimradEnvironmentPerFileDataInterface(subm);
    init_c_SimradPingDataInterface(subm);
    init_c_SimradPingPerFileDataInterface(subm);
    init_c_SimradAnnotationDataInterface(subm);
    init_c_SimradAnnotationPerFileDataInterface(subm);
    init_c_SimradOtherDataInterface(subm);
    init_c_SimradOtherPerFileDataInterface(subm);
}

}
}
}
}
}
