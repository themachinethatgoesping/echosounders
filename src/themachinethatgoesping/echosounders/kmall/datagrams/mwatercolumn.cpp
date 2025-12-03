// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mwatercolumn.hpp"

#include <fmt/format.h>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

using substructs::MWCSectorInfo;

MWaterColumn::MWaterColumn(const KMALLDatagram& header)
    : KMALLMultibeamDatagram(header)
{
}

MWaterColumn::MWaterColumn()
{
    _datagram_identifier = DatagramIdentifier;
}

// // ----- setters -----

// // ----- processed data access -----

// // ----- to/from stream functions -----
void MWaterColumn::__read_tx_info__(std::istream& is)
{
    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&_tx_info), sizeof(_tx_info));
}
void MWaterColumn::__write_tx_info__(std::ostream& os) const
{
    // read first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&_tx_info), sizeof(_tx_info));
}

void MWaterColumn::__read_sectors__(std::istream& is)
{
    const auto n_sectors = _tx_info.get_number_of_tx_sectors();
    _tx_sectors.resize(n_sectors);

    is.read(reinterpret_cast<char*>(_tx_sectors.data()), sizeof(MWCSectorInfo) * n_sectors);
}

void MWaterColumn::__write_sectors__(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(_tx_sectors.data()),
             sizeof(MWCSectorInfo) * _tx_sectors.size());
}

void MWaterColumn::__read_rxinfo__(std::istream& is)
{
    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&_rx_info), sizeof(substructs::MWCRxInfo));
}
void MWaterColumn::__write_rxinfo__(std::ostream& os) const
{
    // read first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&_rx_info), sizeof(substructs::MWCRxInfo));
}

void MWaterColumn::__read_beamdata__(std::istream& is)
{
    const auto n_beams = _rx_info.get_number_of_beams();
    _beam_data.beams().reserve(n_beams);

    // read per beam
    for (auto i = 0; i < n_beams; ++i)
        _beam_data.beams().emplace_back(substructs::MWCRxBeamData::from_stream(is));
}

void MWaterColumn::__write_beamdata__(std::ostream& os) const
{
    for (const auto& beam : _beam_data.get_beams())
        beam.to_stream(os);
}

// void MWaterColumn::__read_soundings__(std::istream& is)
// {
//     auto&      soundings = _soundings.soundings();
//     const auto n_soundings =
//         _rx_info.get_number_of_soundings_max_main() + _rx_info.get_number_of_extra_detections();

//     soundings.resize(n_soundings);

//     // read as block
//     is.read(reinterpret_cast<char*>(soundings.data()),
//             sizeof(substructs::MRZSoundings) * n_soundings);
// }

// void MWaterColumn::__write_soundings__(std::ostream& os) const
// {
//     const auto& soundings = _soundings.get_soundings();
//     // read as block
//     os.write(reinterpret_cast<const char*>(soundings.data()),
//              sizeof(substructs::MRZSoundings) * soundings.size());
// }

// void MWaterColumn::__read_seabed_image_samples__(std::istream& is)
// {
//     const size_t n_samples = _soundings.get_number_of_seabed_image_samples();
//     _seabed_image_samples_dezi_db.resize({ n_samples });
//     is.read(reinterpret_cast<char*>(_seabed_image_samples_dezi_db.data()),
//             sizeof(int16_t) * n_samples);
// }
// void MWaterColumn::__write_seabed_image_samples__(std::ostream& os) const
// {
//     const size_t n_samples = _seabed_image_samples_dezi_db.size();
//     os.write(reinterpret_cast<const char*>(_seabed_image_samples_dezi_db.data()),
//              sizeof(int16_t) * n_samples);
//}

MWaterColumn MWaterColumn::from_stream(std::istream& is, const KMALLDatagram& header)
{
    MWaterColumn datagram(header);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_tx_info__(is);
    datagram.__read_sectors__(is);
    datagram.__read_rxinfo__(is);
    datagram.__read_beamdata__(is);
    // datagram.__read_soundings__(is);
    // datagram.__read_seabed_image_samples__(is);
    // is.read(reinterpret_cast<char*>(&datagram._bytes_datagram_check),
    //         sizeof(datagram._bytes_datagram_check));

    return datagram;
}

MWaterColumn MWaterColumn::from_stream(std::istream&             is,
                                       o_KMALLDatagramIdentifier datagram_identifier)
{
    MWaterColumn datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_tx_info__(is);
    datagram.__read_sectors__(is);
    datagram.__read_rxinfo__(is);
    datagram.__read_beamdata__(is);
    // datagram.__read_soundings__(is);
    // datagram.__read_seabed_image_samples__(is);
    // is.read(reinterpret_cast<char*>(&datagram._bytes_datagram_check),
    //         sizeof(datagram._bytes_datagram_check));
    return datagram;
}

MWaterColumn MWaterColumn::from_stream(std::istream& is)
{
    MWaterColumn datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_tx_info__(is);
    datagram.__read_sectors__(is);
    datagram.__read_rxinfo__(is);
    datagram.__read_beamdata__(is);
    // datagram.__read_soundings__(is);
    // datagram.__read_seabed_image_samples__(is);
    // is.read(reinterpret_cast<char*>(&datagram._bytes_datagram_check),
    //         sizeof(datagram._bytes_datagram_check));
    return datagram;
}

void MWaterColumn::to_stream(std::ostream& os) const
{
    KMALLDatagram::to_stream(os);
    KMALLMultibeamDatagram::to_stream(os);

    __write_tx_info__(os);
    __write_sectors__(os);
    __write_rxinfo__(os);
    __write_beamdata__(os);
    // __write_soundings__(os);
    // __write_seabed_image_samples__(os);
    // os.write(reinterpret_cast<const char*>(&_bytes_datagram_check),
    // sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MWaterColumn::__printer__(unsigned int float_precision,
                                                            bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MWaterColumn", float_precision, superscript_exponents);

    // false is mpart skipped
    printer.append(
        KMALLMultibeamDatagram::__printer__(float_precision, superscript_exponents, false));

    printer.register_section("Tx info (.tx_info)");
    printer.append(_tx_info.__printer__(float_precision, superscript_exponents));

    printer.register_section(
        fmt::format("Sector infos (.tx_sectors - {} sectors)", _tx_sectors.size()));
    for (const auto& sector : _tx_sectors)
    {
        printer.register_section(fmt::format("Content sector -{}-", sector.get_tx_sector_number()),
                                 '.');
        printer.append(sector.__printer__(float_precision, superscript_exponents));
    }

    printer.register_section("Rx info (.rx_info)");
    printer.append(_rx_info.__printer__(float_precision, superscript_exponents));

    // printer.register_section("Extra detection classes (.extra_det_class_info)");
    // printer.register_value("extra_det_class_info (vector)",
    //                        fmt::format("size={}", _extra_det_class_info.size()),
    //                        "classes");

    printer.register_section("Beam data (.beam_data)");
    printer.register_value(
        "beam_data (vector)", fmt::format("size={}", _beam_data.get_beams().size()), "beams");

    // printer.register_section("Seabed image samples");
    // printer.register_container("seabed_image_samples_dezi_db", _seabed_image_samples_dezi_db);
    // printer.register_container("seabed_image_samples_db",
    //                            get_seabed_image_samples_db()); // convert to dB

    // printer.register_section("processed");

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
