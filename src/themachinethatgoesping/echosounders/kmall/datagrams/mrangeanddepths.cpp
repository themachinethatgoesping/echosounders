// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mrangeanddepth.hpp"

#include <fmt/format.h>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

using substructs::MRZSectorInfo;

MRangeAndDepth::MRangeAndDepth(const KMALLDatagram& header)
    : KMALLMultibeamDatagram(header)
{
}

MRangeAndDepth::MRangeAndDepth()
{
    _datagram_identifier = DatagramIdentifier;
}

// ----- setters -----

// ----- processed data access -----

// ----- to/from stream functions -----
void MRangeAndDepth::__read_ping_info__(std::istream& is)
{
    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&_ping_info), sizeof(_ping_info));
}
void MRangeAndDepth::__write_ping_info__(std::ostream& os) const
{
    // read first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&_ping_info), sizeof(_ping_info));
}

void MRangeAndDepth::__read_sectors__(std::istream& is)
{
    const auto n_sectors = _ping_info.get_number_of_tx_sectors();
    const auto version   = get_datagram_version();
    _tx_sectors.resize(n_sectors);

    // if old version read one by one
    if (version < 1)
    {
        for (auto& sector : _tx_sectors)
            sector = sector.__read_version_0__(is);
    }
    else
    {
        // if latest version read as block
        is.read(reinterpret_cast<char*>(_tx_sectors.data()), sizeof(MRZSectorInfo) * n_sectors);
    }
}

void MRangeAndDepth::__write_sectors__(std::ostream& os) const
{
    // const auto n_sectors = get_number_of_tx_sectors();
    const auto version = get_datagram_version();

    // if old version read one by one
    if (version < 1)
    {
        for (const auto& sector : _tx_sectors)
            sector.__write_version_0__(os);
    }
    else
    {
        // if latest version read as block
        os.write(reinterpret_cast<const char*>(_tx_sectors.data()),
                 sizeof(MRZSectorInfo) * _tx_sectors.size());
    }
}

void MRangeAndDepth::__read_rxinfo__(std::istream& is)
{
    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&_rx_info), sizeof(substructs::MRZRxInfo));
}
void MRangeAndDepth::__write_rxinfo__(std::ostream& os) const
{
    // read first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&_rx_info), sizeof(substructs::MRZRxInfo));
}

void MRangeAndDepth::__read_extradetclassinfo__(std::istream& is)
{
    const auto n_classes = _rx_info.get_number_of_extra_detection_classes();
    _extra_det_class_info.resize(n_classes);

    // read as block
    is.read(reinterpret_cast<char*>(_extra_det_class_info.data()),
            sizeof(substructs::MRZExtraDetClassInfo) * n_classes);
}

void MRangeAndDepth::__write_extradetclassinfo__(std::ostream& os) const
{
    // read as block
    os.write(reinterpret_cast<const char*>(_extra_det_class_info.data()),
             sizeof(substructs::MRZExtraDetClassInfo) * _extra_det_class_info.size());
}

MRangeAndDepth MRangeAndDepth::from_stream(std::istream& is, const KMALLDatagram& header)
{
    MRangeAndDepth datagram(header);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_ping_info__(is);
    datagram.__read_sectors__(is);
    datagram.__read_rxinfo__(is);
    datagram.__read_extradetclassinfo__(is);

    return datagram;
}

MRangeAndDepth MRangeAndDepth::from_stream(std::istream&             is,
                                           o_KMALLDatagramIdentifier datagram_identifier)
{
    MRangeAndDepth datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_ping_info__(is);
    datagram.__read_sectors__(is);
    datagram.__read_rxinfo__(is);
    datagram.__read_extradetclassinfo__(is);
    return datagram;
}

MRangeAndDepth MRangeAndDepth::from_stream(std::istream& is)
{
    MRangeAndDepth datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_ping_info__(is);
    datagram.__read_sectors__(is);
    datagram.__read_rxinfo__(is);
    datagram.__read_extradetclassinfo__(is);
    return datagram;
}

void MRangeAndDepth::to_stream(std::ostream& os)
{
    KMALLDatagram::to_stream(os);
    KMALLMultibeamDatagram::to_stream(os);

    __write_ping_info__(os);
    __write_sectors__(os);
    __write_rxinfo__(os);
    __write_extradetclassinfo__(os);
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MRangeAndDepth::__printer__(unsigned int float_precision,
                                                              bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MRangeAndDepth", float_precision, superscript_exponents);

    // false is mpart skipped
    printer.append(
        KMALLMultibeamDatagram::__printer__(float_precision, superscript_exponents, false));

    printer.register_section("Ping info (.ping_info)");
    printer.append(_ping_info.__printer__(float_precision, superscript_exponents));

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

    printer.register_section("Extra detection classes (.extra_det_class_info)");
    printer.register_value("extra_det_class_info (vector)",
                           fmt::format("size={}", _extra_det_class_info.size()),
                           "classes");

    // printer.register_section("processed");

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
