// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <chrono>
#include <pybind11/pybind11.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatainterfaces {

#define DOC_I_DatagramInterface(ARG)                                                               \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datainterfaces,                                                                            \
        I_DatagramInterface,                                                                       \
        ARG)

#define DOC_KongsbergAllDatagramInterface(ARG)                                                           \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                                    \
        filedatainterfaces,                                                                        \
        KongsbergAllDatagramInterface,                                                                   \
        ARG)

template<typename T_BaseClass, typename T_PyClass>
void KongsbergAllDatagramInterface_add_interface_functions(T_PyClass& cls)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates;
    using namespace themachinethatgoesping::echosounders::kongsbergall;
    using themachinethatgoesping::tools::progressbars::I_ProgressBar;

    using namespace py_filetemplates::py_datainterfaces;
    py_i_datagraminterface::add_InterfaceFunctions<T_BaseClass>(cls);
    //----- iterators via () operator -----
    cls.def(
        "datagrams",
        [](const T_BaseClass& self, bool skip_data) {
            if (skip_data)
                return py::cast(self.template datagrams<datagrams::t_KongsbergAllDatagramVariant,
                                                        datagrams::KongsbergAllSkipDataVariantFactory>());

            return py::cast(self.template datagrams<datagrams::t_KongsbergAllDatagramVariant,
                                                    datagrams::KongsbergAllDatagramVariant>());
        },
        DOC_I_DatagramInterface(datagrams),
        py::arg("skip_data") = false);
    cls.def(
        "datagrams",
        [](const T_BaseClass& self, t_KongsbergAllDatagramIdentifier type, bool skip_data) {
            // KongsbergAllDATAGRAMTYPEAREA
            switch (type)
            {
                case t_KongsbergAllDatagramIdentifier::XYZDatagram:
                    return py::cast(self.template datagrams<datagrams::XYZDatagram>(type));
                case t_KongsbergAllDatagramIdentifier::ExtraDetections:
                    return py::cast(self.template datagrams<datagrams::ExtraDetections>(type));
                case t_KongsbergAllDatagramIdentifier::RawRangeAndAngle:
                    return py::cast(self.template datagrams<datagrams::RawRangeAndAngle>(type));
                case t_KongsbergAllDatagramIdentifier::SeabedImageData:
                    return py::cast(self.template datagrams<datagrams::SeabedImageData>(type));
                case t_KongsbergAllDatagramIdentifier::WatercolumnDatagram:
                    if (skip_data)
                        return py::cast(
                            self.template datagrams<
                                datagrams::WatercolumnDatagram,
                                datagrams::KongsbergAllSkipDataFactory<datagrams::WatercolumnDatagram>>(
                                type));
                    return py::cast(self.template datagrams<datagrams::WatercolumnDatagram>(type));
                case t_KongsbergAllDatagramIdentifier::QualityFactorDatagram:
                    return py::cast(
                        self.template datagrams<datagrams::QualityFactorDatagram>(type));
                case t_KongsbergAllDatagramIdentifier::AttitudeDatagram:
                    return py::cast(self.template datagrams<datagrams::AttitudeDatagram>(type));
                case t_KongsbergAllDatagramIdentifier::NetworkAttitudeVelocityDatagram:
                    return py::cast(
                        self.template datagrams<datagrams::NetworkAttitudeVelocityDatagram>(type));
                case t_KongsbergAllDatagramIdentifier::ClockDatagram:
                    return py::cast(self.template datagrams<datagrams::ClockDatagram>(type));
                case t_KongsbergAllDatagramIdentifier::DepthOrHeightDatagram:
                    return py::cast(
                        self.template datagrams<datagrams::DepthOrHeightDatagram>(type));
                case t_KongsbergAllDatagramIdentifier::HeadingDatagram:
                    return py::cast(self.template datagrams<datagrams::HeadingDatagram>(type));
                case t_KongsbergAllDatagramIdentifier::PositionDatagram:
                    return py::cast(self.template datagrams<datagrams::PositionDatagram>(type));
                case t_KongsbergAllDatagramIdentifier::SingleBeamEchoSounderDepth:
                    return py::cast(
                        self.template datagrams<datagrams::SingleBeamEchoSounderDepth>(type));
                case t_KongsbergAllDatagramIdentifier::SurfaceSoundSpeedDatagram:
                    return py::cast(
                        self.template datagrams<datagrams::SurfaceSoundSpeedDatagram>(type));
                case t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram:
                    return py::cast(
                        self.template datagrams<datagrams::SoundSpeedProfileDatagram>(type));
                case t_KongsbergAllDatagramIdentifier::InstallationParametersStart:
                    return py::cast(
                        self.template datagrams<datagrams::InstallationParameters>(type));
                case t_KongsbergAllDatagramIdentifier::InstallationParametersStop:
                    return py::cast(
                        self.template datagrams<datagrams::InstallationParameters>(type));
                case t_KongsbergAllDatagramIdentifier::RuntimeParameters:
                    return py::cast(self.template datagrams<datagrams::RuntimeParameters>(type));
                case t_KongsbergAllDatagramIdentifier::ExtraParameters:
                    return py::cast(self.template datagrams<datagrams::ExtraParameters>(type));
                case t_KongsbergAllDatagramIdentifier::PUIDOutput:
                    return py::cast(self.template datagrams<datagrams::PUIDOutput>(type));
                case t_KongsbergAllDatagramIdentifier::PUStatusOutput:
                    return py::cast(self.template datagrams<datagrams::PUStatusOutput>(type));
                default:
                    return py::cast(self.template datagrams<datagrams::KongsbergAllUnknown>(type));
            }
        },
        DOC_I_DatagramInterface(datagrams_2),
        py::arg("datagram_type"),
        py::arg("skip_data") = false);
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self) {
            return py::cast(self.template datagrams<datagrams::KongsbergAllDatagram>());
        },
        DOC_I_DatagramInterface(datagrams));
    cls.def(
        "datagram_headers",
        [](const T_BaseClass& self, t_KongsbergAllDatagramIdentifier type) {
            return py::cast(self.template datagrams<datagrams::KongsbergAllDatagram>(type));
        },
        DOC_I_DatagramInterface(datagrams_2),
        py::arg("datagram_type"));
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self) {
            return py::cast(self.template datagrams<datagrams::KongsbergAllUnknown>());
        },
        DOC_I_DatagramInterface(datagrams));
    cls.def(
        "datagrams_raw",
        [](const T_BaseClass& self, t_KongsbergAllDatagramIdentifier type) {
            return py::cast(self.template datagrams<datagrams::KongsbergAllUnknown>(type));
        },
        DOC_I_DatagramInterface(datagrams_2),
        py::arg("datagram_type"));

    cls.def("per_file",
            &T_BaseClass::per_file,
            DOC_KongsbergAllDatagramInterface(per_file),
            py::return_value_policy::reference_internal);

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(T_BaseClass);
}

}
}
}
}
}