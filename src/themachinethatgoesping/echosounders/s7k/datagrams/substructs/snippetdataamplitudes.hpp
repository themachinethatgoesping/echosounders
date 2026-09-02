// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/snippetdataamplitudes.doc.hpp"

// std includes
#include <cstdint>
#include <iosfwd>
#include <variant>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Intensity snippet samples of a 7028 SnippetData record (all beams).
 *
 * The samples of all beams are stored as one contiguous block on disk and are therefore read as a
 * single bulk read into a flat array. The sample data type is either 16- or 32-bit unsigned (flags
 * bit 0 of the record) and is held as a std::variant. Per-beam access, list access and dB
 * conversion are computed on demand from the flat array and the per-beam offset table. If the
 * samples were skipped while reading, the file position is stored so they can be read lazily
 * (read_samples).
 */
class SnippetDataAmplitudes
{
  public:
    using t_SamplesVariant = std::variant<xt::xtensor<uint16_t, 1>, xt::xtensor<uint32_t, 1>>;

  private:
    t_SamplesVariant        _samples;              ///< flat samples of all beams (concatenated)
    xt::xtensor<uint64_t, 1> _beam_offsets;        ///< per-beam start offsets into _samples (N + 1)
    bool                    _samples_are_32bit = false; ///< true if the samples are 32-bit
    bool                    _skipped           = false; ///< true if the samples were skipped
    int64_t                 _sample_position   = -1; ///< file position of the first sample byte

  public:
    SnippetDataAmplitudes()  = default;
    ~SnippetDataAmplitudes() = default;

    // ----- meta data access -----
    /// true if the intensity samples are stored as 32-bit values (else 16-bit)
    bool   get_samples_are_32bit() const { return _samples_are_32bit; }
    size_t get_number_of_beams() const
    {
        return _beam_offsets.size() > 0 ? _beam_offsets.size() - 1 : 0;
    }
    size_t get_total_number_of_samples() const
    {
        return _beam_offsets.size() > 0 ? size_t(_beam_offsets.unchecked(_beam_offsets.size() - 1))
                                        : 0;
    }
    bool get_samples_are_skipped() const { return _skipped; }

    /// file position of the first sample byte (only valid if the samples were skipped)
    int64_t get_sample_position() const;

    // ----- raw sample access -----
    /// flat samples of all beams (16- or 32-bit, concatenated over all beams)
    const t_SamplesVariant& get_samples() const { return _samples; }
    /// per-beam start offsets into the flat sample array (size = number_of_beams + 1)
    const xt::xtensor<uint64_t, 1>& get_beam_offsets() const { return _beam_offsets; }

    // ----- per-beam / processed access (computed on demand) -----
    /// intensity samples of a single beam (as float, in the raw amplitude scale)
    xt::xtensor<float, 1> get_beam(size_t beam_index) const;
    /// intensity samples of all beams as a list of arrays (one per beam)
    std::vector<xt::xtensor<float, 1>> get_beams() const;
    /// intensity samples of a single beam in relative dB (20*log10(amplitude) + db_offset)
    xt::xtensor<float, 1> get_beam_in_db(size_t beam_index, float db_offset = 0.f) const;
    /// intensity samples of all beams in relative dB, one array per beam
    std::vector<xt::xtensor<float, 1>> get_beams_in_db(float db_offset = 0.f) const;

    // ----- setters -----
    void set_samples(t_SamplesVariant samples)
    {
        _samples           = std::move(samples);
        _samples_are_32bit = _samples.index() == 1;
        _skipped           = false;
    }
    void set_beam_offsets(xt::xtensor<uint64_t, 1> beam_offsets)
    {
        _beam_offsets = std::move(beam_offsets);
    }
    void set_samples_are_32bit(bool value) { _samples_are_32bit = value; }
    /// mark the samples as skipped and remember the file position of the first sample byte
    void set_skipped(int64_t sample_position)
    {
        _skipped         = true;
        _sample_position = sample_position;
    }

    // ----- lazy reading -----
    /**
     * @brief Read the (previously skipped) samples from the stream.
     * @param is Input stream. Must be the same file the record was originally read from.
     */
    void read_samples(std::istream& is);

    // ----- operators -----
    bool operator==(const SnippetDataAmplitudes& other) const;
    bool operator!=(const SnippetDataAmplitudes& other) const { return !operator==(other); }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
