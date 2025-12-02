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
    substructs::MWCTxInfo _tx_info;
    // std::vector<substructs::MRZSectorInfo>        _tx_sectors;
    // substructs::MRZRxInfo                         _rx_info;
    // std::vector<substructs::MRZExtraDetClassInfo> _extra_det_class_info;
    // substructs::MRZSoundingsContainer             _soundings;
    // xt::xtensor<int16_t, 1>                       _seabed_image_samples_dezi_db;

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
    // const std::vector<substructs::MRZSectorInfo>& get_tx_sectors() const { return _tx_sectors; }
    // std::vector<substructs::MRZSectorInfo>&       tx_sectors() { return _tx_sectors; }
    // void set_tx_sectors(const std::vector<substructs::MRZSectorInfo>& sectors)
    // {
    //     _tx_sectors = sectors;
    //     _ping_info.set_number_of_tx_sectors(_tx_sectors.size());
    //     static constexpr size_t dbytes = sizeof(substructs::MRZPingInfo) + sizeof(uint32_t);
    //     _ping_info.set_bytes_content(dbytes +
    //                                  _tx_sectors.size() * sizeof(substructs::MRZSectorInfo));

    //     set_bytes_datagram(KMALLDatagram::__size + +KMALLMultibeamDatagram::__size +
    //                        _ping_info.get_bytes_content());
    // }

    // // rx info
    // const substructs::MRZRxInfo& get_rx_info() const { return _rx_info; }
    // substructs::MRZRxInfo&       rx_info() { return _rx_info; }
    // void                         set_rx_info(const substructs::MRZRxInfo& info) { _rx_info =
    // info; }

    // const std::vector<substructs::MRZExtraDetClassInfo>& get_extra_det_class_info() const
    // {
    //     return _extra_det_class_info;
    // }
    // std::vector<substructs::MRZExtraDetClassInfo>& extra_det_class_info()
    // {
    //     return _extra_det_class_info;
    // }
    // void set_extra_det_class_info(const std::vector<substructs::MRZExtraDetClassInfo>& info)
    // {
    //     _extra_det_class_info = info;
    // }

    // // soundings
    // const substructs::MRZSoundingsContainer& get_soundings() const { return _soundings; }
    // substructs::MRZSoundingsContainer&       soundings() { return _soundings; }
    // void set_soundings(const substructs::MRZSoundingsContainer& soundings)
    // {
    //     _soundings = soundings;
    // }

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

    //----- to/from stream functions -----
    static MWaterColumn from_stream(std::istream& is, const KMALLDatagram& header);

    static MWaterColumn from_stream(std::istream&             is,
                                    o_KMALLDatagramIdentifier datagram_identifier);

    static MWaterColumn from_stream(std::istream& is);

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
    // void __read_sectors__(std::istream& is);
    // void __write_sectors__(std::ostream& os) const;
    // void __read_rxinfo__(std::istream& is);
    // void __write_rxinfo__(std::ostream& os) const;
    // void __read_extradetclassinfo__(std::istream& is);
    // void __write_extradetclassinfo__(std::ostream& os) const;
    // void __read_soundings__(std::istream& is);
    // void __write_soundings__(std::ostream& os) const;
    // void __read_seabed_image_samples__(std::istream& is);
    // void __write_seabed_image_samples__(std::ostream& os) const;
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
