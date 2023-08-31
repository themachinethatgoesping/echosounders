// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0



#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/echosounders/simrad/datagrams/raw3datatypes/raw3datatypes.hpp>
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
        raw3datatypes,                                                                             \
        t_RAW3DataType,                                                                            \
        TYPE)

// -- submodule declarations --
void init_c_i_raw3data(pybind11::module& m);             // c_i_raw3data.cpp
void init_c_raw3datacomplexfloat32(pybind11::module& m); // c_i_raw3data_power.cpp
void init_c_raw3datapowerandangle(pybind11::module& m);  // c_i_raw3data_power_and_angle.cpp
void init_c_raw3datapower(pybind11::module& m);          // c_i_raw3data_power.cpp
void init_c_raw3dataangle(pybind11::module& m);          // c_i_raw3data_angle.cpp
void init_c_raw3dataskipped(pybind11::module& m);        // c_i_raw3data_skipped.cpp

// -- create submodule --
void init_m_raw3datatypes(pybind11::module& m)
{
    // module description
    auto subm = m.def_submodule(
        "raw3datatypes", "Simrad EK80 sample datagram data structures used in RAW3 datagrams).");

    using themachinethatgoesping::echosounders::simrad::datagrams::raw3datatypes::t_RAW3DataType;

    // enums
    auto pyenum_raw3_datatype =
        pybind11::enum_<t_RAW3DataType>(subm,
                                        "t_RAW3DataType",
                                        DOC(themachinethatgoesping,
                                            echosounders,
                                            simrad,
                                            datagrams,
                                            raw3datatypes,
                                            t_RAW3DataType))
            .value("Power", t_RAW3DataType::Power, DOC_T_RAW3_DATATYPE(Power))
            .value("Angle", t_RAW3DataType::Angle, DOC_T_RAW3_DATATYPE(Angle))
            .value(
                "PowerAndAngle", t_RAW3DataType::PowerAndAngle, DOC_T_RAW3_DATATYPE(PowerAndAngle))
            .value("ComplexFloat16",
                   t_RAW3DataType::ComplexFloat16,
                   DOC_T_RAW3_DATATYPE(ComplexFloat16))
            .value("ComplexFloat32",
                   t_RAW3DataType::ComplexFloat32,
                   DOC_T_RAW3_DATATYPE(ComplexFloat32))
            .export_values()
        //
        ;

    tools::pybind_helper::add_string_to_enum_conversion<t_RAW3DataType>(pyenum_raw3_datatype);

    // RAW datatype structures
    init_c_i_raw3data(subm);
    init_c_raw3datacomplexfloat32(subm);
    init_c_raw3datapowerandangle(subm);
    init_c_raw3datapower(subm);
    init_c_raw3dataangle(subm);
    init_c_raw3dataskipped(subm);
}

}
}
}
}
}
}
