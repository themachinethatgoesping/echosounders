// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/variant.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datacontainers/datagramcontainer.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datacontainers {
namespace py_datagramcontainer {

template<typename T_BaseClass, typename T_DatagramIdentifier, typename T_PyClass>
void _add_DatagramReading(T_PyClass& cls)
{
    namespace nb = nanobind;

    /* get datagram infos */

    /* implement breakers */
    cls.def("split_by_time_diff",
            &T_BaseClass::split_by_time_diff,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datacontainers,
                DatagramContainer,
                split_by_time_diff),
            nb::arg("max_time_diff_seconds"));

    /* implement sorters */
    cls.def("get_sorted_by_time",
            &T_BaseClass::get_sorted_by_time,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datacontainers,
                DatagramContainer,
                get_sorted_by_time));

    /* implement find info functions */
    cls.def("count_datagrams_per_type",
            &T_BaseClass::count_datagrams_per_type,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datacontainers,
                DatagramContainer,
                count_datagrams_per_type));

    cls.def("find_datagram_types",
            &T_BaseClass::find_datagram_types,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datacontainers,
                DatagramContainer,
                find_datagram_types));

    /* datagram infos filters */
    cls.def("__call__",
            nb::overload_cast<T_DatagramIdentifier>(&T_BaseClass::operator(), nb::const_),
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datacontainers,
                DatagramContainer,
                operator_call),
        nb::arg("datagram_identifier"));
    cls.def("__call__",
        nb::overload_cast<const std::vector<T_DatagramIdentifier>&>(&T_BaseClass::operator(),
                                    nb::const_),
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datacontainers,
                DatagramContainer,
                operator_call_2),
            nb::arg("datagram_identifiers"));

    /* datagram reading */
    cls.def("size",
            &T_BaseClass::size,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datacontainers,
                DatagramContainer,
                size));
    cls.def("__len__",
            &T_BaseClass::size,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datacontainers,
                DatagramContainer,
                size));
    cls.def("__getitem__",
            &T_BaseClass::at,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datacontainers,
                DatagramContainer,
                at),
        nb::arg("index"),
        nanobind::rv_policy::reference_internal);
    cls.def("__getitem__",
        nb::overload_cast<const tools::pyhelper::PyIndexer::Slice&>(&T_BaseClass::operator(),
                                    nb::const_),
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datacontainers,
                DatagramContainer,
                operator_call),
        nb::arg("slice"),
        nanobind::rv_policy::reference_internal);
    cls.def("__reversed__",
            &T_BaseClass::reversed,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datacontainers,
                DatagramContainer,
                reversed),
            nanobind::rv_policy::reference_internal);
}

template<typename T_DatagramType,
         typename T_DatagramIdentifier,
         typename T_DatagramFactory = T_DatagramType>
void create_DatagramContainerTypes(nanobind::module_& m, const std::string& CONTAINER_NAME)
{
    using filetemplates::datacontainers::DatagramContainer;
    using filetemplates::datastreams::MappedFileStream;
    namespace nb = nanobind;

    using T_CONTAINER_STREAM =
        DatagramContainer<T_DatagramType, T_DatagramIdentifier, std::ifstream, T_DatagramFactory>;

    using T_CONTAINER_MAPPED = DatagramContainer<T_DatagramType,
                                                 T_DatagramIdentifier,
                                                 MappedFileStream,
                                                 T_DatagramFactory>;

    auto container_name_stream = CONTAINER_NAME + "_stream";
    auto cls_stream            = nb::class_<T_CONTAINER_STREAM>(
        m,
        container_name_stream.c_str(),
        DOC(themachinethatgoesping, echosounders, filetemplates, datacontainers, DatagramContainer))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(T_CONTAINER_STREAM)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(T_CONTAINER_STREAM)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(T_CONTAINER_STREAM)
        // end LinearInterpolator
        ;

    auto container_name_mapped = CONTAINER_NAME;
    auto cls_mapped            = nb::class_<T_CONTAINER_MAPPED>(
        m,
        container_name_mapped.c_str(),
        DOC(themachinethatgoesping, echosounders, filetemplates, datacontainers, DatagramContainer))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(T_CONTAINER_MAPPED)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(T_CONTAINER_MAPPED)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(T_CONTAINER_MAPPED)
        // end LinearInterpolator
        ;

    _add_DatagramReading<T_CONTAINER_STREAM, T_DatagramIdentifier>(cls_stream);
    _add_DatagramReading<T_CONTAINER_MAPPED, T_DatagramIdentifier>(cls_mapped);
}

}
}
}
}
}
}