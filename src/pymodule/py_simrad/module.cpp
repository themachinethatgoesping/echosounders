// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp> // Numpy bindings

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

// datagram submodules
#include "py_datagrams/module.hpp"
#include "py_filedatacontainers/module.hpp"
#include "py_filedatainterfaces/module.hpp"
#include "py_filedatatypes/module.hpp"

namespace py = pybind11;

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

// -- submodule declarations --
void init_c_filesimradraw(pybind11::module& m); // c_filesimradraw.cpp

void init_c_file_test_functions(pybind11::module& m); // c_file_test_functions.cpp

// -- create submodule --
void init_m_simrad(pybind11::module& m)
{
    xt::import_numpy(); // import numpy for xtensor (otherwise there will be weird segfaults)
    using namespace simrad;

    // module description
    auto subm = m.def_submodule("simrad", "Classes related to Simrad EK60 and EK80 data files");

    py::enum_<t_SimradDatagramIdentifier>(
        subm,
        "t_SimradDatagramIdentifier",
        DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramIdentifier))
        .value("XML0",
               t_SimradDatagramIdentifier::XML0,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramIdentifier, XML0))
        .value("FIL1",
               t_SimradDatagramIdentifier::FIL1,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramIdentifier, FIL1))
        .value("NME0",
               t_SimradDatagramIdentifier::NME0,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramIdentifier, NME0))
        .value("MRU0",
               t_SimradDatagramIdentifier::MRU0,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramIdentifier, MRU0))
        .value("TAG0",
               t_SimradDatagramIdentifier::TAG0,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramIdentifier, TAG0))
        .value("RAW3",
               t_SimradDatagramIdentifier::RAW3,
               DOC(themachinethatgoesping, echosounders, simrad, t_SimradDatagramIdentifier, RAW3))
        .export_values()
        // pybind enum helper
        // unfortunately magic_enum only works for enums within a specific range that cannot exceed
        // max(uint16_t) therefore we need to use a custom function
        //__PYENUM_FROM_STRING__(t_SimradDatagramIdentifier)
        .def(py::init([](const std::string& str) {
                 if (str == "XML0")
                     return t_SimradDatagramIdentifier::XML0;
                 if (str == "FIL1")
                     return t_SimradDatagramIdentifier::FIL1;
                 if (str == "NME0")
                     return t_SimradDatagramIdentifier::NME0;
                 if (str == "MRU0")
                     return t_SimradDatagramIdentifier::MRU0;
                 if (str == "TAG0")
                     return t_SimradDatagramIdentifier::TAG0;
                 if (str == "RAW3")
                     return t_SimradDatagramIdentifier::RAW3;

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

    py::implicitly_convertible<std::string, t_SimradDatagramIdentifier>();

    subm.def("datagram_type_to_string",
             py::overload_cast<simrad_long>(&datagram_type_to_string),
             DOC(themachinethatgoesping, echosounders, simrad, datagram_type_to_string),
             py::arg("datagram_type"));
    subm.def("datagram_type_to_string",
             py::overload_cast<t_SimradDatagramIdentifier>(&datagram_type_to_string),
             DOC(themachinethatgoesping, echosounders, simrad, datagram_type_to_string_2),
             py::arg("datagram_type"));
    subm.def("SimradDatagram_type_from_string",
             &SimradDatagram_type_from_string,
             DOC(themachinethatgoesping, echosounders, simrad, SimradDatagram_type_from_string),
             py::arg("datagram_type"));

    // datagrams
    py_datagrams::init_m_SimradDatagrams(subm);
    py_filedatatypes::init_m_SimradFileDataTypes(subm);
    py_filedatacontainers::init_m_SimradFileDataContainers(subm);
    py_filedatainterfaces::init_m_SimradFileDataInterfaces(subm);

    // simrad classes
    init_c_filesimradraw(subm);

    init_c_file_test_functions(subm);
}

}
}
}
}