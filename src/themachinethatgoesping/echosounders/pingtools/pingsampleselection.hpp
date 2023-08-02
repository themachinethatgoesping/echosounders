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
    std::map<std::string, substructures::BeamSampleSelection> _sample_selections;

  public:
    PingSampleSelection() = default;

    // --- add beams/samples ---
    /**
     * @brief Add a beam to the sample selection
     *
     * @param transducer_id transducer id of the beam
     * @param beam_nr beam numer
     * @param first_sample_number first sample to select (>0)
     * @param last_sample_number last sample to select (>0)
     */
    void add_beam(const std::string& transducer_id,
                  size_t             beam_nr,
                  uint16_t           first_sample_number = 0,
                  uint16_t           last_sample_number  = std::numeric_limits<uint16_t>::max())
    {
        _sample_selections[transducer_id].add_beam(
            beam_nr, first_sample_number, last_sample_number);

        // synchronize sample range information
        set_first_sample_number_ensemble(get_first_sample_number_ensemble());
        set_last_sample_number_ensemble(get_last_sample_number_ensemble());
    }

    void set_sample_step_ensemble(uint16_t sample_step_ensemble)
    {
        for (auto& [id, selection] : _sample_selections)
        {
            selection.set_sample_step_ensemble(sample_step_ensemble);
        }
    }

    uint16_t get_sample_step_ensemble() const
    {
        uint16_t sample_step_ensemble = 0;

        for (auto& [id, selection] : _sample_selections)
        {
            if (sample_step_ensemble == 0)
            {
                sample_step_ensemble = selection.get_sample_step_ensemble();
            }
            else if (sample_step_ensemble != selection.get_sample_step_ensemble())
            {
                throw std::runtime_error(
                    "ERROR[PingSampleSelector::get_sample_step_ensemble] Sample step ensemble is "
                    "not the same for all transducers");
            }
        }

        return sample_step_ensemble;
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
    bool operator==(const PingSampleSelection& other) const = default;

    // ----- get information -----
    /**
     * @brief Return the number of beams in the sample selection
     *
     * @return size_t
     */
    size_t get_number_of_beams() const
    {
        size_t n = 0;
        for (const auto& [id, selection] : _sample_selections)
        {
            n += selection.get_number_of_beams();
        }
        return n;
    }

    /**
     * @brief Return the first sample number in the sample selection
     *
     * @return size_t
     */
    uint16_t get_first_sample_number_ensemble() const
    {
        if (_sample_selections.empty())
        {
            return 0;
        }

        uint16_t first_sample_number_ensemble = std::numeric_limits<uint16_t>::max();

        for (const auto& [id, selection] : _sample_selections)
        {
            first_sample_number_ensemble = std::min(first_sample_number_ensemble,
                                                    selection.get_first_sample_number_ensemble());
        }

        return first_sample_number_ensemble;
    }

    /**
     * @brief Return the last sample number in the sample selection
     *
     * @return size_t
     */
    uint16_t get_last_sample_number_ensemble() const
    {
        uint16_t first_last_ensemble = 0;

        for (const auto& [id, selection] : _sample_selections)
        {
            first_last_ensemble =
                std::max(first_last_ensemble, selection.get_last_sample_number_ensemble());
        }

        return first_last_ensemble;
    }

    /**
     * @brief Return the number of samples in the sample selection
     *
     * @return size_t
     */
    size_t get_number_of_samples_ensemble() const
    {
        size_t first_sample_number_ensemble = get_first_sample_number_ensemble();
        size_t first_last_ensemble          = get_last_sample_number_ensemble();

        if (first_sample_number_ensemble > first_last_ensemble)
        {
            return 0;
        }

        return first_last_ensemble - first_sample_number_ensemble + 1;
    }

    /**
     * @brief Set the first sample number for the selection
     *
     * @param first_sample_number_ensemble First sample number in the selection
     */
    void set_first_sample_number_ensemble(size_t first_sample_number_ensemble)
    {
        for (auto& [id, selection] : _sample_selections)
        {
            selection.set_first_sample_number_ensemble(first_sample_number_ensemble);
        }
    }

    /**
     * @brief Set the last sample number for the selection
     *
     * @param last_sample_number_ensemble Last sample number in the selection
     */
    void set_last_sample_number_ensemble(size_t last_sample_number_ensemble)
    {
        for (auto& [id, selection] : _sample_selections)
        {
            selection.set_last_sample_number_ensemble(last_sample_number_ensemble);
        }
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