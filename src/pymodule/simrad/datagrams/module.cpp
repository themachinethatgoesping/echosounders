// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include "../../docstrings.hpp"
#include <themachinethatgoesping/tools/pybind11_helpers/enumhelpers.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/ek80_RAW3_datatypes/ek80_RAW3_datatypes.hpp"

#include "module.hpp"
#include "xml_datagrams/module.hpp"

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

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
void init_c_ek60_datagram(pybind11::module& m); // c_ek60_datagram.cpp
void init_c_ek60_unknown(pybind11::module& m);  // c_ek60_unknown.cpp
void init_c_ek80_MRU0(pybind11::module& m);     // c_EK80_MRU0.cpp
void init_c_ek60_NME0(pybind11::module& m);     // c_ek60_nme0.cpp
void init_c_ek80_XML0(pybind11::module& m);     // c_ek80_xml0.cpp
void init_c_EK60_TAG0(pybind11::module& m);     // c_EK60_TAG0.cpp
void init_c_ek80_FIL1(pybind11::module& m);     // c_ek80_FIL1.cpp
void init_c_ek80_RAW3(pybind11::module& m);     // c_ek80_RAW3.cpp

// -- create submodule --
void init_m_simrad_datagrams(pybind11::module& m)
{
    using themachinethatgoesping::echosounders::simrad::datagrams::RAW3_datatypes::t_RAW3_DataType;
    // module description
    auto subm = m.def_submodule("datagrams", "Simrad EK60 and EK80 datagram classes");

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

    tools::pybind_helpers::add_string_to_enum_conversion<t_RAW3_DataType>(pyenum_raw3_datatype);


    // init submodules
    py_datagrams_xml::init_m_simrad_datagrams_xml(subm);

    // simrad classes
    init_c_ek60_datagram(subm);
    init_c_ek60_unknown(subm);
    init_c_ek80_MRU0(subm);
    init_c_ek60_NME0(subm);
    init_c_ek80_XML0(subm);
    init_c_EK60_TAG0(subm);
    init_c_ek80_FIL1(subm);
    init_c_ek80_RAW3(subm);
}

}
}
}
}
}
