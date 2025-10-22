// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/headingdatagram.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief Heading datagrams
 */
class HeadingDatagram : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::HeadingDatagram;

  protected:
    uint16_t _heading_counter; ///< Sequential Number
    uint16_t _system_serial_number;
    uint16_t _number_of_entries = 0; ///< N

    xt::xtensor<uint16_t, 2>
        _times_and_headings; ///< 2xN array of time in ms since record start and heading in 0.01°

    uint8_t  _heading_indicator; ///< 0 = inactive
    uint8_t  _etx = 0x03;        ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit HeadingDatagram(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    HeadingDatagram();
    ~HeadingDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_heading_counter() const;
    uint16_t get_system_serial_number() const;
    uint16_t get_number_of_entries() const;
    uint8_t  get_heading_indicator() const;
    uint8_t  get_etx() const;
    uint16_t get_checksum() const;

    // setters
    void set_heading_counter(uint16_t heading_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_number_of_entries(int32_t number_of_entries);
    void set_heading_indicator(uint8_t heading_indicator);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // substructures
    xt::xtensor<uint16_t, 2>&       times_and_headings();
    const xt::xtensor<uint16_t, 2>& get_times_and_headings() const;
    void set_times_and_headings(const xt::xtensor<uint16_t, 2>& times_and_headings);

    // ----- processed data access -----
    /**
     * @brief return the times converted to unix timestamps
     *
     * @return np.array([_number_of_entries], dtype = np.float64)
     */
    xt::xtensor<double, 1> get_heading_timestamps() const;

    /**
     * @brief return headings in degrees by multiplying the heading by 0.01
     *
     * @return np.array([_number_of_entries], dtype = np.float32)
     */
    xt::xtensor<float, 1> get_headings_in_degrees() const;

    // ----- operators -----
    bool operator==(const HeadingDatagram& other) const = default;

    //----- to/from stream functions -----
    static HeadingDatagram from_stream(std::istream& is, KongsbergAllDatagram header);

    static HeadingDatagram from_stream(std::istream& is);

    static HeadingDatagram from_stream(std::istream&              is,
                                       t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(HeadingDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
