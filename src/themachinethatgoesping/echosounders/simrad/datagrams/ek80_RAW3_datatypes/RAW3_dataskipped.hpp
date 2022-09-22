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

struct RAW3_DataSkipped : public i_RAW3_Data
{
    RAW3_DataSkipped()
        : i_RAW3_Data("Skipped")
    {
    }
    ~RAW3_DataSkipped() = default;

    inline static RAW3_DataSkipped from_stream(std::istream&   is,
                                               ek60_long       count,
                                               t_RAW3_DataType data_type,
                                               uint8_t         number_of_complex_samples)
    {
        switch (data_type)
        {
            case t_RAW3_DataType::PowerAndAngle:
                is.seekg(count * RAW3_DataType_size(data_type), std::ios_base::cur);
                break;
            case t_RAW3_DataType::ComplexFloat32:
                is.seekg(count * RAW3_DataType_size(data_type) * number_of_complex_samples,
                         std::ios_base::cur);
                break;
            case t_RAW3_DataType::Power:
                is.seekg(count * RAW3_DataType_size(data_type), std::ios_base::cur);
                break;
            case t_RAW3_DataType::Angle:
                is.seekg(count * RAW3_DataType_size(data_type), std::ios_base::cur);
                break;
            case t_RAW3_DataType::ComplexFloat16:
                is.seekg(count * RAW3_DataType_size(data_type) * number_of_complex_samples,
                         std::ios_base::cur);
                break;
            default:
                throw std::runtime_error("Unknown data type");
        }

        return RAW3_DataSkipped();
    }

    inline void to_stream(std::ostream&   os,
                          ek60_long       count,
                          t_RAW3_DataType data_type,
                          uint8_t         number_of_complex_samples) const
    {
        switch (data_type)
        {
            case t_RAW3_DataType::PowerAndAngle: {
                // write _Count.size() zeros
                auto samples = std::vector<ek60_short>(count, 0);
                os.write(reinterpret_cast<char*>(samples.data()),
                         samples.size() * RAW3_DataType_size(data_type));
                break;
            }
            case t_RAW3_DataType::ComplexFloat32: {
                // write _Count.size() zeros
                auto samples =
                    std::vector<ek60_complex_float>(count * number_of_complex_samples, 0);
                os.write(reinterpret_cast<char*>(samples.data()),
                         samples.size() * RAW3_DataType_size(data_type));
                break;
            }
            case t_RAW3_DataType::Power: {
                // write _Count.size() zeros
                auto samples = std::vector<ek60_short>(count, 0);
                os.write(reinterpret_cast<char*>(samples.data()),
                         samples.size() * RAW3_DataType_size(data_type));
                break;
            }
            case t_RAW3_DataType::Angle: {
                // write _Count.size() zeros
                auto samples = std::vector<uint8_t>(count * 2, 0);
                os.write(reinterpret_cast<char*>(samples.data()),
                         samples.size() * RAW3_DataType_size(data_type));
                break;
            }
            case t_RAW3_DataType::ComplexFloat16: {
                // write _Count.size() zeros
                auto samples = std::vector<ek60_float>(count * number_of_complex_samples, 0);
                os.write(reinterpret_cast<char*>(samples.data()),
                         samples.size() * RAW3_DataType_size(data_type));
                break;
            }
            default:
                throw std::runtime_error("Unknown data type");
        }
    }
};

}
}
}
}
}