// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mwcrxbeamdatacontainer.doc.hpp"

#include <cstddef>
#include <cstdint>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "mwcrxbeamdata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

class MWCRxBeamDataContainer
{
  public:
    MWCRxBeamDataContainer()  = default;
    ~MWCRxBeamDataContainer() = default;

    const std::vector<MWCRxBeamData>& get_beams() const;
    std::vector<MWCRxBeamData>&       beams();
    void                              set_beams(const std::vector<MWCRxBeamData>& beams);

    xt::xtensor<float, 1>    get_beam_pointing_angle_re_vertical_deg_tensor() const;
    xt::xtensor<uint16_t, 1> get_start_range_sample_number_tensor() const;
    xt::xtensor<uint16_t, 1> get_detected_range_in_samples_tensor() const;
    xt::xtensor<uint16_t, 1> get_transmit_sector_number_tensor() const;
    xt::xtensor<uint16_t, 1> get_number_of_samples_tensor() const;
    xt::xtensor<float, 1>    get_detected_range_in_samples_high_resolution_tensor() const;

    size_t get_number_of_beams() const;
    size_t get_total_number_of_samples() const;

    bool operator==(const MWCRxBeamDataContainer& other) const = default;

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<MWCRxBeamData> _beams;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&& getter) const
    {
        auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _beams.size() });
        for (std::size_t idx = 0; idx < _beams.size(); ++idx)
            tensor.unchecked(idx) = static_cast<ValueType>(getter(_beams[idx]));
        return tensor;
    }
};

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
