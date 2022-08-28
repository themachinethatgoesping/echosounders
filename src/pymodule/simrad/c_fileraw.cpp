// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <xtensor/xmath.hpp> // xtensor import for the C++ universal functions
#define FORCE_IMPORT_ARRAY
#include <xtensor-python/pyarray.hpp> // Numpy bindings

#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/ek60_datagrams.hpp"
#include "../../themachinethatgoesping/echosounders/simrad/fileraw.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_inputfile.hpp"
#include "../fileinterfaces/i_inputfileiterator.hpp"

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;



void init_c_fileraw(pybind11::module& m)
{
    xt::import_numpy(); // import numpy for xtensor (otherwise there will be weird segfaults)

    ADD_ITERATOR_TYPE(m, "FileRawIterator_Header", datagrams::EK60_Datagram, t_EK60_DatagramType);
    ADD_ITERATOR_TYPE(m, "FileRawIterator_Unknown", datagrams::EK60_Unknown, t_EK60_DatagramType);

    auto PyFileRaw =
        py::class_<FileRaw>(
            m, "FileRaw", DOC(themachinethatgoesping, echosounders, simrad, FileRaw))
        // constructors
        __INPUTFILE_DEFAULT_CONSTRUCTORS__(FileRaw)
        // inputfile interface
        __INPUTFILE_INTERFACE__(FileRaw)
        // package reading
        __INPUTFILE_PACKAGE_READING__(
            FileRaw, datagrams::t_EK60_DatagramVariant, datagrams::EK60_DatagramVariant)
            //__INPUTFILE_PACKAGE_READING__(FileRaw, datagrams::EK60_Unknown,
            // datagrams::EK60_Unknown)

            .def("get_header",
                 &FileRaw::get_datagram<datagrams::EK60_Datagram>,
                 DOC(themachinethatgoesping,
                     echosounders,
                     fileinterfaces,
                     I_InputFile,
                     get_datagram),
                 py::arg("index"))
            .def("get_unknown",
                 &FileRaw::get_datagram<datagrams::EK60_Unknown>,
                 DOC(themachinethatgoesping,
                     echosounders,
                     fileinterfaces,
                     I_InputFile,
                     get_datagram),
                 py::arg("index"))
        // iterators
        ADD_ITERATOR(FileRaw, datagrams::EK60_Datagram, t_EK60_DatagramType::ek60_header, "Header")
        ADD_ITERATOR(FileRaw, datagrams::EK60_Unknown, t_EK60_DatagramType::FIL1, "FIL1")
        ADD_ITERATOR(FileRaw, datagrams::EK60_Unknown, t_EK60_DatagramType::MRU0, "MRU0")
        ADD_ITERATOR(FileRaw, datagrams::EK60_Unknown, t_EK60_DatagramType::NME0, "NME0")
        ADD_ITERATOR(FileRaw, datagrams::EK60_Unknown, t_EK60_DatagramType::RAW3, "RAW3")
        ADD_ITERATOR(FileRaw, datagrams::EK60_Unknown, t_EK60_DatagramType::XML0, "XML0")
        ADD_ITERATOR(FileRaw, datagrams::EK60_Unknown, t_EK60_DatagramType::TAG0, "TAG0")

        // default copy functions
        // __PYCLASS_DEFAULT_COPY__(LinearInterpolator)
        // // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(FileRaw)
        // end FileRaw
        ;


    // create string of all possible enum values

    // test(PyFileRaw, t_EK60_DatagramType::ek60_header);
}
