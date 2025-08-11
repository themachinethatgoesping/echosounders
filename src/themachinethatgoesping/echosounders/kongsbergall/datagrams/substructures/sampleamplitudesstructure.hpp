// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/sampleamplitudesstructure.doc.hpp"

// std includes
#include <string>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief A structure to store the sample amplitudes of multiple beams in a single array.
 * Each beam may have a different number of samples.
 * One of the main reasons behind this structure is read/write performance and the possibility
 * to use xsimd on the data (stored as xtensor).
 *
 * @tparam t_sample
 */
template<typename t_sample>
class SampleAmplitudesStructure
{
    float _db_step_size = 0.1f; ///< db step size associated with this structure (typically 0.1 dB)
    xt::xtensor<t_sample, 1> _sample_amplitudes; ///< in db steps
    std::vector<uint16_t>    _start_index_per_beam;
    std::vector<uint16_t>    _samples_per_beam;

  public:
    SampleAmplitudesStructure() = default;
    SampleAmplitudesStructure(uint16_t              total_samples,
                              std::vector<uint16_t> start_index_per_beam,
                              std::vector<uint16_t> samples_per_beam)
        : _sample_amplitudes(
              xt::empty<t_sample>(typename xt::xtensor<t_sample, 1>::shape_type({ total_samples })))
        , _start_index_per_beam(std::move(start_index_per_beam))
        , _samples_per_beam(std::move(samples_per_beam))
    {
    }

    ~SampleAmplitudesStructure() = default;

    // ----- getters -----
    float                           get_db_step_size() const { return _db_step_size; }
    const xt::xtensor<t_sample, 1>& get_sample_amplitudes() const { return _sample_amplitudes; }
    const std::vector<uint16_t>& get_start_index_per_beam() const { return _start_index_per_beam; }
    const std::vector<uint16_t>& get_samples_per_beam() const { return _samples_per_beam; }

    // ----- setters -----
    void set_db_step_size(float db_step_size) { _db_step_size = db_step_size; }

    void set_sample_amplitudes(const xt::xtensor<t_sample, 1>& sample_amplitudes)
    {
        _sample_amplitudes = sample_amplitudes;
    }
    void set_start_index_per_beam(const std::vector<uint16_t>& start_index_per_beam)
    {
        _start_index_per_beam = start_index_per_beam;
    }
    void set_samples_per_beam(const std::vector<uint16_t>& samples_per_beam)
    {
        _samples_per_beam = samples_per_beam;
    }

    // ----- convenient getters -----
    /**
     * @brief Convert the sample amplitudes to db using _db_step_size.
     *
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 1> get_sample_amplitudes_in_db() const
    {
        return xt::xtensor<float, 1>(_sample_amplitudes * _db_step_size);
    }

    /**
     * @brief return a view of the sample amplitudes of a single beam
     *
     * @param beam_index
     * @return xt::xtensor<t_sample, 1>
     */
    xt::xtensor<t_sample, 1> get_beam(size_t beam_index) const
    {
        return xt::view(
            _sample_amplitudes,
            xt::range(_start_index_per_beam.at(beam_index),
                      _start_index_per_beam.at(beam_index) + _samples_per_beam.at(beam_index)));
    }

    /**
     * @brief return a xtensor of the sample amplitudes of a single beam converted to db
     *
     * @param mp_cores number of cores to use for parallelization (default 1)
     * 
     * @param beam_index
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 1> get_beam_in_db(size_t beam_index) const
    {
        auto beam = xt::view(
            _sample_amplitudes,
            xt::range(_start_index_per_beam.at(beam_index),
                      _start_index_per_beam.at(beam_index) + _samples_per_beam.at(beam_index)));

        return xt::xtensor<float, 1>(beam * _db_step_size);
    }

    /**
     * @brief get all sample amplitude values of all beams in a single xtensor
     *
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 2> get_sample_amplitudes_per_beam(unsigned int mp_cores = 1) const
    {
        auto sample_amplitudes = xt::xtensor<float, 2>::from_shape(
            { _samples_per_beam.size(),
              *std::max_element(_samples_per_beam.begin(), _samples_per_beam.end()) });
        sample_amplitudes.fill(std::numeric_limits<float>::quiet_NaN());

#pragma omp parallel for num_threads(mp_cores)
        for (size_t i = 0; i < _samples_per_beam.size(); ++i)
        {
            auto beam = get_beam(i);
            xt::view(sample_amplitudes, i, xt::range(0, beam.size())) = beam;
        }

        return sample_amplitudes;
    }

    /**
     * @brief get all sample amplitude valuesof all beams in a single xtensor in db
     * Convert the sample amplitudes to db using _db_step_size.
     *
     * @param mp_cores number of cores to use for parallelization (default 1)
     * 
     * @return xt::xtensor<float, 1>
     */
    xt::xtensor<float, 2> get_sample_amplitudes_per_beam_in_db(unsigned int mp_cores = 1) const
    {
        auto sample_amplitudes = xt::xtensor<float, 2>::from_shape(
            { _samples_per_beam.size(),
              *std::max_element(_samples_per_beam.begin(), _samples_per_beam.end()) });
        sample_amplitudes.fill(std::numeric_limits<float>::quiet_NaN());

#pragma omp parallel for num_threads(mp_cores)
        for (size_t i = 0; i < _samples_per_beam.size(); ++i)
        {
            auto beam = get_beam_in_db(i);
            xt::view(sample_amplitudes, i, xt::range(0, beam.size())) = beam;
        }

        return sample_amplitudes;
    }

    // ----- container functions -----
    size_t size() const { return _sample_amplitudes.size(); }
    size_t size(size_t beam_index) const { return _samples_per_beam.at(beam_index); }

    // ----- operators -----
    bool operator==(const SampleAmplitudesStructure& other) const
    {
        return _sample_amplitudes == other._sample_amplitudes;
    }
    bool operator!=(const SampleAmplitudesStructure& other) const { return !operator==(other); }

    //----- to/from stream functions -----
    static SampleAmplitudesStructure from_stream(std::istream&         is,
                                                 uint16_t              total_samples,
                                                 std::vector<uint16_t> start_index_per_beam,
                                                 std::vector<uint16_t> samples_per_beam)
    {
        // init the sample amplitudes structure with the correct size
        SampleAmplitudesStructure data(
            total_samples, std::move(start_index_per_beam), std::move(samples_per_beam));

        is.read(reinterpret_cast<char*>(data._sample_amplitudes.data()),
                data._sample_amplitudes.size() * sizeof(t_sample));

        return data;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_sample_amplitudes.data()),
                 _sample_amplitudes.size() * sizeof(t_sample));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "SampleAmplitudesStructure", float_precision, superscript_exponents);

        printer.register_value("db_step_size", _db_step_size);
        printer.register_value("number of sample_amplitudes", _sample_amplitudes.size());
        printer.register_container("samples_per_beam", _samples_per_beam);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SampleAmplitudesStructure)
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
