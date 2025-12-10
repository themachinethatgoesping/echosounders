// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallnavigationdatainterfaceperfile.doc.hpp"

/* library includes */
#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datainterfaces/i_navigationdatainterface.hpp"
#include "kmallconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"
#include "kmalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KMALLNavigationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
          KMALLConfigurationDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
        KMALLConfigurationDataInterface<t_ifstream>>;

    bool _prefer_spo_over_cpo = true; ///< Prefer S_POSITION over C_POSITION
    bool _prefer_skm_over_che = true; ///< Prefer S_KM_BINARY over C_HEAVE for heave

  public:
    KMALLNavigationDataInterfacePerFile()
        : t_base("KMALLNavigationDataInterfacePerFile")
    {
    }
    KMALLNavigationDataInterfacePerFile(
        std::shared_ptr<KMALLConfigurationDataInterface<t_ifstream>> configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "KMALLNavigationDataInterfacePerFile")
    {
    }
    ~KMALLNavigationDataInterfacePerFile() = default;

    // ----- getters/setters for datagram preference -----
    /**
     * @brief Get whether S_POSITION is preferred over C_POSITION
     * @return true if S_POSITION is preferred (default)
     */
    bool get_prefer_spo_over_cpo() const { return _prefer_spo_over_cpo; }

    /**
     * @brief Get whether S_KM_BINARY is preferred over C_HEAVE for heave data
     * @return true if S_KM_BINARY is preferred (default)
     */
    bool get_prefer_skm_over_che() const { return _prefer_skm_over_che; }

    /**
     * @brief Set whether S_POSITION is preferred over C_POSITION
     * @param prefer true to prefer S_POSITION (default), false to prefer C_POSITION
     */
    void set_prefer_spo_over_cpo(bool prefer) { _prefer_spo_over_cpo = prefer; }

    /**
     * @brief Set whether S_KM_BINARY is preferred over C_HEAVE for heave data
     * @param prefer true to prefer S_KM_BINARY (default), false to prefer C_HEAVE
     */
    void set_prefer_skm_over_che(bool prefer) { _prefer_skm_over_che = prefer; }

    navigation::NavigationInterpolatorLatLon read_navigation_data() const final
    {
        navigation::NavigationInterpolatorLatLon navi(
            this->configuration_data_interface_const().get_sensor_configuration(
                this->get_file_nr()));

        const auto& config =
            this->configuration_data_interface_const().per_file_const(this->get_file_nr());

        /* ----- scan through position datagrams ----- */
        std::vector<double> latitudes, longitudes;
        std::vector<double> times_pos;

        // Determine which position datagram to use based on preference and availability
        bool use_spo = _prefer_spo_over_cpo;
        bool has_spo =
            this->_datagram_infos_by_type.contains(t_KMALLDatagramIdentifier::S_POSITION) &&
            !this->_datagram_infos_by_type.at_const(t_KMALLDatagramIdentifier::S_POSITION).empty();
        bool has_cpo =
            this->_datagram_infos_by_type.contains(t_KMALLDatagramIdentifier::C_POSITION) &&
            !this->_datagram_infos_by_type.at_const(t_KMALLDatagramIdentifier::C_POSITION).empty();

        if (use_spo && !has_spo && has_cpo)
            use_spo = false;
        if (!use_spo && !has_cpo && has_spo)
            use_spo = true;
        
        // std::cerr << fmt::format(
        //                  "KMALLNavigationDataInterfacePerFile::read_navigation_data [file {}]: "
        //                  "has_spo={} has_cpo={} use_spo={}\n",
        //                  this->get_file_nr(),
        //                  has_spo,
        //                  has_cpo,
        //                  use_spo)
        //           << std::flush;

        if (use_spo && has_spo)
        {
            read_position_from_spo(times_pos, latitudes, longitudes, config);
        }
        else if (has_cpo)
        {
            read_position_from_cpo(times_pos, latitudes, longitudes, config);
        }

        /* ----- scan through attitude datagrams (S_KM_BINARY) ----- */
        std::vector<float>  headings, pitchs, rolls;
        std::vector<double> heaves;
        std::vector<double> times_pitch_roll, times_heading, times_heave;

        // S_KM_BINARY provides all attitude data
        if (this->_datagram_infos_by_type.contains(t_KMALLDatagramIdentifier::S_KM_BINARY))
        {
            read_attitude_from_skm(headings,
                                   pitchs,
                                   rolls,
                                   heaves,
                                   times_heading,
                                   times_pitch_roll,
                                   times_heave);
        }

        // Optionally use C_HEAVE for heave if S_KM_BINARY heave not available or not preferred
        if (!_prefer_skm_over_che || times_heave.empty())
        {
            if (this->_datagram_infos_by_type.contains(t_KMALLDatagramIdentifier::C_HEAVE))
            {
                // Only use C_HEAVE if we don't have heave data yet
                if (times_heave.empty())
                {
                    read_heave_from_che(heaves, times_heave);
                }
            }
        }

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

        printer.register_section("KMALLNavigationDataInterfacePerFile");
        printer.register_value("prefer_spo_over_cpo", _prefer_spo_over_cpo);
        printer.register_value("prefer_skm_over_che", _prefer_skm_over_che);

        return printer;
    }

  private:
    /**
     * @brief Internal function to check if a timestamp is within the allowed time range
     * If the timestamp is equal to the previous one, it is ignored (return false).
     * If the timestamp is smaller than the previous one, an exception is thrown.
     *
     * @param times vector with previous timestamps
     * @param packet_timestamp timestamp to check
     * @param data_name name of the data type for error messages
     * @return true if timestamp is valid and should be added
     * @return false if timestamp should be ignored (duplicate)
     */
    bool packet_timestamp_in_range(const std::vector<double>& times,
                                   double                     packet_timestamp,
                                   std::string_view           data_name) const
    {
        if (times.empty())
            return true;

        // Silently ignore datagrams with the same timestamp as the previous one
        if (times.back() == packet_timestamp)
            return false;

        if (times.back() > packet_timestamp)
            throw std::runtime_error(
                fmt::format("ERROR in file [{}]: {} "
                            "\nKMALLNavigationDataInterfacePerFile::read_navigation_data: "
                            "{} datagrams are not in chronological order.",
                            this->get_file_nr(),
                            this->get_file_path(),
                            data_name));

        return true;
    }

    /**
     * @brief Read position data from S_POSITION datagrams
     */
    void read_position_from_spo(
        std::vector<double>&                                                     times_pos,
        std::vector<double>&                                                     latitudes,
        std::vector<double>&                                                     longitudes,
        const KMALLConfigurationDataInterfacePerFile<t_ifstream>& config) const
    {
        uint8_t active_pos_system = config.get_active_position_system_number();

        for (const auto& packet :
             this->_datagram_infos_by_type.at_const(t_KMALLDatagramIdentifier::S_POSITION))
        {
            auto datagram = packet->template read_datagram_from_file<datagrams::SPosition>();

            // Only use data from the active position system
            if (datagram.get_sensor_system() != active_pos_system)
                continue;

            double timestamp = datagram.get_timestamp();

            if (!packet_timestamp_in_range(times_pos, timestamp, "S_POSITION"))
                continue;

            times_pos.push_back(timestamp);
            latitudes.push_back(datagram.get_corrected_lat_deg());
            longitudes.push_back(datagram.get_corrected_lon_deg());
        }
    }

    /**
     * @brief Read position data from C_POSITION datagrams
     */
    void read_position_from_cpo(
        std::vector<double>&                                                     times_pos,
        std::vector<double>&                                                     latitudes,
        std::vector<double>&                                                     longitudes,
        const KMALLConfigurationDataInterfacePerFile<t_ifstream>& config) const
    {
        uint8_t active_pos_system = config.get_active_position_system_number();

        for (const auto& packet :
             this->_datagram_infos_by_type.at_const(t_KMALLDatagramIdentifier::C_POSITION))
        {
            auto datagram = packet->template read_datagram_from_file<datagrams::CPosition>();

            // Only use data from the active position system
            if (datagram.get_sensor_system() != active_pos_system)
                continue;

            double timestamp = datagram.get_timestamp();

            if (!packet_timestamp_in_range(times_pos, timestamp, "C_POSITION"))
                continue;

            times_pos.push_back(timestamp);
            latitudes.push_back(datagram.get_corrected_lat_deg());
            longitudes.push_back(datagram.get_corrected_lon_deg());
        }
    }

    /**
     * @brief Read attitude data from S_KM_BINARY datagrams
     *
     * S_KM_BINARY contains multiple samples per datagram with:
     * - Position (lat, lon, height)
     * - Attitude (roll, pitch, heading, heave)
     * - Velocities and accelerations
     * - Validity flags for each data type
     */
    void read_attitude_from_skm(std::vector<float>&  headings,
                                std::vector<float>&  pitchs,
                                std::vector<float>&  rolls,
                                std::vector<double>& heaves,
                                std::vector<double>& times_heading,
                                std::vector<double>& times_pitch_roll,
                                std::vector<double>& times_heave) const
    {
        for (const auto& packet :
             this->_datagram_infos_by_type.at_const(t_KMALLDatagramIdentifier::S_KM_BINARY))
        {
            auto datagram = packet->template read_datagram_from_file<datagrams::SKMBinary>();

            // Check which data types are active in this datagram
            bool heading_active    = datagram.get_heading_active();
            bool roll_pitch_active = datagram.get_roll_and_pitch_active();
            bool heave_active      = datagram.get_heave_active();

            // Iterate through all samples in the datagram
            for (const auto& sample : datagram.get_sensor_data())
            {
                const auto& km_binary = sample.km_binary;
                double      timestamp = km_binary.get_sensor_timestamp();

                // Roll and pitch
                if (roll_pitch_active && km_binary.get_roll_and_pitch_valid())
                {
                    if (packet_timestamp_in_range(times_pitch_roll, timestamp, "pitch/roll"))
                    {
                        times_pitch_roll.push_back(timestamp);
                        pitchs.push_back(km_binary.pitch_deg);
                        rolls.push_back(km_binary.roll_deg);
                    }
                }

                // Heading
                if (heading_active && km_binary.get_heading_valid())
                {
                    if (packet_timestamp_in_range(times_heading, timestamp, "heading"))
                    {
                        times_heading.push_back(timestamp);
                        headings.push_back(km_binary.heading_deg);
                    }
                }

                // Heave
                if (heave_active && km_binary.get_heave_valid())
                {
                    if (packet_timestamp_in_range(times_heave, timestamp, "heave"))
                    {
                        times_heave.push_back(timestamp);
                        // Heave sign convention: positive upwards
                        heaves.push_back(km_binary.heave_m);
                    }
                }
            }
        }
    }

    /**
     * @brief Read heave data from C_HEAVE datagrams
     */
    void read_heave_from_che(std::vector<double>& heaves, std::vector<double>& times_heave) const
    {
        for (const auto& packet :
             this->_datagram_infos_by_type.at_const(t_KMALLDatagramIdentifier::C_HEAVE))
        {
            auto   datagram  = packet->template read_datagram_from_file<datagrams::CHeave>();
            double timestamp = datagram.get_timestamp();

            if (!packet_timestamp_in_range(times_heave, timestamp, "C_HEAVE"))
                continue;

            times_heave.push_back(timestamp);
            heaves.push_back(datagram.get_heave_m());
        }
    }
};

}
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
