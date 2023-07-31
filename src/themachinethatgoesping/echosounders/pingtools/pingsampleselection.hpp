// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/pingsampleselection.doc.hpp"

/* std includes */
#include <map>
#include <set>

/* external includes */
#include <fmt/core.h>

/* ping includes */
#include <themachinethatgoesping/echosounders/pingtools/substructures/beamsampleselection.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pingtools {

class PingSampleSelection
{

  private:
    std::map<std::string, substructures::BeamSampleSelection> _sample_selections;

  public:
    PingSampleSelection() = default;

    // --- add beams/samples ---
    void add_beam(const std::string& transducer_id,
                  size_t             beam_nr,
                  uint16_t           first_sample_number   = 0,
                  uint16_t           max_number_of_samples = std::numeric_limits<uint16_t>::max())
    {
        _sample_selections[transducer_id].add_beam(
            beam_nr, first_sample_number, max_number_of_samples);
    }

    void set_sample_step_ensemble(uint16_t sample_step_ensemble)
    {
        for (auto& [id, selection] : _sample_selections)
        {
            selection.set_sample_step_ensemble(sample_step_ensemble);
        }
    }

    void set_sample_step_ensemble(const std::string& transducer_id, uint16_t sample_step_ensemble)
    {
        _sample_selections.at(transducer_id).set_sample_step_ensemble(sample_step_ensemble);
    }

    // --- convenient data access ---
    /**
     * @brief Return the names of the transducers
     *
     * @return std::set<std::string>
     */
    std::set<std::string> transducer_ids() const
    {
        std::set<std::string> ids;
        for (const auto& [id, selection] : _sample_selections)
        {
            ids.insert(id);
        }
        return ids;
    }

    /**
     * @brief Return the sample selections for each transducer
     *
     * @return dict of sample selections
     */
    const auto& get_sample_selections() const { return _sample_selections; }

    // operators
    bool operator==(const PingSampleSelection& other) const
    {
        return _sample_selections == other._sample_selections;
    }

    // ----- from/to binary -----
    /**
     * @brief Return a PingSampleSelection read from a binary stream
     *
     * @param is input stream
     * @return PingSampleSelection
     */
    static PingSampleSelection from_stream(std::istream& is)
    {
        using themachinethatgoesping::tools::classhelper::stream::optional_from_stream;

        PingSampleSelection object;
        size_t              size;
        is.read(reinterpret_cast<char*>(&size), sizeof(size));

        for (size_t i = 0; i < size; ++i)
        {
            std::string name;
            is.read(reinterpret_cast<char*>(&name), sizeof(name));

            object._sample_selections[name] = substructures::BeamSampleSelection::from_stream(is);
        }

        return object;
    }

    /**
     * @brief Write a PingSampleSelection to a binary stream
     *
     * @param os output stream
     */
    void to_stream(std::ostream& os) const
    {
        size_t size = _sample_selections.size();
        os.write(reinterpret_cast<const char*>(&size), sizeof(size));

        for (const auto& [name, selection] : _sample_selections)
        {
            os.write(reinterpret_cast<const char*>(&name), sizeof(name));
            selection.to_stream(os);
        }
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

        ObjectPrinter printer("PingSampleSelection", float_precision);

        if (_sample_selections.empty())
        {
            printer.register_value("empty", true);
            return printer;
        }

        for (const auto& [name, selection] : _sample_selections)
        {
            printer.register_section(fmt::format("BeamSampleSelection Transducer '{}'", name));
            printer.append(selection.__printer__(float_precision), true);
        }

        return printer;
    }

  public:
    // -- class helper function macros --
    // define to_binary and from_binary functions (needs to_stream and from_stream)
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(PingSampleSelection)
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace pingtools
} // namespace echosounders
} // namespace themachinethatgoesping