// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/echosounders/simrad/datagrams/RAW3_datatypes/RAW3_datatypes.hpp>
#include "../../../docstrings.hpp"
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "module.hpp"

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_raw3_datatypes {

// --- helper defines ---
#define DOC_T_RAW3_DATATYPE(TYPE)                                                                  \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simrad,                                                                                    \
        datagrams,                                                                                 \
        RAW3_datatypes,                                                                            \
        t_RAW3_DataType,                                                                           \
        TYPE)

// -- submodule declarations --
void init_c_i_raw3_data(pybind11::module& m);             // c_i_raw3_data.cpp
void init_c_raw3_datacomplexfloat32(pybind11::module& m); // c_i_raw3_data_power.cpp
void init_c_raw3_datapowerandangle(pybind11::module& m);  // c_i_raw3_data_power_and_angle.cpp
void init_c_raw3_datapower(pybind11::module& m);          // c_i_raw3_data_power.cpp
void init_c_raw3_dataangle(pybind11::module& m);          // c_i_raw3_data_angle.cpp
void init_c_raw3_dataskipped(pybind11::module& m);        // c_i_raw3_data_skipped.cpp

// -- create submodule --
void init_m_RAW3_datatypes(pybind11::module& m)
{
    // module description
    auto subm = m.def_submodule(
        "RAW3_datatypes", "Simrad EK80 sample datagram data structures used in RAW3 datagrams).");

    using themachinethatgoesping::echosounders::simrad::datagrams::RAW3_datatypes::t_RAW3_DataType;

    // enums
    auto pyenum_raw3_datatype =
        pybind11::enum_<t_RAW3_DataType>(subm,
                                         "t_RAW3_DataType",
                                         DOC(themachinethatgoesping,
                                             echosounders,
                                             simrad,
                                             datagrams,
                                             RAW3_datatypes,
                                             t_RAW3_DataType))
            .value("Power", t_RAW3_DataType::Power, DOC_T_RAW3_DATATYPE(Power))
            .value("Angle", t_RAW3_DataType::Angle, DOC_T_RAW3_DATATYPE(Angle))
            .value(
                "PowerAndAngle", t_RAW3_DataType::PowerAndAngle, DOC_T_RAW3_DATATYPE(PowerAndAngle))
            .value("ComplexFloat16",
                   t_RAW3_DataType::ComplexFloat16,
                   DOC_T_RAW3_DATATYPE(ComplexFloat16))
            .value("ComplexFloat32",
                   t_RAW3_DataType::ComplexFloat32,
                   DOC_T_RAW3_DATATYPE(ComplexFloat32))
            .export_values()
        //
        ;

    tools::pybind_helper::add_string_to_enum_conversion<t_RAW3_DataType>(pyenum_raw3_datatype);

    // RAW datatype structures
    init_c_i_raw3_data(subm);
    init_c_raw3_datacomplexfloat32(subm);
    init_c_raw3_datapowerandangle(subm);
    init_c_raw3_datapower(subm);
    init_c_raw3_dataangle(subm);
    init_c_raw3_dataskipped(subm);
}

}
}
}
}
}
}
