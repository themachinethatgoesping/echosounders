// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000navigationdatainterfaceperfile.doc.hpp"

/* library includes */
#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_navigationdatainterface.hpp"
#include "em3000configurationdatainterface.hpp"

#include "../em3000_datagrams.hpp"
#include "../em3000_types.hpp"
#include "em3000datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatainterfaces {

template<typename t_ifstream>
class EM3000NavigationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
          EM3000ConfigurationDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
        EM3000ConfigurationDataInterface<t_ifstream>>;

  public:
    EM3000NavigationDataInterfacePerFile()
        : t_base("EM3000NavigationDataInterfacePerFile")
    {
    }
    EM3000NavigationDataInterfacePerFile(
        std::shared_ptr<EM3000ConfigurationDataInterface<t_ifstream>> configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "EM3000NavigationDataInterfacePerFile")
    {
    }
    ~EM3000NavigationDataInterfacePerFile() = default;

    

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
        for (auto& packet :
             this->_datagram_infos_by_type.at_const(t_EM3000DatagramIdentifier::PositionDatagram))
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
                        "\nEM3000NavigationDataInterfacePerFile::read_navigation_data: "
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
        //          t_EM3000DatagramIdentifier::DepthOrHeightDatagram))
        // {
        //     auto datagram =
        //         packet->template read_datagram_from_file<datagrams::DepthOrHeightDatagram>();

        //     double timestamp = datagram.get_timestamp();

        //     if (!times_depth.empty())
        //         if (!(times_depth.back() < timestamp))
        //             throw std::runtime_error(fmt::format(
        //                 "ERROR in file [{}]: {} "
        //                 "\nEM3000NavigationDataInterfacePerFile::read_navigation_data: "
        //                 "timestamps are not strictly increasing. This is not supported yet.",
        //                 this->get_file_nr(),
        //                 this->get_file_path()));

        //     times_depth.push_back(timestamp);
        //     depths.push_back(-datagram.get_height_in_meters());
        // }

        /* ----- scan through attitude datagrams ----- */
        std::vector<double> headings_attitudes, pitchs, rolls, heaves;
        std::vector<double> times_pitch_roll, times_heading_attitude, times_heave;

        for (auto& packet :
             this->_datagram_infos_by_type.at_const(t_EM3000DatagramIdentifier::AttitudeDatagram))
        {
            auto datagram = packet->template read_datagram_from_file<datagrams::AttitudeDatagram>();

            double base_time          = datagram.get_timestamp();
            bool   use_heave_sensor   = datagram.get_heave_sensor_is_active();
            bool   use_heading_sensor = datagram.get_heading_sensor_is_active();
            bool   use_roll_sensor    = datagram.get_roll_sensor_is_active();
            bool   use_pitch_sensor   = datagram.get_pitch_sensor_is_active();
            // const auto sensor_number      = datagram.get_attitude_sensor_number();

            if (use_roll_sensor != use_pitch_sensor)
                throw std::runtime_error(fmt::format(
                    "ERROR in file [{}]: {} "
                    "\nEM3000NavigationDataInterfacePerFile::read_navigation_data: roll and "
                    "pitch sensor are not active at the same time. This is not supported yet.",
                    this->get_file_nr(),
                    this->get_file_path()));

            // only use the sensor data if the correct sensor is active
            // apparently the sensor number is not the same as the attitude sensor number
            // if (sensor_number !=
            //     t_EM3000ActiveSensor_to_attitude_sensor_number(config.get_active_heave_sensor()))
            //     use_heave_sensor = false;

            // if (sensor_number !=
            //     t_EM3000ActiveSensor_to_attitude_sensor_number(config.get_active_heading_sensor()))
            //     use_heading_sensor = false;

            // if (sensor_number != t_EM3000ActiveSensor_to_attitude_sensor_number(
            //                          config.get_active_pitch_roll_sensor()))
            // {
            //     use_roll_sensor  = false;
            //     use_pitch_sensor = false;
            // }

            for (const auto& attitude : datagram.get_attitudes())
            {
                double packet_timestamp = base_time + attitude.get_time_in_seconds();

                if (use_pitch_sensor)
                {
                    if (!times_pitch_roll.empty())
                        if (!(times_pitch_roll.back() < packet_timestamp))
                            throw std::runtime_error(fmt::format(
                                "ERROR in file [{}]: {} "
                                "\nEM3000NavigationDataInterfacePerFile::read_navigation_data: "
                                "pitch and roll datagrams are not in chronological order.",
                                this->get_file_nr(),
                                this->get_file_path()));

                    times_pitch_roll.push_back(packet_timestamp);
                    pitchs.push_back(attitude.get_pitch_in_degrees());
                    rolls.push_back(attitude.get_roll_in_degrees());
                }

                if (use_heading_sensor)
                {
                    if (!times_heading_attitude.empty())
                        if (!(times_heading_attitude.back() < packet_timestamp))
                            throw std::runtime_error(fmt::format(
                                "ERROR in file [{}]: {} "
                                "\nEM3000NavigationDataInterfacePerFile::read_navigation_data: "
                                "heading datagrams are not in chronological order.",
                                this->get_file_nr(),
                                this->get_file_path()));

                    times_heading_attitude.push_back(packet_timestamp);
                    headings_attitudes.push_back(attitude.get_heading_in_degrees());
                }

                if (use_heave_sensor)
                {
                    if (!times_heave.empty())
                        if (!(times_heave.back() < packet_timestamp))
                            throw std::runtime_error(fmt::format(
                                "ERROR in file [{}]: {} "
                                "\nEM3000NavigationDataInterfacePerFile::read_navigation_data: "
                                "heave datagrams are not in chronological order.",
                                this->get_file_nr(),
                                this->get_file_path()));

                    times_heave.push_back(packet_timestamp);
                    heaves.push_back(attitude.get_heave_in_meters());
                }
            }
        }

        navi.set_data_attitude(std::move(times_pitch_roll), std::move(pitchs), std::move(rolls));
        navi.set_data_heading(std::move(times_heading_attitude), std::move(headings_attitudes));
        navi.set_data_heave(std::move(times_heave), std::move(heaves));
        navi.set_data_position(std::move(times_pos), std::move(latitudes), std::move(longitudes));
        //navi.set_data_depth(std::move(times_depth), std::move(depths));

        return navi;
    }

    //     /* scan through NMEA data */
    //     std::vector<double> lats, lons, gps_times, depths;

    //     for (auto& packet :
    //          this->_datagram_infos_by_type.at_const(t_EM3000DatagramIdentifier::NME0))
    //     {
    //         auto nme0 = packet->template read_datagram_from_file<datagrams::NME0>();

    //         if (nme0.get_sentence_type() == "GGA")
    //         {
    //             auto gga     = std::get<navigation::nmea_0183::NMEA_GGA>(nme0.decode());
    //             auto quality = gga.get_quality();

    //             if (quality < _min_gga_quality || quality > _max_gga_quality)
    //                 continue;

    //             // TODO: correct with gps time
    //             auto packet_timestamp = nme0.get_timestamp();
    //             if (!gps_times.empty())
    //                 if (!(gps_times.back() < packet_timestamp))
    //                     continue;

    //             auto lat = gga.get_latitude();
    //             auto lon = gga.get_longitude();
    //             auto alt = gga.get_altitude();

    //             if (!std::isfinite(lat) || !std::isfinite(lon) || !std::isfinite(alt))
    //                 continue;

    //             lats.push_back(lat);
    //             lons.push_back(lon);
    //             gps_times.push_back(packet_timestamp);
    //             // depths.push_back(-alt); ?
    //             depths.push_back(alt);
    //         }
    //     }

    //     std::vector<double> headings, pitchs, rolls, heaves, mru0_times;

    //     for (auto& packet :
    //          this->_datagram_infos_by_type.at_const(t_EM3000DatagramIdentifier::MRU0))
    //     {
    //         auto mru0 = packet->template read_datagram_from_file<datagrams::MRU0>();

    //         auto packet_timestamp = mru0.get_timestamp();
    //         if (!mru0_times.empty())
    //             if (!(mru0_times.back() < packet_timestamp))
    //                 continue;

    //         auto heading = mru0.get_heading();
    //         auto pitch   = mru0.get_pitch();
    //         auto roll    = mru0.get_roll();
    //         auto heave   = mru0.get_heave();

    //         if (!std::isfinite(heading) || !std::isfinite(pitch) || !std::isfinite(roll) ||
    //             !std::isfinite(heave))
    //             continue;

    //         headings.push_back(heading);
    //         pitchs.push_back(pitch);
    //         rolls.push_back(roll);
    //         heaves.push_back(heave);
    //         mru0_times.push_back(packet_timestamp);
    //     }

    //     navi.set_data_attitude(mru0_times, pitchs, rolls);
    //     navi.set_data_heading(mru0_times, headings);
    //     navi.set_data_heave(mru0_times, heaves);
    //     navi.set_data_position(gps_times, lats, lons);
    //     navi.set_data_depth(gps_times, depths);

    //     return navi;
    // }

    // ----- em3000 specific functions -----
    /* interface setup */
    // void set_min_gga_quality(int min_gga_quality) { _min_gga_quality = min_gga_quality; }
    // void set_max_gga_quality(int max_gga_quality) { _max_gga_quality = max_gga_quality; }
    // int  get_min_gga_quality() const { return _min_gga_quality; }
    // int  get_max_gga_quality() const { return _max_gga_quality; }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("EM3000NavigationDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
