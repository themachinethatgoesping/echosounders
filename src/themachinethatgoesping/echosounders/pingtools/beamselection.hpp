// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/beamselection.doc.hpp"

/* std includes */
#include <algorithm>
#include <map>
#include <ranges>
#include <numeric>

/* external includes */
#include <fmt/core.h>

/* ping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>


#include "readsamplerange.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pingtools {

/**
 * @brief A class to hold the selected beams/sample range for a single transducer
 *
 */
class BeamSelection
{
  protected:
    std::vector<uint32_t> _beam_numbers; ///< selected beam numbers

  public:
    BeamSelection() {}

    /**
     * @brief Initialize a beam sample selection from a whole swath
     *
     * @param number_of_beams number of beams in the swath
     */
    BeamSelection(size_t number_of_beams)
        : _beam_numbers(std::vector<uint32_t>(number_of_beams))
    {
        std::iota(std::begin(_beam_numbers),
                  std::end(_beam_numbers),
                  0); // Fill vector with 0, 1, ..., number_of_beams-1.
    }

    /**
     * @brief Initialize a beam sample selection from a whole swath
     *
     * @param number_of_beams number of beams in the swath
     */
    BeamSelection(std::vector<uint32_t> beam_numbers)
        : _beam_numbers(std::move(beam_numbers))
    {
    }

    // --- operators ---
    bool operator==(const BeamSelection& other) const = default;

    // ----- add beams/samples -----
    /**
     * @brief Add a beam to the selection
     *
     * @param beam_nr beam number
     * @param first_sample_number first sample number to select
     * @param last_sample_number_per_beam last sample number to select
     */
    void add_beam(uint32_t beam_nr) { _beam_numbers.push_back(beam_nr); }

    // ----- convenient data access -----
    /**
     * @brief Return the number of beams
     *
     * @return size_t
     */
    size_t get_number_of_beams() const { return _beam_numbers.size(); }

    /**
     * @brief return if the selection contains beams
     *
     * @return true
     * @return false
     */
    bool empty() const { return _beam_numbers.empty(); }

    /**
     * @brief Return the beam numbers
     *
     * @return std::vector<uint32_t>
     */
    const std::vector<uint32_t>& get_beam_numbers() const { return _beam_numbers; }

    // ----- from/to binary -----
    /**
     * @brief Return a BeamSelection read from a binary stream
     *
     * @param is input stream
     * @return BeamSelection
     */
    static BeamSelection from_stream(std::istream& is)
    {
        using themachinethatgoesping::tools::classhelper::stream::container_from_stream;

        BeamSelection object;
        object._beam_numbers = container_from_stream<std::vector<uint32_t>>(is);

        return object;
    }

    /**
     * @brief Write a BeamSelection to a binary stream
     *
     * @param os output stream
     */
    void to_stream(std::ostream& os) const
    {
        using themachinethatgoesping::tools::classhelper::stream::container_to_stream;

        container_to_stream(os, _beam_numbers);
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

        ObjectPrinter printer("BeamSelection", float_precision, superscript_exponents);

        printer.register_container("_beam_numbers", _beam_numbers);

        return printer;
    }

  public:
    // -- class helper function macros --
    // define to_binary and from_binary functions (needs to_stream and from_stream)
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(BeamSelection)
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

/**
 * @brief Provide a boost hash function for BeamSelection
 * - Note: this is needed to use BeamSelection as boost::flyweight
 *
 * @param data
 * @return std::size_t
 */
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_pingtools_hash_value
inline size_t hash_value(const BeamSelection& data)
{
    return data.binary_hash();
}

} // namespace pingtools
} // namespace echosounders
} // namespace themachinethatgoesping