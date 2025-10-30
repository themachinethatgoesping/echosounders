// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings

#include <sstream>
#include <tuple>
#include <vector>
#include <stdexcept>
#include <string>
#include <string_view>

#include <fmt/format.h>

#include <themachinethatgoesping/echosounders/simradraw/types.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include "module.hpp"

// datagram submodules
#include "py_datagrams/module.hpp"
#include "py_filedatacontainers/module.hpp"
#include "py_filedatainterfaces/module.hpp"
#include "py_filedatatypes/module.hpp"

namespace nb = nanobind;

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {


// -- submodule declarations --
void init_c_simradrawfilehandler(nanobind::module_& m); // c_simradrawfilehandler.cpp

void init_c_file_test_functions(nanobind::module_& m); // c_file_test_functions.cpp

// -- create submodule --
void init_m_simradraw(nanobind::module_& m)
{
    using namespace simradraw;

    // module description
    auto subm = m.def_submodule("simradraw", "Classes related to SimradRaw EK60 and EK80 data files");

    nb::enum_<t_SimradRawDatagramIdentifier>(
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
        // pybind enum helper
        // unfortunately magic_enum only works for enums within a specific range that cannot exceed
        // max(uint16_t) therefore we need to use a custom function
        //__PYENUM_FROM_STRING__(t_SimradRawDatagramIdentifier)
        // .def(nb::init(&SimradRawDatagramIdentifier_from_string),
        //      "Construct this enum type from string",
        //      nb::arg("str"))
        //
        ;

    themachinethatgoesping::tools::nanobind_helper::make_option_class<o_SimradRawDatagramIdentifier>(
        subm, "o_SimradRawDatagramIdentifier");

    subm.def("datagram_type_to_string",
             nb::overload_cast<simradraw_long>(&datagram_type_to_string),
             DOC(themachinethatgoesping, echosounders, simradraw, datagram_type_to_string),
             nb::arg("datagram_type"));
    subm.def("datagram_type_to_string",
             nb::overload_cast<t_SimradRawDatagramIdentifier>(&datagram_type_to_string),
             DOC(themachinethatgoesping, echosounders, simradraw, datagram_type_to_string_2),
             nb::arg("datagram_type"));
    subm.def("SimradRawDatagram_type_from_string",
             &SimradRawDatagram_type_from_string,
             DOC(themachinethatgoesping, echosounders, simradraw, SimradRawDatagram_type_from_string),
             nb::arg("datagram_type"));
       

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