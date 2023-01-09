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

#include "../../../themachinethatgoesping/echosounders/em3000/em3000_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/em3000/em3000_types.hpp"
#include "../../docstrings.hpp"

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatacontainers {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::em3000;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

void init_c_em3000datagramcontainer(pybind11::module& m)
{
    using namespace py_filetemplates::py_datacontainers;
    // EM3000DATAGRAMTYPEAREA

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::EM3000Datagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_Header");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::EM3000Unknown,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_Unknown");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::XYZDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_XYZDatagram");

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::t_EM3000DatagramVariant,
                                                        t_EM3000DatagramIdentifier,
                                                        datagrams::EM3000DatagramVariant>(
        m, "EM3000DatagramContainer_Variant");
}

}
}
}
}
}