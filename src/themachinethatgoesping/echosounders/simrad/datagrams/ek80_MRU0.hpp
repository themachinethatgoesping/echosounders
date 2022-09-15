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
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../ek60_types.hpp"
#include "ek60_datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

/**
 * @brief Motion binary datagram (MRU0)
 * This datagram contains heave, roll, pitch and heading as float values.
 * Conveniently, these values can be used directly in themachinethatgoesping navigation processing
 * because they are defined in the default coordinate system / value range.
 *
 */
struct EK80_MRU0 : public EK60_Datagram
{
    // ----- datagram content -----
    ek60_float _Heave   = NAN; ///< Heave in m, positive up
    ek60_float _Roll    = NAN; ///< Roll in degrees, positive port up
    ek60_float _Pitch   = NAN; ///< Pitch in degrees, positive nose up
    ek60_float _Heading = NAN; ///< Heading in degrees, 0° north, 90° east

  private:
    // ----- public constructors -----
    explicit EK80_MRU0(EK60_Datagram header)
        : EK60_Datagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    EK80_MRU0()
        : EK60_Datagram(12 + 4 * sizeof(ek60_float),
                        ek60_long(t_EK60_DatagramType::MRU0))
    {
    }
    ~EK80_MRU0() = default;

    // ----- operators -----
    bool operator==(const EK80_MRU0& other) const
    {
        using tools::helper::approx;

        return EK60_Datagram::operator==(other) && approx(_Heave, other._Heave) &&
               approx(_Roll, other._Roll) && approx(_Pitch, other._Pitch) &&
               approx(_Heading, other._Heading);
    }
    bool operator!=(const EK80_MRU0& other) const { return !operator==(other); }

    // ----- getter setter -----
    double get_heave() const { return _Heave; }
    double get_roll() const { return _Roll; }
    double get_pitch() const { return _Pitch; }
    double get_heading() const { return _Heading; }
    void   set_heave(double value) { _Heave = value; }
    void   set_roll(double value) { _Roll = value; }
    void   set_pitch(double value) { _Pitch = value; }
    void   set_heading(double value) { _Heading = value; }

    // ----- file I/O -----
    static EK80_MRU0 from_stream(std::istream& is, EK60_Datagram header)
    {
        EK80_MRU0 datagram(std::move(header));
        is.read(reinterpret_cast<char*>(&datagram._Heave), 4 * sizeof(ek60_float));

        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);

        return datagram;
    }

    static EK80_MRU0 from_stream(std::istream& is)
    {
        return from_stream(is, EK60_Datagram::from_stream(is, t_EK60_DatagramType::MRU0));
    }

    static EK80_MRU0 from_stream(std::istream& is, t_EK60_DatagramType type)
    {
        if (type != t_EK60_DatagramType::MRU0)
            throw std::runtime_error("EK80_MRU0::from_stream: wrong datagram type");

        return from_stream(is, EK60_Datagram::from_stream(is, t_EK60_DatagramType::MRU0));
    }

    void to_stream(std::ostream& os)
    {
        _Length       = 12 + 4 * sizeof(ek60_float);
        _DatagramType = ek60_long(t_EK60_DatagramType::MRU0);
        EK60_Datagram::to_stream(os);
        os.write(reinterpret_cast<const char*>(&_Heave), 4 * sizeof(ek60_float));
        os.write(reinterpret_cast<const char*>(&_Length), sizeof(ek60_long));
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("Motion binary datagram", float_precision);

        printer.append(EK60_Datagram::__printer__(float_precision));

        printer.register_section("Motion data");
        printer.register_value("Heave", _Heave, "m");
        printer.register_value("Roll", _Roll, "°");
        printer.register_value("Pitch", _Pitch, "°");
        printer.register_value("Heading", _Heading, "°");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK80_MRU0)
};

}
}
}
}