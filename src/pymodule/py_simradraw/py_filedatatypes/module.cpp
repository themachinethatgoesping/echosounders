// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {

namespace py = pybind11;

// -- submodule declarations --
namespace py_cache_structures {
void init_c_simradrawfilepackageindex(pybind11::module& m); // c_simradrawfilepackageindex.cpp
}

namespace py_sub {
void init_c_transceiverinformation(pybind11::module& m); // sub/c_transceiverinformation.cpp
}

void init_c_simradrawpingcommon(pybind11::module& m);      // c_simradrawpingcommon.cpp
void init_c_simradrawping(pybind11::module& m);            // c_simradrawping.cpp
void init_c_simradrawpingfiledata(pybind11::module& m);    // c_simradrawpingfiledata.cpp
void init_c_simradrawpingbottom(pybind11::module& m);      // c_simradrawpingbottom.cpp
void init_c_simradrawpingwatercolumn(pybind11::module& m); // c_simradrawpingwatercolumn.cpp

// -- create submodule --
void init_m_simradrawfiledatatypes(pybind11::module& m)
{
    auto subm = m.def_submodule("filetypes", "SimradRaw EK60 and EK80 file data types");
    py_cache_structures::init_c_simradrawfilepackageindex(subm);
    py_sub::init_c_transceiverinformation(subm);
    init_c_simradrawpingfiledata(subm);
    init_c_simradrawpingcommon(subm);
    init_c_simradrawpingbottom(subm);
    init_c_simradrawpingwatercolumn(subm);
    init_c_simradrawping(subm);
}

}
}
}
}
}
