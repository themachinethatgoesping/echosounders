// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
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

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace calibration {

class WaterColumnCalibration
{
    // system offsets
    float                                         _system_offset = 0.0f;
    tools::vectorinterpolators::AkimaInterpolator _offset_per_beamangle;
    // tools::vectorinterpolators::AkimaInterpolator _offset_per_swathangle; implement in the future
    tools::vectorinterpolators::AkimaInterpolator _offset_per_range;

    // environment offsets
    tools::vectorinterpolators::AkimaInterpolator _absorption_per_depth;

  public:
    WaterColumnCalibration() = default;
    WaterColumnCalibration(
        float                                                       system_offset = 0.0f,
        const tools::vectorinterpolators::AkimaInterpolator<float>& offset_per_beamangle =
            tools::vectorinterpolators::AkimaInterpolator(),
        const tools::vectorinterpolators::AkimaInterpolator<float>& offset_per_range =
            tools::vectorinterpolators::AkimaInterpolator(),
        const tools::vectorinterpolators::AkimaInterpolator<float>& _absorption_per_depth =
            tools::vectorinterpolators::AkimaInterpolator())
        : _system_offset(system_offset)
        , _offset_per_beamangle(offset_per_beamangle)
        , _offset_per_range(offset_per_range)
        , _absorption_per_depth(_absorption_per_depth)
    {
    }

    // operator overloads
    WaterColumnCalibration& operator=(const WaterColumnCalibration&) = default;

    // getters / setters
    float get_system_offset() const { return _system_offset; }
    void  set_system_offset(float value) { _system_offset = value; }

    void set_offset_per_beamangle(const std::vector<float>& beamangle,
                                  const std::vector<float>& offset)
    {
        _offset_per_beamangle.set_data(beamangle, offset);
    }

    void set_offset_per_range(const std::vector<float>& range, const std::vector<float>& offset)
    {
        _offset_per_range.set_data(range, offset);
    }

    void set_absorption_per_depth(const std::vector<float>& depth, const std::vector<float>& absorption)
    {
        _absorption_per_depth.set_data(depth, absorption);
    }

    // interpolator access
    const tools::vectorinterpolators::AkimaInterpolator& get_interpolator_offset_per_beamangle()
        const
    {
        return _offset_per_beamangle;
    }
    const tools::vectorinterpolators::AkimaInterpolator& get_interpolator_offset_per_range() const
    {
        return _offset_per_range;
    }
    const tools::vectorinterpolators::AkimaInterpolator& get_interpolator_absorption_per_depth()
        const
    {
        return _absorption_coefficient_per_depth;
    }

    auto get_offset_per_beamangle(const std::vector<float>& beamangles) const
    {
        return _offset_per_beamangle(beamangles);
    }

    auto get_offset_per_range(const std::vector<float>& ranges) const
    {
        return _offset_per_range(ranges);
    }

    auto get_absorption_per_depth(const std::vector<float>& depths) const
    {
        return _absorption_per_depth(depths);
    }
};
}
}
}
}
}
