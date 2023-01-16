// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
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
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

#include "substructures/sampleamplitudesstructure.hpp"
#include "substructures/seabedimagedatabeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

/**
 * @brief This datagram is used for the models EM 2040, EM 2040C, EM 710, EM 122, EM
302 and ME70BO. All receiver beams are included, check detection info and real time
cleaning for beam status (note 4 and 5).
 */
class SeabedImageData : public EM3000Datagram
{
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
    explicit SeabedImageData(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    SeabedImageData() { _datagram_identifier = t_EM3000DatagramIdentifier::SeabedImageData; }
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
        return EM3000Datagram::operator==(other) && _ping_counter == other._ping_counter &&
               _system_serial_number == other._system_serial_number &&
               _sampling_frequency == other._sampling_frequency &&
               _range_to_normal_incidence == other._range_to_normal_incidence &&
               _normal_incidence_backscatter == other._normal_incidence_backscatter &&
               _oblique_backscatter == other._oblique_backscatter &&
               _tx_beamwidth_along == other._tx_beamwidth_along &&
               _tvg_law_crossover_angle == other._tvg_law_crossover_angle &&
               _number_of_valid_beams == other._number_of_valid_beams &&
               _spare_byte == other._spare_byte && _etx == other._etx &&
               _checksum == other._checksum && _beams == other._beams &&
               _sample_amplitudes == other._sample_amplitudes;
    }
    bool operator!=(const SeabedImageData& other) const { return !operator==(other); }

    //----- to/from stream functions -----
    static SeabedImageData from_stream(std::istream& is, EM3000Datagram header)
    {
        SeabedImageData datagram(std::move(header));

        if (datagram._datagram_identifier != t_EM3000DatagramIdentifier::SeabedImageData)
            throw std::runtime_error(
                fmt::format("SeabedImageData: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                            uint8_t(t_EM3000DatagramIdentifier::SeabedImageData),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 20 * sizeof(uint8_t));

        // read the beams
        datagram._beams.resize(datagram._number_of_valid_beams);
        is.read(reinterpret_cast<char*>(datagram._beams.data()),
                datagram._number_of_valid_beams * sizeof(substructures::SeabedImageDataBeam));

        uint16_t              total_samples = 0;
        std::vector<uint16_t> samples_per_beam;
        std::vector<uint16_t> start_index_per_beam;
        samples_per_beam.reserve(datagram._number_of_valid_beams);

        for (const auto& beam : datagram._beams)
        {
            start_index_per_beam.push_back(total_samples);
            samples_per_beam.push_back(beam.get_number_of_samples());
            total_samples += samples_per_beam.back();
        }

        datagram._sample_amplitudes =
            substructures::SampleAmplitudesStructure<int16_t>::from_stream(
                is, total_samples, std::move(start_index_per_beam), std::move(samples_per_beam));

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._spare_byte)), 4 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "SeabedImageData: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static SeabedImageData from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static SeabedImageData from_stream(std::istream&              is,
                                       t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os)
    {
        EM3000Datagram::to_stream(os);
        _number_of_valid_beams = _beams.size();

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_ping_counter)), 20 * sizeof(uint8_t));

        // write the beams
        os.write(reinterpret_cast<const char*>(_beams.data()),
                 _number_of_valid_beams * sizeof(substructures::SeabedImageDataBeam));

        // write the sample amplitudes
        _sample_amplitudes.to_stream(os);
        // _sample_amplitudes.resize(_number_of_valid_beams);
        // for (uint b = 0; b < _number_of_valid_beams; ++b)
        // {
        //     _sample_amplitudes[b].resize(_beams[b].get_number_of_samples());
        //     os.write(reinterpret_cast<const char*>(_sample_amplitudes[b].data()),
        //              _beams[b].get_number_of_samples() * sizeof(int16_t));
        // }

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_spare_byte)), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("SeabedImageData", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("ping_counter", _ping_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("sampling_frequency", _sampling_frequency, "Hz");
        printer.register_value("range_to_normal_incidence", _range_to_normal_incidence);
        printer.register_value(
            "normal_incidence_backscatter", _normal_incidence_backscatter, "0.01 dB");
        printer.register_value("oblique_backscatter", _oblique_backscatter, "0.01 dB");
        printer.register_value("tx_beamwidth_along", _tx_beamwidth_along, "0.1°");
        printer.register_value("tvg_law_crossover_angle", _tvg_law_crossover_angle, "0.1°");
        printer.register_value("number_of_valid_beams", _number_of_valid_beams);
        printer.register_value("spare_byte", _spare_byte);
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        printer.register_section("processed");
        printer.register_value(
            "normal_incidence_backscatter", get_normal_incidence_backscatter_in_db(), "dB");
        printer.register_value("oblique_backscatter", get_oblique_backscatter_in_db(), "dB");
        printer.register_value("tx_beamwidth_along", get_tx_beamwidth_along_in_degrees(), "°");
        printer.register_value(
            "tvg_law_crossover_angle", get_tvg_law_crossover_angle_in_degrees(), "°");

        printer.register_section("substructures");
        printer.register_value("beams", _beams.size(), "SeabedImageDataBeams");
        printer.register_value(
            "sample_amplitudes", _sample_amplitudes.size(), "SampleAmplitudesStructure");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SeabedImageData)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
