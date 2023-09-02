// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/pingsampleselector.doc.hpp"

/* std includes */
#include <string>
#include <vector>

/* ping includes */
#include "../filetemplates/datatypes/i_ping.hpp"
#include "beamsampleselection.hpp"
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pingtools {

class PingSampleSelector
{
    std::optional<size_t> _min_beam_number; ///< min beam number to select
    std::optional<size_t> _max_beam_number; ///< max beam number to select

    std::optional<size_t> _min_sample_number; ///< min sample number to select
    std::optional<size_t> _max_sample_number; ///< max sample number to select

    std::optional<float> _min_beam_angle; ///< min beam angle to select (°)
    std::optional<float> _max_beam_angle; ///< max beam angle to select (°)

    std::optional<float> _min_sample_range; ///< min sample range to select (m)
    std::optional<float> _max_sample_range; ///< max sample range to select (m)

    size_t _beam_step   = 1; ///< step size for beam numbers
    size_t _sample_step = 1; ///< step size for sample numbers

  public:
    PingSampleSelector() = default;

    // operators
    bool operator==(const PingSampleSelector& other) const = default;

    // get selection
    BeamSampleSelection apply_selection(
        const std::shared_ptr<filetemplates::datatypes::I_Ping>& ping)
    {

        BeamSampleSelection selection;

        // select beams according to the options
        const auto number_of_beams = ping->get_number_of_beams();

        const auto& beam_pointing_angles = ping->get_beam_pointing_angles();
        if (beam_pointing_angles.size() < number_of_beams)
            throw std::runtime_error(fmt::format(
                "Number of beam pointing angles ({}) is smaller than the number of beams ({})",
                beam_pointing_angles.size(),
                number_of_beams));

        // convert min/max beam numbers to indices (if set, and according to python negative
        // indexing)
        size_t min_beam_number = _min_beam_number ? *_min_beam_number : 0;
        size_t max_beam_number = _max_beam_number ? *_max_beam_number : number_of_beams - 1;

        tools::pyhelper::PyIndexer beam_indexer(
            number_of_beams, min_beam_number, max_beam_number, _beam_step);

        for (unsigned int counter = 0; counter < beam_indexer.size(); ++counter)
        {
            auto bn = beam_indexer(counter);

            if (_min_beam_angle && beam_pointing_angles.unchecked(bn) < *_min_beam_angle)
                continue;
            if (_max_beam_angle && beam_pointing_angles.unchecked(bn) > *_max_beam_angle)
                continue;

            size_t number_of_samples = ping->get_number_of_samples_per_beam().unchecked(bn);
            size_t min_sample_number = _min_sample_number ? *_min_sample_number : 0;
            size_t max_sample_number =
                _max_sample_number ? *_max_sample_number : number_of_samples - 1;

            if (min_sample_number >= number_of_samples)
                continue;
            if (max_sample_number >= number_of_samples)
                max_sample_number = number_of_samples - 1;

            tools::pyhelper::PyIndexer sample_indexer(
                number_of_samples, min_sample_number, max_sample_number + 1, _sample_step);

            selection.add_beam(bn, sample_indexer(0), sample_indexer(-1));
            bn++;
        }

        // select samples according to the options
        selection.set_sample_step_ensemble(_sample_step);

        return selection;
    }

    // getters
    auto get_min_beam_number() const { return _min_beam_number; }
    auto get_max_beam_number() const { return _max_beam_number; }
    auto get_min_sample_number() const { return _min_sample_number; }
    auto get_max_sample_number() const { return _max_sample_number; }
    auto get_min_beam_angle() const { return _min_beam_angle; }
    auto get_max_beam_angle() const { return _max_beam_angle; }
    auto get_min_sample_range() const { return _min_sample_range; }
    auto get_max_sample_range() const { return _max_sample_range; }
    auto get_beam_step() const { return _beam_step; }
    auto get_sample_step() const { return _sample_step; }

    // resetters
    void clear_beam_number_range()
    {
        _min_beam_number.reset();
        _max_beam_number.reset();
    }

    void clear_sample_number_range()
    {
        _min_sample_number.reset();
        _max_sample_number.reset();
    }

    void clear_beam_angle_range()
    {
        _min_beam_angle.reset();
        _max_beam_angle.reset();
    }

    void clear_sample_range_range()
    {
        _min_sample_range.reset();
        _max_sample_range.reset();
    }

    void clear_beam_step() { _beam_step = 1; }
    void clear_sample_step() { _sample_step = 1; }

    void clear()
    {
        clear_beam_number_range();
        clear_sample_number_range();
        clear_beam_angle_range();
        clear_sample_range_range();
        clear_beam_step();
        clear_sample_step();
    }

    // selectors

    void select_beam_range_by_numbers(size_t                min_beam_number,
                                      size_t                max_beam_number,
                                      std::optional<size_t> beam_step = std::nullopt)
    {
        _min_beam_number = min_beam_number;
        _max_beam_number = max_beam_number;
        if (beam_step)
            _beam_step = *beam_step;
    }

    void select_sample_range_by_numbers(size_t                min_sample_number,
                                        size_t                max_sample_number,
                                        std::optional<size_t> sample_step = std::nullopt)
    {
        _min_sample_number = min_sample_number;
        _max_sample_number = max_sample_number;
        if (sample_step)
            _sample_step = *sample_step;
    }

    void select_beam_range_by_angles(float                 min_beam_angle,
                                     float                 max_beam_angle,
                                     std::optional<size_t> beam_step = std::nullopt)
    {
        _min_beam_angle = min_beam_angle;
        _max_beam_angle = max_beam_angle;
        if (beam_step)
            _beam_step = *beam_step;
    }

    void select_sample_range_by_ranges(float                 min_sample_range,
                                       float                 max_sample_range,
                                       std::optional<size_t> sample_step = std::nullopt)
    {
        _min_sample_range = min_sample_range;
        _max_sample_range = max_sample_range;
        if (sample_step)
            _sample_step = *sample_step;
    }

    void set_sample_step(size_t sample_step) { _sample_step = sample_step; }
    void set_beam_step(size_t beam_step) { _beam_step = beam_step; }

    // ----- from/to binary -----
    /**
     * @brief Return a PingSampleSelector read from a binary stream
     *
     * @param is input stream
     * @return PingSampleSelector
     */
    static PingSampleSelector from_stream(std::istream& is)
    {
        using themachinethatgoesping::tools::classhelper::stream::optional_from_stream;
        using themachinethatgoesping::tools::classhelper::stream::optional_set_from_stream;

        PingSampleSelector object;
        object._min_beam_number   = optional_from_stream<size_t>(is);
        object._max_beam_number   = optional_from_stream<size_t>(is);
        object._min_sample_number = optional_from_stream<size_t>(is);
        object._max_sample_number = optional_from_stream<size_t>(is);
        object._min_beam_angle    = optional_from_stream<float>(is);
        object._max_beam_angle    = optional_from_stream<float>(is);
        object._min_sample_range  = optional_from_stream<float>(is);
        object._max_sample_range  = optional_from_stream<float>(is);
        is.read(reinterpret_cast<char*>(&object._beam_step), sizeof(object._beam_step));
        is.read(reinterpret_cast<char*>(&object._sample_step), sizeof(object._sample_step));

        return object;
    }

    /**
     * @brief Write a PingSampleSelector to a binary stream
     *
     * @param os output stream
     */
    void to_stream(std::ostream& os) const
    {
        using themachinethatgoesping::tools::classhelper::stream::optional_set_to_stream;
        using themachinethatgoesping::tools::classhelper::stream::optional_to_stream;

        optional_to_stream(os, _min_beam_number);
        optional_to_stream(os, _max_beam_number);
        optional_to_stream(os, _min_sample_number);
        optional_to_stream(os, _max_sample_number);
        optional_to_stream(os, _min_beam_angle);
        optional_to_stream(os, _max_beam_angle);
        optional_to_stream(os, _min_sample_range);
        optional_to_stream(os, _max_sample_range);
        os.write(reinterpret_cast<const char*>(&_beam_step), sizeof(_beam_step));
        os.write(reinterpret_cast<const char*>(&_sample_step), sizeof(_sample_step));
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

        ObjectPrinter printer("PingSampleSelector", float_precision);

        std::string inactive_filters;

        printer.register_section("Active beam/sample filters");
        if (_min_beam_number)
            printer.register_value("min_beam_number", *_min_beam_number);
        else
            inactive_filters += "min_beam_number, ";

        if (_max_beam_number)
            printer.register_value("max_beam_number", *_max_beam_number);
        else
            inactive_filters += "max_beam_number, ";

        if (_min_sample_number)
            printer.register_value("min_sample_number", *_min_sample_number);
        else
            inactive_filters += "min_sample_number, ";

        if (_max_sample_number)
            printer.register_value("max_sample_number", *_max_sample_number);
        else
            inactive_filters += "max_sample_number, ";

        if (_min_beam_angle)
            printer.register_value("min_beam_angle", *_min_beam_angle, "°");
        else
            inactive_filters += "min_beam_angle, ";

        if (_max_beam_angle)
            printer.register_value("max_beam_angle", *_max_beam_angle, "°");
        else
            inactive_filters += "max_beam_angle, ";

        if (_min_sample_range)
            printer.register_value("min_sample_range", *_min_sample_range, "m");
        else
            inactive_filters += "min_sample_range, ";

        if (_max_sample_range)
            printer.register_value("max_sample_range", *_max_sample_range, "m");
        else
            inactive_filters += "max_sample_range, ";

        printer.register_value("beam_step", _beam_step);
        printer.register_value("sample_step", _sample_step);

        printer.register_section("Inactive beam/sample filters");
        if (inactive_filters.size() > 2)
            inactive_filters = inactive_filters.substr(0, inactive_filters.size() - 2);
        else
            inactive_filters = "None";
        printer.register_string("inactive_filters", inactive_filters);

        return printer;
    }

  public:
    // -- class helper function macros --
    // define to_binary and from_binary functions (needs to_stream and from_stream)
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(PingSampleSelector)
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace pingtools
} // namespace echosounders
} // namespace themachinethatgoesping