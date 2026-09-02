// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "fileheaderdeviceinfocontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

const std::vector<FileHeaderDeviceInfo>& FileHeaderDeviceInfoContainer::get_devices() const
{
    return _devices;
}

std::vector<FileHeaderDeviceInfo>& FileHeaderDeviceInfoContainer::devices()
{
    return _devices;
}

void FileHeaderDeviceInfoContainer::set_devices(const std::vector<FileHeaderDeviceInfo>& devices)
{
    _devices = devices;
}

xt::xtensor<uint32_t, 1> FileHeaderDeviceInfoContainer::get_device_identifier_tensor() const
{
    return build_tensor<uint32_t>(
        [](const FileHeaderDeviceInfo& device) { return device.get_device_identifier(); });
}

xt::xtensor<uint16_t, 1> FileHeaderDeviceInfoContainer::get_system_enumerator_tensor() const
{
    return build_tensor<uint16_t>(
        [](const FileHeaderDeviceInfo& device) { return device.get_system_enumerator(); });
}

size_t FileHeaderDeviceInfoContainer::get_number_of_devices() const
{
    return _devices.size();
}

tools::classhelper::ObjectPrinter FileHeaderDeviceInfoContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "FileHeaderDeviceInfoContainer", float_precision, superscript_exponents);

    printer.register_value("number_of_devices", get_number_of_devices());

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
