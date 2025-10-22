// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "qualityfactordatagram.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>
#include <xtensor/generators/xbuilder.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

QualityFactorDatagram::QualityFactorDatagram(KongsbergAllDatagram header)
	: KongsbergAllDatagram(std::move(header))
{
}

QualityFactorDatagram::QualityFactorDatagram()
{
	_datagram_identifier = t_KongsbergAllDatagramIdentifier::QualityFactorDatagram;
}

uint16_t QualityFactorDatagram::get_ping_counter() const
{
	return _ping_counter;
}

uint16_t QualityFactorDatagram::get_system_serial_number() const
{
	return _system_serial_number;
}

uint16_t QualityFactorDatagram::get_number_of_receive_beams() const
{
	return _number_of_receive_beams;
}

uint8_t QualityFactorDatagram::get_number_of_parameters_per_beam() const
{
	return _number_of_parameters_per_beam;
}

uint8_t QualityFactorDatagram::get_spare() const
{
	return _spare;
}

uint8_t QualityFactorDatagram::get_spare_byte() const
{
	return _spare_byte;
}

uint8_t QualityFactorDatagram::get_etx() const
{
	return _etx;
}

uint16_t QualityFactorDatagram::get_checksum() const
{
	return _checksum;
}

void QualityFactorDatagram::set_ping_counter(uint16_t ping_counter)
{
	_ping_counter = ping_counter;
}

void QualityFactorDatagram::set_system_serial_number(uint16_t system_serial_number)
{
	_system_serial_number = system_serial_number;
}

void QualityFactorDatagram::set_number_of_receive_beams(uint16_t number_of_receive_beams)
{
	_number_of_receive_beams = number_of_receive_beams;
}

void QualityFactorDatagram::set_number_of_parameters_per_beam(uint8_t number_of_parameters_per_beam)
{
	_number_of_parameters_per_beam = number_of_parameters_per_beam;
}

void QualityFactorDatagram::set_spare(uint8_t spare)
{
	_spare = spare;
}

void QualityFactorDatagram::set_spare_byte(uint8_t spare_byte)
{
	_spare_byte = spare_byte;
}

void QualityFactorDatagram::set_etx(uint8_t etx)
{
	_etx = etx;
}

void QualityFactorDatagram::set_checksum(uint16_t checksum)
{
	_checksum = checksum;
}

xt::xtensor<float, 2>& QualityFactorDatagram::quality_factors()
{
	return _quality_factors;
}

const xt::xtensor<float, 2>& QualityFactorDatagram::get_quality_factors() const
{
	return _quality_factors;
}

void QualityFactorDatagram::set_quality_factors(xt::xtensor<float, 2> quality_factors)
{
	_quality_factors = std::move(quality_factors);
}

QualityFactorDatagram::t_Shape QualityFactorDatagram::qf_shape() const
{
	return { _number_of_receive_beams, _number_of_parameters_per_beam };
}

QualityFactorDatagram QualityFactorDatagram::from_stream(std::istream&       is,
	                                                     KongsbergAllDatagram header)
{
	QualityFactorDatagram datagram(std::move(header));

	if (datagram._datagram_identifier !=
	    t_KongsbergAllDatagramIdentifier::QualityFactorDatagram)
		throw std::runtime_error(fmt::format(
		    "QualityFactorDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
		    uint8_t(t_KongsbergAllDatagramIdentifier::QualityFactorDatagram),
		    uint8_t(datagram._datagram_identifier)));

	is.read(reinterpret_cast<char*>(&(datagram._ping_counter)),
	        static_cast<std::streamsize>(8 * sizeof(uint8_t)));

	datagram._quality_factors = xt::empty<float>(datagram.qf_shape());
	is.read(reinterpret_cast<char*>(datagram._quality_factors.data()),
	        static_cast<std::streamsize>(datagram._quality_factors.size() * sizeof(float)));

	is.read(reinterpret_cast<char*>(&(datagram._spare_byte)),
	        static_cast<std::streamsize>(4 * sizeof(uint8_t)));

	if (datagram._etx != 0x03)
		throw std::runtime_error(fmt::format(
		    "QualityFactorDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

	return datagram;
}

QualityFactorDatagram QualityFactorDatagram::from_stream(std::istream& is)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

QualityFactorDatagram QualityFactorDatagram::from_stream(
	std::istream&              is,
	t_KongsbergAllDatagramIdentifier datagram_identifier)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void QualityFactorDatagram::to_stream(std::ostream& os)
{
	KongsbergAllDatagram::to_stream(os);

	auto shape = _quality_factors.shape();
	if (shape.size() != 2)
		throw std::runtime_error("QualityFactorDatagram: quality_factors tensor must have rank 2");

	_number_of_receive_beams       = static_cast<uint16_t>(shape[0]);
	_number_of_parameters_per_beam = static_cast<uint8_t>(shape[1]);

	os.write(reinterpret_cast<const char*>(&(_ping_counter)),
	         static_cast<std::streamsize>(8 * sizeof(uint8_t)));

	os.write(reinterpret_cast<const char*>(_quality_factors.data()),
	         static_cast<std::streamsize>(_quality_factors.size() * sizeof(float)));

	os.write(reinterpret_cast<const char*>(&(_spare_byte)),
	         static_cast<std::streamsize>(4 * sizeof(uint8_t)));
}

tools::classhelper::ObjectPrinter QualityFactorDatagram::__printer__(
	unsigned int float_precision, bool superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
	    "QualityFactorDatagram", float_precision, superscript_exponents);

	printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
	printer.register_section("datagram content");
	printer.register_value("ping_counter", _ping_counter);
	printer.register_value("system_serial_number", _system_serial_number);
	printer.register_value("number_of_receive_beams", _number_of_receive_beams, "Nrx");
	printer.register_value(
	    "number_of_parameters_per_beam", _number_of_parameters_per_beam, "Npar");
	printer.register_value("spare", _spare);
	printer.register_string("etx", fmt::format("0x{:02x}", _etx));
	printer.register_value("checksum", _checksum);

	printer.register_section("substructures");
	printer.register_value(
	    "quality_factors", _quality_factors.size(), "np.array({Nrx, Npar}, dtype=float)");

	return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
