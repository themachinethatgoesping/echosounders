// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/complex.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "c_simradrawpingcommon.hpp"

#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/filedatatypes/simradrawpingcommon.hpp"
#include "../../../themachinethatgoesping/echosounders/simradraw/types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_SimradRawPingCommon(ARG)                                                               \
    DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingCommon, ARG)

template<typename T_FileStream>
void py_create_class_simradrawpingcommon(nb::module_& m, const std::string& CLASS_NAME)
{
    using t_SimradRawPingCommon = filedatatypes::SimradRawPingCommon<T_FileStream>;

    auto cls = nb::class_<t_SimradRawPingCommon>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, SimradRawPingCommon))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_SimradRawPingCommon)
        //end
        ;

    py_simradrawpingcommon::SimradRawPingCommon_add_interface<t_SimradRawPingCommon>(cls);

}

void init_c_simradrawpingcommon(nanobind::module_& m)
{
    static const std::string name        = "SimradRawPingCommon";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_simradrawpingcommon<std::ifstream>(m, name_stream);
    py_create_class_simradrawpingcommon<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}