// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/fileheader.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"
#include "substructs/fileheaderdeviceinfocontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief 7k record FileHeader (7200): the first record of a .s7k file. Describes the file (recording
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
        uint64_t _file_identifier[2];    ///< unique file identifier (magic number)
        uint16_t _version;               ///< file format version
        uint16_t _reserved;              ///< reserved
        uint64_t _session_identifier[2]; ///< user-defined session identifier
        uint32_t _record_data_size;      ///< size of record data (0 if not set)
        uint32_t _number_devices;        ///< number of devices described in this file
        char     _recording_name[64];    ///< name of the recording program
        char     _recording_version[16]; ///< version of the recording program
        char     _user_defined_name[64]; ///< user defined name
        char     _notes[128];            ///< notes

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content); // 316

    substructs::FileHeaderDeviceInfoContainer _devices; ///< device entries

    // optional data appended after the device list (e.g. the file catalog pointer, identifier 7300)
    std::string _optional_data;

    uint32_t _checksum = 0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

    static std::string trim(const char* s, size_t n);

  public:
    FileHeader();
    ~FileHeader() = default;

    // ----- record type header access -----
    uint16_t    get_version() const;
    uint32_t    get_record_data_size() const;
    uint32_t    get_number_devices() const;
    std::string get_recording_name() const;
    std::string get_recording_version() const;
    std::string get_user_defined_name() const;
    std::string get_notes() const;
    uint32_t    get_checksum() const;
    void        set_checksum(uint32_t val);

    // ----- substructure access -----
    const substructs::FileHeaderDeviceInfoContainer& get_devices() const;
    substructs::FileHeaderDeviceInfoContainer&       devices();
    void set_devices(const substructs::FileHeaderDeviceInfoContainer& devices);

    // ----- optional data (file catalog pointer, if present) -----
    const std::string& get_optional_data() const;
    bool               has_file_catalog_info() const;
    uint32_t           get_file_catalog_size() const;
    uint64_t           get_file_catalog_offset() const;

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
    explicit FileHeader(S7KDatagram header);
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
