// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/rawrangeandangletransmitsector.doc.hpp"

// std includes
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/algorithms/signalprocessing/types.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../types.hpp"

#include "flag_detection_information.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief The beam data are given re the transmit transducer or sonar head depth and the horizontal
 * location (x,y) of the active positioning system's reference point. Heave, roll, pitch, sound
 * speed at the transducer depth and ray bending through the water column have been applied.
 *
 */
class RawRangeAndAngleTransmitSector
{
    int16_t  _tilt_angle;                  ///< re TX array in 0.01°
    uint16_t _focus_range;                 ///< in 0.1m 0 = no focus applied
    float    _signal_length;               ///< in s
    float    _sector_transmit_delay;       ///< relative first TX pulse, in s
    float    _centre_frequency;            ///< in Hz
    uint16_t _mean_absorption_coefficient; ///< in 0.01 dB/km
    uint8_t  _signal_waveform_identifier;
    uint8_t  _transmit_sector_number;
    float    _signal_bandwidth; ///< in Hz

  public:
    RawRangeAndAngleTransmitSector()  = default;
    ~RawRangeAndAngleTransmitSector() = default;

    // convenient member access
    int16_t  get_tilt_angle() const { return _tilt_angle; }
    uint16_t get_focus_range() const { return _focus_range; }
    float    get_signal_length() const { return _signal_length; }
    float    get_sector_transmit_delay() const { return _sector_transmit_delay; }
    float    get_centre_frequency() const { return _centre_frequency; }
    uint16_t get_mean_absorption_coefficient() const { return _mean_absorption_coefficient; }
    uint8_t  get_signal_waveform_identifier() const { return _signal_waveform_identifier; }
    uint8_t  get_transmit_sector_number() const { return _transmit_sector_number; }
    float    get_signal_bandwidth() const { return _signal_bandwidth; }

    void set_tilt_angle(int16_t tilt_angle) { _tilt_angle = tilt_angle; }
    void set_focus_range(uint16_t focus_range) { _focus_range = focus_range; }
    void set_signal_length(float signal_length) { _signal_length = signal_length; }
    void set_sector_transmit_delay(float sector_transmit_delay)
    {
        _sector_transmit_delay = sector_transmit_delay;
    }
    void set_centre_frequency(float centre_frequency) { _centre_frequency = centre_frequency; }
    void set_mean_absorption_coefficient(uint16_t mean_absorption_coefficient)
    {
        _mean_absorption_coefficient = mean_absorption_coefficient;
    }
    void set_signal_waveform_identifier(uint8_t signal_waveform_identifier)
    {
        _signal_waveform_identifier = signal_waveform_identifier;
    }
    void set_transmit_sector_number(uint8_t transmit_sector_number)
    {
        _transmit_sector_number = transmit_sector_number;
    }
    void set_signal_bandwidth(float signal_bandwidth) { _signal_bandwidth = signal_bandwidth; }

    // ----- processed member access -----
    /**
     * @brief Get the tilt angle in °
     *
     * @return _tilt_angle * 0.01 (float)
     */
    float get_tilt_angle_in_degrees() const { return _tilt_angle * 0.01f; }

    /**
     * @brief Get the focus range in m
     *
     * @return _focus_range * 0.1 (float)
     */
    float get_focus_range_in_m() const { return _focus_range * 0.1f; }

    /**
     * @brief Get the mean absorption coefficient in dB/m
     *
     * @return _mean_absorption_coefficient * 10 (float)
     */
    float get_mean_absorption_coefficient_in_dB_per_m() const
    {
        return _mean_absorption_coefficient * 0.00001f;
    }

    algorithms::signalprocessing::types::t_TxSignalType get_tx_signal_type() const
    {
        switch (_signal_waveform_identifier)
        {
            case 0:
                return algorithms::signalprocessing::types::t_TxSignalType::CW;
            case 1:
                return algorithms::signalprocessing::types::t_TxSignalType::FM_UP_SWEEP;
            case 2:
                return algorithms::signalprocessing::types::t_TxSignalType::FM_DOWN_SWEEP;
            default:
                return algorithms::signalprocessing::types::t_TxSignalType::OTHER;
        }
    }

    // ----- operators -----
    bool operator==(const RawRangeAndAngleTransmitSector& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("RawRangeAndAngleTransmitSector",
                                                  float_precision);

        // raw values
        printer.register_value("tilt_angle", _tilt_angle, "0.01°");
        printer.register_value("focus_range", _focus_range, "0.1m");
        printer.register_value("signal_length", _signal_length, "s");
        printer.register_value("sector_transmit_delay", _sector_transmit_delay, "s");
        printer.register_value("centre_frequency", _centre_frequency, "Hz");
        printer.register_value(
            "mean_absorption_coefficient", _mean_absorption_coefficient, "0.01 dB/km");
        printer.register_value("signal_waveform_identifier", _signal_waveform_identifier);
        printer.register_value("transmit_sector_number", _transmit_sector_number);
        printer.register_value("signal_bandwidth", _signal_bandwidth, "Hz");

        // processed values
        printer.register_section("processed");
        printer.register_value("tilt_angle", get_tilt_angle_in_degrees(), "°");
        printer.register_value("focus_range", get_focus_range_in_m(), "m");
        printer.register_value(
            "mean_absorption_coefficient", get_mean_absorption_coefficient_in_dB_per_m(), "dB/m");
        printer.register_value(
            "tx_signal_type",
            algorithms::signalprocessing::types::to_string(get_tx_signal_type()));

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
