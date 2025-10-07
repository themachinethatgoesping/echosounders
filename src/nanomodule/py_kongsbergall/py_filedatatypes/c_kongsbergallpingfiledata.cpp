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
#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/kongsbergallping.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/types.hpp"

#include "../py_filedatainterfaces/c_kongsbergalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KongsbergAllPingFileData(ARG)                                                          \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        filedatatypes,                                                                             \
        KongsbergAllPingFileData,                                                                  \
        ARG)

template<typename T_FileStream>
void py_create_class_kongsbergallPingFileData(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_KongsbergAllPingFileData = filedatatypes::KongsbergAllPingFileData<T_FileStream>;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;
    using namespace themachinethatgoesping::echosounders::kongsbergall::filedatatypes::calibration;

     auto cls = nb::class_<t_KongsbergAllPingFileData,
                          datatypes::I_PingFileData>(m,
                                                     (CLASS_NAME).c_str(),
                                                     DOC(themachinethatgoesping,
                                                         echosounders,
                                                         kongsbergall,
                                                         filedatatypes,
                                                         KongsbergAllPingFileData))

                   // --- substructure access ---
                   .def("set_runtime_parameters",
                        &t_KongsbergAllPingFileData::set_runtime_parameters,
                        DOC_KongsbergAllPingFileData(set_runtime_parameters),
                        nb::arg("runtime_parameters"))
                   .def("get_runtime_parameters",
                        &t_KongsbergAllPingFileData::get_runtime_parameters,
                        DOC_KongsbergAllPingFileData(get_runtime_parameters))

                   // --- file_data data access ---
                   .def("read_merged_watercolumndatagram",
                        &t_KongsbergAllPingFileData::read_merged_watercolumndatagram,
                        DOC_KongsbergAllPingFileData(read_merged_watercolumndatagram),
                        nb::arg("skip_data") = false)

                   // --- watercolumncalibration access ---
                   .def("init_watercolumn_calibration",
                        &t_KongsbergAllPingFileData::init_watercolumn_calibration,
                        DOC_KongsbergAllPingFileData(init_watercolumn_calibration))
                   .def("has_watercolumn_calibration",
                        &t_KongsbergAllPingFileData::has_watercolumn_calibration,
                        DOC_KongsbergAllPingFileData(has_watercolumn_calibration))
                   .def("set_watercolumn_calibration",
                              nb::overload_cast<
                            const filedatatypes::calibration::KongsbergAllWaterColumnCalibration&>(
                            &t_KongsbergAllPingFileData::set_watercolumn_calibration),
                        DOC_KongsbergAllPingFileData(set_watercolumn_calibration),
                              nb::arg("calibration"))
                   .def("set_watercolumn_calibration",
                              nb::overload_cast<const std::vector<
                            filedatatypes::calibration::KongsbergAllWaterColumnCalibration>&>(
                            &t_KongsbergAllPingFileData::set_watercolumn_calibration),
                        DOC_KongsbergAllPingFileData(set_watercolumn_calibration_2),
                              nb::arg("calibrations"))
                   .def("get_watercolumn_calibration",
                              nb::overload_cast<size_t>(
                                   &t_KongsbergAllPingFileData::get_watercolumn_calibration, nb::const_),
                        DOC_KongsbergAllPingFileData(get_watercolumn_calibration),
                              nb::arg("tx_sector"))
                   .def("get_watercolumn_calibration",
                              nb::overload_cast<>(
                                   &t_KongsbergAllPingFileData::get_watercolumn_calibration, nb::const_),
                        DOC_KongsbergAllPingFileData(get_watercolumn_calibration_2))
                   .def("get_multisector_calibration",
                        &t_KongsbergAllPingFileData::get_multisector_calibration,
                        DOC_KongsbergAllPingFileData(get_multisector_calibration))
                   .def("set_multisector_calibration",
                        &t_KongsbergAllPingFileData::set_multisector_calibration,
                        DOC_KongsbergAllPingFileData(set_multisector_calibration),
                        nb::arg("calibration"))

                   // --- bottom detection ---
                   .def("read_xyz",
                        nb::overload_cast<>(&t_KongsbergAllPingFileData::read_xyz),
                        DOC_KongsbergAllPingFileData(read_xyz))
                   .def("read_xyz",
                              nb::overload_cast<const pingtools::BeamSelection&>(
                            &t_KongsbergAllPingFileData::read_xyz),
                        DOC_KongsbergAllPingFileData(read_xyz_2),
                              nb::arg("selection"))

                   // load/release
                   .def("release_wci",
                        &t_KongsbergAllPingFileData::release_wci,
                        DOC_KongsbergAllPingFileData(release_wci))
                   .def("release_sys",
                        &t_KongsbergAllPingFileData::release_sys,
                        DOC_KongsbergAllPingFileData(release_sys))
                   .def("release_multisector_calibration",
                        &t_KongsbergAllPingFileData::release_multisector_calibration,
                        DOC_KongsbergAllPingFileData(release_multisector_calibration))

                   .def("wci_loaded",
                        &t_KongsbergAllPingFileData::wci_loaded,
                        DOC_KongsbergAllPingFileData(wci_loaded))
                   .def("sys_loaded",
                        &t_KongsbergAllPingFileData::sys_loaded,
                        DOC_KongsbergAllPingFileData(sys_loaded))
                   .def("multisector_calibration_loaded",
                        &t_KongsbergAllPingFileData::multisector_calibration_loaded,
                        DOC_KongsbergAllPingFileData(multisector_calibration_loaded))
               // ----- this is also commented out in simradraw equivalent-----
               // ----- operators -----
               // .def("__eq__",
               //      &KongsbergAllPing::operator==,
               //      DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes,
               //      KongsbergAllPing, operator_eq), py::arg("other"))
               // ----- pybind macros -----
               // default copy functions
               __PYCLASS_DEFAULT_COPY__(t_KongsbergAllPingFileData)
               // default binary functions
               __PYCLASS_DEFAULT_PRINTING__(t_KongsbergAllPingFileData)
        // end KongsbergAllPing
        ;

    // inherit from KongsbergAllDatagramInterface
    py_filedatainterfaces::KongsbergAllDatagramInterface_add_interface_functions<
        t_KongsbergAllPingFileData>(cls);
}

void init_c_kongsbergallPingFileData(nanobind::module_& m)
{
    static const std::string name        = "KongsbergAllPingFileData";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kongsbergallPingFileData<std::ifstream>(m, name_stream);
    py_create_class_kongsbergallPingFileData<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}