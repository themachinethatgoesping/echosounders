// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/extraparameters.doc.hpp"

// std includes
#include <iosfwd>
#include <string>
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/option.hpp>

#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

class ExtraParameters : public KongsbergAllDatagram
{
    public:
        static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::ExtraParameters;

        enum class t_ContentIdentifier : uint16_t
        {
                CalibTxt                  = 1, ///< Calib.txt file for angle offset
                LogAllHeights             = 2, ///< Log of all heights
                SoundVelocityAtTransducer = 3, ///< Sound velocity at transducer
                SoundVelocityProfile      = 4, ///< Sound velocity profile
                MultiCastInputStatus      = 5, ///< Multicast input status
                Bscorr                    = 6, ///< Bscorr.txt file
        };

        using o_ContentIdentifier = tools::classhelper::Option<t_ContentIdentifier>;

    protected:
        uint16_t            _ping_counter;
        uint16_t            _system_serial_number;
        t_ContentIdentifier _content_identifier;
        std::string         _raw_content; ///< depends on the content identifier

        uint8_t _spare;

        uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
        uint16_t _checksum;

    private:
        explicit ExtraParameters(KongsbergAllDatagram header);

    public:
        ExtraParameters();
        ~ExtraParameters() = default;

        uint16_t            get_ping_counter() const;
        uint16_t            get_system_serial_number() const;
        t_ContentIdentifier get_content_identifier() const;
        std::string         get_raw_content() const;
        uint8_t             get_spare() const;
        uint8_t             get_etx() const;
        uint16_t            get_checksum() const;

        void set_ping_counter(uint16_t ping_counter);
        void set_system_serial_number(uint16_t system_serial_number);
        void set_content_identifier(t_ContentIdentifier content_identifier);
        void set_raw_content(std::string raw_content);
        void set_spare(uint8_t spare);
        void set_checksum(uint16_t checksum);
        void set_etx(uint8_t etx);

        bool operator==(const ExtraParameters& other) const = default;

        static ExtraParameters from_stream(std::istream& is, KongsbergAllDatagram header);
        static ExtraParameters from_stream(std::istream& is);
        static ExtraParameters from_stream(std::istream&                    is,
                                                                             t_KongsbergAllDatagramIdentifier datagram_identifier);

        void to_stream(std::ostream& os);

        tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                                                                    bool         superscript_exponents) const;

        __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
        __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(ExtraParameters)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping

extern template class themachinethatgoesping::tools::classhelper::Option<
    themachinethatgoesping::echosounders::kongsbergall::datagrams::ExtraParameters::
        t_ContentIdentifier>;
