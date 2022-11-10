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

struct RAW3HeaderFactory
{
    static datagrams::RAW3 from_stream(std::istream& is)
    {
        return datagrams::RAW3::from_stream(is, true);
    }

    static datagrams::RAW3 from_stream(std::istream& is, t_SimradDatagramType type)
    {
        return datagrams::RAW3::from_stream(is, type, true);
    }
};

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
    py_i_InputFile::add_PackageReading<FileRaw<T_FileStream>,
                                       datagrams::t_SimradDatagramVariant,
                                       datagrams::SimradDatagramVariant>(cls);

    //----- iterators -----
    // this makes documentation crash. Ignore for now
    // py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>,
    //                                      datagrams::t_SimradDatagramVariant,
    //                                      datagrams::t_SimradDatagramVariant>(cls, "all");

    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::FIL1>(
        cls, t_SimradDatagramType::FIL1, "FIL1");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::RAW3>(
        cls, t_SimradDatagramType::RAW3, "RAW3");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::MRU0>(
        cls, t_SimradDatagramType::MRU0, "MRU0");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::XML0>(
        cls, t_SimradDatagramType::XML0, "XML0");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::NME0>(
        cls, t_SimradDatagramType::NME0, "NME0");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::TAG0>(
        cls, t_SimradDatagramType::TAG0, "TAG0");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::RAW3>(
        cls, t_SimradDatagramType::RAW3, "RAW3");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::RAW3, RAW3HeaderFactory>(
        cls, t_SimradDatagramType::RAW3, "RAW3_header");

    // TODO: move this intp i_inptufile (after adding Pings to the inputfile interface)
    py_i_PingContainer::add_PingContainer<FileRaw<T_FileStream>>(cls, "Pings");

    //----- iterators via () operator -----
    cls.def(
        "__call__",
        [](const FileRaw<T_FileStream>& self, long index_min, long index_max, long index_step) {
            return py::cast(self.template get_iterator<datagrams::t_SimradDatagramVariant,
                                                       datagrams::SimradDatagramVariant>(
                index_min, index_max, index_step));
        },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<long>::max(),
        py::arg("index_step") = 1);
    cls.def(
        "__call__",
        [](const FileRaw<T_FileStream>& self,
           t_SimradDatagramType         type,
           long                         index_min,
           long                         index_max,
           long                         index_step) {
            switch (type)
            {
                case t_SimradDatagramType::MRU0:
                    return py::cast(self.template get_iterator<datagrams::MRU0>(
                        type, index_min, index_max, index_step));
                case t_SimradDatagramType::NME0:
                    return py::cast(self.template get_iterator<datagrams::NME0>(
                        type, index_min, index_max, index_step));
                case t_SimradDatagramType::XML0:
                    return py::cast(self.template get_iterator<datagrams::XML0>(
                        type, index_min, index_max, index_step));
                case t_SimradDatagramType::TAG0:
                    return py::cast(self.template get_iterator<datagrams::TAG0>(
                        type, index_min, index_max, index_step));
                case t_SimradDatagramType::FIL1:
                    return py::cast(self.template get_iterator<datagrams::FIL1>(
                        type, index_min, index_max, index_step));
                case t_SimradDatagramType::RAW3:
                    return py::cast(self.template get_iterator<datagrams::RAW3>(
                        type, index_min, index_max, index_step));
                default:
                    return py::cast(self.template get_iterator<datagrams::SimradUnknown>(
                        type, index_min, index_max, index_step));
            }
        },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator_3),
        py::arg("datagram_type"),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<long>::max(),
        py::arg("index_step") = 1);
    cls.def(
        "headers",
        [](const FileRaw<T_FileStream>& self, long index_min, long index_max, long index_step) {
            return py::cast(self.template get_iterator<datagrams::SimradDatagram>(
                index_min, index_max, index_step));
        },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<long>::max(),
        py::arg("index_step") = 1);
    cls.def(
        "headers",
        [](const FileRaw<T_FileStream>& self,
           t_SimradDatagramType         type,
           long                         index_min,
           long                         index_max,
           long                         index_step) {
            return py::cast(self.template get_iterator<datagrams::SimradDatagram>(
                type, index_min, index_max, index_step));
        },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator_3),
        py::arg("datagram_type"),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<long>::max(),
        py::arg("index_step") = 1);
    cls.def(
        "raw",
        [](const FileRaw<T_FileStream>& self, long index_min, long index_max, long index_step) {
            return py::cast(self.template get_iterator<datagrams::SimradUnknown>(
                index_min, index_max, index_step));
        },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<long>::max(),
        py::arg("index_step") = 1);
    cls.def(
        "raw",
        [](const FileRaw<T_FileStream>& self,
           t_SimradDatagramType         type,
           long                         index_min,
           long                         index_max,
           long                         index_step) {
            return py::cast(self.template get_iterator<datagrams::SimradUnknown>(
                type, index_min, index_max, index_step));
        },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator_3),
        py::arg("datagram_type"),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<long>::max(),
        py::arg("index_step") = 1);
    cls.def("navigation",
            py::overload_cast<>(&FileRaw<T_FileStream>::navigation, py::const_),
            DOC(themachinethatgoesping, echosounders, simrad, FileRaw, navigation));
    cls.def("pings",
            py::overload_cast<>(&FileRaw<T_FileStream>::pings, py::const_),
            DOC(themachinethatgoesping, echosounders, simrad, FileRaw, pings));
    cls.def("pings",
            py::overload_cast<long, long, long>(&FileRaw<T_FileStream>::pings, py::const_),
            DOC(themachinethatgoesping, echosounders, simrad, FileRaw, pings_2),
            py::arg("index_min")  = 0,
            py::arg("index_max")  = std::numeric_limits<long>::max(),
            py::arg("index_step") = 1);
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
    using py_fileinterfaces::py_i_InputFileIterator::create_IteratorTypes;
    using py_fileinterfaces::py_i_PingContainer::create_PingContainerType;

    create_IteratorTypes<datagrams::SimradDatagram, t_SimradDatagramType>(m,
                                                                          "FileRawIterator_Header");
    create_IteratorTypes<datagrams::SimradUnknown, t_SimradDatagramType>(m,
                                                                         "FileRawIterator_Unknown");
    create_IteratorTypes<datagrams::MRU0, t_SimradDatagramType>(m, "FileRawIterator_MRU0");
    create_IteratorTypes<datagrams::TAG0, t_SimradDatagramType>(m, "FileRawIterator_TAG0");
    create_IteratorTypes<datagrams::FIL1, t_SimradDatagramType>(m, "FileRawIterator_FIL1");
    create_IteratorTypes<datagrams::RAW3, t_SimradDatagramType>(m, "FileRawIterator_RAW3");
    create_IteratorTypes<datagrams::RAW3, t_SimradDatagramType, RAW3HeaderFactory>(
        m, "FileRawIterator_RAW3_header");
    create_IteratorTypes<datagrams::XML0, t_SimradDatagramType>(m, "FileRawIterator_XML0");
    create_IteratorTypes<datagrams::NME0, t_SimradDatagramType>(m, "FileRawIterator_NME0");
    create_IteratorTypes<datagrams::t_SimradDatagramVariant,
                         t_SimradDatagramType,
                         datagrams::SimradDatagramVariant>(m, "FileRawIterator_Variant");

    create_PingContainerType<SimradPing<std::ifstream>>(m, "SimradPingContainer");
    create_PingContainerType<SimradPing<MappedFileStream>>(m, "SimradPingContainer_mapped");

    py_create_class_FileRaw<std::ifstream>(m, "FileRaw");
    py_create_class_FileRaw<MappedFileStream>(m, "FileRaw_mapped");
}

}
}
}
}