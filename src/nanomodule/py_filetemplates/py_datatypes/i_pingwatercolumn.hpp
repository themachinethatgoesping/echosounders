// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingwatercolumn.hpp"
#include "i_pingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_i_pingwatercolumn {

#define DOC_I_PingWatercolumn(ARG)                                                                \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingWatercolumn, ARG)

namespace pingtools = themachinethatgoesping::echosounders::pingtools;

template<typename T_BaseClass, typename T_PyClass>
void I_PingWatercolumn_add_interface(T_PyClass& cls)
{
    namespace nb = nanobind;

    py_i_pingcommon::I_PingCommon_add_interface<T_BaseClass>(cls);

    cls.def("has_tx_signal_parameters",
            &T_BaseClass::has_tx_signal_parameters,
            DOC_I_PingWatercolumn(has_tx_signal_parameters));
    cls.def("has_number_of_tx_sectors",
            &T_BaseClass::has_number_of_tx_sectors,
            DOC_I_PingWatercolumn(has_number_of_tx_sectors));
    cls.def("has_beam_numbers_per_tx_sector",
            &T_BaseClass::has_beam_numbers_per_tx_sector,
            DOC_I_PingWatercolumn(has_beam_numbers_per_tx_sector));
    cls.def("has_beam_selection_all",
            &T_BaseClass::has_beam_selection_all,
            DOC_I_PingWatercolumn(has_beam_selection_all));
    cls.def("has_number_of_beams",
            &T_BaseClass::has_number_of_beams,
            DOC_I_PingWatercolumn(has_number_of_beams));
    cls.def("has_tx_sector_per_beam",
            &T_BaseClass::has_tx_sector_per_beam,
            DOC_I_PingWatercolumn(has_tx_sector_per_beam));

    cls.def("get_tx_signal_parameters",
            &T_BaseClass::get_tx_signal_parameters,
            DOC_I_PingWatercolumn(get_tx_signal_parameters));
    cls.def("get_number_of_tx_sectors",
            &T_BaseClass::get_number_of_tx_sectors,
            DOC_I_PingWatercolumn(get_number_of_tx_sectors));

    cls.def("get_watercolumn_calibration",
            nb::overload_cast<>(&T_BaseClass::get_watercolumn_calibration, nb::const_),
            DOC_I_PingWatercolumn(get_watercolumn_calibration),
            nb::rv_policy::reference_internal);
    cls.def("get_watercolumn_calibration",
            nb::overload_cast<size_t>(&T_BaseClass::get_watercolumn_calibration, nb::const_),
            DOC_I_PingWatercolumn(get_watercolumn_calibration_2),
            nb::rv_policy::reference_internal,
            nb::arg("sector_nr"));
    cls.def("get_multisectorwatercolumn_calibration",
            &T_BaseClass::get_multisectorwatercolumn_calibration,
            DOC_I_PingWatercolumn(get_multisectorwatercolumn_calibration),
            nb::rv_policy::reference_internal);

    cls.def("get_beam_selection_all",
            nb::overload_cast<>(&T_BaseClass::get_beam_selection_all),
            DOC_I_PingWatercolumn(get_beam_selection_all));
    cls.def("get_number_of_beams",
            &T_BaseClass::get_number_of_beams,
            DOC_I_PingWatercolumn(get_number_of_beams));
    cls.def("get_beam_crosstrack_angles",
            nb::overload_cast<>(&T_BaseClass::get_beam_crosstrack_angles),
            DOC_I_PingWatercolumn(get_beam_crosstrack_angles));
    cls.def("get_beam_crosstrack_angles",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_beam_crosstrack_angles),
            DOC_I_PingWatercolumn(get_beam_crosstrack_angles),
            nb::arg("beam_selection"));
    cls.def("get_beam_alongtrack_angles",
            nb::overload_cast<>(&T_BaseClass::get_beam_alongtrack_angles),
            DOC_I_PingWatercolumn(get_beam_alongtrack_angles));
    cls.def("get_beam_alongtrack_angles",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_beam_alongtrack_angles),
            DOC_I_PingWatercolumn(get_beam_alongtrack_angles),
            nb::arg("beam_selection"));

    cls.def("get_beam_sample_selection_all",
            nb::overload_cast<>(&T_BaseClass::get_beam_sample_selection_all),
            DOC_I_PingWatercolumn(get_beam_sample_selection_all),
            nb::rv_policy::reference_internal);
    cls.def("get_first_sample_offset_per_beam",
            &T_BaseClass::get_first_sample_offset_per_beam,
            DOC_I_PingWatercolumn(get_first_sample_offset_per_beam));
    cls.def("get_number_of_samples_per_beam",
            nb::overload_cast<>(&T_BaseClass::get_number_of_samples_per_beam),
            DOC_I_PingWatercolumn(get_number_of_samples_per_beam));
    cls.def("get_number_of_samples_per_beam",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_number_of_samples_per_beam),
            DOC_I_PingWatercolumn(get_number_of_samples_per_beam_2),
            nb::arg("beam_selection"));

    cls.def("get_tx_sector_per_beam",
            nb::overload_cast<>(&T_BaseClass::get_tx_sector_per_beam),
            DOC_I_PingWatercolumn(get_tx_sector_per_beam));
    cls.def("get_tx_sector_per_beam",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_tx_sector_per_beam),
            DOC_I_PingWatercolumn(get_tx_sector_per_beam_2),
            nb::arg("beam_selection"));
    cls.def("get_beam_numbers_per_tx_sector",
            nb::overload_cast<>(&T_BaseClass::get_beam_numbers_per_tx_sector),
            DOC_I_PingWatercolumn(get_beam_numbers_per_tx_sector));
    cls.def("get_beam_numbers_per_tx_sector",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_beam_numbers_per_tx_sector),
            DOC_I_PingWatercolumn(get_beam_numbers_per_tx_sector),
            nb::arg("beam_selection"));

    cls.def("get_approximate_ranges",
            nb::overload_cast<>(&T_BaseClass::get_approximate_ranges),
            DOC_I_PingWatercolumn(get_approximate_ranges));
    cls.def("get_approximate_ranges",
            nb::overload_cast<const pingtools::BeamSampleSelection&>(&T_BaseClass::get_approximate_ranges),
            DOC_I_PingWatercolumn(get_approximate_ranges),
            nb::arg("beam_sample_selection"));

    cls.def("get_sound_speed_at_transducer",
            &T_BaseClass::get_sound_speed_at_transducer,
            DOC_I_PingWatercolumn(get_sound_speed_at_transducer));
    cls.def("get_sample_interval",
            &T_BaseClass::get_sample_interval,
            DOC_I_PingWatercolumn(get_sample_interval));

    cls.def("has_amplitudes",
            nb::overload_cast<>(&T_BaseClass::has_amplitudes, nb::const_),
            DOC_I_PingWatercolumn(has_amplitudes));
    cls.def("has_ap",
            nb::overload_cast<>(&T_BaseClass::has_ap, nb::const_),
            DOC_I_PingWatercolumn(has_ap));
    cls.def("has_av",
            nb::overload_cast<>(&T_BaseClass::has_av, nb::const_),
            DOC_I_PingWatercolumn(has_av));
    cls.def("has_power",
            nb::overload_cast<>(&T_BaseClass::has_power, nb::const_),
            DOC_I_PingWatercolumn(has_power));
    cls.def("has_rp",
            nb::overload_cast<>(&T_BaseClass::has_rp, nb::const_),
            DOC_I_PingWatercolumn(has_rp));
    cls.def("has_rv",
            nb::overload_cast<>(&T_BaseClass::has_rv, nb::const_),
            DOC_I_PingWatercolumn(has_rv));
    cls.def("has_pp",
            nb::overload_cast<>(&T_BaseClass::has_pp, nb::const_),
            DOC_I_PingWatercolumn(has_pp));
    cls.def("has_pv",
            nb::overload_cast<>(&T_BaseClass::has_pv, nb::const_),
            DOC_I_PingWatercolumn(has_pv));
    cls.def("has_sp",
            nb::overload_cast<>(&T_BaseClass::has_sp, nb::const_),
            DOC_I_PingWatercolumn(has_sp));
    cls.def("has_sv",
            nb::overload_cast<>(&T_BaseClass::has_sv, nb::const_),
            DOC_I_PingWatercolumn(has_sv));
    cls.def("has_watercolumn_calibration",
            nb::overload_cast<>(&T_BaseClass::has_watercolumn_calibration, nb::const_),
            DOC_I_PingWatercolumn(has_watercolumn_calibration));
    cls.def("has_multisectorwatercolumn_calibration",
            nb::overload_cast<>(&T_BaseClass::has_multisectorwatercolumn_calibration, nb::const_),
            DOC_I_PingWatercolumn(has_multisectorwatercolumn_calibration));

    cls.def("get_amplitudes",
            nb::overload_cast<int>(&T_BaseClass::get_amplitudes),
            DOC_I_PingWatercolumn(get_amplitudes),
            nb::arg("mp_cores") = 1);
    cls.def("get_amplitudes",
            nb::overload_cast<const pingtools::BeamSampleSelection&, int>(&T_BaseClass::get_amplitudes),
            DOC_I_PingWatercolumn(get_amplitudes),
            nb::arg("beam_selection"),
            nb::arg("mp_cores") = 1);

    cls.def("get_rp",
            nb::overload_cast<int>(&T_BaseClass::get_rp),
            DOC_I_PingWatercolumn(get_rp),
            nb::arg("mp_cores") = 1);
    cls.def("get_rp",
            nb::overload_cast<const pingtools::BeamSampleSelection&, int>(&T_BaseClass::get_rp),
            DOC_I_PingWatercolumn(get_rp),
            nb::arg("beam_selection"),
            nb::arg("mp_cores") = 1);

    cls.def("get_rv",
            nb::overload_cast<int>(&T_BaseClass::get_rv),
            DOC_I_PingWatercolumn(get_rv),
            nb::arg("mp_cores") = 1);
    cls.def("get_rv",
            nb::overload_cast<const pingtools::BeamSampleSelection&, int>(&T_BaseClass::get_rv),
            DOC_I_PingWatercolumn(get_rv),
            nb::arg("beam_selection"),
            nb::arg("mp_cores") = 1);

    cls.def("get_pp",
            nb::overload_cast<int>(&T_BaseClass::get_pp),
            DOC_I_PingWatercolumn(get_pp),
            nb::arg("mp_cores") = 1);
    cls.def("get_pp",
            nb::overload_cast<const pingtools::BeamSampleSelection&, int>(&T_BaseClass::get_pp),
            DOC_I_PingWatercolumn(get_pp),
            nb::arg("beam_selection"),
            nb::arg("mp_cores") = 1);

    cls.def("get_pv",
            nb::overload_cast<int>(&T_BaseClass::get_pv),
            DOC_I_PingWatercolumn(get_pv),
            nb::arg("mp_cores") = 1);
    cls.def("get_pv",
            nb::overload_cast<const pingtools::BeamSampleSelection&, int>(&T_BaseClass::get_pv),
            DOC_I_PingWatercolumn(get_pv),
            nb::arg("beam_selection"),
            nb::arg("mp_cores") = 1);

    cls.def("get_ap",
            nb::overload_cast<int>(&T_BaseClass::get_ap),
            DOC_I_PingWatercolumn(get_ap),
            nb::arg("mp_cores") = 1);
    cls.def("get_ap",
            nb::overload_cast<const pingtools::BeamSampleSelection&, int>(&T_BaseClass::get_ap),
            DOC_I_PingWatercolumn(get_ap),
            nb::arg("beam_selection"),
            nb::arg("mp_cores") = 1);

    cls.def("get_av",
            nb::overload_cast<int>(&T_BaseClass::get_av),
            DOC_I_PingWatercolumn(get_av),
            nb::arg("mp_cores") = 1);
    cls.def("get_av",
            nb::overload_cast<const pingtools::BeamSampleSelection&, int>(&T_BaseClass::get_av),
            DOC_I_PingWatercolumn(get_av),
            nb::arg("beam_selection"),
            nb::arg("mp_cores") = 1);

    cls.def("get_power",
            nb::overload_cast<int>(&T_BaseClass::get_power),
            DOC_I_PingWatercolumn(get_power),
            nb::arg("mp_cores") = 1);
    cls.def("get_power",
            nb::overload_cast<const pingtools::BeamSampleSelection&, int>(&T_BaseClass::get_power),
            DOC_I_PingWatercolumn(get_power),
            nb::arg("beam_selection"),
            nb::arg("mp_cores") = 1);

    cls.def("get_sp",
            nb::overload_cast<int>(&T_BaseClass::get_sp),
            DOC_I_PingWatercolumn(get_sp),
            nb::arg("mp_cores") = 1);
    cls.def("get_sp",
            nb::overload_cast<const pingtools::BeamSampleSelection&, int>(&T_BaseClass::get_sp),
            DOC_I_PingWatercolumn(get_sp),
            nb::arg("beam_selection"),
            nb::arg("mp_cores") = 1);

    cls.def("get_sv",
            nb::overload_cast<int>(&T_BaseClass::get_sv),
            DOC_I_PingWatercolumn(get_sv),
            nb::arg("mp_cores") = 1);
    cls.def("get_sv",
            nb::overload_cast<const pingtools::BeamSampleSelection&, int>(&T_BaseClass::get_sv),
            DOC_I_PingWatercolumn(get_sv),
            nb::arg("beam_selection"),
            nb::arg("mp_cores") = 1);

    cls.def("has_bottom_range_samples",
            nb::overload_cast<>(&T_BaseClass::has_bottom_range_samples, nb::const_),
            DOC_I_PingWatercolumn(has_bottom_range_samples));
    cls.def("get_bottom_range_samples",
            nb::overload_cast<>(&T_BaseClass::get_bottom_range_samples),
            DOC_I_PingWatercolumn(get_bottom_range_samples));
    cls.def("get_bottom_range_samples",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_bottom_range_samples),
            DOC_I_PingWatercolumn(get_bottom_range_samples),
            nb::arg("beam_selection"));

    cls.def("get_minslant_sample_nr",
            nb::overload_cast<>(&T_BaseClass::get_minslant_sample_nr),
            DOC_I_PingWatercolumn(get_minslant_sample_nr));
    cls.def("get_minslant_sample_nr",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_minslant_sample_nr),
            DOC_I_PingWatercolumn(get_minslant_sample_nr),
            nb::arg("beam_selection"));

    cls.def_prop_rw("_test_mode",
                    &T_BaseClass::get_test_mode,
                    &T_BaseClass::set_test_mode,
                    DOC_I_PingWatercolumn(test_mode));
}

}
}
}
}
}
}
