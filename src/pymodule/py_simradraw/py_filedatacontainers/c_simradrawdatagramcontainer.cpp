// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pytensor.hpp> // Numpy bindings
#include <xtensor/xmath.hpp>          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/types.hpp"

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatacontainers {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

void init_c_simradrawdatagramcontainer(pybind11::module& m)
{
    using namespace py_filetemplates::py_datacontainers;

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SimradRawDatagram,
                                                        t_SimradRawDatagramIdentifier>(
        m, "SimradRawDatagramContainer_Header");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SimradRawUnknown,
                                                        t_SimradRawDatagramIdentifier>(
        m, "SimradRawDatagramContainer_Unknown");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::MRU0,
                                                        t_SimradRawDatagramIdentifier>(
        m, "SimradRawDatagramContainer_MRU0");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::TAG0,
                                                        t_SimradRawDatagramIdentifier>(
        m, "SimradRawDatagramContainer_TAG0");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::FIL1,
                                                        t_SimradRawDatagramIdentifier>(
        m, "SimradRawDatagramContainer_FIL1");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::RAW3,
                                                        t_SimradRawDatagramIdentifier>(
        m, "SimradRawDatagramContainer_RAW3");
    py_datagramcontainer::create_DatagramContainerTypes<
        datagrams::RAW3,
        t_SimradRawDatagramIdentifier,
        datagrams::SimradRawSkipDataFactory<datagrams::RAW3>>(
        m, "SimradRawDatagramContainer_RAW3_skipped_data");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::XML0,
                                                        t_SimradRawDatagramIdentifier>(
        m, "SimradRawDatagramContainer_XML0");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::NME0,
                                                        t_SimradRawDatagramIdentifier>(
        m, "SimradRawDatagramContainer_NME0");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::t_SimradRawDatagramVariant,
                                                        t_SimradRawDatagramIdentifier,
                                                        datagrams::SimradRawDatagramVariant>(
        m, "SimradRawDatagramContainer_Variant");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::t_SimradRawDatagramVariant,
                                                        t_SimradRawDatagramIdentifier,
                                                        datagrams::SimradRawSkipDataVariantFactory>(
        m, "SimradRawDatagramContainer_Variant_skipped_data");
}

}
}
}
}
}