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
namespace py_em3000 {
namespace py_filedatainterfaces {

template<typename T_BaseClass, typename T_PyClass>
void EM3000DatagramInterface_add_interface_functions(T_PyClass& cls)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates;
    using namespace themachinethatgoesping::echosounders::em3000;
    using themachinethatgoesping::tools::progressbars::I_ProgressBar;

    using namespace py_filetemplates; // this holds py_i_DatagramInterface and
                                      // py_i_DatagramInterface
    //----- iterators via () operator -----
    cls.def(
        "datagrams",
        [](const T_BaseClass& self) {
            return py::cast(self.template datagrams<datagrams::t_EM3000DatagramVariant,
                                                    datagrams::EM3000DatagramVariant>());
        },
        DOC(themachinethatgoesping,
            echosounders,
            filetemplates,
            datainterfaces,
            I_DatagramInterface,
            datagrams));
    cls.def(
        "datagrams",
        [](const T_BaseClass& self, t_EM3000DatagramIdentifier type) {
            // EM3000DATAGRAMTYPEAREA
            switch (type)
            {
                case t_EM3000DatagramIdentifier::XYZDatagram:
                    return py::cast(self.template datagrams<datagrams::XYZDatagram>(type));
                case t_EM3000DatagramIdentifier::ExtraDetections:
                    return py::cast(self.template datagrams<datagrams::ExtraDetections>(type));
                case t_EM3000DatagramIdentifier::RawRangeAndAngle:
                    return py::cast(self.template datagrams<datagrams::RawRangeAndAngle>(type));
                case t_EM3000DatagramIdentifier::SeabedImageData:
                    return py::cast(self.template datagrams<datagrams::SeabedImageData>(type));
                case t_EM3000DatagramIdentifier::WaterColumnDatagram:
                    return py::cast(self.template datagrams<datagrams::WaterColumnDatagram>(type));
                default:
                    return py::cast(self.template datagrams<datagrams::EM3000Unknown>(type));
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
            return py::cast(self.template datagrams<datagrams::EM3000Datagram>());
        },
        DOC(themachinethatgoesping,
            echosounders,
            filetemplates,
            datainterfaces,
            I_DatagramInterface,
            datagrams));
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self, t_EM3000DatagramIdentifier type) {
            return py::cast(self.template datagrams<datagrams::EM3000Datagram>(type));
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
            return py::cast(self.template datagrams<datagrams::EM3000Unknown>());
        },
        DOC(themachinethatgoesping,
            echosounders,
            filetemplates,
            datainterfaces,
            I_DatagramInterface,
            datagrams));
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self, t_EM3000DatagramIdentifier type) {
            return py::cast(self.template datagrams<datagrams::EM3000Unknown>(type));
        },
        DOC(themachinethatgoesping,
            echosounders,
            filetemplates,
            datainterfaces,
            I_DatagramInterface,
            datagrams_2),
        py::arg("datagram_type"));

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