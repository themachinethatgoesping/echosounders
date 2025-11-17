// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/sclock.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "kmallsensordatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

/**
 * @brief Clock datagrams
 */
class SClock : public KMALLSensorDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KMALLDatagramIdentifier::S_CLOCK;

  protected:
    // 4-byte alignment can be a performance penalty for the doubles (they are packed unaligned now)
    // should not be a problem for this structure, the penalty would otherwise occur when reading
    // the memory and applying an extra copy to aligned memory on larger/compute intensive
    // structures this should be considered more carefully
#pragma pack(push, 4) // force 4-byte alignment
    struct Content
    {
        float   offset_sec;
        int32_t clock_dev_pu_microsec;

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __size = 8; // size till clock_data_from_sensor

    std::string _clock_data_from_sensor;
    uint32_t    _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                       ///< integrity check

  public:
    // ----- public constructors -----
    SClock();
    ~SClock() = default;

    // ----- convenient data access -----
    float              get_offset_sec() const { return _content.offset_sec; }
    int32_t            get_clock_dev_pu_microsec() const { return _content.clock_dev_pu_microsec; }
    const std::string& get_clock_data_from_sensor() const { return _clock_data_from_sensor; }
    uint32_t           get_bytes_datagram_check() const { return _bytes_datagram_check; }

    void set_offset_sec(float offset_sec) { _content.offset_sec = offset_sec; }
    void set_clock_dev_pu_microsec(int32_t clock_dev_pu_microsec)
    {
        _content.clock_dev_pu_microsec = clock_dev_pu_microsec;
    }
    void set_clock_data_from_sensor(std::string_view pos_data);
    void set_bytes_datagram_check(uint32_t val) { _bytes_datagram_check = val; }

    // ----- operators -----
    bool operator==(const SClock& other) const = default;

    //----- to/from stream functions -----
    static SClock from_stream(std::istream& is, const KMALLDatagram& header);

    static SClock from_stream(std::istream& is, o_KMALLDatagramIdentifier datagram_identifier);

    static SClock from_stream(std::istream& is);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SClock)

  private:
    explicit SClock(const KMALLDatagram& header)
        : KMALLSensorDatagram(header)
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
