// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "beamgeometry.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

void BeamGeometry::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);

    const size_t        N     = _content.number_beams;
    const std::streamsize bytes = std::streamsize(N * sizeof(float));

    auto read_array = [&](xt::xtensor<float, 1>& a) {
        a.resize({ N });
        is.read(reinterpret_cast<char*>(a.data()), bytes);
    };

    read_array(_beam_vertical_angle);
    read_array(_beam_horizontal_angle);
    read_array(_beamwidth_vertical);
    read_array(_beamwidth_horizontal);

    // the tx_delay array is optional (added in a later record version)
    _has_tx_delay = compute_size_content() >= __content_size + 5 * N * sizeof(float);
    if (_has_tx_delay)
        read_array(_tx_delay);
    else
        _tx_delay = xt::xtensor<float, 1>();
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

    const std::streamsize bytes = std::streamsize(_content.number_beams * sizeof(float));
    os.write(reinterpret_cast<const char*>(_beam_vertical_angle.data()), bytes);
    os.write(reinterpret_cast<const char*>(_beam_horizontal_angle.data()), bytes);
    os.write(reinterpret_cast<const char*>(_beamwidth_vertical.data()), bytes);
    os.write(reinterpret_cast<const char*>(_beamwidth_horizontal.data()), bytes);
    if (_has_tx_delay)
        os.write(reinterpret_cast<const char*>(_tx_delay.data()), bytes);
}

tools::classhelper::ObjectPrinter BeamGeometry::__printer__(unsigned int float_precision,
                                                            bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("BeamGeometry", float_precision, superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("BeamGeometry content");
    printer.register_value("serial_number", _content.serial_number);
    printer.register_value("number_beams", _content.number_beams);
    printer.register_value("has_tx_delay", _has_tx_delay);

    printer.register_section("per-beam geometry");
    printer.register_container("beam_vertical_angle", _beam_vertical_angle, "rad");
    printer.register_container("beam_horizontal_angle", _beam_horizontal_angle, "rad");
    printer.register_container("beamwidth_vertical", _beamwidth_vertical, "rad");
    printer.register_container("beamwidth_horizontal", _beamwidth_horizontal, "rad");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
