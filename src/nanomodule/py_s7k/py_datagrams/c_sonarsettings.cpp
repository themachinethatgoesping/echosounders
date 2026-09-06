// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/sonarsettings.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;

#define DOC_C(CLASS, ...) DOC(themachinethatgoesping, echosounders, s7k, datagrams, CLASS, __VA_ARGS__)
#define DOC_SonarSettings(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, s7k, datagrams, SonarSettings, ARG)

void init_c_sonarsettings(nb::module_& m)
{
    using t_tx_pulse_type       = SonarSettings::t_tx_pulse_type;
    using o_tx_pulse_type       = SonarSettings::o_tx_pulse_type;
    using t_tx_pulse_envelope   = SonarSettings::t_tx_pulse_envelope;
    using o_tx_pulse_envelope   = SonarSettings::o_tx_pulse_envelope;
    using t_tx_pulse_mode       = SonarSettings::t_tx_pulse_mode;
    using o_tx_pulse_mode       = SonarSettings::o_tx_pulse_mode;
    using t_projector_weighting = SonarSettings::t_projector_weighting;
    using o_projector_weighting = SonarSettings::o_projector_weighting;
    using t_rx_weighting        = SonarSettings::t_rx_weighting;
    using o_rx_weighting        = SonarSettings::o_rx_weighting;
    namespace nbh               = themachinethatgoesping::tools::nanobind_helper;

    nb::enum_<t_tx_pulse_type>(m, "SonarSettings_t_tx_pulse_type", "transmit pulse type")
        .value("cw", t_tx_pulse_type::cw, "CW")
        .value("chirp", t_tx_pulse_type::chirp, "linear chirp (FM)");
    nbh::make_option_class<o_tx_pulse_type>(m, "SonarSettings_o_tx_pulse_type");

    nb::enum_<t_tx_pulse_envelope>(
        m, "SonarSettings_t_tx_pulse_envelope", "transmit pulse envelope")
        .value("tapered_rectangular", t_tx_pulse_envelope::tapered_rectangular, "tapered rectangular")
        .value("tukey", t_tx_pulse_envelope::tukey, "Tukey")
        .value("hamming", t_tx_pulse_envelope::hamming, "Hamming")
        .value("han", t_tx_pulse_envelope::han, "Han")
        .value("rectangular", t_tx_pulse_envelope::rectangular, "rectangular");
    nbh::make_option_class<o_tx_pulse_envelope>(m, "SonarSettings_o_tx_pulse_envelope");

    nb::enum_<t_tx_pulse_mode>(m, "SonarSettings_t_tx_pulse_mode", "transmit pulse mode")
        .value("undefined", t_tx_pulse_mode::undefined, "undefined")
        .value("single_ping", t_tx_pulse_mode::single_ping, "single ping")
        .value("multi_ping_2", t_tx_pulse_mode::multi_ping_2, "multi-ping 2")
        .value("multi_ping_3", t_tx_pulse_mode::multi_ping_3, "multi-ping 3")
        .value("multi_ping_4", t_tx_pulse_mode::multi_ping_4, "multi-ping 4");
    nbh::make_option_class<o_tx_pulse_mode>(m, "SonarSettings_o_tx_pulse_mode");

    nb::enum_<t_projector_weighting>(
        m, "SonarSettings_t_projector_weighting", "projector beam weighting window type")
        .value("rectangular", t_projector_weighting::rectangular, "rectangular")
        .value("chebychev", t_projector_weighting::chebychev, "Chebychev")
        .value("gauss", t_projector_weighting::gauss, "Gauss");
    nbh::make_option_class<o_projector_weighting>(m, "SonarSettings_o_projector_weighting");

    nb::enum_<t_rx_weighting>(
        m, "SonarSettings_t_rx_weighting", "receive beam weighting window")
        .value("chebychev", t_rx_weighting::chebychev, "Chebychev")
        .value("kaiser", t_rx_weighting::kaiser, "Kaiser");
    nbh::make_option_class<o_rx_weighting>(m, "SonarSettings_o_rx_weighting");

    nb::class_<SonarSettings, S7KDatagram>(m, "SonarSettings", DOC(themachinethatgoesping, echosounders, s7k, datagrams, SonarSettings))
        .def(nb::init<>(), DOC_C(SonarSettings, SonarSettings))
        .def("get_serial_number", &SonarSettings::get_serial_number, DOC_C(SonarSettings, Content, serial_number))
        .def("set_serial_number", &SonarSettings::set_serial_number, DOC_C(SonarSettings, Content, serial_number), nb::arg("val"))
        .def("get_ping_number", &SonarSettings::get_ping_number, DOC_C(SonarSettings, Content, ping_number))
        .def("set_ping_number", &SonarSettings::set_ping_number, DOC_C(SonarSettings, Content, ping_number), nb::arg("val"))
        .def("get_multi_ping", &SonarSettings::get_multi_ping, DOC_C(SonarSettings, Content, multi_ping))
        .def("set_multi_ping", &SonarSettings::set_multi_ping, DOC_C(SonarSettings, Content, multi_ping), nb::arg("val"))
        .def("get_frequency", &SonarSettings::get_frequency, DOC_C(SonarSettings, Content, frequency))
        .def("set_frequency", &SonarSettings::set_frequency, DOC_C(SonarSettings, Content, frequency), nb::arg("val"))
        .def("get_sample_rate", &SonarSettings::get_sample_rate, DOC_C(SonarSettings, Content, sample_rate))
        .def("set_sample_rate", &SonarSettings::set_sample_rate, DOC_C(SonarSettings, Content, sample_rate), nb::arg("val"))
        .def("get_receiver_bandwidth", &SonarSettings::get_receiver_bandwidth, DOC_C(SonarSettings, Content, receiver_bandwidth))
        .def("set_receiver_bandwidth", &SonarSettings::set_receiver_bandwidth, DOC_C(SonarSettings, Content, receiver_bandwidth), nb::arg("val"))
        .def("get_tx_pulse_width", &SonarSettings::get_tx_pulse_width, DOC_C(SonarSettings, Content, tx_pulse_width))
        .def("set_tx_pulse_width", &SonarSettings::set_tx_pulse_width, DOC_C(SonarSettings, Content, tx_pulse_width), nb::arg("val"))
        .def("get_tx_pulse_type", &SonarSettings::get_tx_pulse_type, DOC_C(SonarSettings, Content, tx_pulse_type))
        .def("set_tx_pulse_type", &SonarSettings::set_tx_pulse_type, DOC_C(SonarSettings, Content, tx_pulse_type), nb::arg("val"))
        .def("get_tx_pulse_envelope", &SonarSettings::get_tx_pulse_envelope, DOC_C(SonarSettings, Content, tx_pulse_envelope))
        .def("set_tx_pulse_envelope", &SonarSettings::set_tx_pulse_envelope, DOC_C(SonarSettings, Content, tx_pulse_envelope), nb::arg("val"))
        .def("get_tx_pulse_envelope_parameter", &SonarSettings::get_tx_pulse_envelope_parameter, DOC_C(SonarSettings, Content, tx_pulse_envelope_parameter))
        .def("set_tx_pulse_envelope_parameter", &SonarSettings::set_tx_pulse_envelope_parameter, DOC_C(SonarSettings, Content, tx_pulse_envelope_parameter), nb::arg("val"))
        .def("get_tx_pulse_mode", &SonarSettings::get_tx_pulse_mode, DOC_C(SonarSettings, Content, tx_pulse_mode))
        .def("set_tx_pulse_mode", &SonarSettings::set_tx_pulse_mode, DOC_C(SonarSettings, Content, tx_pulse_mode), nb::arg("val"))
        .def("get_max_ping_rate", &SonarSettings::get_max_ping_rate, DOC_C(SonarSettings, Content, max_ping_rate))
        .def("set_max_ping_rate", &SonarSettings::set_max_ping_rate, DOC_C(SonarSettings, Content, max_ping_rate), nb::arg("val"))
        .def("get_ping_period", &SonarSettings::get_ping_period, DOC_C(SonarSettings, Content, ping_period))
        .def("set_ping_period", &SonarSettings::set_ping_period, DOC_C(SonarSettings, Content, ping_period), nb::arg("val"))
        .def("get_range_selection", &SonarSettings::get_range_selection, DOC_C(SonarSettings, Content, range_selection))
        .def("set_range_selection", &SonarSettings::set_range_selection, DOC_C(SonarSettings, Content, range_selection), nb::arg("val"))
        .def("get_power_selection", &SonarSettings::get_power_selection, DOC_C(SonarSettings, Content, power_selection))
        .def("set_power_selection", &SonarSettings::set_power_selection, DOC_C(SonarSettings, Content, power_selection), nb::arg("val"))
        .def("get_gain_selection", &SonarSettings::get_gain_selection, DOC_C(SonarSettings, Content, gain_selection))
        .def("set_gain_selection", &SonarSettings::set_gain_selection, DOC_C(SonarSettings, Content, gain_selection), nb::arg("val"))
        .def("get_control_flags", &SonarSettings::get_control_flags, DOC_C(SonarSettings, Content, control_flags))
        .def("set_control_flags", &SonarSettings::set_control_flags, DOC_C(SonarSettings, Content, control_flags), nb::arg("val"))
        .def("get_projector_id", &SonarSettings::get_projector_id, DOC_C(SonarSettings, Content, projector_id))
        .def("set_projector_id", &SonarSettings::set_projector_id, DOC_C(SonarSettings, Content, projector_id), nb::arg("val"))
        .def("get_steering_vertical", &SonarSettings::get_steering_vertical, DOC_C(SonarSettings, Content, steering_vertical))
        .def("set_steering_vertical", &SonarSettings::set_steering_vertical, DOC_C(SonarSettings, Content, steering_vertical), nb::arg("val"))
        .def("get_steering_horizontal", &SonarSettings::get_steering_horizontal, DOC_C(SonarSettings, Content, steering_horizontal))
        .def("set_steering_horizontal", &SonarSettings::set_steering_horizontal, DOC_C(SonarSettings, Content, steering_horizontal), nb::arg("val"))
        .def("get_beamwidth_vertical", &SonarSettings::get_beamwidth_vertical, DOC_C(SonarSettings, Content, beamwidth_vertical))
        .def("set_beamwidth_vertical", &SonarSettings::set_beamwidth_vertical, DOC_C(SonarSettings, Content, beamwidth_vertical), nb::arg("val"))
        .def("get_beamwidth_horizontal", &SonarSettings::get_beamwidth_horizontal, DOC_C(SonarSettings, Content, beamwidth_horizontal))
        .def("set_beamwidth_horizontal", &SonarSettings::set_beamwidth_horizontal, DOC_C(SonarSettings, Content, beamwidth_horizontal), nb::arg("val"))
        .def("get_focal_point", &SonarSettings::get_focal_point, DOC_C(SonarSettings, Content, focal_point))
        .def("set_focal_point", &SonarSettings::set_focal_point, DOC_C(SonarSettings, Content, focal_point), nb::arg("val"))
        .def("get_projector_weighting", &SonarSettings::get_projector_weighting, DOC_C(SonarSettings, Content, projector_weighting))
        .def("set_projector_weighting", &SonarSettings::set_projector_weighting, DOC_C(SonarSettings, Content, projector_weighting), nb::arg("val"))
        .def("get_projector_weighting_parameter", &SonarSettings::get_projector_weighting_parameter, DOC_C(SonarSettings, Content, projector_weighting_parameter))
        .def("set_projector_weighting_parameter", &SonarSettings::set_projector_weighting_parameter, DOC_C(SonarSettings, Content, projector_weighting_parameter), nb::arg("val"))
        .def("get_transmit_flags", &SonarSettings::get_transmit_flags, DOC_C(SonarSettings, Content, transmit_flags))
        .def("set_transmit_flags", &SonarSettings::set_transmit_flags, DOC_C(SonarSettings, Content, transmit_flags), nb::arg("val"))
        .def("get_hydrophone_id", &SonarSettings::get_hydrophone_id, DOC_C(SonarSettings, Content, hydrophone_id))
        .def("set_hydrophone_id", &SonarSettings::set_hydrophone_id, DOC_C(SonarSettings, Content, hydrophone_id), nb::arg("val"))
        .def("get_rx_weighting", &SonarSettings::get_rx_weighting, DOC_C(SonarSettings, Content, rx_weighting))
        .def("set_rx_weighting", &SonarSettings::set_rx_weighting, DOC_C(SonarSettings, Content, rx_weighting), nb::arg("val"))
        .def("get_rx_weighting_parameter", &SonarSettings::get_rx_weighting_parameter, DOC_C(SonarSettings, Content, rx_weighting_parameter))
        .def("set_rx_weighting_parameter", &SonarSettings::set_rx_weighting_parameter, DOC_C(SonarSettings, Content, rx_weighting_parameter), nb::arg("val"))
        .def("get_rx_flags", &SonarSettings::get_rx_flags, DOC_C(SonarSettings, Content, rx_flags))
        .def("set_rx_flags", &SonarSettings::set_rx_flags, DOC_C(SonarSettings, Content, rx_flags), nb::arg("val"))
        .def("get_rx_width", &SonarSettings::get_rx_width, DOC_C(SonarSettings, Content, rx_width))
        .def("set_rx_width", &SonarSettings::set_rx_width, DOC_C(SonarSettings, Content, rx_width), nb::arg("val"))
        .def("get_range_minimum", &SonarSettings::get_range_minimum, DOC_C(SonarSettings, Content, range_minimum))
        .def("set_range_minimum", &SonarSettings::set_range_minimum, DOC_C(SonarSettings, Content, range_minimum), nb::arg("val"))
        .def("get_range_maximum", &SonarSettings::get_range_maximum, DOC_C(SonarSettings, Content, range_maximum))
        .def("set_range_maximum", &SonarSettings::set_range_maximum, DOC_C(SonarSettings, Content, range_maximum), nb::arg("val"))
        .def("get_depth_minimum", &SonarSettings::get_depth_minimum, DOC_C(SonarSettings, Content, depth_minimum))
        .def("set_depth_minimum", &SonarSettings::set_depth_minimum, DOC_C(SonarSettings, Content, depth_minimum), nb::arg("val"))
        .def("get_depth_maximum", &SonarSettings::get_depth_maximum, DOC_C(SonarSettings, Content, depth_maximum))
        .def("set_depth_maximum", &SonarSettings::set_depth_maximum, DOC_C(SonarSettings, Content, depth_maximum), nb::arg("val"))
        .def("get_absorption", &SonarSettings::get_absorption, DOC_C(SonarSettings, Content, absorption))
        .def("set_absorption", &SonarSettings::set_absorption, DOC_C(SonarSettings, Content, absorption), nb::arg("val"))
        .def("get_sound_velocity", &SonarSettings::get_sound_velocity, DOC_C(SonarSettings, Content, sound_velocity))
        .def("set_sound_velocity", &SonarSettings::set_sound_velocity, DOC_C(SonarSettings, Content, sound_velocity), nb::arg("val"))
        .def("get_spreading", &SonarSettings::get_spreading, DOC_C(SonarSettings, Content, spreading))
        .def("set_spreading", &SonarSettings::set_spreading, DOC_C(SonarSettings, Content, spreading), nb::arg("val"))
        .def("get_checksum", &SonarSettings::get_checksum, DOC_C(SonarSettings, Content, checksum))
        .def("set_checksum", &SonarSettings::set_checksum, DOC_C(SonarSettings, Content, checksum), nb::arg("val"))
        .def("get_steering_vertical_in_degrees", &SonarSettings::get_steering_vertical_in_degrees, DOC_SonarSettings(get_steering_vertical_in_degrees))
        .def("get_steering_horizontal_in_degrees", &SonarSettings::get_steering_horizontal_in_degrees, DOC_SonarSettings(get_steering_horizontal_in_degrees))
        .def("get_beamwidth_vertical_in_degrees", &SonarSettings::get_beamwidth_vertical_in_degrees, DOC_SonarSettings(get_beamwidth_vertical_in_degrees))
        .def("get_beamwidth_horizontal_in_degrees", &SonarSettings::get_beamwidth_horizontal_in_degrees, DOC_SonarSettings(get_beamwidth_horizontal_in_degrees))
        .def("get_rx_width_in_degrees", &SonarSettings::get_rx_width_in_degrees, DOC_SonarSettings(get_rx_width_in_degrees))
        .def("__eq__", &SonarSettings::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(SonarSettings)
        __PYCLASS_DEFAULT_BINARY__(SonarSettings)
        __PYCLASS_DEFAULT_PRINTING__(SonarSettings);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
