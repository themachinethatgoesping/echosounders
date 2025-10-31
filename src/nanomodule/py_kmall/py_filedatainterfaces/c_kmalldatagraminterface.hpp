// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <chrono>
#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/variant.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools/progressbars/i_progressbar.hpp>
#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatainterfaces {

#define DOC_I_DatagramInterface(ARG)                                                               \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datainterfaces,                                                                            \
        I_DatagramInterface,                                                                       \
        ARG)

#define DOC_KMALLDatagramInterface(ARG)                                                            \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                                     \
        filedatainterfaces,                                                                        \
        KMALLDatagramInterface,                                                                    \
        ARG)

template<typename T_BaseClass, typename T_PyClass>
void KMALLDatagramInterface_add_interface_functions(T_PyClass& cls)
{
    namespace nb = nanobind;
    using namespace themachinethatgoesping::echosounders::filetemplates;
    using namespace themachinethatgoesping::echosounders::kmall;
    using themachinethatgoesping::tools::progressbars::I_ProgressBar;

    using namespace py_filetemplates::py_datainterfaces;
    py_i_datagraminterface::add_InterfaceFunctions<T_BaseClass>(cls);
    //----- iterators via () operator -----
    cls.def(
        "datagrams",
        [](const T_BaseClass& self, bool skip_data) {
            if (skip_data)
                return nb::cast(self.template datagrams<datagrams::t_KMALLDatagramVariant,
                                                        datagrams::KMALLSkipDataVariantFactory>());

            return nb::cast(self.template datagrams<datagrams::t_KMALLDatagramVariant,
                                                    datagrams::KMALLDatagramVariant>());
        },
        DOC_I_DatagramInterface(datagrams),
        nb::arg("skip_data") = false);
    cls.def(
        "datagrams",
        [](const T_BaseClass&        self,
           o_KMALLDatagramIdentifier type,
           [[maybe_unused]] bool     skip_data) {
            // KMALLDATAGRAMTYPEAREA
            switch (type.value)
            {
                case t_KMALLDatagramIdentifier::I_INSTALLATION_PARAM:
                    return nb::cast(
                        self.template datagrams<datagrams::IInstallationParam>(type));
                case t_KMALLDatagramIdentifier::I_OP_RUNTIME:
                    return nb::cast(
                        self.template datagrams<datagrams::IOpRuntime>(type));
                default:
                    return nb::cast(self.template datagrams<datagrams::KMALLUnknown>(type));
            }
        },
        DOC_I_DatagramInterface(datagrams_2),
        nb::arg("datagram_type"),
        nb::arg("skip_data") = false);
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self) {
            return nb::cast(self.template datagrams<datagrams::KMALLDatagram>());
        },
        DOC_I_DatagramInterface(datagrams));
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self, o_KMALLDatagramIdentifier type) {
            return nb::cast(self.template datagrams<datagrams::KMALLDatagram>(type));
        },
        DOC_I_DatagramInterface(datagrams_2),
        nb::arg("datagram_type"));
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self) {
            return nb::cast(self.template datagrams<datagrams::KMALLUnknown>());
        },
        DOC_I_DatagramInterface(datagrams));
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self, o_KMALLDatagramIdentifier type) {
            return nb::cast(self.template datagrams<datagrams::KMALLUnknown>(type));
        },
        DOC_I_DatagramInterface(datagrams_2),
        nb::arg("datagram_type"));

    cls.def("per_file",
            &T_BaseClass::per_file,
            DOC_KMALLDatagramInterface(per_file),
            nb::rv_policy::reference_internal);

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(T_BaseClass);
}

}
}
}
}
}