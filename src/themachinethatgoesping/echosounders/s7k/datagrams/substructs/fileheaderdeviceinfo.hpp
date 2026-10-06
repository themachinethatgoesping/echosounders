// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/fileheaderdeviceinfo.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Single device entry of a 7200 FileHeader record.
 *
 * The device entries are stored as one contiguous block and read as a single bulk read.
 */
#pragma pack(push, 1) // byte-packed on disk (7k spec); bulk read as one contiguous block
class FileHeaderDeviceInfo
{
    uint32_t _device_identifier = 0; ///< device identifier
    uint16_t _system_enumerator = 0; ///< system enumerator (differentiates devices with same id)

  public:
    FileHeaderDeviceInfo()  = default;
    ~FileHeaderDeviceInfo() = default;

    // ----- convenient member access -----
    uint32_t get_device_identifier() const;
    uint16_t get_system_enumerator() const;

    void set_device_identifier(uint32_t val);
    void set_system_enumerator(uint16_t val);

    // ----- operators -----
    // NOTE: user-provided (NOT defaulted) on purpose. A defaulted operator== makes this tightly
    // packed, all-integer 6-byte struct "trivially equality comparable", which makes clang-cl /
    // MSVC route std::find/count/remove (instantiated by nanobind's bind_vector) through a SIMD
    // path that only supports element sizes 1/2/4/8 bytes and fails to compile ("unexpected
    // size") for 6 bytes. A user-provided operator== keeps the scalar path while preserving the
    // on-disk layout. See the s7k skill / meson.build note.
    bool operator==(const FileHeaderDeviceInfo& other) const
    {
        return _device_identifier == other._device_identifier &&
               _system_enumerator == other._system_enumerator;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};
#pragma pack(pop)

static_assert(sizeof(FileHeaderDeviceInfo) == 6,
              "s7k FileHeaderDeviceInfo (7200 RD): must equal the 6-byte packed on-disk entry");

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
