// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "beamgeometry.hpp"

#include <utility>

#include <fmt/format.h>

#include <xtensor/core/xmath.hpp> // for xt::rad2deg

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- constructors -----
BeamGeometry::BeamGeometry()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
}

BeamGeometry::BeamGeometry(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- record type header access -----
uint64_t BeamGeometry::get_serial_number() const
{
    return _content._serial_number;
}
uint32_t BeamGeometry::get_number_beams() const
{
    return _content._number_beams;
}
uint32_t BeamGeometry::get_checksum() const
{
    return _checksum;
}

void BeamGeometry::set_serial_number(uint64_t val)
{
    _content._serial_number = val;
}
void BeamGeometry::set_number_beams(uint32_t val)
{
    _content._number_beams = val;
}
void BeamGeometry::set_checksum(uint32_t val)
{
    _checksum = val;
}

// ----- per-beam data access -----
const xt::xtensor<float, 1>& BeamGeometry::get_beam_vertical_angle() const
{
    return _beam_vertical_angle;
}
const xt::xtensor<float, 1>& BeamGeometry::get_beam_horizontal_angle() const
{
    return _beam_horizontal_angle;
}
const xt::xtensor<float, 1>& BeamGeometry::get_beamwidth_vertical() const
{
    return _beamwidth_vertical;
}
const xt::xtensor<float, 1>& BeamGeometry::get_beamwidth_horizontal() const
{
    return _beamwidth_horizontal;
}
bool BeamGeometry::get_has_tx_delay() const
{
    return _has_tx_delay;
}
const xt::xtensor<float, 1>& BeamGeometry::get_tx_delay() const
{
    return _tx_delay;
}

void BeamGeometry::set_beam_vertical_angle(const xt::xtensor<float, 1>& v)
{
    _beam_vertical_angle = v;
}
void BeamGeometry::set_beam_horizontal_angle(const xt::xtensor<float, 1>& v)
{
    _beam_horizontal_angle = v;
}
void BeamGeometry::set_beamwidth_vertical(const xt::xtensor<float, 1>& v)
{
    _beamwidth_vertical = v;
}
void BeamGeometry::set_beamwidth_horizontal(const xt::xtensor<float, 1>& v)
{
    _beamwidth_horizontal = v;
}
void BeamGeometry::set_tx_delay(const xt::xtensor<float, 1>& v)
{
    _tx_delay = v;
}
void BeamGeometry::set_has_tx_delay(bool v)
{
    _has_tx_delay = v;
}

void BeamGeometry::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);

    const size_t        N     = _content._number_beams;
    const std::streamsize bytes = std::streamsize(N * sizeof(float));

    auto read_array = [&](xt::xtensor<float, 1>& a) {
        a.resize({ N });
        is.read(reinterpret_cast<char*>(a.data()), bytes);
    };

    read_array(_beam_vertical_angle);
    read_array(_beam_horizontal_angle);
    read_array(_beamwidth_vertical);
    read_array(_beamwidth_horizontal);

    // the tx_delay array is optional (added in a later record version); every record ends with a
    // 4-byte checksum, so the optional array is only present if there is room for it before it
    _has_tx_delay = compute_size_content() >= __content_size + 5 * N * sizeof(float) + 4;
    if (_has_tx_delay)
        read_array(_tx_delay);
    else
        _tx_delay = xt::xtensor<float, 1>();

    // read the trailing 4-byte checksum (stored for debugging only, not verified)
    is.read(reinterpret_cast<char*>(&_checksum), sizeof(_checksum));
}

BeamGeometry BeamGeometry::from_stream(std::istream& is, S7KDatagram header)
{
    BeamGeometry datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

BeamGeometry BeamGeometry::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

BeamGeometry BeamGeometry::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void BeamGeometry::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);

    const std::streamsize bytes = std::streamsize(_content._number_beams * sizeof(float));
    os.write(reinterpret_cast<const char*>(_beam_vertical_angle.data()), bytes);
    os.write(reinterpret_cast<const char*>(_beam_horizontal_angle.data()), bytes);
    os.write(reinterpret_cast<const char*>(_beamwidth_vertical.data()), bytes);
    os.write(reinterpret_cast<const char*>(_beamwidth_horizontal.data()), bytes);
    if (_has_tx_delay)
        os.write(reinterpret_cast<const char*>(_tx_delay.data()), bytes);

    os.write(reinterpret_cast<const char*>(&_checksum), sizeof(_checksum));
}

xt::xtensor<float, 1> BeamGeometry::get_beam_vertical_angle_in_degrees() const
{
    return xt::rad2deg(_beam_vertical_angle);
}

xt::xtensor<float, 1> BeamGeometry::get_beam_horizontal_angle_in_degrees() const
{
    return xt::rad2deg(_beam_horizontal_angle);
}

xt::xtensor<float, 1> BeamGeometry::get_beamwidth_vertical_in_degrees() const
{
    return xt::rad2deg(_beamwidth_vertical);
}

xt::xtensor<float, 1> BeamGeometry::get_beamwidth_horizontal_in_degrees() const
{
    return xt::rad2deg(_beamwidth_horizontal);
}

tools::classhelper::ObjectPrinter BeamGeometry::__printer__(unsigned int float_precision,
                                                            bool superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("BeamGeometry content");
    printer.register_value("serial_number", _content._serial_number);
    printer.register_value("number_beams", _content._number_beams);
    printer.register_value("has_tx_delay", _has_tx_delay);
    printer.register_value("checksum", _checksum);

    printer.register_section("per-beam geometry");
    printer.register_container("beam_vertical_angle", _beam_vertical_angle, "rad");
    printer.register_container("beam_horizontal_angle", _beam_horizontal_angle, "rad");
    printer.register_container("beamwidth_vertical", _beamwidth_vertical, "rad");
    printer.register_container("beamwidth_horizontal", _beamwidth_horizontal, "rad");

    printer.register_section("processed");
    printer.register_container(
        "beam_vertical_angle_in_degrees", get_beam_vertical_angle_in_degrees(), "°");
    printer.register_container(
        "beam_horizontal_angle_in_degrees", get_beam_horizontal_angle_in_degrees(), "°");
    printer.register_container(
        "beamwidth_vertical_in_degrees", get_beamwidth_vertical_in_degrees(), "°");
    printer.register_container(
        "beamwidth_horizontal_in_degrees", get_beamwidth_horizontal_in_degrees(), "°");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
