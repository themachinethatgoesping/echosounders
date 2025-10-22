// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/depthorheightdatagram.doc.hpp"

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
 * @brief Depth (pressure) or height datagrams
 */
class DepthOrHeightDatagram : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::DepthOrHeightDatagram;

  protected:
    uint16_t _height_counter; ///< Sequential Number
    uint16_t _system_serial_number;
    int32_t  _height;      ///< in cm
    uint8_t  _height_type; ///< 0: derived from GGK or GGA, 1-99 ???, 100 depth is taken from the
                           ///< DepthOrheight datagram, 200: Input from depth sensor

    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit DepthOrHeightDatagram(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    DepthOrHeightDatagram();
    ~DepthOrHeightDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_height_counter() const;
    uint16_t get_system_serial_number() const;
    int32_t  get_height() const;
    uint8_t  get_height_type() const;
    uint8_t  get_etx() const;
    uint16_t get_checksum() const;

    // setters
    void set_height_counter(uint16_t height_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_height(int32_t height);
    void set_height_type(uint8_t height_type);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // ----- processed data access -----
    /**
     * @brief Get the height in meters
     *
     * @return _height * 0.01m (float)
     */
    float get_height_in_meters() const;

    /**
     * @brief Get a string description of the height_type
     *
     * @return std::string
     */
    std::string get_height_type_explained() const;

    // ----- operators -----
    bool operator==(const DepthOrHeightDatagram& other) const = default;

    //----- to/from stream functions -----
    static DepthOrHeightDatagram from_stream(std::istream& is, KongsbergAllDatagram header);

    static DepthOrHeightDatagram from_stream(std::istream& is);

    static DepthOrHeightDatagram from_stream(std::istream&              is,
                                             t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(DepthOrHeightDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
