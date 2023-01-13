// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/qualityfactordatagram.doc.hpp"

// std includes
#include <string>
#include <vector>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
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
class QualityFactorDatagram : public EM3000Datagram
{

  protected:
    uint16_t _ping_counter;                  ///< 0-65535 ping number (in this file)
    uint16_t _system_serial_number;          ///< 100 -
    uint16_t _number_of_receive_beams;       ///< Nrx
    uint8_t  _number_of_parameters_per_beam; ///< Npar
    uint8_t  _spare;

    xt::xtensor<float, 2> _quality_factors; ///< dimension is [Nrx, Npar]

    uint8_t  _spare_byte = 0;
    uint8_t  _etx        = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit QualityFactorDatagram(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    QualityFactorDatagram()
    {
        _datagram_identifier = t_EM3000DatagramIdentifier::QualityFactorDatagram;
    }
    ~QualityFactorDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_ping_counter() const { return _ping_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_number_of_receive_beams() const { return _number_of_receive_beams; }
    uint8_t  get_number_of_parameters_per_beam() const { return _number_of_parameters_per_beam; }
    uint8_t  get_spare() const { return _spare; }
    uint8_t  get_spare_byte() const { return _spare_byte; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_ping_counter(uint16_t ping_counter) { _ping_counter = ping_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_number_of_receive_beams(uint16_t number_of_receive_beams)
    {
        _number_of_receive_beams = number_of_receive_beams;
    }
    void set_number_of_parameters_per_beam(uint8_t number_of_parameters_per_beam)
    {
        _number_of_parameters_per_beam = number_of_parameters_per_beam;
    }
    void set_spare(uint8_t spare) { _spare = spare; }
    void set_spare_byte(uint8_t spare_byte) { _spare_byte = spare_byte; }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // substrucutre access
    xt::xtensor<float, 2>        quality_factors() { return _quality_factors; }
    const xt::xtensor<float, 2>& get_quality_factors() const { return _quality_factors; }
    void                         set_quality_factors(xt::xtensor<float, 2> quality_factors)
    {
        _quality_factors = quality_factors;
    }

    /**
     * @brief return the shape of the quality factor array
     * Computed as [_number_of_receive_beams, _number_of_parameters_per_beam]
     *
     * @return xt::xtensor<float, 2>::shape_type
     */
    xt::xtensor<float, 2>::shape_type qf_shape() const
    {
        return { _number_of_receive_beams, _number_of_parameters_per_beam };
    }

    // ----- processed data access -----

    // ----- operators -----
    bool operator==(const QualityFactorDatagram& other) const
    {
        return EM3000Datagram::operator==(other) && _ping_counter == other._ping_counter &&
               _system_serial_number == other._system_serial_number &&
               _number_of_receive_beams == other._number_of_receive_beams &&
               _number_of_parameters_per_beam == other._number_of_parameters_per_beam &&
               _spare == other._spare && _quality_factors == other._quality_factors &&
               _spare_byte == other._spare_byte && _etx == other._etx &&
               _checksum == other._checksum;
    }
    bool operator!=(const QualityFactorDatagram& other) const { return !operator==(other); }

    //----- to/from stream functions -----
    static QualityFactorDatagram from_stream(std::istream& is, EM3000Datagram header)
    {
        QualityFactorDatagram datagram(std::move(header));

        if (datagram._datagram_identifier != t_EM3000DatagramIdentifier::QualityFactorDatagram)
            throw std::runtime_error(fmt::format(
                "QualityFactorDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                uint8_t(t_EM3000DatagramIdentifier::QualityFactorDatagram),
                uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 8 * sizeof(uint8_t));

        // read the beams
        datagram._quality_factors = xt::empty<float>(datagram.qf_shape());
        is.read(reinterpret_cast<char*>(datagram._quality_factors.data()),
                datagram._quality_factors.size() * sizeof(float));

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._spare_byte)), 4 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "QualityFactorDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static QualityFactorDatagram from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static QualityFactorDatagram from_stream(std::istream&              is,
                                             t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os)
    {
        EM3000Datagram::to_stream(os);
        auto shape                     = _quality_factors.shape();
        _number_of_receive_beams       = shape[0];
        _number_of_parameters_per_beam = shape[1];

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_ping_counter)), 8 * sizeof(uint8_t));

        // write the beams
        os.write(reinterpret_cast<const char*>(_quality_factors.data()),
                 _quality_factors.size() * sizeof(float));

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_spare_byte)), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("QualityFactorDatagram", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("ping_counter", _ping_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("number_of_receive_beams", _number_of_receive_beams, "Nrx");
        printer.register_value(
            "number_of_parameters_per_beam", _number_of_parameters_per_beam, "Npar");
        printer.register_value("spare", _spare);
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        // printer.register_section("processed");

        printer.register_section("substructures");
        printer.register_value(
            "quality_factors", _quality_factors.size(), "np.array({Nrx, Npar}, dtype=float)");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(QualityFactorDatagram)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
