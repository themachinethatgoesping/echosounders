// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/shared_ptr.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datacontainers/pingcontainer.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datacontainers {
namespace py_pingcontainer {

#define DOC_PingContainer(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, filetemplates, datacontainers, PingContainer, ARG)

template<typename T_BaseClass, typename T_PyClass>
void _PingContainer_add_interface(T_PyClass& cls)
{
        namespace nb = nanobind;

    /* get ping infos */
    cls.def("max_number_of_samples",
            &T_BaseClass::max_number_of_samples,
            DOC_PingContainer(max_number_of_samples));

    /* implement breakers */
    cls.def("split_by_time_diff",
            &T_BaseClass::split_by_time_diff,
            DOC_PingContainer(split_by_time_diff),
            nb::arg("max_time_diff_seconds"));

    cls.def("split_by_sensor_configuration",
            &T_BaseClass::split_by_sensor_configuration
            // ,DOC_PingContainer(split_by_sensor_configuration) TODO: doc makes mkdoc crash
            );

    /* implement sorters */
    cls.def("get_sorted_by_time",
            &T_BaseClass::get_sorted_by_time,
            DOC_PingContainer(get_sorted_by_time));

    /* implement find info functions */
    cls.def("count_pings_per_channel_id",
            &T_BaseClass::count_pings_per_channel_id,
            DOC_PingContainer(count_pings_per_channel_id));

    cls.def(
        "find_channel_ids", &T_BaseClass::find_channel_ids, DOC_PingContainer(find_channel_ids));

    /* ping filters */
    cls.def("__call__",
            nb::overload_cast<const std::string&>(&T_BaseClass::operator(), nb::const_),
            DOC_PingContainer(operator_call_2),
            nb::arg("channel_id"));
    cls.def(
        "__call__",
        nb::overload_cast<const std::vector<std::string>&>(&T_BaseClass::operator(), nb::const_),
        DOC_PingContainer(operator_call_3),
        nb::arg("channel_ids"));

    /* datagram reading */
    cls.def("size", &T_BaseClass::size, DOC_PingContainer(size));
    cls.def("__len__", &T_BaseClass::size, DOC_PingContainer(size));
    cls.def("get_pings", &T_BaseClass::get_pings, DOC_PingContainer(get_pings));
    cls.def("__getitem__",
            &T_BaseClass::at,
            DOC_PingContainer(at),
            nb::arg("index"),
            nanobind::rv_policy::reference_internal);
    cls.def("__getitem__",
            nb::overload_cast<const tools::pyhelper::PyIndexer::Slice&>(&T_BaseClass::operator(),
                                                                        nb::const_),
            DOC_PingContainer(operator_call),
            nb::arg("slice"),
            nanobind::rv_policy::reference_internal);
    cls.def("__reversed__",
            &T_BaseClass::reversed,
            DOC_PingContainer(reversed),
            nanobind::rv_policy::reference_internal);
}

template<typename T_PingType>
void create_PingContainerType(nanobind::module_& m, const std::string& ITERATOR_NAME)
{
    using filetemplates::datacontainers::PingContainer;
    namespace nb = nanobind;

    using T_CONTAINER = PingContainer<T_PingType>;

    auto cls_stream =
                nb::class_<T_CONTAINER>(
            m,
            ITERATOR_NAME.c_str(),
            DOC(themachinethatgoesping, echosounders, filetemplates, datacontainers, PingContainer))
                        .def(nb::init<>(), DOC_PingContainer(PingContainer))
                        .def(nb::init<std::vector<std::shared_ptr<T_PingType>>>(),
                 DOC_PingContainer(PingContainer))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(T_CONTAINER)
        // default binary functions
        //__PYCLASS_DEFAULT_BINARY__(FIL1)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(T_CONTAINER)
        // end LinearInterpolator
        /// end
        ;

    _PingContainer_add_interface<T_CONTAINER>(cls_stream);
}

}
}
}
}
}
}