// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "compressedwatercolumnbeam.hpp"

#include <istream>
#include <ostream>
#include <string>
#include <utility>
#include <variant>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

// ----- convenient member access -----
uint16_t CompressedWaterColumnBeam::get_beam_number() const
{
    return _beam_number;
}
uint8_t CompressedWaterColumnBeam::get_segment_number() const
{
    return _segment_number;
}
uint32_t CompressedWaterColumnBeam::get_sample_count() const
{
    return _sample_count;
}

void CompressedWaterColumnBeam::set_beam_number(uint16_t val)
{
    _beam_number = val;
}
void CompressedWaterColumnBeam::set_segment_number(uint8_t val)
{
    _segment_number = val;
}
void CompressedWaterColumnBeam::set_sample_count(uint32_t val)
{
    _sample_count = val;
}

// ----- sample data access -----
const CompressedWaterColumnDataVariant& CompressedWaterColumnBeam::get_samples() const
{
    return _samples;
}
CompressedWaterColumnDataVariant& CompressedWaterColumnBeam::samples()
{
    return _samples;
}
void CompressedWaterColumnBeam::set_samples(CompressedWaterColumnDataVariant samples)
{
    _samples = std::move(samples);
}

bool CompressedWaterColumnBeam::has_phase() const
{
    return std::visit([](const auto& data) { return data.has_phase(); }, _samples);
}
xt::xtensor<uint32_t, 1> CompressedWaterColumnBeam::get_raw_magnitude() const
{
    return std::visit([](const auto& data) { return data.get_raw_magnitude(); }, _samples);
}
xt::xtensor<int16_t, 1> CompressedWaterColumnBeam::get_raw_phase() const
{
    return std::visit([](const auto& data) { return data.get_raw_phase(); }, _samples);
}

void CompressedWaterColumnBeam::read(std::istream&                   is,
                                     bool                            has_segment,
                                     t_CompressedWaterColumnDataType type)
{
    is.read(reinterpret_cast<char*>(&_beam_number), sizeof(_beam_number));
    if (has_segment)
        is.read(reinterpret_cast<char*>(&_segment_number), sizeof(_segment_number));
    is.read(reinterpret_cast<char*>(&_sample_count), sizeof(_sample_count));

    // read the samples straight into the matching native-typed variant alternative (no conversion)
    _samples = compressed_water_column_data_from_stream(is, type, _sample_count);
}

void CompressedWaterColumnBeam::to_stream(std::ostream& os, bool has_segment) const
{
    os.write(reinterpret_cast<const char*>(&_beam_number), sizeof(_beam_number));
    if (has_segment)
        os.write(reinterpret_cast<const char*>(&_segment_number), sizeof(_segment_number));
    os.write(reinterpret_cast<const char*>(&_sample_count), sizeof(_sample_count));

    std::visit([&os](const auto& data) { data.to_stream(os); }, _samples);
}

tools::classhelper::ObjectPrinter CompressedWaterColumnBeam::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "CompressedWaterColumnBeam", float_precision, superscript_exponents);

    printer.register_value("beam_number", _beam_number);
    printer.register_value("segment_number", _segment_number);
    printer.register_value("sample_count", _sample_count, "samples");
    printer.register_string(
        "data_type",
        std::visit([](const auto& data) { return std::string(data.class_name()); }, _samples));

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
