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

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

static const std::map<std::string, std::string> __parameter_explained__ = {
    { "WLZ", "Water line vertical location in m" },
    { "SMH", "System main head serial number" },
    { "HUN", "Hull Unit" },
    { "HUT", "Hull Unit tilt offset" },
    { "TXS", "TX serial number" },
    { "T2X", "TX no. 2 serial number" },
    { "R1S", "RX no. 1, serial number" },
    { "R2S", "RX no. 2, serial number" },
    { "STC", "System transducer configuration" },

    { "S0Z", "Transducer 0 vertical location in m" },
    { "S0X", "Transducer 0 along location in m" },
    { "S0Y", "Transducer 0 athwart location in m" },
    { "S0H", "Transducer 0 heading in degrees" },
    { "S0R", "Transducer 0 roll in degrees re horizontal" },
    { "S0P", "Transducer 0 pitch in degrees" },

    { "S1Z", "Transducer 1 vertical location in m" },
    { "S1X", "Transducer 1 along location in m" },
    { "S1Y", "Transducer 1 athwart location in m" },
    { "S1H", "Transducer 1 heading in degrees" },
    { "S1R", "Transducer 1 roll in degrees re horizontal" },
    { "S1P", "Transducer 1 pitch in degrees" },

    { "S2Z", "Transducer 2 vertical location in m" },
    { "S2X", "Transducer 2 along location in m" },
    { "S2Y", "Transducer 2 athwart location in m" },
    { "S2H", "Transducer 2 heading in degrees" },
    { "S2R", "Transducer 2 roll in degrees re horizontal" },
    { "S2P", "Transducer 2 pitch in degrees" },

    { "S3Z", "Transducer 3 vertical location in m" },
    { "S3X", "Transducer 3 along location in m" },
    { "S3Y", "Transducer 3 athwart location in m" },
    { "S3H", "Transducer 3 heading in degrees" },
    { "S3R", "Transducer 3 roll in degrees re horizontal" },
    { "S3P", "Transducer 3 pitch in degrees" },

    { "S1S", "TX array size (0=0.5o, 1=1o, 2=2o)" },
    { "S2S", "RX array size (1=1o, 2=2o)" },
    { "GO1", "System (sonar head 1) gain offset" },
    { "GO2", "Sonar head 2 gain offset" },
    { "OBO", "Outer beam offset" },
    { "FGD", "High/Low Frequency Gain Difference" },
    { "TSV", "Transmitter (sonar head no1) software version" },
    { "RSV", "Receiver (sonar head 2) software version" },
    { "BSV", "BSP software version" },
    { "PSV", "Processing unit software version" },
    { "DDS", "DDS software version" },
    { "OSV", "Operator station software version" },
    { "DSV", "Datagram format version" },
    { "DSX", "Depth (pressure) sensor along location in m" },
    { "DSY", "Depth (pressure) sensor athwart location in m" },
    { "DSZ", "Depth (pressure) sensor vertical location in m" },
    { "DSD", "Depth (pressure) sensor time delay in millisec" },
    { "DSO", "Depth (pressure) sensor offset" },
    { "DSF", "Depth (pressure) sensor scale factor" },
    { "DSH", "Depth (pressure) sensor heave" },
    { "APS", "Active position system number" },

    { "P1Q", "Position system 1, quality check of position, 0=off, 1=on" },
    { "P1M", "Position system 1 motion compensation" },
    { "P1T", "Position system 1 time stamp used" },
    { "P1Z", "Position system 1 vertical location in m" },
    { "P1X", "Position system 1 along location in m" },
    { "P1Y", "Position system 1 athwart location in m" },
    { "P1D", "Position system 1 time delay in seconds" },
    { "P1G", "Position system 1 geodetic datum" },

    { "P2Q", "Position system 2, quality check of position, 0=off, 2=on" },
    { "P2M", "Position system 2 motion compensation" },
    { "P2T", "Position system 2 time stamp used" },
    { "P2Z", "Position system 2 vertical location in m" },
    { "P2X", "Position system 2 along location in m" },
    { "P2Y", "Position system 2 athwart location in m" },
    { "P2D", "Position system 2 time delay in seconds" },
    { "P2G", "Position system 2 geodetic datum" },

    { "P3Q", "Position system 3, quality check of position, 0=off, 1=on" },
    { "P3M", "Position system 3 motion compensation" },
    { "P3T", "Position system 3 time stamp used" },
    { "P3Z", "Position system 3 vertical location in m" },
    { "P3X", "Position system 3 along location in m" },
    { "P3Y", "Position system 3 athwart location in m" },
    { "P3D", "Position system 3 time delay in seconds" },
    { "P3G", "Position system 3 geodetic datum" },
    { "P3S", "Position system 3 on serial line or Ethernet" },

    { "MSZ", "Motion sensor 1 vertical location in m" },
    { "MSX", "Motion sensor 1 along location in m" },
    { "MSY", "Motion sensor 1 athwart location in m" },
    { "MRP", "Motion sensor 1 roll reference plane" },
    { "MSD", "Motion sensor 1 time delay in milliseconds" },
    { "MSR", "Motion sensor 1 roll offset in degrees" },
    { "MSP", "Motion sensor 1 pitch offset in degrees" },
    { "MSG", "Motion sensor 1 HEADING offset in degrees" },

    { "NSZ", "Motion sensor 2 vertical location in m" },
    { "NSX", "Motion sensor 2 along location in m" },
    { "NSY", "Motion sensor 2 athwart location in m" },
    { "NRP", "Motion sensor 2 roll reference plane" },
    { "NSD", "Motion sensor 2 time delay in milliseconds" },
    { "NSR", "Motion sensor 2 roll offset in degrees" },
    { "NSP", "Motion sensor 2 pitch offset in degrees" },
    { "NSG", "Motion sensor 2 HEADING offset in degrees" },

    { "GCG", "Gyrocompass heading offset in degrees" },
    { "MAS", "Roll scaling factor" },
    { "SHC", "Transducer depth sound speed source" },
    { "PPS", "1PPS clock synchronization" },
    { "CLS", "Clock source" },
    { "CLO", "Clock offset in seconds" },
    { "VSN", "Active attitude velocity sensor" },
    { "VSU", "Attitude velocity sensor 1 UDP port address (UDP5)" },
    { "VSE", "Attitude velocity sensor 1 Ethernet port" },
    { "VTU", "Attitude velocity sensor 2 UDP port address (UDP6)" },
    { "VTE", "Attitude velocity sensor 2 Ethernet port" },
    { "ARO", "Active roll/pitch sensor" },
    { "AHE", "Active heave sensor" },
    { "AHS", "Active heading sensor" },
    { "VSI", "Ethernet 2 address" },
    { "VSM", "Ethernet 2 IP network mask" },
    { "MCAn", "Multicast sensor IP multicast address (Ethernet 2)" },
    { "MCUn", "Multicast sensor UDP port number" },
    { "MCIn", "Multicast sensor identifier" },
    { "MCPn", "Multicast position system number" },
    { "SNL", "Ships noise level" },
    { "CPR", "Cartographic projection" },
    { "ROP", "Responsible operator" },
    { "SID", "Survey identifier" },
    { "RFN", "Raw File Name" },
    { "PLL", "Survey line identifier (planned line no)" },
    { "COM", "Comment" }
};

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

    // parsed data (will not be saved)
    std::map<std::string, std::string> _parsed_installation_parameters;

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
    const std::map<std::string, std::string>& get_installation_parameters_parsed()
    {
        return _parsed_installation_parameters;
    }

    // ----- public methods -----
    /**
     * @brief parse the installation parameters string into a map
     * This happens when the datagram is read from a file, but must be called manually when the
     * installation parameters string is changed manually.
     *
     */
    void reparse_installation_parameters()
    {
        std::string        fields;
        std::istringstream iss(_installation_parameters);

        _parsed_installation_parameters.clear();

        // fields are comma separated, key value pairs are separated by '='
        while (std::getline(iss, fields, ','))
        {
            std::istringstream iss2(fields);
            std::string        key;
            std::string        value;
            std::getline(iss2, key, '=');
            std::getline(iss2, value, '=');

            // delete NULL characters
            key.erase(std::remove(key.begin(), key.end(), '\0'), key.end());

            if (key.empty())
            {
                continue;
            }

            // if key is only whitespaces skip
            if (key.find_first_not_of(" \t\r\n\0\x00") == std::string::npos)
            {
                continue;
            }

            _parsed_installation_parameters[std::move(key)] = std::move(value);
        }
    }

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
        // 21 = size of EM3000Datagram(12) + etx(1) + checksum(2) + 6
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

        // parse the installation parameters string
        datagram.reparse_installation_parameters();

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
                fmt::format("InstallationParameters: bytes - 21 ({}) does not match the size of "
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

        printer.register_section("substructures");
        printer.register_string("installation_parameters", _installation_parameters, "", -1, 50);

        printer.register_section("processed (installation parameter fields)");
        for (const auto& [key, value] : _parsed_installation_parameters)
        {
            std::string exp;
            if (__parameter_explained__.find(key) != __parameter_explained__.end())
                exp = __parameter_explained__.at(key);
            else
                exp = "unknown parameter";

            printer.register_string(key, value, exp);
        }

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
