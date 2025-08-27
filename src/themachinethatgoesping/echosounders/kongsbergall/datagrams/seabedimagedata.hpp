// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/seabedimagedata.doc.hpp"

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

#include "substructures/sampleamplitudesstructure.hpp"
#include "substructures/seabedimagedatabeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief This datagram is used for the models EM 2040, EM 2040C, EM 710, EM 122, EM
302 and ME70BO. All receiver beams are included, check detection info and real time
cleaning for beam status (note 4 and 5).
 */
class SeabedImageData : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::SeabedImageData;

  protected:
    uint16_t _ping_counter; ///< sequential number
    uint16_t _system_serial_number;
    float    _sampling_frequency;           ///< in Hz
    uint16_t _range_to_normal_incidence;    ///< used to correct sample amplitudes in no. of samples
    int16_t  _normal_incidence_backscatter; ///< in 0.01 dB (BSN)
    int16_t  _oblique_backscatter;          ///< in 0.01 dB (BSO)
    uint16_t _tx_beamwidth_along;           ///< in 0.1 degree
    uint16_t _tvg_law_crossover_angle;      ///< in 0.1 degree
    uint16_t _number_of_valid_beams;

    std::vector<substructures::SeabedImageDataBeam> _beams;

    // std::vector<std::vector<int16_t>>
    //     _sample_amplitudes;
    substructures::SampleAmplitudesStructure<int16_t>
        _sample_amplitudes; ///< in 0.1 dB (size = sum of _Number_of_samples of all Beams

    uint8_t  _spare_byte = 0;
    uint8_t  _etx        = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit SeabedImageData(KongsbergAllDatagram header)
        : KongsbergAllDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    SeabedImageData() { _datagram_identifier = t_KongsbergAllDatagramIdentifier::SeabedImageData; }
    ~SeabedImageData() = default;

    // ----- convenient data access -----
    uint16_t get_ping_counter() const { return _ping_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    float    get_sampling_frequency() const { return _sampling_frequency; }
    uint16_t get_range_to_normal_incidence() const { return _range_to_normal_incidence; }
    int16_t  get_normal_incidence_backscatter() const { return _normal_incidence_backscatter; }
    int16_t  get_oblique_backscatter() const { return _oblique_backscatter; }
    uint16_t get_tx_beamwidth_along() const { return _tx_beamwidth_along; }
    uint16_t get_tvg_law_crossover_angle() const { return _tvg_law_crossover_angle; }
    uint16_t get_number_of_valid_beams() const { return _number_of_valid_beams; }
    uint8_t  get_spare_byte() const { return _spare_byte; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    void set_ping_counter(uint16_t ping_counter) { _ping_counter = ping_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_sampling_frequency(float sampling_frequency)
    {
        _sampling_frequency = sampling_frequency;
    }
    void set_range_to_normal_incidence(uint16_t range_to_normal_incidence)
    {
        _range_to_normal_incidence = range_to_normal_incidence;
    }
    void set_normal_incidence_backscatter(int16_t normal_incidence_backscatter)
    {
        _normal_incidence_backscatter = normal_incidence_backscatter;
    }
    void set_oblique_backscatter(int16_t oblique_backscatter)
    {
        _oblique_backscatter = oblique_backscatter;
    }
    void set_tx_beamwidth_along(uint16_t tx_beamwidth_along)
    {
        _tx_beamwidth_along = tx_beamwidth_along;
    }
    void set_tvg_law_crossover_angle(uint16_t tvg_law_crossover_angle)
    {
        _tvg_law_crossover_angle = tvg_law_crossover_angle;
    }
    void set_number_of_valid_beams(uint16_t number_of_valid_beams)
    {
        _number_of_valid_beams = number_of_valid_beams;
    }
    void set_spare_byte(uint8_t spare_byte) { _spare_byte = spare_byte; }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- substructure access -----
    const std::vector<substructures::SeabedImageDataBeam>& get_beams() const { return _beams; }
    void set_beams(const std::vector<substructures::SeabedImageDataBeam>& beams) { _beams = beams; }
    std::vector<substructures::SeabedImageDataBeam>& beams() { return _beams; }

    const substructures::SampleAmplitudesStructure<int16_t>& get_sample_amplitudes() const
    {
        return _sample_amplitudes;
    }
    void set_sample_amplitudes(
        const substructures::SampleAmplitudesStructure<int16_t>& sample_amplitudes)
    {
        _sample_amplitudes = sample_amplitudes;
    }
    substructures::SampleAmplitudesStructure<int16_t>& sample_amplitudes()
    {
        return _sample_amplitudes;
    }

    // ----- processed data access -----
    /**
     * @brief Get the normal incidence backscatter in db
     *
     * @return _normal_incidence_backscatter * 0.01f (float)
     */
    float get_normal_incidence_backscatter_in_db() const
    {
        return _normal_incidence_backscatter * 0.01f;
    }

    /**
     * @brief Get the oblique backscatter in db
     *
     * @return _oblique_backscatter * 0.01f (float)
     */
    float get_oblique_backscatter_in_db() const { return _oblique_backscatter * 0.01f; }

    /**
     * @brief get the tx beamwidth along in degrees
     *
     * @return _tx_beamwidth_along * 0.1f (float)
     */
    float get_tx_beamwidth_along_in_degrees() const { return _tx_beamwidth_along * 0.1f; }

    /**
     * @brief get the tvg law crossover angle in degrees
     *
     * @return _tvg_law_crossover_angle * 0.1f (float)
     */
    float get_tvg_law_crossover_angle_in_degrees() const { return _tvg_law_crossover_angle * 0.1f; }

    // ----- operators -----
    bool operator==(const SeabedImageData& other) const
    {
        return KongsbergAllDatagram::operator==(other) && _ping_counter == other._ping_counter &&
               _system_serial_number == other._system_serial_number &&
               tools::helper::float_equals(_sampling_frequency, other._sampling_frequency) &&
               _range_to_normal_incidence == other._range_to_normal_incidence &&
               _normal_incidence_backscatter == other._normal_incidence_backscatter &&
               _oblique_backscatter == other._oblique_backscatter &&
               _tx_beamwidth_along == other._tx_beamwidth_along &&
               _tvg_law_crossover_angle == other._tvg_law_crossover_angle &&
               _number_of_valid_beams == other._number_of_valid_beams && _beams == other._beams &&
               _sample_amplitudes == other._sample_amplitudes && _spare_byte == other._spare_byte &&
               _etx == other._etx && _checksum == other._checksum;
    }

    //----- to/from stream functions -----
    static SeabedImageData from_stream(std::istream& is, KongsbergAllDatagram header);

    static SeabedImageData from_stream(std::istream& is);

    static SeabedImageData from_stream(std::istream&                    is,
                                       t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SeabedImageData)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
