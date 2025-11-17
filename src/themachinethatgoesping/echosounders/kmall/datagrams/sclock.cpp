// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "sclock.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

SClock::SClock()
{
    _datagram_identifier = DatagramIdentifier;
}

// ----- setters -----
void SClock::set_clock_data_from_sensor(std::string_view pos_data)
{
    static constexpr size_t dbytes = __size + KMALLSensorDatagram::__size + sizeof(uint32_t);

    auto bytes_content = dbytes + pos_data.size() * sizeof(char); // size of the string in bytes

    _clock_data_from_sensor.assign(pos_data.begin(), pos_data.end());

    // increase _bytes_content to 4 byte alignment
    if (bytes_content % 4 != 0)
    {
        bytes_content += 4 - (bytes_content % 4);
    }

    _clock_data_from_sensor.resize(bytes_content - dbytes, '\0'); // pad with null characters
    set_bytes_datagram(KMALLDatagram::__size + bytes_content);
    _bytes_datagram_check = get_bytes_datagram();
}

// ----- processed data access -----


// ----- to/from stream functions -----
void SClock::__read__(std::istream& is)
{
    static constexpr size_t dbytes = __size + KMALLSensorDatagram::__size + sizeof(uint32_t);

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&_content), __size);

    // read position data string
    _clock_data_from_sensor.resize(compute_size_content() -
                                 dbytes); // minus size of the previous fields
    is.read(_clock_data_from_sensor.data(), _clock_data_from_sensor.size());
    is.read(reinterpret_cast<char*>(&(_bytes_datagram_check)), sizeof(_bytes_datagram_check));
}

SClock SClock::from_stream(std::istream& is, const KMALLDatagram& header)
{
    SClock datagram(header);
    datagram.__read_sensordatagram__(is);
    datagram.__read__(is);

    return datagram;
}

SClock SClock::from_stream(std::istream& is, o_KMALLDatagramIdentifier datagram_identifier)
{
    SClock datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read_sensordatagram__(is);
    datagram.__read__(is);
    return datagram;
}

SClock SClock::from_stream(std::istream& is)
{
    SClock datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read_sensordatagram__(is);
    datagram.__read__(is);
    return datagram;
}

void SClock::to_stream(std::ostream& os)
{
    KMALLDatagram::to_stream(os);
    KMALLSensorDatagram::to_stream(os);

    os.write(reinterpret_cast<char*>(&_content), __size);
    os.write(reinterpret_cast<const char*>(_clock_data_from_sensor.data()),
             _clock_data_from_sensor.size() * sizeof(char));
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter SClock::__printer__(unsigned int float_precision,
                                                         bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("SClock", float_precision, superscript_exponents);

    printer.append(KMALLSensorDatagram::__printer__(float_precision, superscript_exponents));
    // printer.register_section("datagram content");
    //printer.register_value("content_size", __size, std::to_string(sizeof(Content)));
    printer.register_value("offset_sec", _content.offset_sec, "s");
    printer.register_value("clock_dev_pu_microsec", _content.clock_dev_pu_microsec, "µs");
    printer.register_string("clock_data_from_sensor", _clock_data_from_sensor);
    printer.register_value("bytes_datagram_check", _bytes_datagram_check, "bytes");

    //printer.register_section("processed");

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
