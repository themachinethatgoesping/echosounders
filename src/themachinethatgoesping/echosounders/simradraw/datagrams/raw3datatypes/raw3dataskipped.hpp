// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/raw3dataskipped.doc.hpp"

// std includes
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>

#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "i_raw3data.hpp"
#include "t_raw3datatype.hpp"
#include "../../types.hpp" // for simradraw_long

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace raw3datatypes {

/**
 * @brief This class represents a pseudo data type that is used to skip the raw3 data in the stream.
 * It is used to load the RAW3 datagram info without the samples.
 *
 */
struct RAW3DataSkipped : public i_RAW3Data
{
    RAW3DataSkipped()
        : i_RAW3Data("Skipped")
    {
    }
    ~RAW3DataSkipped() = default;

    // ----- operator overloads -----
    bool operator==([[maybe_unused]] const RAW3DataSkipped& other) const { return true; }
    bool operator!=(const RAW3DataSkipped& other) const { return !(operator==(other)); }

    // ----- to/from stream -----
    /**
     * @brief This function returns an empty RawDataSkipped object, but skips the data in the stream
     * according to the given parameters (they must be known in advance)
     *
     * @param is input stream
     * @param count number of elements
     * @param data_type data type
     * @param number_of_complex_samples number of complex samples
     * @return RAW3DataSkipped
     */
    static RAW3DataSkipped from_stream(std::istream&  is,
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

    /**
     * @brief This function writes zeros to the stream according to the given parameters (they must
     * be known in advance)
     *
     * @param os output stream
     * @param count number of elements
     * @param data_type data type
     * @param number_of_complex_samples number of complex samples
     */
    void to_stream(std::ostream&  os,
                   simradraw_long    count,
                   t_RAW3DataType data_type,
                   uint8_t        number_of_complex_samples) const
    {
        switch (data_type)
        {
            case t_RAW3DataType::PowerAndAngle: {
                // write _count.size() zeros
                auto samples = std::vector<simradraw_short>(count, 0);
                os.write(reinterpret_cast<char*>(samples.data()),
                         samples.size() * get_raw3datatype_size(data_type));
                break;
            }
            case t_RAW3DataType::ComplexFloat32: {
                // write _count.size() zeros
                auto samples =
                    std::vector<simradraw_complex_float>(count * number_of_complex_samples, 0);
                os.write(reinterpret_cast<char*>(samples.data()),
                         samples.size() * get_raw3datatype_size(data_type));
                break;
            }
            case t_RAW3DataType::Power: {
                // write _count.size() zeros
                auto samples = std::vector<simradraw_short>(count, 0);
                os.write(reinterpret_cast<char*>(samples.data()),
                         samples.size() * get_raw3datatype_size(data_type));
                break;
            }
            case t_RAW3DataType::Angle: {
                // write _count.size() zeros
                auto samples = std::vector<uint8_t>(count * 2, 0);
                os.write(reinterpret_cast<char*>(samples.data()),
                         samples.size() * get_raw3datatype_size(data_type));
                break;
            }
            case t_RAW3DataType::ComplexFloat16: {
                // write _count.size() zeros
                auto samples = std::vector<simradraw_float>(count * number_of_complex_samples, 0);
                os.write(reinterpret_cast<char*>(samples.data()),
                         samples.size() * get_raw3datatype_size(data_type));
                break;
            }
            default:
                throw std::runtime_error("Unknown data type");
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("Sample binary data (Skipped)", float_precision, superscript_exponents);

        printer.register_string("Data", "Skipped");

        return printer;
    }
};

}
}
}
}
}