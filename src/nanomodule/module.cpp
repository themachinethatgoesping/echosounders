// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#define FORCE_IMPORT_ARRAY // this is needed for xtensor interop when required

#include <nanobind/nanobind.h>

// larger submodules
//#include "py_kongsbergall/module.hpp"
#include "py_filetemplates/module.hpp"
// #include "py_pingtools/module.hpp"
// #include "py_simradraw/module.hpp"
// #include "py_gsf/module.hpp"

#include <themachinethatgoesping/tools_nanobind/ostream_redirect.hpp>

namespace nb = nanobind;

// declare modules
namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {

NB_MODULE(MODULE_NAME, m)
{
    auto tools_module = nb::module_::import_("themachinethatgoesping.algorithms_nanopy");

    m.doc() =
        "Python module to read, write and process single- and multibeam echosounder data formats";
    m.attr("__version__") = MODULE_VERSION;

    //py_filetemplates::init_m_filetemplates(m);

    // py_pingtools::init_m_pingtools(m);
    // py_simradraw::init_m_simradraw(m);
    // py_kongsbergall::init_m_kongsbergall(m);
    // py_gsf::init_m_gsf(m);
}

}
}
}