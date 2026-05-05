// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/extradetectionsdetectionclassescontainer.doc.hpp"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "extradetectionsdetectionclasses.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief Container that stores a vector of ExtraDetectionsDetectionClasses and exposes
 *        per-field vectorised (xtensor) accessors for fast bulk access.
 */
class ExtraDetectionsDetectionClassesContainer
{
  public:
    ExtraDetectionsDetectionClassesContainer()  = default;
    ~ExtraDetectionsDetectionClassesContainer() = default;

    // ----- vector access -----
    const std::vector<ExtraDetectionsDetectionClasses>& get_detection_classes() const;
    std::vector<ExtraDetectionsDetectionClasses>&       detection_classes();
    void set_detection_classes(const std::vector<ExtraDetectionsDetectionClasses>& classes);

    // ----- raw fields -----
    xt::xtensor<uint16_t, 1> get_start_depth_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_stop_depth_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_qf_threshold_100_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<int16_t, 1> get_bs_threshold_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_snr_threshold_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_alarm_threshold_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_number_of_extra_detections_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_show_class_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_alarm_flag_1_tensor(
        const std::vector<uint32_t>& indices = {}) const;

    // ----- processed -----
    xt::xtensor<double, 1> get_qf_threshold_tensor(
        const std::vector<uint32_t>& indices = {}) const;

    // ----- size -----
    size_t get_number_of_detection_classes() const;

    // ----- operators -----
    bool operator==(const ExtraDetectionsDetectionClassesContainer& other) const = default;

    // ----- printer -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<ExtraDetectionsDetectionClasses> _detection_classes;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&&                     getter,
                                           const std::vector<uint32_t>& indices) const
    {
        if (indices.empty())
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _detection_classes.size() });
            for (std::size_t idx = 0; idx < _detection_classes.size(); ++idx)
            {
                tensor.unchecked(idx) = static_cast<ValueType>(getter(_detection_classes[idx]));
            }
            return tensor;
        }
        else
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ indices.size() });
            for (std::size_t bi = 0; bi < indices.size(); ++bi)
            {
                auto bn = indices[bi];
                if (bn >= _detection_classes.size())
                {
                    if constexpr (std::is_floating_point_v<ValueType>)
                        tensor.unchecked(bi) = std::numeric_limits<ValueType>::quiet_NaN();
                    else
                        tensor.unchecked(bi) = ValueType{ 0 };
                }
                else
                {
                    tensor.unchecked(bi) = static_cast<ValueType>(getter(_detection_classes[bn]));
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
