// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pytensor.hpp> // Numpy bindings
          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/filedatainterfaces/simradrawpingdatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_pingdatainterface.hpp"
#include "c_simradrawdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatainterfaces {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, simradraw, filedatainterfaces, SimradRawPingDataInterface

template<typename T_FileStream>
void py_create_class_simradrawpingdatainterfacePerFile(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_filetemplates; // this holds py_i_DatagramInterface and
                                      // py_i_DatagramInterface

    using T_BaseClass = filedatainterfaces::SimradRawPingDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls = py::classh<T_BaseClass>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping,
            echosounders,
            simradraw,
            filedatainterfaces,
            SimradRawPingDataInterfacePerFile))

        //    .def("get_deduplicated_parameters",
        //         &T_BaseClass::get_deduplicated_parameters,
        //         DOC(themachinethatgoesping,
        //             echosounders,
        //             simradraw,
        //             filedatainterfaces,
        //             SimradRawPingDataInterfacePerFile,
        //             get_deduplicated_parameters))

        //
        ;

    //----- inherit functions from I_DatagramInterface -----
    py_filetemplates::py_datainterfaces::py_i_pingdatainterface::
        PingDataInterfacePerFile_add_interface<T_BaseClass>(cls);
    SimradRawDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_simradrawpingdatainterfaceperfile(pybind11::module& m)
{
    static const std::string name        = "SimradRawPingDataInterfacePerFile";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_simradrawpingdatainterfacePerFile<std::ifstream>(
        m, name_stream);
    py_create_class_simradrawpingdatainterfacePerFile<datastreams::MappedFileStream>(
        m, name_mapped);
}

}
}
}
}
}