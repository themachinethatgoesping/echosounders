// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
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

#include "../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simraddatagraminterface.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_datagramcontainer.hpp"
#include "../fileinterfaces/i_datagraminterface.hpp"
#include "c_simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

template<typename T_FileStream>
void py_create_class_SimradDatagramInterface(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_fileinterfaces; // this holds py_i_DatagramInterface and
                                       // py_i_DatagramInterface

    // initialize class
    auto cls = py::class_<SimradDatagramInterface<T_FileStream>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simrad, SimradDatagramInterface));

    //----- inherit functions from I_DatagramInterface -----
    SimradDatagramInterface_add_interface_functions<SimradDatagramInterface<T_FileStream>>(cls);
}


void init_c_simraddatagraminterface(pybind11::module& m)
{

    py_create_class_SimradDatagramInterface<std::ifstream>(m, "SimradDatagramInterface");
    py_create_class_SimradDatagramInterface<MappedFileStream>(m, "SimradDatagramInterface_mapped");
}

}
}
}
}