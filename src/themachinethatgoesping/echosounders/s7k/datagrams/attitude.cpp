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
    uint8_t number_of_samples = 0;
    is.read(reinterpret_cast<char*>(&number_of_samples), sizeof(number_of_samples));

    auto& samples = _samples.samples();
    samples.resize(number_of_samples);

    // read all samples as one contiguous block
    is.read(reinterpret_cast<char*>(samples.data()),
            std::streamsize(number_of_samples * sizeof(substructs::AttitudeSample)));
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

    const auto&   samples           = _samples.get_samples();
    const uint8_t number_of_samples = uint8_t(samples.size());
    os.write(reinterpret_cast<const char*>(&number_of_samples), sizeof(number_of_samples));

    os.write(reinterpret_cast<const char*>(samples.data()),
             std::streamsize(samples.size() * sizeof(substructs::AttitudeSample)));
}

tools::classhelper::ObjectPrinter Attitude::__printer__(unsigned int float_precision,
                                                        bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("Attitude content");
    printer.register_value("number_of_samples", get_number_of_samples());

    printer.register_section("samples");
    printer.append(_samples.__printer__(float_precision, superscript_exponents));

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
