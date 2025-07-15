// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp>                 // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingwatercolumn.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_I_PingWatercolumn(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingWatercolumn, ARG)

void init_c_i_pingwatercolumn(pybind11::module& m)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls =
        py::class_<I_PingWatercolumn, I_PingCommon, std::shared_ptr<I_PingWatercolumn>>(
            m,
            "I_PingWatercolumn",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingWatercolumn))

            // ----- sector information -----
            .def("has_tx_signal_parameters",
                 &I_PingWatercolumn::has_tx_signal_parameters,
                 DOC_I_PingWatercolumn(has_tx_signal_parameters))
            .def("has_number_of_tx_sectors",
                 &I_PingWatercolumn::has_number_of_tx_sectors,
                 DOC_I_PingWatercolumn(has_number_of_tx_sectors))
            .def("has_beam_numbers_per_tx_sector",
                 &I_PingWatercolumn::has_beam_numbers_per_tx_sector,
                 DOC_I_PingWatercolumn(has_beam_numbers_per_tx_sector))
            .def("has_beam_selection_all",
                 &I_PingWatercolumn::has_beam_selection_all,
                 DOC_I_PingWatercolumn(has_beam_selection_all))
            .def("has_number_of_beams",
                 &I_PingWatercolumn::has_number_of_beams,
                 DOC_I_PingWatercolumn(has_number_of_beams))
            .def("has_tx_sector_per_beam",
                 &I_PingWatercolumn::has_tx_sector_per_beam,
                 DOC_I_PingWatercolumn(has_tx_sector_per_beam))

            .def("get_tx_signal_parameters",
                 &I_PingWatercolumn::get_tx_signal_parameters,
                 DOC_I_PingWatercolumn(get_tx_signal_parameters))
            .def("get_number_of_tx_sectors",
                 &I_PingWatercolumn::get_number_of_tx_sectors,
                 DOC_I_PingWatercolumn(get_number_of_tx_sectors))

            // These functions should be overwritten ...
            .def("get_watercolumn_calibration",
                 py::overload_cast<>(&I_PingWatercolumn::get_watercolumn_calibration, py::const_),
                 DOC_I_PingWatercolumn(get_watercolumn_calibration))
            .def("get_watercolumn_calibration",
                 py::overload_cast<size_t>(&I_PingWatercolumn::get_watercolumn_calibration,
                                           py::const_),
                 DOC_I_PingWatercolumn(get_watercolumn_calibration_2),
                 py::arg("sector_nr"))
            .def("get_multisectorwatercolumn_calibration",
                 &I_PingWatercolumn::get_multisectorwatercolumn_calibration,
                 DOC_I_PingWatercolumn(get_multisectorwatercolumn_calibration))

            // ---- pingwatercolumn interface ----
            .def("get_beam_selection_all",
                 py::overload_cast<>(&I_PingWatercolumn::get_beam_selection_all),
                 DOC_I_PingWatercolumn(get_beam_selection_all))

            .def("get_number_of_beams",
                 &I_PingWatercolumn::get_number_of_beams,
                 DOC_I_PingWatercolumn(get_number_of_beams))
            .def("get_beam_crosstrack_angles",
                 py::overload_cast<>(&I_PingWatercolumn::get_beam_crosstrack_angles),
                 DOC_I_PingWatercolumn(get_beam_crosstrack_angles))
            .def("get_beam_crosstrack_angles",
                 py::overload_cast<const pingtools::BeamSelection&>(
                     &I_PingWatercolumn::get_beam_crosstrack_angles),
                 DOC_I_PingWatercolumn(get_beam_crosstrack_angles),
                 py::arg("beam_selection"))
            .def("get_beam_alongtrack_angles",
                 py::overload_cast<>(&I_PingWatercolumn::get_beam_alongtrack_angles),
                 DOC_I_PingWatercolumn(get_beam_alongtrack_angles))
            .def("get_beam_alongtrack_angles",
                 py::overload_cast<const pingtools::BeamSelection&>(
                     &I_PingWatercolumn::get_beam_alongtrack_angles),
                 DOC_I_PingWatercolumn(get_beam_alongtrack_angles),
                 py::arg("beam_selection"))

            .def("get_beam_sample_selection_all",
                 py::overload_cast<>(&I_PingWatercolumn::get_beam_sample_selection_all),
                 DOC_I_PingWatercolumn(get_beam_sample_selection_all))

            .def("get_first_sample_offset_per_beam",
                 py::overload_cast<>(&I_PingWatercolumn::get_first_sample_offset_per_beam),
                 DOC_I_PingWatercolumn(get_first_sample_offset_per_beam))
            .def("get_number_of_samples_per_beam",
                 py::overload_cast<>(&I_PingWatercolumn::get_number_of_samples_per_beam),
                 DOC_I_PingWatercolumn(get_number_of_samples_per_beam))
            .def("get_number_of_samples_per_beam",
                 py::overload_cast<const pingtools::BeamSelection&>(
                     &I_PingWatercolumn::get_number_of_samples_per_beam),
                 DOC_I_PingWatercolumn(get_number_of_samples_per_beam_2))

            // ----- common parameters -----
            .def("get_tx_sector_per_beam",
                 py::overload_cast<>(&I_PingWatercolumn::get_tx_sector_per_beam),
                 DOC_I_PingWatercolumn(get_tx_sector_per_beam))
            .def("get_tx_sector_per_beam",
                 py::overload_cast<const pingtools::BeamSelection&>(
                     &I_PingWatercolumn::get_tx_sector_per_beam),
                 DOC_I_PingWatercolumn(get_tx_sector_per_beam_2),
                 py::arg("beam_selection"))
            .def("get_beam_numbers_per_tx_sector",
                 py::overload_cast<>(&I_PingWatercolumn::get_beam_numbers_per_tx_sector),
                 DOC_I_PingWatercolumn(get_beam_numbers_per_tx_sector))
            .def("get_beam_numbers_per_tx_sector",
                 py::overload_cast<const pingtools::BeamSelection&>(
                     &I_PingWatercolumn::get_beam_numbers_per_tx_sector),
                 DOC_I_PingWatercolumn(get_beam_numbers_per_tx_sector),
                 py::arg("beam_selection"))
            .def("get_approximate_ranges",
                 py::overload_cast<>(&I_PingWatercolumn::get_approximate_ranges),
                 DOC_I_PingWatercolumn(get_approximate_ranges))
            .def("get_approximate_ranges",
                 py::overload_cast<const pingtools::BeamSampleSelection&>(
                     &I_PingWatercolumn::get_approximate_ranges),
                 DOC_I_PingWatercolumn(get_approximate_ranges),
                 py::arg("beam_sample_selection"))

            .def("get_sound_speed_at_transducer",
                 &I_PingWatercolumn::get_sound_speed_at_transducer,
                 DOC_I_PingWatercolumn(get_sound_speed_at_transducer))

            .def("get_sample_interval",
                 &I_PingWatercolumn::get_sample_interval,
                 DOC_I_PingWatercolumn(get_sample_interval))

            // ----- features -----
            .def("has_amplitudes",
                 py::overload_cast<>(&I_PingWatercolumn::has_amplitudes, py::const_),
                 DOC_I_PingWatercolumn(has_amplitudes))
            .def("has_av",
                 py::overload_cast<>(&I_PingWatercolumn::has_av, py::const_),
                 DOC_I_PingWatercolumn(has_av))
            .def("has_ap",
                 py::overload_cast<>(&I_PingWatercolumn::has_ap, py::const_),
                 DOC_I_PingWatercolumn(has_ap))
            .def("has_power",
                 py::overload_cast<>(&I_PingWatercolumn::has_power, py::const_),
                 DOC_I_PingWatercolumn(has_power))
            .def("has_rp",
                 py::overload_cast<>(&I_PingWatercolumn::has_rp, py::const_),
                 DOC_I_PingWatercolumn(has_rp))
            .def("has_rv",
                 py::overload_cast<>(&I_PingWatercolumn::has_rv, py::const_),
                 DOC_I_PingWatercolumn(has_rv))
            .def("has_pp",
                 py::overload_cast<>(&I_PingWatercolumn::has_pp, py::const_),
                 DOC_I_PingWatercolumn(has_pp))
            .def("has_pv",
                 py::overload_cast<>(&I_PingWatercolumn::has_pv, py::const_),
                 DOC_I_PingWatercolumn(has_pv))
            .def("has_sp",
                 py::overload_cast<>(&I_PingWatercolumn::has_sp, py::const_),
                 DOC_I_PingWatercolumn(has_sp))
            .def("has_sv",
                 py::overload_cast<>(&I_PingWatercolumn::has_sv, py::const_),
                 DOC_I_PingWatercolumn(has_sv))
            .def("has_watercolumn_calibration",
                 py::overload_cast<>(&I_PingWatercolumn::has_watercolumn_calibration, py::const_),
                 DOC_I_PingWatercolumn(has_watercolumn_calibration))
            .def("has_multisectorwatercolumn_calibration",
                 py::overload_cast<>(&I_PingWatercolumn::has_watercolumn_calibration, py::const_),
                 DOC_I_PingWatercolumn(has_watercolumn_calibration))
            .def("get_amplitudes",
                 py::overload_cast<int>(&I_PingWatercolumn::get_amplitudes),
                 DOC_I_PingWatercolumn(get_amplitudes),
                 py::arg("mp_cores") = 1)
            .def("get_amplitudes",
                 py::overload_cast<const pingtools::BeamSampleSelection&, int>(
                     &I_PingWatercolumn::get_amplitudes),
                 DOC_I_PingWatercolumn(get_amplitudes),
                 py::arg("beam_selection"),
                 py::arg("mp_cores") = 1)
            .def("get_rp",
                 py::overload_cast<int>(&I_PingWatercolumn::get_rp),
                 DOC_I_PingWatercolumn(get_rp),
                 py::arg("mp_cores") = 1)
            .def("get_rp",
                 py::overload_cast<const pingtools::BeamSampleSelection&, int>(
                     &I_PingWatercolumn::get_rp),
                 DOC_I_PingWatercolumn(get_rp),
                 py::arg("beam_selection"),
                 py::arg("mp_cores") = 1)
            .def("get_rv",
                 py::overload_cast<int>(&I_PingWatercolumn::get_rv),
                 DOC_I_PingWatercolumn(get_rv),
                 py::arg("mp_cores") = 1)
            .def("get_rv",
                 py::overload_cast<const pingtools::BeamSampleSelection&, int>(
                     &I_PingWatercolumn::get_rv),
                 DOC_I_PingWatercolumn(get_rv),
                 py::arg("beam_selection"),
                 py::arg("mp_cores") = 1)
            .def("get_pp",
                 py::overload_cast<int>(&I_PingWatercolumn::get_pp),
                 DOC_I_PingWatercolumn(get_pp),
                 py::arg("mp_cores") = 1)
            .def("get_pp",
                 py::overload_cast<const pingtools::BeamSampleSelection&, int>(
                     &I_PingWatercolumn::get_pp),
                 DOC_I_PingWatercolumn(get_pp),
                 py::arg("beam_selection"),
                 py::arg("mp_cores") = 1)
            .def("get_pv",
                 py::overload_cast<int>(&I_PingWatercolumn::get_pv),
                 DOC_I_PingWatercolumn(get_pv),
                 py::arg("mp_cores") = 1)
            .def("get_pv",
                 py::overload_cast<const pingtools::BeamSampleSelection&, int>(
                     &I_PingWatercolumn::get_pv),
                 DOC_I_PingWatercolumn(get_pv),
                 py::arg("beam_selection"),
                 py::arg("mp_cores") = 1)
            .def("get_ap",
                 py::overload_cast<int>(&I_PingWatercolumn::get_ap),
                 DOC_I_PingWatercolumn(get_ap),
                 py::arg("mp_cores") = 1)
            .def("get_ap",
                 py::overload_cast<const pingtools::BeamSampleSelection&, int>(
                     &I_PingWatercolumn::get_ap),
                 DOC_I_PingWatercolumn(get_ap),
                 py::arg("beam_selection"),
                 py::arg("mp_cores") = 1)
            .def("get_av",
                 py::overload_cast<int>(&I_PingWatercolumn::get_av),
                 DOC_I_PingWatercolumn(get_av),
                 py::arg("mp_cores") = 1)
            .def("get_av",
                 py::overload_cast<const pingtools::BeamSampleSelection&, int>(
                     &I_PingWatercolumn::get_av),
                 DOC_I_PingWatercolumn(get_av),
                 py::arg("beam_selection"),
                 py::arg("mp_cores") = 1)
            .def("get_power",
                 py::overload_cast<int>(&I_PingWatercolumn::get_power),
                 DOC_I_PingWatercolumn(get_power),
                 py::arg("mp_cores") = 1)
            .def("get_power",
                 py::overload_cast<const pingtools::BeamSampleSelection&, int>(
                     &I_PingWatercolumn::get_power),
                 DOC_I_PingWatercolumn(get_power),
                 py::arg("beam_selection"),
                 py::arg("mp_cores") = 1)
            .def("get_sp",
                 py::overload_cast<int>(&I_PingWatercolumn::get_sp),
                 DOC_I_PingWatercolumn(get_sp),
                 py::arg("mp_cores") = 1)
            .def("get_sp",
                 py::overload_cast<const pingtools::BeamSampleSelection&, int>(
                     &I_PingWatercolumn::get_sp),
                 DOC_I_PingWatercolumn(get_sp),
                 py::arg("beam_selection"),
                 py::arg("mp_cores") = 1)
            .def("get_sv",
                 py::overload_cast<int>(&I_PingWatercolumn::get_sv),
                 DOC_I_PingWatercolumn(get_sv),
                 py::arg("mp_cores") = 1)
            .def("get_sv",
                 py::overload_cast<const pingtools::BeamSampleSelection&, int>(
                     &I_PingWatercolumn::get_sv),
                 DOC_I_PingWatercolumn(get_sv),
                 py::arg("beam_selection"),
                 py::arg("mp_cores") = 1)

            .def("has_bottom_range_samples",
                 py::overload_cast<>(&I_PingWatercolumn::has_bottom_range_samples, py::const_),
                 DOC_I_PingWatercolumn(has_bottom_range_samples))
            .def("get_bottom_range_samples",
                 py::overload_cast<>(&I_PingWatercolumn::get_bottom_range_samples),
                 DOC_I_PingWatercolumn(get_bottom_range_samples))
            .def("get_bottom_range_samples",
                 py::overload_cast<const pingtools::BeamSelection&>(
                     &I_PingWatercolumn::get_bottom_range_samples),
                 DOC_I_PingWatercolumn(get_bottom_range_samples),
                 py::arg("beam_selection"))
            .def("get_minslant_sample_nr",
                 py::overload_cast<>(&I_PingWatercolumn::get_minslant_sample_nr),
                 DOC_I_PingWatercolumn(get_minslant_sample_nr))
            .def("get_minslant_sample_nr",
                 py::overload_cast<const pingtools::BeamSelection&>(
                     &I_PingWatercolumn::get_minslant_sample_nr),
                 DOC_I_PingWatercolumn(get_minslant_sample_nr),
                 py::arg("beam_selection"))

            // internal
            .def_property("_test_mode",
                          &I_PingWatercolumn::get_test_mode,
                          &I_PingWatercolumn::set_test_mode,
                          DOC_I_PingWatercolumn(test_mode))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(I_PingWatercolumn)
        // default printing functions
        // cls __PYCLASS_DEFAULT_PRINTING__(I_PingWatercolumn);
        ;
}

}
}
}
}
}