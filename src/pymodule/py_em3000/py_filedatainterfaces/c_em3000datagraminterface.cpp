// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pyarray.hpp> // Numpy bindings
#include <xtensor/xmath.hpp>          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/em3000/em3000_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/em3000/em3000_types.hpp"
#include "../../../themachinethatgoesping/echosounders/em3000/filedatainterfaces/em3000datagraminterface.hpp"

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"
#include "c_em3000datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatainterfaces {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::em3000;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

template<typename T_FileStream>
void py_create_class_EM3000DatagramInterface(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface
    using T_BaseClass = filedatainterfaces::EM3000DatagramInterface<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass>(m,
                                       CLASS_NAME.c_str(),
                                       DOC(themachinethatgoesping,
                                           echosounders,
                                           em3000,
                                           filedatainterfaces,
                                           EM3000DatagramInterface));

    //----- inherit functions from I_DatagramInterface -----
    EM3000DatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_EM3000DatagramInterface(pybind11::module& m)
{
    py_create_class_EM3000DatagramInterface<std::ifstream>(m, "EM3000DatagramInterface");
    py_create_class_EM3000DatagramInterface<datastreams::MappedFileStream>(
        m, "EM3000DatagramInterface_mapped");
}

}
}
}
}
}