// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/string.h>

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/echosounders/kmall/types.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include "module.hpp"

#include "py_datagrams/module.hpp"
#include "py_filedatacontainers/module.hpp"
#include "py_filedatainterfaces/module.hpp"

// datagram submodules
// #include "py_datagrams/module.hpp"
// #include "py_filedatacontainers/module.hpp"
// #include "py_filedatainterfaces/module.hpp"
// #include "py_filedatatypes/module.hpp"

namespace nb = nanobind;
namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {

// -- submodule declarations --
void init_c_kmallfilehandler(nanobind::module_& m); // c_kmallfilehandler.cpp

// void init_c_file_test_functions(nanobind::module_& m); // c_file_test_functions.cpp

#define DOC_t_KMALLDatagramIdentifier(ARG)                                                         \
    DOC(themachinethatgoesping, echosounders, kmall, t_KMALLDatagramIdentifier, ARG)
#define DOC_t_KMALLActiveSensor(ARG)                                                               \
    DOC(themachinethatgoesping, echosounders, kmall, t_KMALLActiveSensor, ARG)
#define DOC_t_KMALLSystemTransducerConfiguration(ARG)                                              \
    DOC(themachinethatgoesping, echosounders, kmall, t_KMALLSystemTransducerConfiguration, ARG)

// -- create submodule --
void init_m_kmall(nanobind::module_& m)
{
    using namespace kmall;

    // module description
    auto subm = m.def_submodule("kmall", "Classes related to KMALL data files");

    nb::enum_<t_KMALLDatagramIdentifier>(
        subm,
        "t_KMALLDatagramIdentifier",
        DOC(themachinethatgoesping, echosounders, kmall, t_KMALLDatagramIdentifier))
        .value("I_INSTALLATION_PARAM",
               t_KMALLDatagramIdentifier::I_INSTALLATION_PARAM,
               DOC_t_KMALLDatagramIdentifier(I_INSTALLATION_PARAM))
        .value("I_OP_RUNTIME",
               t_KMALLDatagramIdentifier::I_OP_RUNTIME,
               DOC_t_KMALLDatagramIdentifier(I_OP_RUNTIME))
        .value("S_POSITION",
               t_KMALLDatagramIdentifier::S_POSITION,
               DOC_t_KMALLDatagramIdentifier(S_POSITION))
        .value("S_POSITION_ERROR",
               t_KMALLDatagramIdentifier::S_POSITION_ERROR,
               DOC_t_KMALLDatagramIdentifier(S_POSITION_ERROR))
        .value("S_POSITION_DATUM",
               t_KMALLDatagramIdentifier::S_POSITION_DATUM,
               DOC_t_KMALLDatagramIdentifier(S_POSITION_DATUM))
        .value("S_KM_BINARY",
               t_KMALLDatagramIdentifier::S_KM_BINARY,
               DOC_t_KMALLDatagramIdentifier(S_KM_BINARY))
        .value("S_SOUND_VELOCITY_PROFILE",
               t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_PROFILE,
               DOC_t_KMALLDatagramIdentifier(S_SOUND_VELOCITY_PROFILE))
        .value("S_SOUND_VELOCITY_TRANSDUCER",
               t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_TRANSDUCER,
               DOC_t_KMALLDatagramIdentifier(S_SOUND_VELOCITY_TRANSDUCER))
        .value(
            "S_CLOCK", t_KMALLDatagramIdentifier::S_CLOCK, DOC_t_KMALLDatagramIdentifier(S_CLOCK))
        .value(
            "S_DEPTH", t_KMALLDatagramIdentifier::S_DEPTH, DOC_t_KMALLDatagramIdentifier(S_DEPTH))
        .value("S_HEIGHT",
               t_KMALLDatagramIdentifier::S_HEIGHT,
               DOC_t_KMALLDatagramIdentifier(S_HEIGHT))
        .value("M_RANGE_AND_DEPTH",
               t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH,
               DOC_t_KMALLDatagramIdentifier(M_RANGE_AND_DEPTH))
        .value("M_WATER_COLUMN",
               t_KMALLDatagramIdentifier::M_WATER_COLUMN,
               DOC_t_KMALLDatagramIdentifier(M_WATER_COLUMN))
        .value("C_POSITION",
               t_KMALLDatagramIdentifier::C_POSITION,
               DOC_t_KMALLDatagramIdentifier(C_POSITION));

    themachinethatgoesping::tools::nanobind_helper::make_option_class<o_KMALLDatagramIdentifier>(
        subm, "o_KMALLDatagramIdentifier");

    subm.def("datagram_type_to_string",
             nb::overload_cast<t_KMALLDatagramIdentifier>(&datagram_type_to_string),
             DOC(themachinethatgoesping, echosounders, kmall, datagram_type_to_string),
             nb::arg("datagram_type"));
    subm.def("KMALLDatagram_type_from_string",
             &KMALLDatagram_type_from_string,
             DOC(themachinethatgoesping, echosounders, kmall, KMALLDatagram_type_from_string),
             nb::arg("datagram_type"));

    // datagrams
    //     py_filedatatypes::init_m_kmallfiledatatypes(subm);
    //     py_filedatacontainers::init_m_kmallfiledatacontainers(subm);
    //     py_filedatainterfaces::init_m_kmallfiledatainterfaces(subm);

    py_datagrams::init_m_kmalldatagrams(subm);
    py_filedatacontainers::init_m_kmallfiledatacontainers(subm);
    py_filedatainterfaces::init_m_kmallfiledatainterfaces(subm);

    // kmall classes
    init_c_kmallfilehandler(subm);

    // init_c_file_test_functions(subm);
}

}
}
}
}