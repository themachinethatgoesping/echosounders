// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/beamsampleselection.doc.hpp"

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
namespace substructures {

/**
 * @brief A class to hold the selected beams/sample range for a single transducer
 *
 */
class BeamSampleSelection
{
    std::vector<uint16_t> _beam_numbers;                 ///< selected beam numbers
    std::vector<uint16_t> _first_sample_number_per_beam; ///< first sample number per beam
    std::vector<uint16_t> _last_sample_number_per_beam;  ///< last sample number per beam

    uint16_t _sample_step_ensemble; ///< sample step size (same for the entire ensemble)
    uint16_t _first_sample_number_ensemble =
        std::numeric_limits<uint16_t>::max(); ///< minimum sample number
                                              ///< (min(first_sample_number_per_beam))
    uint16_t _last_sample_number_ensemble =
        0; ///< maximum sample number (max(last_sample_number_per_beam))

  public:
    BeamSampleSelection(uint16_t sample_step_ensemble = 1)
        : _sample_step_ensemble(sample_step_ensemble)
    {
    }

    // --- builders ---

    /**
     * @brief Initialize a beam sample selection from a whole swath
     *
     * @param beam_nr beam number
     * @param first_sample_number first sample number to select
     * @param last_sample_number_per_beam last sample number to select
     */
    BeamSampleSelection(std::vector<uint16_t> first_sample_number_per_beam,
                        std::vector<uint16_t> last_sample_number_per_beam,
                        uint16_t              sample_step_ensemble = 1)
        : _beam_numbers(std::vector<uint16_t>(first_sample_number_per_beam.size()))
        , _first_sample_number_per_beam(std::move(first_sample_number_per_beam))
        , _last_sample_number_per_beam(std::move(last_sample_number_per_beam))
        , _sample_step_ensemble(sample_step_ensemble)
    {
        // check that size is equal
        if (first_sample_number_per_beam.size() != last_sample_number_per_beam.size())
            throw std::invalid_argument(fmt::format(
                "ERROR[BeamSampleSelection::init]: first_sample_number_per_beam.size() ({}) != "
                "last_sample_number_per_beam.size() ({})",
                first_sample_number_per_beam.size(),
                last_sample_number_per_beam.size()));

        std::iota(std::begin(_beam_numbers),
                  std::end(_beam_numbers),
                  0); // Fill vector with 0, 1, ..., number_of_beams-1.

        // find min/max sample numbers
        _first_sample_number_ensemble = *std::ranges::min_element(_first_sample_number_per_beam);
        _last_sample_number_ensemble  = *std::ranges::max_element(_last_sample_number_per_beam);
    }

    // --- operators ---
    bool operator==(const BeamSampleSelection& other) const = default;

    // ----- add beams/samples -----
    /**
     * @brief Add a beam to the selection
     *
     * @param beam_nr beam number
     * @param first_sample_number first sample number to select
     * @param last_sample_number_per_beam last sample number to select
     */
    void add_beam(size_t   beam_nr,
                  uint16_t first_sample_number = 0,
                  uint16_t last_sample_number  = std::numeric_limits<uint16_t>::max())
    {
        _beam_numbers.push_back(beam_nr);
        _first_sample_number_per_beam.push_back(first_sample_number);
        _last_sample_number_per_beam.push_back(last_sample_number);

        _first_sample_number_ensemble =
            std::min(_first_sample_number_ensemble, first_sample_number);
        _last_sample_number_ensemble = std::max(_last_sample_number_ensemble, last_sample_number);
    }

    // ----- convenient data access -----
    /**
     * @brief Return the number of beams
     *
     * @return size_t
     */
    size_t get_number_of_beams() const { return _beam_numbers.size(); }

    /**
     * @brief Return the beam numbers
     *
     * @return std::vector<uint16_t>
     */
    const std::vector<uint16_t>& get_beam_numbers() const { return _beam_numbers; }

    /**
     * @brief Return the first sample number per beam
     *
     * @return std::vector<uint16_t>
     */
    const std::vector<uint16_t>& get_first_sample_number_per_beam() const
    {
        return _first_sample_number_per_beam;
    }

    /**
     * @brief Return the max number of samples per beam
     *
     * @return std::vector<uint16_t>
     */
    const std::vector<uint16_t>& get_last_sample_number_per_beam() const
    {
        return _last_sample_number_per_beam;
    }

    // ----- ensemble data -----
    void set_sample_step_ensemble(uint16_t sample_step_ensemble)
    {
        _sample_step_ensemble = sample_step_ensemble;
    }

    void set_first_sample_number_ensemble(uint16_t first_sample_number_ensemble)
    {
        _first_sample_number_ensemble = first_sample_number_ensemble;
    }

    void set_last_sample_number_ensemble(uint16_t last_sample_number_ensemble)
    {
        _last_sample_number_ensemble = last_sample_number_ensemble;
    }

    /**
     * @brief Return the sample step size
     *
     * @return uint16_t
     */
    uint16_t get_sample_step_ensemble() const { return _sample_step_ensemble; }

    /**
     * @brief Return the first sample number of the ensemble
     *
     * @return uint16_t
     */
    uint16_t get_first_sample_number_ensemble() const { return _first_sample_number_ensemble; }

    /**
     * @brief Return the last sample number of the ensemble
     *
     * @return uint16_t
     */
    uint16_t get_last_sample_number_ensemble() const { return _last_sample_number_ensemble; }

    /**
     * @brief return the number of samples within the ensemble
     *
     * @return uint16_t
     */
    uint16_t get_number_of_samples_ensemble() const
    {
        return (_last_sample_number_ensemble - _first_sample_number_ensemble) /
                   _sample_step_ensemble +
               1;
    }

    // ----- from/to binary -----
    /**
     * @brief Return a BeamSampleSelection read from a binary stream
     *
     * @param is input stream
     * @return BeamSampleSelection
     */
    static BeamSampleSelection from_stream(std::istream& is)
    {
        using themachinethatgoesping::tools::classhelper::stream::container_from_stream;

        BeamSampleSelection object;
        object._beam_numbers                 = container_from_stream<std::vector<uint16_t>>(is);
        object._first_sample_number_per_beam = container_from_stream<std::vector<uint16_t>>(is);
        object._last_sample_number_per_beam  = container_from_stream<std::vector<uint16_t>>(is);

        // read other variables
        is.read(reinterpret_cast<char*>(&object._sample_step_ensemble), sizeof(uint16_t) * 3);

        return object;
    }

    /**
     * @brief Write a BeamSampleSelection to a binary stream
     *
     * @param os output stream
     */
    void to_stream(std::ostream& os) const
    {
        using themachinethatgoesping::tools::classhelper::stream::container_to_stream;

        container_to_stream(os, _beam_numbers);
        container_to_stream(os, _first_sample_number_per_beam);
        container_to_stream(os, _last_sample_number_per_beam);

        // write other variables
        os.write(reinterpret_cast<const char*>(&_sample_step_ensemble), sizeof(uint16_t) * 3);
    }

    // ----- printing -----
    /**
     * @brief Print function, needs __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ macro
     * See also: classhelper/objectprinter.hpp
     *
     * @param float_precision Precision of floating point numbers
     * @return classhelper::ObjectPrinter
     */
    auto __printer__(unsigned int float_precision) const
    {
        using themachinethatgoesping::tools::classhelper::ObjectPrinter;

        ObjectPrinter printer("BeamSampleSelection", float_precision);

        printer.register_container("_beam_numbers", _beam_numbers);
        printer.register_container("_first_sample_number_per_beam", _first_sample_number_per_beam);
        printer.register_container("_last_sample_number_per_beam", _last_sample_number_per_beam);

        printer.register_value("_sample_step_ensemble", _sample_step_ensemble);
        printer.register_value("_first_sample_number_ensemble", _first_sample_number_ensemble);
        printer.register_value("_last_sample_number_ensemble", _last_sample_number_ensemble);

        return printer;
    }

  public:
    // -- class helper function macros --
    // define to_binary and from_binary functions (needs to_stream and from_stream)
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(BeamSampleSelection)
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace substructures
} // namespace pingtools
} // namespace echosounders
} // namespace themachinethatgoesping