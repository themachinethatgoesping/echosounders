// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <xtensor/xmath.hpp> // xtensor import for the C++ universal functions
#define FORCE_IMPORT_ARRAY
#include <xtensor-python/pyarray.hpp> // Numpy bindings

#include <chrono>

#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/ek60_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/fileraw.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_inputfile.hpp"
#include "../fileinterfaces/i_inputfileiterator.hpp"

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define CLASS_FILERAW(T_FILE_RAW, CLASS_NAME)                                                      \
    py::class_<T_FILE_RAW>(                                                                             \
            m, CLASS_NAME, DOC(themachinethatgoesping, echosounders, simrad, FileRaw))                  \
        /* constructors */                                                                              \
        __INPUTFILE_DEFAULT_CONSTRUCTORS__(T_FILE_RAW)                                                  \
        /* inputfile interface */                                                                       \
        __INPUTFILE_INTERFACE__(T_FILE_RAW)                                                             \
        /* package reading */                                                                           \
        __INPUTFILE_PACKAGE_READING__(                                                                  \
            T_FILE_RAW, datagrams::t_EK60_DatagramVariant, datagrams::EK60_DatagramVariant)             \
                                                                                                        \
        /* iterators */                                                                                 \
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::FIL1, "FIL1")            \
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::MRU0, "MRU0")            \
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::NME0, "NME0")            \
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::RAW3, "RAW3")            \
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::XML0, "XML0")            \
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::TAG0, "TAG0")            \
        .def("__call__", [](const T_FILE_RAW& self, bool read_content) {                                 \
            if(!read_content)                                                                             \
                return py::cast(self.get_iterator<datagrams::EK60_Datagram>());                         \
            return py::cast(self.get_iterator<datagrams::t_EK60_DatagramVariant, datagrams::EK60_DatagramVariant>());                    \
            },                                                                                          \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator),       \
            py::arg("read_content") = true                                                              \
            )                                                                                           \
        .def("__call__", [](const T_FILE_RAW& self,t_EK60_DatagramType type, bool read_content) {        \
            if(!read_content)                                                                             \
                return py::cast(self.get_iterator<datagrams::EK60_Datagram>(type));                     \
            switch (type)                                                                               \
            {                                                                                           \
            case t_EK60_DatagramType::FIL1: [[fallthrough]];                                            \
            case t_EK60_DatagramType::MRU0: [[fallthrough]];                                            \
            case t_EK60_DatagramType::NME0: [[fallthrough]];                                            \
            case t_EK60_DatagramType::RAW3: [[fallthrough]];                                            \
            case t_EK60_DatagramType::XML0: [[fallthrough]];                                            \
            case t_EK60_DatagramType::TAG0: [[fallthrough]];                                            \
            default:                                                                                    \
            return py::cast(self.get_iterator<datagrams::EK60_Unknown>(type));                          \
            }                                                                                           \
            },                                                                                          \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator_2),     \
            py::arg("datagram_type"),                                                                   \
            py::arg("read_content") = true                                                              \
            )                                                                                           \
                                                                                                        \
        /* default copy functions */                                                                    \
        /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/                                               \
        /* default binary functions*/                                                                   \
        /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/                                             \
        /* default printing functions */                                                                \
        __PYCLASS_DEFAULT_PRINTING__(T_FILE_RAW)                                                        \
        /* end T_FILE_RAW */

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

void test_speed(const FileRaw<MappedFileStream>& ifi, t_EK60_DatagramType type)
{
    // get current time
    auto                    start = std::chrono::high_resolution_clock::now();
    datagrams::EK60_Unknown a;

    auto it  = ifi.get_iterator<datagrams::EK60_Unknown>(type);
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

void test_speed_header(const FileRaw<MappedFileStream>& ifi, t_EK60_DatagramType type)
{
    // get current time
    auto                    start = std::chrono::high_resolution_clock::now();
    datagrams::EK60_Unknown a;

    auto it  = ifi.get_iterator<datagrams::EK60_Datagram>(type);
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

void init_c_fileraw(pybind11::module& m)
{
    xt::import_numpy(); // import numpy for xtensor (otherwise there will be weird segfaults)

    ADD_ITERATOR_TYPES(m,
                       "FileRawIterator_Header",
                       datagrams::EK60_Datagram,
                       t_EK60_DatagramType,
                       datagrams::EK60_Datagram);
    ADD_ITERATOR_TYPES(m,
                       "FileRawIterator_Unknown",
                       datagrams::EK60_Unknown,
                       t_EK60_DatagramType,
                       datagrams::EK60_Unknown);
    ADD_ITERATOR_TYPES(m,
                       "FileRawIterator_Variant",
                       datagrams::t_EK60_DatagramVariant,
                       t_EK60_DatagramType,
                       datagrams::EK60_DatagramVariant);

    auto c_streamed = CLASS_FILERAW(FileRaw<std::ifstream>, "FileRaw");
    auto c_mapped   = CLASS_FILERAW(FileRaw<MappedFileStream>, "FileRaw_mapped");

    m.def("test_speed", &test_speed, py::call_guard<py::scoped_ostream_redirect>());
    m.def("test_speed_all", &test_speed_all, py::call_guard<py::scoped_ostream_redirect>());
    m.def("test_speed_header", &test_speed_header, py::call_guard<py::scoped_ostream_redirect>());
    // m.def("test_speed", py::overload_cast<const FileRaw<MappedFileStream>&, t_EK60_DatagramType
    // >(test_speed),
    //     py::call_guard<py::scoped_ostream_redirect>());

    // c_mapped.def(
    //     "__getitem__",
    //     [](const FileRaw<MappedFileStream>& self, const py::slice& slice) {
    //         py::print("slice", slice);
    //         //slice.begin();
    //         //return self.get_iterator<datagrams::EK60_Datagram>(slice);
    //         // if (!read_content)
    //         //     return py::cast(self.get_iterator<datagrams::EK60_Datagram>());
    //         // return py::cast(self.get_iterator<datagrams::t_EK60_DatagramVariant,
    //         //                                   datagrams::EK60_DatagramVariant>());
    //     },
    //     DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator),
    //     py::arg("slice") = true);
}
