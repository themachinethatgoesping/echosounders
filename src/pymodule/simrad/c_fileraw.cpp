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

#include "../../themachinethatgoesping/echosounders/simrad/fileraw.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_inputfile.hpp"
#include "../fileinterfaces/i_inputfileiterator.hpp"
#include "../fileinterfaces/i_pingcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

//#define CLASS_FILERAW(FileRaw<T_FileStream>, CLASS_NAME)
template<typename T_FileStream>
void py_create_class_FileRaw(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_fileinterfaces; // this holds py_i_InputFile and py_i_InputFileIterator

    // initialize class
    auto cls = py::class_<FileRaw<T_FileStream>>(
        m, CLASS_NAME.c_str(), DOC(themachinethatgoesping, echosounders, simrad, FileRaw));

    //----- inherit functions from I_InputFile -----
    py_i_InputFile::add_DefaultConstructors(cls);
    py_i_InputFile::add_FileOpenInterface<FileRaw<T_FileStream>>(cls);
    py_i_InputFile::add_DefaultContainers<FileRaw<T_FileStream>>(cls);
    // py_i_InputFile::add_PackageReading<FileRaw<T_FileStream>,
    //                                    datagrams::t_SimradDatagramVariant,
    //                                    datagrams::SimradDatagramVariant>(cls);

    //----- containers  -----


    // TODO: move this intp i_inptufile (after adding Pings to the inputfile interface)
    py_i_PingContainer::add_PingContainer<FileRaw<T_FileStream>>(cls, "Pings");

    //----- iterators via () operator -----
    
    cls.def("navigation",
            py::overload_cast<>(&FileRaw<T_FileStream>::navigation, py::const_),
            DOC(themachinethatgoesping, echosounders, simrad, FileRaw, navigation));
    cls.def("pings",
            py::overload_cast<>(&FileRaw<T_FileStream>::pings, py::const_),
            DOC(themachinethatgoesping, echosounders, simrad, FileRaw, pings));
    cls.def("pings",
            py::overload_cast<long, long, long>(&FileRaw<T_FileStream>::pings, py::const_),
            DOC(themachinethatgoesping, echosounders, simrad, FileRaw, pings_2),
            py::arg("start")  = 0,
            py::arg("end")  = std::numeric_limits<long>::max(),
            py::arg("step") = 1);
    cls.def("pings",
            py::overload_cast<const std::string&>(&FileRaw<T_FileStream>::pings, py::const_),
            DOC(themachinethatgoesping, echosounders, simrad, FileRaw, pings_3),
            py::arg("channel_id"));
    cls.def("channel_ids",
            &FileRaw<T_FileStream>::channel_ids,
            DOC(themachinethatgoesping, echosounders, simrad, FileRaw, channel_ids));

    cls.def("get_navigation_interpolators",
            &FileRaw<T_FileStream>::get_navigation_interpolators,
            DOC(themachinethatgoesping, echosounders, simrad, FileRaw, navigation_interpolators));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(FileRaw<T_FileStream>);
}

void init_c_fileraw(pybind11::module& m)
{

    // add python iterator classes
    using py_fileinterfaces::py_i_PingContainer::create_PingContainerType;

    create_PingContainerType<SimradPing<std::ifstream>>(m, "SimradPingContainer");
    create_PingContainerType<SimradPing<MappedFileStream>>(m, "SimradPingContainer_mapped");

    py_create_class_FileRaw<std::ifstream>(m, "FileRaw");
    py_create_class_FileRaw<MappedFileStream>(m, "FileRaw_mapped");
}

}
}
}
}