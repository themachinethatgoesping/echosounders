// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/em3000ping.doc.hpp"

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
#include <themachinethatgoesping/tools/helper/defaultsharedpointermap.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include "../../filetemplates/datatypes/i_ping.hpp"
#include "../em3000_datagrams.hpp"

#include "em3000pingbottom.hpp"
#include "em3000pingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatatypes {

template<typename t_ifstream>
class EM3000Ping
    : public filetemplates::datatypes::I_Ping
    , public EM3000PingCommon<t_ifstream>
{
    // file nr and path of primary file
    size_t      _file_nr;
    std::string _file_path;

    EM3000PingBottom<t_ifstream> _bottom;

  public:
    using t_base0 =
        filetemplates::datatypes::I_PingCommon; // this is the common ancestor which is virtually
                                                // inherited by base1 and base2
    using t_base1               = filetemplates::datatypes::I_Ping;
    using t_base2               = EM3000PingCommon<t_ifstream>;
    using type_DatagramInfo_ptr = typename EM3000PingRawData<t_ifstream>::type_DatagramInfo_ptr;

    // select virtual overrides
    using t_base1::set_channel_id;

  protected:
    using t_base2::_raw_data;
    using typename t_base2::t_rawdata;

  public:
    EM3000Ping(size_t                                   file_nr,
               std::string                              file_path,
               const datagrams::InstallationParameters& param)
        : t_base0("EM3000Ping")
        , _file_nr(file_nr)
        , _file_path(std::move(file_path))
        , _bottom(_raw_data)
    {
        /* set i_ping parameters */
        set_channel_id(param.build_channel_id());
    }
    virtual ~EM3000Ping() = default;

    // explicit copy constructor and assignment operators
    EM3000Ping(const EM3000Ping& other)
        : t_base0(other) // calling base constructor (I_PingCommon) is necessary
                         // because of virtual inheritance
        , t_base1(other)
        , t_base2(other)
        , _file_nr(other._file_nr)
        , _file_path(other._file_path)
        , _bottom(_raw_data)
    {
    }
    EM3000Ping& operator=(const EM3000Ping& other)
    {
        t_base1::operator=(other);
        t_base2::operator=(other);
        _file_nr   = other._file_nr;
        _file_path = other._file_path;
        _bottom    = EM3000PingBottom<t_ifstream>(_raw_data);
        return *this;
    }

    size_t      get_file_nr() const final { return _file_nr; }
    std::string get_file_path() const final { return _file_path; }

    void add_datagram_info(const type_DatagramInfo_ptr& datagram_info)
    {
        // update timestamp if it is much smaller or larger than the current one
        if (_timestamp < datagram_info->get_timestamp() - 1000 ||
            _timestamp > datagram_info->get_timestamp())
            _timestamp = datagram_info->get_timestamp();

        _raw_data->add_datagram_info(datagram_info);
    }

    void set_runtime_parameters(std::shared_ptr<datagrams::RuntimeParameters> runtime_parameters)
    {
        _raw_data->set_runtime_parameters(runtime_parameters);
    }

    void load_datagrams(bool skip_data = true) { _raw_data->load_datagrams(skip_data); }

    // ----- I_Ping interface -----
    using t_base1::get_beam_pointing_angles;
    using t_base1::get_number_of_beams;
    using t_base1::get_number_of_samples_per_beam;
    using t_base1::get_sv;
    using t_base1::get_sv_stacked;
    using t_base2::raw_data;

    size_t get_number_of_beams() const final { return _raw_data->get_number_of_beams(); }

    xt::xtensor<float, 1> get_beam_pointing_angles() const final
    {
        return raw_data().get_beam_pointing_angles();
    }

    xt::xtensor<float, 1> get_beam_pointing_angles(
        const pingtools::BeamSampleSelection& selection) const final
    {
        return raw_data().get_beam_pointing_angles(selection);
    }

    xt::xtensor<uint16_t, 1> get_number_of_samples_per_beam() const final
    {
        return _raw_data->get_number_of_samples_per_beam();
    }
    xt::xtensor<uint16_t, 1> get_number_of_samples_per_beam(
        const pingtools::BeamSampleSelection& selection)
    {
        return _raw_data->get_number_of_samples_per_beam(selection);
    }

    xt::xtensor<float, 2> get_sv([[maybe_unused]] bool dB = false) const final
    {
        return get_sv(_raw_data->get_beam_sample_selection_all(), dB);
    }

    xt::xtensor<float, 2> get_sv([[maybe_unused]] const pingtools::BeamSampleSelection& selection,
                                 [[maybe_unused]] bool dB = false) const final
    {
        auto samples = xt::xtensor<float, 2>::from_shape(
            { selection.get_number_of_beams(), selection.get_number_of_samples_ensemble() });
        // samples.fill(std::numeric_limits<float>::quiet_NaN());
        size_t ensemble_offset = selection.get_first_sample_number_ensemble();

        size_t output_bn = 0;

        auto& ifs = _raw_data->get_wci_ifs();

        size_t local_output_bn = 0;
        for (const auto& bn : selection.get_beam_numbers())
        {
            // read samples
            auto rsr = selection.get_read_sample_range(
                local_output_bn,
                _raw_data->get_start_range_sample_numbers().unchecked(bn),
                _raw_data->get_number_of_samples_per_beam().unchecked(bn));

            if (rsr.get_number_of_samples_to_read() > 0)
            {
                xt::xtensor<int8_t, 1> beam_samples = _raw_data->read_beam_samples(bn, rsr, ifs);
                xt::view(samples,
                         output_bn,
                         xt::range(rsr.get_first_read_sample_offset() - ensemble_offset,
                                   rsr.get_last_read_sample_offset() + 1 - ensemble_offset)) =
                    xt::cast<float>(beam_samples);
            }

            // assign nan to samples that were not read
            xt::view(samples,
                     output_bn,
                     xt::range(0, rsr.get_first_read_sample_offset() - ensemble_offset))
                .fill(std::numeric_limits<float>::quiet_NaN());

            using namespace xt::placeholders;
            xt::view(samples,
                     output_bn,
                     xt::range(rsr.get_last_read_sample_offset() + 1 - ensemble_offset, _))
                .fill(std::numeric_limits<float>::quiet_NaN());

            ++local_output_bn;
            ++output_bn;
        }

        return samples;
    }

    // ----- bottom -----
    EM3000PingBottom<t_ifstream>&       bottom() override { return _bottom; }
    const EM3000PingBottom<t_ifstream>& bottom() const override { return _bottom; }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base1::__printer__(float_precision));
        // printer.append(t_base1::__printer__(float_precision));

        // printer.register_section("EM3000 ping infos");

        // printer.register_string(
        //     "Sample data type",
        //     std::string(magic_enum::enum_name(_raw_data->_ping_data.get_data_type())));

        // printer.register_section("Important members");
        // printer.register_string("raw_data", "EM3000PingRawData");

        return printer;
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping