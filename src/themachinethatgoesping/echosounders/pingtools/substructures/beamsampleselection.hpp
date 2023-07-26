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
 * @brief A struct to hold the selected beams/samples for a single transducer
 *
 */
struct BeamSampleSelection
{
    std::vector<uint16_t> beam_numbers;                   ///< selected beam numbers
    std::vector<uint16_t> first_sample_number_per_beam;   ///< first sample number per beam
    std::vector<uint16_t> max_number_of_samples_per_beam; ///< max number of samples per beam

    uint16_t sample_step_ensemble         = 1; ///< sample step size (same for the entire ensemble)
    uint16_t first_sample_number_ensemble = 0; ///< first sample number of the ensemble (computed)
    uint16_t number_of_samples_ensemble   = 0; ///< max number of samples in the ensemble (computed)

    bool operator==(const BeamSampleSelection& other) const
    {
        return beam_numbers == other.beam_numbers &&
               first_sample_number_per_beam == other.first_sample_number_per_beam &&
               max_number_of_samples_per_beam == other.max_number_of_samples_per_beam &&
               sample_step_ensemble == other.sample_step_ensemble &&
               first_sample_number_ensemble == other.first_sample_number_ensemble &&
               number_of_samples_ensemble == other.number_of_samples_ensemble;
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
        object.beam_numbers                   = container_from_stream<std::vector<uint16_t>>(is);
        object.first_sample_number_per_beam   = container_from_stream<std::vector<uint16_t>>(is);
        object.max_number_of_samples_per_beam = container_from_stream<std::vector<uint16_t>>(is);

        // read rest
        is.read(reinterpret_cast<char*>(&object.sample_step_ensemble), sizeof(uint16_t) * 3);

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

        container_to_stream(os, beam_numbers);
        container_to_stream(os, first_sample_number_per_beam);
        container_to_stream(os, max_number_of_samples_per_beam);
        os.write(reinterpret_cast<const char*>(&sample_step_ensemble), sizeof(uint16_t) * 3);
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

        printer.register_container("beam_numbers", beam_numbers);
        printer.register_container("first_sample_number_per_beam", first_sample_number_per_beam);
        printer.register_container("max_number_of_samples_per_beam",
                                   max_number_of_samples_per_beam);
        printer.register_value("sample_step_ensemble", sample_step_ensemble);
        printer.register_value("first_number_sample_ensemble", first_sample_number_ensemble);
        printer.register_value("number_of_samples_ensemble", number_of_samples_ensemble);

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