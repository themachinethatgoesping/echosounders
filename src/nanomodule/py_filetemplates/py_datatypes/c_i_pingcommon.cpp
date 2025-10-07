// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingcommon.hpp"
#include "i_pingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_I_PingCommon(ARG)                                                                      \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingCommon, ARG)

void init_c_i_pingcommon(nanobind::module_& m)
{
    namespace nb = nanobind;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    nb::enum_<t_pingfeature>(
        m,
        "t_pingfeature",
        DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, t_pingfeature))
        .value("timestamp", t_pingfeature::timestamp)
        .value("datetime", t_pingfeature::datetime)
        .value("channel_id", t_pingfeature::channel_id)
        .value("sensor_configuration", t_pingfeature::sensor_configuration)
        .value("navigation_interpolator_latlon", t_pingfeature::navigation_interpolator_latlon)
        .value("sensor_data_latlon", t_pingfeature::sensor_data_latlon)
        .value("geolocation", t_pingfeature::geolocation)
        .value("bottom", t_pingfeature::bottom)
        .value("watercolumn", t_pingfeature::watercolumn)
        .value("tx_signal_parameters", t_pingfeature::tx_signal_parameters)
        .value("beam_numbers_per_tx_sector", t_pingfeature::beam_numbers_per_tx_sector)
        .value("beam_selection_all", t_pingfeature::beam_selection_all)
        .value("number_of_beams", t_pingfeature::number_of_beams)
        .value("tx_sector_per_beam", t_pingfeature::tx_sector_per_beam)
        .value("number_of_tx_sectors", t_pingfeature::number_of_tx_sectors)
        .value("beam_crosstrack_angles", t_pingfeature::beam_crosstrack_angles)
        .value("two_way_travel_times", t_pingfeature::two_way_travel_times)
        .value("xyz", t_pingfeature::xyz)
        .value("bottom_range_samples", t_pingfeature::bottom_range_samples)
        .value("amplitudes", t_pingfeature::amplitudes)
        .value("ap", t_pingfeature::ap)
        .value("av", t_pingfeature::av)
        .value("power", t_pingfeature::power)
        .value("rp", t_pingfeature::rp)
        .value("rv", t_pingfeature::rv)
        .value("pp", t_pingfeature::pp)
        .value("pv", t_pingfeature::pv)
        .value("sp", t_pingfeature::sp)
        .value("sv", t_pingfeature::sv)
        .value("watercolumn_calibration", t_pingfeature::watercolumn_calibration)
        .value("multisectorwatercolumn_calibration", t_pingfeature::multisectorwatercolumn_calibration);

    tools::nanobind_helper::make_option_class<o_pingfeature>(m, "o_pingfeature");

    auto cls =
        nb::class_<I_PingCommon>(
            m,
            "I_PingCommon",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingCommon));

    py_i_pingcommon::I_PingCommon_add_interface<I_PingCommon>(cls);

    cls __PYCLASS_DEFAULT_COPY__(I_PingCommon)
        __PYCLASS_DEFAULT_PRINTING__(I_PingCommon);
}

}
}
}
}
}