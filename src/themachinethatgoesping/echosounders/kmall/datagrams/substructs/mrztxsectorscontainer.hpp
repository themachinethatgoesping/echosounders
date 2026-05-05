// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mrztxsectorscontainer.doc.hpp"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/algorithms/signalprocessing/types.hpp>

#include "mrzsectorinfo.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

/**
 * @brief Container that stores a vector of MRZSectorInfo and exposes per-field
 *        vectorised (xtensor) accessors for fast bulk access.
 */
class MRZTxSectorsContainer
{
  public:
    MRZTxSectorsContainer()  = default;
    ~MRZTxSectorsContainer() = default;

    // ----- vector access -----
    const std::vector<MRZSectorInfo>& get_tx_sectors() const;
    std::vector<MRZSectorInfo>&       tx_sectors();
    void set_tx_sectors(const std::vector<MRZSectorInfo>& sectors);

    // ----- raw fields -----
    xt::xtensor<uint8_t, 1> get_tx_sector_number_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_tx_arrary_number_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_tx_sub_array_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_padding_0_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_sector_transmit_delay_sec_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_tilt_angle_re_tx_deg_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_tx_nominal_source_level_db_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_tx_focus_range_m_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_centre_frequency_hz_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_signal_band_width_hz_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_total_signal_length_sec_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_pulse_shading_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_signal_wave_form_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_padding_1_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_high_voltage_level_db_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_sector_tracking_corr_db_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_effective_signal_length_sec_tensor(
        const std::vector<uint32_t>& indices = {}) const;

    // ----- processed -----
    xt::xtensor<uint8_t, 1> get_tx_signal_type_tensor(
        const std::vector<uint32_t>& indices = {}) const;

    // ----- size -----
    size_t get_number_of_tx_sectors() const;

    // ----- operators -----
    bool operator==(const MRZTxSectorsContainer& other) const = default;

    // ----- printer -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<MRZSectorInfo> _tx_sectors;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&&                     getter,
                                           const std::vector<uint32_t>& indices) const
    {
        if (indices.empty())
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _tx_sectors.size() });
            for (std::size_t idx = 0; idx < _tx_sectors.size(); ++idx)
            {
                tensor.unchecked(idx) = static_cast<ValueType>(getter(_tx_sectors[idx]));
            }
            return tensor;
        }
        else
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ indices.size() });
            for (std::size_t bi = 0; bi < indices.size(); ++bi)
            {
                auto bn = indices[bi];
                if (bn >= _tx_sectors.size())
                {
                    if constexpr (std::is_floating_point_v<ValueType>)
                        tensor.unchecked(bi) = std::numeric_limits<ValueType>::quiet_NaN();
                    else
                        tensor.unchecked(bi) = ValueType{ 0 };
                }
                else
                {
                    tensor.unchecked(bi) = static_cast<ValueType>(getter(_tx_sectors[bn]));
                }
            }
            return tensor;
        }
    }
};

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
