// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawnavigationdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "simradrawconfigurationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "simradrawdatagraminterface.hpp"

#include "../../filetemplates/datainterfaces/i_navigationdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradRawNavigationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
          SimradRawConfigurationDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
        SimradRawConfigurationDataInterface<t_ifstream>>;

    int _min_gga_quality = 1;
    int _max_gga_quality = 5;

  public:
    SimradRawNavigationDataInterfacePerFile()
        : t_base("SimradRawNavigationDataInterfacePerFile")
    {
    }
    SimradRawNavigationDataInterfacePerFile(
        std::shared_ptr<SimradRawConfigurationDataInterface<t_ifstream>> configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "SimradRawNavigationDataInterfacePerFile")
    {
    }
    ~SimradRawNavigationDataInterfacePerFile() = default;

    void set_min_gga_quality(int min_gga_quality) { _min_gga_quality = min_gga_quality; }
    void set_max_gga_quality(int max_gga_quality) { _max_gga_quality = max_gga_quality; }
    int  get_min_gga_quality() const { return _min_gga_quality; }
    int  get_max_gga_quality() const { return _max_gga_quality; }

    navigation::NavigationInterpolatorLatLon read_navigation_data() const final
    {
        navigation::NavigationInterpolatorLatLon navi(
            this->configuration_data_interface_const().get_sensor_configuration(
                this->get_file_nr()));

        /* scan through NMEA data */
        std::vector<float> depths;
        std::vector<double> lats, lons, gps_times;

        for (auto& packet :
             this->_datagram_infos_by_type.at_const(t_SimradRawDatagramIdentifier::NME0))
        {
            auto nme0 = packet->template read_datagram_from_file<datagrams::NME0>();

            if (nme0.get_sentence_type() == "GGA")
            {
                auto gga     = std::get<navigation::nmea_0183::NMEA_GGA>(nme0.decode());
                auto quality = gga.get_quality();

                if (quality < _min_gga_quality || quality > _max_gga_quality)
                    continue;

                // TODO: correct with gps time
                auto packet_timestamp = nme0.get_timestamp();
                if (!gps_times.empty())
                    if (!(gps_times.back() < packet_timestamp))
                        continue;

                auto lat = gga.get_latitude();
                auto lon = gga.get_longitude();
                auto alt = gga.get_altitude();

                if (!std::isfinite(lat) || !std::isfinite(lon) || !std::isfinite(alt))
                    continue;

                lats.push_back(lat);
                lons.push_back(lon);
                gps_times.push_back(packet_timestamp);
                // depths.push_back(-alt); ?
                depths.push_back(alt);
            }
        }

        std::vector<float> headings, pitchs, rolls;
        std::vector<double> heaves, mru0_times;

        for (auto& packet :
             this->_datagram_infos_by_type.at_const(t_SimradRawDatagramIdentifier::MRU0))
        {
            auto mru0 = packet->template read_datagram_from_file<datagrams::MRU0>();

            auto packet_timestamp = mru0.get_timestamp();
            if (!mru0_times.empty())
                if (!(mru0_times.back() < packet_timestamp))
                    continue;

            auto heading = mru0.get_heading();
            auto pitch   = mru0.get_pitch();
            auto roll    = mru0.get_roll();
            auto heave   = mru0.get_heave();

            if (!std::isfinite(heading) || !std::isfinite(pitch) || !std::isfinite(roll) ||
                !std::isfinite(heave))
                continue;

            headings.push_back(heading);
            pitchs.push_back(pitch);
            rolls.push_back(roll);
            heaves.push_back(heave);
            mru0_times.push_back(packet_timestamp);
        }

        navi.set_data_attitude(mru0_times, pitchs, rolls);
        navi.set_data_heading(mru0_times, headings);
        navi.set_data_heave(mru0_times, heaves);
        navi.set_data_position(gps_times, lats, lons);
        //navi.set_data_depth(gps_times, depths);

        return navi;
    }

    // --------------------- simradraw specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("SimradRawNavigationDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
