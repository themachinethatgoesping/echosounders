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

void MWaterColumn::__read_beamdata__(std::istream& is, bool skip_data)
{
    const auto n_beams = _rx_info.get_number_of_beams();
    _beam_data.beams().reserve(n_beams);

    const auto nbytes_per_beam = _rx_info.get_number_bytes_per_beam_entry();
    const auto phase_data      = (_rx_info.get_phase_flag() != 0);

    // read per beam
    for (auto i = 0; i < n_beams; ++i)
    {
        _beam_data.beams().emplace_back(
            substructs::MWCRxBeamData::from_stream(is, skip_data, nbytes_per_beam, phase_data));
        if (nbytes_per_beam < 16)
        {
            _beam_data.beams().back().set_detected_range_in_samples_high_resolution(
                std::numeric_limits<float>::quiet_NaN());
        }
    }
}

void MWaterColumn::__write_beamdata__(std::ostream& os) const
{
    const auto nbytes_per_beam = _rx_info.get_number_bytes_per_beam_entry();

    for (const auto& beam : _beam_data.get_beams())
        beam.to_stream(os, nbytes_per_beam);
}

MWaterColumn MWaterColumn::from_stream(std::istream&        is,
                                       const KMALLDatagram& header,
                                       bool                 skip_data)
{
    MWaterColumn datagram(header);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_tx_info__(is);
    datagram.__read_sectors__(is);
    datagram.__read_rxinfo__(is);
    datagram.__read_beamdata__(is, skip_data);
    // datagram.__read_soundings__(is);
    // datagram.__read_seabed_image_samples__(is);
    is.read(reinterpret_cast<char*>(&datagram._bytes_datagram_check),
            sizeof(datagram._bytes_datagram_check));

    return datagram;
}

MWaterColumn MWaterColumn::from_stream(std::istream&             is,
                                       o_KMALLDatagramIdentifier datagram_identifier,
                                       bool                      skip_data)
{
    MWaterColumn datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_tx_info__(is);
    datagram.__read_sectors__(is);
    datagram.__read_rxinfo__(is);
    datagram.__read_beamdata__(is, skip_data);
    // datagram.__read_soundings__(is);
    // datagram.__read_seabed_image_samples__(is);
    is.read(reinterpret_cast<char*>(&datagram._bytes_datagram_check),
            sizeof(datagram._bytes_datagram_check));
    return datagram;
}

MWaterColumn MWaterColumn::from_stream(std::istream& is, bool skip_data)
{
    MWaterColumn datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_tx_info__(is);
    datagram.__read_sectors__(is);
    datagram.__read_rxinfo__(is);
    datagram.__read_beamdata__(is, skip_data);
    // datagram.__read_soundings__(is);
    // datagram.__read_seabed_image_samples__(is);
    is.read(reinterpret_cast<char*>(&datagram._bytes_datagram_check),
            sizeof(datagram._bytes_datagram_check));
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
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MWaterColumn::__printer__(unsigned int float_precision,
                                                            bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MWaterColumn", float_precision, superscript_exponents);

    // false is mpart skipped
    printer.append(
        KMALLMultibeamDatagram::__printer__(float_precision, superscript_exponents, true));

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
