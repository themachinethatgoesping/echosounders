// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>

#include "i_RAW3_data.hpp"
#include "t_RAW3_datatype.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {
namespace RAW3_datatypes {

struct RAW3_DataComplexFloat32 : public i_RAW3_Data
{
    xt::xarray<ek60_complex_float> _complex_samples; ///< Sample data

    RAW3_DataComplexFloat32()
        : i_RAW3_Data("ComplexFloat32")
    {
    }
    ~RAW3_DataComplexFloat32() = default;

    inline static RAW3_DataComplexFloat32 from_stream(std::istream& is,
                                                      ek60_long     input_count,
                                                      ek60_long     output_count,
                                                      uint8_t       number_of_complex_samples)
    {
        // (void)(output_count);
        RAW3_DataComplexFloat32 data;

        data._complex_samples.resize({ number_of_complex_samples, unsigned(output_count) }, 0);

        // initialize data_block using from_shape
        if (output_count < input_count)
        {
            is.read(reinterpret_cast<char*>(data._complex_samples.data()),
                    output_count * number_of_complex_samples * sizeof(ek60_complex_float));
        }
        else
        {
            is.read(reinterpret_cast<char*>(data._complex_samples.data()),
                    input_count * number_of_complex_samples * sizeof(ek60_complex_float));
        }

        return data;
    }

    inline void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_complex_samples.data()),
                 _complex_samples.size() * sizeof(ek60_complex_float));
        return;
    }
};

}
}
}
}
}