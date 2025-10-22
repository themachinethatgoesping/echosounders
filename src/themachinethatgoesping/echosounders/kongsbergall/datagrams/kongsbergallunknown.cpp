// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "kongsbergallunknown.hpp"

#include <fmt/core.h>

#include <stdexcept>
#include <utility>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

KongsbergAllUnknown::KongsbergAllUnknown(KongsbergAllDatagram header)
	: KongsbergAllDatagram(std::move(header))
{
}

const std::string& KongsbergAllUnknown::get_raw_content() const
{
	return _raw_content;
}

uint8_t KongsbergAllUnknown::get_etx() const
{
	return _etx;
}

uint16_t KongsbergAllUnknown::get_checksum() const
{
	return _checksum;
}

void KongsbergAllUnknown::set_raw_content(const std::string& value)
{
	_raw_content = value;
}

void KongsbergAllUnknown::set_etx(uint8_t value)
{
	_etx = value;
}

void KongsbergAllUnknown::set_checksum(uint16_t value)
{
	_checksum = value;
}

KongsbergAllUnknown KongsbergAllUnknown::from_stream(std::istream& is, KongsbergAllDatagram header)
{
	KongsbergAllUnknown datagram(std::move(header));

	if (datagram._bytes > 15)
	{
		datagram._raw_content.resize(size_t(datagram._bytes - 15));
	}
	else
	{
		throw std::runtime_error("ERROR[KongsbergAllUnknown::from_stream]: _bytes is too small");
	}

	// verify the datagram is read correctly by reading the length field at the end
	// datagram._verify_datagram_end(is);
	is.read(datagram._raw_content.data(), datagram._raw_content.size());
	is.read(reinterpret_cast<char*>(&(datagram._etx)), 3 * sizeof(uint8_t));

	if (datagram._etx != 0x03)
	{
		throw std::runtime_error(fmt::format(
			"KongsbergAllUnknown: end identifier is not 0x03, but 0x{:x}", datagram._etx));
	}

	return datagram;
}

KongsbergAllUnknown KongsbergAllUnknown::from_stream(std::istream& is)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

KongsbergAllUnknown KongsbergAllUnknown::from_stream(std::istream&                    is,
													 t_KongsbergAllDatagramIdentifier datagram_identifier)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void KongsbergAllUnknown::to_stream(std::ostream& os)
{
	_bytes = static_cast<uint32_t>(15 + _raw_content.size());
	KongsbergAllDatagram::to_stream(os);

	os.write(_raw_content.data(), static_cast<std::streamsize>(_raw_content.size()));
	os.write(reinterpret_cast<char*>(&_etx), 3 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter KongsbergAllUnknown::__printer__(unsigned int float_precision,
																   bool         superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer("KongsbergAllUnknown",
											  float_precision,
											  superscript_exponents);

	printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
	printer.register_section("datagram content");
	printer.register_value("raw data", _raw_content.size(), "bytes");
	printer.register_string("etx", fmt::format("0x{:02x}", _etx));
	// printer.register_value("checksum", _checksum, verify_checksum() ? "valid" : "invalid");
	printer.register_value("checksum", _checksum);

	return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
