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

#define CLASS_FILERAW(T_FILE_RAW, CLASS_NAME)                                                      \
    py::class_<T_FILE_RAW>( \
            m, CLASS_NAME, DOC(themachinethatgoesping, echosounders, simrad, FileRaw)) \
        /* constructors */\
        __INPUTFILE_DEFAULT_CONSTRUCTORS__(T_FILE_RAW)\
        /* inputfile interface */\
        __INPUTFILE_INTERFACE__(T_FILE_RAW)\
        /* package reading */ \
        __INPUTFILE_PACKAGE_READING__(\
            T_FILE_RAW, datagrams::t_EK60_DatagramVariant, datagrams::EK60_DatagramVariant)\
            \
        /* iterators */ \
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Datagram, t_EK60_DatagramType::ek60_header, "Header") \
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::FIL1, "FIL1") \
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::MRU0, "MRU0")\
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::NME0, "NME0")\
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::RAW3, "RAW3")\
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::XML0, "XML0")\
        ADD_ITERATOR(T_FILE_RAW, datagrams::EK60_Unknown, t_EK60_DatagramType::TAG0, "TAG0")\
\
        /* default copy functions */ \
        /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/\
        /* default binary functions*/\
        /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/\
        /* default printing functions */\
        __PYCLASS_DEFAULT_PRINTING__(T_FILE_RAW) \
        /* end T_FILE_RAW */

void init_c_fileraw(pybind11::module& m)
{
    xt::import_numpy(); // import numpy for xtensor (otherwise there will be weird segfaults)

    ADD_ITERATOR_TYPES(m, "FileRawIterator_Header", datagrams::EK60_Datagram, t_EK60_DatagramType);
    ADD_ITERATOR_TYPES(m, "FileRawIterator_Unknown", datagrams::EK60_Unknown, t_EK60_DatagramType);

    CLASS_FILERAW(FileRaw<std::ifstream>, "FileRaw");
    CLASS_FILERAW(FileRaw<MappedFileStream>, "FileRaw_mapped");

    // create string of all possible enum values

    // test(PyFileRaw, t_EK60_DatagramType::ek60_header);
}
