// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>

#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings
          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/filedatainterfaces/simradrawdatagraminterface.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/types.hpp"

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"
#include "c_simradrawdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatainterfaces {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simradraw;

template<typename T_FileStream>
void py_create_class_SimradRawDatagramInterface(nb::module_& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces; // this holds py_i_DatagramInterface and
                                                         // py_i_DatagramInterface
    using T_BaseClass = filedatainterfaces::SimradRawDatagramInterface<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(m,
                                       CLASS_NAME.c_str(),
                                       DOC(themachinethatgoesping,
                                           echosounders,
                                           simradraw,
                                           filedatainterfaces,
                                           SimradRawDatagramInterface));

    //----- inherit functions from I_DatagramInterface -----
    SimradRawDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_SimradRawDatagramInterface(nanobind::module_& m)
{
    static const std::string name        = "SimradRawDatagramInterface";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_SimradRawDatagramInterface<std::ifstream>(m, name_stream);
    py_create_class_SimradRawDatagramInterface<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}