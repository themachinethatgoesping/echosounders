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
class I_MultiSectorCalibration
{
  protected:
    I_MultiSectorCalibration() = default;

  public:
    virtual size_t get_number_of_sectors() const = 0;
    virtual bool   initialized() const { return get_number_of_sectors() > 0; }
    virtual const WaterColumnCalibration& calibration_for_sector(size_t sector) const = 0;
    virtual WaterColumnCalibration&       calibration_for_sector(size_t sector)       = 0;

    virtual ~I_MultiSectorCalibration() = default;

    bool operator==(const I_MultiSectorCalibration& other) const = default;

  public:
    template<WaterColumnCalibration::t_calibration_type calibration_type,
             tools::helper::c_xtensor                   t_xtensor_2d,
             tools::helper::c_xtensor                   t_xtensor_1d>
    void inplace_beam_sample_correction(
        [[maybe_unused]] t_xtensor_2d&          wci,
        const t_xtensor_1d&                     beam_angles,
        const t_xtensor_1d&                     ranges,
        const std::vector<std::vector<size_t>>& beam_numbers_per_tx_sector,
        int                                     mp_cores = 1) const
    {
        if (get_number_of_sectors() == 1)
        {
            calibration_for_sector(0).template inplace_beam_sample_correction<calibration_type>(
                wci, beam_angles, ranges, std::nullopt, std::nullopt, mp_cores);
            return;
        }

        for (size_t tx_sector = 0; tx_sector < beam_numbers_per_tx_sector.size(); ++tx_sector)
        {
            const auto& beam_numbers = beam_numbers_per_tx_sector[tx_sector];

            if (beam_numbers.empty())
                continue;

            if (tx_sector >= get_number_of_sectors())
            {
                throw std::runtime_error(fmt::format("ERROR[{}]:Sector nr {} out of range {}",
                                                     __func__,
                                                     tx_sector,
                                                     get_number_of_sectors()));
            }

            const auto& calibration = calibration_for_sector(tx_sector);

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

    template<WaterColumnCalibration::t_calibration_type calibration_type,
             tools::helper::c_xtensor                   t_xtensor_2d,
             tools::helper::c_xtensor                   t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction(
        const t_xtensor_2d&                     wci,
        const t_xtensor_1d&                     beam_angles,
        const t_xtensor_1d&                     ranges,
        const std::vector<std::vector<size_t>>& beam_numbers_per_tx_sector,
        int                                     mp_cores = 1) const
    {
        if (get_number_of_sectors() == 1)
        {
            return calibration_for_sector(0)
                .template apply_beam_sample_correction<calibration_type>(
                    wci, beam_angles, ranges, mp_cores);
        }

        auto result = wci;
        for (size_t tx_sector = 0; tx_sector < beam_numbers_per_tx_sector.size(); ++tx_sector)
        {
            const auto& beam_numbers = beam_numbers_per_tx_sector[tx_sector];

            if (beam_numbers.empty())
                continue;

            if (tx_sector >= get_number_of_sectors())
            {
                throw std::runtime_error(
                    fmt::format("ERROR[{}]:Sector {} out of range", __func__, tx_sector));
            }

            const auto& calibration = calibration_for_sector(tx_sector);

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
};

template<typename t_calibration>
concept t_WaterColumnCalibration = std::is_base_of_v<WaterColumnCalibration, t_calibration>;

template<t_WaterColumnCalibration t_calibration>
class T_MultiSectorCalibration : public I_MultiSectorCalibration
{
  protected:
    std::vector<t_calibration> _calibration_per_sector;

  public:
    T_MultiSectorCalibration() = default;

    T_MultiSectorCalibration(std::vector<t_calibration> calibration_per_sector)
        : I_MultiSectorCalibration()
        , _calibration_per_sector(std::move(calibration_per_sector))
    {
    }

    T_MultiSectorCalibration(const T_MultiSectorCalibration& other)
        : I_MultiSectorCalibration()
        , _calibration_per_sector(other._calibration_per_sector)
    {
    }

    T_MultiSectorCalibration& operator=(const T_MultiSectorCalibration& other)
    {
        if (this != &other)
        {
            _calibration_per_sector = other._calibration_per_sector;
        }
        return *this;
    }

    virtual ~T_MultiSectorCalibration() = default;

  public:
    size_t get_number_of_sectors() const override { return _calibration_per_sector.size(); }
    bool   initialized() const override { return !_calibration_per_sector.empty(); }
    const t_calibration& calibration_for_sector(size_t sector) const
    {
        if (sector >= get_number_of_sectors())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Sector {} out of range", __func__, sector));
        }
        return _calibration_per_sector[sector];
    }
    t_calibration& calibration_for_sector(size_t sector)
    {
        if (sector >= get_number_of_sectors())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Sector {} out of range", __func__, sector));
        }
        return _calibration_per_sector[sector];
    }

    const std::vector<t_calibration>& get_calibrations() const { return _calibration_per_sector; }

    // operator overloads
    bool operator==(const T_MultiSectorCalibration& other) const = default;

    // stream i/o
    static T_MultiSectorCalibration from_stream(std::istream& is)
    {
        T_MultiSectorCalibration calibration;

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
        size_t number_of_sectors = get_number_of_sectors();
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
            "T_MultiSectorCalibration", float_precision, superscript_exponents);

        printer.register_value("Number of sectors:", get_number_of_sectors());

        return printer;
    }

    void add_hash(boost::iostreams::stream<XXHashSink>& hash_stream) const
    {
        for (const auto& calibration : _calibration_per_sector)
        {
            calibration.add_hash(hash_stream);
        }
    }

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
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NO_HASH__(T_MultiSectorCalibration)
};

// boost hash
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
template<typename t_calibration>
inline std::size_t hash_value(const T_MultiSectorCalibration<t_calibration>& arg)
{
    return arg.binary_hash();
}

// typedefs
using MultiSectorWaterColumnCalibration = T_MultiSectorCalibration<WaterColumnCalibration>;

}
}
}
}
}