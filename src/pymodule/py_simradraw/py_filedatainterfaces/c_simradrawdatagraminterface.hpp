// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <chrono>
#include <pybind11/pybind11.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatainterfaces {

#define DOC_SimradRawDatagramInterface(ARG)                                                           \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                    \
        filedatainterfaces,                                                                        \
        SimradRawDatagramInterface,                                                                   \
        ARG)

#define DOC_I_DatagramInterface(ARG)                                                               \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datainterfaces,                                                                            \
        I_DatagramInterface,                                                                       \
        ARG)

template<typename T_BaseClass, typename T_PyClass>
void SimradRawDatagramInterface_add_interface_functions(T_PyClass& cls)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates;
    using namespace themachinethatgoesping::echosounders::simradraw;
    using themachinethatgoesping::tools::progressbars::I_ProgressBar;

    using namespace py_filetemplates::py_datainterfaces;
    py_i_datagraminterface::add_InterfaceFunctions<T_BaseClass>(cls);

    //----- iterators via () operator -----
    cls.def(
        "datagrams",
        [](const T_BaseClass& self, bool skip_data) {
            if (skip_data)
                return py::cast(self.template datagrams<datagrams::t_SimradRawDatagramVariant,
                                                        datagrams::SimradRawSkipDataVariantFactory>());

            return py::cast(self.template datagrams<datagrams::t_SimradRawDatagramVariant,
                                                    datagrams::SimradRawDatagramVariant>());
        },
        DOC_I_DatagramInterface(datagrams),
        py::arg("skip_data") = false);
    cls.def(
        "datagrams",
        [](const T_BaseClass& self, t_SimradRawDatagramIdentifier type, bool skip_data) {
            switch (type)
            {
                case t_SimradRawDatagramIdentifier::MRU0:
                    return py::cast(self.template datagrams<datagrams::MRU0>(type));
                case t_SimradRawDatagramIdentifier::NME0:
                    return py::cast(self.template datagrams<datagrams::NME0>(type));
                case t_SimradRawDatagramIdentifier::XML0:
                    return py::cast(self.template datagrams<datagrams::XML0>(type));
                case t_SimradRawDatagramIdentifier::TAG0:
                    return py::cast(self.template datagrams<datagrams::TAG0>(type));
                case t_SimradRawDatagramIdentifier::FIL1:
                    return py::cast(self.template datagrams<datagrams::FIL1>(type));
                case t_SimradRawDatagramIdentifier::RAW3:
                    if (skip_data)
                        return py::cast(self.template datagrams<
                                        datagrams::RAW3,
                                        datagrams::SimradRawSkipDataFactory<datagrams::RAW3>>(type));
                    else
                        return py::cast(self.template datagrams<datagrams::RAW3>(type));
                default:
                    return py::cast(self.template datagrams<datagrams::SimradRawUnknown>(type));
            }
        },
        DOC_I_DatagramInterface(datagrams_2),
        py::arg("datagram_type"),
        py::arg("skip_data") = false);
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self) {
            return py::cast(self.template datagrams<datagrams::SimradRawDatagram>());
        },
        DOC_I_DatagramInterface(datagrams));
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self, t_SimradRawDatagramIdentifier type) {
            return py::cast(self.template datagrams<datagrams::SimradRawDatagram>(type));
        },
        DOC_I_DatagramInterface(datagrams_2),
        py::arg("datagram_type"));
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self) {
            return py::cast(self.template datagrams<datagrams::SimradRawUnknown>());
        },
        DOC_I_DatagramInterface(datagrams));
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self, t_SimradRawDatagramIdentifier type) {
            return py::cast(self.template datagrams<datagrams::SimradRawUnknown>(type));
        },
        DOC_I_DatagramInterface(datagrams_2),
        py::arg("datagram_type"));

    cls.def("per_file",
            &T_BaseClass::per_file,
            DOC_SimradRawDatagramInterface(per_file),
            py::return_value_policy::reference_internal);

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