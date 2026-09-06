// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7knavigationdatainterfaceperfile.doc.hpp"

/* std includes */
#include <algorithm>
#include <cmath>
#include <numbers>
#include <numeric>
#include <vector>

#include <fmt/format.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datainterfaces/i_navigationdatainterface.hpp"
#include "s7kconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"
#include "s7kdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatainterfaces {

/**
 * @brief Interface that reads the navigation (position, attitude, heading) of a single .s7k file.
 *
 * The 7k format stores each navigation quantity in two kinds of records: a modern "fused" record
 * (1015 Navigation for position/heading, 1016 Attitude for roll/pitch/heave/heading) and a legacy
 * single-quantity record (1003 Position, 1012 Roll Pitch Heave, 1013 Heading). By default the modern
 * records are preferred; the two preferences can be toggled with the setters below.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KNavigationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
          S7KConfigurationDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
        S7KConfigurationDataInterface<t_ifstream>>;

    bool _prefer_navigation_over_position = true; ///< Prefer 1015 Navigation over 1003 Position
    bool _prefer_attitude_over_rollpitchheave =
        true; ///< Prefer 1016 Attitude over 1012 Roll Pitch Heave

  public:
    S7KNavigationDataInterfacePerFile()
        : t_base("S7KNavigationDataInterfacePerFile")
    {
    }
    S7KNavigationDataInterfacePerFile(
        std::shared_ptr<S7KConfigurationDataInterface<t_ifstream>> configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "S7KNavigationDataInterfacePerFile")
    {
    }
    ~S7KNavigationDataInterfacePerFile() = default;

    // ----- getters/setters for datagram preference -----
    /**
     * @brief Get whether the 1015 Navigation record is preferred over the 1003 Position record
     * @return true if 1015 Navigation is preferred (default)
     */
    bool get_prefer_navigation_over_position() const { return _prefer_navigation_over_position; }

    /**
     * @brief Get whether the 1016 Attitude record is preferred over the 1012 Roll Pitch Heave record
     * @return true if 1016 Attitude is preferred (default)
     */
    bool get_prefer_attitude_over_rollpitchheave() const
    {
        return _prefer_attitude_over_rollpitchheave;
    }

    /**
     * @brief Set whether the 1015 Navigation record is preferred over the 1003 Position record
     * @param prefer true to prefer 1015 Navigation (default), false to prefer 1003 Position
     */
    void set_prefer_navigation_over_position(bool prefer)
    {
        _prefer_navigation_over_position = prefer;
    }

    /**
     * @brief Set whether the 1016 Attitude record is preferred over the 1012 Roll Pitch Heave record
     * @param prefer true to prefer 1016 Attitude (default), false to prefer 1012 Roll Pitch Heave
     */
    void set_prefer_attitude_over_rollpitchheave(bool prefer)
    {
        _prefer_attitude_over_rollpitchheave = prefer;
    }

    navigation::NavigationInterpolatorLatLon read_navigation_data() const final
    {
        // Treat the sensor configuration as a real one even if the file has no offset records: an
        // empty SensorConfiguration means zero offsets, which is a valid configuration here.
        navigation::NavigationInterpolatorLatLon navi(
            this->configuration_data_interface_const().get_sensor_configuration(
                this->get_file_nr()));

        /* ----- position (latitude / longitude) ----- */
        std::vector<double> times_pos, latitudes, longitudes;

        const bool has_navigation = has_datagrams(t_S7KDatagramIdentifier::Navigation);
        const bool has_position   = has_datagrams(t_S7KDatagramIdentifier::Position);

        bool use_navigation = _prefer_navigation_over_position;
        if (use_navigation && !has_navigation && has_position)
            use_navigation = false;
        if (!use_navigation && !has_position && has_navigation)
            use_navigation = true;

        if (use_navigation && has_navigation)
            read_position_from_navigation(times_pos, latitudes, longitudes);
        else if (has_position)
            read_position_from_position(times_pos, latitudes, longitudes);

        /* ----- roll / pitch, heave (and heading when it comes from 1016 Attitude) ----- */
        std::vector<float>  pitchs, rolls, headings;
        std::vector<double> heaves;
        std::vector<double> times_pitch_roll, times_heave, times_heading;

        const bool has_attitude       = has_datagrams(t_S7KDatagramIdentifier::Attitude);
        const bool has_rollpitchheave = has_datagrams(t_S7KDatagramIdentifier::RollPitchHeave);

        bool use_attitude = _prefer_attitude_over_rollpitchheave;
        if (use_attitude && !has_attitude && has_rollpitchheave)
            use_attitude = false;
        if (!use_attitude && !has_rollpitchheave && has_attitude)
            use_attitude = true;

        if (use_attitude && has_attitude)
            // 1016 Attitude carries roll, pitch, heave AND heading together (like the Kongsberg SKM
            // record), so the heading is filled here as well.
            read_attitude_from_attitude(
                times_pitch_roll, pitchs, rolls, times_heave, heaves, times_heading, headings);
        else if (has_rollpitchheave)
            // 1012 Roll Pitch Heave carries roll, pitch and heave only (no heading).
            read_attitude_from_rollpitchheave(times_pitch_roll, pitchs, rolls, times_heave, heaves);

        /* ----- heading fallback (1012 has no heading, or 1016 was not used) ----- */
        // Prefer the fused Navigation (1015) heading over the dedicated Heading (1013) record; only
        // use the 1016 Attitude heading here if nothing else is available.
        if (times_heading.empty())
        {
            if (has_navigation)
                read_heading_from_navigation(times_heading, headings);
            else if (has_datagrams(t_S7KDatagramIdentifier::Heading))
                read_heading_from_heading(times_heading, headings);
            else if (has_attitude)
                read_heading_from_attitude(times_heading, headings);
        }

        /* ----- sort, deduplicate and store ----- */
        sort_and_deduplicate_time_series(times_pos, latitudes, longitudes);
        sort_and_deduplicate_time_series(times_pitch_roll, pitchs, rolls);
        sort_and_deduplicate_time_series(times_heading, headings);
        sort_and_deduplicate_time_series(times_heave, heaves);

        navi.set_data_attitude(std::move(times_pitch_roll), std::move(pitchs), std::move(rolls));
        navi.set_data_heading(std::move(times_heading), std::move(headings));
        navi.set_data_heave(std::move(times_heave), std::move(heaves));
        navi.set_data_position(std::move(times_pos), std::move(latitudes), std::move(longitudes));

        return navi;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("S7KNavigationDataInterfacePerFile");
        printer.register_value("prefer_navigation_over_position", _prefer_navigation_over_position);
        printer.register_value("prefer_attitude_over_rollpitchheave",
                               _prefer_attitude_over_rollpitchheave);

        return printer;
    }

  private:
    /// Convert radians to degrees (7k stores angles in radians, the interpolator expects degrees).
    static constexpr double rad_to_deg = 180.0 / std::numbers::pi;

    /// @brief Check whether the file contains at least one datagram of the given type.
    bool has_datagrams(t_S7KDatagramIdentifier datagram_identifier) const
    {
        return this->_datagram_infos_by_type.contains(datagram_identifier) &&
               !this->_datagram_infos_by_type.at_const(datagram_identifier).empty();
    }

    /**
     * @brief Read position (latitude/longitude) from the 1015 Navigation records.
     */
    void read_position_from_navigation(std::vector<double>& times_pos,
                                       std::vector<double>& latitudes,
                                       std::vector<double>& longitudes) const
    {
        for (const auto& packet :
             this->_datagram_infos_by_type.at_const(t_S7KDatagramIdentifier::Navigation))
        {
            auto datagram = packet->template read_datagram_from_file<datagrams::Navigation>();

            times_pos.push_back(datagram.get_timestamp());
            latitudes.push_back(datagram.get_latitude_in_degrees());
            longitudes.push_back(datagram.get_longitude_in_degrees());
        }
    }

    /**
     * @brief Read position (latitude/longitude) from the 1003 Position records.
     *
     * Only geographical coordinates are supported; records in grid coordinates are skipped.
     */
    void read_position_from_position(std::vector<double>& times_pos,
                                     std::vector<double>& latitudes,
                                     std::vector<double>& longitudes) const
    {
        for (const auto& packet :
             this->_datagram_infos_by_type.at_const(t_S7KDatagramIdentifier::Position))
        {
            auto datagram = packet->template read_datagram_from_file<datagrams::Position>();

            if (datagram.get_position_type_flag() ==
                datagrams::Position::t_position_type_flag::grid)
                continue;

            times_pos.push_back(datagram.get_timestamp());
            latitudes.push_back(datagram.get_latitude_in_degrees());
            longitudes.push_back(datagram.get_longitude_in_degrees());
        }
    }

    /**
     * @brief Read roll, pitch, heave and heading from the 1016 Attitude records.
     *
     * Each 1016 record holds several samples, each with a time offset (delta_time, in ms) relative
     * to the record timestamp. The 7k sign conventions (7k DFD Table 2) match ours: roll +port up,
     * pitch +bow up, heave +up, heading true north-referenced -> no sign flips are needed.
     */
    void read_attitude_from_attitude(std::vector<double>& times_pitch_roll,
                                     std::vector<float>&  pitchs,
                                     std::vector<float>&  rolls,
                                     std::vector<double>& times_heave,
                                     std::vector<double>& heaves,
                                     std::vector<double>& times_heading,
                                     std::vector<float>&  headings) const
    {
        for (const auto& packet :
             this->_datagram_infos_by_type.at_const(t_S7KDatagramIdentifier::Attitude))
        {
            auto         datagram  = packet->template read_datagram_from_file<datagrams::Attitude>();
            const double base_time = datagram.get_timestamp();

            for (const auto& sample : datagram.get_attitudes().get_attitudes())
            {
                const double timestamp = base_time + double(sample.get_delta_time()) * 0.001;

                times_pitch_roll.push_back(timestamp);
                pitchs.push_back(float(double(sample.get_pitch()) * rad_to_deg));
                rolls.push_back(float(double(sample.get_roll()) * rad_to_deg));

                times_heave.push_back(timestamp);
                // s7k heave is positive up (7k DFD Table 2) -> matches our convention (no sign flip).
                heaves.push_back(double(sample.get_heave()));

                times_heading.push_back(timestamp);
                headings.push_back(float(double(sample.get_heading()) * rad_to_deg));
            }
        }
    }

    /**
     * @brief Read roll, pitch and heave from the 1012 Roll Pitch Heave records (no heading).
     */
    void read_attitude_from_rollpitchheave(std::vector<double>& times_pitch_roll,
                                           std::vector<float>&  pitchs,
                                           std::vector<float>&  rolls,
                                           std::vector<double>& times_heave,
                                           std::vector<double>& heaves) const
    {
        for (const auto& packet :
             this->_datagram_infos_by_type.at_const(t_S7KDatagramIdentifier::RollPitchHeave))
        {
            auto         datagram  = packet->template read_datagram_from_file<datagrams::RollPitchHeave>();
            const double timestamp = datagram.get_timestamp();

            times_pitch_roll.push_back(timestamp);
            pitchs.push_back(datagram.get_pitch_in_degrees());
            rolls.push_back(datagram.get_roll_in_degrees());

            times_heave.push_back(timestamp);
            // s7k heave is positive up (7k DFD Table 2) -> matches our convention (no sign flip).
            heaves.push_back(double(datagram.get_heave()));
        }
    }

    /**
     * @brief Read heading from the 1015 Navigation records.
     */
    void read_heading_from_navigation(std::vector<double>& times_heading,
                                      std::vector<float>&  headings) const
    {
        for (const auto& packet :
             this->_datagram_infos_by_type.at_const(t_S7KDatagramIdentifier::Navigation))
        {
            auto datagram = packet->template read_datagram_from_file<datagrams::Navigation>();

            times_heading.push_back(datagram.get_timestamp());
            headings.push_back(datagram.get_heading_in_degrees());
        }
    }

    /**
     * @brief Read heading from the 1013 Heading records.
     */
    void read_heading_from_heading(std::vector<double>& times_heading,
                                   std::vector<float>&  headings) const
    {
        for (const auto& packet :
             this->_datagram_infos_by_type.at_const(t_S7KDatagramIdentifier::Heading))
        {
            auto datagram = packet->template read_datagram_from_file<datagrams::Heading>();

            times_heading.push_back(datagram.get_timestamp());
            headings.push_back(datagram.get_heading_in_degrees());
        }
    }

    /**
     * @brief Read heading only from the 1016 Attitude records (roll/pitch/heave read elsewhere).
     */
    void read_heading_from_attitude(std::vector<double>& times_heading,
                                    std::vector<float>&  headings) const
    {
        for (const auto& packet :
             this->_datagram_infos_by_type.at_const(t_S7KDatagramIdentifier::Attitude))
        {
            auto         datagram  = packet->template read_datagram_from_file<datagrams::Attitude>();
            const double base_time = datagram.get_timestamp();

            for (const auto& sample : datagram.get_attitudes().get_attitudes())
            {
                times_heading.push_back(base_time + double(sample.get_delta_time()) * 0.001);
                headings.push_back(float(double(sample.get_heading()) * rad_to_deg));
            }
        }
    }

    /**
     * @brief Sort a time series, drop invalid timestamps, and keep the first sample for duplicates.
     *
     * The associated value vectors are reordered in lock-step with the timestamps.
     */
    template<typename... ValueVectors>
    void sort_and_deduplicate_time_series(std::vector<double>& times,
                                          ValueVectors&... values) const
    {
        if (times.empty())
            return;

        std::vector<size_t> order(times.size());
        std::iota(order.begin(), order.end(), size_t{ 0 });

        std::stable_sort(order.begin(), order.end(), [&times](size_t a, size_t b) {
            const double ta = times[a];
            const double tb = times[b];
            const bool   va = std::isfinite(ta) && ta > 0.0;
            const bool   vb = std::isfinite(tb) && tb > 0.0;

            if (va != vb)
                return va;
            if (!va && !vb)
                return a < b;

            return ta < tb;
        });

        std::vector<size_t> keep_indices;
        keep_indices.reserve(order.size());

        double last_time = 0.0;
        bool   have_last = false;

        for (const auto idx : order)
        {
            const double timestamp = times[idx];
            if (!std::isfinite(timestamp) || timestamp <= 0.0)
                continue;

            if (have_last && timestamp == last_time)
                continue;

            keep_indices.push_back(idx);
            last_time = timestamp;
            have_last = true;
        }

        auto rebuild = [&keep_indices](auto& series) {
            using value_type = typename std::decay_t<decltype(series)>::value_type;

            std::vector<value_type> reordered;
            reordered.reserve(keep_indices.size());

            for (const auto idx : keep_indices)
                reordered.push_back(series[idx]);

            series = std::move(reordered);
        };

        rebuild(times);
        (rebuild(values), ...);
    }
};

} // namespace filedatainterfaces
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
