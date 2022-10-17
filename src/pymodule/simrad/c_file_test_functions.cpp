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
#include "../fileinterfaces/i_pingcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

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

void init_c_file_test_functions(pybind11::module& m)
{
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