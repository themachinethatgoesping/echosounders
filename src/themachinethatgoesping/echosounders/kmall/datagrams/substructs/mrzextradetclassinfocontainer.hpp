// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mrzextradetclassinfocontainer.doc.hpp"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "mrzextradetclassinfo.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

/**
 * @brief Container that stores a vector of MRZExtraDetClassInfo and exposes per-field
 *        vectorised (xtensor) accessors.
 */
class MRZExtraDetClassInfoContainer
{
  public:
    MRZExtraDetClassInfoContainer()  = default;
    ~MRZExtraDetClassInfoContainer() = default;

    // ----- vector access -----
    const std::vector<MRZExtraDetClassInfo>& get_extra_det_class_info() const;
    std::vector<MRZExtraDetClassInfo>&       extra_det_class_info();
    void set_extra_det_class_info(const std::vector<MRZExtraDetClassInfo>& info);

    // ----- raw fields -----
    xt::xtensor<uint16_t, 1> get_num_extra_det_in_class_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<int8_t, 1> get_padding_tensor(const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint8_t, 1> get_alarm_flag_tensor(
        const std::vector<uint32_t>& indices = {}) const;

    // ----- size -----
    size_t get_number_of_extra_det_class_info() const;

    // ----- operators -----
    bool operator==(const MRZExtraDetClassInfoContainer& other) const = default;

    // ----- printer -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<MRZExtraDetClassInfo> _extra_det_class_info;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&&                     getter,
                                           const std::vector<uint32_t>& indices) const
    {
        if (indices.empty())
        {
            auto tensor =
                xt::xtensor<ValueType, 1>::from_shape({ _extra_det_class_info.size() });
            for (std::size_t idx = 0; idx < _extra_det_class_info.size(); ++idx)
            {
                tensor.unchecked(idx) = static_cast<ValueType>(getter(_extra_det_class_info[idx]));
            }
            return tensor;
        }
        else
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ indices.size() });
            for (std::size_t bi = 0; bi < indices.size(); ++bi)
            {
                auto bn = indices[bi];
                if (bn >= _extra_det_class_info.size())
                {
                    if constexpr (std::is_floating_point_v<ValueType>)
                        tensor.unchecked(bi) = std::numeric_limits<ValueType>::quiet_NaN();
                    else
                        tensor.unchecked(bi) = ValueType{ 0 };
                }
                else
                {
                    tensor.unchecked(bi) =
                        static_cast<ValueType>(getter(_extra_det_class_info[bn]));
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
