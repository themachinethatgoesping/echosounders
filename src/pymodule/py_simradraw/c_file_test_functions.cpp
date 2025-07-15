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

#include "../../themachinethatgoesping/echosounders/simradraw/simradrawfilehandler.hpp"
#include "../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simradraw/types.hpp"

#include "module.hpp"

#include "../py_filetemplates/i_inputfilehandler.hpp"
#include "../py_filetemplates/py_datacontainers/datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

void test_speed_all(const SimradRawFileHandler<datastreams::MappedFileStream>& ifi)
{
    // get current time
    auto                     start = std::chrono::high_resolution_clock::now();
    datagrams::SimradRawUnknown a;

    auto it  = ifi.datagram_interface().datagrams<datagrams::SimradRawUnknown>();
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0., double(it.size()), "test reading");

    double t = 0;
    for (size_t i = 0; i < it.size(); ++i)
    {
        auto dg = it.at(int64_t(i));
        t += dg.get_timestamp();
        prg.tick();
    }

    prg.close(fmt::format(
        "time: {:3f}ms",
        std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - start)
            .count()));
}

template<typename T_DatagramType>
void test_speed_content(const SimradRawFileHandler<datastreams::MappedFileStream>& ifi,
                        t_SimradRawDatagramIdentifier                          type)
{
    // get current time
    auto start = std::chrono::high_resolution_clock::now();

    auto it  = ifi.datagram_interface().datagrams<T_DatagramType>(type);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0., double(it.size()), "test reading");

    // double t = 0;
    for (size_t i = 0; i < it.size(); ++i)
    {
        auto dg = it.at(int64_t(i));
        // t += dg.get_timestamp();
        prg.tick();
    }

    prg.close(fmt::format(
        "time: {:3f}ms",
        std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - start)
            .count()));
}

void test_speed_decode_nmea(const SimradRawFileHandler<datastreams::MappedFileStream>& ifi)
{
    // get current time
    auto start = std::chrono::high_resolution_clock::now();

    auto it = ifi.datagram_interface().datagrams<datagrams::NME0>(t_SimradRawDatagramIdentifier::NME0);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0., double(it.size()), "test reading");

    using namespace themachinethatgoesping::navigation::nmea_0183;

    // double t = 0;
    for (int64_t i = 0; i < int64_t(it.size()); ++i)
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

void test_speed_decode_xml(const SimradRawFileHandler<datastreams::MappedFileStream>& ifi, int level = 10)
{
    // get current time
    auto start = std::chrono::high_resolution_clock::now();

    auto it = ifi.datagram_interface().datagrams<datagrams::XML0>(t_SimradRawDatagramIdentifier::XML0);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0., double(it.size()), "test reading");

    using namespace themachinethatgoesping::navigation::nmea_0183;

    // double t = 0;
    for (int64_t i = 0; i < int64_t(it.size()); ++i)
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

void test_speed_type(const SimradRawFileHandler<datastreams::MappedFileStream>& ifi,
                     t_SimradRawDatagramIdentifier                          type)
{
    switch (type)
    {
        case t_SimradRawDatagramIdentifier::MRU0:
            test_speed_content<datagrams::MRU0>(ifi, type);
            break;
        case t_SimradRawDatagramIdentifier::NME0:
            test_speed_content<datagrams::NME0>(ifi, type);
            break;
        case t_SimradRawDatagramIdentifier::XML0:
            test_speed_content<datagrams::XML0>(ifi, type);
            break;
        case t_SimradRawDatagramIdentifier::TAG0:
            test_speed_content<datagrams::TAG0>(ifi, type);
            break;
        case t_SimradRawDatagramIdentifier::FIL1:
            test_speed_content<datagrams::FIL1>(ifi, type);
            break;
        case t_SimradRawDatagramIdentifier::RAW3:
            test_speed_content<datagrams::RAW3>(ifi, type);
            break;
        default:
            test_speed_content<datagrams::SimradRawUnknown>(ifi, type);
            break;
    }
}

void test_speed_header(const SimradRawFileHandler<datastreams::MappedFileStream>& ifi,
                       t_SimradRawDatagramIdentifier                          type)
{
    // get current time
    auto                     start = std::chrono::high_resolution_clock::now();
    datagrams::SimradRawUnknown a;

    auto it  = ifi.datagram_interface().datagrams<datagrams::SimradRawDatagram>(type);
    auto prg = themachinethatgoesping::tools::progressbars::ProgressIndicator();
    prg.init(0., double(it.size()), "test reading");

    // double t = 0;
    for (int64_t i = 0; i < int64_t(it.size()); ++i)
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

void init_c_file_test_functions(pybind11::module& m)
{
    m.def("test_speed_raw",
          &test_speed_content<datagrams::SimradRawUnknown>,
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