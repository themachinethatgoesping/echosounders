// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/fileheader.doc.hpp"

// std includes
#include <cstdint>
#include <cstring>
#include <string>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief 7k record FileHeader: the first record of a .s7k file. Describes the file (recording
 * program, session, notes) and lists the devices contained in the file.
 */
class FileHeader : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::FileHeader;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint64_t file_identifier[2];    ///< unique file identifier (magic number)
        uint16_t version;               ///< file format version
        uint16_t reserved;              ///< reserved
        uint64_t session_identifier[2]; ///< user-defined session identifier
        uint32_t record_data_size;      ///< size of record data (0 if not set)
        uint32_t number_devices;        ///< number of devices described in this file
        char     recording_name[64];    ///< name of the recording program
        char     recording_version[16]; ///< version of the recording program
        char     user_defined_name[64]; ///< user defined name
        char     notes[128];            ///< notes

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content); // 316

    // per-device arrays (length = number_devices)
    xt::xtensor<uint32_t, 1> _device_identifier;
    xt::xtensor<uint16_t, 1> _system_enumerator;

    // optional data appended after the device list (e.g. the file catalog pointer, identifier 7300)
    std::string _optional_data;

    static std::string trim(const char* s, size_t n) { return std::string(s, ::strnlen(s, n)); }

  public:
    FileHeader()  = default;
    ~FileHeader() = default;

    // ----- record type header access -----
    uint16_t get_version() const { return _content.version; }
    uint32_t get_record_data_size() const { return _content.record_data_size; }
    uint32_t get_number_devices() const { return _content.number_devices; }
    std::string get_recording_name() const { return trim(_content.recording_name, 64); }
    std::string get_recording_version() const { return trim(_content.recording_version, 16); }
    std::string get_user_defined_name() const { return trim(_content.user_defined_name, 64); }
    std::string get_notes() const { return trim(_content.notes, 128); }

    // ----- per-device data access -----
    const xt::xtensor<uint32_t, 1>& get_device_identifier() const { return _device_identifier; }
    const xt::xtensor<uint16_t, 1>& get_system_enumerator() const { return _system_enumerator; }

    // ----- optional data (file catalog pointer, if present) -----
    const std::string& get_optional_data() const { return _optional_data; }
    bool               has_file_catalog_info() const { return _optional_data.size() >= 12; }
    uint32_t           get_file_catalog_size() const
    {
        uint32_t v = 0;
        if (has_file_catalog_info())
            std::memcpy(&v, _optional_data.data(), sizeof(v));
        return v;
    }
    uint64_t get_file_catalog_offset() const
    {
        uint64_t v = 0;
        if (has_file_catalog_info())
            std::memcpy(&v, _optional_data.data() + 4, sizeof(v));
        return v;
    }

    // ----- operators -----
    bool operator==(const FileHeader& other) const = default;

    //----- to/from stream functions -----
    static FileHeader from_stream(std::istream& is, S7KDatagram header);
    static FileHeader from_stream(std::istream& is);
    static FileHeader from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(FileHeader)

  private:
    explicit FileHeader(S7KDatagram header)
        : S7KDatagram(std::move(header))
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
