// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once


#include "../../../themachinethatgoesping/echosounders/simradraw/filedatatypes/simradrawpingcommon.hpp"
#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {
namespace py_simradrawpingcommon {

template<typename T_BaseClass, typename T_PyClass>
void SimradRawPingCommon_add_interface(T_PyClass& cls)
{
    namespace nb = nanobind;

    cls.def_prop_ro("file_data",
                    nb::overload_cast<>(&T_BaseClass::file_data),
                    DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingCommon, file_data),
                    nb::rv_policy::reference_internal);
}

} // namespace py_simradrawpingcommon
} // namespace py_filedatatypes
} // namespace py_simradraw
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
