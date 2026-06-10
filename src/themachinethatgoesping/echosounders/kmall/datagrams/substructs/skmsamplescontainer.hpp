// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/skmsamplescontainer.doc.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <fmt/core.h>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

template<typename t_sample>
class SKMSamplesContainerT
{
  public:
    SKMSamplesContainerT()  = default;
    ~SKMSamplesContainerT() = default;

    // ----- vector access -----
    const std::vector<t_sample>& get_sensor_data() const { return _sensor_data; }
    std::vector<t_sample>&       sensor_data() { return _sensor_data; }
    void                         set_sensor_data(const std::vector<t_sample>& data)
    {
        _sensor_data = data;
    }

    // Vector-like compatibility helpers
    std::size_t            size() const { return _sensor_data.size(); }
    const t_sample& operator[](std::size_t idx) const { return _sensor_data[idx]; }
    t_sample&       operator[](std::size_t idx) { return _sensor_data[idx]; }
    auto begin() { return _sensor_data.begin(); }
    auto end() { return _sensor_data.end(); }
    auto begin() const { return _sensor_data.begin(); }
    auto end() const { return _sensor_data.end(); }
    auto cbegin() const { return _sensor_data.cbegin(); }
    auto cend() const { return _sensor_data.cend(); }

    // Build a reusable permutation once, then pass it into tensor getters.
    // This avoids repeated sort work when fetching many fields in timestamp order.
    std::vector<uint32_t> get_indices_sorted_by_sensor_timestamp(
        const std::vector<uint32_t>& indices = {}) const
    {
        std::vector<uint32_t> sorted_indices;
        if (indices.empty())
        {
            sorted_indices.resize(_sensor_data.size());
            std::iota(sorted_indices.begin(), sorted_indices.end(), uint32_t{ 0 });
        }
        else
        {
            sorted_indices = indices;
        }

        std::stable_sort(sorted_indices.begin(),
                         sorted_indices.end(),
                         [this](uint32_t a, uint32_t b) {
                             const bool valid_a = a < _sensor_data.size();
                             const bool valid_b = b < _sensor_data.size();

                             if (!valid_a || !valid_b)
                             {
                                 if (!valid_a && !valid_b)
                                     return a < b;
                                 return valid_a;
                             }

                             const double ta = _sensor_data[a].km_binary.get_sensor_timestamp();
                             const double tb = _sensor_data[b].km_binary.get_sensor_timestamp();
                             const bool   fa = std::isfinite(ta);
                             const bool   fb = std::isfinite(tb);

                             if (fa != fb)
                                 return fa;
                             if (!fa && !fb)
                                 return a < b;

                             return ta < tb;
                         });

        return sorted_indices;
    }

    // ----- KMBinary raw fields -----
    xt::xtensor<uint32_t, 1> get_datagram_identifier_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint32_t>(
            [](const t_sample& s) { return static_cast<uint32_t>(s.km_binary.datagram_identifier); },
            indices);
    }
    xt::xtensor<uint16_t, 1> get_bytes_content_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint16_t>([](const t_sample& s) { return s.km_binary.bytes_content; },
                                      indices);
    }
    xt::xtensor<uint16_t, 1> get_dgm_version_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint16_t>([](const t_sample& s) { return s.km_binary.dgm_version; },
                                      indices);
    }
    xt::xtensor<uint32_t, 1> get_time_sec_tensor(const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint32_t>([](const t_sample& s) { return s.km_binary.time_sec; },
                                      indices);
    }
    xt::xtensor<uint32_t, 1> get_time_nanosec_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint32_t>([](const t_sample& s) { return s.km_binary.time_nanosec; },
                                      indices);
    }
    xt::xtensor<uint32_t, 1> get_status_tensor(const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint32_t>([](const t_sample& s) { return s.km_binary.status; }, indices);
    }
    xt::xtensor<double, 1> get_latitude_deg_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<double>([](const t_sample& s) { return s.km_binary.latitude_deg; },
                                    indices);
    }
    xt::xtensor<double, 1> get_longitude_deg_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<double>([](const t_sample& s) { return s.km_binary.longitude_deg; },
                                    indices);
    }
    xt::xtensor<float, 1> get_ellipsoid_height_m_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.ellipsoid_height_m; },
                                   indices);
    }
    xt::xtensor<float, 1> get_roll_deg_tensor(const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.roll_deg; }, indices);
    }
    xt::xtensor<float, 1> get_pitch_deg_tensor(const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.pitch_deg; }, indices);
    }
    xt::xtensor<float, 1> get_heading_deg_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.heading_deg; },
                                   indices);
    }
    xt::xtensor<float, 1> get_heave_m_tensor(const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.heave_m; }, indices);
    }
    xt::xtensor<float, 1> get_roll_rate_tensor(const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.roll_rate; }, indices);
    }
    xt::xtensor<float, 1> get_pitch_rate_tensor(const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.pitch_rate; },
                                   indices);
    }
    xt::xtensor<float, 1> get_yaw_rate_tensor(const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.yaw_rate; }, indices);
    }
    xt::xtensor<float, 1> get_vel_north_tensor(const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.vel_north; },
                                   indices);
    }
    xt::xtensor<float, 1> get_vel_east_tensor(const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.vel_east; }, indices);
    }
    xt::xtensor<float, 1> get_vel_down_tensor(const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.vel_down; }, indices);
    }
    xt::xtensor<float, 1> get_latitude_error_m_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.latitude_error_m; },
                                   indices);
    }
    xt::xtensor<float, 1> get_longitude_error_m_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>(
            [](const t_sample& s) { return s.km_binary.longitude_error_m; }, indices);
    }
    xt::xtensor<float, 1> get_ellipsoid_height_error_m_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>(
            [](const t_sample& s) { return s.km_binary.ellipsoid_height_error_m; }, indices);
    }
    xt::xtensor<float, 1> get_roll_error_deg_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.roll_error_deg; },
                                   indices);
    }
    xt::xtensor<float, 1> get_pitch_error_deg_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.pitch_error_deg; },
                                   indices);
    }
    xt::xtensor<float, 1> get_heading_error_deg_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>(
            [](const t_sample& s) { return s.km_binary.heading_error_deg; }, indices);
    }
    xt::xtensor<float, 1> get_heave_error_m_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.heave_error_m; },
                                   indices);
    }
    xt::xtensor<float, 1> get_north_acceleration_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>(
            [](const t_sample& s) { return s.km_binary.north_acceleration; }, indices);
    }
    xt::xtensor<float, 1> get_east_acceleration_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.east_acceleration; },
                                   indices);
    }
    xt::xtensor<float, 1> get_down_acceleration_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>([](const t_sample& s) { return s.km_binary.down_acceleration; },
                                   indices);
    }

    // ----- KMDelayedHeave raw fields -----
    xt::xtensor<uint32_t, 1> get_delayed_heave_time_sec_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint32_t>(
            [](const t_sample& s) { return s.km_delayed_heave.time_sec; }, indices);
    }
    xt::xtensor<uint32_t, 1> get_delayed_heave_time_nanosec_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint32_t>(
            [](const t_sample& s) { return s.km_delayed_heave.time_nanosec; }, indices);
    }
    xt::xtensor<float, 1> get_delayed_heave_m_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<float>(
            [](const t_sample& s) { return s.km_delayed_heave.delayed_heave_m; }, indices);
    }

    // ----- processed -----
    xt::xtensor<double, 1> get_sensor_timestamp_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<double>(
            [](const t_sample& s) { return s.km_binary.get_sensor_timestamp(); }, indices);
    }

    xt::xtensor<uint8_t, 1> get_horizontal_position_and_velocity_valid_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) {
                return static_cast<uint8_t>(s.km_binary.get_horizontal_position_and_velocity_valid());
            },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_roll_and_pitch_valid_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) { return static_cast<uint8_t>(s.km_binary.get_roll_and_pitch_valid()); },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_heading_valid_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) { return static_cast<uint8_t>(s.km_binary.get_heading_valid()); },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_heave_valid_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) { return static_cast<uint8_t>(s.km_binary.get_heave_valid()); },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_acceleration_valid_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) { return static_cast<uint8_t>(s.km_binary.get_acceleration_valid()); },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_delayed_heave1_valid_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) {
                return static_cast<uint8_t>(s.km_binary.get_delayed_heave1_valid());
            },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_delayed_heave2_valid_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) {
                return static_cast<uint8_t>(s.km_binary.get_delayed_heave2_valid());
            },
            indices);
    }

    xt::xtensor<uint8_t, 1> get_horizontal_position_and_velocity_reduced_performance_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) {
                return static_cast<uint8_t>(
                    s.km_binary.get_horizontal_position_and_velocity_reduced_performance());
            },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_roll_and_pitch_reduced_performance_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) {
                return static_cast<uint8_t>(s.km_binary.get_roll_and_pitch_reduced_performance());
            },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_heading_reduced_performance_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) {
                return static_cast<uint8_t>(s.km_binary.get_heading_reduced_performance());
            },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_heave_reduced_performance_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) {
                return static_cast<uint8_t>(s.km_binary.get_heave_reduced_performance());
            },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_acceleration_reduced_performance_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) {
                return static_cast<uint8_t>(s.km_binary.get_acceleration_reduced_performance());
            },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_delayed_heave1_reduced_performance_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) {
                return static_cast<uint8_t>(
                    s.km_binary.get_delayed_heave1_reduced_performance());
            },
            indices);
    }
    xt::xtensor<uint8_t, 1> get_delayed_heave2_reduced_performance_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<uint8_t>(
            [](const t_sample& s) {
                return static_cast<uint8_t>(
                    s.km_binary.get_delayed_heave2_reduced_performance());
            },
            indices);
    }

    xt::xtensor<double, 1> get_delayed_heave_timestamp_tensor(
        const std::vector<uint32_t>& indices = {}) const
    {
        return build_tensor<double>(
            [](const t_sample& s) { return s.km_delayed_heave.get_sensor_timestamp(); }, indices);
    }

    // ----- size -----
    size_t get_number_of_samples() const { return _sensor_data.size(); }

    // ----- operators -----
    bool operator==(const SKMSamplesContainerT<t_sample>& other) const = default;

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "SKMSamplesContainer", float_precision, superscript_exponents);

        printer.register_section("Sensor Data (.sensor_data)");
        printer.register_value("sensor_data (vector)",
                               fmt::format("size={}", get_number_of_samples()),
                               "samples");

        printer.register_container("datagram_identifier", get_datagram_identifier_tensor());
        printer.register_container("bytes_content", get_bytes_content_tensor(), "bytes");
        printer.register_container("dgm_version", get_dgm_version_tensor());
        printer.register_container("time_sec", get_time_sec_tensor(), "s");
        printer.register_container("time_nanosec", get_time_nanosec_tensor(), "ns");
        printer.register_container("status", get_status_tensor());
        printer.register_container("latitude_deg", get_latitude_deg_tensor(), "deg");
        printer.register_container("longitude_deg", get_longitude_deg_tensor(), "deg");
        printer.register_container("ellipsoid_height_m", get_ellipsoid_height_m_tensor(), "m");
        printer.register_container("roll_deg", get_roll_deg_tensor(), "deg");
        printer.register_container("pitch_deg", get_pitch_deg_tensor(), "deg");
        printer.register_container("heading_deg", get_heading_deg_tensor(), "deg");
        printer.register_container("heave_m", get_heave_m_tensor(), "m");
        printer.register_container("roll_rate", get_roll_rate_tensor(), "deg/s");
        printer.register_container("pitch_rate", get_pitch_rate_tensor(), "deg/s");
        printer.register_container("yaw_rate", get_yaw_rate_tensor(), "deg/s");
        printer.register_container("vel_north", get_vel_north_tensor(), "m/s");
        printer.register_container("vel_east", get_vel_east_tensor(), "m/s");
        printer.register_container("vel_down", get_vel_down_tensor(), "m/s");
        printer.register_container("latitude_error_m", get_latitude_error_m_tensor(), "m");
        printer.register_container("longitude_error_m", get_longitude_error_m_tensor(), "m");
        printer.register_container(
            "ellipsoid_height_error_m", get_ellipsoid_height_error_m_tensor(), "m");
        printer.register_container("roll_error_deg", get_roll_error_deg_tensor(), "deg");
        printer.register_container("pitch_error_deg", get_pitch_error_deg_tensor(), "deg");
        printer.register_container("heading_error_deg", get_heading_error_deg_tensor(), "deg");
        printer.register_container("heave_error_m", get_heave_error_m_tensor(), "m");
        printer.register_container(
            "north_acceleration", get_north_acceleration_tensor(), "m/s^2");
        printer.register_container(
            "east_acceleration", get_east_acceleration_tensor(), "m/s^2");
        printer.register_container(
            "down_acceleration", get_down_acceleration_tensor(), "m/s^2");
        printer.register_container(
            "delayed_heave_time_sec", get_delayed_heave_time_sec_tensor(), "s");
        printer.register_container(
            "delayed_heave_time_nanosec", get_delayed_heave_time_nanosec_tensor(), "ns");
        printer.register_container("delayed_heave_m", get_delayed_heave_m_tensor(), "m");

        printer.register_section("processed");
        printer.register_value("number_of_samples", get_number_of_samples());
        printer.register_container(
            "indices_sorted_by_sensor_timestamp", get_indices_sorted_by_sensor_timestamp());
        printer.register_container("sensor_timestamp", get_sensor_timestamp_tensor(), "s");
        printer.register_container(
            "delayed_heave_timestamp", get_delayed_heave_timestamp_tensor(), "s");
        printer.register_container("horizontal_position_and_velocity_valid",
                                   get_horizontal_position_and_velocity_valid_tensor());
        printer.register_container("roll_and_pitch_valid", get_roll_and_pitch_valid_tensor());
        printer.register_container("heading_valid", get_heading_valid_tensor());
        printer.register_container("heave_valid", get_heave_valid_tensor());
        printer.register_container("acceleration_valid", get_acceleration_valid_tensor());
        printer.register_container("delayed_heave1_valid", get_delayed_heave1_valid_tensor());
        printer.register_container("delayed_heave2_valid", get_delayed_heave2_valid_tensor());
        printer.register_container(
            "horizontal_position_and_velocity_reduced_performance",
            get_horizontal_position_and_velocity_reduced_performance_tensor());
        printer.register_container("roll_and_pitch_reduced_performance",
                                   get_roll_and_pitch_reduced_performance_tensor());
        printer.register_container("heading_reduced_performance",
                                   get_heading_reduced_performance_tensor());
        printer.register_container("heave_reduced_performance",
                                   get_heave_reduced_performance_tensor());
        printer.register_container("acceleration_reduced_performance",
                                   get_acceleration_reduced_performance_tensor());
        printer.register_container(
            "delayed_heave1_reduced_performance",
            get_delayed_heave1_reduced_performance_tensor());
        printer.register_container(
            "delayed_heave2_reduced_performance",
            get_delayed_heave2_reduced_performance_tensor());

        return printer;
    }

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<t_sample> _sensor_data;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&&                     getter,
                                           const std::vector<uint32_t>& indices) const
    {
        if (indices.empty())
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _sensor_data.size() });
            for (std::size_t idx = 0; idx < _sensor_data.size(); ++idx)
            {
                tensor.unchecked(idx) = static_cast<ValueType>(getter(_sensor_data[idx]));
            }
            return tensor;
        }

        auto tensor = xt::xtensor<ValueType, 1>::from_shape({ indices.size() });
        for (std::size_t si = 0; si < indices.size(); ++si)
        {
            const auto idx = indices[si];
            if (idx >= _sensor_data.size())
            {
                if constexpr (std::is_floating_point_v<ValueType>)
                    tensor.unchecked(si) = std::numeric_limits<ValueType>::quiet_NaN();
                else
                    tensor.unchecked(si) = ValueType{ 0 };
            }
            else
            {
                tensor.unchecked(si) = static_cast<ValueType>(getter(_sensor_data[idx]));
            }
        }

        return tensor;
    }
};

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
