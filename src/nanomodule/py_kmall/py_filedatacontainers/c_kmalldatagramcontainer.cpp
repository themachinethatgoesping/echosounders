// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <chrono>

#include <themachinethatgoesping/tools/progressbars/i_progressbar.hpp>
#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams.hpp>
#include <themachinethatgoesping/echosounders/kmall/types.hpp>

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatacontainers {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::kmall;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

void init_c_kmalldatagramcontainer(nanobind::module_& m)
{
    using namespace py_filetemplates::py_datacontainers;
    // KMALLDATAGRAMTYPEAREA

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::KMALLDatagram,
                                                        t_KMALLDatagramIdentifier>(
        m, "KMALLDatagramContainer_Header");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::KMALLUnknown,
                                                        t_KMALLDatagramIdentifier>(
        m, "KMALLDatagramContainer_Unknown");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::IInstallationParam,
                                                        t_KMALLDatagramIdentifier>(
        m, "KMALLDatagramContainer_IInstallationParam");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::IOpRuntime,
                                                        t_KMALLDatagramIdentifier>(
        m, "KMALLDatagramContainer_IOpRuntime");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SPosition,
                                                        t_KMALLDatagramIdentifier>(
        m, "KMALLDatagramContainer_SPosition");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SPositionError,
                                                        t_KMALLDatagramIdentifier>(
        m, "KMALLDatagramContainer_SPositionError");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SClock,
                                                        t_KMALLDatagramIdentifier>(
        m, "KMALLDatagramContainer_SClock");
        
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SoundVelocityProfile,
                                                        t_KMALLDatagramIdentifier>(
        m, "KMALLDatagramContainer_SoundVelocityProfile");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::t_KMALLDatagramVariant,
                                                        t_KMALLDatagramIdentifier,
                                                        datagrams::KMALLDatagramVariant>(
        m, "KMALLDatagramContainer_Variant");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::t_KMALLDatagramVariant,
                                                        t_KMALLDatagramIdentifier,
                                                        datagrams::KMALLSkipDataVariantFactory>(
        m, "KMALLDatagramContainer_Variant_SkippedData");
}

}
}
}
}
}