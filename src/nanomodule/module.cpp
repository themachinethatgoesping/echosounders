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
    m.doc() =
        "Python module to read, write and process single- and multibeam echosounder data formats";
    m.attr("__version__") = MODULE_VERSION;

    // nanobind 3.x initializes every extension through CPython's multi-phase
    // module mechanism. On some configurations (observed with VS2026 / clang-cl
    // on Windows) the module body is executed more than once per process, each
    // time with a *fresh* module object, while nanobind's type registry is
    // global to the process. Registering the bindings again would therefore
    // re-add the already bound types, and nanobind aborts the process when an
    // enum value is registered twice ("refusing to add duplicate key ...").
    //
    // Register the bindings exactly once. If the body runs again, mirror the
    // public attributes of the first, fully initialized module into the new
    // module object instead of registering anything a second time (a plain
    // early return would leave that module object empty).
    static PyObject* initialized_module = nullptr;
    if (initialized_module != nullptr)
    {
        nb::dict first_dict = nb::borrow<nb::dict>(PyModule_GetDict(initialized_module));
        for (auto [key, value] : first_dict)
        {
            PyObject* key_obj = key.ptr();
            if (PyUnicode_Check(key_obj) && PyUnicode_GetLength(key_obj) > 0 &&
                PyUnicode_READ_CHAR(key_obj, 0) == '_')
                continue; // keep this module object's own private / dunder attributes
            m.attr(key) = value;
        }
        return;
    }

    auto tools_module = nb::module_::import_("themachinethatgoesping.tools_nanopy");
    auto navigation_module = nb::module_::import_("themachinethatgoesping.navigation_nanopy");
    auto algorithms_module = nb::module_::import_("themachinethatgoesping.algorithms_nanopy");

    py_filetemplates::init_m_filetemplates(m);

    py_pingtools::init_m_pingtools(m);
    py_simradraw::init_m_simradraw(m);
    py_kongsbergall::init_m_kongsbergall(m);
    py_gsf::init_m_gsf(m);
    py_kmall::init_m_kmall(m);
    py_s7k::init_m_s7k(m);

    // Remember the fully initialized module so a possible second (multi-phase)
    // execution can reuse it without re-registering any types. The reference is
    // intentionally kept for the lifetime of the process.
    initialized_module = m.ptr();
    Py_INCREF(initialized_module);
}

}
}
}