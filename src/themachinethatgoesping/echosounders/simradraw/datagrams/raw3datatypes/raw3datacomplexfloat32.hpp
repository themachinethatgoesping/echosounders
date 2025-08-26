// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/raw3datacomplexfloat32.doc.hpp"

// std includes
#include <string>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>

#include <Eigen/Core>
#include <Eigen/Dense>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "i_raw3data.hpp"
#include "t_raw3datatype.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace raw3datatypes {

struct RAW3DataComplexFloat32 : public i_RAW3Data
{
    // axis[0] = first sample
    // axis[0][0] = first sample, first channel
    // axis[0][0][0] = first sample, first channel, real part
    // axis[0][0][1] = first sample, first channel, imaginary part
    // note: storage order is real/imaginary, real/imaginary, ... for each channel for each sample
    xt::xtensor<simradraw_float, 3> _complex_samples; ///< Sample data

    RAW3DataComplexFloat32()
        : i_RAW3Data("ComplexFloat32")
    {
    }
    RAW3DataComplexFloat32(xt::xtensor<simradraw_float, 3> complex_samples)
        : i_RAW3Data("ComplexFloat32")
        , _complex_samples(std::move(complex_samples))
    {
    }
    ~RAW3DataComplexFloat32() = default;

    // ----- i_RAW3Data interface -----
    bool has_power() const final { return true; }
    bool has_angle() const final { return true; }

    xt::xtensor<simradraw_float, 4> get_complex_samples_bfloat16(size_t max_samples);

    xt::xtensor<simradraw_float, 1> get_power_xtensor(bool dB = false) const;

    xt::xtensor<simradraw_float, 1> get_coherent_sum(bool dB = false) const;

    xt::xtensor<simradraw_float, 1> get_incoherent_sum_xtensor(bool dB = false) const;
    xt::xtensor<simradraw_float, 1> get_incoherent_sum(bool dB = false) const;

    // strictly speaking: this is not the power, but the sum of the squares of the real and
    // imaginary To get the power, the impedance factor has to be applied
    xt::xtensor<simradraw_float, 1> get_power(bool dB = false) const final;

    xt::xtensor<simradraw_float, 2> get_angle() const final;

    // ----- operator overloads -----
    bool operator==(const RAW3DataComplexFloat32& other) const
    {
        return _complex_samples == other._complex_samples;
    }
    bool operator!=(const RAW3DataComplexFloat32& other) const { return !(operator==(other)); }

    // ----- to/from stream -----
    static RAW3DataComplexFloat32 from_stream(std::istream&  is,
                                              simradraw_long input_count,
                                              simradraw_long output_count,
                                              uint8_t        number_of_complex_samples);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;
};
}
}
}
}
}