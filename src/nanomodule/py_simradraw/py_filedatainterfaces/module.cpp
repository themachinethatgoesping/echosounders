// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatainterfaces {

namespace nb = nanobind;

// -- submodule declarations --
void init_c_SimradRawDatagramInterface(nb::module_& m); // c_simradrawdatagraminterface.cpp

void init_c_simradrawdatagramdatainterface(
    nanobind::module_& m); // c_simradrawdatagramdatainterface.cpp
void init_c_simradrawdatagramdatainterfaceperfile(
    nanobind::module_& m); // c_simradrawdatagramdatainterfaceperfile.cpp
void init_c_simradrawconfigurationdatainterface(
    nanobind::module_& m); // c_simradrawdatagramdatainterface.cpp
void init_c_simradrawconfigurationdatainterfaceperfile(
    nanobind::module_& m); // c_simradrawconfigurationdatainterfaceperfile.cpp
void init_c_simradrawnavigationdatainterface(
    nanobind::module_& m); // c_simradrawnavigationdatainterface.cpp
void init_c_simradrawnavigationdatainterfaceperfile(
    nanobind::module_& m); // c_simradrawnavigationdatainterfaceperfile.cpp
void init_c_simradrawenvironmentdatainterface(
    nanobind::module_& m); // c_simradrawenvironmentdatainterface.cpp
void init_c_simradrawenvironmentdatainterfaceperfile(
    nanobind::module_& m); // c_simradrawenvironmentdatainterfaceperfile.cpp
void init_c_simradrawpingdatainterface(nanobind::module_& m); // c_simradrawpingdatainterface.cpp
void init_c_simradrawpingdatainterfaceperfile(
    nanobind::module_& m); // c_simradrawpingdatainterfaceperfile.cpp
void init_c_simradrawotherfiledatainterface(nanobind::module_& m); // c_simradrawotherfiledatainterface.cpp
void init_c_simradrawotherfiledatainterfaceperfile(
    nanobind::module_& m); // c_init_c_simradrawotherfiledatainterfaceperfile.cpp

// -- create submodule --
void init_m_simradrawfiledatainterfaces(nanobind::module_& m)
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
    init_c_simradrawotherfiledatainterface(subm);
    init_c_simradrawotherfiledatainterfaceperfile(subm);
}

}
}
}
}
}
