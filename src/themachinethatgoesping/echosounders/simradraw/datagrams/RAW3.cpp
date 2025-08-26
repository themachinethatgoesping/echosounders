// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "RAW3.hpp"

#include <bitset>
#include <fmt/format.h>
#include <magic_enum/magic_enum.hpp>
#include <stdexcept>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

// ----- file I/O -----
RAW3 RAW3::from_stream(std::istream& is,
                       bool          skip_sample_data,
                       bool          seek_end_when_skipping_data)
{
    return from_stream(is,
                       SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::RAW3),
                       skip_sample_data,
                       seek_end_when_skipping_data);
}

RAW3 RAW3::from_stream(std::istream&                 is,
                       t_SimradRawDatagramIdentifier type,
                       bool                          skip_sample_data,
                       bool                          seek_end_when_skipping_data)
{
    if (type != t_SimradRawDatagramIdentifier::RAW3)
        throw std::runtime_error("RAW3::from_stream: wrong datagram type");

    return from_stream(is,
                       SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::RAW3),
                       skip_sample_data,
                       seek_end_when_skipping_data);
}

void RAW3::to_stream(std::ostream& os)
{
    //_count = _Samples.size();
    auto data_type_size = get_raw3datatype_size(_data_type);

    // TODO: support 16 bit complex data
    _length = simradraw_long(_count * data_type_size * get_number_of_complex_samples() + 152);

    _datagram_type = simradraw_long(t_SimradRawDatagramIdentifier::RAW3);
    //_channel_id.resize(128, '\x00');

    SimradRawDatagram::to_stream(os);

    os.write(_channel_id.data(), 140);

    tools::helper::visit_variant(
        _sample_data,
        [&os, this](raw3datatypes::RAW3DataSkipped& data) {
            data.to_stream(
                os, this->_count, this->get_data_type(), this->get_number_of_complex_samples());
        },
        [&os](auto& data) { data.to_stream(os); });

    os.write(reinterpret_cast<const char*>(&_length), sizeof(simradraw_long));
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter RAW3::__printer__(unsigned int float_precision,
                                              bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "Sample binary datagram", float_precision, superscript_exponents);

    printer.append(SimradRawDatagram::__printer__(float_precision, superscript_exponents));

    std::stringstream datatype_as_bytes;
    datatype_as_bytes << "0b" << std::bitset<8>(uint8_t(_data_type));

    std::stringstream csamples_as_bytes;
    csamples_as_bytes << "0b" << std::bitset<8>(_number_of_complex_samples);

    printer.register_section("Sample datagram header");
    printer.register_string("channel_id", std::string(get_channel_id_stripped()));
    printer.register_string("data_type (bytes)", datatype_as_bytes.str());
    printer.register_enum("data_type", _data_type);
    printer.register_value("complex samples (bytes)", csamples_as_bytes.str());
    printer.register_value("complex samples", _number_of_complex_samples);
    printer.register_value("spare_1", _spare_1);
    printer.register_value("spare_2", _spare_2);
    printer.register_value("offset", _offset);
    printer.register_value("count", _count);

    printer.register_section(
        fmt::format("sample data ({})", magic_enum::enum_name(_data_type)));
    printer.append(tools::helper::visit_variant(
        _sample_data, [float_precision, superscript_exponents](auto& data) {
            return data.__printer__(float_precision, superscript_exponents);
        }));

    return printer;
}

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
