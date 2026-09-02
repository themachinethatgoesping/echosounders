// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "attitude.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

void Attitude::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_number_of_samples), sizeof(_number_of_samples));

    const size_t N = _number_of_samples;
    _delta_time.resize({ N });
    _roll.resize({ N });
    _pitch.resize({ N });
    _heave.resize({ N });
    _heading.resize({ N });

    AttitudeSample s;
    for (size_t i = 0; i < N; ++i)
    {
        is.read(reinterpret_cast<char*>(&s), __sample_size);
        _delta_time.unchecked(i) = s.delta_time;
        _roll.unchecked(i)       = s.roll;
        _pitch.unchecked(i)      = s.pitch;
        _heave.unchecked(i)      = s.heave;
        _heading.unchecked(i)    = s.heading;
    }
}

Attitude Attitude::from_stream(std::istream& is, S7KDatagram header)
{
    Attitude datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

Attitude Attitude::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

Attitude Attitude::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void Attitude::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_number_of_samples), sizeof(_number_of_samples));

    AttitudeSample s;
    for (size_t i = 0; i < _number_of_samples; ++i)
    {
        s.delta_time = _delta_time.unchecked(i);
        s.roll       = _roll.unchecked(i);
        s.pitch      = _pitch.unchecked(i);
        s.heave      = _heave.unchecked(i);
        s.heading    = _heading.unchecked(i);
        os.write(reinterpret_cast<const char*>(&s), __sample_size);
    }
}

tools::classhelper::ObjectPrinter Attitude::__printer__(unsigned int float_precision,
                                                        bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("Attitude", float_precision, superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("Attitude content");
    printer.register_value("number_of_samples", _number_of_samples);

    printer.register_section("per-sample attitude");
    printer.register_container("delta_time", _delta_time, "ms");
    printer.register_container("roll", _roll, "rad");
    printer.register_container("pitch", _pitch, "rad");
    printer.register_container("heave", _heave, "m");
    printer.register_container("heading", _heading, "rad");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
