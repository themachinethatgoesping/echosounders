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

class BeamSampleSelection
{
  public:
    struct SampleSelection
    {
        std::vector<uint16_t> beam_numbers;
        std::vector<uint16_t> first_sample_number_per_beam;
        std::vector<uint16_t> max_number_of_samples_per_beam;

        uint16_t sample_step_ensemble         = 1;
        uint16_t first_sample_number_ensemble = 0;
        uint16_t number_of_samples_ensemble   = 0;

        bool operator==(const SampleSelection& other) const
        {
            return beam_numbers == other.beam_numbers &&
                   first_sample_number_per_beam == other.first_sample_number_per_beam &&
                   max_number_of_samples_per_beam == other.max_number_of_samples_per_beam &&
                   sample_step_ensemble == other.sample_step_ensemble &&
                   first_sample_number_ensemble == other.first_sample_number_ensemble &&
                   number_of_samples_ensemble == other.number_of_samples_ensemble;
        }
    };

  private:
    std::map<std::string, SampleSelection> _sample_selections;

  public:
    BeamSampleSelection() = default;

    // operators
    bool operator==(const BeamSampleSelection& other) const
    {
        return _sample_selections == other._sample_selections;
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
        using themachinethatgoesping::tools::classhelper::stream::optional_from_stream;

        BeamSampleSelection object;
        size_t              size;
        is.read(reinterpret_cast<char*>(&size), sizeof(size));

        for (size_t i = 0; i < size; ++i)
        {
            std::string name;
            is.read(reinterpret_cast<char*>(&name), sizeof(name));

            SampleSelection selection;
            is.read(reinterpret_cast<char*>(&selection), sizeof(selection));

            object._sample_selections[name] = selection;
        }

        return object;
    }

    /**
     * @brief Write a BeamSampleSelection to a binary stream
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
            os.write(reinterpret_cast<const char*>(&selection), sizeof(selection));
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

        ObjectPrinter printer("BeamSampleSelection", float_precision);

        if (_sample_selections.empty())
        {
            printer.register_value("empty", true);
            return printer;
        }

        for (const auto& [name, selection] : _sample_selections)
        {
            printer.register_section(fmt::format("SampleSelection Transducer '{}'", name));
            printer.register_container("beam_numbers", selection.beam_numbers);
            printer.register_container("first_sample_number_per_beam",
                                       selection.first_sample_number_per_beam);
            printer.register_container("max_number_of_samples_per_beam",
                                       selection.max_number_of_samples_per_beam);
            printer.register_value("sample_step_ensemble", selection.sample_step_ensemble);
            printer.register_value("first_number_sample_ensemble",
                                   selection.first_sample_number_ensemble);
            printer.register_value("number_of_samples_ensemble",
                                   selection.number_of_samples_ensemble);
        }

        return printer;
    }

  public:
    // -- class helper function macros --
    // define to_binary and from_binary functions (needs to_stream and from_stream)
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(BeamSampleSelection)
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace pingtools
} // namespace echosounders
} // namespace themachinethatgoesping