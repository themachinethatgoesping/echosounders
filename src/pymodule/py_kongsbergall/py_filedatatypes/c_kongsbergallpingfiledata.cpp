// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

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

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KongsbergAllPingFileData(ARG)                                                           \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        filedatatypes,                                                                             \
        KongsbergAllPingFileData,                                                                   \
        ARG)

template<typename T_FileStream>
void py_create_class_kongsbergallPingFileData(py::module& m, const std::string& CLASS_NAME)
{
    using t_KongsbergAllPingFileData = filedatatypes::KongsbergAllPingFileData<T_FileStream>;

    auto cls = py::class_<t_KongsbergAllPingFileData,
                          std::shared_ptr<t_KongsbergAllPingFileData>,
                          datatypes::I_PingFileData>(m,
                                                    (CLASS_NAME).c_str(),
                                                    DOC(themachinethatgoesping,
                                                        echosounders,
                                                        kongsbergall,
                                                        filedatatypes,
                                                        KongsbergAllPingFileData))

                   // --- substructure access ---
                   .def("get_runtime_parameters",
                        &t_KongsbergAllPingFileData::get_runtime_parameters,
                        DOC_KongsbergAllPingFileData(get_runtime_parameters))

                   // --- file_data data access ---
                   .def("read_merged_watercolumndatagram",
                        &t_KongsbergAllPingFileData::read_merged_watercolumndatagram,
                        DOC_KongsbergAllPingFileData(read_merged_watercolumndatagram),
                        py::arg("skip_data") = false)

                   // --- bottom detection ---
                   .def("read_xyz",
                        py::overload_cast<>(&t_KongsbergAllPingFileData::read_xyz),
                        DOC_KongsbergAllPingFileData(read_xyz))
                   .def("read_xyz",
                        py::overload_cast<const pingtools::BeamSelection&>(
                            &t_KongsbergAllPingFileData::read_xyz),
                        DOC_KongsbergAllPingFileData(read_xyz_2),
                        py::arg("selection"))

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

void init_c_kongsbergallPingFileData(pybind11::module& m)
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