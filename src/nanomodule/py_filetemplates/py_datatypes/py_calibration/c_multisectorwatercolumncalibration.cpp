// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/stl/string.h>
#include <nanobind/stl/optional.h>

// xtensor python includes
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/calibration/multisectorwatercolumncalibration.hpp>
#include <themachinethatgoesping/echosounders/kongsbergall/filedatatypes/calibration/kongsbergallwatercolumncalibration.hpp>

#include "c_multisectorwatercolumncalibration.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_calibration {

namespace nb = nanobind;


void init_c_multisectorwatercolumncalibration(nanobind::module_& m)
{
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;
    using namespace themachinethatgoesping::echosounders::kongsbergall::filedatatypes::calibration;

    init_multisectorcalibration<WaterColumnCalibration>(m, "MultiSectorWaterColumnCalibration");
}

}
}
}
}
}
}