// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/beamsampleselection.doc.hpp"

/* std includes */
#include <algorithm>
#include <map>
#include <ranges>

/* external includes */
#include <fmt/core.h>
#include <xtensor/containers/xtensor.hpp>
#include <xtensor/views/xview.hpp>

/* ping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>


#include <themachinethatgoesping/tools/helper/integermath.hpp>

#include "beamselection.hpp"
#include "readsamplerange.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pingtools {

/**
 * @brief A class to hold the selected beams/sample range for a single transducer
 *
 */
class BeamSampleSelection : public BeamSelection
{
    using BeamSelection::_beam_numbers;                  ///< selected beam numbers
    std::vector<uint32_t> _first_sample_number_per_beam; ///< first sample number per beam
    std::vector<uint32_t> _last_sample_number_per_beam;  ///< last sample number per beam

    uint32_t _sample_step_ensemble = 1; ///< sample step size (same for the entire ensemble)
    uint32_t _first_sample_number_ensemble =
        std::numeric_limits<uint32_t>::max();  ///< minimum sample number
                                               ///< (min(first_sample_number_per_beam))
    uint32_t _last_sample_number_ensemble = 0; ///< maximum sample number
                                               ///< (max(last_sample_number_per_beam))

  public:
    BeamSampleSelection(uint32_t sample_step_ensemble = 1)
        : _sample_step_ensemble(sample_step_ensemble)
    {
    }

    /**
     * @brief Construct a new Beam Sample Selection object
     *
     * @param beam_selection
     */
    BeamSampleSelection(BeamSelection beam_selection)
        : BeamSelection(std::move(beam_selection))
    {
        _first_sample_number_per_beam = std::vector<uint32_t>(get_number_of_beams(), 0);
        _last_sample_number_per_beam =
            std::vector<uint32_t>(get_number_of_beams(), std::numeric_limits<uint32_t>::max());

        _first_sample_number_ensemble = 0;
        _last_sample_number_ensemble  = std::numeric_limits<uint32_t>::max();
    }

    // --- get read sample range ---
    /**
     * @brief Return the read sample range for a given beam
     *
     * @param beam_index index of the beam within the beam sample selection
     * @param first_sample_offset offset to the first sample (often 0)
     * @param number_of_samples number of samples in the real beam structure
     * @return ReadSampleRange read sample range
     */
    ReadSampleRange get_read_sample_range(uint32_t beam_index,
                                          uint32_t first_sample_offset_in_beam,
                                          uint32_t number_of_samples_in_beam) const
    {
        using tools::helper::substract_set_zero_if_negative;

        if (beam_index >= get_number_of_beams())
        {
            throw std::runtime_error(fmt::format(
                "BeamSampleSelection::get_read_sample_range: beam index {} out of range [0,{}]",
                beam_index,
                get_number_of_beams() - 1));
        }

        auto first_beam_sample_to_read = substract_set_zero_if_negative<uint32_t>(
            std::max(_first_sample_number_per_beam[beam_index], _first_sample_number_ensemble),
            first_sample_offset_in_beam);

        auto last_beam_sample_to_read = substract_set_zero_if_negative<uint32_t>(
            std::min(_last_sample_number_per_beam[beam_index], _last_sample_number_ensemble),
            first_sample_offset_in_beam);

        if (last_beam_sample_to_read >= number_of_samples_in_beam)
        {
            last_beam_sample_to_read = number_of_samples_in_beam - 1;
        }

        int number_of_samples_to_read =
            (last_beam_sample_to_read - first_beam_sample_to_read) / _sample_step_ensemble + 1;
        if (number_of_samples_to_read < 0)
        {
            number_of_samples_to_read = 0;
        }

        int first_read_sample_offset = first_beam_sample_to_read + first_sample_offset_in_beam;
        int last_read_sample_offset =
            first_read_sample_offset + (number_of_samples_to_read - 1) * _sample_step_ensemble;

        if (last_read_sample_offset < first_read_sample_offset)
        {
            last_read_sample_offset = first_read_sample_offset;
        }

        return ReadSampleRange(uint32_t(first_beam_sample_to_read),
                               uint32_t(number_of_samples_to_read),
                               uint32_t(first_read_sample_offset),
                               uint32_t(last_read_sample_offset));
    }

    /**
     * @brief Initialize a beam sample selection from a whole swath
     *
     * @param beam_nr beam number
     * @param first_sample_number first sample number to select
     * @param last_sample_number_per_beam last sample number to select
     */
    BeamSampleSelection(std::vector<uint32_t> first_sample_number_per_beam,
                        std::vector<uint32_t> last_sample_number_per_beam,
                        uint32_t              sample_step_ensemble = 1)
        : BeamSelection(first_sample_number_per_beam.size())
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
    void add_beam(uint32_t beam_nr,
                  uint32_t first_sample_number = 0,
                  uint32_t last_sample_number  = std::numeric_limits<uint32_t>::max())
    {
        BeamSelection::add_beam(beam_nr);

        _first_sample_number_per_beam.push_back(first_sample_number);
        _last_sample_number_per_beam.push_back(last_sample_number);

        _first_sample_number_ensemble =
            std::min(_first_sample_number_ensemble, first_sample_number);
        _last_sample_number_ensemble = std::max(_last_sample_number_ensemble, last_sample_number);
    }

    // ----- convenient data access -----
    using BeamSelection::get_beam_numbers;
    using BeamSelection::get_number_of_beams;

    /**
     * @brief Return the first sample number per beam
     *
     * @return std::vector<uint32_t>
     */
    const std::vector<uint32_t>& get_first_sample_number_per_beam() const
    {
        return _first_sample_number_per_beam;
    }

    /**
     * @brief Return the max number of samples per beam
     *
     * @return std::vector<uint32_t>
     */
    const std::vector<uint32_t>& get_last_sample_number_per_beam() const
    {
        return _last_sample_number_per_beam;
    }

    // ----- ensemble data -----
    void set_sample_step_ensemble(uint32_t sample_step_ensemble)
    {
        _sample_step_ensemble = sample_step_ensemble;
    }

    void set_first_sample_number_ensemble(uint32_t first_sample_number_ensemble)
    {
        _first_sample_number_ensemble = first_sample_number_ensemble;
    }

    void set_last_sample_number_ensemble(uint32_t last_sample_number_ensemble)
    {
        _last_sample_number_ensemble = last_sample_number_ensemble;
    }

    /**
     * @brief Return the sample step size
     *
     * @return uint32_t
     */
    uint32_t get_sample_step_ensemble() const { return _sample_step_ensemble; }

    /**
     * @brief Return the first sample number of the ensemble
     *
     * @return uint32_t
     */
    uint32_t get_first_sample_number_ensemble() const { return _first_sample_number_ensemble; }

    /**
     * @brief Return the last sample number of the ensemble
     *
     * @return uint32_t
     */
    uint32_t get_last_sample_number_ensemble() const { return _last_sample_number_ensemble; }

    /**
     * @brief return the number of samples within the ensemble
     *
     * @return uint32_t
     */
    uint32_t get_number_of_samples_ensemble() const
    {
        // this check is necessary because of potential buffer overflows
        if (_last_sample_number_ensemble < _first_sample_number_ensemble)
            return 0;

        return (_last_sample_number_ensemble - _first_sample_number_ensemble) /
                   _sample_step_ensemble +
               1;
    }

    /**
     * @brief return if the selection contains beams and samples
     *
     * @return true
     * @return false
     */
    bool empty() const
    {
        if (BeamSelection::empty())
            return true;
        return get_number_of_samples_ensemble() == 0;
    }

    xt::xtensor<uint32_t, 1> get_sample_numbers_ensemble_1d() const
    {
        xt::xtensor<uint32_t, 1> sample_numbers_ensemble =
            xt::arange<uint32_t>(_first_sample_number_ensemble,
                                 _last_sample_number_ensemble + _sample_step_ensemble,
                                 _sample_step_ensemble);

        return sample_numbers_ensemble;
    }

    xt::xtensor<uint32_t, 2> get_sample_numbers_ensemble_2d() const
    {
        xt::xtensor<uint32_t, 1> sample_numbers_ensemble = get_sample_numbers_ensemble_1d();

        // return copy of sample_numbers_ensemble for each beam as 2d array
        xt::xtensor<uint32_t, 2> sample_numbers_ensemble_2d = xt::xtensor<uint32_t, 2>::from_shape(
            { get_number_of_beams(), get_number_of_samples_ensemble() });

        for (uint32_t bn = 0; bn < get_number_of_beams(); ++bn)
        {
            xt::view(sample_numbers_ensemble_2d, bn) = sample_numbers_ensemble;
        }

        return sample_numbers_ensemble_2d;
    }

    // ----- from/to binary -----
  public:
    /**
     * @brief Return a BeamSampleSelection read from a binary stream
     *
     * @param is input stream
     * @return BeamSampleSelection
     */
    static BeamSampleSelection from_stream(std::istream& is)
    {
        using themachinethatgoesping::tools::classhelper::stream::container_from_stream;

        BeamSampleSelection object(BeamSelection::from_stream(is));
        object._first_sample_number_per_beam = container_from_stream<std::vector<uint32_t>>(is);
        object._last_sample_number_per_beam  = container_from_stream<std::vector<uint32_t>>(is);

        // read other variables
        is.read(reinterpret_cast<char*>(&object._sample_step_ensemble), sizeof(uint32_t) * 3);

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

        BeamSelection::to_stream(os);
        container_to_stream(os, _first_sample_number_per_beam);
        container_to_stream(os, _last_sample_number_per_beam);

        // write other variables
        os.write(reinterpret_cast<const char*>(&_sample_step_ensemble), sizeof(uint32_t) * 3);
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

        ObjectPrinter printer("BeamSampleSelection", float_precision, superscript_exponents);

        printer.append(BeamSelection::__printer__(float_precision, superscript_exponents), true);
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

/**
 * @brief Provide a boost hash function for BeamSampleSelection
 * - Note: this is needed to use BeamSampleSelection as boost::flyweight
 *
 * @param data
 * @return std::size_t
 */
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_pingtools_hash_value
inline size_t hash_value(const BeamSampleSelection& data)
{
    return data.binary_hash();
}

} // namespace pingtools
} // namespace echosounders
} // namespace themachinethatgoesping