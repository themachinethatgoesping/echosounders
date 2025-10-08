// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/complex.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

// xtensor python includes
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>


#include <themachinethatgoesping/echosounders/simradraw/filedatatypes/calibration/functions.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {
namespace py_calibration {
namespace py_functions {

namespace nb = nanobind;

#define DOC_SimradRawWaterColumnCalibrationFunctions(ARG)                                          \
    DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, calibration, functions, ARG)

template<typename t_float>
void init_simradrawwatercolumncalibration_functions_(nanobind::module_& m, std::string suffix)
{
    using namespace simradraw::filedatatypes::calibration;

    nb::module_ submodule = m.def_submodule("functions");
    submodule.doc()      = "Functions used for Simrad RAW water column calibration";

    // hann(L) -> xtensor<float,1>
    submodule.def((std::string("hann") + suffix).c_str(),
                  nb::overload_cast<const int>(
                      &functions::compute_hann_window_weights<xt::nanobind::pytensor<t_float, 1>>),
                  DOC_SimradRawWaterColumnCalibrationFunctions(compute_hann_window_weights),
                  nb::arg("length"));

    // chirp(t, f0, tau, f1) -> xtensor<float,1>
    submodule.def((std::string("create_linear_chirp_signal") + suffix).c_str(),
                  nb::overload_cast<const t_float,
                                    const t_float,
                                    const t_float,
                                    const t_float,
                                    const t_float>(
                      &functions::create_linear_chirp_signal<xt::nanobind::pytensor<t_float, 1>>),
                  DOC_SimradRawWaterColumnCalibrationFunctions(create_linear_chirp_signal),
                  nb::arg("f0"),
                  nb::arg("f1"),
                  nb::arg("pulse_duration"),
                  nb::arg("sampling_frequency")  = 1500000,
                  nb::arg("start_phase_degrees") = 90);

    // generateIdealWindowedTransmitSignal(f0, f1, tau, fs, slope)
    // -> tuple(y: xtensor<float,1>, t: xtensor<float,1>)
    submodule.def((std::string("generate_transmit_pulse") + suffix).c_str(),
                  nb::overload_cast<const t_float,
                                    const t_float,
                                    const t_float,
                                    const t_float,
                                    const t_float,
                                    const t_float>(
                      &functions::generate_transmit_pulse<xt::nanobind::pytensor<t_float, 1>>),
                  DOC_SimradRawWaterColumnCalibrationFunctions(generate_transmit_pulse),
                  nb::arg("f0"),
                  nb::arg("f1"),
                  nb::arg("pulse_duration"),
                  nb::arg("slope_factor"),
                  nb::arg("sampling_frequency")  = 1500000,
                  nb::arg("start_phase_degrees") = 0);

    submodule.def(
        "filter_and_decimate_pulse",
        nb::overload_cast<const xt::nanobind::pytensor<t_float, 1>&,
                          const int16_t,
                          const xt::nanobind::pytensor<std::complex<t_float>, 1>&,
                          const int16_t,
                          const xt::nanobind::pytensor<std::complex<t_float>, 1>&,
                          double>(
            &functions::filter_and_decimate_pulse<xt::nanobind::pytensor<t_float, 1>,
                                                  xt::nanobind::pytensor<std::complex<t_float>, 1>>),
        DOC_SimradRawWaterColumnCalibrationFunctions(filter_and_decimate_pulse),
        nb::arg("pulse_amplitudes").noconvert(),
        nb::arg("stage1_decimation_factor"),
        nb::arg("stage1_filter_coefficients"),
        nb::arg("stage2_decimation_factor"),
        nb::arg("stage2_filter_coefficients"),
        nb::arg("sampling_frequency") = 1500000);

    submodule.def(
        "compute_effective_pulse_duration_cw",
        nb::overload_cast<const xt::nanobind::pytensor<std::complex<t_float>, 1>&, const t_float, const bool>(
            &functions::compute_effective_pulse_duration_cw<xt::nanobind::pytensor<std::complex<t_float>, 1>,
                                                            t_float>),
        DOC_SimradRawWaterColumnCalibrationFunctions(compute_effective_pulse_duration_cw),
        nb::arg("pulse_amplitudes").noconvert(),
        nb::arg("sample_interval"),
        nb::arg("round_to_full_samples") = true);

    submodule.def(
        "compute_effective_pulse_duration_cw",
        nb::overload_cast<const xt::nanobind::pytensor<std::complex<t_float>, 1>&,
                          const xt::nanobind::pytensor<t_float, 1>&>(
            &functions::compute_effective_pulse_duration_cw<xt::nanobind::pytensor<std::complex<t_float>, 1>,
                                                            xt::nanobind::pytensor<t_float, 1>>),
        DOC_SimradRawWaterColumnCalibrationFunctions(compute_effective_pulse_duration_cw),
        nb::arg("pulse_amplitudes").noconvert(),
        nb::arg("pulse_times"));
}

void init_simradrawwatercolumncalibration_functions(nanobind::module_& m)
{
    init_simradrawwatercolumncalibration_functions_<float>(m, "_f");
    init_simradrawwatercolumncalibration_functions_<double>(m, "_d");
}

} // namespace py_functions
} // namespace py_calibration
} // namespace py_filedatatypes
} // namespace py_simradraw
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
