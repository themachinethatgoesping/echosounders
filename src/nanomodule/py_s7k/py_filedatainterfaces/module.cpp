// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatainterfaces {

namespace nb = nanobind;

// -- submodule declarations --
void init_c_s7kdatagraminterface(nanobind::module_& m); // c_s7kdatagraminterface.cpp
void init_c_s7kdatagramdatainterfaceperfile(nanobind::module_& m);
void init_c_s7kdatagramdatainterface(nanobind::module_& m);
void init_c_s7kotherfiledatainterfaceperfile(nanobind::module_& m);
void init_c_s7kotherfiledatainterface(nanobind::module_& m);
void init_c_s7kconfigurationdatainterfaceperfile(nanobind::module_& m);
void init_c_s7kconfigurationdatainterface(nanobind::module_& m);
void init_c_s7knavigationdatainterfaceperfile(nanobind::module_& m);
void init_c_s7knavigationdatainterface(nanobind::module_& m);
void init_c_s7kenvironmentdatainterfaceperfile(nanobind::module_& m);
void init_c_s7kenvironmentdatainterface(nanobind::module_& m);
void init_c_s7kpingdatainterfaceperfile(nanobind::module_& m);
void init_c_s7kpingdatainterface(nanobind::module_& m);

// -- create submodule --
void init_m_s7kfiledatainterfaces(nanobind::module_& m)
{
    auto subm = m.def_submodule("filedatainterfaces",
                                "Teledyne RESON .s7k (7k) file data interface classes");

    init_c_s7kdatagraminterface(subm);

    init_c_s7kdatagramdatainterfaceperfile(subm);
    init_c_s7kdatagramdatainterface(subm);

    init_c_s7kotherfiledatainterfaceperfile(subm);
    init_c_s7kotherfiledatainterface(subm);

    init_c_s7kconfigurationdatainterfaceperfile(subm);
    init_c_s7kconfigurationdatainterface(subm);

    init_c_s7knavigationdatainterfaceperfile(subm);
    init_c_s7knavigationdatainterface(subm);

    init_c_s7kenvironmentdatainterfaceperfile(subm);
    init_c_s7kenvironmentdatainterface(subm);

    init_c_s7kpingdatainterfaceperfile(subm);
    init_c_s7kpingdatainterface(subm);
}

}
}
}
}
}
