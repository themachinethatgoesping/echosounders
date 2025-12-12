// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/complex.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../themachinethatgoesping/echosounders/kmall/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/kmall/filedatatypes/kmallping.hpp"
#include "../../../themachinethatgoesping/echosounders/kmall/types.hpp"

#include "../py_filedatainterfaces/c_kmalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KMALLPingFileData(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, kmall, filedatatypes, KMALLPingFileData, ARG)

template<typename T_FileStream>
void py_create_class_kmallPingFileData(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_KMALLPingFileData = filedatatypes::KMALLPingFileData<T_FileStream>;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;
    using namespace themachinethatgoesping::echosounders::kmall::filedatatypes::calibration;

    auto cls =
        nb::class_<t_KMALLPingFileData, datatypes::I_PingFileData>(
            m,
            (CLASS_NAME).c_str(),
            DOC(themachinethatgoesping, echosounders, kmall, filedatatypes, KMALLPingFileData))

            //     // --- substructure access ---
            .def("set_runtime_parameters",
                 &t_KMALLPingFileData::set_runtime_parameters,
                 DOC_KMALLPingFileData(set_runtime_parameters),
                 nb::arg("runtime_parameters"))
            .def("get_runtime_parameters",
                 &t_KMALLPingFileData::get_runtime_parameters,
                 DOC_KMALLPingFileData(get_runtime_parameters))

            //     // --- file_data data access ---

            // --- watercolumncalibration access ---
            .def("init_watercolumn_calibration",
                 &t_KMALLPingFileData::init_watercolumn_calibration,
                 DOC_KMALLPingFileData(init_watercolumn_calibration))
            .def("has_watercolumn_calibration",
                 &t_KMALLPingFileData::has_watercolumn_calibration,
                 DOC_KMALLPingFileData(has_watercolumn_calibration))
            .def("set_watercolumn_calibration",
                 nb::overload_cast<const filedatatypes::calibration::KMALLWaterColumnCalibration&>(
                     &t_KMALLPingFileData::set_watercolumn_calibration),
                 DOC_KMALLPingFileData(set_watercolumn_calibration),
                 nb::arg("calibration"))
            .def("set_watercolumn_calibration",
                 nb::overload_cast<
                     const std::vector<filedatatypes::calibration::KMALLWaterColumnCalibration>&>(
                     &t_KMALLPingFileData::set_watercolumn_calibration),
                 DOC_KMALLPingFileData(set_watercolumn_calibration_2),
                 nb::arg("calibrations"))
            .def("get_watercolumn_calibration",
                 nb::overload_cast<size_t>(&t_KMALLPingFileData::get_watercolumn_calibration,
                                           nb::const_),
                 DOC_KMALLPingFileData(get_watercolumn_calibration),
                 nb::arg("tx_sector"))
            .def("get_watercolumn_calibration",
                 nb::overload_cast<>(&t_KMALLPingFileData::get_watercolumn_calibration, nb::const_),
                 DOC_KMALLPingFileData(get_watercolumn_calibration_2))
            .def("get_multisector_calibration",
                 &t_KMALLPingFileData::get_multisector_calibration,
                 DOC_KMALLPingFileData(get_multisector_calibration))
            .def("set_multisector_calibration",
                 &t_KMALLPingFileData::set_multisector_calibration,
                 DOC_KMALLPingFileData(set_multisector_calibration),
                 nb::arg("calibration"))

            //     // --- bottom detection ---
            //     .def("read_xyz",
            //          nb::overload_cast<>(&t_KMALLPingFileData::read_xyz),
            //          DOC_KMALLPingFileData(read_xyz))
            //     .def("read_xyz",
            //                nb::overload_cast<const pingtools::BeamSelection&>(
            //              &t_KMALLPingFileData::read_xyz),
            //          DOC_KMALLPingFileData(read_xyz_2),
            //                nb::arg("selection"))

            // load/release
            .def("release_wci",
                 &t_KMALLPingFileData::release_wci,
                 DOC_KMALLPingFileData(release_wci))
            .def("release_sys",
                 &t_KMALLPingFileData::release_sys,
                 DOC_KMALLPingFileData(release_sys))
            .def("release_multisector_calibration",
                 &t_KMALLPingFileData::release_multisector_calibration,
                 DOC_KMALLPingFileData(release_multisector_calibration))

            .def("wci_loaded", &t_KMALLPingFileData::wci_loaded, DOC_KMALLPingFileData(wci_loaded))
            .def("sys_loaded", &t_KMALLPingFileData::sys_loaded, DOC_KMALLPingFileData(sys_loaded))
            .def("multisector_calibration_loaded",
                 &t_KMALLPingFileData::multisector_calibration_loaded,
                 DOC_KMALLPingFileData(multisector_calibration_loaded))
        // ----- this is also commented out in simradraw equivalent-----
        // ----- operators -----
        // .def("__eq__",
        //      &KMALLPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, kmall, filedatatypes,
        //      KMALLPing, operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_KMALLPingFileData)
        // default binary functions
        __PYCLASS_DEFAULT_PRINTING__(t_KMALLPingFileData)
        // end KMALLPing
        ;

    // inherit from KMALLDatagramInterface
    py_filedatainterfaces::KMALLDatagramInterface_add_interface_functions<t_KMALLPingFileData>(cls);
}

void init_c_kmallPingFileData(nanobind::module_& m)
{
    static const std::string name        = "KMALLPingFileData";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kmallPingFileData<std::ifstream>(m, name_stream);
    py_create_class_kmallPingFileData<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}