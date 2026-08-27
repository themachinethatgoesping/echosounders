// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mwctxsectorscontainer.hpp"

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

const std::vector<MWCSectorInfo>& MWCTxSectorsContainer::get_tx_sectors() const
{
    return _tx_sectors;
}

std::vector<MWCSectorInfo>& MWCTxSectorsContainer::tx_sectors() { return _tx_sectors; }

void MWCTxSectorsContainer::set_tx_sectors(const std::vector<MWCSectorInfo>& sectors)
{
    _tx_sectors = sectors;
}

#define _MWC_TXS_GETTER(NAME, TYPE)                                                                \
    xt::xtensor<TYPE, 1> MWCTxSectorsContainer::get_##NAME##_tensor(                               \
        const std::vector<uint32_t>& indices) const                                                \
    {                                                                                              \
        return build_tensor<TYPE>([](const MWCSectorInfo& s) { return s.get_##NAME(); }, indices); \
    }

_MWC_TXS_GETTER(tilt_angle_re_tx_deg, float)
_MWC_TXS_GETTER(centre_frequency_hz, float)
_MWC_TXS_GETTER(tx_beam_width_along_deg, float)
_MWC_TXS_GETTER(tx_sector_number, uint16_t)
_MWC_TXS_GETTER(padding, int16_t)

#undef _MWC_TXS_GETTER

size_t MWCTxSectorsContainer::get_number_of_tx_sectors() const { return _tx_sectors.size(); }

tools::classhelper::ObjectPrinter MWCTxSectorsContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MWCTxSectorsContainer", float_precision, superscript_exponents);

    printer.register_section("TxSectors (.tx_sectors)");
    printer.register_value("tx_sectors (vector)",
                           fmt::format("size={}", get_number_of_tx_sectors()),
                           "sectors");

    printer.register_container("tilt_angle_re_tx_deg", get_tilt_angle_re_tx_deg_tensor(), "deg");
    printer.register_container("centre_frequency_hz", get_centre_frequency_hz_tensor(), "Hz");
    printer.register_container(
        "tx_beam_width_along_deg", get_tx_beam_width_along_deg_tensor(), "deg");
    printer.register_container("tx_sector_number", get_tx_sector_number_tensor());
    printer.register_container("padding", get_padding_tensor());

    printer.register_section("processed");
    printer.register_value("number_of_tx_sectors", get_number_of_tx_sectors());

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
