// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatainterfaces {

namespace nb = nanobind;

// -- submodule declarations --
void init_c_kmalldatagraminterface(nanobind::module_& m); // c_kmalldatagraminterface.cpp
void init_c_kmalldatagramdatainterfaceperfile(
    nanobind::module_& m); // c_kmalldatagramdatainterfaceperfile.cpp
void init_c_kmalldatagramdatainterface(nanobind::module_& m); // c_kmalldatagramdatainterface.cpp
void init_c_kmallotherfiledatainterfaceperfile(
    nanobind::module_& m); // c_kmallotherfiledatainterfaceperfile.cpp
void init_c_kmallotherfiledatainterface(nanobind::module_& m); // c_kmallotherfiledatainterface.cpp
void init_c_kmallconfigurationdatainterfaceperfile(
    nanobind::module_& m); // c_kmallconfigurationdatainterfaceperfile.cpp
void init_c_kmallconfigurationdatainterface(
    nanobind::module_& m); // c_kmallconfigurationdatainterface.cpp
void init_c_kmallenvironmentdatainterfaceperfile(
    nanobind::module_& m); // c_kmallenvironmentdatainterfaceperfile.cpp
void init_c_kmallenvironmentdatainterface(
    nanobind::module_& m); // c_kmallenvironmentdatainterface.cpp
void init_c_kmallnavigationdatainterfaceperfile(
    nanobind::module_& m); // c_kmallnavigationdatainterfaceperfile.cpp
void init_c_kmallnavigationdatainterface(
    nanobind::module_& m); // c_kmallnavigationdatainterface.cpp
void init_c_kmallpingdatainterfaceperfile(
    nanobind::module_& m);                                // c_kmallpingdatainterfaceperfile.cpp
void init_c_kmallpingdatainterface(nanobind::module_& m); // c_kmallpingdatainterface.cpp

// -- create submodule --
void init_m_kmallfiledatainterfaces(nanobind::module_& m)
{
    auto subm = m.def_submodule("filedatainterfaces",
                                "KMALL (kongsberg .kmall/.kmwcd) file data interface classes");

    init_c_kmalldatagraminterface(subm);
    init_c_kmalldatagramdatainterfaceperfile(subm);
    init_c_kmalldatagramdatainterface(subm);
    init_c_kmallotherfiledatainterfaceperfile(subm);
    init_c_kmallotherfiledatainterface(subm);
    init_c_kmallconfigurationdatainterfaceperfile(subm);
    init_c_kmallconfigurationdatainterface(subm);
    init_c_kmallenvironmentdatainterfaceperfile(subm);
    init_c_kmallenvironmentdatainterface(subm);
    init_c_kmallnavigationdatainterfaceperfile(subm);
    init_c_kmallnavigationdatainterface(subm);
    init_c_kmallpingdatainterfaceperfile(subm);
    init_c_kmallpingdatainterface(subm);
}

}
}
}
}
}
