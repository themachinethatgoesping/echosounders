// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/raw3datacomplexfloat32.doc.hpp"

// std includes
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>

#include "i_raw3data.hpp"
#include "t_raw3datatype.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace raw3datatypes {

struct RAW3DataComplexFloat32 : public i_RAW3Data
{
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

    xt::xtensor<simradraw_float, 1> get_power(bool dB = false) const final
    {
        // ToDo: can this be done faster? (it is pretty fast already, so benchmark first)
        // auto r1 = xt::eval(xt::sum(_complex_samples, 0));
        auto r1 = xt::eval(xt::sum(_complex_samples, 1));

        if (!dB)
        {
            return xt::xtensor<simradraw_float, 1>(xt::eval(xt::sum(xt::eval(r1 * r1), 1)));
        }
        else
        {
            auto r2 = xt::eval(xt::sum(xt::eval(r1 * r1), 1));
            return xt::xtensor<simradraw_float, 1>(xt::eval(10.f * xt::log10(r2)));
        }
    }
    xt::xtensor<simradraw_float, 2> get_angle() const final
    {
        throw std::runtime_error("get_angle() not yet implemented for " + std::string(class_name()));
    }

    // ----- operator overloads -----
    bool operator==(const RAW3DataComplexFloat32& other) const
    {
        return _complex_samples == other._complex_samples;
    }
    bool operator!=(const RAW3DataComplexFloat32& other) const { return !(operator==(other)); }

    // ----- to/from stream -----
    static RAW3DataComplexFloat32 from_stream(std::istream& is,
                                              simradraw_long   input_count,
                                              simradraw_long   output_count,
                                              uint8_t       number_of_complex_samples)
    {
        using xt_shape = xt::xtensor<simradraw_float, 3>::shape_type;
        RAW3DataComplexFloat32 data(xt::empty<simradraw_float>(
            xt_shape({ unsigned(output_count), number_of_complex_samples, 2 })));
        // RAW3DataComplexFloat32 data(xt::empty<simradraw_float>(
        //     xt_shape({ number_of_complex_samples, 2, unsigned(output_count) })));

        // initialize data_block using from_shape
        if (output_count <= input_count)
        {
            is.read(reinterpret_cast<char*>(data._complex_samples.data()),
                    output_count * 2 * number_of_complex_samples * sizeof(simradraw_float));
        }
        else
        {
            is.read(reinterpret_cast<char*>(data._complex_samples.data()),
                    input_count * 2 * number_of_complex_samples * sizeof(simradraw_float));

            // fill remaining samples with quiet NaN
            std::fill(data._complex_samples.begin() + input_count * 2 * number_of_complex_samples,
                      data._complex_samples.end(),
                      std::numeric_limits<simradraw_float>::quiet_NaN());
        }

        return data;
    }

    void to_stream(std::ostream& os) const
    {

        os.write(reinterpret_cast<const char*>(_complex_samples.data()),
                 _complex_samples.size() * sizeof(simradraw_float));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("Sample binary data (ComplexFloat32)",
                                                  float_precision);

        std::stringstream ss;
        ss << _complex_samples;
        printer.register_string("complex_samples", ss.str());

        return printer;
    }
};

}
}
}
}
}