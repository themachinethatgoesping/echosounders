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
#pragma pack(push, 1)
class FileHeaderDeviceInfo
{
    uint32_t _device_identifier = 0; ///< device identifier
    uint16_t _system_enumerator = 0; ///< system enumerator (differentiates devices with same id)

  public:
    FileHeaderDeviceInfo()  = default;
    ~FileHeaderDeviceInfo() = default;

    // ----- convenient member access -----
    uint32_t get_device_identifier() const { return _device_identifier; }
    uint16_t get_system_enumerator() const { return _system_enumerator; }

    void set_device_identifier(uint32_t val) { _device_identifier = val; }
    void set_system_enumerator(uint16_t val) { _system_enumerator = val; }

    // ----- operators -----
    bool operator==(const FileHeaderDeviceInfo& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "FileHeaderDeviceInfo", float_precision, superscript_exponents);

        printer.register_value("device_identifier", _device_identifier);
        printer.register_value("system_enumerator", _system_enumerator);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};
#pragma pack(pop)

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
