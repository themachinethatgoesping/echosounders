// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <chrono>
#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/variant.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools/progressbars/i_progressbar.hpp>
#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams.hpp>
#include <themachinethatgoesping/echosounders/s7k/filedatainterfaces/s7kdatagraminterface.hpp>
#include <themachinethatgoesping/echosounders/s7k/types.hpp>

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatainterfaces {

#define DOC_I_DatagramInterface(ARG)                                                               \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datainterfaces,                                                                            \
        I_DatagramInterface,                                                                       \
        ARG)

#define DOC_S7KDatagramInterface(ARG)                                                              \
    DOC(themachinethatgoesping, echosounders, s7k, filedatainterfaces, S7KDatagramInterface, ARG)

template<typename T_BaseClass, typename T_PyClass>
void S7KDatagramInterface_add_interface_functions(T_PyClass& cls)
{
    namespace nb = nanobind;
    using namespace themachinethatgoesping::echosounders::filetemplates;
    using namespace themachinethatgoesping::echosounders::s7k;
    using themachinethatgoesping::tools::progressbars::I_ProgressBar;

    using namespace py_filetemplates::py_datainterfaces;
    py_i_datagraminterface::add_InterfaceFunctions<T_BaseClass>(cls);

    //----- iterators via () operator -----
    // all datagrams (each is read on demand and returned as the matching variant type)
    cls.def(
        "datagrams",
        [](const T_BaseClass& self, bool skip_data) {
            if (skip_data)
                return nb::cast(self.template datagrams<datagrams::t_S7KDatagramVariant,
                                                        datagrams::S7KSkipDataVariantFactory>());

            return nb::cast(self.template datagrams<datagrams::t_S7KDatagramVariant,
                                                    datagrams::S7KDatagramVariant>());
        },
        DOC_I_DatagramInterface(datagrams),
        nb::arg("skip_data") = false);

    // typed datagrams for a given record type (returns the parsed record objects)
    // S7KDATAGRAMTYPEAREA
    cls.def(
        "datagrams",
        [](const T_BaseClass& self, o_S7KDatagramIdentifier type, [[maybe_unused]] bool skip_data) {
            switch (type.value)
            {
                case t_S7KDatagramIdentifier::ReferencePoint:
                    return nb::cast(self.template datagrams<datagrams::ReferencePoint>(type));
                case t_S7KDatagramIdentifier::Position:
                    return nb::cast(self.template datagrams<datagrams::Position>(type));
                case t_S7KDatagramIdentifier::RollPitchHeave:
                    return nb::cast(self.template datagrams<datagrams::RollPitchHeave>(type));
                case t_S7KDatagramIdentifier::Heading:
                    return nb::cast(self.template datagrams<datagrams::Heading>(type));
                case t_S7KDatagramIdentifier::Navigation:
                    return nb::cast(self.template datagrams<datagrams::Navigation>(type));
                case t_S7KDatagramIdentifier::SonarSettings:
                    return nb::cast(self.template datagrams<datagrams::SonarSettings>(type));
                case t_S7KDatagramIdentifier::MatchFilter:
                    return nb::cast(self.template datagrams<datagrams::MatchFilter>(type));
                case t_S7KDatagramIdentifier::SoundVelocity:
                    return nb::cast(self.template datagrams<datagrams::SoundVelocity>(type));
                case t_S7KDatagramIdentifier::AbsorptionLoss:
                    return nb::cast(self.template datagrams<datagrams::AbsorptionLoss>(type));
                case t_S7KDatagramIdentifier::SpreadingLoss:
                    return nb::cast(self.template datagrams<datagrams::SpreadingLoss>(type));
                case t_S7KDatagramIdentifier::RawDetectionData:
                    return nb::cast(self.template datagrams<datagrams::RawDetection>(type));
                case t_S7KDatagramIdentifier::SnippetData: {
                    if (skip_data)
                        return nb::cast(self.template datagrams<
                                        datagrams::SnippetData,
                                        datagrams::S7KSkipDataFactory<datagrams::SnippetData>>(type));
                    return nb::cast(self.template datagrams<datagrams::SnippetData>(type));
                }
                case t_S7KDatagramIdentifier::CompressedWaterColumnData: {
                    if (skip_data)
                        return nb::cast(
                            self.template datagrams<
                                datagrams::CompressedWaterColumn,
                                datagrams::S7KSkipDataFactory<datagrams::CompressedWaterColumn>>(
                                type));
                    return nb::cast(
                        self.template datagrams<datagrams::CompressedWaterColumn>(type));
                }
                case t_S7KDatagramIdentifier::BeamGeometry:
                    return nb::cast(self.template datagrams<datagrams::BeamGeometry>(type));
                case t_S7KDatagramIdentifier::Attitude:
                    return nb::cast(self.template datagrams<datagrams::Attitude>(type));
                case t_S7KDatagramIdentifier::FileHeader:
                    return nb::cast(self.template datagrams<datagrams::FileHeader>(type));
                default:
                    return nb::cast(self.template datagrams<datagrams::S7KUnknown>(type));
            }
        },
        DOC_I_DatagramInterface(datagrams_2),
        nb::arg("datagram_type"),
        nb::arg("skip_data") = false);

    // datagram headers (Data Record Frame only)
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self) {
            return nb::cast(self.template datagrams<datagrams::S7KDatagram>());
        },
        DOC_I_DatagramInterface(datagrams));
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self, o_S7KDatagramIdentifier type) {
            return nb::cast(self.template datagrams<datagrams::S7KDatagram>(type));
        },
        DOC_I_DatagramInterface(datagrams_2),
        nb::arg("datagram_type"));

    // raw datagrams (each datagram is read on demand as an S7KUnknown, i.e. DRF header + raw bytes)
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self) {
            return nb::cast(self.template datagrams<datagrams::S7KUnknown>());
        },
        DOC_I_DatagramInterface(datagrams));
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self, o_S7KDatagramIdentifier type) {
            return nb::cast(self.template datagrams<datagrams::S7KUnknown>(type));
        },
        DOC_I_DatagramInterface(datagrams_2),
        nb::arg("datagram_type"));

    cls.def("per_file",
            &T_BaseClass::per_file,
            DOC_S7KDatagramInterface(per_file),
            nb::rv_policy::reference_internal);

    // ----- convenience functions -----
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(T_BaseClass);
}

}
}
}
}
}
