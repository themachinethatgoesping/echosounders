// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mwcrxbeamdata.doc.hpp"

// std includes
#include <cstdint>
#include <optional>
#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

/**
 * @brief
 *
 */
class MWCRxBeamData
{
    float    _beam_pointing_angle_re_vertical_deg;
    uint16_t _start_range_sample_number;
    uint16_t _detected_range_in_samples;
    uint16_t _transmit_sector_number;
    uint16_t _number_of_samples;
    float    _detected_range_in_samples_high_resolution;

    std::optional<xt::xtensor<int8_t, 1>> _sample_amplitudes_05dB;
    std::optional<xt::xtensor<int8_t, 1>> _rx_beam_phase;

    size_t _sample_pos; ///< the position of the sample data in the filestream. This
                        ///< is used to load skipped sample data.

  public:
    MWCRxBeamData()          = default;
    virtual ~MWCRxBeamData() = default;

    // ----- convenient member access -----
    // getters
    float get_beam_pointing_angle_re_vertical_deg() const
    {
        return _beam_pointing_angle_re_vertical_deg;
    }
    uint16_t get_start_range_sample_number() const { return _start_range_sample_number; }
    uint16_t get_detected_range_in_samples() const { return _detected_range_in_samples; }
    uint16_t get_transmit_sector_number() const { return _transmit_sector_number; }
    uint16_t get_number_of_samples() const { return _number_of_samples; }
    float    get_detected_range_in_samples_high_resolution() const
    {
        return _detected_range_in_samples_high_resolution;
    }
    std::optional<xt::xtensor<int8_t, 1>> get_sample_amplitudes_05dB() const
    {
        return _sample_amplitudes_05dB;
    }
    std::optional<xt::xtensor<int8_t, 1>> get_rx_beam_phase() const { return _rx_beam_phase; }

    bool   get_samples_are_skipped() const { return !_sample_amplitudes_05dB.has_value(); }
    size_t get_sample_position() const
    {
        if (!get_samples_are_skipped())
            throw std::runtime_error(
                fmt::format("ERROR[MWCRxBeamData::get_sample_position]: "
                            "The sample position is only available if the data was skipped!"));

        return _sample_pos;
    }

    // setters
    void set_beam_pointing_angle_re_vertical_deg(int16_t beam_pointing_angle_re_vertical_deg)
    {
        _beam_pointing_angle_re_vertical_deg = beam_pointing_angle_re_vertical_deg;
    }
    void set_start_range_sample_number(uint16_t start_range_sample_number)
    {
        _start_range_sample_number = start_range_sample_number;
    }
    void set_detected_range_in_samples(uint16_t detected_range_in_samples)
    {
        _detected_range_in_samples = detected_range_in_samples;
    }
    void set_transmit_sector_number(uint16_t transmit_sector_number)
    {
        _transmit_sector_number = transmit_sector_number;
    }
    void set_number_of_samples(uint16_t number_of_samples)
    {
        _number_of_samples = number_of_samples;
    }
    void set_detected_range_in_samples_high_resolution(
        float detected_range_in_samples_high_resolution)
    {
        _detected_range_in_samples_high_resolution = detected_range_in_samples_high_resolution;
    }
    void set_sample_amplitudes_05dB(const xt::xtensor<int8_t, 1>& sample_amplitudes_05dB)
    {
        _sample_amplitudes_05dB = sample_amplitudes_05dB;
        _number_of_samples      = static_cast<uint16_t>(_sample_amplitudes_05dB.value().size());
    }
    void set_rx_beam_phase(const xt::xtensor<int8_t, 1>& rx_beam_phase)
    {
        _rx_beam_phase = rx_beam_phase;
    }
    void set_sample_are_skipped(size_t sample_pos)
    {
        _sample_pos             = sample_pos;
        _sample_amplitudes_05dB = std::nullopt;
        _rx_beam_phase          = std::nullopt;
    }

    // structure access
    /**
     * @brief Read and return the sample data. This is useful if the sample data was originally
     * skipped
     *
     * @param ifs InputFileHandler stream. Must be the same file the original structure was read
     * from
     * @return xt::xtensor<int8_t, 1>
     */
    xt::xtensor<int8_t, 1> read_sample_amplitudes_05dB(std::istream& ifs) const;

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
    static xt::xtensor<int8_t, 1> read_sample_amplitudes_05dB(std::istream& ifs,
                                                              size_t        pos_first_sample,
                                                              size_t        first_sample,
                                                              size_t        number_of_samples,
                                                              size_t number_of_samples_in_datagram);

    xt::xtensor<int8_t, 1>& sample_amplitudes_05dB();

    // ----- processed member access -----
    xt::xtensor<float, 1> get_sample_amplitudes_in_db(float db_offset = 0.0f) const;

    //----- to/from stream functions -----
    static MWCRxBeamData from_stream(std::istream& is,
                                     bool          skip_data            = false,
                                     const size_t  header_bytes_to_read = 16,
                                     const bool    phase_data           = true);

    void to_stream(std::ostream& os, const size_t header_bytes_to_write = 16) const;

    // ----- operators -----
    bool operator==(const MWCRxBeamData& other) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(MWCRxBeamData)
};

} // namespace substructures
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
