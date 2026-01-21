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

// xtensor includes
#include <xtensor/containers/xadapt.hpp>
#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

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
        , _channel_id()
        , _data_type(raw3datatypes::t_RAW3DataType(0))
        , _number_of_complex_samples(0)
        , _spare_1('\x00')
        , _spare_2('\x00')
        , _offset(0)
        , _count(0)
        , _sample_data()
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
    std::string_view get_channel_id_stripped() const;
    void set_channel_id(std::string_view channel_id);
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
    uint8_t get_number_of_complex_samples() const;
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
                                                            size_t        header_pos) const;

    raw3datatypes::RAW3DataVariant read_sample_data(std::istream& is) const;

    static RAW3 from_stream(std::istream&     is,
                            SimradRawDatagram header,
                            bool              skip_sample_data            = false,
                            bool              seek_end_when_skipping_data = true);

    static RAW3 from_stream(std::istream& is,
                            bool          skip_sample_data            = false,
                            bool          seek_end_when_skipping_data = true);

    static RAW3 from_stream(std::istream&                 is,
                            t_SimradRawDatagramIdentifier type,
                            bool                          skip_sample_data            = false,
                            bool                          seek_end_when_skipping_data = true);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- functions used for PackageCache -----
    static RAW3 from_stream(std::istream&                                  is,
                           const std::unordered_map<size_t, std::string>& hash_cache);

    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const;

    xxh::hash_t<64> hash_content_without_samples() const;

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
size_t hash_value(const RAW3& data);

}
}
}
}