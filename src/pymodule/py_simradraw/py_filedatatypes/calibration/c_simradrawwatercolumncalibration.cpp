// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pytensor.hpp>                 // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include <themachinethatgoesping/echosounders/simradraw/filedatatypes/calibration/simradrawwatercolumncalibration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {
namespace py_calibration {

namespace py = pybind11;

#define DOC_SimradRawWaterColumnCalibration(ARG)                                                   \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                 \
        filedatatypes,                                                                             \
        calibration,                                                                               \
        SimradRawWaterColumnCalibration,                                                           \
        ARG)

void init_c_simradrawwatercolumncalibration(pybind11::module& m)
{
    using namespace themachinethatgoesping::echosounders::simradraw;
    using namespace themachinethatgoesping::echosounders::simradraw::filedatatypes::calibration;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;

    // add class
    auto c =
        py::class_<SimradRawWaterColumnCalibration,
                   WaterColumnCalibration,
                   std::shared_ptr<SimradRawWaterColumnCalibration>>(
            m,
            "SimradRawWaterColumnCalibration",
            DOC(themachinethatgoesping,
                echosounders,
                simradraw,
                filedatatypes,
                calibration,
                SimradRawWaterColumnCalibration))
            .def(py::init<>(), DOC_SimradRawWaterColumnCalibration(SimradRawWaterColumnCalibration))
            .def(py::init<const datagrams::xml_datagrams::XML_Environment&,
                          const datagrams::xml_datagrams::XML_Parameter_Channel&,
                          const filedatatypes::_sub::TransceiverInformation&,
                          size_t>(),
                 DOC_SimradRawWaterColumnCalibration(SimradRawWaterColumnCalibration_3),
                 py::arg("environment"),
                 py::arg("parameters"),
                 py::arg("transceiver_information"),
                 py::arg("n_complex_samples"))

            // ----- setters -----
            .def("set_transducer_parameters",
                 py::overload_cast<
                     const datagrams::xml_datagrams::XMLConfigurationTransceiverChannelTransducer&,
                     size_t,
                     bool>(&SimradRawWaterColumnCalibration::set_transducer_parameters),
                 DOC_SimradRawWaterColumnCalibration(set_transducer_parameters),
                 py::arg("transducer"),
                 py::arg("pulse_duration_index"),
                 py::arg("init_calibration") = true)
            .def("set_transducer_parameters",
                 py::overload_cast<float, float, float, float, bool>(
                     &SimradRawWaterColumnCalibration::set_transducer_parameters),
                 DOC_SimradRawWaterColumnCalibration(set_transducer_parameters_2),
                 py::arg("transducer_gain_db"),
                 py::arg("sa_correction_db"),
                 py::arg("equivalent_beam_angle_db"),
                 py::arg("frequency_nominal_hz"),
                 py::arg("init_calibration") = true)
            .def("set_environment_parameters",
                 py::overload_cast<const datagrams::xml_datagrams::XML_Environment&, bool>(
                     &SimradRawWaterColumnCalibration::set_environment_parameters),
                 DOC_SimradRawWaterColumnCalibration(set_environment_parameters),
                 py::arg("environment"),
                 py::arg("init_calibration") = true)
            .def("set_environment_parameters",
                 py::overload_cast<float, float, float, bool>(
                     &SimradRawWaterColumnCalibration::set_environment_parameters),
                 DOC_SimradRawWaterColumnCalibration(set_environment_parameters_2),
                 py::arg("reference_depth_m"),
                 py::arg("temperature_c"),
                 py::arg("salinity_psu"),
                 py::arg("init_calibration") = true)
            .def("set_runtime_parameters",
                 py::overload_cast<const datagrams::xml_datagrams::XML_Parameter_Channel&, bool>(
                     &SimradRawWaterColumnCalibration::set_runtime_parameters),
                 DOC_SimradRawWaterColumnCalibration(set_runtime_parameters),
                 py::arg("parameters"),
                 py::arg("init_calibration") = true)
            .def("set_runtime_parameters",
                 py::overload_cast<float, float, float, bool>(
                     &SimradRawWaterColumnCalibration::set_runtime_parameters),
                 DOC_SimradRawWaterColumnCalibration(set_runtime_parameters_2),
                 py::arg("frequency_hz"),
                 py::arg("transmit_power_w"),
                 py::arg("effective_pulse_duration_s"),
                 py::arg("init_calibration") = true)
            .def("set_power_calibration_parameters",
                 &SimradRawWaterColumnCalibration::set_power_calibration_parameters,
                 DOC_SimradRawWaterColumnCalibration(set_power_calibration_parameters),
                 py::arg("n_complex_samples"),
                 py::arg("impedance_factor") = std::nullopt,
                 py::arg("init_calibration") = true)
            .def("set_optional_parameters",
                 &SimradRawWaterColumnCalibration::set_optional_parameters,
                 DOC_SimradRawWaterColumnCalibration(set_optional_parameters),
                 py::arg("rounded_latitude_deg")  = std::nullopt,
                 py::arg("rounded_longitude_deg") = std::nullopt,
                 py::arg("init_calibration")      = true)

            //--- getters ---
            .def("get_transducer_gain_db",
                 &SimradRawWaterColumnCalibration::get_transducer_gain_db,
                 DOC_SimradRawWaterColumnCalibration(get_transducer_gain_db))
            .def("get_sa_correction_db",
                 &SimradRawWaterColumnCalibration::get_sa_correction_db,
                 DOC_SimradRawWaterColumnCalibration(get_sa_correction_db))
            .def("get_equivalent_beam_angle_db",
                 &SimradRawWaterColumnCalibration::get_equivalent_beam_angle_db,
                 DOC_SimradRawWaterColumnCalibration(get_equivalent_beam_angle_db))
            .def("get_frequency_nominal_hz",
                 &SimradRawWaterColumnCalibration::get_frequency_nominal_hz,
                 DOC_SimradRawWaterColumnCalibration(get_frequency_nominal_hz))

            .def("get_reference_depth_m",
                 &SimradRawWaterColumnCalibration::get_reference_depth_m,
                 DOC_SimradRawWaterColumnCalibration(get_reference_depth_m))
            .def("get_temperature_c",
                 &SimradRawWaterColumnCalibration::get_temperature_c,
                 DOC_SimradRawWaterColumnCalibration(get_temperature_c))
            .def("get_salinity_psu",
                 &SimradRawWaterColumnCalibration::get_salinity_psu,
                 DOC_SimradRawWaterColumnCalibration(get_salinity_psu))

            .def("get_frequency_hz",
                 &SimradRawWaterColumnCalibration::get_frequency_hz,
                 DOC_SimradRawWaterColumnCalibration(get_frequency_hz))
            .def("get_transmit_power_w",
                 &SimradRawWaterColumnCalibration::get_transmit_power_w,
                 DOC_SimradRawWaterColumnCalibration(get_transmit_power_w))
            .def("get_effective_pulse_duration_s",
                 &SimradRawWaterColumnCalibration::get_effective_pulse_duration_s,
                 DOC_SimradRawWaterColumnCalibration(get_effective_pulse_duration_s))

            .def("get_sound_velocity_m_s",
                 &SimradRawWaterColumnCalibration::get_sound_velocity_m_s,
                 DOC_SimradRawWaterColumnCalibration(get_sound_velocity_m_s))
            .def("get_absorption_db_m",
                 &SimradRawWaterColumnCalibration::get_absorption_db_m,
                 DOC_SimradRawWaterColumnCalibration(get_absorption_db_m))
            .def("get_wavelength_m",
                 &SimradRawWaterColumnCalibration::get_wavelength_m,
                 DOC_SimradRawWaterColumnCalibration(get_wavelength_m))
            .def("get_corr_transducer_gain_db",
                 &SimradRawWaterColumnCalibration::get_corr_transducer_gain_db,
                 DOC_SimradRawWaterColumnCalibration(get_corr_transducer_gain_db))
            .def("get_corr_equivalent_beam_angle_db",
                 &SimradRawWaterColumnCalibration::get_corr_equivalent_beam_angle_db,
                 DOC_SimradRawWaterColumnCalibration(get_corr_equivalent_beam_angle_db))

            .def("get_n_complex_samples",
                 &SimradRawWaterColumnCalibration::get_n_complex_samples,
                 DOC_SimradRawWaterColumnCalibration(get_n_complex_samples))
            .def("get_power_conversion_factor_db",
                 &SimradRawWaterColumnCalibration::get_power_conversion_factor_db,
                 DOC_SimradRawWaterColumnCalibration(get_power_conversion_factor_db))

            .def("get_rounded_latitude_deg",
                 &SimradRawWaterColumnCalibration::get_rounded_latitude_deg,
                 DOC_SimradRawWaterColumnCalibration(get_rounded_latitude_deg))
            .def("get_rounded_longitude_deg",
                 &SimradRawWaterColumnCalibration::get_rounded_longitude_deg,
                 DOC_SimradRawWaterColumnCalibration(get_rounded_longitude_deg))

            // ----- setup calibration for simradraw systems ----
            .def("setup_simrad_calibration",
                 &SimradRawWaterColumnCalibration::setup_simrad_calibration,
                 DOC_SimradRawWaterColumnCalibration(setup_simrad_calibration))
            .def("initialized",
                 &SimradRawWaterColumnCalibration::initialized,
                 DOC_SimradRawWaterColumnCalibration(initialized))
            .def("check_initialized",
                 &SimradRawWaterColumnCalibration::check_initialized,
                 DOC_SimradRawWaterColumnCalibration(check_initialized))
            .def("check_can_be_initialized",
                 &SimradRawWaterColumnCalibration::check_can_be_initialized,
                 DOC_SimradRawWaterColumnCalibration(check_can_be_initialized))

            // ----- operators -----
            .def("__eq__",
                 &SimradRawWaterColumnCalibration::operator==,
                 DOC_SimradRawWaterColumnCalibration(operator_eq),
                 py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SimradRawWaterColumnCalibration)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SimradRawWaterColumnCalibration)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SimradRawWaterColumnCalibration)
        // end SimradRawWaterColumnCalibration
        ;
}
}
}
}
}
}
}