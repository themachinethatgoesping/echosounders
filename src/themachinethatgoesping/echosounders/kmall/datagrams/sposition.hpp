// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/sposition.doc.hpp"

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
class SPosition : public KMALLSensorDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KMALLDatagramIdentifier::S_POSITION;

  protected:
    // 4-byte alignment can be a performance penalty for the doubles (they are packed unaligned now)
    // should not be a problem for this structure, the penalty would otherwise occur when reading the
    // memory and applying an extra copy to aligned memory
    // on larger/compute intensive structures this should be considered more carefully
#pragma pack(push, 4) // force 4-byte alignment
    struct Content
    {
        uint32_t time_from_sensor_sec;
        uint32_t time_from_sensor_nanosec;
        float    pos_fix_quality_m;
        double   corrected_lat_deg;
        double   corrected_lon_deg;
        float    speed_over_ground_m_per_sec;
        float    course_over_ground_deg;
        float    ellipsoid_height_re_ref_point_m;

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __size = 40; // size till pos_data_from_sensor

    std::string _pos_data_from_sensor;
    uint32_t    _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                       ///< integrity check

  public:
    // ----- public constructors -----
    SPosition();
    ~SPosition() = default;

    // ----- convenient data access -----
    uint32_t get_time_from_sensor_sec() const { return _content.time_from_sensor_sec; }
    uint32_t get_time_from_sensor_nanosec() const { return _content.time_from_sensor_nanosec; }
    float    get_pos_fix_quality_m() const { return _content.pos_fix_quality_m; }
    double   get_corrected_lat_deg() const { return _content.corrected_lat_deg; }
    double   get_corrected_lon_deg() const { return _content.corrected_lon_deg; }
    float get_speed_over_ground_m_per_sec() const { return _content.speed_over_ground_m_per_sec; }
    float get_course_over_ground_deg() const { return _content.course_over_ground_deg; }
    float get_ellipsoid_height_re_ref_point_m() const
    {
        return _content.ellipsoid_height_re_ref_point_m;
    }
    const std::string& get_pos_data_from_sensor() const { return _pos_data_from_sensor; }
    uint32_t           get_bytes_datagram_check() const { return _bytes_datagram_check; }

    void set_time_from_sensor_sec(uint32_t val) { _content.time_from_sensor_sec = val; }
    void set_time_from_sensor_nanosec(uint32_t val) { _content.time_from_sensor_nanosec = val; }
    void set_pos_fix_quality_m(float val) { _content.pos_fix_quality_m = val; }
    void set_corrected_lat_deg(double val) { _content.corrected_lat_deg = val; }
    void set_corrected_lon_deg(double val) { _content.corrected_lon_deg = val; }
    void set_speed_over_ground_m_per_sec(float val) { _content.speed_over_ground_m_per_sec = val; }
    void set_course_over_ground_deg(float val) { _content.course_over_ground_deg = val; }
    void set_ellipsoid_height_re_ref_point_m(float val)
    {
        _content.ellipsoid_height_re_ref_point_m = val;
    }
    void set_pos_data_from_sensor(std::string_view pos_data);
    void set_bytes_datagram_check(uint32_t val) { _bytes_datagram_check = val; }

    // ----- processed data access -----
    double get_sensor_timestamp() const;

    /**
     * @brief Get the time as string
     *
     * @param fractionalSecondsDigits
     * @param format
     * @return std::string
     */
    std::string get_sensor_date_string(unsigned int       fractionalSecondsDigits = 2,
                                       const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const;

    // ----- operators -----
    bool operator==(const SPosition& other) const = default;

    //----- to/from stream functions -----
    static SPosition from_stream(std::istream& is, const KMALLDatagram& header);

    static SPosition from_stream(std::istream& is, o_KMALLDatagramIdentifier datagram_identifier);

    static SPosition from_stream(std::istream& is);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SPosition)

  private:
    explicit SPosition(const KMALLDatagram& header)
        : KMALLSensorDatagram(header)
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
