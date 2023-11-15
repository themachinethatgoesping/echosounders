// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatainterfaces {

namespace py = pybind11;

// -- submodule declarations --
void init_c_KongsbergAllDatagramInterface(py::module& m); // c_kongsbergalldatagraminterface.cpp

void init_c_kongsbergalldatagramdatainterface(pybind11::module& m); // c_kongsbergalldatagramdatainterface.cpp
void init_c_kongsbergalldatagramdatainterfaceperfile(
    pybind11::module& m); // c_kongsbergalldatagramdatainterfaceperfile.cpp
void init_c_kongsbergallconfigurationdatainterface(
    pybind11::module& m); // c_kongsbergallconfigurationdatainterface.cpp
void init_c_kongsbergallconfigurationdatainterfaceperfile(
    pybind11::module& m); // c_kongsbergallconfigurationdatainterfaceperfile.cpp
void init_c_kongsbergallnavigationdatainterface(
    pybind11::module& m); // c_kongsbergallnavigationdatainterface.cpp
void init_c_kongsbergallnavigationdatainterfaceperfile(
    pybind11::module& m); // c_kongsbergallnavigationdatainterfaceperfile.cpp
void init_c_kongsbergallenvironmentdatainterface(
    pybind11::module& m); // c_kongsbergallenvironmentdatainterface.cpp
void init_c_kongsbergallenvironmentdatainterfaceperfile(
    pybind11::module& m); // c_kongsbergallenvironmentdatainterfaceperfile.cpp
void init_c_kongsbergallannotationdatainterface(
    pybind11::module& m); // c_kongsbergallannotationdatainterface.cpp
void init_c_kongsbergallannotationdatainterfaceperfile(pybind11::module& m);
void init_c_kongsbergallotherfiledatainterface(pybind11::module& m); // c_kongsbergallotherfiledatainterface.cpp
void init_c_kongsbergallotherfiledatainterfaceperfile(
    pybind11::module& m); // c_kongsbergallotherfiledatainterfaceperfile.cpp
void init_c_kongsbergallpingdatainterface(pybind11::module& m); // c_kongsbergallpingdatainterface.cpp
void init_c_kongsbergallpingdatainterfaceperfile(
    pybind11::module& m); // c_kongsbergallpingdatainterfaceperfile.cpp

// -- create submodule --
void init_m_kongsbergallfiledatainterfaces(pybind11::module& m)
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
    init_c_kongsbergallannotationdatainterface(subm);
    init_c_kongsbergallannotationdatainterfaceperfile(subm);
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
