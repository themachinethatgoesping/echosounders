// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>
#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include "../ek60_types.hpp"
#include "ek60_datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

/**
 * @brief NMEA text datagram (NME0)
 * This datagram contains NMEA sentences received by the EK60/EK80 transceiver.
 *
 */
struct EK60_NME0 : public EK60_Datagram
{
    // ----- datagram content -----
    navigation::nmea_0183::NMEA_Base _nmea_base;

  private:
    // ----- public constructors -----
    explicit EK60_NME0(EK60_Datagram header)
        : EK60_Datagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    EK60_NME0()
    {
        _DatagramType = ek60_long(t_EK60_DatagramType::NME0);
    }
    ~EK60_NME0() = default;

    // ----- operators -----
    bool operator==(const EK60_NME0& other) const
    {
        return EK60_Datagram::operator==(other) && _nmea_base == other._nmea_base;
    }
    bool operator!=(const EK60_NME0& other) const { return !operator==(other); }

    // ----- getter setter -----
    std::string get_sender_id() const { return std::string(_nmea_base.get_sender_id()); }
    std::string get_sentence_type() const { return std::string(_nmea_base.get_sentence_type()); }
    std::string get_sentence_id() const { return std::string(_nmea_base.get_sentence_id()); }
    std::string get_sentence() const { return std::string(_nmea_base.get_sentence()); }
    std::string get_field(size_t index) const { return std::string(_nmea_base.get_field(index)); }
    double get_field_as_double(size_t index) const { return _nmea_base.get_field_as_double(index); }
    int get_field_as_int(size_t index) const { return _nmea_base.get_field_as_int(index); }
    void parse_fields() { _nmea_base.parse_fields(); }
    //navigation::nmea_0183::NMEA_Base decode() const { return _nmea_base; }
    navigation::nmea_0183::NMEA_0183_type decode() const { return navigation::nmea_0183::decode(_nmea_base); }

    // ----- file I/O -----
    static EK60_NME0 from_stream(std::istream& is, EK60_Datagram header)
    {
        EK60_NME0 datagram(std::move(header));
        datagram._nmea_base = navigation::nmea_0183::NMEA_Base::from_stream(is, datagram._Length-12);
        
        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);
        
        return datagram;
    }

    static EK60_NME0 from_stream(std::istream& is)
    {
        return from_stream(is,EK60_Datagram::from_stream(is, t_EK60_DatagramType::NME0));
    }

    static EK60_NME0 from_stream(std::istream& is, t_EK60_DatagramType type)
    {
        if (type != t_EK60_DatagramType::NME0)
            throw std::runtime_error("EK60_NME0::from_stream: wrong datagram type");

        return from_stream(is,EK60_Datagram::from_stream(is, t_EK60_DatagramType::NME0));
    }

    void to_stream(std::ostream& os)
    {
        _Length       = 12 + _nmea_base.size();
        _DatagramType = ek60_long(t_EK60_DatagramType::NME0);
        EK60_Datagram::to_stream(os);
        _nmea_base.to_stream_dont_write_size(os);
        os.write(reinterpret_cast<const char*>(&_Length), sizeof(ek60_float));
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("NMEA text datagram", float_precision);

        printer.append(EK60_Datagram::__printer__(float_precision));

        printer.register_section("Nmea sentence");
        printer.register_value("Sender", get_sender_id(), "");
        printer.register_value("Type", get_sentence_type(), "");
        printer.register_value("Full sentence", get_sentence(), "");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK60_NME0)
};

}
}
}
}