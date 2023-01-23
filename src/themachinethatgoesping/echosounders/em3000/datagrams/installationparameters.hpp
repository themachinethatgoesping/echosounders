// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/installationparameters.doc.hpp"

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
 * @brief This datagram is an ASCII datagram except for the header which is formatted as in all
 * other output datagrams. The datagram is issued as a start datagram when logging is switched on
 * and as a stop datagram when logging is turned off, i.e. at the start and end of a survey line. It
 * may also be sent to a remote port as an information datagram. It is usually followed by a sound
 * speed profile datagram. In the datagram all ASCII fields start with a unique three character
 * identifier followed by “=”. This should be used when searching for a specific field as the
 * position of a field within the datagram is not guaranteed. The number or character part following
 * is in a variable format with a minus sign and decimal point if needed, and with “,” as the field
 * delimiter. The format may at any time later be expanded with the addition of new fields at any
 * place in the datagram.
 */
class InstallationParameters : public EM3000Datagram
{
  protected:
    uint16_t _installation_parameters_counter; ///< Sequential Number
    uint16_t _system_serial_number;
    uint16_t _secondary_system_serial_number;

    std::string _installation_parameters;

    // uint8_t  _spare;      ///< only used if number of bytes is odd
    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit InstallationParameters(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    InstallationParameters()
    {
        _datagram_identifier = t_EM3000DatagramIdentifier::InstallationParametersStart;
    }
    ~InstallationParameters() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_installation_parameters_counter() const
    {
        return _installation_parameters_counter;
    }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_secondary_system_serial_number() const { return _secondary_system_serial_number; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_installation_parameters_counter(uint16_t installation_parameters_counter)
    {
        _installation_parameters_counter = installation_parameters_counter;
    }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_secondary_system_serial_number(uint16_t secondary_system_serial_number)
    {
        _secondary_system_serial_number = secondary_system_serial_number;
    }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // substructures
    std::string&       installation_parameters() { return _installation_parameters; }
    const std::string& get_installation_parameters() const { return _installation_parameters; }
    void               set_installation_parameters(const std::string& installation_parameters)
    {
        _installation_parameters = installation_parameters;
    }

    // ----- processed data access -----

    // ----- operators -----
    bool operator==(const InstallationParameters& other) const
    {
        return EM3000Datagram::operator==(other) &&
               _installation_parameters_counter == other._installation_parameters_counter &&
               _system_serial_number == other._system_serial_number &&
               _secondary_system_serial_number == other._secondary_system_serial_number &&
               _installation_parameters == other._installation_parameters && _etx == other._etx &&
               _checksum == other._checksum;
    }
    bool operator!=(const InstallationParameters& other) const { return !operator==(other); }

    //----- to/from stream functions -----
    static InstallationParameters from_stream(std::istream& is, EM3000Datagram header)
    {
        InstallationParameters datagram(std::move(header));

        if (datagram._datagram_identifier !=
                t_EM3000DatagramIdentifier::InstallationParametersStart &&
            datagram._datagram_identifier != t_EM3000DatagramIdentifier::InstallationParametersStop)
            throw std::runtime_error(
                fmt::format("InstallationParameters: datagram identifier is neither 0x{:02x} nor "
                            "0x{:02x}, but 0x{:02x}",
                            uint8_t(t_EM3000DatagramIdentifier::InstallationParametersStart),
                            uint8_t(t_EM3000DatagramIdentifier::InstallationParametersStop),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._installation_parameters_counter)),
                6 * sizeof(uint8_t));

        // size of the ascii datagram
        const static uint8_t tmp = sizeof(uint8_t) * (21);

        // read the ASCII datagram
        datagram._installation_parameters.resize(datagram.get_bytes() - tmp);
        is.read(reinterpret_cast<char*>(datagram._installation_parameters.data()),
                datagram._installation_parameters.size());

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._etx)), sizeof(uint8_t));
        is.read(reinterpret_cast<char*>(&(datagram._checksum)), sizeof(uint16_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "InstallationParameters: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static InstallationParameters from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static InstallationParameters from_stream(std::istream&              is,
                                              t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os) const
    {
        if (_bytes - 21 != _installation_parameters.size())
            throw std::runtime_error(
                fmt::format("InstallationParameters: bytes - 15 ({}) does not match the size of "
                            "the _installation_parameters string ({})",
                            _bytes - 21,
                            _installation_parameters.size()));

        EM3000Datagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_installation_parameters_counter)),
                 6 * sizeof(uint8_t));

        // write the installation paramaters string
        os.write(reinterpret_cast<const char*>(_installation_parameters.data()),
                 _installation_parameters.size() * sizeof(uint8_t));

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_etx)), sizeof(uint8_t));
        os.write(reinterpret_cast<const char*>(&(_checksum)), sizeof(uint16_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("InstallationParameters", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("installation_parameters_counter", _installation_parameters_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("secondary_system_serial_number", _secondary_system_serial_number);
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        // printer.register_section("processed");

        printer.register_section("substructures");
        printer.register_string("installation_parameters", _installation_parameters);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(InstallationParameters)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
