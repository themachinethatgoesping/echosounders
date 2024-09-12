// SPDX-FileCopyrightText: 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumncalibration.doc.hpp"

#include <fmt/core.h>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/vectorinterpolators.hpp>

#include "amplitudecalibration.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace calibration {

class WaterColumnCalibration
{
    // different types of offsets
    AmplitudeCalibration _power_calibration;
    AmplitudeCalibration _sp_calibration;
    AmplitudeCalibration _sv_calibration;

    uint64_t _hash;

  public:
    WaterColumnCalibration() { compute_hash(); }
    WaterColumnCalibration(AmplitudeCalibration power_calibration,
                           AmplitudeCalibration sp_calibration,
                           AmplitudeCalibration sv_calibration)
        : _power_calibration(power_calibration)
        , _sp_calibration(sp_calibration)
        , _sv_calibration(sv_calibration)
    {
        compute_hash();
    }

    // has calibration
    bool has_power_calibration() const { return _power_calibration.initialized(); }
    bool has_sp_calibration() const { return _sp_calibration.initialized(); }
    bool has_sv_calibration() const { return _sv_calibration.initialized(); }

    // getters / setters
    const AmplitudeCalibration& get_power_calibration() const
    {
        if (!has_power_calibration())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Power calibration not initialized", __func__));
        }
        return _power_calibration;
    }
    const AmplitudeCalibration& get_sp_calibration() const
    {
        if (!has_sp_calibration())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Sp calibration not initialized", __func__));
        }
        return _sp_calibration;
    }
    const AmplitudeCalibration& get_sv_calibration() const
    {
        if (!has_sv_calibration())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Sv calibration not initialized", __func__));
        }
        return _sv_calibration;
    }
    void set_power_calibration(const AmplitudeCalibration& calibration)
    {
        _power_calibration = calibration;
        compute_hash();
    }

    void set_sp_calibration(const AmplitudeCalibration& calibration)
    {
        _sp_calibration = calibration;
        compute_hash();
    }

    void set_sv_calibration(const AmplitudeCalibration& calibration)
    {
        _sv_calibration = calibration;
        compute_hash();
    }

    // operator overloads
    bool operator==(const WaterColumnCalibration& other) const = default;

    bool initialized() const { return _hash != 3244421341483603138ULL; } // hash of default constructor

    // stream i/o
    static WaterColumnCalibration from_stream(std::istream& is)
    {
        WaterColumnCalibration calibration;

        calibration._power_calibration = AmplitudeCalibration::from_stream(is);
        calibration._sp_calibration    = AmplitudeCalibration::from_stream(is);
        calibration._sv_calibration    = AmplitudeCalibration::from_stream(is);

        return calibration;
    }

    void to_stream(std::ostream& os) const
    {
        _power_calibration.to_stream(os);
        _sp_calibration.to_stream(os);
        _sv_calibration.to_stream(os);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("WaterColumnCalibration", float_precision);

        printer.register_section("Power Calibration");
        printer.append(_power_calibration.__printer__(float_precision));
        printer.register_section("Sp Calibration (uncompensated TS)");
        printer.append(_sp_calibration.__printer__(float_precision));
        printer.register_section("Sv Calibration (Volume scattering)");
        printer.append(_sv_calibration.__printer__(float_precision));

        return printer;
    }

    uint64_t        cached_hash() const { return _hash; }
    xxh::hash_t<64> binary_hash() const
    {

        xxh::hash3_state_t<64>               hash;
        boost::iostreams::stream<XXHashSink> stream(hash);

        _power_calibration.add_hash(stream);
        _sp_calibration.add_hash(stream);
        _sv_calibration.add_hash(stream);

        stream.flush();
        return hash.digest();
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NO_HASH__(WaterColumnCalibration)

  private:
    void compute_hash() { _hash = binary_hash(); }
};

// boost hash
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const WaterColumnCalibration& arg)
{
    return arg.cached_hash();
}

}
}
}
}
}