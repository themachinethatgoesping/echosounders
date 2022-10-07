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
#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/fileraw.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
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

void test_speed_all(const FileRaw<MappedFileStream>& ifi)
{
    // get current time
    auto                     start = std::chrono::high_resolution_clock::now();
    datagrams::SimradUnknown a;

    auto it  = ifi.get_iterator<datagrams::SimradUnknown>();
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0., double(it.size()), "test reading");

    double t = 0;
    for (size_t i = 0; i < it.size(); ++i)
    {
        auto dg = it.at(long(i));
        t += dg.get_timestamp();
        prg.tick();
    }

    prg.close(fmt::format(
        "time: {:3f}ms",
        std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - start)
            .count()));
}

template<typename T_DatagramType>
void test_speed_content(const FileRaw<MappedFileStream>& ifi, t_SimradDatagramType type)
{
    // get current time
    auto start = std::chrono::high_resolution_clock::now();

    auto it  = ifi.get_iterator<T_DatagramType>(type);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0., double(it.size()), "test reading");

    // double t = 0;
    for (size_t i = 0; i < it.size(); ++i)
    {
        auto dg = it.at(long(i));
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

    auto it  = ifi.get_iterator<datagrams::NME0>(t_SimradDatagramType::NME0);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0., double(it.size()), "test reading");

    using namespace themachinethatgoesping::navigation::nmea_0183;

    // double t = 0;
    for (long i = 0; i < long(it.size()); ++i)
    {
        NMEA_0183_type nmea_sentence = it.at(i).decode();

        if (std::holds_alternative<NMEA_ZDA>(nmea_sentence))
        {
            std::get<NMEA_ZDA>(nmea_sentence).to_timestamp();
        }
        else if (std::holds_alternative<NMEA_GGA>(nmea_sentence))
        {
            std::get<NMEA_GGA>(nmea_sentence).get_latitude();
            std::get<NMEA_GGA>(nmea_sentence).get_longitude();
        }
        else if (std::holds_alternative<NMEA_GLL>(nmea_sentence))
        {
            std::get<NMEA_GLL>(nmea_sentence).get_latitude();
            std::get<NMEA_GLL>(nmea_sentence).get_longitude();
        }
        else if (std::holds_alternative<NMEA_RMC>(nmea_sentence))
        {
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

    auto it  = ifi.get_iterator<datagrams::XML0>(t_SimradDatagramType::XML0);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0., double(it.size()), "test reading");

    using namespace themachinethatgoesping::navigation::nmea_0183;

    // double t = 0;
    for (long i = 0; i < long(it.size()); ++i)
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

void test_speed_type(const FileRaw<MappedFileStream>& ifi, t_SimradDatagramType type)
{
    switch (type)
    {
        case t_SimradDatagramType::MRU0:
            test_speed_content<datagrams::MRU0>(ifi, type);
            break;
        case t_SimradDatagramType::NME0:
            test_speed_content<datagrams::NME0>(ifi, type);
            break;
        case t_SimradDatagramType::XML0:
            test_speed_content<datagrams::XML0>(ifi, type);
            break;
        case t_SimradDatagramType::TAG0:
            test_speed_content<datagrams::TAG0>(ifi, type);
            break;
        case t_SimradDatagramType::FIL1:
            test_speed_content<datagrams::FIL1>(ifi, type);
            break;
        case t_SimradDatagramType::RAW3:
            test_speed_content<datagrams::RAW3>(ifi, type);
            break;
        default:
            test_speed_content<datagrams::SimradUnknown>(ifi, type);
            break;
    }
}

void test_speed_header(const FileRaw<MappedFileStream>& ifi, t_SimradDatagramType type)
{
    // get current time
    auto                     start = std::chrono::high_resolution_clock::now();
    datagrams::SimradUnknown a;

    auto it  = ifi.get_iterator<datagrams::SimradDatagram>(type);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0., double(it.size()), "test reading");

    // double t = 0;
    for (long i = 0; i < long(it.size()); ++i)
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

    // add python iterator classes
    using py_fileinterfaces::py_i_InputFileIterator::create_IteratorTypes;

    create_IteratorTypes<datagrams::SimradDatagram, t_SimradDatagramType>(m,
                                                                          "FileRawIterator_Header");
    create_IteratorTypes<datagrams::SimradUnknown, t_SimradDatagramType>(m,
                                                                         "FileRawIterator_Unknown");
    create_IteratorTypes<datagrams::MRU0, t_SimradDatagramType>(m, "FileRawIterator_MRU0");
    create_IteratorTypes<datagrams::TAG0, t_SimradDatagramType>(m, "FileRawIterator_TAG0");
    create_IteratorTypes<datagrams::FIL1, t_SimradDatagramType>(m, "FileRawIterator_FIL1");
    create_IteratorTypes<datagrams::RAW3, t_SimradDatagramType>(m, "FileRawIterator_RAW3");
    create_IteratorTypes<datagrams::RAW3, t_SimradDatagramType, RAW3HeaderFactory>(m, "FileRawIterator_RAW3_header");
    create_IteratorTypes<datagrams::XML0, t_SimradDatagramType>(m, "FileRawIterator_XML0");
    create_IteratorTypes<datagrams::NME0, t_SimradDatagramType>(m, "FileRawIterator_NME0");
    create_IteratorTypes<datagrams::t_SimradDatagramVariant,
                         t_SimradDatagramType,
                         datagrams::SimradDatagramVariant>(m, "FileRawIterator_Variant");

    py_create_class_FileRaw<std::ifstream>(m, "FileRaw");
    py_create_class_FileRaw<MappedFileStream>(m, "FileRaw_mapped");

    m.def("test_speed_raw",
          &test_speed_content<datagrams::SimradUnknown>,
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