// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/spositionerror.doc.hpp"

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
class SPositionError : public KMALLSensorDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KMALLDatagramIdentifier::S_POSITION_ERROR;

  protected:
    // 4-byte alignment can be a performance penalty for the doubles (they are packed unaligned now)
    // should not be a problem for this structure, the penalty would otherwise occur when reading
    // the memory and applying an extra copy to aligned memory on larger/compute intensive
    // structures this should be considered more carefully
#pragma pack(push, 4) // force 4-byte alignment 
    struct Content
    {
        uint32_t time_from_sensor_sec;
        uint32_t time_from_sensor_nanosec;
        float    range_input_rms;
        float    ellipse_semi_major_axis_error_m;
        float    ellipse_semi_minor_axis_error_m;
        float    ellipse_erientation_error_deg;
        float    latitude_error_m;
        float    longitude_error_m;
        float    height_error_m;

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __size = 9*4; // size till pos_error_data_from_sensor

    std::string _pos_error_data_from_sensor;
    uint32_t    _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                       ///< integrity check

  public:
    // ----- public constructors -----
    SPositionError();
    ~SPositionError() = default;

    // ----- convenient data access -----
    uint32_t get_time_from_sensor_sec() const { return _content.time_from_sensor_sec; }
    uint32_t get_time_from_sensor_nanosec() const { return _content.time_from_sensor_nanosec; }
    float    get_range_input_rms() const { return _content.range_input_rms; }
    float    get_ellipse_semi_major_axis_error_m() const
    { return _content.ellipse_semi_major_axis_error_m; }
    float get_ellipse_semi_minor_axis_error_m() const
    { return _content.ellipse_semi_minor_axis_error_m; }
    float get_ellipse_erientation_error_deg() const
    { return _content.ellipse_erientation_error_deg; }
    float get_latitude_error_m() const { return _content.latitude_error_m; }
    float get_longitude_error_m() const { return _content.longitude_error_m; }
    float get_height_error_m() const { return _content.height_error_m; }
    const std::string& get_pos_error_data_from_sensor() const { return _pos_error_data_from_sensor; }
    uint32_t           get_bytes_datagram_check() const { return _bytes_datagram_check; }

    void set_time_from_sensor_sec(uint32_t val) { _content.time_from_sensor_sec = val; }
    void set_time_from_sensor_nanosec(uint32_t val) { _content.time_from_sensor_nanosec = val; }
    void set_range_input_rms(float val) { _content.range_input_rms = val; }
    void set_ellipse_semi_major_axis_error_m(float val)
    { _content.ellipse_semi_major_axis_error_m = val; }
    void set_ellipse_semi_minor_axis_error_m(float val)
    { _content.ellipse_semi_minor_axis_error_m = val; }
    void set_ellipse_erientation_error_deg(float val) { _content.ellipse_erientation_error_deg = val; }
    void set_latitude_error_m(float val) { _content.latitude_error_m = val; }
    void set_longitude_error_m(float val) { _content.longitude_error_m = val; }
    void set_height_error_m(float val) { _content.height_error_m = val; }
    void set_pos_error_data_from_sensor(std::string_view pos_error_data);
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
    bool operator==(const SPositionError& other) const = default;

    //----- to/from stream functions -----
    static SPositionError from_stream(std::istream& is, const KMALLDatagram& header);

    static SPositionError from_stream(std::istream&             is,
                                      o_KMALLDatagramIdentifier datagram_identifier);

    static SPositionError from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SPositionError)

  private:
    explicit SPositionError(const KMALLDatagram& header)
        : KMALLSensorDatagram(header)
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
