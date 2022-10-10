// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
//#define FORCE_IMPORT_ARRAY
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/fileraw.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simradpingiterator.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_inputfile.hpp"
#include "../fileinterfaces/i_inputfileiterator.hpp"
#include "../fileinterfaces/i_pingiterator.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using namespace themachinethatgoesping::echosounders::fileinterfaces;

template<typename T_FileStream>
void py_create_class_SimradPingIterator(py::module& m, const std::string& CLASS_NAME)
{
    using t_SimradPingIterator = SimradPingIterator<T_FileStream>;

    auto cls = py::class_<t_SimradPingIterator>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simrad, SimradPingIterator));

    // --- ping interface ---
    py_fileinterfaces::py_i_PingIterator::_PingIterator_add_PackageReading<t_SimradPingIterator>(
        cls);

    // --- raw data access ---

    // ----- operators -----
    // .def("__eq__",
    //      &SimradPingIterator::operator==,
    //      DOC(themachinethatgoesping, echosounders, simrad, SimradPingIterator, operator_eq),
    //      py::arg("other"))
    // ----- pybind macros -----
    // default copy functions
    // __PYCLASS_DEFAULT_COPY__(SimradPingIterator)
    // default binary functions
    // __PYCLASS_DEFAULT_BINARY__(SimradPingIterator)
    // default printing functions
    //__PYCLASS_DEFAULT_PRINTING__(SimradPingIterator)
    // end SimradPingIterator
    ;
}

void init_c_SimradPingIterator(pybind11::module& m)
{

    py_create_class_SimradPingIterator<std::ifstream>(m, "SimradPingIterator");
    py_create_class_SimradPingIterator<MappedFileStream>(m, "SimradPingIterator_mapped");
}

}
}
}
}