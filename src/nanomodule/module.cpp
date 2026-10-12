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
    // --- guard against multi-phase re-exec of this extension ---
    // nanobind uses CPython multi-phase module init, whose exec body may run
    // more than once in a single process. On Windows / CPython 3.13 this module
    // is in fact destroyed and re-exec'd mid-import. Re-running the registration
    // body below re-registers the process-global nanobind types, which is noisy
    // (RuntimeWarnings) and, depending on the nanobind version, fatal (aborts)
    // or raises ("bad cast"). Instead, snapshot the fully-built module namespace
    // after the first successful exec; on any later exec, repopulate the fresh
    // module object from that snapshot and return before re-registering anything.
    // Uses only the stable (abi3) C-API so it works in split mode too.
    static PyObject* module_snapshot = nullptr; // process-global, intentionally leaked
    if (module_snapshot != nullptr)
    {
        PyDict_Update(PyModule_GetDict(m.ptr()), module_snapshot);
        return;
    }

    //auto tools_module = nb::module_::import_("themachinethatgoesping.tools_nanopy");
    //auto navigation_module = nb::module_::import_("themachinethatgoesping.navigation_nanopy");
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

    // Snapshot the fully-built namespace so a later re-exec (see guard above)
    // can repopulate without re-registering. Kept for the process lifetime.
    module_snapshot = PyDict_Copy(PyModule_GetDict(m.ptr()));
}

}
}
}