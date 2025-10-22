// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/qualityfactordatagram.doc.hpp"

// std includes
#include <cstdint>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief The Quality Factor is an estimate of the standard deviation of the detected depth.
 * QF = − log(Est(dz)/z)
 * QF = 3.0 means an estimated standard deviation of 0.1% of the detected depth.
 * QF = 2.0 means an estimated standard deviation of 1.0% of the detected depth.
 * QF = 0 means that the Quality Factor could not be computed.
 * The Quality Factor is calculated by the echo sounder according to formulas provided
 * by IFREMER.
 * Used for EM 122, EM 302, EM 710, EM 2040, EM 2040C, EM 3002 and ME70BO.
 */
class QualityFactorDatagram : public KongsbergAllDatagram
{
  public:
    using t_Shape = xt::xtensor<float, 2>::shape_type; // shape type of the quality factors tensor
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::QualityFactorDatagram;

  protected:
    uint16_t _ping_counter;                  ///< 0-65535 ping number (in this file)
    uint16_t _system_serial_number;          ///< 100 -
    uint16_t _number_of_receive_beams;       ///< Nrx
    uint8_t  _number_of_parameters_per_beam; ///< Npar
    uint8_t  _spare;                         ///< always 0

    xt::xtensor<float, 2> _quality_factors; ///< dimension is [Nrx, Npar]

    uint8_t  _spare_byte = 0;
    uint8_t  _etx        = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit QualityFactorDatagram(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    QualityFactorDatagram();
    ~QualityFactorDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_ping_counter() const;
    uint16_t get_system_serial_number() const;
    uint16_t get_number_of_receive_beams() const;
    uint8_t  get_number_of_parameters_per_beam() const;
    uint8_t  get_spare() const;
    uint8_t  get_spare_byte() const;
    uint8_t  get_etx() const;
    uint16_t get_checksum() const;

    // setters
    void set_ping_counter(uint16_t ping_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_number_of_receive_beams(uint16_t number_of_receive_beams);
    void set_number_of_parameters_per_beam(uint8_t number_of_parameters_per_beam);
    void set_spare(uint8_t spare);
    void set_spare_byte(uint8_t spare_byte);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // substrucutre access
  xt::xtensor<float, 2>&       quality_factors();
  const xt::xtensor<float, 2>& get_quality_factors() const;
  void                         set_quality_factors(xt::xtensor<float, 2> quality_factors);

    /**
     * @brief return the shape of the quality factor array
     * Computed as [_number_of_receive_beams, _number_of_parameters_per_beam]
     *
     * @return xt::xtensor<float, 2>::shape_type
     */
    t_Shape qf_shape() const;

    // ----- processed data access -----

    // ----- operators -----
    bool operator==(const QualityFactorDatagram& other) const = default;

    //----- to/from stream functions -----
    static QualityFactorDatagram from_stream(std::istream& is, KongsbergAllDatagram header);

    static QualityFactorDatagram from_stream(std::istream& is);

    static QualityFactorDatagram from_stream(std::istream&              is,
                                             t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(QualityFactorDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
