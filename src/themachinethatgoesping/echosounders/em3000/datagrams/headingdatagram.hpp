// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/headingdatagram.doc.hpp"

// std includes
#include <string>
#include <vector>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

/**
 * @brief Heading datagrams
 */
class HeadingDatagram : public EM3000Datagram
{
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
    explicit HeadingDatagram(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    HeadingDatagram() { _datagram_identifier = t_EM3000DatagramIdentifier::HeadingDatagram; }
    ~HeadingDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_heading_counter() const { return _heading_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_number_of_entries() const { return _number_of_entries; }
    uint8_t  get_heading_indicator() const { return _heading_indicator; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_heading_counter(uint16_t heading_counter) { _heading_counter = heading_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_number_of_entries(int32_t number_of_entries)
    {
        _number_of_entries = number_of_entries;
    }
    void set_heading_indicator(uint8_t heading_indicator)
    {
        _heading_indicator = heading_indicator;
    }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // substructures
    xt::xtensor<uint16_t, 2>&       times_and_headings() { return _times_and_headings; }
    const xt::xtensor<uint16_t, 2>& get_times_and_headings() const { return _times_and_headings; }
    void set_times_and_headings(const xt::xtensor<uint16_t, 2>& times_and_headings)
    {
        _times_and_headings = times_and_headings;
    }

    // ----- processed data access -----
    /**
     * @brief return the times converted to unix timestamps
     *
     * @return np.array([_number_of_entries], dtype = np.float64)
     */
    xt::xtensor<double, 1> get_heading_timestamps() const
    {
        double timestamp = get_timestamp();

        // the output timestamp is the timestamp of the datagram plus the time of the entry
        return xt::view(_times_and_headings, xt::all(), 0) * 0.001 + timestamp;
    }

    /**
     * @brief return headings in degrees by multiplying the heading by 0.01
     *
     * @return np.array([_number_of_entries], dtype = np.float32)
     */
    xt::xtensor<float, 1> get_headings_in_degrees() const
    {
        return xt::view(_times_and_headings, xt::all(), 1) * 0.01;
    }

    // ----- operators -----
    bool operator==(const HeadingDatagram& other) const
    {
        return EM3000Datagram::operator==(other) && _heading_counter == other._heading_counter &&
               _system_serial_number == other._system_serial_number &&
               _number_of_entries == other._number_of_entries &&
               _times_and_headings == other._times_and_headings &&
               _heading_indicator == other._heading_indicator && _etx == other._etx &&
               _checksum == other._checksum;
    }
    bool operator!=(const HeadingDatagram& other) const { return !operator==(other); }

    //----- to/from stream functions -----
    static HeadingDatagram from_stream(std::istream& is, EM3000Datagram header)
    {
        HeadingDatagram datagram(std::move(header));

        if (datagram._datagram_identifier != t_EM3000DatagramIdentifier::HeadingDatagram)
            throw std::runtime_error(
                fmt::format("HeadingDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                            uint8_t(t_EM3000DatagramIdentifier::HeadingDatagram),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._heading_counter)), 6 * sizeof(uint8_t));

        // read the times and headings
        if (datagram._number_of_entries > 0)
        {
            datagram._times_and_headings = xt::empty<uint16_t>(
                xt::xtensor<uint16_t, 2>::shape_type({ datagram._number_of_entries, 2 }));

            is.read(reinterpret_cast<char*>(datagram._times_and_headings.data()),
                    datagram._times_and_headings.size() * sizeof(uint16_t));
        }

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._heading_indicator)), 4 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "HeadingDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static HeadingDatagram from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static HeadingDatagram from_stream(std::istream&              is,
                                       t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os) const
    {
        if (_number_of_entries != _times_and_headings.shape()[0])
            throw std::runtime_error(
                fmt::format("HeadingDatagram: number of entries ({}) does not match the size of "
                            "the times_and_headings array ({})",
                            _number_of_entries,
                            _times_and_headings.shape()[0]));

        EM3000Datagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_heading_counter)), 6 * sizeof(uint8_t));

        // write the times and headings
        os.write(reinterpret_cast<const char*>(_times_and_headings.data()),
                 _times_and_headings.size() * sizeof(uint16_t));

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_heading_indicator)), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("HeadingDatagram", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("heading_counter", _heading_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("number_of_entries", _number_of_entries);

        printer.register_section("processed");
        printer.register_container("heading_timestamps", get_heading_timestamps(), "s");
        printer.register_container("headings", get_headings_in_degrees(), "°");

        printer.register_section("substructures");
        printer.register_container("times_and_headings", _times_and_headings);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(HeadingDatagram)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
