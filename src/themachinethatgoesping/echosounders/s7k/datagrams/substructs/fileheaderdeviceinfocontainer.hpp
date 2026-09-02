// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/fileheaderdeviceinfocontainer.doc.hpp"

// std includes
#include <cstddef>
#include <cstdint>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "fileheaderdeviceinfo.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Container for the device entries of a 7200 FileHeader record.
 *
 * The device entries are stored as one contiguous block and read as a single bulk read. Per-field
 * numpy arrays (tensors) are built on demand.
 */
class FileHeaderDeviceInfoContainer
{
  public:
    FileHeaderDeviceInfoContainer()  = default;
    ~FileHeaderDeviceInfoContainer() = default;

    // ----- raw struct access -----
    const std::vector<FileHeaderDeviceInfo>& get_devices() const;
    std::vector<FileHeaderDeviceInfo>&       devices();
    void set_devices(const std::vector<FileHeaderDeviceInfo>& devices);

    // ----- per-field tensor access (built on demand) -----
    xt::xtensor<uint32_t, 1> get_device_identifier_tensor() const;
    xt::xtensor<uint16_t, 1> get_system_enumerator_tensor() const;

    // ----- processed -----
    size_t get_number_of_devices() const;

    // ----- operators -----
    bool operator==(const FileHeaderDeviceInfoContainer& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<FileHeaderDeviceInfo> _devices;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&& getter) const
    {
        auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _devices.size() });
        for (std::size_t idx = 0; idx < _devices.size(); ++idx)
            tensor.unchecked(idx) = static_cast<ValueType>(getter(_devices[idx]));
        return tensor;
    }
};

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
