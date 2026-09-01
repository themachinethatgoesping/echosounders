// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/unordered_map.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/s7k/datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/s7k/s7kfilehandler.hpp"
#include "../../themachinethatgoesping/echosounders/s7k/types.hpp"

#include "module.hpp"

#include "../py_filetemplates/i_inputfilehandler.hpp"
#include "../py_filetemplates/py_datacontainers/datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::s7k;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define DOC_S7KFileHandler(ARG) DOC(themachinethatgoesping, echosounders, s7k, S7KFileHandler, ARG)

template<typename T_FileStream>
void py_create_class_s7kfilehandler(nb::module_& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_inputfilehandler and py_datagramcontainer

    // initialize class
    auto cls = nb::class_<S7KFileHandler<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(themachinethatgoesping, echosounders, s7k, S7KFileHandler));

    //----- inherit functions from I_InputFileHandler -----
    py_i_inputfilehandler::add_default_constructors<S7KFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_open_file_interface<S7KFileHandler<T_FileStream>>(cls);
    py_i_inputfilehandler::add_default_containers<S7KFileHandler<T_FileStream>>(cls);

    // ----- convenience functions -----
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(S7KFileHandler<T_FileStream>);
}

void init_c_s7kfilehandler(nanobind::module_& m)
{
    static const std::string name        = "S7KFileHandler";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_s7kfilehandler<std::ifstream>(m, name_stream);
    py_create_class_s7kfilehandler<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
