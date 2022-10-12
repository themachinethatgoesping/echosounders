// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>
#define FORCE_IMPORT_ARRAY
#include <xtensor-python/pyarray.hpp> // Numpy bindings

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools/pybind11_helpers/enumhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

// datagram submodules
#include "datagrams/module.hpp"

namespace py = pybind11;

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

// -- submodule declarations --
void init_c_fileraw(pybind11::module& m); // c_fileraw.cpp
void init_c_SimradPing(pybind11::module& m); // c_SimradPing.cpp
void init_c_SimradPingIterator(pybind11::module& m); // c_SimradPingIterator.cpp
void init_c_SimradFileData(pybind11::module& m); // c_SimradFileData.cpp

// -- create submodule --
void init_m_simrad(pybind11::module& m)
{
    xt::import_numpy(); // import numpy for xtensor (otherwise there will be weird segfaults)
    using namespace simrad;

    // module description
    auto subm = m.def_submodule("simrad", "Classes related to Simrad EK60 and EK80 data files");

    py::enum_<t_SimradDatagramType>(
        subm,
        "t_SimradDatagramType",
        DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramType))
        .value("XML0",
               t_SimradDatagramType::XML0,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramType, XML0))
        .value("FIL1",
               t_SimradDatagramType::FIL1,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramType, FIL1))
        .value("NME0",
               t_SimradDatagramType::NME0,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramType, NME0))
        .value("MRU0",
               t_SimradDatagramType::MRU0,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramType, MRU0))
        .value("TAG0",
               t_SimradDatagramType::TAG0,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramType, TAG0))
        .value("RAW3",
               t_SimradDatagramType::RAW3,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramType, RAW3))
        .export_values()
        // pybind enum helpers
        // unfortunately magic_enum only works for enums within a specific range that cannot exceed
        // max(uint16_t) therefore we need to use a custom function
        //__PYENUM_FROM_STRING__(t_SimradDatagramType)
        .def(py::init([](const std::string& str) {
                 if (str == "XML0")
                     return t_SimradDatagramType::XML0;
                 if (str == "FIL1")
                     return t_SimradDatagramType::FIL1;
                 if (str == "NME0")
                     return t_SimradDatagramType::NME0;
                 if (str == "MRU0")
                     return t_SimradDatagramType::MRU0;
                 if (str == "TAG0")
                     return t_SimradDatagramType::TAG0;
                 if (str == "RAW3")
                     return t_SimradDatagramType::RAW3;

                 std::string enum_info = "[XML0, FIL1, NME0, MRU0, TAG0, RAW3]";

                 pybind11::print(
                     fmt::format("ERROR: unknown value option '{}'! Try: [{}]", str, enum_info));

                 throw std::invalid_argument(
                     fmt::format("ERROR: unknown value option '{}'! Try: [{}]", str, enum_info));
             }),
             "Construct this enum type from string",
             py::arg("str"))
        //
        ;

    py::implicitly_convertible<std::string, t_SimradDatagramType>();

    subm.def("datagram_type_to_string",
             &datagram_type_to_string,
             DOC(themachinethatgoesping, echosounders, simrad, datagram_type_to_string),
             py::arg("datagram_type"));
    subm.def("SimradDatagram_type_from_string",
             &SimradDatagram_type_from_string,
             DOC(themachinethatgoesping, echosounders, simrad, SimradDatagram_type_from_string),
             py::arg("datagram_type"));

    // datagrams
    py_datagrams::init_m_SimradDatagrams(subm);

    // simrad classes
    init_c_SimradFileData(subm);
    init_c_SimradPing(subm);
    init_c_SimradPingIterator(subm);
    init_c_fileraw(subm);
}

}
}
}
}