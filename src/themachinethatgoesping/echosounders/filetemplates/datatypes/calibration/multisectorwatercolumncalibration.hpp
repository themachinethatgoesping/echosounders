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
#include <themachinethatgoesping/echosounders/filetemplates/datatypes/cache_structures/packagecache.hpp>
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

    template<t_calibration::t_calibration_type calibration_type,
             tools::helper::c_xtensor          t_xtensor_2d,
             tools::helper::c_xtensor          t_xtensor_1d>
    void inplace_beam_sample_correction(
        [[maybe_unused]] t_xtensor_2d&          wci,
        const t_xtensor_1d&                     beam_angles,
        const t_xtensor_1d&                     ranges,
        const std::vector<std::vector<size_t>>& beam_numbers_per_tx_sector,
        int                                     mp_cores = 1) const
    {
        if (_calibration_per_sector.size() == 1)
        {
            _calibration_per_sector.at(0).template inplace_beam_sample_correction<calibration_type>(
                wci, beam_angles, ranges, std::nullopt, std::nullopt, mp_cores);
            return;
        }

        for (size_t tx_sector = 0; tx_sector < beam_numbers_per_tx_sector.size(); ++tx_sector)
        {
            const auto& beam_numbers = beam_numbers_per_tx_sector[tx_sector];

            if (beam_numbers.empty())
                continue;

            if (tx_sector >= _calibration_per_sector.size())
            {
                throw std::runtime_error(fmt::format("ERROR[{}]:Sector nr {} out of range {}",
                                                     __func__,
                                                     tx_sector,
                                                     _calibration_per_sector.size()));
            }

            const auto& calibration = _calibration_per_sector.at(tx_sector);

            t_xtensor_1d sector_beam_angles =
                xt::view(beam_angles, xt::range(beam_numbers.front(), beam_numbers.back() + 1));

            calibration.template inplace_beam_sample_correction<calibration_type>(
                wci,
                sector_beam_angles,
                ranges,
                beam_numbers.front(),
                beam_numbers.back(),
                mp_cores);
        }
    }

    template<t_calibration::t_calibration_type calibration_type,
             tools::helper::c_xtensor          t_xtensor_2d,
             tools::helper::c_xtensor          t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction(
        const t_xtensor_2d&                     wci,
        const t_xtensor_1d&                     beam_angles,
        const t_xtensor_1d&                     ranges,
        const std::vector<std::vector<size_t>>& beam_numbers_per_tx_sector,
        int                                     mp_cores = 1) const
    {
        if (_calibration_per_sector.size() == 1)
        {
            return _calibration_per_sector.at(0)
                .template apply_beam_sample_correction<calibration_type>(
                    wci, beam_angles, ranges, mp_cores);
        }

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

            const auto& calibration = _calibration_per_sector.at(tx_sector);

            t_xtensor_1d sector_beam_angles =
                xt::view(beam_angles, xt::range(beam_numbers.front(), beam_numbers.back() + 1));

            calibration.template inplace_beam_sample_correction<calibration_type>(
                result,
                sector_beam_angles,
                ranges,
                beam_numbers.front(),
                beam_numbers.back(),
                mp_cores);
        }

        return result;
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

        is.read(reinterpret_cast<char*>(&calibration._hash), sizeof(calibration._hash));

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

        os.write(reinterpret_cast<const char*>(&_hash), sizeof(_hash));
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

  public:
    // ----- functions used for PackageCache -----
    static auto from_stream(std::istream&                                  is,
                            const std::unordered_map<size_t, std::string>& hash_cache)
    {
        size_t hash;
        is.read(reinterpret_cast<char*>(&hash), sizeof(hash));

        return from_binary(hash_cache.at(hash));
    }

    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const
    {
        auto cache = this->to_binary();

        if (!hash_cache.contains(_hash))
            hash_cache[_hash] = std::move(cache);

        os.write(reinterpret_cast<const char*>(&_hash), sizeof(_hash));
    }
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