// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../ek60_types.hpp"
#include "ek60_datagram.hpp"
#include "ek80_RAW3_datatypes/ek80_RAW3_datatypes.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

/**
 * @brief Sample binary datagram (RAW3)
 * This datagram contains the sample data for each ping. The exact datatype and size depends on the
 * Datatype field!
 *
 */
struct EK80_RAW3 : public EK60_Datagram
{
    // ----- datagram content -----
    std::string                     _ChannelID; ///< Channel identification (size is always 128)
    RAW3_datatypes::t_RAW3_DataType _Datatype =
        RAW3_datatypes::t_RAW3_DataType(0b00000000); ///< Datatype
    uint8_t _NumberOfComplexSamples =
        0; ///< Number of transducer samples per sample (used when Datatype is complex)
    ek60_char _Spare_1 = '\x00'; ///< Spare 1
    ek60_char _Spare_2 = '\x00'; ///< Spare 2
    ek60_long _Offset  = 0;      ///< First sample number in the datagram
    ek60_long _Count   = 0;      ///< Number of samples in the datagram

    // std::variant<xt::xarray<ek60_float>,
    //              xt::xarray<ek60_complex_float>> _Samples; ///< Sample data

  private:
    // ----- public constructors -----
    explicit EK80_RAW3(EK60_Datagram header)
        : EK60_Datagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    EK80_RAW3()
        : EK60_Datagram(152, ek60_long(t_EK60_DatagramType::RAW3))
    {
    }
    ~EK80_RAW3() = default;

    // ----- operators -----
    bool operator==(const EK80_RAW3& other) const
    {
        using namespace tools::helper; // approx and approx_container

        return EK60_Datagram::operator==(other) && _ChannelID == other._ChannelID &&
               _Datatype == other._Datatype &&
               _NumberOfComplexSamples == other._NumberOfComplexSamples &&
               _Spare_1 == other._Spare_1 && _Spare_2 == other._Spare_2 &&
               _Offset == other._Offset && _Count == other._Count;
    }
    bool operator!=(const EK80_RAW3& other) const { return !operator==(other); }

    // ----- getter setter -----
    const std::string& get_channel_id() const { return _ChannelID; }
    void               set_channel_id(const std::string& channel_id) { _ChannelID = channel_id; }
    RAW3_datatypes::t_RAW3_DataType get_data_type() const
    {
        // set short to 0 except for the last 4 bits
        return _Datatype;
    }
    void set_data_type(RAW3_datatypes::t_RAW3_DataType data_type) { _Datatype = data_type; }

    /**
     * @brief Get the number of complex samples.
     * This corresponds to the number of transducer elements.
     * This field is only valid for complex data types.
     *
     * @return ek60_short
     */
    uint8_t get_number_of_complex_samples() const
    {
        // complex data types set at least bit 3
        if (uint8_t(_Datatype) < 4)
            return 1;
            
        // the number of samples is written in _Datatype bits 8-10
        return _NumberOfComplexSamples;
    }
    void set_number_of_complex_samples(uint8_t number_of_complex_samples)
    {
        _NumberOfComplexSamples = number_of_complex_samples;
    }

    ek60_char get_spare_1() const { return _Spare_1; }
    ek60_char get_spare_2() const { return _Spare_2; }
    ek60_long get_offset() const { return _Offset; }
    void      set_offset(ek60_long offset) { _Offset = offset; }
    ek60_long get_count() const { return _Count; }
    void      set_count(ek60_long count) { _Count = count; }

    // ----- file I/O -----
    static EK80_RAW3 from_stream(std::istream& is, EK60_Datagram header, bool skip = true)
    {
        auto      pos = is.tellg();
        EK80_RAW3 datagram(std::move(header));
        datagram._ChannelID.resize(128);

        is.read(datagram._ChannelID.data(), datagram._ChannelID.size());
        is.read(reinterpret_cast<char*>(&datagram._Datatype), sizeof(datagram._Datatype));
        is.read(reinterpret_cast<char*>(&datagram._NumberOfComplexSamples),
                sizeof(datagram._NumberOfComplexSamples));
        is.read(reinterpret_cast<char*>(&datagram._Spare_1), sizeof(datagram._Spare_1));
        is.read(reinterpret_cast<char*>(&datagram._Spare_2), sizeof(datagram._Spare_2));
        is.read(reinterpret_cast<char*>(&datagram._Offset), sizeof(datagram._Offset));
        is.read(reinterpret_cast<char*>(&datagram._Count), sizeof(datagram._Count));

        if (!skip)
            return datagram;

        (void)RAW3_datatypes::RAW3_DataSkipped::from_stream(
            is,
            datagram._Count,
            datagram.get_data_type(),
            datagram.get_number_of_complex_samples());

        return datagram;
    }

    static EK80_RAW3 from_stream(std::istream& is)
    {
        return from_stream(is, EK60_Datagram::from_stream(is, t_EK60_DatagramType::RAW3));
    }

    static EK80_RAW3 from_stream(std::istream& is, t_EK60_DatagramType type)
    {
        if (type != t_EK60_DatagramType::RAW3)
            throw std::runtime_error("EK80_RAW3::from_stream: wrong datagram type");

        return from_stream(is, EK60_Datagram::from_stream(is, t_EK60_DatagramType::RAW3));
    }

    void to_stream(std::ostream& os, bool skip = true)
    {
        //_Count = _Samples.size();
        auto data_type_size = RAW3_DataType_size(_Datatype);

        // TODO: support 16 bit complex data
        _Length = _Count * data_type_size * get_number_of_complex_samples() + 152;

        _DatagramType = ek60_long(t_EK60_DatagramType::RAW3);
        _ChannelID.resize(128, '\x00');

        EK60_Datagram::to_stream(os);

        os.write(_ChannelID.data(), _ChannelID.size());
        os.write(reinterpret_cast<char*>(&_Datatype), sizeof(_Datatype));
        os.write(reinterpret_cast<char*>(&_NumberOfComplexSamples),
                 sizeof(_NumberOfComplexSamples));
        os.write(reinterpret_cast<char*>(&_Spare_1), sizeof(_Spare_1));
        os.write(reinterpret_cast<char*>(&_Spare_2), sizeof(_Spare_2));
        os.write(reinterpret_cast<char*>(&_Offset), sizeof(_Offset));
        os.write(reinterpret_cast<char*>(&_Count), sizeof(_Count));

        if (!skip)
            return;

        RAW3_datatypes::RAW3_DataSkipped skipped;
        skipped.to_stream(os, _Count, get_data_type(), get_number_of_complex_samples());

        os.write(reinterpret_cast<const char*>(&_Length), sizeof(ek60_long));
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("Sample binary datagram (only header)",
                                                   float_precision);

        printer.append(EK60_Datagram::__printer__(float_precision));

        std::string channel_id = _ChannelID;
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
        datatype_as_bytes << "0b" << std::bitset<8>(uint8_t(_Datatype));

        std::stringstream csamples_as_bytes;
        csamples_as_bytes << "0b" << std::bitset<8>(_NumberOfComplexSamples);

        printer.register_section("Sample datagram header");
        printer.register_string("ChannelID", channel_id);
        printer.register_string("Datatype (bytes)", datatype_as_bytes.str());
        printer.register_enum("Datatype", _Datatype);
        printer.register_value("Complex samples (bytes)", csamples_as_bytes.str());
        printer.register_value("Complex samples", _NumberOfComplexSamples);
        printer.register_value("Spare_1", _Spare_1);
        printer.register_value("Spare_2", _Spare_2);
        printer.register_value("_Offset", _Offset);
        printer.register_value("_Count", _Count);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK80_RAW3)
};

}
}
}
}