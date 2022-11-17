// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pyarray.hpp> // Numpy bindings
#include <xtensor/xmath.hpp>          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simraddatagraminterface.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_datagramcontainer.hpp"
#include "../fileinterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;


template<typename T_FileStream>
void py_create_class_SimradDatagramInterface(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_fileinterfaces; // this holds py_i_DatagramInterface and
                                       // py_i_DatagramInterface

    // initialize class
    auto cls = py::class_<SimradDatagramInterface<T_FileStream>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simrad, SimradDatagramInterface));

    //----- inherit functions from I_DatagramInterface -----


    //----- iterators via () operator -----
    cls.def(
        "datagrams",
        [](const SimradDatagramInterface<T_FileStream>& self) {
            return py::cast(self.template datagrams<datagrams::t_SimradDatagramVariant,
                                                       datagrams::SimradDatagramVariant>());
        },
        DOC(themachinethatgoesping, echosounders, simrad, SimradDatagramInterface,
            datagrams));
    cls.def(
        "datagrams",
        [](const SimradDatagramInterface<T_FileStream>& self, t_SimradDatagramIdentifier type) {
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
        DOC(themachinethatgoesping, echosounders, simrad, SimradDatagramInterface,
            datagrams_2),
        py::arg("datagram_type"));
    cls.def(
        "datagram_headers",
        [](const SimradDatagramInterface<T_FileStream>& self) {
            return py::cast(self.template datagrams<datagrams::SimradDatagram>());
        },
        DOC(themachinethatgoesping, echosounders, simrad, SimradDatagramInterface,
            datagrams));
    cls.def(
        "datagram_headers",
        [](const SimradDatagramInterface<T_FileStream>& self, t_SimradDatagramIdentifier type) {
            return py::cast(self.template datagrams<datagrams::SimradDatagram>(type));
        },
        DOC(themachinethatgoesping, echosounders, simrad, SimradDatagramInterface,
            datagrams_2),
        py::arg("datagram_type"));
    cls.def(
        "datagrams_raw",
        [](const SimradDatagramInterface<T_FileStream>& self) {
            return py::cast(self.template datagrams<datagrams::SimradUnknown>());
        },
        DOC(themachinethatgoesping, echosounders, simrad, SimradDatagramInterface,
            datagrams));
    cls.def(
        "datagrams_raw",
        [](const SimradDatagramInterface<T_FileStream>& self, t_SimradDatagramIdentifier type) {
            return py::cast(self.template datagrams<datagrams::SimradUnknown>(type));
        },
        DOC(themachinethatgoesping, echosounders, simrad, SimradDatagramInterface,
            datagrams_2),
        py::arg("datagram_type"));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(SimradDatagramInterface<T_FileStream>);
}

void init_c_simraddatagraminterface(pybind11::module& m)
{

    py_create_class_SimradDatagramInterface<std::ifstream>(m, "SimradDatagramInterface");
    py_create_class_SimradDatagramInterface<MappedFileStream>(m, "SimradDatagramInterface_mapped");
}

}
}
}
}