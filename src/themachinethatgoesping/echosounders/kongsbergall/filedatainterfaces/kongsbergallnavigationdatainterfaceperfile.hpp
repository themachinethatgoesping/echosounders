// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallnavigationdatainterfaceperfile.doc.hpp"

/* library includes */
#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../../filetemplates/datainterfaces/i_navigationdatainterface.hpp"
#include "kongsbergallconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"
#include "kongsbergalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KongsbergAllNavigationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
          KongsbergAllConfigurationDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
        KongsbergAllConfigurationDataInterface<t_ifstream>>;

  public:
    KongsbergAllNavigationDataInterfacePerFile()
        : t_base("KongsbergAllNavigationDataInterfacePerFile")
    {
    }
    KongsbergAllNavigationDataInterfacePerFile(
        std::shared_ptr<KongsbergAllConfigurationDataInterface<t_ifstream>>
            configuration_data_interface)
        : t_base(std::move(configuration_data_interface),
                 "KongsbergAllNavigationDataInterfacePerFile")
    {
    }
    ~KongsbergAllNavigationDataInterfacePerFile() = default;

    navigation::NavigationInterpolatorLatLon read_navigation_data() const final
    {
        navigation::NavigationInterpolatorLatLon navi(
            this->configuration_data_interface_const().get_sensor_configuration(
                this->get_file_nr()));

        const auto& config =
            this->configuration_data_interface_const().per_file_const(this->get_file_nr());

        /* ----- scan through position datagrams ----- */
        std::vector<double> headings_pos, latitudes, longitudes, qualities;
        std::vector<double> times_pos;
        for (auto& packet : this->_datagram_infos_by_type.at_const(
                 t_KongsbergAllDatagramIdentifier::PositionDatagram))
        {
            auto datagram = packet->template read_datagram_from_file<datagrams::PositionDatagram>();

            double     timestamp     = datagram.get_timestamp();
            const auto sensor_number = datagram.get_position_system_number();

            // only use the position data if the correct position system is active
            if (sensor_number != config.get_active_position_system_number())
                continue;

            if (!times_pos.empty())
                if (!(times_pos.back() < timestamp))
                    throw std::runtime_error(fmt::format(
                        "ERROR in file [{}]: {} "
                        "\nKongsbergAllNavigationDataInterfacePerFile::read_navigation_data: "
                        "timestamps are not strictly increasing. This is not supported yet.",
                        this->get_file_nr(),
                        this->get_file_path()));

            times_pos.push_back(timestamp);
            latitudes.push_back(datagram.get_latitude_in_degrees());
            longitudes.push_back(datagram.get_longitude_in_degrees());

            headings_pos.push_back(datagram.get_heading_in_degrees());
            qualities.push_back(datagram.get_position_fix_quality_in_meters());
        }

        /* ----- scan through depth/height datagrams ----- */
        // for now ignore depth datagrams
        // std::vector<double> depths;
        // std::vector<double> times_depth;
        // for (auto& packet : this->_datagram_infos_by_type.at_const(
        //          t_KongsbergAllDatagramIdentifier::DepthOrHeightDatagram))
        // {
        //     auto datagram =
        //         packet->template read_datagram_from_file<datagrams::DepthOrHeightDatagram>();

        //     double timestamp = datagram.get_timestamp();

        //     if (!times_depth.empty())
        //         if (!(times_depth.back() < timestamp))
        //             throw std::runtime_error(fmt::format(
        //                 "ERROR in file [{}]: {} "
        //                 "\nKongsbergAllNavigationDataInterfacePerFile::read_navigation_data: "
        //                 "timestamps are not strictly increasing. This is not supported yet.",
        //                 this->get_file_nr(),
        //                 this->get_file_path()));

        //     times_depth.push_back(timestamp);
        //     depths.push_back(-datagram.get_height_in_meters());
        // }

        /* ----- scan through attitude datagrams ----- */
        std::vector<float>  headings_attitudes, pitchs, rolls;
        std::vector<double> heaves;
        std::vector<double> times_pitch_roll, times_heading_attitude, times_heave;

        this->add_attitudes<datagrams::AttitudeDatagram>(
            t_KongsbergAllDatagramIdentifier::AttitudeDatagram,
            headings_attitudes,
            pitchs,
            rolls,
            heaves,
            times_heading_attitude,
            times_pitch_roll,
            times_heave);

        this->add_attitudes<datagrams::NetworkAttitudeVelocityDatagram>(
            t_KongsbergAllDatagramIdentifier::NetworkAttitudeVelocityDatagram,
            headings_attitudes,
            pitchs,
            rolls,
            heaves,
            times_heading_attitude,
            times_pitch_roll,
            times_heave,
            times_heading_attitude.empty(),
            times_pitch_roll.empty(),
            times_heave.empty());

        // if heading, pitchs or heaves are still not found, fall back to inactive sensors from
        // existing datagrams
        // TODO: this should generate a warning within a log file
        this->add_attitudes<datagrams::AttitudeDatagram>(
            t_KongsbergAllDatagramIdentifier::AttitudeDatagram,
            headings_attitudes,
            pitchs,
            rolls,
            heaves,
            times_heading_attitude,
            times_pitch_roll,
            times_heave,
            headings_attitudes.empty(),
            pitchs.empty(),
            heaves.empty(),
            headings_attitudes.empty(),
            pitchs.empty(),
            heaves.empty());

        // if heading, pitchs or heaves are still not found, fall back to inactive sensors from
        // existing datagrams
        // TODO: this should generate a warning within a log file
        this->add_attitudes<datagrams::NetworkAttitudeVelocityDatagram>(
            t_KongsbergAllDatagramIdentifier::NetworkAttitudeVelocityDatagram,
            headings_attitudes,
            pitchs,
            rolls,
            heaves,
            times_heading_attitude,
            times_pitch_roll,
            times_heave,
            headings_attitudes.empty(),
            pitchs.empty(),
            heaves.empty(),
            headings_attitudes.empty(),
            pitchs.empty(),
            heaves.empty());

        navi.set_data_attitude(std::move(times_pitch_roll), std::move(pitchs), std::move(rolls));
        navi.set_data_heading(std::move(times_heading_attitude), std::move(headings_attitudes));
        navi.set_data_heave(std::move(times_heave), std::move(heaves));
        navi.set_data_position(std::move(times_pos), std::move(latitudes), std::move(longitudes));
        // navi.set_data_depth(std::move(times_depth), std::move(depths));

        return navi;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("KongsbergAllNavigationDataInterfacePerFile");

        return printer;
    }

  private:
    /**
     * @brief Internat function to check if a attitude timestamp is within the allowed time range (>
     * then previous attitude) If the timestamp is equal than the previous one, it is ignored
     * (return false). If the timestamp is smaller than the previous one, an exception is thrown.
     *
     * @param times vector with previous packet time_stamps of this attitude type
     * @param packet_timestamp packet timestamp to check
     * @param attitude_name name of the attitude type (heading, pitch, roll, heave)
     * @return true
     * @return false
     */
    bool packet_timestamp_in_range(const std::vector<double>& times,
                                   double                     packet_timestamp,
                                   std::string_view           attitude_name) const
    {
        if (times.empty())
            return true;

        // TODO: this silently ignores datagrams with the same timestamp as the previous one (e.g.
        // time distance < 1ms) This should generate a warning within a log file
        if (times.back() == packet_timestamp)
            return false;

        if (times.back() > packet_timestamp)
            throw std::runtime_error(
                fmt::format("ERROR in file [{}]: {} "
                            "\nKongsbergAllNavigationDataInterfacePerFile::read_navigation_data: "
                            "{} datagrams are not in chronological order.",
                            this->get_file_nr(),
                            this->get_file_path(),
                            attitude_name));

        return true;
    }

    template<typename t_attitude_datagram>
    void add_attitudes(t_KongsbergAllDatagramIdentifier datagram_identifier,
                       std::vector<float>&              headings_attitudes,
                       std::vector<float>&              pitchs,
                       std::vector<float>&              rolls,
                       std::vector<double>&             heaves,
                       std::vector<double>&             times_heading_attitude,
                       std::vector<double>&             times_pitch_roll,
                       std::vector<double>&             times_heave,
                       bool                             look_for_heading_sensor        = true,
                       bool                             look_for_roll_pitch_sensor     = true,
                       bool                             look_for_heave_sensor          = true,
                       bool                             use_inactive_heading_sensor    = false,
                       bool                             use_inactive_roll_pitch_sensor = false,
                       bool                             use_inactive_heave_sensor = false) const
    {
        for (auto& packet : this->_datagram_infos_by_type.at_const(datagram_identifier))
        {
            auto datagram = packet->template read_datagram_from_file<t_attitude_datagram>();

            bool use_heading_sensor =
                (datagram.get_heading_sensor_is_active() || use_inactive_heading_sensor) &&
                look_for_heading_sensor;
            bool use_roll_sensor =
                (datagram.get_roll_sensor_is_active() || use_inactive_roll_pitch_sensor) &&
                look_for_roll_pitch_sensor;
            bool use_pitch_sensor =
                (datagram.get_pitch_sensor_is_active() || use_inactive_roll_pitch_sensor) &&
                look_for_roll_pitch_sensor;
            bool use_heave_sensor =
                (datagram.get_heave_sensor_is_active() || use_inactive_heave_sensor) &&
                look_for_heave_sensor;

            // const auto sensor_number      = datagram.get_attitude_sensor_number();

            if (use_roll_sensor != use_pitch_sensor)
                throw std::runtime_error(fmt::format(
                    "ERROR in file [{}]: {} "
                    "\nKongsbergAllNavigationDataInterfacePerFile::read_navigation_data: roll and "
                    "pitch sensor are not active at the same time. This is not supported yet.",
                    this->get_file_nr(),
                    this->get_file_path()));

            double base_time = datagram.get_timestamp();

            for (const auto& attitude : datagram.get_attitudes())
            {
                double packet_timestamp = base_time + attitude.get_time_in_seconds();

                if (use_pitch_sensor)
                {
                    if (packet_timestamp_in_range(times_pitch_roll, packet_timestamp, "pitch"))
                    {
                        times_pitch_roll.push_back(packet_timestamp);
                        pitchs.push_back(attitude.get_pitch_in_degrees());
                        rolls.push_back(attitude.get_roll_in_degrees());
                    }
                }

                if (use_heading_sensor)
                {
                    if (packet_timestamp_in_range(
                            times_heading_attitude, packet_timestamp, "heading"))
                    {
                        times_heading_attitude.push_back(packet_timestamp);
                        headings_attitudes.push_back(attitude.get_heading_in_degrees());
                    }
                }

                if (use_heave_sensor)
                {
                    if (packet_timestamp_in_range(times_heave, packet_timestamp, "heave"))
                    {
                        times_heave.push_back(packet_timestamp);
                        // TODO heave: heave should be positive upwards, but it seems it is positive
                        // downwards for the belgica data
                        heaves.push_back(-attitude.get_heave_in_meters());
                    }
                }
            }
        }
    }
};

}
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
