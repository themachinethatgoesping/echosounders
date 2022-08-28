// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0
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

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

struct A
{
    ek60_long a;
    ek60_long b;

    A() = default;
};

void init_c_fileraw(pybind11::module& m)
{
    xt::import_numpy(); // import numpy for xtensor (otherwise there will be weird segfaults)

    py::class_<datagrams::EK60_DatagramVariant> (m, "EK60_DatagramVariant", DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_DatagramVariant));

    py::class_<FileRaw> PyFileRaw(
        m, "FileRaw", DOC(themachinethatgoesping, echosounders, simrad, FileRaw));
    PyFileRaw
        // constructors
        __INPUTFILE_DEFAULT_CONSTRUCTORS__(FileRaw)
        // inputfile interface
        __INPUTFILE_INTERFACE__(FileRaw)
        // package reading
        //__INPUTFILE_PACKAGE_READING__(FileRaw, datagrams::EK60_DatagramVariant, datagrams::EK60_DatagramVariant)
        __INPUTFILE_PACKAGE_READING__(FileRaw, datagrams::EK60_Unknown, datagrams::EK60_Unknown)

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
            // more methods
            .def(
                "read_datagram_headers",
                [](FileRaw& self, const xt::pyarray<size_t> indices) {
                    std::vector<datagrams::EK60_Datagram> datagram_headers;
                    // xt::pyarray<datagrams::EK60_Datagram> datagram_headers_pyarray;

                    datagram_headers.reserve(indices.size());
                    themachinethatgoesping::tools::progressbars::ProgressIndicator pbar;
                    pbar.init(0, indices.size(), "reading headers");
                    for (const auto& index : indices)
                    {
                        datagram_headers.push_back(self.read_datagram_header(index));
                        pbar.tick();
                    }
                    pbar.close();
                    return datagram_headers;
                },
                py::call_guard<py::scoped_ostream_redirect>(),
                DOC(themachinethatgoesping,
                    echosounders,
                    fileinterfaces,
                    I_InputFile,
                    read_datagram_header),
                py::arg("indices"))

        // default copy functions
        // __PYCLASS_DEFAULT_COPY__(LinearInterpolator)
        // // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(FileRaw)
        // end FileRaw
        ;

}
