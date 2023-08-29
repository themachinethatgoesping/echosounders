// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/em3000pingwatercolumn.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datatypes/i_pingwatercolumn.hpp"

#include "../em3000_datagrams.hpp"
#include "../em3000_types.hpp"

#include "em3000pingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatatypes {

template<typename t_ifstream>
class EM3000PingWatercolumn
    : public filetemplates::datatypes::I_PingWatercolumn
    , public EM3000PingCommon<t_ifstream>
{
  public:
    using t_base0 = filetemplates::datatypes::I_PingCommon;
    using t_base1 = filetemplates::datatypes::I_PingWatercolumn;
    using t_base2 = EM3000PingCommon<t_ifstream>;

    using t_base2::_raw_data;
    using typename t_base2::t_rawdata;

  public:
    EM3000PingWatercolumn(std::shared_ptr<t_rawdata> raw_data)
        : t_base0("EM3000PingWatercolumn") // necessary because of virtual inheritance
        //, t_base1("EM3000PingWatercolumn"),
        , t_base2(std::move(raw_data))
    {
    }
    virtual ~EM3000PingWatercolumn() = default;

    // ----- I_PingWatercolumn interface -----
    using t_base1::has_amplitudes;
    using t_base2::raw_data;

    bool has_amplitudes() const override
    {
        return raw_data()
                   .get_datagram_infos_by_type(t_EM3000DatagramIdentifier::WatercolumnDatagram)
                   .size() > 0;
    }

    xt::xarray<float> get_amplitudes() const override { return _raw_data->read_amplitudes(); }

    xt::xarray<float> get_amplitudes(const pingtools::BeamSampleSelection& selection) const override
    {
        auto amplitudes = xt::xarray<float>::from_shape(
            { selection.get_number_of_beams(), selection.get_number_of_samples_ensemble() });

        // samples.fill(std::numeric_limits<float>::quiet_NaN());
        size_t ensemble_offset = selection.get_first_sample_number_ensemble();

        size_t output_bn = 0;

        auto& ifs = _raw_data->get_wci_ifs();

        size_t local_output_bn = 0;
        for (const auto& bn : selection.get_beam_numbers())
        {
            // read amplitudes
            auto rsr = selection.get_read_sample_range(
                local_output_bn,
                _raw_data->get_start_range_sample_numbers().unchecked(bn),
                _raw_data->get_number_of_samples_per_beam().unchecked(bn));

            if (rsr.get_number_of_samples_to_read() > 0)
            {
                xt::xtensor<int8_t, 1> beam_amplitudes = _raw_data->read_beam_samples(bn, rsr, ifs);
                xt::view(amplitudes,
                         output_bn,
                         xt::range(rsr.get_first_read_sample_offset() - ensemble_offset,
                                   rsr.get_last_read_sample_offset() + 1 - ensemble_offset)) =
                    xt::cast<float>(beam_amplitudes);
            }

            // assign nan to amplitudes that were not read
            xt::view(amplitudes,
                     output_bn,
                     xt::range(0, rsr.get_first_read_sample_offset() - ensemble_offset))
                .fill(std::numeric_limits<float>::quiet_NaN());

            using namespace xt::placeholders;
            xt::view(amplitudes,
                     output_bn,
                     xt::range(rsr.get_last_read_sample_offset() + 1 - ensemble_offset, _))
                .fill(std::numeric_limits<float>::quiet_NaN());

            ++local_output_bn;
            ++output_bn;
        }

        return amplitudes;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base1::__printer__(float_precision));

        return printer;
    }
};

}
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping