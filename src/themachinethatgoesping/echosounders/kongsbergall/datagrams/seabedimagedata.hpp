// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/seabedimagedata.doc.hpp"

// std includes
#include <array>
#include <cstdint>
#include <iosfwd>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

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
    explicit SeabedImageData(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    SeabedImageData();
    ~SeabedImageData() = default;

    // ----- convenient data access -----
    uint16_t get_ping_counter() const;
    uint16_t get_system_serial_number() const;
    float    get_sampling_frequency() const;
    uint16_t get_range_to_normal_incidence() const;
    int16_t  get_normal_incidence_backscatter() const;
    int16_t  get_oblique_backscatter() const;
    uint16_t get_tx_beamwidth_along() const;
    uint16_t get_tvg_law_crossover_angle() const;
    uint16_t get_number_of_valid_beams() const;
    uint8_t  get_spare_byte() const;
    uint8_t  get_etx() const;
    uint16_t get_checksum() const;

    void set_ping_counter(uint16_t ping_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_sampling_frequency(float sampling_frequency);
    void set_range_to_normal_incidence(uint16_t range_to_normal_incidence);
    void set_normal_incidence_backscatter(int16_t normal_incidence_backscatter);
    void set_oblique_backscatter(int16_t oblique_backscatter);
    void set_tx_beamwidth_along(uint16_t tx_beamwidth_along);
    void set_tvg_law_crossover_angle(uint16_t tvg_law_crossover_angle);
    void set_number_of_valid_beams(uint16_t number_of_valid_beams);
    void set_spare_byte(uint8_t spare_byte);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // ----- substructure access -----
    const std::vector<substructures::SeabedImageDataBeam>& get_beams() const;
    void set_beams(const std::vector<substructures::SeabedImageDataBeam>& beams);
    std::vector<substructures::SeabedImageDataBeam>& beams();

    const substructures::SampleAmplitudesStructure<int16_t>& get_sample_amplitudes() const;
    void set_sample_amplitudes(
        const substructures::SampleAmplitudesStructure<int16_t>& sample_amplitudes);
    substructures::SampleAmplitudesStructure<int16_t>& sample_amplitudes();

    // ----- processed data access -----
    /**
     * @brief Get the normal incidence backscatter in db
     *
     * @return _normal_incidence_backscatter * 0.01f (float)
     */
    float get_normal_incidence_backscatter_in_db() const;

    /**
     * @brief Get the oblique backscatter in db
     *
     * @return _oblique_backscatter * 0.01f (float)
     */
    float get_oblique_backscatter_in_db() const;

    /**
     * @brief get the tx beamwidth along in degrees
     *
     * @return _tx_beamwidth_along * 0.1f (float)
     */
    float get_tx_beamwidth_along_in_degrees() const;

    /**
     * @brief get the tvg law crossover angle in degrees
     *
     * @return _tvg_law_crossover_angle * 0.1f (float)
     */
    float get_tvg_law_crossover_angle_in_degrees() const;

    // ----- operators -----
    bool operator==(const SeabedImageData& other) const;

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
