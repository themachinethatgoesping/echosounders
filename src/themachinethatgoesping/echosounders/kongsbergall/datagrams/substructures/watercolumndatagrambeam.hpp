// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumndatagrambeam.doc.hpp"

// std includes
#include <string>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>


#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief
 *
 */
class WatercolumnDatagramBeam
{
    int16_t  _beam_crosstrack_angle; ///< re vertical in 0.01 steps°
    uint16_t _start_range_sample_number;
    uint16_t _number_of_samples;
    uint16_t _detected_range_in_samples;
    uint8_t  _transmit_sector_number;
    uint8_t  _beam_number; ///< redundant info, max 255 even if more beams exist

    // TODO: this should be an optional value because it takes to much space otherwise
    xt::xtensor<int8_t, 1> _samples; /// < in 0.5 dB steps

    // flags that do not belong to the datagramformat specification
    bool _samples_are_skipped =
        false; ///< This flag is set if from_stream was called with the "skip_data" argument. Call
               ///< load or set_data to set it to false.

    size_t _sample_pos; ///< the position of the sample data in the filestream. This
                        ///< is used to load skipped sample data.

  public:
    WatercolumnDatagramBeam()          = default;
    virtual ~WatercolumnDatagramBeam() = default;

    // ----- convenient member access -----
    // getters
    int16_t  get_beam_crosstrack_angle() const { return _beam_crosstrack_angle; }
    uint16_t get_start_range_sample_number() const { return _start_range_sample_number; }
    uint16_t get_number_of_samples() const { return _number_of_samples; }
    uint16_t get_detected_range_in_samples() const { return _detected_range_in_samples; }
    uint8_t  get_transmit_sector_number() const { return _transmit_sector_number; }
    uint8_t  get_beam_number() const { return _beam_number; }
    size_t   get_sample_position() const
    {
        if (!_samples_are_skipped)
            throw(std::runtime_error(
                fmt::format("ERROR[WatercolumnDatagramBeam::get_sample_position]: "
                            "The sample position is only available if the data "
                            "was skipped!")));
        return _sample_pos;
    }

    // this function is only used for testing
    void _set_sample_are_skipped(size_t sample_pos)
    {
        _sample_pos          = sample_pos;
        _samples_are_skipped = true;
        _samples = xt::xtensor<int8_t, 1>();
    }

    // setters
    void set_beam_crosstrack_angle(int16_t beam_crosstrack_angle)
    {
        _beam_crosstrack_angle = beam_crosstrack_angle;
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

    bool get_samples_are_skipped() { return _samples_are_skipped; }

    // structure access
    /**
     * @brief Read and return the sample data. This is useful if the sample data was originally
     * skipped
     *
     * @param ifs InputFileHandler stream. Must be the same file the original structure was read
     * from
     * @return xt::xtensor<int8_t, 1>
     */
    xt::xtensor<int8_t, 1> read_samples(std::istream& ifs) const
    {
        xt::xtensor<int8_t, 1> samples =
            xt::empty<int8_t>(xt::xtensor<int8_t, 1>::shape_type({ _number_of_samples }));

        ifs.seekg(get_sample_position());

        ifs.read(reinterpret_cast<char*>(samples.data()), _number_of_samples * sizeof(int8_t));

        return samples;
    }

    // structure access
    /**
     * @brief Read and return the sample data. This function allows for only reading a selected
     * number of samples
     *
     * @param ifs InputFileHandler stream. Must be the same file the original structure was read
     * from
     * @param pos_first_samples The position of the first sample in the structure
     * @param first_sample The first sample to read
     * @param number_of_samples The number of samples to read
     * @param number_of_samples_in_datagram The total number of samples in the datagram
     * @param fill_val The value to fill the array with if the requested number of samples is
     * @return xt::xtensor<int8_t, 1>
     */
    static xt::xtensor<int8_t, 1> read_samples(std::istream& ifs,
                                               size_t        pos_first_sample,
                                               size_t        first_sample,
                                               size_t        number_of_samples,
                                               size_t        number_of_samples_in_datagram)
    {
        auto samples = xt::xtensor<int8_t, 1>::from_shape({ number_of_samples });

        // do not read more samples than exist
        if (first_sample + number_of_samples > number_of_samples_in_datagram)
            throw std::range_error(
                fmt::format("ERROR[WatercolumnDatagramBeam::read_samples]: The requested number of "
                            "samples [{} + {} ]"
                            "exceeds the number of samples in the datagram [{}]!",
                            first_sample,
                            number_of_samples,
                            number_of_samples_in_datagram));

        ifs.seekg(pos_first_sample + size_t(first_sample * sizeof(int8_t)));

        ifs.read(reinterpret_cast<char*>(samples.data()), number_of_samples * sizeof(int8_t));

        return samples;
    }

    const xt::xtensor<int8_t, 1>& get_samples() const
    {
        if (_samples_are_skipped)
            throw(std::runtime_error(fmt::format("ERROR[WatercolumnDatagramBeam::get_samples]: The "
                                                 "data is not available because it was skipped! "
                                                 "Call load or set_data first.")));

        return _samples;
    }
    void set_samples(const xt::xtensor<int8_t, 1>& samples)
    {
        _samples             = samples;
        _samples_are_skipped = false;
    }
    xt::xtensor<int8_t, 1>& samples() { return _samples; }

    // ----- processed member access -----
    /**
     * @brief get the tilt angle in °
     *
     * @return _beam_crosstrack_angle * 0.1° (float)
     */
    float get_beam_crosstrack_angle_in_degrees() const { return _beam_crosstrack_angle * 0.01f; }

    xt::xtensor<float, 1> get_samples_in_db(float db_offset = 0.f) const
    {
        if (_samples_are_skipped)
            throw(std::runtime_error(fmt::format("ERROR[WatercolumnDatagramBeam::get_samples]: The "
                                                 "data is not available because it was skipped! "
                                                 "Call load or set_data first.")));

        return xt::xtensor<float, 1>(xt::eval(_samples * 0.5f - db_offset));
    }

    //----- to/from stream functions -----
    static WatercolumnDatagramBeam from_stream(std::istream& is, bool skip_data = false)
    {
        // init the sample amplitudes structure with the correct size
        WatercolumnDatagramBeam data;

        // read the first part of the data
        is.read(reinterpret_cast<char*>(&data._beam_crosstrack_angle), 10 * sizeof(uint8_t));

        // save the position of the samples of this beam
        data._sample_pos = is.tellg();

        // read the sample amplitudes
        if (skip_data)
        {
            data._samples_are_skipped = true;

            // data._samples = xt::empty<int8_t>(xt::xtensor<int8_t, 1>::shape_type({ 0 }));

            // reset the _samples array
            data._samples = xt::xtensor<int8_t, 1>();

            // skip the data
            is.seekg(data._number_of_samples * sizeof(int8_t), std::ios_base::cur);
        }
        else
        {
            data._samples_are_skipped = false;

            data._samples =
                xt::empty<int8_t>(xt::xtensor<int8_t, 1>::shape_type({ data._number_of_samples }));

            is.read(reinterpret_cast<char*>(data._samples.data()),
                    data._number_of_samples * sizeof(int8_t));
        }

        return data;
    }

    void to_stream(std::ostream& os)
    {
        _number_of_samples = _samples.size();

        // write the first part of the data
        os.write(reinterpret_cast<const char*>(&_beam_crosstrack_angle), 10 * sizeof(uint8_t));

        // write the sample amplitudes
        if (!_samples_are_skipped)
        {
            if (_samples.size() != _number_of_samples)
                throw(std::runtime_error(fmt::format("ERROR[WatercolumnDatagramBeam::to_stream]: "
                                                     "The number of samples does not match the "
                                                     "number of samples in the sample amplitude "
                                                     "array!")));
            os.write(reinterpret_cast<char*>(_samples.data()), _number_of_samples * sizeof(int8_t));
        }
        else
        {
            // write zeros
            std::vector<int8_t> zeros(_number_of_samples, 0);
            os.write(reinterpret_cast<char*>(zeros.data()), _number_of_samples * sizeof(int8_t));
        }
    }

    // ----- operators -----
    bool operator==(const WatercolumnDatagramBeam& other) const
    {
        return _beam_crosstrack_angle == other._beam_crosstrack_angle &&
               _start_range_sample_number == other._start_range_sample_number &&
               _number_of_samples == other._number_of_samples &&
               _detected_range_in_samples == other._detected_range_in_samples &&
               _transmit_sector_number == other._transmit_sector_number &&
               _beam_number == other._beam_number && xt::all(xt::equal(_samples, other._samples));
    }
    bool operator!=(const WatercolumnDatagramBeam& other) const { return !(*this == other); }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("WatercolumnDatagramBeam", float_precision, superscript_exponents);

        // raw values
        printer.register_value("beam_crosstrack_angle", _beam_crosstrack_angle, "0.01°");

        printer.register_value("start_range_sample_number", _start_range_sample_number);
        printer.register_value("number_of_samples", _number_of_samples);
        printer.register_value("detected_range_in_samples", _detected_range_in_samples);
        printer.register_value("transmit_sector_number", _transmit_sector_number);
        printer.register_value("beam_number", _beam_number);

        // sample values
        printer.register_section("samples");
        if (!_samples_are_skipped)
            printer.register_container("samples", _samples);
        else
            printer.register_string("samples", "skipped");

        // processed values
        printer.register_section("processed");
        printer.register_value(
            "beam_crosstrack_angle", get_beam_crosstrack_angle_in_degrees(), "°");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(WatercolumnDatagramBeam)
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
