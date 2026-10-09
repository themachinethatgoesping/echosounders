// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#define FORCE_IMPORT_ARRAY // this is needed for xtensor interop when required

#include <nanobind/nanobind.h>

// larger submodules
#include "py_kongsbergall/module.hpp"
#include "py_filetemplates/module.hpp"
#include "py_pingtools/module.hpp"
#include "py_simradraw/module.hpp"
#include "py_gsf/module.hpp"
#include "py_kmall/module.hpp"
#include "py_s7k/module.hpp"

#include <themachinethatgoesping/tools_nanobind/ostream_redirect.hpp>

namespace nb = nanobind;

// declare modules
namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {

NB_MODULE(MODULE_NAME, m)
{
    // nanobind split mode builds this extension against the stable ABI (abi3),
    // which uses CPython's multi-phase module initialization. On some
    // toolchains (observed with VS2026 / clang-cl on Windows) the module
    // execution callback is invoked more than once for the same module object.
    // Re-running the body re-registers the bound types, and nanobind 3.x aborts
    // when it re-adds values to an already-registered enum ("refusing to add
    // duplicate key ..."). Guard against that: the first pass fully populates
    // the module, so any subsequent pass can safely return early.
    if (nb::hasattr(m, "__echosounders_initialized__"))
        return;
    m.attr("__echosounders_initialized__") = true;

    auto tools_module = nb::module_::import_("themachinethatgoesping.tools_nanopy");
    auto navigation_module = nb::module_::import_("themachinethatgoesping.navigation_nanopy");
    auto algorithms_module = nb::module_::import_("themachinethatgoesping.algorithms_nanopy");

    m.doc() =
        "Python module to read, write and process single- and multibeam echosounder data formats";
    m.attr("__version__") = MODULE_VERSION;

    py_filetemplates::init_m_filetemplates(m);

    py_pingtools::init_m_pingtools(m);
    py_simradraw::init_m_simradraw(m);
    py_kongsbergall::init_m_kongsbergall(m);
    py_gsf::init_m_gsf(m);
    py_kmall::init_m_kmall(m);
    py_s7k::init_m_s7k(m);
}

}
}
}