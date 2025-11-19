// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mrangeanddepth.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "kmallmultibeamdatagram.hpp"
#include "substructs/mrzpinginfo.hpp"
#include "substructs/mrzrxinfo.hpp"
#include "substructs/mrzsectorinfo.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

class MRangeAndDepth : public KMALLMultibeamDatagram
{
    // delete unused functions
  private:
    // using KMALLMultibeamDatagram::__read_multibeamdatagram_no_mpart__;
    // using KMALLMultibeamDatagram::__size_no_mpart;
    // using KMALLMultibeamDatagram::to_stream_no_mpart;

  public:
    static constexpr auto DatagramIdentifier = t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH;

  protected:
    substructs::MRZPingInfo                _ping_info;
    std::vector<substructs::MRZSectorInfo> _tx_sectors;

    substructs::MRZRxInfo _rx_info;

    uint32_t _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                    ///< integrity check

  public:
    // ----- public constructors -----
    MRangeAndDepth();
    ~MRangeAndDepth() = default;

    // ----- convenient data access -----
    const substructs::MRZPingInfo& get_ping_info() const { return _ping_info; }
    substructs::MRZPingInfo&       ping_info() { return _ping_info; }
    void set_ping_info(const substructs::MRZPingInfo& info) { _ping_info = info; }

    // tx sectors
    const std::vector<substructs::MRZSectorInfo>& get_tx_sectors() const { return _tx_sectors; }
    std::vector<substructs::MRZSectorInfo>&       tx_sectors() { return _tx_sectors; }
    void set_tx_sectors(const std::vector<substructs::MRZSectorInfo>& sectors)
    {
        _tx_sectors = sectors;
        _ping_info.set_number_of_tx_sectors(_tx_sectors.size());
        static constexpr size_t dbytes = sizeof(substructs::MRZPingInfo) + sizeof(uint32_t);
        _ping_info.set_bytes_content(
            dbytes + _tx_sectors.size() * sizeof(substructs::MRZSectorInfo));

        set_bytes_datagram(KMALLDatagram::__size + +KMALLMultibeamDatagram::__size +
                           _ping_info.get_bytes_content());
    }

    // rx info
    const substructs::MRZRxInfo& get_rx_info() const { return _rx_info; }
    substructs::MRZRxInfo&       rx_info() { return _rx_info; }
    void                         set_rx_info(const substructs::MRZRxInfo& info) { _rx_info = info; }

    // ----- operators -----
    bool operator==(const MRangeAndDepth& other) const = default;

    //----- to/from stream functions -----
    static MRangeAndDepth from_stream(std::istream& is, const KMALLDatagram& header);

    static MRangeAndDepth from_stream(std::istream&             is,
                                      o_KMALLDatagramIdentifier datagram_identifier);

    static MRangeAndDepth from_stream(std::istream& is);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(MRangeAndDepth)

  private:
    explicit MRangeAndDepth(const KMALLDatagram& header);
    void __read_ping_info__(std::istream& is);
    void __write_ping_info__(std::ostream& os) const;
    void __read_sectors__(std::istream& is);
    void __write_sectors__(std::ostream& os) const;
    void __read_rxinfo__(std::istream& is);
    void __write_rxinfo__(std::ostream& os) const;
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
