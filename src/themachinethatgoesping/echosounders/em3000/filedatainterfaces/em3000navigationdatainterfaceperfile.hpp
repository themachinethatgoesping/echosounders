// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000navigationdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

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
