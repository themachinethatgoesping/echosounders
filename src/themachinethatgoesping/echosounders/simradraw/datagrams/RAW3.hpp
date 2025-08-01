// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/RAW3.doc.hpp"

// std includes
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>

#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper/variant.hpp>

#include "../types.hpp"
#include "raw3datatypes/raw3datatypes.hpp"
#include "simradrawdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

/**
 * @brief Sample binary datagram (RAW3)
 * This datagram contains the sample data for each ping. The exact datatype and size depends on the
 * data_type field!
 *
 */
class RAW3 : public SimradRawDatagram
{
    // ----- datagram content -----
    std::array<char, 128>         _channel_id; ///< Channel identification (size is always 128)
    raw3datatypes::t_RAW3DataType _data_type;  ///< data_type
    uint8_t _number_of_complex_samples; ///< Number of transducer samples per sample (used when
                                        ///< data_type is complex)
    simradraw_char _spare_1;            ///< Spare 1
    simradraw_char _spare_2;            ///< Spare 2
    simradraw_long _offset;             ///< First sample number in the datagram
    simradraw_long _count;              ///< Number of samples in the datagram

    raw3datatypes::RAW3DataVariant _sample_data; ///< Sample data

    // std::variant<xt::xtensor<simradraw_float>,
    //              xt::xtensor<simradraw_complex_float,2>> _Samples; ///< Sample data

  private:
    // ----- public constructors -----
    explicit RAW3(SimradRawDatagram header)
        : SimradRawDatagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    RAW3()
        : SimradRawDatagram(152, simradraw_long(t_SimradRawDatagramIdentifier::RAW3))
        , _channel_id()
        , _data_type(raw3datatypes::t_RAW3DataType(0b00000000))
        , _number_of_complex_samples(0)
        , _spare_1('\x00')
        , _spare_2('\x00')
        , _offset(0)
        , _count(0)
        , _sample_data()
    {
        _channel_id.fill('\x00');
    }
    ~RAW3() = default;

    // ----- operators -----
    bool operator==(const RAW3& other) const = default;

    // ----- getter setter -----
    std::string_view get_channel_id() const { return std::string_view(_channel_id.data(), 128); }
    std::string_view get_channel_id_stripped() const
    {
        auto channel_id = get_channel_id();
        return channel_id.substr(0, channel_id.find('\x00'));
    }
    void set_channel_id(std::string_view channel_id)
    {
        if (channel_id.size() > 128)
            throw std::runtime_error("channel_id too long");

        std::copy(channel_id.begin(), channel_id.end(), _channel_id.begin());
        // fill _channel_id with \x00
        std::fill(_channel_id.begin() + channel_id.size(), _channel_id.end(), '\x00');
    }
    raw3datatypes::t_RAW3DataType get_data_type() const
    {
        // set int16_t to 0 except for the last 4 bits
        return _data_type;
    }
    void set_data_type(raw3datatypes::t_RAW3DataType data_type)
    {
        _data_type = std::move(data_type);
    }

    /**
     * @brief Get the number of complex samples.
     * This corresponds to the number of transducer elements.
     * This field is only valid for complex data types.
     *
     * @return simradraw_short
     */
    uint8_t get_number_of_complex_samples() const
    {
        // complex data types set at least bit 3
        if (uint8_t(_data_type) < 4)
            return 1;

        // the number of samples is written in _data_type bits 8-10
        return _number_of_complex_samples;
    }
    void set_number_of_complex_samples(uint8_t number_of_complex_samples)
    {
        _number_of_complex_samples = std::move(number_of_complex_samples);
    }

    simradraw_char get_spare_1() const { return _spare_1; }
    void           set_spare_1(simradraw_char spare_1) { _spare_1 = std::move(spare_1); }
    simradraw_char get_spare_2() const { return _spare_2; }
    void           set_spare_2(simradraw_char spare_2) { _spare_2 = std::move(spare_2); }
    simradraw_long get_offset() const { return _offset; }
    void           set_offset(simradraw_long offset) { _offset = std::move(offset); }
    simradraw_long get_count() const { return _count; }
    void           set_count(simradraw_long count) { _count = std::move(count); }

    /**
     * @brief Get the sample data.
     * The sample data is stored in a variant of xtensor containers.
     * The exact type depends on the data type.
     *
     * @return raw3datatypes::RAW3DataVariant
     */
    raw3datatypes::RAW3DataVariant& sample_data() { return _sample_data; }

    /**
     * @brief Get the sample data. (const overload)
     * The sample data is stored in a variant of xtensor containers.
     * The exact type depends on the data type.
     *
     * @return raw3datatypes::RAW3DataVariant
     */
    const raw3datatypes::RAW3DataVariant& sample_data() const { return _sample_data; }

    /**
     * @brief Get the sample data.
     * The sample data is stored in a variant of xtensor containers.
     * The exact type depends on the data type.
     *
     * @return raw3datatypes::RAW3DataVariant
     */
    const raw3datatypes::RAW3DataVariant& get_sample_data() const { return _sample_data; }
    void set_sample_data(raw3datatypes::RAW3DataVariant sample_data) { _sample_data = sample_data; }

    // ----- file I/O -----
    raw3datatypes::RAW3DataVariant read_skipped_sample_data(std::istream& is,
                                                            size_t        header_pos) const
    {
        is.seekg(header_pos + size_t(156)); // size of the header(4xint32_t) + 140 bytes channel_id
        return read_sample_data(is);
    }

    raw3datatypes::RAW3DataVariant read_sample_data(std::istream& is) const
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

    static RAW3 from_stream(std::istream&     is,
                            SimradRawDatagram header,
                            bool              skip_sample_data            = false,
                            bool              seek_end_when_skipping_data = true)
    {
        using namespace raw3datatypes;

        RAW3 datagram(std::move(header));
        is.read(datagram._channel_id.data(), 140);

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

    static RAW3 from_stream(std::istream& is,
                            bool          skip_sample_data            = false,
                            bool          seek_end_when_skipping_data = true)
    {
        return from_stream(is,
                           SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::RAW3),
                           skip_sample_data,
                           seek_end_when_skipping_data);
    }

    static RAW3 from_stream(std::istream&                 is,
                            t_SimradRawDatagramIdentifier type,
                            bool                          skip_sample_data            = false,
                            bool                          seek_end_when_skipping_data = true)
    {
        if (type != t_SimradRawDatagramIdentifier::RAW3)
            throw std::runtime_error("RAW3::from_stream: wrong datagram type");

        return from_stream(is,
                           SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::RAW3),
                           skip_sample_data,
                           seek_end_when_skipping_data);
    }

    void to_stream(std::ostream& os)
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
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "Sample binary datagram", float_precision, superscript_exponents);

        printer.append(SimradRawDatagram::__printer__(float_precision, superscript_exponents));

        std::string channel_id = std::string(get_channel_id());
        // remove all non ascii characters
        channel_id.erase(std::remove_if(channel_id.begin(),
                                        channel_id.end(),
                                        [](char c) { return !std::isprint(c); }),
                         channel_id.end());
        // remove all white spaces
        channel_id.erase(std::remove_if(channel_id.begin(),
                                        channel_id.end(),
                                        [](char c) { return std::isspace(c); }),
                         channel_id.end());

        std::stringstream datatype_as_bytes;
        datatype_as_bytes << "0b" << std::bitset<8>(uint8_t(_data_type));

        std::stringstream csamples_as_bytes;
        csamples_as_bytes << "0b" << std::bitset<8>(_number_of_complex_samples);

        printer.register_section("Sample datagram header");
        printer.register_string("channel_id", channel_id);
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
    static RAW3 from_stream(std::istream&                                  is,
                            const std::unordered_map<size_t, std::string>& hash_cache)
    {
        RAW3 datagram(SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::RAW3));

        size_t hash;
        is.read(reinterpret_cast<char*>(&hash), sizeof(hash));

        const auto& buffer = hash_cache.at(hash);
        if (buffer.size() != 140)
            throw std::runtime_error("RAW3::from_stream: invalid cached buffer size");

        memcpy(datagram._channel_id.data(), buffer.data(), 140);

        datagram._sample_data = raw3datatypes::RAW3DataSkipped();

        return datagram;
    }

    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const
    {
        std::string cache;
        cache.resize(140);
        memcpy(cache.data(), _channel_id.data(), 140);

        size_t hash = xxh::xxhash3<64>(cache);

        if (!hash_cache.contains(hash))
            hash_cache[hash] = std::move(cache);

        SimradRawDatagram::to_stream(os);
        os.write(reinterpret_cast<const char*>(&hash), sizeof(hash));
    }

    xxh::hash_t<64> hash_content_without_samples() const
    {
        // hash streaming
        xxh::hash3_state_t<64> hash_stream;

        // use all variables starting from system_serial number
        // ignore e.g. timestamp and ping_counter to be useful in the deduplicate buffer
        hash_stream.update(_channel_id.data(), 140);

        return hash_stream.digest();
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(RAW3)
};

/**
 * @brief Provide a boost hash function for XML_Parameter_Channel
 * - Note: this is needed to use XML_Parameter_Channel as boost::flyweight
 *
 * @param data
 * @return std::size_t
 */
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_pingtools_hash_value
inline size_t hash_value(const RAW3& data)
{
    return data.hash_content_without_samples();
}

}
}
}
}