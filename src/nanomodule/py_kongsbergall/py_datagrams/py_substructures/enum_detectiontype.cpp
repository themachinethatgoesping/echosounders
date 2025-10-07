// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/flag_detection_information.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::detection_information::t_DetectionType;

#define DOC_t_DetectionType(ARG)                                                                   \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        datagrams,                                                                                 \
        substructures,                                                                             \
        detection_information,                                                                     \
        t_DetectionType,                                                                           \
        ARG)

void init_enum_detectiontype(nanobind::module_& m)
{
    nb::enum_<t_DetectionType>(m,
                               "XYZDatagramBeam_t_DetectionType",
                               DOC(themachinethatgoesping,
                                   echosounders,
                                   kongsbergall,
                                   datagrams,
                                   substructures,
                                   detection_information,
                                   t_DetectionType))
        // Multibeam data
        .value("AmplitudeDetect",
               t_DetectionType::AmplitudeDetect,
               DOC_t_DetectionType(AmplitudeDetect))
        .value("PhaseDetect", t_DetectionType::PhaseDetect, DOC_t_DetectionType(PhaseDetect))
        .value("InvalidNormalDetection",
               t_DetectionType::InvalidNormalDetection,
               DOC_t_DetectionType(InvalidNormalDetection))
        .value("Interpolated", t_DetectionType::Interpolated, DOC_t_DetectionType(Interpolated))
        .value("Estimated", t_DetectionType::Estimated, DOC_t_DetectionType(Estimated))
        .value("Rejected", t_DetectionType::Rejected, DOC_t_DetectionType(Rejected))
        .value("NoDetection", t_DetectionType::NoDetection, DOC_t_DetectionType(NoDetection))
        .value("Invalid", t_DetectionType::Invalid, DOC_t_DetectionType(Invalid))

        //
        ;

    tools::nanobind_helper::make_option_class<
        datagrams::substructures::detection_information::o_DetectionType>(
        m, "o_XYZDatagramBeam_t_DetectionType");
}
}
}
}
}
}
}