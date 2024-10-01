// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/readsamplerange.doc.hpp"

/* std includes */
#include <map>

/* external includes */
#include <fmt/core.h>

/* ping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pingtools {

/**
 * @brief A class to hold range of samples for a single beam
 *
 */
class ReadSampleRange
{
    uint32_t _first_sample_to_read; ///< first sample number to read (local to beam sample offset)
    uint32_t
        _number_of_samples_to_read;     ///< number of samples to read (local to beam sample offset)
    uint32_t _first_read_sample_offset; ///< offset of the first read sample (compared to global
                                        ///< sample number)
    uint32_t _last_read_sample_offset;  ///< offset of the last read sample (compared to global

    ReadSampleRange() {}

  public:
    ReadSampleRange(uint32_t first_sample_to_read,
                    uint32_t number_of_samples_to_read,
                    uint32_t first_read_sample_offset,
                    uint32_t last_read_sample_offset)
        : _first_sample_to_read(first_sample_to_read)
        , _number_of_samples_to_read(number_of_samples_to_read)
        , _first_read_sample_offset(first_read_sample_offset)
        , _last_read_sample_offset(last_read_sample_offset)
    {
    }

    // ----- operators -----
    bool operator==(const ReadSampleRange& other) const = default;

    // ----- accessors -----
    /**
     * @brief Return the first sample number to read (local to beam sample offset)
     *
     * @return uint32_t
     */
    uint32_t get_first_sample_to_read() const { return _first_sample_to_read; }
    uint32_t get_number_of_samples_to_read() const { return _number_of_samples_to_read; }
    uint32_t get_first_read_sample_offset() const { return _first_read_sample_offset; }
    uint32_t get_last_read_sample_offset() const { return _last_read_sample_offset; }

    // ----- from/to binary -----
    /**
     * @brief Return a ReadSampleRange read from a binary stream
     *
     * @param is input stream
     * @return ReadSampleRange
     */
    static ReadSampleRange from_stream(std::istream& is)
    {
        ReadSampleRange object;
        is.read(reinterpret_cast<char*>(&object), sizeof(object));

        return object;
    }

    /**
     * @brief Write a ReadSampleRange to a binary stream
     *
     * @param os output stream
     */
    void to_stream(std::ostream& os) const
    {
        // write other variables
        os.write(reinterpret_cast<const char*>(this), sizeof(ReadSampleRange));
    }

    // ----- printing -----
    /**
     * @brief Print function, needs __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ macro
     * See also: classhelper/objectprinter.hpp
     *
     * @param float_precision Precision of floating point numbers
     * @return classhelper::ObjectPrinter
     */
    auto __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        using themachinethatgoesping::tools::classhelper::ObjectPrinter;

        ObjectPrinter printer("ReadSampleRange", float_precision, superscript_exponents);

        printer.register_value("first_sample_to_read", _first_sample_to_read, "beamlocal");
        printer.register_value(
            "number_of_samples_to_read", _number_of_samples_to_read, "beamlocal");
        printer.register_value(
            "first_read_sample_offset", _first_read_sample_offset, "swathglobal");
        printer.register_value("last_read_sample_offset", _last_read_sample_offset, "swathglobal");

        return printer;
    }

  public:
    // -- class helper function macros --
    // define to_binary and from_binary functions (needs to_stream and from_stream)
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(ReadSampleRange)
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace pingtools
} // namespace echosounders
} // namespace themachinethatgoesping