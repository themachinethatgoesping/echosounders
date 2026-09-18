// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "fileheaderdeviceinfo.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

// ----- convenient member access -----
uint32_t FileHeaderDeviceInfo::get_device_identifier() const
{
    return _device_identifier;
}
uint16_t FileHeaderDeviceInfo::get_system_enumerator() const
{
    return _system_enumerator;
}

void FileHeaderDeviceInfo::set_device_identifier(uint32_t val)
{
    _device_identifier = val;
}
void FileHeaderDeviceInfo::set_system_enumerator(uint16_t val)
{
    _system_enumerator = val;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter FileHeaderDeviceInfo::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "FileHeaderDeviceInfo", float_precision, superscript_exponents);

    printer.register_value("device_identifier", _device_identifier);
    printer.register_value("system_enumerator", _system_enumerator);

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
