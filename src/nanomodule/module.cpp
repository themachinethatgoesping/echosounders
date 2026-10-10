// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#define FORCE_IMPORT_ARRAY // this is needed for xtensor interop when required

#include <cstdio>
#include <string>

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
    // ===================== TEMPORARY WINDOWS DIAGNOSTIC =====================
    // Counts how often this module's exec body runs in the process and prints
    // the Python import stack each time. A second run proves the extension is
    // being re-exec'd (re-registering types -> fatal under nanobind 3.x).
    // Remove once the Windows double-exec is understood.
    {
        static int echo_exec_count = 0;
        ++echo_exec_count;
        std::string modname = "?";
        try {
            modname = nb::cast<std::string>(m.attr("__name__"));
        } catch (...) {
        }
        std::fprintf(stderr,
                     "\n[ECHO_DIAG] echosounders_nanopy exec #%d  module=%p  __name__=%s\n",
                     echo_exec_count,
                     (void*)m.ptr(),
                     modname.c_str());
        std::fflush(stderr);
        try {
            nb::object stack = nb::module_::import_("traceback").attr("format_stack")();
            for (nb::handle line : stack)
                std::fprintf(stderr, "[ECHO_DIAG]   %s", nb::cast<std::string>(line).c_str());
        } catch (...) {
            std::fprintf(stderr, "[ECHO_DIAG]   (python stack unavailable)\n");
        }
        std::fflush(stderr);
    }
    // =================== END TEMPORARY WINDOWS DIAGNOSTIC ===================

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
}

}
}
}