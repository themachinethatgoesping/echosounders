// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor/xmath.hpp> // xtensor import for the C++ universal functions
#define FORCE_IMPORT_ARRAY
#include <xtensor-python/pyarray.hpp> // Numpy bindings

#include <chrono>

#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>
#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/ek60_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/ek60_types.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/fileraw.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_inputfile.hpp"
#include "../fileinterfaces/i_inputfileiterator.hpp"

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
    py_i_InputFile::add_PackageReading<FileRaw<T_FileStream>,
                                       datagrams::t_EK60_DatagramVariant,
                                       datagrams::EK60_DatagramVariant>(cls);

    //----- iterators -----
    // this makes documentation crash. Ignore for now
    // py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>,
    //                                      datagrams::t_EK60_DatagramVariant,
    //                                      datagrams::t_EK60_DatagramVariant>(cls, "all");

    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::EK60_Unknown>(
        cls, t_EK60_DatagramType::FIL1, "FIL1");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::EK80_MRU0>(
        cls, t_EK60_DatagramType::MRU0, "MRU0");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::EK60_Unknown>(
        cls, t_EK60_DatagramType::XML0, "XML0");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::EK60_NME0>(
        cls, t_EK60_DatagramType::NME0, "NME0");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::EK60_Unknown>(
        cls, t_EK60_DatagramType::TAG0, "TAG0");
    py_i_InputFileIterator::add_Iterator<FileRaw<T_FileStream>, datagrams::EK60_Unknown>(
        cls, t_EK60_DatagramType::RAW3, "RAW3");

    //----- iterators via () operator -----
    cls.def(
        "__call__",
        [](const FileRaw<T_FileStream>& self, long index_min, long index_max, long index_step) {
            return py::cast(self.template get_iterator<datagrams::t_EK60_DatagramVariant,
                                                       datagrams::EK60_DatagramVariant>(
                index_min, index_max, index_step));
        },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<long>::max(),
        py::arg("index_step") = 1);
    cls.def(
        "__call__",
        [](const FileRaw<T_FileStream>& self,
           t_EK60_DatagramType          type,
           long                         index_min,
           long                         index_max,
           long                         index_step) {
            switch (type)
            {
                case t_EK60_DatagramType::MRU0:
                    return py::cast(self.template get_iterator<datagrams::EK80_MRU0>(
                        type, index_min, index_max, index_step));
                case t_EK60_DatagramType::NME0:
                    return py::cast(self.template get_iterator<datagrams::EK60_NME0>(
                        type, index_min, index_max, index_step));
                case t_EK60_DatagramType::XML0:
                    return py::cast(self.template get_iterator<datagrams::EK80_XML0>(
                        type, index_min, index_max, index_step));
                case t_EK60_DatagramType::FIL1:
                    [[fallthrough]];
                case t_EK60_DatagramType::RAW3:
                    [[fallthrough]];
                case t_EK60_DatagramType::TAG0:
                    [[fallthrough]];
                default:
                    return py::cast(self.template get_iterator<datagrams::EK60_Unknown>(
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
            return py::cast(self.template get_iterator<datagrams::EK60_Datagram>(
                index_min, index_max, index_step));
        },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<long>::max(),
        py::arg("index_step") = 1);
    cls.def(
        "headers",
        [](const FileRaw<T_FileStream>& self,
           t_EK60_DatagramType          type,
           long                         index_min,
           long                         index_max,
           long                         index_step) {
            return py::cast(self.template get_iterator<datagrams::EK60_Datagram>(
                type, index_min, index_max, index_step));
        },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator_3),
        py::arg("datagram_type"),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<long>::max(),
        py::arg("index_step") = 1);

    // ----- ping convinience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(FileRaw<T_FileStream>);
}

void test_speed_all(const FileRaw<MappedFileStream>& ifi)
{
    // get current time
    auto                    start = std::chrono::high_resolution_clock::now();
    datagrams::EK60_Unknown a;

    auto it  = ifi.get_iterator<datagrams::EK60_Unknown>();
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0, it.size(), "test reading");

    double t = 0;
    for (size_t i = 0; i < it.size(); ++i)
    {
        auto dg = it.at(i);
        t += dg.get_timestamp();
        prg.tick();
    }

    prg.close(fmt::format(
        "time: {:3f}ms",
        std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - start)
            .count()));
}

template<typename T_DatagramType>
void test_speed_content(const FileRaw<MappedFileStream>& ifi, t_EK60_DatagramType type)
{
    // get current time
    auto start = std::chrono::high_resolution_clock::now();

    auto it  = ifi.get_iterator<T_DatagramType>(type);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0, it.size(), "test reading");

    // double t = 0;
    for (size_t i = 0; i < it.size(); ++i)
    {
        auto dg = it.at(i);
        // t += dg.get_timestamp();
        prg.tick();
    }

    prg.close(fmt::format(
        "time: {:3f}ms",
        std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - start)
            .count()));
}

void test_speed_decode_nmea(const FileRaw<MappedFileStream>& ifi)
{
    // get current time
    auto start = std::chrono::high_resolution_clock::now();

    auto it  = ifi.get_iterator<datagrams::EK60_NME0>(t_EK60_DatagramType::NME0);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0, it.size(), "test reading");

    using namespace themachinethatgoesping::navigation::nmea_0183;

    // double t = 0;
    for (size_t i = 0; i < it.size(); ++i)
    {
         NMEA_0183_type nmea_sentence = it.at(i).decode();

        if (std::holds_alternative<NMEA_ZDA>(nmea_sentence)){
            std::get<NMEA_ZDA>(nmea_sentence).to_timestamp();
        }
        else if (std::holds_alternative<NMEA_GGA>(nmea_sentence)){
            std::get<NMEA_GGA>(nmea_sentence).get_latitude();
            std::get<NMEA_GGA>(nmea_sentence).get_longitude();
        }
        else if (std::holds_alternative<NMEA_GLL>(nmea_sentence)){
            std::get<NMEA_GLL>(nmea_sentence).get_latitude();
            std::get<NMEA_GLL>(nmea_sentence).get_longitude();
        }
        else if (std::holds_alternative<NMEA_RMC>(nmea_sentence)){
            std::get<NMEA_RMC>(nmea_sentence).get_latitude();
            std::get<NMEA_RMC>(nmea_sentence).get_longitude();
        }

        prg.tick();
    }

    prg.close(fmt::format(
        "time: {:3f}ms",
        std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - start)
            .count()));
}

void test_speed_decode_xml(const FileRaw<MappedFileStream>& ifi, int level = 10)
{
    // get current time
    auto start = std::chrono::high_resolution_clock::now();

    auto it  = ifi.get_iterator<datagrams::EK80_XML0>(t_EK60_DatagramType::XML0);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0, it.size(), "test reading");

    using namespace themachinethatgoesping::navigation::nmea_0183;

    // double t = 0;
    for (size_t i = 0; i < it.size(); ++i)
    {
         auto xml = it.at(i);

         switch (level)
         {
         case 0:
            break;
        case 1:
            xml.get_xml_datagram_type();
            break;
        case 2:
            [[fallthrough]];
        case 3:
            xml.parse_xml(level);
            break;
        case 4:
            xml.raw();
            break;
         
         default:
            xml.decode();
            break;
         }
         


        prg.tick();
    }

    prg.close(fmt::format(
        "time: {:3f}ms",
        std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - start)
            .count()));
}

void test_speed_type(const FileRaw<MappedFileStream>& ifi, t_EK60_DatagramType type)
{
    switch (type)
    {
        case t_EK60_DatagramType::MRU0:
            test_speed_content<datagrams::EK80_MRU0>(ifi, type);
            break;
        case t_EK60_DatagramType::NME0:
            test_speed_content<datagrams::EK60_NME0>(ifi, type);
            break;
        case t_EK60_DatagramType::XML0:
            test_speed_content<datagrams::EK80_XML0>(ifi, type);
            break;
        case t_EK60_DatagramType::FIL1:
            [[fallthrough]];
        case t_EK60_DatagramType::RAW3:
            [[fallthrough]];
        case t_EK60_DatagramType::TAG0:
            [[fallthrough]];
        default:
            test_speed_content<datagrams::EK60_Unknown>(ifi, type);
            break;
    }
}

void test_speed_header(const FileRaw<MappedFileStream>& ifi, t_EK60_DatagramType type)
{
    // get current time
    auto                    start = std::chrono::high_resolution_clock::now();
    datagrams::EK60_Unknown a;

    auto it  = ifi.get_iterator<datagrams::EK60_Datagram>(type);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0, it.size(), "test reading");

    // double t = 0;
    for (size_t i = 0; i < it.size(); ++i)
    {
        auto dg = it.at(i);
        // t += dg.get_timestamp();
        prg.tick();
    }

    prg.close(fmt::format(
        "time: {:3f}ms",
        std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - start)
            .count()));
}

void init_c_fileraw(pybind11::module& m)
{
    xt::import_numpy(); // import numpy for xtensor (otherwise there will be weird segfaults)

    // add python iterator classes
    using py_fileinterfaces::py_i_InputFileIterator::create_IteratorTypes;

    create_IteratorTypes<datagrams::EK60_Datagram, t_EK60_DatagramType>(m,
                                                                        "FileRawIterator_Header");
    create_IteratorTypes<datagrams::EK60_Unknown, t_EK60_DatagramType>(m,
                                                                       "FileRawIterator_Unknown");
    create_IteratorTypes<datagrams::EK80_MRU0, t_EK60_DatagramType>(m, "FileRawIterator_MRU0");
    create_IteratorTypes<datagrams::EK80_XML0, t_EK60_DatagramType>(m, "FileRawIterator_XML0");
    create_IteratorTypes<datagrams::EK60_NME0, t_EK60_DatagramType>(m, "FileRawIterator_NME0");
    create_IteratorTypes<datagrams::t_EK60_DatagramVariant,
                         t_EK60_DatagramType,
                         datagrams::EK60_DatagramVariant>(m, "FileRawIterator_Variant");

    py_create_class_FileRaw<std::ifstream>(m, "FileRaw");
    py_create_class_FileRaw<MappedFileStream>(m, "FileRaw_mapped");

    m.def("test_speed_raw",
          &test_speed_content<datagrams::EK60_Unknown>,
          py::call_guard<py::scoped_ostream_redirect>());
    m.def("test_speed_type", &test_speed_type, py::call_guard<py::scoped_ostream_redirect>());
    m.def("test_speed_decode_nmea",
          &test_speed_decode_nmea,
          py::call_guard<py::scoped_ostream_redirect>());
    m.def("test_speed_decode_xml",
          &test_speed_decode_xml,
          py::call_guard<py::scoped_ostream_redirect>(),
          py::arg("mapped_file_stream"),
          py::arg("level") = 10);
    m.def("test_speed_raw_all", &test_speed_all, py::call_guard<py::scoped_ostream_redirect>());
    m.def("test_speed_header", &test_speed_header, py::call_guard<py::scoped_ostream_redirect>());
}

}
}
}
}