// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumndatagrambeam.doc.hpp"

// std includes
#include <string>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../em3000_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {
namespace substructures {

/**
 * @brief
 *
 */
class WaterColumnDatagramBeam
{
    int16_t  _beam_pointing_angle; ///< re vertical in 0.01 steps°
    uint16_t _start_range_sample_number;
    uint16_t _number_of_samples;
    uint16_t _detected_range_in_samples;
    uint8_t  _transmit_sector_number;
    uint8_t  _beam_number; ///< redundant info, max 255 even if more beams exist

    xt::xtensor<int8_t, 1> _samples; /// < in 0.5 dB steps

  public:
    WaterColumnDatagramBeam()  = default;
    ~WaterColumnDatagramBeam() = default;

    // ----- convenient member access -----
    // getters
    int16_t  get_beam_pointing_angle() const { return _beam_pointing_angle; }
    uint16_t get_start_range_sample_number() const { return _start_range_sample_number; }
    uint16_t get_number_of_samples() const { return _number_of_samples; }
    uint16_t get_detected_range_in_samples() const { return _detected_range_in_samples; }
    uint8_t  get_transmit_sector_number() const { return _transmit_sector_number; }
    uint8_t  get_beam_number() const { return _beam_number; }

    // setters
    void set_beam_pointing_angle(int16_t beam_pointing_angle)
    {
        _beam_pointing_angle = beam_pointing_angle;
    }
    void set_start_range_sample_number(uint16_t start_range_sample_number)
    {
        _start_range_sample_number = start_range_sample_number;
    }
    void set_number_of_samples(uint16_t number_of_samples)
    {
        _number_of_samples = number_of_samples;
    }
    void set_detected_range_in_samples(uint16_t detected_range_in_samples)
    {
        _detected_range_in_samples = detected_range_in_samples;
    }
    void set_transmit_sector_number(uint8_t transmit_sector_number)
    {
        _transmit_sector_number = transmit_sector_number;
    }
    void set_beam_number(uint8_t beam_number) { _beam_number = beam_number; }

    // structure access
    const xt::xtensor<int8_t, 1>& get_samples() { return _samples; }
    void set_samples(const xt::xtensor<int8_t, 1>& samples) { _samples = samples; }
    xt::xtensor<int8_t, 1>& samples() { return _samples; }

    // ----- processed member access -----
    /**
     * @brief get the tilt angle in °
     *
     * @return _beam_pointing_angle * 0.1° (float)
     */
    float get_beam_pointing_angle_in_degrees() const { return _beam_pointing_angle * 0.1f; }

    xt::xtensor<float, 1> get_samples_in_db() const
    {
        return xt::xtensor<float, 1>(xt::eval(_samples * 0.5f));
    }

    //----- to/from stream functions -----
    static WaterColumnDatagramBeam from_stream(std::istream& is)
    {
        // init the sample amplitudes structure with the correct size
        WaterColumnDatagramBeam data;

        // read the first part of the data
        is.read(reinterpret_cast<char*>(&data._beam_pointing_angle), 10 * sizeof(uint8_t));

        // read the sample amplitudes
        data._samples =
            xt::empty<int8_t>(xt::xtensor<int8_t, 1>::shape_type({ data._number_of_samples }));

        is.read(reinterpret_cast<char*>(data._samples.data()),
                data._number_of_samples * sizeof(int8_t));

        return data;
    }

    void to_stream(std::ostream& os)
    {
        _number_of_samples = _samples.size();

        // write the first part of the data
        os.write(reinterpret_cast<const char*>(&_beam_pointing_angle), 10 * sizeof(uint8_t));

        // write the sample amplitudes
        os.write(reinterpret_cast<char*>(_samples.data()), _number_of_samples * sizeof(int8_t));
    }

    // ----- operators -----
    bool operator==(const WaterColumnDatagramBeam& other) const
    {
        return _beam_pointing_angle == other._beam_pointing_angle &&
               _start_range_sample_number == other._start_range_sample_number &&
               _number_of_samples == other._number_of_samples &&
               _detected_range_in_samples == other._detected_range_in_samples &&
               _transmit_sector_number == other._transmit_sector_number &&
               _beam_number == other._beam_number && xt::all(xt::equal(_samples, other._samples));
    }
    bool operator!=(const WaterColumnDatagramBeam& other) const { return !(*this == other); }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("WaterColumnDatagramBeam", float_precision);

        // raw values
        printer.register_value("_beam_pointing_angle", _beam_pointing_angle, "0.01°");

        printer.register_value("start_range_sample_number", _start_range_sample_number);
        printer.register_value("number_of_samples", _number_of_samples);
        printer.register_value("detected_range_in_samples", _detected_range_in_samples);
        printer.register_value("transmit_sector_number", _transmit_sector_number);
        printer.register_value("beam_number", _beam_number);

        // sample values
        printer.register_section("samples");
        printer.register_container("samples", _samples);

        // processed values
        printer.register_section("processed");
        printer.register_value("beam_pointing_angle", get_beam_pointing_angle_in_degrees(), "°");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(WaterColumnDatagramBeam)
};

} // namespace substructures
} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping