// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <bitset>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xview.hpp>
#include <xtensor/xio.hpp>

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
    xt::xtensor<ek60_short, 1> _power; ///< Sample data

    RAW3_DataPower()
        : i_RAW3_Data("Power")
    {
    }
    RAW3_DataPower(xt::xtensor<ek60_short, 1> power)
        : i_RAW3_Data("Power")
        , _power(std::move(power))
    {
    }
    ~RAW3_DataPower() = default;

    // ----- operator overloads -----
    bool operator==(const RAW3_DataPower& other) const { return _power == other._power; }
    bool operator!=(const RAW3_DataPower& other) const { return !(operator==(other)); }

    static RAW3_DataPower from_stream(std::istream& is,
                                      ek60_long     input_count,
                                      ek60_long     output_count)
    {

        using xt_shape = xt::xtensor<ek60_short, 1>::shape_type;
        RAW3_DataPower data(xt::empty<ek60_short>(xt_shape({ unsigned(output_count) })));

        // initialize data_block using from_shape
        if (output_count < input_count)
        {
            is.read(reinterpret_cast<char*>(data._power.data()), output_count * sizeof(ek60_short));
        }
        else
        {
            is.read(reinterpret_cast<char*>(data._power.data()), input_count * sizeof(ek60_short));

            // fill remaining samples with 0
            std::fill(data._power.begin() + input_count, data._power.end(), 0);
        }

        return data;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_power.data()), _power.size() * sizeof(ek60_short));
        return;
    }


    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("Sample binary data (Power)", float_precision);

        std::stringstream ss;
        ss << _power;
        printer.register_string("Power", ss.str());

        return printer;
    }
};

}
}
}
}
}