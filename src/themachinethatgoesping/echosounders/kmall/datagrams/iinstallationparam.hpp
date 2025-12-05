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
#include <map>
#include <string>
#include <string_view>

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
    /**
     * @brief Decode the install_txt string into a key-value map
     *
     * This function parses the KMALL installation parameter text format.
     * The format contains comma-separated fields with different separators
     * for different field types (e.g., ':' for OSCV, '_' for PU, '=' for SN).
     *
     * @return std::map<std::string, std::string> Map of parameter names to values
     */
    std::map<std::string, std::string> get_install_txt_decoded() const;

    /**
     * @brief Decode an install_txt string into a key-value map (static version)
     *
     * @param install_txt The installation parameter text to decode
     * @return std::map<std::string, std::string> Map of parameter names to values
     */
    static std::map<std::string, std::string> decode_install_txt(std::string_view install_txt);

    /**
     * @brief Get human-readable explanation for an install_txt key
     *
     * @param key The key to look up (e.g., "OSCV", "EMXV", "PU")
     * @return std::string Human-readable explanation, or "Unknown key" if not found
     */
    static std::string get_install_txt_key_info(std::string_view key);

    /**
     * @brief Get all known install_txt key explanations
     *
     * @return const std::map<std::string, std::string>& Map of keys to their explanations
     */
    static const std::map<std::string, std::string>& get_install_txt_key_infos();

    // ----- operators -----
    bool operator==(const IInstallationParam& other) const = default;

    //----- to/from stream functions -----
    static IInstallationParam from_stream(std::istream& is, const KMALLDatagram& header);

    static IInstallationParam from_stream(std::istream&             is,
                                          o_KMALLDatagramIdentifier datagram_identifier);

    static IInstallationParam from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(IInstallationParam)

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
