// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
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

    std::optional<float>
        _min_minslant_range_percent; ///< min samples after minslant to consider (%)
    std::optional<float>
        _max_minslant_range_percent; ///< max samples before minslant to consider (%)
    std::optional<float>
        _max_bottom_range_percent; ///< max samples before bottom detection to consider (%)
    std::optional<float>
        _min_bottom_range_percent; ///< max samples before bottom detection to consider (%)

    // transmit sectors
    std::optional<std::vector<size_t>> _transmit_sectors; ///< transmit_sectors to select
    std::optional<float> _transmit_sector_min_beam_angle; ///< select transmit sectors with angles
                                                          ///< >= _transmit_sector_min_beam_angle
    std::optional<float> _transmit_sector_max_beam_angle; ///< select transmit sectors with angles
                                                          ///< <= _transmit_sector_max_beam_angle

    size_t _beam_step   = 1; ///< step size for beam numbers
    size_t _sample_step = 1; ///< step size for sample numbers

  public:
    PingSampleSelector() = default;

    // operators
    bool operator==(const PingSampleSelector& other) const = default;

    BeamSampleSelection apply_selection(
        filetemplates::datatypes::I_PingWatercolumn& ping_watercolumn)
    {
        BeamSampleSelection selection;

        // select beams according to the options
        const auto number_of_beams            = ping_watercolumn.get_number_of_beams();
        auto       number_of_samples_per_beam = ping_watercolumn.get_number_of_samples_per_beam();
        auto       min_sample_nr_per_beam     = xt::zeros_like(number_of_samples_per_beam);

        const auto beam_crosstrack_angles = ping_watercolumn.get_beam_crosstrack_angles();
        if (beam_crosstrack_angles.size() < number_of_beams)
            throw std::runtime_error(fmt::format(
                "Number of beam crosstrack angles ({}) is smaller than the number of beams ({})",
                beam_crosstrack_angles.size(),
                number_of_beams));

        if (_max_bottom_range_percent)
        {
            const xt::xtensor<uint32_t, 1> bottom_range_samples =
                ping_watercolumn.get_bottom_range_samples() *
                (_max_bottom_range_percent.value() * 0.01f);

            number_of_samples_per_beam =
                xt::minimum(number_of_samples_per_beam, bottom_range_samples);
        }

        if (_min_bottom_range_percent)
        {
            const xt::xtensor<uint32_t, 1> bottom_range_samples =
                ping_watercolumn.get_bottom_range_samples() *
                (_min_bottom_range_percent.value() * 0.01f);

            min_sample_nr_per_beam = xt::maximum(min_sample_nr_per_beam, bottom_range_samples);
        }

        // convert min/max beam numbers to indices (if set, and according to python negative
        // indexing)
        size_t min_beam_number = _min_beam_number ? *_min_beam_number : 0;
        size_t max_beam_number = _max_beam_number ? *_max_beam_number : number_of_beams - 1;

        // initialize transmit sector selection
        auto beam_numbers_selected_by_transmit_sector =
            get_beam_numbers_selected_by_transmit_sector(ping_watercolumn, beam_crosstrack_angles);

        // create beam indexer
        tools::pyhelper::PyIndexer beam_indexer(
            number_of_beams, min_beam_number, max_beam_number + 1, _beam_step);

        std::optional<size_t> max_sample_nr_ping, min_sample_nr_ping;
        if (_max_minslant_range_percent)
        {
            size_t sn =
                (*_max_minslant_range_percent * 0.01f) * ping_watercolumn.get_minslant_sample_nr();
            if (_max_sample_number)
                max_sample_nr_ping = std::min(sn, *_max_sample_number);
            else
                max_sample_nr_ping = sn;
        }
        else
            max_sample_nr_ping = _max_sample_number;

        if (_min_minslant_range_percent)
        {
            size_t sn =
                (*_min_minslant_range_percent * 0.01f) * ping_watercolumn.get_minslant_sample_nr();
            if (_min_sample_number)
                min_sample_nr_ping = std::max(sn, *_min_sample_number);
            else
                min_sample_nr_ping = sn;
        }
        else
            min_sample_nr_ping = _min_sample_number;

        for (unsigned int counter = 0; counter < beam_indexer.size(); ++counter)
        {
            auto bn = beam_indexer(counter);

            // check transmit sector selection
            if (beam_numbers_selected_by_transmit_sector.has_value())
                if (!beam_numbers_selected_by_transmit_sector.value()[bn])
                    continue;

            if (_min_beam_angle && beam_crosstrack_angles.unchecked(bn) < *_min_beam_angle)
                continue;
            if (_max_beam_angle && beam_crosstrack_angles.unchecked(bn) > *_max_beam_angle)
                continue;

            size_t number_of_samples = number_of_samples_per_beam.unchecked(bn);
            size_t min_sample_number =
                min_sample_nr_ping.value_or(min_sample_nr_per_beam.unchecked(bn));
            size_t max_sample_number = max_sample_nr_ping.value_or(number_of_samples - 1);

            if (min_sample_number >= number_of_samples)
                continue;
            if (min_sample_number < min_sample_nr_per_beam.unchecked(bn))
                min_sample_number = min_sample_nr_per_beam.unchecked(bn);
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

    // get selection
    BeamSelection apply_selection(filetemplates::datatypes::I_PingBottom& ping_bottom)
    {
        BeamSelection selection;

        // select beams according to the options
        const auto number_of_beams = ping_bottom.get_number_of_beams();

        const auto beam_crosstrack_angles = ping_bottom.get_beam_crosstrack_angles();
        if (beam_crosstrack_angles.size() < number_of_beams)
            throw std::runtime_error(fmt::format(
                "Number of beam crosstrack angles ({}) is smaller than the number of beams ({})",
                beam_crosstrack_angles.size(),
                number_of_beams));

        // convert min/max beam numbers to indices (if set, and according to python negative
        // indexing)
        size_t min_beam_number = _min_beam_number ? *_min_beam_number : 0;
        size_t max_beam_number = _max_beam_number ? *_max_beam_number : number_of_beams - 1;

        // initialize transmit sector selection
        auto beam_numbers_selected_by_transmit_sector =
            get_beam_numbers_selected_by_transmit_sector(ping_bottom, beam_crosstrack_angles);

        tools::pyhelper::PyIndexer beam_indexer(
            number_of_beams, min_beam_number, max_beam_number + 1, _beam_step);

        for (unsigned int counter = 0; counter < beam_indexer.size(); ++counter)
        {
            auto bn = beam_indexer(counter);

            // check transmit sector selection
            if (beam_numbers_selected_by_transmit_sector.has_value())
                if (!beam_numbers_selected_by_transmit_sector.value()[bn])
                    continue;

            if (_min_beam_angle && beam_crosstrack_angles.unchecked(bn) < *_min_beam_angle)
                continue;
            if (_max_beam_angle && beam_crosstrack_angles.unchecked(bn) > *_max_beam_angle)
                continue;

            selection.add_beam(bn);
            bn++;
        }

        return selection;
    }

    // getters
    auto        get_min_beam_number() const { return _min_beam_number; }
    auto        get_max_beam_number() const { return _max_beam_number; }
    auto        get_min_sample_number() const { return _min_sample_number; }
    auto        get_max_sample_number() const { return _max_sample_number; }
    auto        get_min_beam_angle() const { return _min_beam_angle; }
    auto        get_max_beam_angle() const { return _max_beam_angle; }
    auto        get_min_sample_range() const { return _min_sample_range; }
    auto        get_max_sample_range() const { return _max_sample_range; }
    auto        get_min_minslant_range_percent() const { return _min_minslant_range_percent; }
    auto        get_max_minslant_range_percent() const { return _max_minslant_range_percent; }
    auto        get_min_bottom_range_percent() const { return _min_bottom_range_percent; }
    auto        get_max_bottom_range_percent() const { return _max_bottom_range_percent; }
    auto        get_beam_step() const { return _beam_step; }
    auto        get_sample_step() const { return _sample_step; }
    const auto& get_transmit_sectors() const { return _transmit_sectors; }
    auto get_transmit_sector_min_beam_angle() const { return _transmit_sector_min_beam_angle; }
    auto get_transmit_sector_max_beam_angle() const { return _transmit_sector_max_beam_angle; }

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

    void clear_minslant_range()
    {
        _min_minslant_range_percent.reset();
        _max_minslant_range_percent.reset();
    }

    void clear_bottom_range()
    {
        _min_bottom_range_percent.reset();
        _max_bottom_range_percent.reset();
    }

    void clear_transmit_sectors() { _transmit_sectors.reset(); }

    void clear_transmit_sector_beam_angle_range()
    {
        _transmit_sector_min_beam_angle.reset();
        _transmit_sector_max_beam_angle.reset();
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
        clear_transmit_sectors();
        clear_transmit_sector_beam_angle_range();
        clear_minslant_range();
        clear_bottom_range();
    }

    // selectors
    void select_beam_range_by_numbers(std::optional<size_t> min_beam_number,
                                      std::optional<size_t> max_beam_number,
                                      std::optional<size_t> beam_step = std::nullopt)
    {
        _min_beam_number = min_beam_number;
        _max_beam_number = max_beam_number;
        if (beam_step)
            _beam_step = *beam_step;
    }

    void select_sample_range_by_numbers(std::optional<size_t> min_sample_number,
                                        std::optional<size_t> max_sample_number,
                                        std::optional<size_t> sample_step = std::nullopt)
    {
        _min_sample_number = min_sample_number;
        _max_sample_number = max_sample_number;
        if (sample_step)
            _sample_step = *sample_step;
    }

    void select_beam_range_by_angles(std::optional<float>  min_beam_angle,
                                     std::optional<float>  max_beam_angle,
                                     std::optional<size_t> beam_step = std::nullopt)
    {
        _min_beam_angle = min_beam_angle;
        _max_beam_angle = max_beam_angle;
        if (beam_step)
            _beam_step = *beam_step;
    }

    void select_sample_range_by_ranges(std::optional<float>  min_sample_range,
                                       std::optional<float>  max_sample_range,
                                       std::optional<size_t> sample_step = std::nullopt)
    {
        _min_sample_range = min_sample_range;
        _max_sample_range = max_sample_range;
        if (sample_step)
            _sample_step = *sample_step;
    }
    void select_max_minslant_range_percent(std::optional<float> max_minslant_range_percent)
    {
        _max_minslant_range_percent = max_minslant_range_percent;
    }
    void select_min_minslant_range_percent(std::optional<float> min_minslant_range_percent)
    {
        _min_minslant_range_percent = min_minslant_range_percent;
    }
    void select_minslant_range_percent(std::optional<float> min_minslant_range_percent,
                                       std::optional<float> max_minslant_range_percent)
    {
        _min_minslant_range_percent = min_minslant_range_percent;
        _max_minslant_range_percent = max_minslant_range_percent;
    }

    void select_min_bottom_range_percent(std::optional<float> min_bottom_range_percent)
    {
        _min_bottom_range_percent = min_bottom_range_percent;
    }

    void select_max_bottom_range_percent(std::optional<float> max_bottom_range_percent)
    {
        _max_bottom_range_percent = max_bottom_range_percent;
    }

    void select_bottom_range_percent(std::optional<float> min_bottom_range_percent,
                                     std::optional<float> max_bottom_range_percent)
    {
        _min_bottom_range_percent = min_bottom_range_percent;
        _max_bottom_range_percent = max_bottom_range_percent;
    }

    void select_transmit_sectors(std::optional<std::vector<size_t>> transmit_sectors)
    {
        _transmit_sectors = transmit_sectors;
    }

    void select_transmit_sectors_by_beam_angles(std::optional<float> transmit_sector_min_beam_angle,
                                                std::optional<float> transmit_sector_max_beam_angle)
    {
        _transmit_sector_min_beam_angle = transmit_sector_min_beam_angle;
        _transmit_sector_max_beam_angle = transmit_sector_max_beam_angle;
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
        using themachinethatgoesping::tools::classhelper::stream::optional_container_from_stream;
        using themachinethatgoesping::tools::classhelper::stream::optional_from_stream;
        using themachinethatgoesping::tools::classhelper::stream::optional_set_from_stream;

        PingSampleSelector object;
        object._min_beam_number            = optional_from_stream<size_t>(is);
        object._max_beam_number            = optional_from_stream<size_t>(is);
        object._min_sample_number          = optional_from_stream<size_t>(is);
        object._max_sample_number          = optional_from_stream<size_t>(is);
        object._min_beam_angle             = optional_from_stream<float>(is);
        object._max_beam_angle             = optional_from_stream<float>(is);
        object._min_sample_range           = optional_from_stream<float>(is);
        object._max_sample_range           = optional_from_stream<float>(is);
        object._min_minslant_range_percent = optional_from_stream<float>(is);
        object._max_minslant_range_percent = optional_from_stream<float>(is);
        object._min_bottom_range_percent   = optional_from_stream<float>(is);
        object._max_bottom_range_percent   = optional_from_stream<float>(is);
        object._transmit_sectors = optional_container_from_stream<std::vector<size_t>>(is);
        object._transmit_sector_min_beam_angle = optional_from_stream<float>(is);
        object._transmit_sector_max_beam_angle = optional_from_stream<float>(is);

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
        using themachinethatgoesping::tools::classhelper::stream::optional_container_to_stream;
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
        optional_to_stream(os, _min_minslant_range_percent);
        optional_to_stream(os, _max_minslant_range_percent);
        optional_to_stream(os, _min_bottom_range_percent);
        optional_to_stream(os, _max_bottom_range_percent);
        optional_container_to_stream(os, _transmit_sectors);
        optional_to_stream(os, _transmit_sector_min_beam_angle);
        optional_to_stream(os, _transmit_sector_max_beam_angle);
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
    auto __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        using themachinethatgoesping::tools::classhelper::ObjectPrinter;

        ObjectPrinter printer("PingSampleSelector", float_precision, superscript_exponents);

        std::string inactive_filters;

        printer.register_section("Active beam/sample filters");
        register_filter(printer, "min_beam_number", _min_beam_number, "", inactive_filters);
        register_filter(printer, "max_beam_number", _max_beam_number, "", inactive_filters);
        register_filter(printer, "min_sample_number", _min_sample_number, "", inactive_filters);
        register_filter(printer, "max_sample_number", _max_sample_number, "", inactive_filters);
        register_filter(printer, "min_beam_angle", _min_beam_angle, "°", inactive_filters);
        register_filter(printer, "max_beam_angle", _max_beam_angle, "°", inactive_filters);
        register_filter(printer, "min_sample_range", _min_sample_range, "m", inactive_filters);
        register_filter(printer, "max_sample_range", _max_sample_range, "m", inactive_filters);

        register_filter(printer,
                        "min_minslant_range_percent",
                        _min_minslant_range_percent,
                        "%",
                        inactive_filters);

        register_filter(printer,
                        "max_minslant_range_percent",
                        _max_minslant_range_percent,
                        "%",
                        inactive_filters);

        register_filter(
            printer, "min_bottom_range_percent", _min_bottom_range_percent, "%", inactive_filters);

        register_filter(
            printer, "max_bottom_range_percent", _max_bottom_range_percent, "%", inactive_filters);

        if (_transmit_sectors)
            printer.register_container("transmit_sectors", *_transmit_sectors);
        else
            inactive_filters += "transmit_sectors, ";

        register_filter(printer,
                        "transmit_sector_min_beam_angle",
                        _transmit_sector_min_beam_angle,
                        "°",
                        inactive_filters);

        register_filter(printer,
                        "transmit_sector_max_beam_angle",
                        _transmit_sector_max_beam_angle,
                        "°",
                        inactive_filters);

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

  private:
    void register_filter(themachinethatgoesping::tools::classhelper::ObjectPrinter& printer,
                         const std::string&                                         name,
                         const std::optional<float>&                                value,
                         const std::string&                                         unit,
                         std::string& inactive_filters) const
    {
        if (value)
            printer.register_value(name, *value, unit);
        else
        {
            printer.register_string(name, "None");
            inactive_filters += name + ", ";
        }
    }

  public:
    // -- class helper function macros --
    // define to_binary and from_binary functions (needs to_stream and from_stream)
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(PingSampleSelector)
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    template<typename ping_watercolumn_or_bottom, typename t_angles>
    std::optional<std::vector<uint_fast16_t>> get_beam_numbers_selected_by_transmit_sector(
        ping_watercolumn_or_bottom& ping_w,
        const t_angles&             beam_crosstrack_angles)
    {

        if (!_transmit_sector_min_beam_angle.has_value() &&
            !_transmit_sector_max_beam_angle.has_value() && !_transmit_sectors.has_value())
            return std::nullopt;

        // init transmit_sector_selection
        const auto                 tx_sector_per_beam = ping_w.get_tx_sector_per_beam();
        std::vector<uint_fast16_t> transmit_sector_selection;

        if (tx_sector_per_beam.size() != beam_crosstrack_angles.size())
            throw std::runtime_error(
                fmt::format("Number of transmit sectors per beam ({}) is "
                            "different from the number of beam crosstrack angles ({})",
                            tx_sector_per_beam.size(),
                            beam_crosstrack_angles.size()));

        if (_transmit_sector_min_beam_angle.has_value() or
            _transmit_sector_max_beam_angle.has_value())
        {
            float min_ba =
                _transmit_sector_min_beam_angle.value_or(std::numeric_limits<float>::lowest());
            float max_ba =
                _transmit_sector_max_beam_angle.value_or(std::numeric_limits<float>::max());

            for (unsigned int bn = 0; bn < tx_sector_per_beam.size(); ++bn)
            {
                if (!transmit_sector_selection.empty())
                    if (tx_sector_per_beam[bn] == transmit_sector_selection.back())
                        continue;

                if (beam_crosstrack_angles.unchecked(bn) >= min_ba &&
                    beam_crosstrack_angles.unchecked(bn) <= max_ba)
                {
                    if (_transmit_sectors.has_value())
                        if (std::find(_transmit_sectors->begin(),
                                      _transmit_sectors->end(),
                                      tx_sector_per_beam[bn]) == _transmit_sectors->end())
                            continue;

                    transmit_sector_selection.push_back(tx_sector_per_beam[bn]);
                }
            }
        }
        else
        {
            std::copy(tx_sector_per_beam.begin(),
                      tx_sector_per_beam.end(),
                      std::back_inserter(transmit_sector_selection));
        }

        std::vector<uint_fast16_t> beam_number_is_selected;
        beam_number_is_selected.resize(tx_sector_per_beam.size());

        for (unsigned int bn = 0; bn < tx_sector_per_beam.size(); ++bn)
            if (std::find(transmit_sector_selection.begin(),
                          transmit_sector_selection.end(),
                          tx_sector_per_beam[bn]) != transmit_sector_selection.end())
                beam_number_is_selected[bn] = 1;

        return beam_number_is_selected;
    }
};

} // namespace pingtools
} // namespace echosounders
} // namespace themachinethatgoesping