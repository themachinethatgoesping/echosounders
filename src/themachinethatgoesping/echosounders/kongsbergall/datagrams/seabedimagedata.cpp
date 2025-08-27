// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "seabedimagedata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

SeabedImageData SeabedImageData::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    SeabedImageData datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::SeabedImageData)
        throw std::runtime_error(
            fmt::format("SeabedImageData: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::SeabedImageData),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 20 * sizeof(uint8_t));

    // read the beams
    datagram._beams.resize(datagram._number_of_valid_beams);
    is.read(reinterpret_cast<char*>(datagram._beams.data()),
            datagram._number_of_valid_beams * sizeof(substructures::SeabedImageDataBeam));

    uint16_t              total_samples = 0;
    std::vector<uint16_t> samples_per_beam;
    std::vector<uint16_t> start_index_per_beam;
    samples_per_beam.reserve(datagram._number_of_valid_beams);

    for (const auto& beam : datagram._beams)
    {
        start_index_per_beam.push_back(total_samples);
        samples_per_beam.push_back(beam.get_number_of_samples());
        total_samples += samples_per_beam.back();
    }

    datagram._sample_amplitudes =
        substructures::SampleAmplitudesStructure<int16_t>::from_stream(
            is, total_samples, std::move(start_index_per_beam), std::move(samples_per_beam));

    // read the rest of the datagram
    is.read(reinterpret_cast<char*>(&(datagram._spare_byte)), 4 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "SeabedImageData: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

SeabedImageData SeabedImageData::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

SeabedImageData SeabedImageData::from_stream(std::istream&                    is,
                                   t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void SeabedImageData::to_stream(std::ostream& os)
{
    KongsbergAllDatagram::to_stream(os);
    _number_of_valid_beams = _beams.size();

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_ping_counter)), 20 * sizeof(uint8_t));

    // write the beams
    os.write(reinterpret_cast<const char*>(_beams.data()),
             _number_of_valid_beams * sizeof(substructures::SeabedImageDataBeam));

    // write the sample amplitudes
    _sample_amplitudes.to_stream(os);
    // _sample_amplitudes.resize(_number_of_valid_beams);
    // for (uint b = 0; b < _number_of_valid_beams; ++b)
    // {
    //     _sample_amplitudes[b].resize(_beams[b].get_number_of_samples());
    //     os.write(reinterpret_cast<const char*>(_sample_amplitudes[b].data()),
    //              _beams[b].get_number_of_samples() * sizeof(int16_t));
    // }

    // write the rest of the datagram
    os.write(reinterpret_cast<const char*>(&(_spare_byte)), 4 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter SeabedImageData::__printer__(unsigned int float_precision,
                                              bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "SeabedImageData", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("ping_counter", _ping_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("sampling_frequency", _sampling_frequency, "Hz");
    printer.register_value("range_to_normal_incidence", _range_to_normal_incidence);
    printer.register_value(
        "normal_incidence_backscatter", _normal_incidence_backscatter, "0.01 dB");
    printer.register_value("oblique_backscatter", _oblique_backscatter, "0.01 dB");
    printer.register_value("tx_beamwidth_along", _tx_beamwidth_along, "0.1°");
    printer.register_value("tvg_law_crossover_angle", _tvg_law_crossover_angle, "0.1°");
    printer.register_value("number_of_valid_beams", _number_of_valid_beams);
    printer.register_value("spare_byte", _spare_byte);
    printer.register_string("etx", fmt::format("0x{:02x}", _etx));
    printer.register_value("checksum", _checksum);

    printer.register_section("processed");
    printer.register_value(
        "normal_incidence_backscatter", get_normal_incidence_backscatter_in_db(), "dB");
    printer.register_value("oblique_backscatter", get_oblique_backscatter_in_db(), "dB");
    printer.register_value("tx_beamwidth_along", get_tx_beamwidth_along_in_degrees(), "°");
    printer.register_value(
        "tvg_law_crossover_angle", get_tvg_law_crossover_angle_in_degrees(), "°");

    printer.register_section("substructures");
    printer.register_value("beams", _beams.size(), "SeabedImageDataBeams");
    printer.register_value(
        "sample_amplitudes", _sample_amplitudes.size(), "SampleAmplitudesStructure");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
