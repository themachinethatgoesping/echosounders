// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "raw3dataskipped.hpp"

#include <vector>
#include <stdexcept>
#include <ios>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace raw3datatypes {

RAW3DataSkipped RAW3DataSkipped::from_stream(std::istream&  is,
                                   simradraw_long    count,
                                   t_RAW3DataType data_type,
                                   uint8_t        number_of_complex_samples)
{
    switch (data_type)
    {
        case t_RAW3DataType::PowerAndAngle:
            is.seekg(count * get_raw3datatype_size(data_type), std::ios_base::cur);
            break;
        case t_RAW3DataType::ComplexFloat32:
            is.seekg(count * get_raw3datatype_size(data_type) * number_of_complex_samples,
                     std::ios_base::cur);
            break;
        case t_RAW3DataType::Power:
            is.seekg(count * get_raw3datatype_size(data_type), std::ios_base::cur);
            break;
        case t_RAW3DataType::Angle:
            is.seekg(count * get_raw3datatype_size(data_type), std::ios_base::cur);
            break;
        case t_RAW3DataType::ComplexFloat16:
            is.seekg(count * get_raw3datatype_size(data_type) * number_of_complex_samples,
                     std::ios_base::cur);
            break;
        default:
            throw std::runtime_error("Unknown data type");
    }

    return RAW3DataSkipped();
}

void RAW3DataSkipped::to_stream(std::ostream&  os,
               simradraw_long    count,
               t_RAW3DataType data_type,
               uint8_t        number_of_complex_samples) const
{
    switch (data_type)
    {
        case t_RAW3DataType::PowerAndAngle: {
            // write _count.size() zeros
            auto samples = std::vector<simradraw_short>(count, 0);
            os.write(reinterpret_cast<const char*>(samples.data()),
                     samples.size() * get_raw3datatype_size(data_type));
            break;
        }
        case t_RAW3DataType::ComplexFloat32: {
            // write _count.size() zeros
            auto samples =
                std::vector<simradraw_complex_float>(count * number_of_complex_samples, 0);
            os.write(reinterpret_cast<const char*>(samples.data()),
                     samples.size() * get_raw3datatype_size(data_type));
            break;
        }
        case t_RAW3DataType::Power: {
            // write _count.size() zeros
            auto samples = std::vector<simradraw_short>(count, 0);
            os.write(reinterpret_cast<const char*>(samples.data()),
                     samples.size() * get_raw3datatype_size(data_type));
            break;
        }
        case t_RAW3DataType::Angle: {
            // write _count.size() zeros
            auto samples = std::vector<uint8_t>(count * 2, 0);
            os.write(reinterpret_cast<const char*>(samples.data()),
                     samples.size() * get_raw3datatype_size(data_type));
            break;
        }
        case t_RAW3DataType::ComplexFloat16: {
            // write _count.size() zeros
            auto samples = std::vector<simradraw_float>(count * number_of_complex_samples, 0);
            os.write(reinterpret_cast<const char*>(samples.data()),
                     samples.size() * get_raw3datatype_size(data_type));
            break;
        }
        default:
            throw std::runtime_error("Unknown data type");
    }
}

tools::classhelper::ObjectPrinter RAW3DataSkipped::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("Sample binary data (Skipped)", float_precision, superscript_exponents);

    printer.register_string("Data", "Skipped");

    return printer;
}

} // namespace raw3datatypes
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
