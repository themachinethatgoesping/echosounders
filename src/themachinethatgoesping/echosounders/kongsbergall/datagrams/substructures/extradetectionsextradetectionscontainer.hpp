// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/extradetectionsextradetectionscontainer.doc.hpp"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "extradetectionsextradetections.hpp"
#include "flag_detection_information.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief Container that stores a vector of ExtraDetectionsExtraDetections and
 *        exposes per-field vectorised (xtensor) accessors for fast bulk access.
 */
class ExtraDetectionsExtraDetectionsContainer
{
  public:
    ExtraDetectionsExtraDetectionsContainer()  = default;
    ~ExtraDetectionsExtraDetectionsContainer() = default;

    // ----- vector access -----
    const std::vector<ExtraDetectionsExtraDetections>& get_extra_detections() const;
    std::vector<ExtraDetectionsExtraDetections>&       extra_detections();
    void set_extra_detections(const std::vector<ExtraDetectionsExtraDetections>& detections);

    // ----- raw fields -----
    xt::xtensor<float, 1> get_depth_tensor(const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_across_tensor(const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_along_tensor(const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_delta_latitude_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_delta_longitude_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_beam_crosstrack_angle_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_applied_pointing_angle_correction_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_two_way_travel_time_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_applied_two_way_travel_time_corrections_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<int16_t, 1> get_backscatter_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<int8_t, 1> get_beam_incidence_angle_adjustment_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_detection_info_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_spare_tensor(const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_tx_sector_number_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_detection_window_length_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_quality_factor_old_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_real_time_cleaning_info_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_range_factor_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_detection_class_number_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_confidence_level_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_qf_10_tensor(const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_water_column_beam_number_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_beam_angle_across_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_detected_range_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_number_of_raw_amplitude_samples_tensor(
        const std::vector<uint32_t>& indices = {}) const;

    // ----- processed -----
    xt::xtensor<double, 1> get_qf_threshold_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<double, 1> get_backscatter_in_db_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_detection_is_valid_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_detection_type_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_backscatter_is_compensated_tensor(
        const std::vector<uint32_t>& indices = {}) const;

    // ----- size -----
    size_t get_number_of_extra_detections() const;

    // ----- operators -----
    bool operator==(const ExtraDetectionsExtraDetectionsContainer& other) const = default;

    // ----- printer -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<ExtraDetectionsExtraDetections> _extra_detections;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&&                     getter,
                                           const std::vector<uint32_t>& indices) const
    {
        if (indices.empty())
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _extra_detections.size() });
            for (std::size_t idx = 0; idx < _extra_detections.size(); ++idx)
            {
                tensor.unchecked(idx) = static_cast<ValueType>(getter(_extra_detections[idx]));
            }
            return tensor;
        }
        else
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ indices.size() });
            for (std::size_t bi = 0; bi < indices.size(); ++bi)
            {
                auto bn = indices[bi];
                if (bn >= _extra_detections.size())
                {
                    if constexpr (std::is_floating_point_v<ValueType>)
                        tensor.unchecked(bi) = std::numeric_limits<ValueType>::quiet_NaN();
                    else
                        tensor.unchecked(bi) = ValueType{ 0 };
                }
                else
                {
                    tensor.unchecked(bi) = static_cast<ValueType>(getter(_extra_detections[bn]));
                }
            }
            return tensor;
        }
    }
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
