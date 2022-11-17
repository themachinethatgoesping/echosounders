// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pyarray.hpp> // Numpy bindings
#include <xtensor/xmath.hpp>          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/simrad_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simrad_types.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/simraddatagraminterface.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_datagramcontainer.hpp"
#include "../fileinterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

struct RAW3HeaderFactory
{
    static datagrams::RAW3 from_stream(std::istream& is)
    {
        return datagrams::RAW3::from_stream(is, true);
    }

    static datagrams::RAW3 from_stream(std::istream& is, t_SimradDatagramIdentifier type)
    {
        return datagrams::RAW3::from_stream(is, type, true);
    }
};

template<typename T_FileStream>
void py_create_class_SimradDatagramInterface(py::module& m, const std::string& CLASS_NAME)
{
    using namespace py_fileinterfaces; // this holds py_i_DatagramInterface and
                                       // py_i_DatagramInterface

    // initialize class
    auto cls = py::class_<SimradDatagramInterface<T_FileStream>>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, simrad, SimradDatagramInterface));

    //----- inherit functions from I_DatagramInterface -----

    //----- iterators -----
    // this makes documentation crash. Ignore for now
    // py_i_DatagramInterface::add_Iterator<SimradDatagramInterface<T_FileStream>,
    //                                      datagrams::t_SimradDatagramVariant,
    //                                      datagrams::t_SimradDatagramVariant>(cls, "all");

    py_i_DatagramInterface::add_Iterator<SimradDatagramInterface<T_FileStream>, datagrams::FIL1>(
        cls, t_SimradDatagramIdentifier::FIL1, "FIL1");
    py_i_DatagramInterface::add_Iterator<SimradDatagramInterface<T_FileStream>, datagrams::RAW3>(
        cls, t_SimradDatagramIdentifier::RAW3, "RAW3");
    py_i_DatagramInterface::add_Iterator<SimradDatagramInterface<T_FileStream>, datagrams::MRU0>(
        cls, t_SimradDatagramIdentifier::MRU0, "MRU0");
    py_i_DatagramInterface::add_Iterator<SimradDatagramInterface<T_FileStream>, datagrams::XML0>(
        cls, t_SimradDatagramIdentifier::XML0, "XML0");
    py_i_DatagramInterface::add_Iterator<SimradDatagramInterface<T_FileStream>, datagrams::NME0>(
        cls, t_SimradDatagramIdentifier::NME0, "NME0");
    py_i_DatagramInterface::add_Iterator<SimradDatagramInterface<T_FileStream>, datagrams::TAG0>(
        cls, t_SimradDatagramIdentifier::TAG0, "TAG0");
    py_i_DatagramInterface::add_Iterator<SimradDatagramInterface<T_FileStream>, datagrams::RAW3>(
        cls, t_SimradDatagramIdentifier::RAW3, "RAW3");
    py_i_DatagramInterface::
        add_Iterator<SimradDatagramInterface<T_FileStream>, datagrams::RAW3, RAW3HeaderFactory>(
            cls, t_SimradDatagramIdentifier::RAW3, "RAW3_header");

    //----- iterators via () operator -----
    cls.def(
        "__call__",
        [](const SimradDatagramInterface<T_FileStream>& self) {
            return py::cast(self.template get_iterator<datagrams::t_SimradDatagramVariant,
                                                       datagrams::SimradDatagramVariant>());
        },
        DOC(themachinethatgoesping,
            echosounders,
            fileinterfaces,
            I_DatagramInterface,
            get_iterator));
    cls.def(
        "__call__",
        [](const SimradDatagramInterface<T_FileStream>& self, t_SimradDatagramIdentifier type) {
            switch (type)
            {
                case t_SimradDatagramIdentifier::MRU0:
                    return py::cast(self.template get_iterator<datagrams::MRU0>(type));
                case t_SimradDatagramIdentifier::NME0:
                    return py::cast(self.template get_iterator<datagrams::NME0>(type));
                case t_SimradDatagramIdentifier::XML0:
                    return py::cast(self.template get_iterator<datagrams::XML0>(type));
                case t_SimradDatagramIdentifier::TAG0:
                    return py::cast(self.template get_iterator<datagrams::TAG0>(type));
                case t_SimradDatagramIdentifier::FIL1:
                    return py::cast(self.template get_iterator<datagrams::FIL1>(type));
                case t_SimradDatagramIdentifier::RAW3:
                    return py::cast(self.template get_iterator<datagrams::RAW3>(type));
                default:
                    return py::cast(self.template get_iterator<datagrams::SimradUnknown>(type));
            }
        },
        DOC(themachinethatgoesping,
            echosounders,
            fileinterfaces,
            I_DatagramInterface,
            get_iterator_2),
        py::arg("datagram_type"));
    cls.def(
        "headers",
        [](const SimradDatagramInterface<T_FileStream>& self) {
            return py::cast(self.template get_iterator<datagrams::SimradDatagram>());
        },
        DOC(themachinethatgoesping,
            echosounders,
            fileinterfaces,
            I_DatagramInterface,
            get_iterator));
    cls.def(
        "headers",
        [](const SimradDatagramInterface<T_FileStream>& self, t_SimradDatagramIdentifier type) {
            return py::cast(self.template get_iterator<datagrams::SimradDatagram>(type));
        },
        DOC(themachinethatgoesping,
            echosounders,
            fileinterfaces,
            I_DatagramInterface,
            get_iterator_2),
        py::arg("datagram_type"));
    cls.def(
        "raw",
        [](const SimradDatagramInterface<T_FileStream>& self) {
            return py::cast(self.template get_iterator<datagrams::SimradUnknown>());
        },
        DOC(themachinethatgoesping,
            echosounders,
            fileinterfaces,
            I_DatagramInterface,
            get_iterator));
    cls.def(
        "raw",
        [](const SimradDatagramInterface<T_FileStream>& self, t_SimradDatagramIdentifier type) {
            return py::cast(self.template get_iterator<datagrams::SimradUnknown>(type));
        },
        DOC(themachinethatgoesping,
            echosounders,
            fileinterfaces,
            I_DatagramInterface,
            get_iterator_2),
        py::arg("datagram_type"));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(SimradDatagramInterface<T_FileStream>);
}

void init_c_datagraminterface(pybind11::module& m)
{

    // add python iterator classes
    using py_fileinterfaces::py_i_DatagramContainer::create_IteratorTypes;

    create_IteratorTypes<datagrams::SimradDatagram, t_SimradDatagramIdentifier>(
        m, "FileSimradRawIterator_Header");
    create_IteratorTypes<datagrams::SimradUnknown, t_SimradDatagramIdentifier>(
        m, "FileSimradRawIterator_Unknown");
    create_IteratorTypes<datagrams::MRU0, t_SimradDatagramIdentifier>(m,
                                                                      "FileSimradRawIterator_MRU0");
    create_IteratorTypes<datagrams::TAG0, t_SimradDatagramIdentifier>(m,
                                                                      "FileSimradRawIterator_TAG0");
    create_IteratorTypes<datagrams::FIL1, t_SimradDatagramIdentifier>(m,
                                                                      "FileSimradRawIterator_FIL1");
    create_IteratorTypes<datagrams::RAW3, t_SimradDatagramIdentifier>(m,
                                                                      "FileSimradRawIterator_RAW3");
    create_IteratorTypes<datagrams::RAW3, t_SimradDatagramIdentifier, RAW3HeaderFactory>(
        m, "FileSimradRawIterator_RAW3_header");
    create_IteratorTypes<datagrams::XML0, t_SimradDatagramIdentifier>(m,
                                                                      "FileSimradRawIterator_XML0");
    create_IteratorTypes<datagrams::NME0, t_SimradDatagramIdentifier>(m,
                                                                      "FileSimradRawIterator_NME0");
    create_IteratorTypes<datagrams::t_SimradDatagramVariant,
                         t_SimradDatagramIdentifier,
                         datagrams::SimradDatagramVariant>(m, "FileSimradRawIterator_Variant");

    py_create_class_SimradDatagramInterface<std::ifstream>(m, "SimradDatagramInterface");
    py_create_class_SimradDatagramInterface<MappedFileStream>(m, "SimradDatagramInterface_mapped");
}

}
}
}
}