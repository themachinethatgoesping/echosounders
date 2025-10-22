// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumndatagrambeam.doc.hpp"

// std includes
#include <cstddef>
#include <cstdint>
#include <iosfwd>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



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
    int16_t  get_beam_crosstrack_angle() const;
    uint16_t get_start_range_sample_number() const;
    uint16_t get_number_of_samples() const;
    uint16_t get_detected_range_in_samples() const;
    uint8_t  get_transmit_sector_number() const;
    uint8_t  get_beam_number() const;
    size_t   get_sample_position() const;

    // this function is only used for testing
    void _set_sample_are_skipped(size_t sample_pos);

    // setters
    void set_beam_crosstrack_angle(int16_t beam_crosstrack_angle);
    void set_start_range_sample_number(uint16_t start_range_sample_number);
    void set_number_of_samples(uint16_t number_of_samples);
    void set_detected_range_in_samples(uint16_t detected_range_in_samples);
    void set_transmit_sector_number(uint8_t transmit_sector_number);
    void set_beam_number(uint8_t beam_number);

    bool get_samples_are_skipped();

    // structure access
    /**
     * @brief Read and return the sample data. This is useful if the sample data was originally
     * skipped
     *
     * @param ifs InputFileHandler stream. Must be the same file the original structure was read
     * from
     * @return xt::xtensor<int8_t, 1>
     */
    xt::xtensor<int8_t, 1> read_samples(std::istream& ifs) const;

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
                                               size_t        number_of_samples_in_datagram);

    const xt::xtensor<int8_t, 1>& get_samples() const;
    void set_samples(const xt::xtensor<int8_t, 1>& samples);
    xt::xtensor<int8_t, 1>& samples();

    // ----- processed member access -----
    /**
     * @brief get the tilt angle in °
     *
     * @return _beam_crosstrack_angle * 0.1° (float)
     */
    float get_beam_crosstrack_angle_in_degrees() const;

    xt::xtensor<float, 1> get_samples_in_db(float db_offset = 0.f) const;

    //----- to/from stream functions -----
    static WatercolumnDatagramBeam from_stream(std::istream& is, bool skip_data = false);

    void to_stream(std::ostream& os);

    // ----- operators -----
    bool operator==(const WatercolumnDatagramBeam& other) const;
    bool operator!=(const WatercolumnDatagramBeam& other) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter
    __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(WatercolumnDatagramBeam)
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
