// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/iinstallationparam.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "kmalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

/**
 * @brief Clock datagrams
 */
class IInstallationParam : public KMALLDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KMALLDatagramIdentifier::I_INSTALLATION_PARAM;

  protected:
    uint16_t    _bytes_content;        ///<  bytes of the datagram body
    uint16_t    _info;                 ///< Information. For future use.
    uint16_t    _status;               ///< Status. For future use.
    std::string _install_txt;          ///< Runtime parameters as text format.
    uint32_t    _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                       ///< integrity check
  public:
    // ----- public constructors -----
    IInstallationParam();
    ~IInstallationParam() = default;

    // ----- convenient data access -----
    // getters
    uint16_t           get_bytes_content() const;
    uint16_t           get_info() const;
    uint16_t           get_status() const;
    const std::string& get_install_txt() const;
    uint32_t           get_bytes_datagram_check() const;

    // setters
    // void set_bytes_content(uint16_t bytes_content);
    void set_info(uint16_t info);
    void set_status(uint16_t status);
    void set_install_txt(std::string_view install_txt);

    // ----- processed data access -----

    // ----- operators -----
    bool operator==(const IInstallationParam& other) const = default;

    //----- to/from stream functions -----
    static IInstallationParam from_stream(std::istream& is, const KMALLDatagram& header);

    static IInstallationParam from_stream(std::istream&             is,
                                          o_KMALLDatagramIdentifier datagram_identifier);

    static IInstallationParam from_stream(std::istream& is);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(IInstallationParam)

  private:
    explicit IInstallationParam(const KMALLDatagram& header)
        : KMALLDatagram(header)
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
