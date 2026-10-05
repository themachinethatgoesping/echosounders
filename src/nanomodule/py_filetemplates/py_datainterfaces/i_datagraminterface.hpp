// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <vector>

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>


#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_datagraminterface {

#define DOC_DatagramInterface(ARG)                                                                 \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datainterfaces,                                                                            \
        I_DatagramInterface,                                                                       \
        ARG)

template<typename T_BaseClass, typename T_OptionDatagramIdentifier, typename T_PyClass>
void add_InterfaceFunctions([[maybe_unused]] T_PyClass& cls)
{
    namespace nb = nanobind;

    // cls.def("static_datagram_identifier_to_string",
    //         &T_BaseClass::datagram_identifier_to_string,
    //         DOC_DatagramInterface(datagram_identifier_to_string),
    //         nb::arg("datagram_identifier"));
    // cls.def("datagram_identifier_info",
    //         &T_BaseClass::datagram_identifier_info,
    //         DOC_DatagramInterface(datagram_identifier_info),
    //         nb::arg("datagram_identifier"));

    cls.def("get_timestamp_first",
            &T_BaseClass::get_timestamp_first,
            DOC_DatagramInterface(get_timestamp_first));
    cls.def("get_timestamp_last",
            &T_BaseClass::get_timestamp_last,
            DOC_DatagramInterface(get_timestamp_last));
    cls.def("get_timestamp_range",
            &T_BaseClass::get_timestamp_range,
            DOC_DatagramInterface(get_timestamp_range));

    // return the datagram identifiers as the format's OptionFrozen wrapper: the raw enum cannot be
    // cast to python for values outside the registered set (proprietary record ids), whereas the
    // option wrapper stores the raw value and round-trips back into datagrams()
    cls.def(
        "keys",
        [](const T_BaseClass& self) {
            const auto                              raw_keys = self.keys();
            std::vector<T_OptionDatagramIdentifier> keys;
            keys.reserve(raw_keys.size());
            for (const auto& key : raw_keys)
                keys.emplace_back(key);
            return keys;
        },
        DOC_DatagramInterface(keys));
}

}
}
}
}
}
}