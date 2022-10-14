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
#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/simradnavigationdatainterface.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX themachinethatgoesping, echosounders, simrad, SimradNavigationDataInterface
#define INTERFACE_DOC_PREFIX                                                                       \
    themachinethatgoesping, echosounders, fileinterfaces, I_NavigationDataInterface

template<typename T_FileStream>
void py_create_class_SimradNavigationDataInterface(py::module& m, const std::string& CLASS_NAME)
{
    // using namespace py_fileinterfaces; // this holds py_i_InputFile and py_i_InputFileIterator

    // initialize class
    auto cls = py::class_<SimradNavigationDataInterface<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX));

    //----- inherit functions from I_NavigationDataInterface -----

    //----- iterators -----

    //----- iterators via () operator -----
    cls.def(
        "packages",
        [](const SimradNavigationDataInterface<T_FileStream>& self,
           long                                           index_min,
           long                                           index_max,
           long                                           index_step) {
            return py::cast(self.template get_iterator<datagrams::t_SimradDatagramVariant,
                                                       datagrams::SimradDatagramVariant>(
                index_min, index_max, index_step));
        },
        DOC(INTERFACE_DOC_PREFIX, get_iterator),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<long>::max(),
        py::arg("index_step") = 1);
    cls.def(
        "packages",
        [](const SimradNavigationDataInterface<T_FileStream>& self,
           t_SimradDatagramType                           type,
           long                                           index_min,
           long                                           index_max,
           long                                           index_step) {
            switch (type)
            {
                case t_SimradDatagramType::MRU0:
                    return py::cast(self.template get_iterator<datagrams::MRU0>(
                        type, index_min, index_max, index_step));
                case t_SimradDatagramType::NME0:
                    return py::cast(self.template get_iterator<datagrams::NME0>(
                        type, index_min, index_max, index_step));
                default:
                    throw std::runtime_error(fmt::format(
                        "This package type should not exist in a SimradNavigationDataInterface: {}",
                        datagram_type_to_string(type)));
            }
        },
        DOC(INTERFACE_DOC_PREFIX, get_iterator_3),
        py::arg("datagram_type"),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<long>::max(),
        py::arg("index_step") = 1);

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    // cls __PYCLASS_DEFAULT_PRINTING__(SimradNavigationDataInterface<T_FileStream>);
}

void init_c_SimradNavigationDataInterface(pybind11::module& m)
{

    py_create_class_SimradNavigationDataInterface<std::ifstream>(m, "SimradNavigationDataInterface");
    py_create_class_SimradNavigationDataInterface<MappedFileStream>(m,
                                                                "SimradNavigationDataInterface_mapped");
}

}
}
}
}