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

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

enum class t_DataType : ek60_short
{
    Power = 0b00000001,
    Angle = 0b00000010,
–   ComplexFloat16 = 0b00000100,
–   ComplexFloat32 = 0b00001000,
}

/**
 * @brief Sample binary datagram (RAW3)
 * This datagram contains the sample data for each ping. The exact datatype and size depends on the Datatype field!
 *
 */
struct EK80_RAW3 : public EK60_Datagram
{
    // ----- datagram content -----
    std::string _ChannelID;             ///< Channel identification (size is always 128)
    ek60_short  _Datatype = 0b00000000; ///< Filter stage number
    ek60_char   _Spare_1  = '\x00';     ///< Spare 1
    ek60_char   _Spare_2  = '\x00';     ///< Spare 2
    ek60_long   _Offset   = 0;          ///< First sample number in the datagram
    ek60_long   _Count    = 0;          ///< Number of samples in the datagram

    std::variant<xt::xtensor<ek60_float>,
                 xt::xtensor<ek60_complex_float>> _Samples; ///< Sample data

  private:
    // ----- public constructors -----
    explicit EK80_RAW3(EK60_Datagram header)
        : EK60_Datagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    EK80_RAW3()
        : EK60_Datagram(140, ek60_long(t_EK60_DatagramType::RAW3))
    {
    }
    ~EK80_RAW3() = default;

    // ----- operators -----
    bool operator==(const EK80_RAW3& other) const
    {
        using namespace tools::helper; // approx and approx_container

        return EK60_Datagram::operator==(other) && _ChannelID == other._ChannelID &&
               _Datatype == other._Datatype && _Spare_1 == other._Spare_1 &&
               _Spare_2 == other._Spare_2 && _Offset == other._Offset && _Count == other._Count &&
               approx_container(xt::flatten(_Samples), xt::flatten(other._Samples.flat));
    }
    bool operator!=(const EK80_RAW3& other) const { return !operator==(other); }

    // ----- getter setter -----
    const std::string& get_channel_id() const { return _ChannelID; }
    void               set_channel_id(const std::string& channel_id) { _ChannelID = channel_id; }
    t_DataType         get_data_type() const
    {
        // set short to 0 except for the last 4 bits
        return _Datatype & 0b00001111;
    }
    /**
     * @brief Get the number of complex samples.
     * This corresponds to the number of transducer elements.
     * This field is only valid for complex data types.
     *
     * @return ek60_short
     */
    ek60_short get_number_of_complex_samples() const
    {
        // the number of samples is written in _Datatype bits 8-10
        return (_Datatype >> 8);
    }

    ek60_char   get_spare_1() const { return _Spare_1; }
    ek60_char   get_spare_2() const { return _Spare_2; }
    ek60_long   get_offset() const { return _Offset; }
    ek60_long   get_count() const { return _Count; }
    const auto& get_samples() const { return _Samples; }

    // ----- file I/O -----
    static EK80_RAW3 from_stream(std::istream& is, EK60_Datagram header)
    {
        EK80_RAW3 datagram(std::move(header));
        datagram._ChannelID.resize(128);

        is.read(datagram._ChannelID.data(), datagram._ChannelID.size());
        is.read(reinterpret_cast<char*>(&datagram._Datatype), sizeof(datagram._Datatype));
        is.read(reinterpret_cast<char*>(&datagram._Spare_1), sizeof(datagram._Spare_1));
        is.read(reinterpret_cast<char*>(&datagram._Spare_2), sizeof(datagram._Spare_2));
        is.read(reinterpret_cast<char*>(&datagram._Offset), sizeof(datagram._Offset));
        is.read(reinterpret_cast<char*>(&datagram._Count), sizeof(datagram._Count));

        auto number_of_transducers = get_number_of_transducers();

        switch (get_data_type())
        {
            case t_DataType::Power:
                datagram._Samples =
                    xt::adapt(reinterpret_cast<ek60_float*>(is.tellg()), datagram._Count);
                break;
            case t_DataType::Angle:
                datagram._Samples =
                    xt::adapt(reinterpret_cast<ek60_float*>(is.tellg()), datagram._Count);
                break;
            case t_DataType::ComplexFloat32:
                datagram._Samples = xt::adapt(reinterpret_cast<ek60_complex_float*>(is.tellg()),
                                              datagram._Count * number_of_transducers);
                datagram._Samples.reshape({ datagram._Count, number_of_transducers });
                break case t_DataType::ComplexFloat16
                    : throw std::runtime_error("Datatype ComplexFloat16 is not yet supported");
                break;
            default:
                throw std::runtime_error("Unknown data type");
        }

        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);

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

    void to_stream(std::ostream& os)
    {
        _Count                  = _Samples.size();
        auto dtype              = get_data_type();
        auto samples_per_sample = 1 if (dtype == t_DataType::ComplexFloat32) samples_per_sample =
            get_number_of_complex_samples();

        // TODO: support 16 bit complex data
        _Length = _Count * sizeof(ek60_complex_float) * samples_per_sample + 140;

        _DatagramType = ek60_long(t_EK60_DatagramType::RAW3);
        _ChannelID.resize(128, '\x00');

        EK60_Datagram::to_stream(os);

        os.write(_ChannelID.data(), _ChannelID.size());
        os.write(reinterpret_cast<char*>(&_Datatype), sizeof(_Datatype));
        os.write(reinterpret_cast<char*>(&_Spare_1), sizeof(_Spare_1));
        os.write(reinterpret_cast<char*>(&_Spare_2), sizeof(_Spare_2));
        os.write(reinterpret_cast<char*>(&_Offset), sizeof(_Offset));
        os.write(reinterpret_cast<char*>(&_Count), sizeof(_Count));

        switch (dtype)
        {
            case t_DataType::Power:
                os.write(reinterpret_cast<char*>(_Coefficients.data()), _Coefficients.size());
                os.write(reinterpret_cast<char*>(_Samples.data()), _Samples.size());
                break;
            case t_DataType::Angle:
                os.write(reinterpret_cast<char*>(_Samples.data()), _Samples.size());
                break;
            case t_DataType::ComplexFloat32:
                os.write(reinterpret_cast<char*>(_Samples.data()), _Samples.size());
                break;
            case t_DataType::ComplexFloat16:
                throw std::runtime_error("Datatype ComplexFloat16 is not yet supported");
                break;
            default:
                throw std::runtime_error("Unknown data type");
        }
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("Filter binary datagram (RAW3)",
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

        printer.register_section("Filter datagram content");
        printer.register_value("Stage", _Stage);
        printer.register_value("Spare_1", _Spare_1);
        printer.register_value("Spare_2", _Spare_2);
        printer.register_string("ChannelID", channel_id);
        printer.register_value("NoOfCoefficients", _NoOfCoefficients);
        printer.register_value("DecimationFactor", _DecimationFactor);

        printer.register_section("Filter coefficients");
        // printer.register_container("Coefficients", _Coefficients);

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