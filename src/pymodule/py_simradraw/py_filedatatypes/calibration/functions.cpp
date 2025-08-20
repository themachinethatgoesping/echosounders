// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pytensor.hpp>                 // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>


#include <themachinethatgoesping/echosounders/simradraw/filedatatypes/calibration/functions.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {
namespace py_calibration {
namespace py_functions {

namespace py = pybind11;

#define DOC_SimradRawWaterColumnCalibrationFunctions(ARG)                                          \
    DOC(themachinethatgoesping, echosounders, simradraw, filedatatypes, calibration, functions, ARG)

template<typename t_float>
void init_simradrawwatercolumncalibration_functions_(pybind11::module& m, std::string suffix)
{
    using namespace simradraw::filedatatypes::calibration;

    py::module submodule = m.def_submodule("functions");
    submodule.doc()      = "Functions used for Simrad RAW water column calibration";

    // hann(L) -> xtensor<float,1>
    submodule.def((std::string("hann") + suffix).c_str(),
                  py::overload_cast<const int>(
                      &functions::compute_hann_window_weights<xt::pytensor<t_float, 1>>),
                  DOC_SimradRawWaterColumnCalibrationFunctions(compute_hann_window_weights),
                  py::arg("length"));

    // chirp(t, f0, tau, f1) -> xtensor<float,1>
    submodule.def((std::string("create_linear_chirp_signal") + suffix).c_str(),
                  py::overload_cast<const t_float,
                                    const t_float,
                                    const t_float,
                                    const t_float,
                                    const t_float>(
                      &functions::create_linear_chirp_signal<xt::pytensor<t_float, 1>>),
                  DOC_SimradRawWaterColumnCalibrationFunctions(create_linear_chirp_signal),
                  py::arg("f0"),
                  py::arg("f1"),
                  py::arg("pulse_duration"),
                  py::arg("sampling_frequency")  = 1500000,
                  py::arg("start_phase_degrees") = 90);

    // generateIdealWindowedTransmitSignal(f0, f1, tau, fs, slope)
    // -> tuple(y: xtensor<float,1>, t: xtensor<float,1>)
    submodule.def((std::string("generate_transmit_pulse") + suffix).c_str(),
                  py::overload_cast<const t_float,
                                    const t_float,
                                    const t_float,
                                    const t_float,
                                    const t_float,
                                    const t_float>(
                      &functions::generate_transmit_pulse<xt::pytensor<t_float, 1>>),
                  DOC_SimradRawWaterColumnCalibrationFunctions(generate_transmit_pulse),
                  py::arg("f0"),
                  py::arg("f1"),
                  py::arg("pulse_duration"),
                  py::arg("slope_factor"),
                  py::arg("sampling_frequency")  = 1500000,
                  py::arg("start_phase_degrees") = 0);

    submodule.def(
        "filter_and_decimate_pulse",
        py::overload_cast<const xt::pytensor<t_float, 1>&,
                          const int16_t,
                          const xt::pytensor<std::complex<t_float>, 1>&,
                          const int16_t,
                          const xt::pytensor<std::complex<t_float>, 1>&,
                          double>(
            &functions::filter_and_decimate_pulse<xt::pytensor<t_float, 1>,
                                                  xt::pytensor<std::complex<t_float>, 1>>),
        DOC_SimradRawWaterColumnCalibrationFunctions(filter_and_decimate_pulse),
        py::arg("pulse_amplitudes").noconvert(),
        py::arg("stage1_decimation_factor"),
        py::arg("stage1_filter_coefficients"),
        py::arg("stage2_decimation_factor"),
        py::arg("stage2_filter_coefficients"),
        py::arg("sampling_frequency") = 1500000);

    submodule.def(
        "compute_effective_pulse_duration_cw",
        py::overload_cast<const xt::pytensor<std::complex<t_float>, 1>&, const t_float, const bool>(
            &functions::compute_effective_pulse_duration_cw<xt::pytensor<std::complex<t_float>, 1>,
                                                            t_float>),
        DOC_SimradRawWaterColumnCalibrationFunctions(compute_effective_pulse_duration_cw),
        py::arg("pulse_amplitudes").noconvert(),
        py::arg("sample_interval"),
        py::arg("round_to_full_samples") = true);

    submodule.def(
        "compute_effective_pulse_duration_cw",
        py::overload_cast<const xt::pytensor<std::complex<t_float>, 1>&,
                          const xt::pytensor<t_float, 1>&>(
            &functions::compute_effective_pulse_duration_cw<xt::pytensor<std::complex<t_float>, 1>,
                                                            xt::pytensor<t_float, 1>>),
        DOC_SimradRawWaterColumnCalibrationFunctions(compute_effective_pulse_duration_cw),
        py::arg("pulse_amplitudes").noconvert(),
        py::arg("pulse_times"));
}

void init_simradrawwatercolumncalibration_functions(pybind11::module& m)
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
