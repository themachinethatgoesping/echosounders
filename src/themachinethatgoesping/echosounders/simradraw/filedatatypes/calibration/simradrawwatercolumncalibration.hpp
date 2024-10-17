// SPDX-FileCopyrightText: 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawwatercolumncalibration.doc.hpp"

#include <fmt/core.h>
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/vectorinterpolators.hpp>

#include "../../../filetemplates/datatypes/calibration/multisectorwatercolumncalibration.hpp"
#include "../../../filetemplates/datatypes/calibration/watercolumncalibration.hpp"
#include "../../datagrams.hpp"
#include "../sub/transceiverinformation.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {
namespace calibration {

class SimradRawWaterColumnCalibration
    : public filetemplates::datatypes::calibration::WaterColumnCalibration
{
    using AmplitudeCalibration = filetemplates::datatypes::calibration::AmplitudeCalibration;
    using t_base               = filetemplates::datatypes::calibration::WaterColumnCalibration;

  protected:
    // This function is procted because it may interfere with the _computed_absorption_db_m
    // parameter from the SimradRawWaterColumnCalibration
    using WaterColumnCalibration::set_absorption_db_m;

  protected:
    // transducer parameters
    float _transducer_gain_db       = std::numeric_limits<float>::quiet_NaN();
    float _sa_correction_db         = std::numeric_limits<float>::quiet_NaN();
    float _equivalent_beam_angle_db = std::numeric_limits<float>::quiet_NaN();
    float _frequency_nominal_hz     = std::numeric_limits<float>::quiet_NaN();

    // derived from environment
    float _reference_depth_m = std::numeric_limits<float>::quiet_NaN();
    float _temperature_c     = std::numeric_limits<float>::quiet_NaN();
    float _salinity_psu      = std::numeric_limits<float>::quiet_NaN();
    float _acidity_ph        = std::numeric_limits<float>::quiet_NaN();

    // derived from parameters
    float _frequency_hz               = std::numeric_limits<float>::quiet_NaN();
    float _transmit_power_w           = std::numeric_limits<float>::quiet_NaN();
    float _effective_pulse_duration_s = std::numeric_limits<float>::quiet_NaN();

    // computed
    float _computed_sound_velocity_m_s   = std::numeric_limits<float>::quiet_NaN();
    float _computed_absorption_db_m      = std::numeric_limits<float>::quiet_NaN();
    float _wavelength_m                  = std::numeric_limits<float>::quiet_NaN();
    float _corr_transducer_gain_db       = std::numeric_limits<float>::quiet_NaN();
    float _corr_equivalent_beam_angle_db = std::numeric_limits<float>::quiet_NaN();

    // power calibration parameters
    std::optional<size_t>
        _n_complex_samples; /// This parameter is NOT optional, if no value is set, the calibration
                            /// is not yet valid. Set to 0 when working working with power/angle
                            /// data. If >0, this calibration includes a correction for the
                            /// impedance factor to translate the complex amplituded to power
                            /// applying this calibration to data which does not match
                            /// n_complex_samples will result in incorrect power values
    std::optional<float> _power_conversion_factor_db =
        std::nullopt; // used for computing power from complex 32 bit samples

    // optional paramters
    std::optional<float> _rounded_latitude_deg =
        std::nullopt; // derived from position, used for computing sound velocity
    std::optional<float> _rounded_longitude_deg =
        std::nullopt; // derived from position, used for computing sound velocity

    std::optional<float> _forced_sound_velocity_m_s = std::nullopt;
    std::optional<float> _forced_absorption_db_m    = std::nullopt;

    bool _initialized = false;

  public:
    SimradRawWaterColumnCalibration()
        : t_base()
    {
    }

    SimradRawWaterColumnCalibration(const t_base& other)
        : t_base(other)
    {
    }

    SimradRawWaterColumnCalibration(
        const datagrams::xml_datagrams::XML_Environment&       environment,
        const datagrams::xml_datagrams::XML_Parameter_Channel& parameters,
        const _sub::TransceiverInformation&                    transceiver_information,
        size_t                                                 n_complex_samples)
        : t_base()
    {
        // get environment parameters
        set_environment_parameters(environment);

        // get parameter parameters
        set_runtime_parameters(parameters);

        // set transducer parameters
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
            // incomplete calibration for FM pulse form for now
            // TODO: this should issue a warning
            // TODO: fm should use FrequencyPar anyways
            set_transducer_parameters(
                NAN, NAN, transducer.EquivalentBeamAngle, transducer.Frequency);
        }
        else
        {
            // call the function in throw mode to print exception
            size_t pdi = transceiver_information.get_pulse_duration_index(
                parameters.get_pulse_duration(), parameters.get_pulse_form_is_fm());

            set_transducer_parameters(transducer, pdi); // this should never be reached ...
        }

        // set power calibration parameters
        if (n_complex_samples == 0)
            set_power_calibration_parameters(n_complex_samples, std::nullopt);
        else
            set_power_calibration_parameters(n_complex_samples,
                                             transceiver_information.get_impedance_factor());

        // derived from position
        set_optional_parameters(environment.Latitude, std::nullopt);

        setup_simrad_calibration();
    }

    // ----- setters -----
    void set_transducer_parameters(
        const datagrams::xml_datagrams::XMLConfigurationTransceiverChannelTransducer& transducer,
        size_t pulse_duration_index)
    {
        set_transducer_parameters(transducer.Gain.at(pulse_duration_index),
                                  transducer.SaCorrection.at(pulse_duration_index),
                                  transducer.EquivalentBeamAngle,
                                  transducer.Frequency);
    }

    void set_transducer_parameters(float transducer_gain_db,
                                   float sa_correction_db,
                                   float equivalent_beam_angle_db,
                                   float frequency_nominal_hz)
    {
        _transducer_gain_db       = transducer_gain_db;
        _sa_correction_db         = sa_correction_db;
        _equivalent_beam_angle_db = equivalent_beam_angle_db;
        _frequency_nominal_hz     = frequency_nominal_hz;

        _initialized = false;
    }

    void set_environment_parameters(const datagrams::xml_datagrams::XML_Environment& environment)
    {
        set_environment_parameters(
            environment.Depth, environment.Temperature, environment.Salinity, environment.Acidity);
    }

    void set_environment_parameters(float reference_depth_m,
                                    float temperature_c,
                                    float salinity_psu,
                                    float acidity_ph = 8.06f)
    {
        _reference_depth_m = reference_depth_m;
        _temperature_c     = temperature_c;
        _salinity_psu      = salinity_psu;
        _acidity_ph        = acidity_ph;

        _initialized = false;
    }

    void set_environment_parameters(float forced_sound_velocity_m_s, float forced_absorption_db_m)
    {
        _forced_sound_velocity_m_s = forced_sound_velocity_m_s;
        _forced_absorption_db_m    = forced_absorption_db_m;

        _initialized = false;
    }

    void set_runtime_parameters(const datagrams::xml_datagrams::XML_Parameter_Channel& parameters)
    {
        set_runtime_parameters(parameters.Frequency,
                               parameters.TransmitPower,
                               parameters.get_pulse_duration() * parameters.Slope);
    }

    void set_runtime_parameters(float frequency_hz,
                                float transmit_power_w,
                                float effective_pulse_duration_s)
    {
        _frequency_hz               = frequency_hz;
        _transmit_power_w           = transmit_power_w;
        _effective_pulse_duration_s = effective_pulse_duration_s;

        _initialized = false;
    }

    void set_power_calibration_parameters(size_t               n_complex_samples,
                                          std::optional<float> impedance_factor = std::nullopt)
    {
        if (n_complex_samples == 0) // power/angle mode (not complex)
        {
            if (impedance_factor.has_value())
                throw std::runtime_error(
                    fmt::format("ERROR[{}]:Impedance factor should not be set for power/angle "
                                "mode. (n_complex_samples == 0)",
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

            _n_complex_samples = n_complex_samples;
            _power_conversion_factor_db =
                10 * std::log10(impedance_factor.value() / n_complex_samples);
        }

        _initialized = false;
    }

    void set_optional_parameters(std::optional<float> rounded_latitude_deg  = std::nullopt,
                                 std::optional<float> rounded_longitude_deg = std::nullopt)
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

    void force_sound_velocity_m_s(std::optional<float> forced_sound_velocity_m_s)
    {
        _forced_sound_velocity_m_s = forced_sound_velocity_m_s;
        _initialized               = false;
    }
    void force_absorption_db_m(std::optional<float> forced_absorption_db_m)
    {
        _forced_absorption_db_m = forced_absorption_db_m;
        _initialized            = false;
    }

    // ------ getters ------
    float get_transducer_gain_db() const { return _transducer_gain_db; }
    float get_sa_correction_db() const { return _sa_correction_db; }
    float get_equivalent_beam_angle_db() const { return _equivalent_beam_angle_db; }
    float get_frequency_nominal_hz() const { return _frequency_nominal_hz; }

    float get_reference_depth_m() const { return _reference_depth_m; }
    float get_temperature_c() const { return _temperature_c; }
    float get_salinity_psu() const { return _salinity_psu; }
    float get_acidity_ph() const { return _acidity_ph; }

    float get_frequency_hz() const { return _frequency_hz; }
    float get_transmit_power_w() const { return _transmit_power_w; }
    float get_effective_pulse_duration_s() const { return _effective_pulse_duration_s; }

    float get_computed_sound_velocity_m_s() const { return _computed_sound_velocity_m_s; }
    auto  get_forced_sound_velocity_m_s() const { return _forced_sound_velocity_m_s; }
    float get_sound_velocity_m_s() const
    {
        return _forced_sound_velocity_m_s.value_or(_computed_sound_velocity_m_s);
    }

    float get_computed_absorption_db_m() const { return _computed_absorption_db_m; }
    auto  get_forced_absorption_db_m() const { return _forced_absorption_db_m; }
    float get_absorption_db_m() const
    {
        return _forced_absorption_db_m.value_or(_computed_absorption_db_m);
    }

    float get_wavelength_m() const { return _wavelength_m; }
    float get_corr_transducer_gain_db() const { return _corr_transducer_gain_db; }
    float get_corr_equivalent_beam_angle_db() const { return _corr_equivalent_beam_angle_db; }

    std::optional<size_t> get_n_complex_samples() const { return _n_complex_samples; }
    std::optional<float>  get_power_conversion_factor_db() const
    {
        return _power_conversion_factor_db;
    }

    std::optional<float> get_rounded_latitude_deg() const { return _rounded_latitude_deg; }
    std::optional<float> get_rounded_longitude_deg() const { return _rounded_longitude_deg; }

    // ----- setup calibration for simradraw systems ----
    void setup_simrad_calibration()
    {
        check_can_be_initialized();

        // computed parameters
        _computed_sound_velocity_m_s =
            algorithms::amplitudecorrection::functions::calc_sound_velocity(
                _reference_depth_m,
                _temperature_c,
                _salinity_psu,
                _rounded_latitude_deg.value_or(0.f),
                _rounded_longitude_deg.value_or(0.f));

        // absorption
        _computed_absorption_db_m =
            algorithms::amplitudecorrection::functions::calc_absorption_coefficient_db_m(
                _frequency_hz,
                _reference_depth_m,
                _computed_sound_velocity_m_s,
                _temperature_c,
                _salinity_psu,
                _acidity_ph);

        // selects between forced and computed values
        float sound_velocity_m_s = get_sound_velocity_m_s();
        float absorption_db_m    = get_absorption_db_m();

        // TODO: test if this parameter shadowing causes problems:
        WaterColumnCalibration::set_absorption_db_m(absorption_db_m);

        _wavelength_m                  = sound_velocity_m_s / _frequency_hz;
        float freq_corr                = 20 * std::log10(_frequency_hz / _frequency_nominal_hz);
        _corr_transducer_gain_db       = _transducer_gain_db + freq_corr;
        _corr_equivalent_beam_angle_db = _equivalent_beam_angle_db + freq_corr;

        // compute gain offsets
        static const float pi_factor = -10 * std::log10(16 * M_PIf * M_PIf);
        float              sp_offset = -2 * _corr_transducer_gain_db - pi_factor -
                          10 * std::log10(_transmit_power_w * _wavelength_m * _wavelength_m);

        float sv_offset = -2 * _sa_correction_db - _corr_equivalent_beam_angle_db -
                          10 * std::log10(sound_velocity_m_s * _effective_pulse_duration_s * 0.5f);

        // reset calibrations
        _power_calibration.reset();
        _ap_calibration.reset();
        _av_calibration.reset();

        // check if power calibration is valid
        if (_n_complex_samples == 0 || std::isfinite(_power_conversion_factor_db.value_or(
                                           std::numeric_limits<float>::quiet_NaN())))
        {
            // power is the raw amplitude data substracted by the system gain offset
            _power_calibration =
                std::make_unique<AmplitudeCalibration>(_power_conversion_factor_db.value_or(0.f));

            // check if ap calibration is valid
            if (std::isfinite(sp_offset))
            {
                _ap_calibration = std::make_unique<AmplitudeCalibration>(
                    _power_conversion_factor_db.value_or(0.f) + sp_offset);

                // check if av calibration is valid
                if (std::isfinite(sv_offset))
                {
                    _av_calibration = std::make_unique<AmplitudeCalibration>(
                        _power_conversion_factor_db.value_or(0.f) + sp_offset + sv_offset);
                }
            }
        }

        _initialized = true;
        check_initialization();
    }

    // operator overloads
    bool operator==(const SimradRawWaterColumnCalibration& other) const
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
               tools::helper::float_equals(_effective_pulse_duration_s,
                                           other._effective_pulse_duration_s) &&
               tools::helper::float_equals(_computed_sound_velocity_m_s,
                                           other._computed_sound_velocity_m_s) &&
               tools::helper::float_equals(_computed_absorption_db_m,
                                           other._computed_absorption_db_m) &&
               tools::helper::float_equals(_wavelength_m, other._wavelength_m) &&
               tools::helper::float_equals(_corr_transducer_gain_db,
                                           other._corr_transducer_gain_db) &&
               tools::helper::float_equals(_corr_equivalent_beam_angle_db,
                                           other._corr_equivalent_beam_angle_db) &&
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
                                                    other._forced_absorption_db_m);
    }

    bool initialized() const { return _initialized; }

    void check_initialized() const override
    {
        if (!initialized())
            throw std::runtime_error(fmt::format(
                "ERROR[{}]:Calibration not initialized, call setup_simrad_calibration() first!",
                __func__));
    }

    void check_modifying_base_calibration_allowed() const override
    {
        throw std::runtime_error(fmt::format(
            "ERROR[{}]:Modifying base calibrations (power, ap, av) is not allowed for "
            "SimradRawWaterColumnCalibration. You may modify the parameters used for "
            "the calibration, and call setup_simrad_calibration() to recompute the "
            "calibration. You may also modify the used sp and sv calibrations. Alternatively "
            "you "
            "can explicitly convert the calibration to a generic calibration. using "
            "WaterColumnCalibration(calibration)",
            __func__));
    }

    void check_initialization() const
    {
        check_initialized();
        check_can_be_initialized();
    }

    void check_can_be_initialized() const
    {
        if (!_n_complex_samples.has_value())
            throw std::runtime_error(
                fmt::format("ERROR[SimradRawWaterColumnCalibration]:Calibration not initialized "
                            "because n_complex_samples is not set!",
                            __func__));
    } // hash of default constructor

    // stream i/o
    static SimradRawWaterColumnCalibration from_stream(std::istream& is)
    {
        SimradRawWaterColumnCalibration calibration(t_base::from_stream(is));

        is.read(reinterpret_cast<char*>(&calibration._transducer_gain_db), sizeof(float) * 16);

        // write optional values
        size_t n_complex_samples;
        is.read(reinterpret_cast<char*>(&n_complex_samples), sizeof(n_complex_samples));
        if (n_complex_samples != std::numeric_limits<size_t>::max())
            calibration._n_complex_samples = n_complex_samples;

        std::array<float, 5> optional_values;
        is.read(reinterpret_cast<char*>(optional_values.data()), sizeof(float) * 5);
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

        is.read(reinterpret_cast<char*>(&calibration._initialized),
                sizeof(calibration._initialized));

        return calibration;
    }

    void to_stream(std::ostream& os) const
    {
        WaterColumnCalibration::to_stream(os);

        os.write(reinterpret_cast<const char*>(&_transducer_gain_db), sizeof(float) * 16);

        // read optional values
        size_t n_complex_samples = _n_complex_samples.value_or(std::numeric_limits<size_t>::max());
        os.write(reinterpret_cast<const char*>(&n_complex_samples), sizeof(n_complex_samples));

        std::array<float, 5> optional_values = {
            _power_conversion_factor_db.value_or(std::numeric_limits<float>::quiet_NaN()),
            _rounded_latitude_deg.value_or(std::numeric_limits<float>::quiet_NaN()),
            _rounded_longitude_deg.value_or(std::numeric_limits<float>::quiet_NaN()),
            _forced_sound_velocity_m_s.value_or(std::numeric_limits<float>::quiet_NaN()),
            _forced_absorption_db_m.value_or(std::numeric_limits<float>::quiet_NaN())
        };
        os.write(reinterpret_cast<const char*>(optional_values.data()), sizeof(float) * 5);
        os.write(reinterpret_cast<const char*>(&_initialized), sizeof(_initialized));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
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
        printer.register_value("effective_pulse_duration_s", _effective_pulse_duration_s, "s");

        printer.register_section("Computed parameters");
        printer.register_value("computed_sound_velocity_m_s", _computed_sound_velocity_m_s, "m/s");
        printer.register_optional_value(
            "forced_sound_velocity_m_s", _forced_sound_velocity_m_s, "m/s");
        printer.register_value("sound_velocity_m_s", get_sound_velocity_m_s(), "m/s [used value]");
        printer.register_value("computed_absorption_db_m", _computed_absorption_db_m, "dB/m");
        printer.register_optional_value("forced_absorption_db_m", _forced_absorption_db_m, "dB/m");
        printer.register_value("absorption_db_m", get_absorption_db_m(), "dB/m [used value]");
        printer.register_value("wavelength_m", _wavelength_m, "m");
        printer.register_value("corr_transducer_gain_db", _corr_transducer_gain_db, "dB");
        printer.register_value(
            "corr_equivalent_beam_angle_db", _corr_equivalent_beam_angle_db, "dB");

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

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SimradRawWaterColumnCalibration)

  private:
    static void throw_because_value_is_note_finite(std::string_view value_name, float value)
    {
        throw std::runtime_error(fmt::format("ERROR[SimradRawWaterColumnCalibraiton]:"
                                             "Calibration not initialized because {} is {}!",
                                             value_name,
                                             value));
    }
};

// boost hash
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const SimradRawWaterColumnCalibration& arg)
{
    return arg.binary_hash();
}
}
}
}
}
}