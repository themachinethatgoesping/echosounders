// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "compressedwatercolumnbeam.hpp"

#include <istream>
#include <ostream>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

void CompressedWaterColumnBeam::read(std::istream& is, bool has_segment, size_t sample_stride)
{
    is.read(reinterpret_cast<char*>(&_beam_number), sizeof(_beam_number));
    if (has_segment)
        is.read(reinterpret_cast<char*>(&_segment_number), sizeof(_segment_number));
    is.read(reinterpret_cast<char*>(&_sample_count), sizeof(_sample_count));

    // read the (raw) sample block directly into its final position
    _raw_samples.resize(size_t(_sample_count) * sample_stride);
    is.read(_raw_samples.data(), std::streamsize(_raw_samples.size()));
}

void CompressedWaterColumnBeam::to_stream(std::ostream& os, bool has_segment) const
{
    os.write(reinterpret_cast<const char*>(&_beam_number), sizeof(_beam_number));
    if (has_segment)
        os.write(reinterpret_cast<const char*>(&_segment_number), sizeof(_segment_number));
    os.write(reinterpret_cast<const char*>(&_sample_count), sizeof(_sample_count));
    os.write(_raw_samples.data(), std::streamsize(_raw_samples.size()));
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

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
