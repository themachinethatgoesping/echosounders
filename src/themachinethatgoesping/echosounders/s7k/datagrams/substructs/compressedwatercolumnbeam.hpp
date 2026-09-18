// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/compressedwatercolumnbeam.doc.hpp"

// std includes
#include <cstdint>
#include <iosfwd>
#include <utility>
#include <variant>

// xtensor includes
#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "compressedwatercolumndatatypes.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Per-beam data of a 7042 CompressedWaterColumnData record.
 *
 * Holds the beam number, optional segment number, sample count and the per-beam samples. The
 * samples are stored in their native (on-disk) encoding as xtensors inside a
 * CompressedWaterColumnDataVariant (one alternative per encoding, see Table 84); no floating point
 * / dB conversion is done at read. Decoding to dB/degrees is deferred to the ping water column
 * accessor.
 */
class CompressedWaterColumnBeam
{
    uint16_t _beam_number    = 0; ///< beam number
    uint8_t  _segment_number = 0; ///< segment number (0 if segments are not used)
    uint32_t _sample_count   = 0; ///< number of samples for this beam

    CompressedWaterColumnDataVariant _samples; ///< per-beam samples in their native encoding

  public:
    CompressedWaterColumnBeam()  = default;
    ~CompressedWaterColumnBeam() = default;

    // ----- convenient member access -----
    uint16_t get_beam_number() const;
    uint8_t  get_segment_number() const;
    uint32_t get_sample_count() const;

    void set_beam_number(uint16_t val);
    void set_segment_number(uint8_t val);
    void set_sample_count(uint32_t val);

    // ----- sample data access -----
    const CompressedWaterColumnDataVariant& get_samples() const;
    CompressedWaterColumnDataVariant&       samples();
    void set_samples(CompressedWaterColumnDataVariant samples);

    /// whether this beam holds phase data
    bool has_phase() const;
    /// magnitude samples in their raw (unconverted) values, widened to uint32
    xt::xtensor<uint32_t, 1> get_raw_magnitude() const;
    /// phase samples in their raw (unconverted) int16 values (empty if there is no phase)
    xt::xtensor<int16_t, 1> get_raw_phase() const;

    // ----- stream i/o -----
    void read(std::istream& is, bool has_segment, t_CompressedWaterColumnDataType type);
    void to_stream(std::ostream& os, bool has_segment) const;

    // ----- operators -----
    bool operator==(const CompressedWaterColumnBeam& other) const = default;

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
