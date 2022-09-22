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

struct RAW3_DataPower : public i_RAW3_Data
{
    xt::xarray<ek60_short> _power; ///< Sample data

    RAW3_DataPower()
        : i_RAW3_Data("Power")
    {
    }
    ~RAW3_DataPower() = default;

    inline static RAW3_DataPower from_stream(std::istream& is,
                                             ek60_long     input_count,
                                             ek60_long     output_count)
    {
        // (void)(output_count);
        RAW3_DataPower data;

        data._power.resize({ unsigned(output_count) }, 0);

        // initialize data_block using from_shape
        if (output_count < input_count)
        {
            is.read(reinterpret_cast<char*>(data._power.data()), output_count * sizeof(ek60_short));
        }
        else
        {
            is.read(reinterpret_cast<char*>(data._power.data()), input_count * sizeof(ek60_short));
        }

        return data;
    }

    inline void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_power.data()), _power.size() * sizeof(ek60_short));
        return;
    }
};

}
}
}
}
}