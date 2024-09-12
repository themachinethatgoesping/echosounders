// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/amplitudecalibration.doc.hpp"

#include <fmt/core.h>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/vectorinterpolators.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace calibration {

class AmplitudeCalibration
{
    // system offsets
    float _system_offset = std::numeric_limits<float>::quiet_NaN();
    tools::vectorinterpolators::AkimaInterpolator<float> _offset_per_beamangle;
    // tools::vectorinterpolators::AkimaInterpolator _offset_per_swathangle; implement in the future
    tools::vectorinterpolators::AkimaInterpolator<float> _offset_per_range;

    uint64_t _hash;

  public:
    AmplitudeCalibration() { compute_hash(); }
    AmplitudeCalibration(float system_offset)
        : _system_offset(system_offset)
    {
        compute_hash();
    }

    // operator overloads
    bool operator==(const AmplitudeCalibration& other) const
    {
        if (_offset_per_beamangle != other._offset_per_beamangle)
            return false;

        if (_offset_per_range != other._offset_per_range)
            return false;

        if (std::isnan(_system_offset) && std::isnan(other._system_offset))
            return true;

        if (_system_offset == other._system_offset)
            return true;

        return false;
    }
    bool initialized() const { return _hash != 3244421341483603138ULL; } // hash of default constructor

    // getters / setters
    float get_system_offset() const { return _system_offset; }
    void  set_system_offset(float value)
    {
        _system_offset = value;
        compute_hash();
    }

    void set_offset_per_beamangle(const std::vector<float>& beamangle,
                                  const std::vector<float>& offset)
    {
        _offset_per_beamangle.set_data_XY(beamangle, offset);
        compute_hash();
    }

    void set_offset_per_range(const std::vector<float>& range, const std::vector<float>& offset)
    {
        _offset_per_range.set_data_XY(range, offset);
        compute_hash();
    }

    // interpolator access
    bool has_offset_per_beamangle() const { return !_offset_per_beamangle.empty(); }
    bool has_offset_per_range() const { return !_offset_per_range.empty(); }
    bool has_system_offset() const { return !std::isnan(_system_offset); }

    const auto& get_interpolator_offset_per_beamangle() const { return _offset_per_beamangle; }
    const auto& get_interpolator_offset_per_range() const { return _offset_per_range; }

    auto get_offset_per_beamangle(const std::vector<float>& beamangles)
    {
        return _offset_per_beamangle(beamangles);
    }

    auto get_offset_per_beamangle(float beamangle) { return _offset_per_beamangle(beamangle); }

    auto get_offset_per_range(const std::vector<float>& ranges)
    {
        return _offset_per_range(ranges);
    }

    auto get_offset_per_range(float range) { return _offset_per_range(range); }

    static AmplitudeCalibration from_stream(std::istream& is)
    {
        AmplitudeCalibration calibration;

        is.read(reinterpret_cast<char*>(&calibration._system_offset), sizeof(float));

        calibration._offset_per_beamangle = calibration._offset_per_beamangle.from_stream(is);
        calibration._offset_per_range     = calibration._offset_per_range.from_stream(is);

        calibration.compute_hash();
        return calibration;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&_system_offset), sizeof(float));

        _offset_per_beamangle.to_stream(os);
        _offset_per_range.to_stream(os);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("AmplitudeCalibration", float_precision);

        printer.register_section("System offsets");
        if (!std::isnan(_system_offset))
            printer.register_value("system_offset", _system_offset);
        if (!_offset_per_beamangle.empty())
            printer.append(_offset_per_beamangle.__printer__(float_precision));
        if (!_offset_per_range.empty())
            printer.append(_offset_per_range.__printer__(float_precision));

        return printer;
    }

    uint64_t cached_hash() const { return _hash; }
    xxh::hash_t<64> binary_hash() const
    {
        xxh::hash3_state_t<64>               hash;
        boost::iostreams::stream<XXHashSink> stream(hash);

        add_hash(stream);

        stream.flush();
        return hash.digest();
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NO_HASH__(AmplitudeCalibration)

    void add_hash(boost::iostreams::stream<XXHashSink>& hash_stream) const
    {
        if (has_system_offset())
            hash_stream.write(reinterpret_cast<const char*>(&_system_offset), sizeof(float));

        if (has_offset_per_beamangle())
            _offset_per_beamangle.to_stream(hash_stream);

        if (has_offset_per_range())
            _offset_per_range.to_stream(hash_stream);
    }

  private:
    void compute_hash() { _hash = binary_hash(); }
};

// boost hash
// IGNORE_DOC:
// __doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const AmplitudeCalibration& arg)
{
    return arg.cached_hash();
}

}
}
}
}
}
