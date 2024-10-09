// SPDX-FileCopyrightText: 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/multisectorwatercolumncalibration.doc.hpp"

#include <fmt/core.h>
#include <xtensor/xadapt.hpp>

#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/vectorinterpolators.hpp>

#include "watercolumncalibration.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace calibration {

template<typename t_calibration = WaterColumnCalibration>
class MultiSectorWaterColumnCalibration
{
  protected:
    std::vector<t_calibration> _calibration_per_sector;

    uint64_t _hash;

  public:
    MultiSectorWaterColumnCalibration() { compute_hash(); }

    MultiSectorWaterColumnCalibration(std::vector<t_calibration> calibration_per_sector)
        : _calibration_per_sector(std::move(calibration_per_sector))
    {
        compute_hash();
    }

    template<tools::helper::c_xtensor t_xtensor_2d, tools::helper::c_xtensor t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction_av(
        const t_xtensor_2d&                     wci,
        const t_xtensor_1d&                     beam_angles,
        const t_xtensor_1d&                     ranges,
        const std::vector<std::vector<size_t>>& beam_numbers_per_tx_sector) const
    {
        auto result = xt::empty_like(wci);

        for (size_t tx_sector = 0; tx_sector < beam_numbers_per_tx_sector.size(); ++tx_sector)
        {
            const auto& beam_numbers = beam_numbers_per_tx_sector[tx_sector];

            if (beam_numbers.empty())
                continue;

            if (tx_sector >= _calibration_per_sector.size())
            {
                throw std::runtime_error(
                    fmt::format("ERROR[{}]:Sector {} out of range", __func__, tx_sector));
            }

            auto beam_range = xt::range(beam_numbers.front(), beam_numbers.back() + 1);

            const auto& calibration = _calibration_per_sector[tx_sector];

            t_xtensor_1d sector_beam_angles = xt::view(beam_angles, beam_range);
            t_xtensor_2d sector_wci         = xt::view(wci, beam_range, xt::all());
            auto         sector_result      = xt::view(result, beam_range, xt::all());
            sector_result =
                calibration.apply_beam_sample_correction_av(sector_wci, sector_beam_angles, ranges);
        }

        return result;
    }

    template<tools::helper::c_xtensor t_xtensor_2d, tools::helper::c_xtensor t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction_av3(
        const t_xtensor_2d&                     wci,
        const t_xtensor_1d&                     beam_angles,
        const t_xtensor_1d&                     ranges,
        const std::vector<std::vector<size_t>>& beam_numbers_per_tx_sector) const
    {
        auto result = wci;
        for (size_t tx_sector = 0; tx_sector < beam_numbers_per_tx_sector.size(); ++tx_sector)
        {
            const auto& beam_numbers = beam_numbers_per_tx_sector[tx_sector];

            if (beam_numbers.empty())
                continue;

            if (tx_sector >= _calibration_per_sector.size())
            {
                throw std::runtime_error(
                    fmt::format("ERROR[{}]:Sector {} out of range", __func__, tx_sector));
            }

            auto beam_range = xt::range(beam_numbers.front(), beam_numbers.back() + 1);

            const auto& calibration = _calibration_per_sector[tx_sector];

            t_xtensor_1d sector_beam_angles = xt::view(beam_angles, beam_range);
            auto         sector_wci         = xt::view(result, beam_range, xt::all());
            calibration.inplace_beam_sample_correction_av(sector_wci, sector_beam_angles, ranges);
        }

        return result;
    }
    template<tools::helper::c_xtensor t_xtensor_2d, tools::helper::c_xtensor t_xtensor_1d>
    void apply_beam_sample_correction_av2(
        t_xtensor_2d                            wci,
        const t_xtensor_1d&                     beam_angles,
        const t_xtensor_1d&                     ranges,
        const std::vector<std::vector<size_t>>& beam_numbers_per_tx_sector) const
    {
        for (size_t tx_sector = 0; tx_sector < beam_numbers_per_tx_sector.size(); ++tx_sector)
        {
            const auto& beam_numbers = beam_numbers_per_tx_sector[tx_sector];

            if (beam_numbers.empty())
                continue;

            if (tx_sector >= _calibration_per_sector.size())
            {
                throw std::runtime_error(
                    fmt::format("ERROR[{}]:Sector {} out of range", __func__, tx_sector));
            }

            auto beam_range = xt::range(beam_numbers.front(), beam_numbers.back() + 1);

            const auto& calibration = _calibration_per_sector[tx_sector];

            t_xtensor_1d sector_beam_angles = xt::view(beam_angles, beam_range);
            auto         sector_wci         = xt::view(wci, beam_range, xt::all());
            calibration.inplace_beam_sample_correction_av(sector_wci, sector_beam_angles, ranges);
        }

        xt::eval(wci);
        // return wci;
    }

    size_t get_number_of_sectors() const { return _calibration_per_sector.size(); }
    auto   size() const { return _calibration_per_sector.size(); }
    auto   empty() const { return _calibration_per_sector.empty(); }

    const std::vector<t_calibration>& get_calibrations() const { return _calibration_per_sector; }

    const auto& at(size_t sector) const
    {
        if (sector >= _calibration_per_sector.size())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Sector {} out of range", __func__, sector));
        }
        return _calibration_per_sector[sector];
    }

    auto& at(size_t sector)
    {
        if (sector >= _calibration_per_sector.size())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Sector {} out of range", __func__, sector));
        }
        return _calibration_per_sector[sector];
    }

    // operator overloads
    bool operator==(const MultiSectorWaterColumnCalibration& other) const = default;

    bool initialized() const { return !_calibration_per_sector.empty(); }

    // stream i/o
    static MultiSectorWaterColumnCalibration from_stream(std::istream& is)
    {
        MultiSectorWaterColumnCalibration calibration;

        size_t number_of_sectors;
        is.read(reinterpret_cast<char*>(&number_of_sectors), sizeof(size_t));
        calibration._calibration_per_sector.resize(number_of_sectors);
        for (size_t i = 0; i < number_of_sectors; ++i)
        {
            calibration._calibration_per_sector[i] = t_calibration::from_stream(is);
        }

        return calibration;
    }

    void to_stream(std::ostream& os) const
    {
        size_t number_of_sectors = _calibration_per_sector.size();
        os.write(reinterpret_cast<const char*>(&number_of_sectors), sizeof(size_t));
        for (const auto& calibration : _calibration_per_sector)
        {
            calibration.to_stream(os);
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "MultiSectorWaterColumnCalibration", float_precision, superscript_exponents);

        printer.register_value("Number of sectors:", _calibration_per_sector.size());

        return printer;
    }

    void add_hash(boost::iostreams::stream<XXHashSink>& hash_stream) const
    {
        for (const auto& calibration : _calibration_per_sector)
        {
            calibration.add_hash(hash_stream);
        }
    }

    uint64_t                cached_hash() const { return _hash; }
    virtual xxh::hash_t<64> binary_hash() const
    {

        xxh::hash3_state_t<64>               hash;
        boost::iostreams::stream<XXHashSink> stream(hash);

        add_hash(stream);

        stream.flush();
        return hash.digest();
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NO_HASH__(MultiSectorWaterColumnCalibration)

  private:
    void compute_hash() { _hash = binary_hash(); }
};

// boost hash
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
template<typename t_calibration = WaterColumnCalibration>
inline std::size_t hash_value(const MultiSectorWaterColumnCalibration<t_calibration>& arg)
{
    return arg.cached_hash();
}
}
}
}
}
}