#include "simradrawwatercolumncalibration.hpp"

#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

#include <array> // added
#include <cmath>
#include <fmt/core.h>
#include <limits>
#include <numbers>
#include <optional>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {
namespace calibration {

// ----- ctors -----
SimradRawWaterColumnCalibration::SimradRawWaterColumnCalibration()
    : t_base()
{
}

SimradRawWaterColumnCalibration::SimradRawWaterColumnCalibration(const t_base& other)
    : t_base(other)
{
}

SimradRawWaterColumnCalibration::SimradRawWaterColumnCalibration(
    const datagrams::xml_datagrams::XML_Environment&       environment,
    const datagrams::xml_datagrams::XML_Parameter_Channel& parameters,
    const _sub::TransceiverInformation&                    transceiver_information,
    const std::pair<datagrams::FIL1, datagrams::FIL1>&     filter_stages,
    size_t                                                 n_complex_samples)
    : t_base()
{
    set_environment_parameters(environment);
    set_runtime_parameters(parameters);
    set_filter_parameters(filter_stages);

    const auto&           transducer = transceiver_information.get_transducer();
    std::optional<size_t> pulse_duration_index =
        transceiver_information.get_pulse_duration_index_optional(
            parameters.get_pulse_duration(), parameters.get_pulse_form_is_fm());

    if (pulse_duration_index.has_value())
    {
        set_transducer_parameters(transducer, pulse_duration_index.value());
    }
    else if (parameters.get_pulse_form_is_fm())
    {
        set_transducer_parameters(NAN, NAN, transducer.EquivalentBeamAngle, transducer.Frequency);
    }
    else
    {
        size_t pdi = transceiver_information.get_pulse_duration_index(
            parameters.get_pulse_duration(), parameters.get_pulse_form_is_fm());
        set_transducer_parameters(transducer, pdi);
    }

    if (n_complex_samples == 0)
        set_power_calibration_parameters(n_complex_samples, std::nullopt);
    else
        set_power_calibration_parameters(n_complex_samples,
                                         transceiver_information.get_impedance_factor());

    set_optional_parameters(environment.Latitude, std::nullopt);
    setup_simrad_calibration();
}

// ----- setters -----
void SimradRawWaterColumnCalibration::set_transducer_parameters(
    const datagrams::xml_datagrams::XMLConfigurationTransceiverChannelTransducer& transducer,
    size_t pulse_duration_index)
{
    set_transducer_parameters(transducer.Gain.at(pulse_duration_index),
                              transducer.SaCorrection.at(pulse_duration_index),
                              transducer.EquivalentBeamAngle,
                              transducer.Frequency);
}

void SimradRawWaterColumnCalibration::set_transducer_parameters(float transducer_gain_db,
                                                                float sa_correction_db,
                                                                float equivalent_beam_angle_db,
                                                                float frequency_nominal_hz)
{
    _transducer_gain_db       = transducer_gain_db;
    _sa_correction_db         = sa_correction_db;
    _equivalent_beam_angle_db = equivalent_beam_angle_db;
    _frequency_nominal_hz     = frequency_nominal_hz;
    _initialized              = false;
}

void SimradRawWaterColumnCalibration::set_environment_parameters(
    const datagrams::xml_datagrams::XML_Environment& environment)
{
    set_environment_parameters(
        environment.Depth, environment.Temperature, environment.Salinity, environment.Acidity);
}

void SimradRawWaterColumnCalibration::set_environment_parameters(float reference_depth_m,
                                                                 float temperature_c,
                                                                 float salinity_psu,
                                                                 float acidity_ph)
{
    _reference_depth_m = reference_depth_m;
    _temperature_c     = temperature_c;
    _salinity_psu      = salinity_psu;
    _acidity_ph        = acidity_ph;
    _initialized       = false;
}

void SimradRawWaterColumnCalibration::set_environment_parameters(float forced_sound_velocity_m_s,
                                                                 float forced_absorption_db_m)
{
    _forced_sound_velocity_m_s = forced_sound_velocity_m_s;
    _forced_absorption_db_m    = forced_absorption_db_m;
    _initialized               = false;
}

void SimradRawWaterColumnCalibration::set_runtime_parameters(
    const datagrams::xml_datagrams::XML_Parameter_Channel& parameters)
{
    set_runtime_parameters(parameters.Frequency,
                           parameters.TransmitPower,
                           parameters.get_pulse_duration(),
                           parameters.Slope,
                           parameters.SampleInterval);
}

void SimradRawWaterColumnCalibration::set_runtime_parameters(float frequency_hz,
                                                             float transmit_power_w,
                                                             float nominal_pulse_duration_s,
                                                             float slope_factor,
                                                             float sample_interval_s)
{
    _frequency_hz             = frequency_hz;
    _transmit_power_w         = transmit_power_w;
    _nominal_pulse_duration_s = nominal_pulse_duration_s;
    _slope_factor             = slope_factor;
    _sample_interval_s        = sample_interval_s;
    _initialized              = false;
}

void SimradRawWaterColumnCalibration::set_filter_parameters(
    const std::pair<datagrams::FIL1, datagrams::FIL1>& filter_stages)
{
    set_filter_parameters(filter_stages.first.get_decimation_factor(),
                          filter_stages.first.get_coefficients(),
                          filter_stages.second.get_decimation_factor(),
                          filter_stages.second.get_coefficients());
}

void SimradRawWaterColumnCalibration::set_filter_parameters(
    int16_t                                    stage1_decimation_factor,
    const xt::xtensor<std::complex<float>, 1>& stage1_coefficients,
    int16_t                                    stage2_decimation_factor,
    const xt::xtensor<std::complex<float>, 1>& stage2_coefficients)
{
    _filter_stage_1_decimation_factor = stage1_decimation_factor;
    _filter_stage_2_decimation_factor = stage2_decimation_factor;
    _filter_stage_1_coefficients      = stage1_coefficients;
    _filter_stage_2_coefficients      = stage2_coefficients;
    _initialized                      = false;
}

void SimradRawWaterColumnCalibration::set_power_calibration_parameters(
    size_t               n_complex_samples,
    std::optional<float> impedance_factor)
{
    if (n_complex_samples == 0)
    {
        if (impedance_factor.has_value())
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Impedance factor should not be set for power/angle mode. "
                            "(n_complex_samples == 0)",
                            __func__));

        _n_complex_samples          = n_complex_samples;
        _power_conversion_factor_db = std::nullopt;
    }
    else
    {
        if (!impedance_factor.has_value())
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Impedance factor must be set for complex mode. "
                            "(n_complex_samples > 0)",
                            __func__));

        _n_complex_samples          = n_complex_samples;
        _power_conversion_factor_db = 10 * std::log10(impedance_factor.value() / n_complex_samples);
    }

    _initialized = false;
}

void SimradRawWaterColumnCalibration::set_optional_parameters(
    std::optional<float> rounded_latitude_deg,
    std::optional<float> rounded_longitude_deg)
{
    if (rounded_latitude_deg.has_value())
    {
        if (std::isfinite(rounded_latitude_deg.value()))
            _rounded_latitude_deg = rounded_latitude_deg;
    }
    if (rounded_longitude_deg.has_value())
    {
        if (std::isfinite(rounded_longitude_deg.value()))
            _rounded_longitude_deg = rounded_longitude_deg;
    }
    _initialized = false;
}

void SimradRawWaterColumnCalibration::force_sound_velocity_m_s(
    std::optional<float> forced_sound_velocity_m_s)
{
    _forced_sound_velocity_m_s = forced_sound_velocity_m_s;
    _initialized               = false;
}

void SimradRawWaterColumnCalibration::force_absorption_db_m(
    std::optional<float> forced_absorption_db_m)
{
    _forced_absorption_db_m = forced_absorption_db_m;
    _initialized            = false;
}

void SimradRawWaterColumnCalibration::force_effective_pulse_duration_s(
    std::optional<float> effective_pulse_duration_s)
{
    _forced_effective_pulse_duration_s = effective_pulse_duration_s;
    _initialized                       = false;
}

// ----- setup calibration -----
void SimradRawWaterColumnCalibration::setup_simrad_calibration()
{
    _power_calibration.reset();
    _ap_calibration.reset();
    _av_calibration.reset();

    try
    {
        check_can_be_initialized();

        // ----- setup power calibration -----
        if (_n_complex_samples == 0 || std::isfinite(_power_conversion_factor_db.value_or(
                                           std::numeric_limits<float>::quiet_NaN())))
        {
            _power_calibration =
                std::make_unique<AmplitudeCalibration>(_power_conversion_factor_db.value_or(0.f));

            // ----- setup ap calibration -----
            _computed_sound_velocity_m_s =
                algorithms::amplitudecorrection::functions::calc_sound_velocity(
                    _reference_depth_m,
                    _temperature_c,
                    _salinity_psu,
                    _rounded_latitude_deg.value_or(0.f),
                    _rounded_longitude_deg.value_or(0.f));

            _computed_absorption_db_m =
                algorithms::amplitudecorrection::functions::calc_absorption_coefficient_db_m(
                    _frequency_hz,
                    _reference_depth_m,
                    _computed_sound_velocity_m_s,
                    _temperature_c,
                    _salinity_psu,
                    _acidity_ph);

            float sound_velocity_m_s = get_sound_velocity_m_s();
            float absorption_db_m    = get_absorption_db_m();

            WaterColumnCalibration::set_absorption_db_m(absorption_db_m);

            _wavelength_m                  = sound_velocity_m_s / _frequency_hz;
            float freq_corr                = 20 * std::log10(_frequency_hz / _frequency_nominal_hz);
            _corr_transducer_gain_db       = _transducer_gain_db + freq_corr;
            _corr_equivalent_beam_angle_db = _equivalent_beam_angle_db + freq_corr;

            static const float pi_factor =
                -10 * std::log10(16 * std::numbers::pi * std::numbers::pi);
            float sp_offset = -2 * _corr_transducer_gain_db - pi_factor -
                              10 * std::log10(_transmit_power_w * _wavelength_m * _wavelength_m);

            if (std::isfinite(sp_offset))
            {

                _ap_calibration = std::make_unique<AmplitudeCalibration>(
                    _power_conversion_factor_db.value_or(0.f) + sp_offset);

                // --- setup av calibration ---
                try
                {
                    _computed_internal_sampling_interval_hz =
                        compute_internal_sampling_interval_hz();
                    _computed_effective_pulse_duration_s = compute_effective_pulse_duration_s();
                }
                catch (std::exception& e)
                {
                    // catching exceptions here allows users to set forced values
                    std::cerr << fmt::format(
                        "Warning[{}]:Failed to compute effective pulse duration: {}",
                        __func__,
                        e.what());
                }

                float sv_offset =
                    -2 * _sa_correction_db - _corr_equivalent_beam_angle_db -
                    10 * std::log10(sound_velocity_m_s * get_effective_pulse_duration_s() * 0.5f);
                if (std::isfinite(sv_offset))
                {
                    _av_calibration = std::make_unique<AmplitudeCalibration>(
                        _power_conversion_factor_db.value_or(0.f) + sp_offset + sv_offset);
                }
            }
        }
    }
    catch (std::exception& e)
    {
        std::cerr << fmt::format(
            "Warning[{}]:Failed to setup SimradRawWaterColumnCalibration: {}", __func__, e.what());
    }

    // setup initialzed state as initialization has been attempted
    // if unsucessful, power_calibraiton and/or _ap_calibration and/or _av_calibration will be empty
    _initialized = true;
    check_initialization();
}

// ----- ops -----
bool SimradRawWaterColumnCalibration::operator==(const SimradRawWaterColumnCalibration& other) const
{
    if (!WaterColumnCalibration::operator==(other))
        return false;

    return tools::helper::float_equals(_transducer_gain_db, other._transducer_gain_db) &&
           tools::helper::float_equals(_sa_correction_db, other._sa_correction_db) &&
           tools::helper::float_equals(_equivalent_beam_angle_db,
                                       other._equivalent_beam_angle_db) &&
           tools::helper::float_equals(_frequency_nominal_hz, other._frequency_nominal_hz) &&
           tools::helper::float_equals(_reference_depth_m, other._reference_depth_m) &&
           tools::helper::float_equals(_temperature_c, other._temperature_c) &&
           tools::helper::float_equals(_salinity_psu, other._salinity_psu) &&
           tools::helper::float_equals(_acidity_ph, other._acidity_ph) &&
           tools::helper::float_equals(_frequency_hz, other._frequency_hz) &&
           tools::helper::float_equals(_transmit_power_w, other._transmit_power_w) &&
           tools::helper::float_equals(_nominal_pulse_duration_s,
                                       other._nominal_pulse_duration_s) &&
           tools::helper::float_equals(_slope_factor, other._slope_factor) &&
           tools::helper::float_equals(_sample_interval_s, other._sample_interval_s) &&
           tools::helper::float_equals(_computed_sound_velocity_m_s,
                                       other._computed_sound_velocity_m_s) &&
           tools::helper::float_equals(_computed_absorption_db_m,
                                       other._computed_absorption_db_m) &&
           tools::helper::float_equals(_wavelength_m, other._wavelength_m) &&
           tools::helper::float_equals(_corr_transducer_gain_db, other._corr_transducer_gain_db) &&
           tools::helper::float_equals(_corr_equivalent_beam_angle_db,
                                       other._corr_equivalent_beam_angle_db) &&
           tools::helper::float_equals(_computed_effective_pulse_duration_s,
                                       other._computed_effective_pulse_duration_s) &&
           tools::helper::float_equals(_computed_internal_sampling_interval_hz,
                                       other._computed_internal_sampling_interval_hz) &&
           _filter_stage_1_decimation_factor == other._filter_stage_1_decimation_factor &&
           _filter_stage_2_decimation_factor == other._filter_stage_2_decimation_factor &&
           _filter_stage_1_coefficients == other._filter_stage_1_coefficients &&
           _filter_stage_2_coefficients == other._filter_stage_2_coefficients &&
           _n_complex_samples == other._n_complex_samples &&
           tools::helper::optional_float_equals(_power_conversion_factor_db,
                                                other._power_conversion_factor_db) &&
           tools::helper::optional_float_equals(_rounded_latitude_deg,
                                                other._rounded_latitude_deg) &&
           tools::helper::optional_float_equals(_rounded_longitude_deg,
                                                other._rounded_longitude_deg) &&
           tools::helper::optional_float_equals(_forced_sound_velocity_m_s,
                                                other._forced_sound_velocity_m_s) &&
           tools::helper::optional_float_equals(_forced_absorption_db_m,
                                                other._forced_absorption_db_m) &&
           tools::helper::optional_float_equals(_forced_effective_pulse_duration_s,
                                                other._forced_effective_pulse_duration_s);
}

// ----- checks -----
void SimradRawWaterColumnCalibration::check_initialized() const
{
    if (!initialized())
        throw std::runtime_error(fmt::format(
            "ERROR[{}]:Calibration not initialized, call setup_simrad_calibration() first!",
            __func__));
}

void SimradRawWaterColumnCalibration::check_modifying_base_calibration_allowed() const
{
    throw std::runtime_error(fmt::format(
        "ERROR[{}]:Modifying base calibrations (power, ap, av) is not allowed for "
        "SimradRawWaterColumnCalibration. You may modify the parameters used for "
        "the calibration, and call setup_simrad_calibration() to recompute the "
        "calibration. You may also modify the used sp and sv calibrations. Alternatively you "
        "can explicitly convert the calibration to a generic calibration. using "
        "WaterColumnCalibration(calibration)",
        __func__));
}

void SimradRawWaterColumnCalibration::check_initialization() const
{
    check_initialized();
    check_can_be_initialized();
}

void SimradRawWaterColumnCalibration::check_can_be_initialized() const
{
    if (!_n_complex_samples.has_value())
        throw std::runtime_error(
            fmt::format("ERROR[SimradRawWaterColumnCalibration]:Calibration not initialized "
                        "because n_complex_samples is not set!"));
}

// ----- stream I/O -----
SimradRawWaterColumnCalibration SimradRawWaterColumnCalibration::from_stream(std::istream& is)
{
    SimradRawWaterColumnCalibration calibration(t_base::from_stream(is));

    is.read(reinterpret_cast<char*>(&calibration._transducer_gain_db), sizeof(float) * 20);

    is.read(reinterpret_cast<char*>(&calibration._filter_stage_1_decimation_factor),
            sizeof(int16_t) * 2);

    std::array<size_t, 2> ncoefficients;
    is.read(reinterpret_cast<char*>(&ncoefficients), sizeof(ncoefficients));

    calibration._filter_stage_1_coefficients =
        xt::xtensor<std::complex<float>, 1>::from_shape({ ncoefficients[0] });
    is.read(reinterpret_cast<char*>(calibration._filter_stage_1_coefficients.data()),
            sizeof(std::complex<float>) * ncoefficients[0]);

    calibration._filter_stage_2_coefficients =
        xt::xtensor<std::complex<float>, 1>::from_shape({ ncoefficients[1] });
    is.read(reinterpret_cast<char*>(calibration._filter_stage_2_coefficients.data()),
            sizeof(std::complex<float>) * ncoefficients[1]);

    size_t n_complex_samples;
    is.read(reinterpret_cast<char*>(&n_complex_samples), sizeof(n_complex_samples));
    if (n_complex_samples != std::numeric_limits<size_t>::max())
        calibration._n_complex_samples = n_complex_samples;

    std::array<float, 6> optional_values;
    is.read(reinterpret_cast<char*>(optional_values.data()), sizeof(float) * 6);
    if (std::isfinite(optional_values[0]))
        calibration._power_conversion_factor_db = optional_values[0];
    if (std::isfinite(optional_values[1]))
        calibration._rounded_latitude_deg = optional_values[1];
    if (std::isfinite(optional_values[2]))
        calibration._rounded_longitude_deg = optional_values[2];
    if (std::isfinite(optional_values[3]))
        calibration._forced_sound_velocity_m_s = optional_values[3];
    if (std::isfinite(optional_values[4]))
        calibration._forced_absorption_db_m = optional_values[4];
    if (std::isfinite(optional_values[5]))
        calibration._forced_effective_pulse_duration_s = optional_values[5];

    is.read(reinterpret_cast<char*>(&calibration._initialized), sizeof(calibration._initialized));

    return calibration;
}

void SimradRawWaterColumnCalibration::to_stream(std::ostream& os) const
{
    WaterColumnCalibration::to_stream(os);

    os.write(reinterpret_cast<const char*>(&_transducer_gain_db), sizeof(float) * 20);
    os.write(reinterpret_cast<const char*>(&_filter_stage_1_decimation_factor),
             sizeof(int16_t) * 2);

    std::array<size_t, 2> ncoefficients = { _filter_stage_1_coefficients.size(),
                                            _filter_stage_2_coefficients.size() };
    os.write(reinterpret_cast<const char*>(ncoefficients.data()), sizeof(ncoefficients));

    os.write(reinterpret_cast<const char*>(_filter_stage_1_coefficients.data()),
             sizeof(std::complex<float>) * _filter_stage_1_coefficients.size());
    os.write(reinterpret_cast<const char*>(_filter_stage_2_coefficients.data()),
             sizeof(std::complex<float>) * _filter_stage_2_coefficients.size());

    size_t n_complex_samples = _n_complex_samples.value_or(std::numeric_limits<size_t>::max());
    os.write(reinterpret_cast<const char*>(&n_complex_samples), sizeof(n_complex_samples));

    std::array<float, 6> optional_values = {
        _power_conversion_factor_db.value_or(std::numeric_limits<float>::quiet_NaN()),
        _rounded_latitude_deg.value_or(std::numeric_limits<float>::quiet_NaN()),
        _rounded_longitude_deg.value_or(std::numeric_limits<float>::quiet_NaN()),
        _forced_sound_velocity_m_s.value_or(std::numeric_limits<float>::quiet_NaN()),
        _forced_absorption_db_m.value_or(std::numeric_limits<float>::quiet_NaN()),
        _forced_effective_pulse_duration_s.value_or(std::numeric_limits<float>::quiet_NaN())
    };
    os.write(reinterpret_cast<const char*>(optional_values.data()), sizeof(float) * 6);
    os.write(reinterpret_cast<const char*>(&_initialized), sizeof(_initialized));
}

// ----- object printer -----
tools::classhelper::ObjectPrinter SimradRawWaterColumnCalibration::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "SimradRawWaterColumnCalibration", float_precision, superscript_exponents);

    printer.register_section("Transducer parameters");
    printer.register_value("transducer_gain_db", _transducer_gain_db, "dB");
    printer.register_value("sa_correction_db", _sa_correction_db, "dB");
    printer.register_value("equivalent_beam_angle_db", _equivalent_beam_angle_db, "dB");
    printer.register_value("frequency_nominal_hz", _frequency_nominal_hz, "Hz");

    printer.register_section("Environment parameters");
    printer.register_value("reference_depth_m", _reference_depth_m, "m");
    printer.register_value("temperature_c", _temperature_c, "°C");
    printer.register_value("salinity_psu", _salinity_psu, "PSU");
    printer.register_value("acidity_ph", _acidity_ph, "pH");

    printer.register_section("Runtime parameters");
    printer.register_value("frequency_hz", _frequency_hz, "Hz");
    printer.register_value("transmit_power_w", _transmit_power_w, "W");
    printer.register_value("nominal_pulse_duration_s", _nominal_pulse_duration_s, "s");
    printer.register_value("slope_factor", _slope_factor);
    printer.register_value("sample_interval_s", _sample_interval_s, "s");

    printer.register_section("Filter parameters");
    printer.register_value("filter_stage_1_decimation_factor", _filter_stage_1_decimation_factor);
    printer.register_value("filter_stage_2_decimation_factor", _filter_stage_2_decimation_factor);
    printer.register_container(
        "filter_stage_1_coefficients", _filter_stage_1_coefficients, "complex<float>");
    printer.register_container(
        "filter_stage_2_coefficients", _filter_stage_2_coefficients, "complex<float>");

    printer.register_section("Computed parameters");
    printer.register_value("computed_sound_velocity_m_s", _computed_sound_velocity_m_s, "m/s");
    printer.register_optional_value("forced_sound_velocity_m_s", _forced_sound_velocity_m_s, "m/s");
    printer.register_value("sound_velocity_m_s", get_sound_velocity_m_s(), "m/s [used value]");
    printer.register_value("computed_absorption_db_m", _computed_absorption_db_m, "dB/m");
    printer.register_optional_value("forced_absorption_db_m", _forced_absorption_db_m, "dB/m");
    printer.register_value("absorption_db_m", get_absorption_db_m(), "dB/m [used value]");
    printer.register_value("wavelength_m", _wavelength_m, "m");
    printer.register_value("corr_transducer_gain_db", _corr_transducer_gain_db, "dB");
    printer.register_value("corr_equivalent_beam_angle_db", _corr_equivalent_beam_angle_db, "dB");
    printer.register_value(
        "computed_internal_sampling_interval_hz", _computed_internal_sampling_interval_hz, "Hz");
    printer.register_value(
        "computed_effective_pulse_duration_s", _computed_effective_pulse_duration_s, "s");
    printer.register_optional_value(
        "forced_effective_pulse_duration_s", _forced_effective_pulse_duration_s, "s");
    printer.register_value(
        "effective_pulse_duration_s", get_effective_pulse_duration_s(), "s [used value]");

    printer.register_section("Power calibration parameters");
    if (!_n_complex_samples.has_value())
        printer.register_optional_value("Amplitude derived from complex samples",
                                        _n_complex_samples);
    else
    {
        if (_n_complex_samples.value() == 0)
            printer.register_value("Amplitude derived from complex samples", false);
        else
        {
            printer.register_value(
                "Amplitude derived from", _n_complex_samples.value(), "n_complex_samples");
            printer.register_value(
                "power_conversion_factor_db", _power_conversion_factor_db.value(), "dB");
        }
    }

    printer.register_section(
        "Optional parameters (if available, used for copmuting sound velocity)");
    printer.register_optional_value("rounded_latitude_deg", _rounded_latitude_deg, "°");
    printer.register_optional_value("rounded_longitude_deg", _rounded_longitude_deg, "°");

    printer.register_section("Generic calibration");
    printer.append(WaterColumnCalibration::__printer__(float_precision, superscript_exponents));

    return printer;
}

// ----- moved getters -----
float SimradRawWaterColumnCalibration::get_sound_velocity_m_s() const
{
    return _forced_sound_velocity_m_s.value_or(_computed_sound_velocity_m_s);
}

float SimradRawWaterColumnCalibration::get_absorption_db_m() const
{
    return _forced_absorption_db_m.value_or(_computed_absorption_db_m);
}

int16_t SimradRawWaterColumnCalibration::get_filter_stage_1_decimation_factor() const
{
    return _filter_stage_1_decimation_factor;
}

int16_t SimradRawWaterColumnCalibration::get_filter_stage_2_decimation_factor() const
{
    return _filter_stage_2_decimation_factor;
}

float SimradRawWaterColumnCalibration::get_computed_internal_sampling_interval_hz() const
{
    return _computed_internal_sampling_interval_hz;
}

float SimradRawWaterColumnCalibration::get_computed_effective_pulse_duration_s() const
{
    return _computed_effective_pulse_duration_s;
}

std::optional<float> SimradRawWaterColumnCalibration::get_forced_effective_pulse_duration_s() const
{
    return _forced_effective_pulse_duration_s;
}

float SimradRawWaterColumnCalibration::get_effective_pulse_duration_s() const
{
    return _forced_effective_pulse_duration_s.value_or(_computed_effective_pulse_duration_s);
}

std::optional<float> SimradRawWaterColumnCalibration::get_power_conversion_factor_db() const
{
    return _power_conversion_factor_db;
}

// ----- private helpers -----
void SimradRawWaterColumnCalibration::throw_because_value_is_note_finite(
    std::string_view value_name,
    float            value)
{
    throw std::runtime_error(fmt::format("ERROR[SimradRawWaterColumnCalibration]:"
                                         "Calibration not initialized because {} is {}!",
                                         value_name,
                                         value));
}
float SimradRawWaterColumnCalibration::compute_internal_sampling_interval_hz() const
{
    if (_filter_stage_1_decimation_factor < 0 || _filter_stage_2_decimation_factor < 0)
        return std::numeric_limits<float>::quiet_NaN();

    return (_filter_stage_1_decimation_factor * _filter_stage_2_decimation_factor) /
           _sample_interval_s;
}

float SimradRawWaterColumnCalibration::compute_effective_pulse_duration_s(
    bool  round_to_full_samples,
    float start_phase_degrees) const
{
    if (tools::helper::float_equals(_slope_factor, 0.f))
        return _nominal_pulse_duration_s;

    // Generate transmit pulse
    const auto [filt_times, filt_amplitudes] =
        compute_filtered_transmit_pulse<xt::xtensor<float, 1>>(start_phase_degrees);

    // Integrate energy to compute effective pulse duration
    return functions::compute_effective_pulse_duration_cw(
        filt_amplitudes, _sample_interval_s, round_to_full_samples);
}

} // namespace calibration
} // namespace filedatatypes
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping