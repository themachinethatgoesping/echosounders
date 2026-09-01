// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools/progressbars/i_progressbar.hpp>
#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/s7k/datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/s7k/filedatainterfaces/s7kdatagraminterface.hpp"
#include "../../themachinethatgoesping/echosounders/s7k/types.hpp"

#include "../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::s7k;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define DOC_I_DatagramInterface(ARG)                                                               \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datainterfaces,                                                                            \
        I_DatagramInterface,                                                                       \
        ARG)

#define DOC_S7KDatagramInterface(ARG)                                                              \
    DOC(themachinethatgoesping, echosounders, s7k, filedatainterfaces, S7KDatagramInterface, ARG)

template<typename T_FileStream>
void py_create_class_S7KDatagramInterface(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces;
    using T_BaseClass = filedatainterfaces::S7KDatagramInterface<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, s7k, filedatainterfaces, S7KDatagramInterface));

    //----- inherit functions from I_DatagramInterface -----
    py_i_datagraminterface::add_InterfaceFunctions<T_BaseClass>(cls);

    //----- iterators via datagram containers -----
    // raw datagrams (each datagram is read on demand as an S7KUnknown, i.e. DRF header + raw bytes)
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self) {
            return nb::cast(self.template datagrams<datagrams::S7KUnknown>());
        },
        DOC_I_DatagramInterface(datagrams));
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self, t_S7KDatagramIdentifier type) {
            return nb::cast(self.template datagrams<datagrams::S7KUnknown>(type));
        },
        DOC_I_DatagramInterface(datagrams_2),
        nb::arg("datagram_type"));

    // datagram headers (Data Record Frame only)
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self) {
            return nb::cast(self.template datagrams<datagrams::S7KDatagram>());
        },
        DOC_I_DatagramInterface(datagrams));
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self, t_S7KDatagramIdentifier type) {
            return nb::cast(self.template datagrams<datagrams::S7KDatagram>(type));
        },
        DOC_I_DatagramInterface(datagrams_2),
        nb::arg("datagram_type"));

    cls.def("per_file",
            &T_BaseClass::per_file,
            DOC_S7KDatagramInterface(per_file),
            nb::rv_policy::reference_internal);

    // ----- convenience functions -----
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(T_BaseClass);
}

void init_c_s7kdatagraminterface(nanobind::module_& m)
{
    static const std::string name        = "S7KDatagramInterface";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_S7KDatagramInterface<std::ifstream>(m, name_stream);
    py_create_class_S7KDatagramInterface<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
