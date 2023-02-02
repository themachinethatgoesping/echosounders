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
namespace py_simrad {
namespace py_filedatainterfaces {

template<typename T_BaseClass, typename T_PyClass>
void SimradDatagramInterface_add_interface_functions(T_PyClass& cls)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates;
    using namespace themachinethatgoesping::echosounders::simrad;
    using themachinethatgoesping::tools::progressbars::I_ProgressBar;

    using namespace py_filetemplates::py_datainterfaces;
    py_i_datagraminterface::add_InterfaceFunctions<T_BaseClass>(cls);

    //----- iterators via () operator -----
    cls.def(
        "datagrams",
        [](const T_BaseClass& self) {
            return py::cast(self.template datagrams<datagrams::t_SimradDatagramVariant,
                                                    datagrams::SimradDatagramVariant>());
        },
        DOC(themachinethatgoesping,
            echosounders,
            filetemplates,
            datainterfaces,
            I_DatagramInterface,
            datagrams));
    cls.def(
        "datagrams",
        [](const T_BaseClass& self, t_SimradDatagramIdentifier type) {
            switch (type)
            {
                case t_SimradDatagramIdentifier::MRU0:
                    return py::cast(self.template datagrams<datagrams::MRU0>(type));
                case t_SimradDatagramIdentifier::NME0:
                    return py::cast(self.template datagrams<datagrams::NME0>(type));
                case t_SimradDatagramIdentifier::XML0:
                    return py::cast(self.template datagrams<datagrams::XML0>(type));
                case t_SimradDatagramIdentifier::TAG0:
                    return py::cast(self.template datagrams<datagrams::TAG0>(type));
                case t_SimradDatagramIdentifier::FIL1:
                    return py::cast(self.template datagrams<datagrams::FIL1>(type));
                case t_SimradDatagramIdentifier::RAW3:
                    return py::cast(self.template datagrams<datagrams::RAW3>(type));
                default:
                    return py::cast(self.template datagrams<datagrams::SimradUnknown>(type));
            }
        },
        DOC(themachinethatgoesping,
            echosounders,
            filetemplates,
            datainterfaces,
            I_DatagramInterface,
            datagrams_2),
        py::arg("datagram_type"));
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self) {
            return py::cast(self.template datagrams<datagrams::SimradDatagram>());
        },
        DOC(themachinethatgoesping,
            echosounders,
            filetemplates,
            datainterfaces,
            I_DatagramInterface,
            datagrams));
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self, t_SimradDatagramIdentifier type) {
            return py::cast(self.template datagrams<datagrams::SimradDatagram>(type));
        },
        DOC(themachinethatgoesping,
            echosounders,
            filetemplates,
            datainterfaces,
            I_DatagramInterface,
            datagrams_2),
        py::arg("datagram_type"));
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self) {
            return py::cast(self.template datagrams<datagrams::SimradUnknown>());
        },
        DOC(themachinethatgoesping,
            echosounders,
            filetemplates,
            datainterfaces,
            I_DatagramInterface,
            datagrams));
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self, t_SimradDatagramIdentifier type) {
            return py::cast(self.template datagrams<datagrams::SimradUnknown>(type));
        },
        DOC(themachinethatgoesping,
            echosounders,
            filetemplates,
            datainterfaces,
            I_DatagramInterface,
            datagrams_2),
        py::arg("datagram_type"));

    cls.def("per_file",
            &T_BaseClass::per_file,
            DOC(themachinethatgoesping,
                echosounders,
                simrad,
                filedatainterfaces,
                SimradDatagramInterface,
                per_file),
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