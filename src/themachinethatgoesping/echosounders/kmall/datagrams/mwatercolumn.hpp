// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mwatercolumn.doc.hpp"

// std includes
#include <cstdint>
#include <string>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "kmallmultibeamdatagram.hpp"
#include "substructs/mwcrxbeamdatacontainer.hpp"
#include "substructs/mwcrxinfo.hpp"
#include "substructs/mwcsectorinfo.hpp"
#include "substructs/mwctxinfo.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

class MWaterColumn : public KMALLMultibeamDatagram
{
    // delete unused functions
  private:
    // using KMALLMultibeamDatagram::__read_multibeamdatagram_no_mpart__;
    // using KMALLMultibeamDatagram::__size_no_mpart;
    // using KMALLMultibeamDatagram::to_stream_no_mpart;

  public:
    static constexpr auto DatagramIdentifier = t_KMALLDatagramIdentifier::M_WATER_COLUMN;

  protected:
    substructs::MWCTxInfo                  _tx_info;
    std::vector<substructs::MWCSectorInfo> _tx_sectors;
    substructs::MWCRxInfo                  _rx_info;
    substructs::MWCRxBeamDataContainer     _beam_data;

    uint32_t _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                    ///< integrity check

  public:
    // ----- public constructors -----
    MWaterColumn();
    ~MWaterColumn() = default;

    // ----- convenient data access -----
    const substructs::MWCTxInfo& get_tx_info() const { return _tx_info; }
    substructs::MWCTxInfo&       tx_info() { return _tx_info; }
    void                         set_tx_info(const substructs::MWCTxInfo& info) { _tx_info = info; }

    // // tx sectors
    const std::vector<substructs::MWCSectorInfo>& get_tx_sectors() const { return _tx_sectors; }
    std::vector<substructs::MWCSectorInfo>&       tx_sectors() { return _tx_sectors; }
    void set_tx_sectors(const std::vector<substructs::MWCSectorInfo>& sectors)
    {
        _tx_sectors = sectors;
        _tx_info.set_number_of_tx_sectors(_tx_sectors.size());
        static constexpr size_t dbytes = sizeof(substructs::MWCTxInfo) + sizeof(uint32_t);
        _tx_info.set_bytes_content(dbytes + _tx_sectors.size() * sizeof(substructs::MWCSectorInfo));

        set_bytes_datagram(KMALLDatagram::__size + +KMALLMultibeamDatagram::__size +
                           _tx_info.get_bytes_content());
    }

    // // rx info
    const substructs::MWCRxInfo& get_rx_info() const { return _rx_info; }
    substructs::MWCRxInfo&       rx_info() { return _rx_info; }
    void                         set_rx_info(const substructs::MWCRxInfo& info) { _rx_info = info; }

    // beam data
    const substructs::MWCRxBeamDataContainer& get_beam_data() const { return _beam_data; }
    substructs::MWCRxBeamDataContainer&       beam_data() { return _beam_data; }
    void set_beam_data(const substructs::MWCRxBeamDataContainer& beam_data)
    {
        _beam_data = beam_data;
        _rx_info.set_number_of_beams(_beam_data.get_beams().size());
    }

    // // seabed image samples
    // const xt::xtensor<int16_t, 1>& get_seabed_image_samples_dezi_db() const
    // {
    //     return _seabed_image_samples_dezi_db;
    // }
    // void set_seabed_image_samples_dezi_db(const xt::xtensor<int16_t, 1>& samples)
    // {
    //     _seabed_image_samples_dezi_db = samples;
    // }
    // const xt::xtensor<float, 1> get_seabed_image_samples_db() const
    // {
    //     return _seabed_image_samples_dezi_db * 0.1f;
    // }
    // void set_seabed_image_samples_db(const xt::xtensor<float, 1>& samples)
    // {
    //     _seabed_image_samples_dezi_db = xt::cast<int16_t>(xt::round(samples * 10.0f));
    // }

    // ----- operators -----
    bool operator==(const MWaterColumn& other) const = default;

    uint32_t get_bytes_datagram_check() const { return _bytes_datagram_check; }
    void     set_bytes_datagram_check(uint32_t bytes_datagram_check)
    {
      _bytes_datagram_check = bytes_datagram_check;
    }

    //----- to/from stream functions -----
    static MWaterColumn from_stream(std::istream&        is,
                                    const KMALLDatagram& header,
                                    bool                 skip_data = false);

    static MWaterColumn from_stream(std::istream&             is,
                                    o_KMALLDatagramIdentifier datagram_identifier,
                                    bool                      skip_data = false);

    static MWaterColumn from_stream(std::istream& is, bool skip_data = false);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(MWaterColumn)

  private:
    explicit MWaterColumn(const KMALLDatagram& header);
    void __read_tx_info__(std::istream& is);
    void __write_tx_info__(std::ostream& os) const;
    void __read_sectors__(std::istream& is);
    void __write_sectors__(std::ostream& os) const;
    void __read_rxinfo__(std::istream& is);
    void __write_rxinfo__(std::ostream& os) const;
    void __read_beamdata__(std::istream& is, bool skip_data = false);
    void __write_beamdata__(std::ostream& os) const;
    // void __read_soundings__(std::istream& is);
    // void __write_soundings__(std::ostream& os) const;
    // void __read_seabed_image_samples__(std::istream& is);
    // void __write_seabed_image_samples__(std::ostream& os) const;
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
