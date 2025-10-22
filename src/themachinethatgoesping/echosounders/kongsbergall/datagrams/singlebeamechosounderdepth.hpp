// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/singlebeamechosounderdepth.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief Single beam echo sounder depth datagram
 */
class SingleBeamEchoSounderDepth : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier =
        t_KongsbergAllDatagramIdentifier::SingleBeamEchoSounderDepth;

  protected:
    uint16_t _echo_sounder_counter; ///< Sequential Number
    uint16_t _system_serial_number;
    uint32_t _input_date; ///< year*10000 + month*100 + day (from input datagram if available)
    uint32_t _input_time_since_midnight; ///< time since midnight in milliseconds (from input
                                         ///< datagram if available)
    uint32_t _echo_sounder_depth;        ///< from waterline in cm
    char     _source_identifier;         ///< 'S', 'T', '1', '2' or '3'

    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit SingleBeamEchoSounderDepth(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    SingleBeamEchoSounderDepth();
    ~SingleBeamEchoSounderDepth() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_echo_sounder_counter() const;
    uint16_t get_system_serial_number() const;
    uint32_t get_input_date() const;
    uint32_t get_input_time_since_midnight() const;
    uint32_t get_echo_sounder_depth() const;
    char     get_source_identifier() const;
    uint8_t  get_etx() const;
    uint16_t get_checksum() const;

    // setters
    void set_echo_sounder_counter(uint16_t echo_sounder_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_input_date(uint32_t date);
    void set_input_time_since_midnight(uint32_t time);
    void set_echo_sounder_depth(uint32_t echo_sounder_depth);
    void set_source_identifier(char source_identifier);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // ----- processed data access -----
    /**
     * @brief convert the date and time_since_midnight field to a unix timestamp
     *
     * @return unixtime as double
     */
    double get_input_timestamp() const;

    /**
     * @brief Get the time as string
     *
     * @param fractionalSecondsDigits
     * @param format
     * @return std::string
     */
    std::string get_input_date_string(unsigned int       fractionalSecondsDigits = 2,
                                      const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const;

    /**
     * @brief Get the echo sounder depth in meters
     *
     * @return _echo_sounder_depth * 0.01f (float)
     */
    float get_echo_sounder_depth_in_meters() const;

    // ----- operators -----
    bool operator==(const SingleBeamEchoSounderDepth& other) const = default;

    //----- to/from stream functions -----
    static SingleBeamEchoSounderDepth from_stream(std::istream& is, KongsbergAllDatagram header);

    static SingleBeamEchoSounderDepth from_stream(std::istream& is);

    static SingleBeamEchoSounderDepth from_stream(std::istream&              is,
                                                  t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SingleBeamEchoSounderDepth)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
