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

#include "../../../themachinethatgoesping/echosounders/simrad/filedatainterfaces/simradpingdatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_pingdatainterface.hpp"
#include "c_simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_filedatainterfaces {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, simrad, filedatainterfaces, SimradPingDataInterface

template<typename T_FileStream>
void py_create_class_simradpingdatainterfacePerFile(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_DatagramInterface and
                                      // py_i_DatagramInterface

    using T_BaseClass = filedatainterfaces::SimradPingDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls =
        py::class_<T_BaseClass, std::shared_ptr<T_BaseClass>>(m,
                                                              CLASS_NAME.c_str(),
                                                              DOC(themachinethatgoesping,
                                                                  echosounders,
                                                                  simrad,
                                                                  filedatainterfaces,
                                                                  SimradPingDataInterfacePerFile))

            .def("get_deduplicated_parameters",
                 &T_BaseClass::get_deduplicated_parameters,
                 DOC(themachinethatgoesping,
                     echosounders,
                     simrad,
                     filedatainterfaces,
                     SimradPingDataInterfacePerFile,
                     get_deduplicated_parameters))

        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_filetemplates::py_datainterfaces::py_i_pingdatainterface::
        PingDataInterfacePerFile_add_interface<T_BaseClass>(cls);
    SimradDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_simradpingdatainterfaceperfile(pybind11::module& m)
{

    py_create_class_simradpingdatainterfacePerFile<std::ifstream>(m,
                                                                  "SimradPingDataInterfacePerFile");
    py_create_class_simradpingdatainterfacePerFile<datastreams::MappedFileStream>(
        m, "SimradPingDataInterfacePerFile_mapped");
}

}
}
}
}
}