// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallsensordatagram.doc.hpp"

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
class KMALLSensorDatagram : public KMALLDatagram
{
  public:
    static constexpr auto   DatagramIdentifier = t_KMALLDatagramIdentifier::I_OP_RUNTIME;
    static constexpr size_t __size             = 4 * sizeof(uint16_t);

  protected:
    struct SCommon
    {
        uint16_t bytes_content; ///<  bytes of the datagram body (should be __size)
        uint16_t sensor_system; ///< Sensor system number
        uint16_t sensor_status; ///< Sensor status
        uint16_t padding;       ///< Padding for 4 byte alignment

        bool operator==(const SCommon& other) const = default;
    } _scommon;

  public:
    // ----- public constructors -----
    KMALLSensorDatagram()  = default;
    ~KMALLSensorDatagram() = default;

    // ----- convenient data access -----
    // Getters
    uint16_t get_bytes_content() const { return _scommon.bytes_content; }
    uint16_t get_sensor_system() const { return _scommon.sensor_system; }
    uint16_t get_sensor_status() const { return _scommon.sensor_status; }
    uint16_t get_padding() const { return _scommon.padding; }

    // Setters
    void set_bytes_content(uint16_t value) { _scommon.bytes_content = value; }
    void set_sensor_system(uint16_t value) { _scommon.sensor_system = value; }
    void set_sensor_status(uint16_t value) { _scommon.sensor_status = value; }
    void set_padding(uint16_t value) { _scommon.padding = value; }

    // ----- processed data access -----

    // ----- operators -----
    bool operator==(const KMALLSensorDatagram& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

  protected:
    explicit KMALLSensorDatagram(const KMALLDatagram& header)
        : KMALLDatagram(header)
    {
    }
    inline void __read_sensordatagram__(std::istream& is)
    {
        is.read(reinterpret_cast<char*>(&_scommon), sizeof(SCommon));
    }
    inline void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&_scommon), sizeof(SCommon));
    }
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
