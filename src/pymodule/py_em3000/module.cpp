// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp> // Numpy bindings

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../themachinethatgoesping/echosounders/em3000/em3000_types.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

// datagram submodules
#include "py_datagrams/module.hpp"

namespace py = pybind11;

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {

// -- submodule declarations --
void init_c_fileem3000(pybind11::module& m); // c_fileem3000.cpp

//void init_c_file_test_functions(pybind11::module& m); // c_file_test_functions.cpp

// -- create submodule --
void init_m_em3000(pybind11::module& m)
{
    xt::import_numpy(); // import numpy for xtensor (otherwise there will be weird segfaults)
    using namespace em3000;

    // module description
    auto subm = m.def_submodule("em3000", "Classes related to Kongsberg EM3000 data files (old Kongsberg .all / .wcd format, used until SIS 4.0)");

    // py::enum_<t_EM3000DatagramIdentifier>(
    //     subm,
    //     "t_EM3000DatagramIdentifier",
    //     DOC(themachinethatgoesping, echosounders, em3000, t_EM3000DatagramIdentifier))
    //     .value("XML0",
    //            t_EM3000DatagramIdentifier::XML0,
    //            DOC(themachinethatgoesping, echosounders, em3000, t_EM3000DatagramIdentifier, XML0))
    //     .value("FIL1",
    //            t_EM3000DatagramIdentifier::FIL1,
    //            DOC(themachinethatgoesping, echosounders, em3000, t_EM3000DatagramIdentifier, FIL1))
    //     .value("NME0",
    //            t_EM3000DatagramIdentifier::NME0,
    //            DOC(themachinethatgoesping, echosounders, em3000, t_EM3000DatagramIdentifier, NME0))
    //     .value("MRU0",
    //            t_EM3000DatagramIdentifier::MRU0,
    //            DOC(themachinethatgoesping, echosounders, em3000, t_EM3000DatagramIdentifier, MRU0))
    //     .value("TAG0",
    //            t_EM3000DatagramIdentifier::TAG0,
    //            DOC(themachinethatgoesping, echosounders, em3000, t_EM3000DatagramIdentifier, TAG0))
    //     .value("RAW3",
    //            t_EM3000DatagramIdentifier::RAW3,
    //            DOC(themachinethatgoesping, echosounders, em3000, t_EM3000DatagramIdentifier, RAW3))
    //     .export_values()
    //     // pybind enum helper
    //     // unfortunately magic_enum only works for enums within a specific range that cannot exceed
    //     // max(uint16_t) therefore we need to use a custom function
    //     //__PYENUM_FROM_STRING__(t_EM3000DatagramIdentifier)
    //     .def(py::init([](const std::string& str) {
    //              if (str == "XML0")
    //                  return t_EM3000DatagramIdentifier::XML0;
    //              if (str == "FIL1")
    //                  return t_EM3000DatagramIdentifier::FIL1;
    //              if (str == "NME0")
    //                  return t_EM3000DatagramIdentifier::NME0;
    //              if (str == "MRU0")
    //                  return t_EM3000DatagramIdentifier::MRU0;
    //              if (str == "TAG0")
    //                  return t_EM3000DatagramIdentifier::TAG0;
    //              if (str == "RAW3")
    //                  return t_EM3000DatagramIdentifier::RAW3;

    //              std::string enum_info = "[XML0, FIL1, NME0, MRU0, TAG0, RAW3]";

    //              pybind11::print(
    //                  fmt::format("ERROR: unknown value option '{}'! Try: [{}]", str, enum_info));

    //              throw std::invalid_argument(
    //                  fmt::format("ERROR: unknown value option '{}'! Try: [{}]", str, enum_info));
    //          }),
    //          "Construct this enum type from string",
    //          py::arg("str"))
    //     //
    //     ;

    // py::implicitly_convertible<std::string, t_EM3000DatagramIdentifier>();

    // subm.def("datagram_type_to_string",
    //          py::overload_cast<em3000_long>(&datagram_type_to_string),
    //          DOC(themachinethatgoesping, echosounders, em3000, datagram_type_to_string),
    //          py::arg("datagram_type"));
    // subm.def("datagram_type_to_string",
    //          py::overload_cast<t_EM3000DatagramIdentifier>(&datagram_type_to_string),
    //          DOC(themachinethatgoesping, echosounders, em3000, datagram_type_to_string_2),
    //          py::arg("datagram_type"));
    // subm.def("EM3000Datagram_type_from_string",
    //          &EM3000Datagram_type_from_string,
    //          DOC(themachinethatgoesping, echosounders, em3000, EM3000Datagram_type_from_string),
    //          py::arg("datagram_type"));

    // datagrams
    py_datagrams::init_m_EM3000Datagrams(subm);
    // py_filedatatypes::init_m_EM3000FileDataTypes(subm);
    // py_filedatacontainers::init_m_EM3000FileDataContainers(subm);
    // py_filedatainterfaces::init_m_EM3000FileDataInterfaces(subm);

    // em3000 classes
    init_c_fileem3000(subm);

    //init_c_file_test_functions(subm);
}

}
}
}
}