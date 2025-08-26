// // SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// //
// // SPDX-License-Identifier: MPL-2.0

// #include "headerdatagram.hpp"

// namespace themachinethatgoesping {
// namespace echosounders {
// namespace gsf {
// namespace datagrams {

// double HeaderDatagram::get_timestamp_external() const
// {
//     int y = int(_date_external / 10000);
//     int m = int(_date_external / 100) - y * 100;
//     int d = int(_date_external) - y * 10000 - m * 100;

//     return tools::timeconv::year_month_day_to_unixtime(
//         y, m, d, uint64_t(_time_since_midnight_external) * 1000);
// }

// std::string HeaderDatagram::get_date_string_external_header(
//     unsigned int       fractionalSecondsDigits,
//     const std::string& format) const
// {
//     return tools::timeconv::unixtime_to_datestring(
//         get_timestamp_external(), fractionalSecondsDigits, format);
// }

// HeaderDatagram HeaderDatagram::from_stream(std::istream& is, GSFDatagram header)
// {
//     HeaderDatagram datagram(std::move(header));

//     if (datagram._datagram_identifier != t_GSFDatagramIdentifier::HeaderDatagram)
//         throw std::runtime_error(
//             fmt::format("HeaderDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
//                         uint8_t(t_GSFDatagramIdentifier::HeaderDatagram),
//                         uint8_t(datagram._datagram_identifier)));

//     // read first part of the datagram (until the first beam)
//     is.read(reinterpret_cast<char*>(&(datagram._header_counter)), 16 * sizeof(uint8_t));

//     if (datagram._etx != 0x03)
//         throw std::runtime_error(fmt::format(
//             "HeaderDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

//     return datagram;
// }

// HeaderDatagram HeaderDatagram::from_stream(std::istream& is)
// {
//     return from_stream(is, GSFDatagram::from_stream(is));
// }

// HeaderDatagram HeaderDatagram::from_stream(std::istream&              is,
//                                           t_GSFDatagramIdentifier datagram_identifier)
// {
//     return from_stream(is, GSFDatagram::from_stream(is, datagram_identifier));
// }

// void HeaderDatagram::to_stream(std::ostream& os)
// {
//     GSFDatagram::to_stream(os);

//     // write first part of the datagram (until the first beam)
//     os.write(reinterpret_cast<const char*>(&(_header_counter)), 16 * sizeof(uint8_t));
// }

// tools::classhelper::ObjectPrinter HeaderDatagram::__printer__(unsigned int float_precision, bool superscript_exponents) const
// {
//     tools::classhelper::ObjectPrinter printer("HeaderDatagram", float_precision, superscript_exponents);

//     static const std::string format_date("%d/%m/%Y");
//     static const std::string format_time("%H:%M:%S");
//     auto                     timestamp_external = get_timestamp_external();

//     using tools::timeconv::unixtime_to_datestring;
//     auto date = unixtime_to_datestring(timestamp_external, 0, format_date);
//     auto time = unixtime_to_datestring(timestamp_external, 3, format_time);

//     printer.append(GSFDatagram::__printer__(float_precision, superscript_exponents));
//     printer.register_section("datagram content");
//     printer.register_value("header_counter", _header_counter);
//     printer.register_value("system_serial_number", _system_serial_number);
//     printer.register_value("date_external", _date_external, "YYYYMMDD");
//     printer.register_value("time_since_midnight_external", _time_since_midnight_external, "ms");
//     printer.register_value("pps_active", _pps_active);
//     printer.register_string("etx", fmt::format("0x{:02x}", _etx));
//     printer.register_value("checksum", _checksum);

//     printer.register_section("External header date/time");
//     printer.register_value("timestamp", timestamp_external, "s");
//     printer.register_string("date", date, "MM/DD/YYYY");
//     printer.register_string("time", time, "HH:MM:SS");
//     printer.register_value("timestamp_offset", (get_timestamp_offset()), "s");
//     return printer;
// }

// } // namespace datagrams
// } // namespace gsf  
// } // namespace echosounders
// } // namespace themachinethatgoesping
