// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatainterfaces {

namespace nb = nanobind;

// -- submodule declarations --
void init_c_KongsbergAllDatagramInterface(nanobind::module_& m); // c_kongsbergalldatagraminterface.cpp

void init_c_kongsbergalldatagramdatainterface(nanobind::module_& m); // c_kongsbergalldatagramdatainterface.cpp
void init_c_kongsbergalldatagramdatainterfaceperfile(
    nanobind::module_& m); // c_kongsbergalldatagramdatainterfaceperfile.cpp
void init_c_kongsbergallconfigurationdatainterface(
    nanobind::module_& m); // c_kongsbergallconfigurationdatainterface.cpp
void init_c_kongsbergallconfigurationdatainterfaceperfile(
    nanobind::module_& m); // c_kongsbergallconfigurationdatainterfaceperfile.cpp
void init_c_kongsbergallnavigationdatainterface(
    nanobind::module_& m); // c_kongsbergallnavigationdatainterface.cpp
void init_c_kongsbergallnavigationdatainterfaceperfile(
    nanobind::module_& m); // c_kongsbergallnavigationdatainterfaceperfile.cpp
void init_c_kongsbergallenvironmentdatainterface(
    nanobind::module_& m); // c_kongsbergallenvironmentdatainterface.cpp
void init_c_kongsbergallenvironmentdatainterfaceperfile(
    nanobind::module_& m); // c_kongsbergallenvironmentdatainterfaceperfile.cpp
void init_c_kongsbergallotherfiledatainterface(nanobind::module_& m); // c_kongsbergallotherfiledatainterface.cpp
void init_c_kongsbergallotherfiledatainterfaceperfile(
    nanobind::module_& m); // c_kongsbergallotherfiledatainterfaceperfile.cpp
void init_c_kongsbergallpingdatainterface(nanobind::module_& m); // c_kongsbergallpingdatainterface.cpp
void init_c_kongsbergallpingdatainterfaceperfile(
    nanobind::module_& m); // c_kongsbergallpingdatainterfaceperfile.cpp

// -- create submodule --
void init_m_kongsbergallfiledatainterfaces(nanobind::module_& m)
{
    auto subm = m.def_submodule("filedatainterfaces",
                                "KongsbergAll (kongsberg .all/.wcd) file data interface classes");

    init_c_KongsbergAllDatagramInterface(subm);
    init_c_kongsbergalldatagramdatainterface(subm);
    init_c_kongsbergalldatagramdatainterfaceperfile(subm);
    init_c_kongsbergallconfigurationdatainterface(subm);
    init_c_kongsbergallconfigurationdatainterfaceperfile(subm);
    init_c_kongsbergallnavigationdatainterface(subm);
    init_c_kongsbergallnavigationdatainterfaceperfile(subm);
    init_c_kongsbergallenvironmentdatainterface(subm);
    init_c_kongsbergallenvironmentdatainterfaceperfile(subm);
    init_c_kongsbergallotherfiledatainterface(subm);
    init_c_kongsbergallotherfiledatainterfaceperfile(subm);

    init_c_kongsbergallpingdatainterface(subm);
    init_c_kongsbergallpingdatainterfaceperfile(subm);
}

}
}
}
}
}
