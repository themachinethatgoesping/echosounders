// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/compressedwatercolumndatatypes.doc.hpp"

// std includes
#include <cstdint>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <string_view>
#include <variant>

// xtensor includes
#include <xtensor/containers/xtensor.hpp>
#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief The possible per-sample encodings of a 7042 CompressedWaterColumnData beam (Table 84).
 *
 * The encoding is record-wide (derived from the record flags); every beam of one record uses the
 * same encoding. Skipped is the state of a beam whose samples were not read (yet).
 */
enum class t_CompressedWaterColumnDataType : uint8_t
{
    Skipped = 0,        ///< samples not read (lazy)
    Magnitude16,        ///< B) 16 bit magnitude, no phase
    Magnitude16Phase16, ///< A) 16 bit magnitude + 16 bit phase
    Magnitude8,         ///< D) 8 bit (dB) magnitude, no phase
    Magnitude8Phase8,   ///< C) 8 bit (dB) magnitude + 8 bit phase
    Magnitude32,        ///< F) 32 bit magnitude, no phase
    Magnitude32Phase8,  ///< E) 32 bit magnitude + 8 bit phase
};

/**
 * @brief Interface for the per-beam sample data of a 7042 CompressedWaterColumnData record.
 *
 * The concrete implementations store the samples in their native (on-disk) integer type as xtensors
 * (magnitude as unsigned integers, phase as signed integers). No floating point / dB conversion is
 * done at read or at raw access; conversion is deferred to the ping water column accessor
 * (S7KPingWatercolumn) where it can run vectorized on only the selected beams/samples.
 *
 * Raw access returns the widest lossless integer type (magnitude -> uint32, phase -> int16) so a
 * single virtual signature can serve all encodings. The 8 bit phase is widened to the same int16
 * scale as the 16 bit phase (shifted into the high byte), so phase-to-radians is uniform
 * (radians = raw_phase / 10430).
 */
class I_CompressedWaterColumnData
{
    std::string_view _name; ///< name of the concrete type (for printing / error messages)

  public:
    I_CompressedWaterColumnData(std::string_view name)
        : _name(name)
    {
    }
    virtual ~I_CompressedWaterColumnData() = default;

    std::string_view class_name() const { return _name; }

    virtual bool     has_magnitude() const { return false; }
    virtual bool     has_phase() const { return false; }
    virtual uint32_t get_number_of_samples() const { return 0; }

    /// magnitude samples in their raw (unconverted) values, widened to uint32
    virtual xt::xtensor<uint32_t, 1> get_raw_magnitude() const
    {
        throw std::runtime_error("get_raw_magnitude() not implemented for " + std::string(_name));
    }

    /// phase samples in their raw (unconverted) values, widened to the int16 phase scale (empty if
    /// there is no phase). radians = raw_phase / 10430
    virtual xt::xtensor<int16_t, 1> get_raw_phase() const
    {
        return xt::xtensor<int16_t, 1>::from_shape({ 0 });
    }
};

/**
 * @brief A) 16 bit magnitude + 16 bit phase (32 bits total).
 *
 * The interleaved [magnitude, phase] samples are stored as a [n, 2] unsigned tensor exactly as on
 * disk; magnitude is column 0, the phase bits are column 1 (reinterpreted as int16 on access).
 */
struct CompressedWaterColumnDataMagnitude16Phase16 : public I_CompressedWaterColumnData
{
    xt::xtensor<uint16_t, 2> _samples; ///< [n, 2] interleaved magnitude (col 0) and phase (col 1)

    CompressedWaterColumnDataMagnitude16Phase16()
        : I_CompressedWaterColumnData("Magnitude16Phase16")
    {
    }
    explicit CompressedWaterColumnDataMagnitude16Phase16(xt::xtensor<uint16_t, 2> samples)
        : I_CompressedWaterColumnData("Magnitude16Phase16")
        , _samples(std::move(samples))
    {
    }

    bool     has_magnitude() const final { return true; }
    bool     has_phase() const final { return true; }
    uint32_t get_number_of_samples() const final { return uint32_t(_samples.shape(0)); }

    xt::xtensor<uint32_t, 1> get_raw_magnitude() const final
    {
        return xt::cast<uint32_t>(xt::view(_samples, xt::all(), 0));
    }
    xt::xtensor<int16_t, 1> get_raw_phase() const final
    {
        return xt::cast<int16_t>(xt::view(_samples, xt::all(), 1));
    }

    bool operator==(const CompressedWaterColumnDataMagnitude16Phase16& o) const
    {
        return _samples == o._samples;
    }

    static CompressedWaterColumnDataMagnitude16Phase16 from_stream(std::istream& is, uint32_t n)
    {
        CompressedWaterColumnDataMagnitude16Phase16 data(
            xt::xtensor<uint16_t, 2>::from_shape({ n, 2 }));
        is.read(reinterpret_cast<char*>(data._samples.data()), std::streamsize(n) * 4);
        return data;
    }
    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_samples.data()),
                 std::streamsize(_samples.size()) * 2);
    }

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "Magnitude16Phase16", float_precision, superscript_exponents);
        printer.register_value("number_of_samples", get_number_of_samples(), "samples");
        return printer;
    }
};

/**
 * @brief B) 16 bit magnitude, no phase (16 bits total).
 */
struct CompressedWaterColumnDataMagnitude16 : public I_CompressedWaterColumnData
{
    xt::xtensor<uint16_t, 1> _magnitude; ///< [n] magnitude samples

    CompressedWaterColumnDataMagnitude16()
        : I_CompressedWaterColumnData("Magnitude16")
    {
    }
    explicit CompressedWaterColumnDataMagnitude16(xt::xtensor<uint16_t, 1> magnitude)
        : I_CompressedWaterColumnData("Magnitude16")
        , _magnitude(std::move(magnitude))
    {
    }

    bool     has_magnitude() const final { return true; }
    uint32_t get_number_of_samples() const final { return uint32_t(_magnitude.size()); }

    xt::xtensor<uint32_t, 1> get_raw_magnitude() const final
    {
        return xt::cast<uint32_t>(_magnitude);
    }

    bool operator==(const CompressedWaterColumnDataMagnitude16& o) const
    {
        return _magnitude == o._magnitude;
    }

    static CompressedWaterColumnDataMagnitude16 from_stream(std::istream& is, uint32_t n)
    {
        CompressedWaterColumnDataMagnitude16 data(
            xt::xtensor<uint16_t, 1>::from_shape({ n }));
        is.read(reinterpret_cast<char*>(data._magnitude.data()), std::streamsize(n) * 2);
        return data;
    }
    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_magnitude.data()),
                 std::streamsize(_magnitude.size()) * 2);
    }

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "Magnitude16", float_precision, superscript_exponents);
        printer.register_value("number_of_samples", get_number_of_samples(), "samples");
        return printer;
    }
};

/**
 * @brief C) 8 bit (dB) magnitude + 8 bit phase (16 bits total).
 *
 * Stored as a [n, 2] unsigned tensor (magnitude col 0, phase col 1). The 8 bit phase is the high
 * byte of the 16 bit phase, so it is widened to int16 by shifting it back into the high byte.
 */
struct CompressedWaterColumnDataMagnitude8Phase8 : public I_CompressedWaterColumnData
{
    xt::xtensor<uint8_t, 2> _samples; ///< [n, 2] interleaved magnitude (col 0) and phase (col 1)

    CompressedWaterColumnDataMagnitude8Phase8()
        : I_CompressedWaterColumnData("Magnitude8Phase8")
    {
    }
    explicit CompressedWaterColumnDataMagnitude8Phase8(xt::xtensor<uint8_t, 2> samples)
        : I_CompressedWaterColumnData("Magnitude8Phase8")
        , _samples(std::move(samples))
    {
    }

    bool     has_magnitude() const final { return true; }
    bool     has_phase() const final { return true; }
    uint32_t get_number_of_samples() const final { return uint32_t(_samples.shape(0)); }

    xt::xtensor<uint32_t, 1> get_raw_magnitude() const final
    {
        return xt::cast<uint32_t>(xt::view(_samples, xt::all(), 0));
    }
    xt::xtensor<int16_t, 1> get_raw_phase() const final
    {
        // 8 bit phase is the high byte of the 16 bit phase -> shift it back into the high byte
        return xt::cast<int16_t>(xt::cast<int8_t>(xt::view(_samples, xt::all(), 1))) *
               int16_t(256);
    }

    bool operator==(const CompressedWaterColumnDataMagnitude8Phase8& o) const
    {
        return _samples == o._samples;
    }

    static CompressedWaterColumnDataMagnitude8Phase8 from_stream(std::istream& is, uint32_t n)
    {
        CompressedWaterColumnDataMagnitude8Phase8 data(
            xt::xtensor<uint8_t, 2>::from_shape({ n, 2 }));
        is.read(reinterpret_cast<char*>(data._samples.data()), std::streamsize(n) * 2);
        return data;
    }
    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_samples.data()), std::streamsize(_samples.size()));
    }

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "Magnitude8Phase8", float_precision, superscript_exponents);
        printer.register_value("number_of_samples", get_number_of_samples(), "samples");
        return printer;
    }
};

/**
 * @brief D) 8 bit (dB) magnitude, no phase (8 bits total).
 */
struct CompressedWaterColumnDataMagnitude8 : public I_CompressedWaterColumnData
{
    xt::xtensor<uint8_t, 1> _magnitude; ///< [n] magnitude samples (8 bit dB)

    CompressedWaterColumnDataMagnitude8()
        : I_CompressedWaterColumnData("Magnitude8")
    {
    }
    explicit CompressedWaterColumnDataMagnitude8(xt::xtensor<uint8_t, 1> magnitude)
        : I_CompressedWaterColumnData("Magnitude8")
        , _magnitude(std::move(magnitude))
    {
    }

    bool     has_magnitude() const final { return true; }
    uint32_t get_number_of_samples() const final { return uint32_t(_magnitude.size()); }

    xt::xtensor<uint32_t, 1> get_raw_magnitude() const final
    {
        return xt::cast<uint32_t>(_magnitude);
    }

    bool operator==(const CompressedWaterColumnDataMagnitude8& o) const
    {
        return _magnitude == o._magnitude;
    }

    static CompressedWaterColumnDataMagnitude8 from_stream(std::istream& is, uint32_t n)
    {
        CompressedWaterColumnDataMagnitude8 data(
            xt::xtensor<uint8_t, 1>::from_shape({ n }));
        is.read(reinterpret_cast<char*>(data._magnitude.data()), std::streamsize(n));
        return data;
    }
    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_magnitude.data()),
                 std::streamsize(_magnitude.size()));
    }

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "Magnitude8", float_precision, superscript_exponents);
        printer.register_value("number_of_samples", get_number_of_samples(), "samples");
        return printer;
    }
};

/**
 * @brief F) 32 bit magnitude, no phase (32 bits total). The 32 bit magnitude is an unsigned integer
 * (DWORD, see Appendix I), not an IEEE float.
 */
struct CompressedWaterColumnDataMagnitude32 : public I_CompressedWaterColumnData
{
    xt::xtensor<uint32_t, 1> _magnitude; ///< [n] magnitude samples (32 bit unsigned)

    CompressedWaterColumnDataMagnitude32()
        : I_CompressedWaterColumnData("Magnitude32")
    {
    }
    explicit CompressedWaterColumnDataMagnitude32(xt::xtensor<uint32_t, 1> magnitude)
        : I_CompressedWaterColumnData("Magnitude32")
        , _magnitude(std::move(magnitude))
    {
    }

    bool     has_magnitude() const final { return true; }
    uint32_t get_number_of_samples() const final { return uint32_t(_magnitude.size()); }

    xt::xtensor<uint32_t, 1> get_raw_magnitude() const final { return _magnitude; }

    bool operator==(const CompressedWaterColumnDataMagnitude32& o) const
    {
        return _magnitude == o._magnitude;
    }

    static CompressedWaterColumnDataMagnitude32 from_stream(std::istream& is, uint32_t n)
    {
        CompressedWaterColumnDataMagnitude32 data(
            xt::xtensor<uint32_t, 1>::from_shape({ n }));
        is.read(reinterpret_cast<char*>(data._magnitude.data()), std::streamsize(n) * 4);
        return data;
    }
    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_magnitude.data()),
                 std::streamsize(_magnitude.size()) * 4);
    }

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "Magnitude32", float_precision, superscript_exponents);
        printer.register_value("number_of_samples", get_number_of_samples(), "samples");
        return printer;
    }
};

/**
 * @brief E) 32 bit magnitude + 8 bit phase (40 bits total).
 *
 * Magnitude (uint32) and phase (int8) have different sizes, so they are de-interleaved into two
 * separate native tensors at read time (the only encoding that is not stored as a single tensor).
 */
struct CompressedWaterColumnDataMagnitude32Phase8 : public I_CompressedWaterColumnData
{
    xt::xtensor<uint32_t, 1> _magnitude; ///< [n] magnitude samples (32 bit unsigned)
    xt::xtensor<int8_t, 1>   _phase;     ///< [n] phase samples (8 bit, high byte of int16 phase)

    CompressedWaterColumnDataMagnitude32Phase8()
        : I_CompressedWaterColumnData("Magnitude32Phase8")
    {
    }
    CompressedWaterColumnDataMagnitude32Phase8(xt::xtensor<uint32_t, 1> magnitude,
                                               xt::xtensor<int8_t, 1>   phase)
        : I_CompressedWaterColumnData("Magnitude32Phase8")
        , _magnitude(std::move(magnitude))
        , _phase(std::move(phase))
    {
    }

    bool     has_magnitude() const final { return true; }
    bool     has_phase() const final { return true; }
    uint32_t get_number_of_samples() const final { return uint32_t(_magnitude.size()); }

    xt::xtensor<uint32_t, 1> get_raw_magnitude() const final { return _magnitude; }
    xt::xtensor<int16_t, 1>  get_raw_phase() const final
    {
        return xt::cast<int16_t>(_phase) * int16_t(256);
    }

    bool operator==(const CompressedWaterColumnDataMagnitude32Phase8& o) const
    {
        return _magnitude == o._magnitude && _phase == o._phase;
    }

    static CompressedWaterColumnDataMagnitude32Phase8 from_stream(std::istream& is, uint32_t n)
    {
        CompressedWaterColumnDataMagnitude32Phase8 data(
            xt::xtensor<uint32_t, 1>::from_shape({ n }), xt::xtensor<int8_t, 1>::from_shape({ n }));

        // magnitude (4 bytes) and phase (1 byte) are interleaved per sample -> de-interleave. This
        // is the exceptional mixed-size encoding (no bulk read); it is rare and has no test data.
        for (uint32_t s = 0; s < n; ++s)
        {
            is.read(reinterpret_cast<char*>(&data._magnitude.unchecked(s)), 4);
            is.read(reinterpret_cast<char*>(&data._phase.unchecked(s)), 1);
        }
        return data;
    }
    void to_stream(std::ostream& os) const
    {
        for (uint32_t s = 0; s < get_number_of_samples(); ++s)
        {
            os.write(reinterpret_cast<const char*>(&_magnitude.unchecked(s)), 4);
            os.write(reinterpret_cast<const char*>(&_phase.unchecked(s)), 1);
        }
    }

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "Magnitude32Phase8", float_precision, superscript_exponents);
        printer.register_value("number_of_samples", get_number_of_samples(), "samples");
        return printer;
    }
};

/**
 * @brief The (default) state of a beam whose samples were not read (skipped for lazy reading).
 */
struct CompressedWaterColumnDataSkipped : public I_CompressedWaterColumnData
{
    CompressedWaterColumnDataSkipped()
        : I_CompressedWaterColumnData("Skipped")
    {
    }

    bool operator==(const CompressedWaterColumnDataSkipped&) const { return true; }

    void to_stream(std::ostream& /*os*/) const {} // nothing to write (samples were not read)

    // graceful empty access (the samples are not loaded)
    xt::xtensor<uint32_t, 1> get_raw_magnitude() const final
    {
        return xt::xtensor<uint32_t, 1>::from_shape({ 0 });
    }

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "Skipped", float_precision, superscript_exponents);
        printer.register_string("state", "samples not read (skipped)");
        return printer;
    }
};

/**
 * @brief Variant over the possible per-beam sample encodings of a 7042 record (one class per
 * encoding, see Table 84). Skipped is the default (unread) state.
 */
using CompressedWaterColumnDataVariant = std::variant<CompressedWaterColumnDataSkipped,
                                                      CompressedWaterColumnDataMagnitude16,
                                                      CompressedWaterColumnDataMagnitude16Phase16,
                                                      CompressedWaterColumnDataMagnitude8,
                                                      CompressedWaterColumnDataMagnitude8Phase8,
                                                      CompressedWaterColumnDataMagnitude32,
                                                      CompressedWaterColumnDataMagnitude32Phase8>;

/**
 * @brief Determine the per-sample encoding of a 7042 record from its flags.
 *
 * @param magnitude_bytes number of magnitude bytes as stored on disk (1, 2 or 4)
 * @param has_phase whether the record contains phase data
 */
inline t_CompressedWaterColumnDataType compressed_water_column_data_type(uint8_t magnitude_bytes,
                                                                         bool    has_phase)
{
    switch (magnitude_bytes)
    {
        case 1:
            return has_phase ? t_CompressedWaterColumnDataType::Magnitude8Phase8
                             : t_CompressedWaterColumnDataType::Magnitude8;
        case 4:
            return has_phase ? t_CompressedWaterColumnDataType::Magnitude32Phase8
                             : t_CompressedWaterColumnDataType::Magnitude32;
        case 2:
        default:
            return has_phase ? t_CompressedWaterColumnDataType::Magnitude16Phase16
                             : t_CompressedWaterColumnDataType::Magnitude16;
    }
}

/**
 * @brief Read one beam's samples from the stream into the matching variant alternative.
 */
inline CompressedWaterColumnDataVariant compressed_water_column_data_from_stream(
    std::istream&                   is,
    t_CompressedWaterColumnDataType type,
    uint32_t                        number_of_samples)
{
    switch (type)
    {
        case t_CompressedWaterColumnDataType::Magnitude16:
            return CompressedWaterColumnDataMagnitude16::from_stream(is, number_of_samples);
        case t_CompressedWaterColumnDataType::Magnitude16Phase16:
            return CompressedWaterColumnDataMagnitude16Phase16::from_stream(is, number_of_samples);
        case t_CompressedWaterColumnDataType::Magnitude8:
            return CompressedWaterColumnDataMagnitude8::from_stream(is, number_of_samples);
        case t_CompressedWaterColumnDataType::Magnitude8Phase8:
            return CompressedWaterColumnDataMagnitude8Phase8::from_stream(is, number_of_samples);
        case t_CompressedWaterColumnDataType::Magnitude32:
            return CompressedWaterColumnDataMagnitude32::from_stream(is, number_of_samples);
        case t_CompressedWaterColumnDataType::Magnitude32Phase8:
            return CompressedWaterColumnDataMagnitude32Phase8::from_stream(is, number_of_samples);
        case t_CompressedWaterColumnDataType::Skipped:
        default:
            return CompressedWaterColumnDataSkipped();
    }
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
