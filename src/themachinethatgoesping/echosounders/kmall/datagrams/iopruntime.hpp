
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/iopruntime.doc.hpp"

// std includes
#include <cstdint>
#include <map>
#include <string>
#include <string_view>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <xxhash.hpp>

#include "../types.hpp"
#include "kmalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

/**
 * @brief Clock datagrams
 */
class IOpRuntime : public KMALLDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KMALLDatagramIdentifier::I_OP_RUNTIME;

  protected:
    uint16_t    _bytes_content;        ///<  bytes of the datagram body
    uint16_t    _info;                 ///< Information. For future use.
    uint16_t    _status;               ///< Status. For future use.
    std::string _runtime_txt;          ///< Runtime parameters as text format.
    uint32_t    _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                       ///< integrity check

  public:
    // ----- public constructors -----
    IOpRuntime();
    ~IOpRuntime() = default;

    // ----- convenient data access -----
    // getters
    uint16_t           get_bytes_content() const;
    uint16_t           get_info() const;
    uint16_t           get_status() const;
    const std::string& get_runtime_txt() const;
    uint32_t           get_bytes_datagram_check() const;

    // setters
    // void set_bytes_content(uint16_t bytes_content);
    void set_info(uint16_t info);
    void set_status(uint16_t status);
    void set_runtime_txt(std::string_view runtime_txt);

    // ----- processed data access -----
    /**
     * @brief Decode the runtime_txt string into a key-value map
     *
     * This function parses the KMALL operator runtime parameter text format.
     * The format contains newline-separated sections with key: value pairs.
     *
     * @return std::map<std::string, std::string> Map of parameter names to values
     */
    std::map<std::string, std::string> get_runtime_txt_decoded() const;

    /**
     * @brief Decode a runtime_txt string into a key-value map (static version)
     *
     * @param runtime_txt The runtime parameter text to decode
     * @return std::map<std::string, std::string> Map of parameter names to values
     */
    static std::map<std::string, std::string> decode_runtime_txt(std::string_view runtime_txt);

    /**
     * @brief Get human-readable explanation for a runtime_txt key
     *
     * @param key The key to look up
     * @return std::string Human-readable explanation, or "Unknown key" if not found
     */
    static std::string get_runtime_txt_key_info(std::string_view key);

    /**
     * @brief Get all known runtime_txt key explanations
     *
     * @return const std::map<std::string, std::string>& Map of keys to their explanations
     */
    static const std::map<std::string, std::string>& get_runtime_txt_key_infos();

    // ----- operators -----
    bool operator==(const IOpRuntime& other) const = default;

    //----- to/from stream functions -----
    static IOpRuntime from_stream(std::istream& is, const KMALLDatagram& header);

    static IOpRuntime from_stream(std::istream& is, o_KMALLDatagramIdentifier datagram_identifier);

    static IOpRuntime from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- hash function -----
    /**
     * @brief Hash the content of the IOpRuntime datagram (excluding header timestamp)
     *
     * @return xxh::hash_t<64> 64-bit hash value
     */
    xxh::hash_t<64> hash_content_only() const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(IOpRuntime)

  private:
    explicit IOpRuntime(const KMALLDatagram& header)
        : KMALLDatagram(header)
    {
    }
    void __read__(std::istream& is);
};

/**
 * @brief Provide a boost hash function for IOpRuntime
 * - Note: this is needed to use IOpRuntime as boost::flyweight
 * - IMPORTANT: this hash function only uses the content of the IOpRuntime for hashing
 * (not information from header e.g. timestamp, etc.)
 *
 * @param data
 * @return std::size_t
 */
// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_kmall_hash_value
size_t hash_value(const IOpRuntime& data);

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
