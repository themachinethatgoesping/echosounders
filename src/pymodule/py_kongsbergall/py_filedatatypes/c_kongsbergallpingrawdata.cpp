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

#include "../../../themachinethatgoesping/echosounders/kongsbergall/kongsbergall_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/kongsbergall_types.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/kongsbergallping.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

#include "../py_filedatainterfaces/c_kongsbergalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KongsbergAllPingRawData(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes, KongsbergAllPingRawData, ARG)

template<typename T_FileStream>
void py_create_class_kongsbergallpingrawdata(py::module& m, const std::string& CLASS_NAME)
{
    using t_KongsbergAllPingRawData = filedatatypes::KongsbergAllPingRawData<T_FileStream>;

    auto cls =
        py::class_<t_KongsbergAllPingRawData, std::shared_ptr<t_KongsbergAllPingRawData>>(
            m,
            (CLASS_NAME).c_str(),
            DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes, KongsbergAllPingRawData))

            // --- substructure access ---
            .def("get_runtime_parameters",
                 &t_KongsbergAllPingRawData::get_runtime_parameters,
                 DOC_KongsbergAllPingRawData(get_runtime_parameters))

            // --- raw_data data access ---
            .def("read_merged_watercolumndatagram",
                 &t_KongsbergAllPingRawData::read_merged_watercolumndatagram,
                 DOC_KongsbergAllPingRawData(read_merged_watercolumndatagram),
                 py::arg("skip_data") = false)

            // --- bottom detection ---
            .def("read_xyz",
                 py::overload_cast<>(&t_KongsbergAllPingRawData::read_xyz),
                 DOC_KongsbergAllPingRawData(read_xyz))
            .def("read_xyz",
                 py::overload_cast<const pingtools::BeamSelection&>(&t_KongsbergAllPingRawData::read_xyz),
                 DOC_KongsbergAllPingRawData(read_xyz_2),
                 py::arg("selection"))

        // ----- this is also commented out in simradraw equivalent-----
        // ----- operators -----
        // .def("__eq__",
        //      &KongsbergAllPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes,  KongsbergAllPing,
        //      operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_KongsbergAllPingRawData)
        // default binary functions
        __PYCLASS_DEFAULT_PRINTING__(t_KongsbergAllPingRawData)
        // end KongsbergAllPing
        ;

    // inherit from KongsbergAllDatagramInterface
    py_filedatainterfaces::KongsbergAllDatagramInterface_add_interface_functions<t_KongsbergAllPingRawData>(
        cls);
    // py_i_datagraminterface::add_InterfaceFunctions<t_KongsbergAllPingRawData>(cls);
}

void init_c_kongsbergallpingrawdata(pybind11::module& m)
{

    py_create_class_kongsbergallpingrawdata<std::ifstream>(m, "KongsbergAllPingRawData");
    py_create_class_kongsbergallpingrawdata<datastreams::MappedFileStream>(m, "KongsbergAllPingRawData_mapped");
}

}
}
}
}
}