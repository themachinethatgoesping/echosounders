// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp> // Numpy bindings

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../themachinethatgoesping/echosounders/simradraw/types.hpp"

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
namespace py_simradraw {

// -- submodule declarations --
void init_c_simradrawfilehandler(pybind11::module& m); // c_simradrawfilehandler.cpp

void init_c_file_test_functions(pybind11::module& m); // c_file_test_functions.cpp

// -- create submodule --
void init_m_simradraw(pybind11::module& m)
{
    using namespace simradraw;

    // module description
    auto subm = m.def_submodule("simradraw", "Classes related to SimradRaw EK60 and EK80 data files");

    py::enum_<t_SimradRawDatagramIdentifier>(
        subm,
        "t_SimradRawDatagramIdentifier",
        DOC(themachinethatgoesping, echosounders, simradraw, t_SimradRawDatagramIdentifier))
        .value("XML0",
               t_SimradRawDatagramIdentifier::XML0,
               DOC(themachinethatgoesping, echosounders, simradraw, t_SimradRawDatagramIdentifier, XML0))
        .value("FIL1",
               t_SimradRawDatagramIdentifier::FIL1,
               DOC(themachinethatgoesping, echosounders, simradraw, t_SimradRawDatagramIdentifier, FIL1))
        .value("NME0",
               t_SimradRawDatagramIdentifier::NME0,
               DOC(themachinethatgoesping, echosounders, simradraw, t_SimradRawDatagramIdentifier, NME0))
        .value("MRU0",
               t_SimradRawDatagramIdentifier::MRU0,
               DOC(themachinethatgoesping, echosounders, simradraw, t_SimradRawDatagramIdentifier, MRU0))
        .value("TAG0",
               t_SimradRawDatagramIdentifier::TAG0,
               DOC(themachinethatgoesping, echosounders, simradraw, t_SimradRawDatagramIdentifier, TAG0))
        .value("RAW3",
               t_SimradRawDatagramIdentifier::RAW3,
               DOC(themachinethatgoesping, echosounders, simradraw, t_SimradRawDatagramIdentifier, RAW3))
        .export_values()
        // pybind enum helper
        // unfortunately magic_enum only works for enums within a specific range that cannot exceed
        // max(uint16_t) therefore we need to use a custom function
        //__PYENUM_FROM_STRING__(t_SimradRawDatagramIdentifier)
        .def(py::init([](const std::string& str) {
                 if (str == "XML0")
                     return t_SimradRawDatagramIdentifier::XML0;
                 if (str == "FIL1")
                     return t_SimradRawDatagramIdentifier::FIL1;
                 if (str == "NME0")
                     return t_SimradRawDatagramIdentifier::NME0;
                 if (str == "MRU0")
                     return t_SimradRawDatagramIdentifier::MRU0;
                 if (str == "TAG0")
                     return t_SimradRawDatagramIdentifier::TAG0;
                 if (str == "RAW3")
                     return t_SimradRawDatagramIdentifier::RAW3;

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

    py::implicitly_convertible<std::string, t_SimradRawDatagramIdentifier>();

    subm.def("datagram_type_to_string",
             py::overload_cast<simradraw_long>(&datagram_type_to_string),
             DOC(themachinethatgoesping, echosounders, simradraw, datagram_type_to_string),
             py::arg("datagram_type"));
    subm.def("datagram_type_to_string",
             py::overload_cast<t_SimradRawDatagramIdentifier>(&datagram_type_to_string),
             DOC(themachinethatgoesping, echosounders, simradraw, datagram_type_to_string_2),
             py::arg("datagram_type"));
    subm.def("SimradRawDatagram_type_from_string",
             &SimradRawDatagram_type_from_string,
             DOC(themachinethatgoesping, echosounders, simradraw, SimradRawDatagram_type_from_string),
             py::arg("datagram_type"));

    // datagrams
    py_datagrams::init_m_simradrawdatagrams(subm);
    py_filedatatypes::init_m_simradrawfiledatatypes(subm);
    py_filedatacontainers::init_m_simradrawfiledatacontainers(subm);
    py_filedatainterfaces::init_m_simradrawfiledatainterfaces(subm);

    // simradraw classes
    init_c_simradrawfilehandler(subm);

    init_c_file_test_functions(subm);
}

}
}
}
}