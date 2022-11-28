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

#include "../../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../../docstrings.hpp"

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_filedatacontainers {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

struct RAW3HeaderFactory
{
    static datagrams::RAW3 from_stream(std::istream& is)
    {
        return datagrams::RAW3::from_stream(is, true);
    }

    static datagrams::RAW3 from_stream(std::istream& is, t_SimradDatagramIdentifier type)
    {
        return datagrams::RAW3::from_stream(is, type, true);
    }
};

void init_c_simraddatagramcontainer(pybind11::module& m)
{
    using namespace py_filetemplates::py_datacontainers;

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SimradDatagram,
                                                        t_SimradDatagramIdentifier>(
        m, "SimradRawDatagramContainer_Header");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SimradUnknown,
                                                        t_SimradDatagramIdentifier>(
        m, "SimradRawDatagramContainer_Unknown");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::MRU0,
                                                        t_SimradDatagramIdentifier>(
        m, "SimradRawDatagramContainer_MRU0");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::TAG0,
                                                        t_SimradDatagramIdentifier>(
        m, "SimradRawDatagramContainer_TAG0");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::FIL1,
                                                        t_SimradDatagramIdentifier>(
        m, "SimradRawDatagramContainer_FIL1");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::RAW3,
                                                        t_SimradDatagramIdentifier>(
        m, "SimradRawDatagramContainer_RAW3");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::RAW3,
                                                        t_SimradDatagramIdentifier,
                                                        RAW3HeaderFactory>(
        m, "SimradRawDatagramContainer_RAW3_header");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::XML0,
                                                        t_SimradDatagramIdentifier>(
        m, "SimradRawDatagramContainer_XML0");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::NME0,
                                                        t_SimradDatagramIdentifier>(
        m, "SimradRawDatagramContainer_NME0");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::t_SimradDatagramVariant,
                                                        t_SimradDatagramIdentifier,
                                                        datagrams::SimradDatagramVariant>(
        m, "SimradRawDatagramContainer_Variant");
}

}
}
}
}
}