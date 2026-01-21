// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "RAW3.hpp"

// std
#include <fmt/format.h>
#include <algorithm>

// deps
#include <magic_enum/magic_enum.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/helper/variant.hpp>

// project 
#include "raw3datatypes/raw3datatypes.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

// ----- getter setter -----
std::string_view RAW3::get_channel_id_stripped() const
{
    auto channel_id = get_channel_id();
    return channel_id.substr(0, channel_id.find('\x00'));
}

void RAW3::set_channel_id(std::string_view channel_id)
{
    if (channel_id.size() > 128)
        throw std::runtime_error("channel_id too long");

    std::copy(channel_id.begin(), channel_id.end(), _channel_id.begin());
    // fill _channel_id with \x00
    std::fill(_channel_id.begin() + channel_id.size(), _channel_id.end(), '\x00');
}

uint8_t RAW3::get_number_of_complex_samples() const
{
    // complex data types set at least bit 3
    if (uint8_t(_data_type) < 4)
        return 1;

    // the number of samples is written in _data_type bits 8-10
    return _number_of_complex_samples;
}

// ----- file I/O -----
raw3datatypes::RAW3DataVariant RAW3::read_skipped_sample_data(std::istream& is,
                                                              size_t        header_pos) const
{
    is.seekg(header_pos + size_t(156)); // size of the header(4xint32_t) + 140 bytes channel_id
    return read_sample_data(is);
}

raw3datatypes::RAW3DataVariant RAW3::read_sample_data(std::istream& is) const
{
    using namespace raw3datatypes;

    switch (this->_data_type)
    {
        case t_RAW3DataType::ComplexFloat32:
            return RAW3DataComplexFloat32::from_stream(
                is, this->_count, this->_count, this->get_number_of_complex_samples());
        case t_RAW3DataType::PowerAndAngle:
            return RAW3DataPowerAndAngle::from_stream(is, this->_count, this->_count);

        case t_RAW3DataType::Power:
            return RAW3DataPower::from_stream(is, this->_count, this->_count);
        case t_RAW3DataType::Angle:
            return RAW3DataAngle::from_stream(is, this->_count, this->_count);
        default:
            std::cerr << fmt::format("WARNING: RAW3 data type [{}] not yet implemented!",
                                     magic_enum::enum_name(this->_data_type))
                      << std::endl;
            return RAW3DataSkipped::from_stream(
                is, this->_count, this->get_data_type(), this->get_number_of_complex_samples());
    }
}

RAW3 RAW3::from_stream(std::istream&     is,
                       SimradRawDatagram header,
                       bool              skip_sample_data,
                       bool              seek_end_when_skipping_data)
{
    using namespace raw3datatypes;

    RAW3 datagram(std::move(header));
    
    // Read fields individually to avoid potential struct padding issues
    // even though the fields appear contiguous, reading past array bounds is undefined behavior
    is.read(datagram._channel_id.data(), 128);
    is.read(reinterpret_cast<char*>(&datagram._data_type), sizeof(datagram._data_type));
    is.read(reinterpret_cast<char*>(&datagram._number_of_complex_samples), sizeof(datagram._number_of_complex_samples));
    is.read(reinterpret_cast<char*>(&datagram._spare_1), sizeof(datagram._spare_1));
    is.read(reinterpret_cast<char*>(&datagram._spare_2), sizeof(datagram._spare_2));
    is.read(reinterpret_cast<char*>(&datagram._offset), sizeof(datagram._offset));
    is.read(reinterpret_cast<char*>(&datagram._count), sizeof(datagram._count));
    
    // Validate the read succeeded and count is reasonable
    if (!is.good()) {
        throw std::runtime_error(fmt::format(
            "RAW3::from_stream: Failed to read datagram fields"));
    }
    if (datagram._count < 0 || datagram._count > 1000000) {
        throw std::runtime_error(fmt::format(
            "RAW3::from_stream: Invalid sample count: {}", datagram._count));
    }

    if (skip_sample_data)
    {
        if (seek_end_when_skipping_data)
        {
            // the next step seeks the end of the
            // datagram to verify the checksum and make
            // sure the stream positions points to the
            // next datagram. If this is not required, we
            // can return here.
            datagram._sample_data = RAW3DataSkipped();
            return datagram;
        }

        datagram._sample_data =
            RAW3DataSkipped::from_stream(is,
                                         datagram._count,
                                         datagram.get_data_type(),
                                         datagram.get_number_of_complex_samples());
    }
    else
    {
        datagram._sample_data = datagram.read_sample_data(is);
    }

    datagram._verify_datagram_end(is);

    return datagram;
}

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

    // Write fields individually to avoid potential struct padding issues
    os.write(_channel_id.data(), 128);
    os.write(reinterpret_cast<const char*>(&_data_type), sizeof(_data_type));
    os.write(reinterpret_cast<const char*>(&_number_of_complex_samples), sizeof(_number_of_complex_samples));
    os.write(reinterpret_cast<const char*>(&_spare_1), sizeof(_spare_1));
    os.write(reinterpret_cast<const char*>(&_spare_2), sizeof(_spare_2));
    os.write(reinterpret_cast<const char*>(&_offset), sizeof(_offset));
    os.write(reinterpret_cast<const char*>(&_count), sizeof(_count));

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

// ----- functions used for PackageCache -----
RAW3 RAW3::from_stream(std::istream&                                  is,
                       const std::unordered_map<size_t, std::string>& hash_cache)
{
    RAW3 datagram(SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::RAW3));

    size_t hash;
    is.read(reinterpret_cast<char*>(&hash), sizeof(hash));

    const auto& buffer = hash_cache.at(hash);
    if (buffer.size() != 140)
        throw std::runtime_error("RAW3::from_stream: invalid cached buffer size");

    // Copy fields individually to avoid potential struct padding issues
    size_t offset = 0;
    memcpy(datagram._channel_id.data(), buffer.data() + offset, 128);
    offset += 128;
    memcpy(&datagram._data_type, buffer.data() + offset, sizeof(datagram._data_type));
    offset += sizeof(datagram._data_type);
    memcpy(&datagram._number_of_complex_samples, buffer.data() + offset, sizeof(datagram._number_of_complex_samples));
    offset += sizeof(datagram._number_of_complex_samples);
    memcpy(&datagram._spare_1, buffer.data() + offset, sizeof(datagram._spare_1));
    offset += sizeof(datagram._spare_1);
    memcpy(&datagram._spare_2, buffer.data() + offset, sizeof(datagram._spare_2));
    offset += sizeof(datagram._spare_2);
    memcpy(&datagram._offset, buffer.data() + offset, sizeof(datagram._offset));
    offset += sizeof(datagram._offset);
    memcpy(&datagram._count, buffer.data() + offset, sizeof(datagram._count));

    datagram._sample_data = raw3datatypes::RAW3DataSkipped();

    return datagram;
}

void RAW3::to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const
{
    std::string cache;
    cache.resize(140);
    
    // Copy fields individually to avoid potential struct padding issues
    size_t offset = 0;
    memcpy(cache.data() + offset, _channel_id.data(), 128);
    offset += 128;
    memcpy(cache.data() + offset, &_data_type, sizeof(_data_type));
    offset += sizeof(_data_type);
    memcpy(cache.data() + offset, &_number_of_complex_samples, sizeof(_number_of_complex_samples));
    offset += sizeof(_number_of_complex_samples);
    memcpy(cache.data() + offset, &_spare_1, sizeof(_spare_1));
    offset += sizeof(_spare_1);
    memcpy(cache.data() + offset, &_spare_2, sizeof(_spare_2));
    offset += sizeof(_spare_2);
    memcpy(cache.data() + offset, &_offset, sizeof(_offset));
    offset += sizeof(_offset);
    memcpy(cache.data() + offset, &_count, sizeof(_count));

    size_t hash = xxh::xxhash3<64>(cache);

    if (!hash_cache.contains(hash))
        hash_cache[hash] = std::move(cache);

    SimradRawDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&hash), sizeof(hash));
}

xxh::hash_t<64> RAW3::hash_content_without_samples() const
{
    // hash streaming
    xxh::hash3_state_t<64> hash_stream;

    // use all variables starting from system_serial number
    // ignore e.g. timestamp and ping_counter to be useful in the deduplicate buffer
    // Hash fields individually to avoid potential struct padding issues
    hash_stream.update(_channel_id.data(), 128);
    hash_stream.update(&_data_type, sizeof(_data_type));
    hash_stream.update(&_number_of_complex_samples, sizeof(_number_of_complex_samples));
    hash_stream.update(&_spare_1, sizeof(_spare_1));
    hash_stream.update(&_spare_2, sizeof(_spare_2));
    hash_stream.update(&_offset, sizeof(_offset));
    hash_stream.update(&_count, sizeof(_count));

    return hash_stream.digest();
}

/**
 * @brief Provide a boost hash function for XML_Parameter_Channel
 * - Note: this is needed to use XML_Parameter_Channel as boost::flyweight
 *
 * @param data
 * @return std::size_t
 */
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_pingtools_hash_value
size_t hash_value(const RAW3& data)
{
    return data.hash_content_without_samples();
}

} // namespace datagrams
} // namespace simradraw  
} // namespace echosounders
} // namespace themachinethatgoesping
