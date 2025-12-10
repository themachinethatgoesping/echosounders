// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/FIL1.doc.hpp"

// std includes (minimal for interface)
#include <array>
#include <complex>
#include <string_view>

// xtensor includes (type appears in the public interface)
#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

// themachinethatgoesping import (types used in interface)
#include "../types.hpp"
#include "simradrawdatagram.hpp"


namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

/**
 * @brief Filter binary datagram (FIL1)
 * This datagram contains filter coefficients used by the EK80 to filter the received signal.
 *
 */
class FIL1 : public SimradRawDatagram
{
    // ----- datagram content -----
    simradraw_short       _stage   = '\x00';        ///< Filter stage number
    simradraw_char        _spare_1 = '\x00';        ///< For future expansions
    simradraw_char        _spare_2 = '\x00';        ///< For future expansions
    std::array<char, 128> _channel_id;              ///< Channel identification (size is always 128)
    simradraw_short       _no_of_coefficients = 0;  ///< Number of complex filter coefficients
    simradraw_short       _decimation_factor  = -1; ///< Filter decimation factor

    xt::xtensor<std::complex<simradraw_float>, 1> _coefficients; ///< Filter coefficients

  private:
    // ----- public constructors -----
    explicit FIL1(SimradRawDatagram header);

  public:
    // ----- constructors -----
    FIL1();
    ~FIL1() = default;

    // ----- operators -----
    bool operator==(const FIL1& other) const;
    bool operator!=(const FIL1& other) const { return !operator==(other); }

    // ----- getter setter -----
    simradraw_short  get_stage() const { return _stage; }
    simradraw_char   get_spare_1() const { return _spare_1; }
    simradraw_char   get_spare_2() const { return _spare_2; }
    std::string_view get_channel_id() const { return std::string_view(_channel_id.data(), 128); }
    std::string_view get_channel_id_stripped() const;
    simradraw_short  get_no_of_coefficients() const { return _no_of_coefficients; }
    simradraw_short  get_decimation_factor() const { return _decimation_factor; }
    const auto&      get_coefficients() const { return _coefficients; }

    void set_stage(simradraw_short stage) { _stage = stage; }
    void set_spare_1(simradraw_char spare_1) { _spare_1 = spare_1; }
    void set_spare_2(simradraw_char spare_2) { _spare_2 = spare_2; }
    void set_channel_id(std::string_view channel_id);
    void set_no_of_coefficients(simradraw_short no_of_coefficients);
    void set_decimation_factor(simradraw_short decimation_factor);
    void set_coefficients(xt::xtensor<std::complex<simradraw_float>, 1> coefficients);

    // ----- file I/O -----
    static FIL1 from_stream(std::istream& is, SimradRawDatagram header);
    static FIL1 from_stream(std::istream& is);
    static FIL1 from_stream(std::istream& is, t_SimradRawDatagramIdentifier type);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(FIL1)
};

// Boost hash function
// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_hash_value
std::size_t hash_value(const FIL1& object);

}
}
}
}