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

#include <boost/algorithm/string.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../ek60_types.hpp"
#include "ek60_datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

/**
 * @brief Filter binary datagram (FIL1)
 * This datagram contains filter coefficients used by the EK80 to filter the received signal.
 *
 */
struct EK80_FIL1 : public EK60_Datagram
{
    // ----- datagram content -----
    ek60_short  _Stage   = '\x00';     ///< Filter stage number
    ek60_char   _Spare_1 = '\x00';     ///< For future expansions
    ek60_char   _Spare_2 = '\x00';     ///< For future expansions
    std::string _ChannelID;            ///< Channel identification (size is always 128)
    ek60_short  _NoOfCoefficients = 0; ///< Number of complex filter coefficients
    ek60_short  _DecimationFactor = -1; ///< Filter decimation factor

    std::vector<ek60_float> _Coefficients; ///< Filter coefficients (real, imag, real, imag, ...)
                                           ///< size = _NoOfCoefficients * 2

  private:
    // ----- public constructors -----
    explicit EK80_FIL1(EK60_Datagram header)
        : EK60_Datagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    EK80_FIL1()
        : EK60_Datagram(148, ek60_long(t_EK60_DatagramType::FIL1))
    {
    }
    ~EK80_FIL1() = default;

    // ----- operators -----
    bool operator==(const EK80_FIL1& other) const
    {
        using namespace tools::helper; //approx and approx_container

        return EK60_Datagram::operator==(other) && _Stage == other._Stage &&
               _Spare_1 == other._Spare_1 && _Spare_2 == other._Spare_2 &&
               _ChannelID == other._ChannelID && _NoOfCoefficients == other._NoOfCoefficients &&
               _DecimationFactor, other._DecimationFactor &&
               approx_container(_Coefficients, other._Coefficients);
    }
    bool operator!=(const EK80_FIL1& other) const { return !operator==(other); }

    // ----- getter setter -----
    ek60_short              get_stage() const { return _Stage; }
    ek60_char               get_spare_1() const { return _Spare_1; }
    ek60_char               get_spare_2() const { return _Spare_2; }
    std::string             get_channel_id() const { return _ChannelID; }
    ek60_short              get_no_of_coefficients() const { return _NoOfCoefficients; }
    ek60_short              get_decimation_factor() const { return _DecimationFactor; }
    std::vector<ek60_float> get_coefficients() const { return _Coefficients; }

    void set_stage(ek60_short stage) { _Stage = stage; }
    void set_spare_1(ek60_char spare_1) { _Spare_1 = spare_1; }
    void set_spare_2(ek60_char spare_2) { _Spare_2 = spare_2; }
    void set_channel_id(std::string channel_id) { _ChannelID = channel_id; }
    void set_no_of_coefficients(ek60_short no_of_coefficients)
    {
        _NoOfCoefficients = no_of_coefficients;
    }
    void set_decimation_factor(ek60_short decimation_factor)
    {
        _DecimationFactor = decimation_factor;
    }
    void set_coefficients(std::vector<ek60_float> coefficients)
    {
        _Coefficients = std::move(coefficients);
    }

    // ----- file I/O -----
    static EK80_FIL1 from_stream(std::istream& is, EK60_Datagram header)
    {
        EK80_FIL1 datagram(std::move(header));
        datagram._ChannelID.resize(128);

        is.read(reinterpret_cast<char*>(&datagram._Stage), sizeof(datagram._Stage));
        is.read(reinterpret_cast<char*>(&datagram._Spare_1), sizeof(datagram._Spare_1));
        is.read(reinterpret_cast<char*>(&datagram._Spare_2), sizeof(datagram._Spare_2));
        is.read(datagram._ChannelID.data(), datagram._ChannelID.size());
        is.read(reinterpret_cast<char*>(&datagram._NoOfCoefficients), sizeof(datagram._NoOfCoefficients));
        is.read(reinterpret_cast<char*>(&datagram._DecimationFactor), sizeof(datagram._DecimationFactor));
        
        int size = datagram._NoOfCoefficients * 2 * sizeof(ek60_float);
        if (size + 148 != datagram._Length)
            throw std::runtime_error(
                fmt::format("EK80_FIL1: size mismatch (NoOfCoefficients {}/{} vs datagram Length {})",datagram._NoOfCoefficients,size, datagram._Length));
            
        datagram._Coefficients.resize(datagram._NoOfCoefficients * 2);
        is.read(reinterpret_cast<char*>(datagram._Coefficients.data()), size);

        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);

        return datagram;
    }

    static EK80_FIL1 from_stream(std::istream& is)
    {
        return from_stream(is, EK60_Datagram::from_stream(is, t_EK60_DatagramType::FIL1));
    }

    static EK80_FIL1 from_stream(std::istream& is, t_EK60_DatagramType type)
    {
        if (type != t_EK60_DatagramType::FIL1)
            throw std::runtime_error("EK80_FIL1::from_stream: wrong datagram type");

        return from_stream(is, EK60_Datagram::from_stream(is, t_EK60_DatagramType::FIL1));
    }

    void to_stream(std::ostream& os)
    {
        _NoOfCoefficients = _Coefficients.size() / 2;

        _Length       = _Coefficients.size() * sizeof(ek60_float) + 148;
        _DatagramType = ek60_long(t_EK60_DatagramType::FIL1);
        _ChannelID.resize(128,'\x00');

        EK60_Datagram::to_stream(os);
        
        os.write(reinterpret_cast<char*>(&_Stage), sizeof(_Stage));
        os.write(reinterpret_cast<char*>(&_Spare_1), sizeof(_Spare_1));
        os.write(reinterpret_cast<char*>(&_Spare_2), sizeof(_Spare_2));
        os.write(_ChannelID.data(), _ChannelID.size());
        os.write(reinterpret_cast<char*>(&_NoOfCoefficients), sizeof(_NoOfCoefficients));
        os.write(reinterpret_cast<char*>(&_DecimationFactor), sizeof(_DecimationFactor));
        os.write(reinterpret_cast<char*>(_Coefficients.data()), _Coefficients.size() * sizeof(ek60_float));
        os.write(reinterpret_cast<char*>(&_Length), sizeof(_Length));
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("Filter binary datagram (FIL1)", float_precision);

        printer.append(EK60_Datagram::__printer__(float_precision));

        std::string channel_id = _ChannelID;
        //remove all non ascii characters
        channel_id.erase(std::remove_if(channel_id.begin(), channel_id.end(), [](char c) { return !std::isprint(c); }), channel_id.end());
        //remove all white spaces
        channel_id.erase(std::remove_if(channel_id.begin(), channel_id.end(), [](char c) { return std::isspace(c); }), channel_id.end());

        printer.register_section("Filter datagram content");
        printer.register_value("Stage", _Stage);
        printer.register_value("Spare_1", _Spare_1);
        printer.register_value("Spare_2", _Spare_2);
        printer.register_string("ChannelID", channel_id);
        printer.register_value("NoOfCoefficients", _NoOfCoefficients);
        printer.register_value("DecimationFactor", _DecimationFactor);

        printer.register_section("Filter coefficients");
        printer.register_container("Coefficients", _Coefficients);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK80_FIL1)
};

}
}
}
}