// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams.hpp>
#include <themachinethatgoesping/echosounders/s7k/types.hpp>

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatacontainers {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::s7k;

void init_c_s7kdatagramcontainer(nanobind::module_& m)
{
    using namespace py_filetemplates::py_datacontainers;
    // S7KDATAGRAMTYPEAREA

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::S7KDatagram,
                                                        t_S7KDatagramIdentifier>(
        m, "S7KDatagramContainer_Header");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::S7KUnknown,
                                                        t_S7KDatagramIdentifier>(
        m, "S7KDatagramContainer_Unknown");

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::ReferencePoint, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_ReferencePoint");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::Position, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_Position");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::RollPitchHeave, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_RollPitchHeave");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::Heading, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_Heading");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::Navigation, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_Navigation");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SonarSettings, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_SonarSettings");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::MatchFilter, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_MatchFilter");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SoundVelocity, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_SoundVelocity");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::AbsorptionLoss, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_AbsorptionLoss");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SpreadingLoss, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_SpreadingLoss");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::RawDetection, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_RawDetection");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SnippetData, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_Snippet");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::CompressedWaterColumn, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_CompressedWaterColumn");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::BeamGeometry, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_BeamGeometry");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::Attitude, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_Attitude");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::FileHeader, t_S7KDatagramIdentifier>(m, "S7KDatagramContainer_FileHeader");

    // water-column records with the (large) sample data skipped
    py_datagramcontainer::create_DatagramContainerTypes<
        datagrams::SnippetData,
        t_S7KDatagramIdentifier,
        datagrams::S7KSkipDataFactory<datagrams::SnippetData>>(
        m, "S7KDatagramContainer_Snippet_SkippedData");
    py_datagramcontainer::create_DatagramContainerTypes<
        datagrams::CompressedWaterColumn,
        t_S7KDatagramIdentifier,
        datagrams::S7KSkipDataFactory<datagrams::CompressedWaterColumn>>(
        m, "S7KDatagramContainer_CompressedWaterColumn_SkippedData");

    // variant container (any datagram type)
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::t_S7KDatagramVariant,
                                                        t_S7KDatagramIdentifier,
                                                        datagrams::S7KDatagramVariant>(
        m, "S7KDatagramContainer_Variant");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::t_S7KDatagramVariant,
                                                        t_S7KDatagramIdentifier,
                                                        datagrams::S7KSkipDataVariantFactory>(
        m, "S7KDatagramContainer_Variant_SkippedData");
}

}
}
}
}
}
