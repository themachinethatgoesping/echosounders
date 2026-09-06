// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kfilehandler.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "datagrams.hpp"
#include "types.hpp"

#include "../filetemplates/datacontainers/pingcontainer.hpp"
#include "../filetemplates/i_inputfilehandler.hpp"

#include "filedatacontainers/s7kpingcontainer.hpp"
#include "filedatainterfaces/s7kconfigurationdatainterface.hpp"
#include "filedatainterfaces/s7kdatagramdatainterface.hpp"
#include "filedatainterfaces/s7kdatagraminterface.hpp"
#include "filedatainterfaces/s7kenvironmentdatainterface.hpp"
#include "filedatainterfaces/s7knavigationdatainterface.hpp"
#include "filedatainterfaces/s7kotherfiledatainterface.hpp"
#include "filedatainterfaces/s7kpingdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {

/**
 * @brief File handler for Teledyne RESON .s7k (7k) data files.
 *
 * Indexes all datagrams (Data Record Frames) in the given file(s), sorts them into the specialized
 * file-data interfaces (configuration, navigation, environment, ping, other) and provides access to
 * the raw datagrams via the datagram_interface().
 *
 * @note The specialized interfaces are structurally present and the datagrams are already sorted
 * into them, but their read_* processing functions are not implemented yet. Initializing them
 * (and therefore get_pings()) is deferred to a later step.
 */
template<typename t_ifstream>
class S7KFileHandler
    : public filetemplates::I_InputFileHandler<datagrams::S7KDatagram,
                                               filedatainterfaces::S7KDatagramInterface<t_ifstream>>
{
  public:
    using t_base = filetemplates::I_InputFileHandler<
        datagrams::S7KDatagram,
        filedatainterfaces::S7KDatagramInterface<t_ifstream>>;

    // ----- types -----
    using t_DatagramDataInterface =
        typename filedatainterfaces::S7KDatagramDataInterface<t_ifstream>;
    using t_OtherFileDataInterface =
        typename filedatainterfaces::S7KOtherFileDataInterface<t_ifstream>;
    using t_ConfigurationDataInterface =
        typename filedatainterfaces::S7KConfigurationDataInterface<t_ifstream>;
    using t_NavigationDataInterface =
        typename filedatainterfaces::S7KNavigationDataInterface<t_ifstream>;
    using t_EnvironmentDataInterface =
        typename filedatainterfaces::S7KEnvironmentDataInterface<t_ifstream>;
    using t_PingDataInterface = typename filedatainterfaces::S7KPingDataInterface<t_ifstream>;

    using typename t_base::FileInfos;
    using typename t_base::FilePackageIndex;

  private:
    // ----- file data interfaces -----
    std::shared_ptr<t_DatagramDataInterface> _datagramdata_interface =
        std::make_shared<t_DatagramDataInterface>();
    std::shared_ptr<t_OtherFileDataInterface> _otherfiledata_interface =
        std::make_shared<t_OtherFileDataInterface>();

    std::shared_ptr<t_ConfigurationDataInterface> _configuration_interface =
        std::make_shared<t_ConfigurationDataInterface>();
    std::shared_ptr<t_NavigationDataInterface> _navigation_interface =
        std::make_shared<t_NavigationDataInterface>(_configuration_interface);
    std::shared_ptr<t_EnvironmentDataInterface> _environment_interface =
        std::make_shared<t_EnvironmentDataInterface>(_navigation_interface);
    std::shared_ptr<t_PingDataInterface> _ping_interface =
        std::make_shared<t_PingDataInterface>(_environment_interface);

  public:
    // inherit constructors
    // This does not work, because I_InputFileHandler calls append before the callback functions are
    // overwritten. Thus inheriting constructors would lead to calling the callback functions of the
    // base class.

    S7KFileHandler(const std::string&                                  file_path,
                   const std::unordered_map<std::string, std::string>& index_paths =
                       std::unordered_map<std::string, std::string>(),
                   bool                 init          = true,
                   bool                 show_progress = true,
                   [[maybe_unused]] int mp_cores      = 1)
        : t_base(index_paths)
    {
        this->append_file(file_path, show_progress);
        setup_interfaces();
        if (init)
            init_interfaces(false, show_progress);
    }
    S7KFileHandler(const std::string&                                  file_path,
                   const std::unordered_map<std::string, std::string>& index_paths,
                   bool                                                init,
                   tools::progressbars::I_ProgressBar&                 progress_bar,
                   [[maybe_unused]] int                                mp_cores = 1)
        : t_base(index_paths)
    {
        this->append_file(file_path, progress_bar);
        setup_interfaces();
        if (init)
            init_interfaces(false, progress_bar);
    }

    S7KFileHandler(const std::vector<std::string>&                     file_paths,
                   const std::unordered_map<std::string, std::string>& index_paths =
                       std::unordered_map<std::string, std::string>(),
                   bool                 init          = true,
                   bool                 show_progress = true,
                   [[maybe_unused]] int mp_cores      = 1)
        : t_base(index_paths)
    {
        this->append_files(file_paths, show_progress);
        setup_interfaces();
        if (init)
            init_interfaces(false, show_progress);
    }
    S7KFileHandler(const std::vector<std::string>&                     file_paths,
                   const std::unordered_map<std::string, std::string>& index_paths,
                   bool                                                init,
                   tools::progressbars::I_ProgressBar&                 progress_bar,
                   [[maybe_unused]] int                                mp_cores = 1)
        : t_base(index_paths)
    {
        this->append_files(file_paths, progress_bar);
        setup_interfaces();
        if (init)
            init_interfaces(false, progress_bar);
    }
    ~S7KFileHandler() = default;

    void setup_interfaces()
    {
        // Nothing to link for s7k (no split file pairs like the .kmall/.kmwcd pair).
    }

    using t_base::init_interfaces;
    void init_interfaces([[maybe_unused]] bool                                force,
                         [[maybe_unused]] tools::progressbars::I_ProgressBar& progress_bar,
                         [[maybe_unused]] int mp_cores = 1) final
    {
        // The generic datagram-data, configuration and navigation interfaces are initialized. The
        // configuration interface currently falls back to an empty sensor configuration (its read_*
        // function is not implemented yet), but the navigation interface treats that as a valid
        // (zero-offset) configuration and builds/caches the navigation interpolators from it. The
        // environment/other/ping interfaces are structurally present and the datagrams are already
        // sorted into them (see callback_scan_packet), but their read_* processing functions are not
        // implemented yet, so initializing them is deferred to the next step.
        auto number_of_primary_files = _datagramdata_interface->per_primary_file().size();
        progress_bar.init(
            0., double(number_of_primary_files + 2), std::string("Initializing file interfaces"));

        progress_bar.set_prefix("Initializing datagramdata interface");
        _datagramdata_interface->init_from_file(this->get_index_paths(), force, progress_bar);
        progress_bar.tick();

        progress_bar.set_prefix("Initializing configuration");
        _configuration_interface->init_from_file(this->get_index_paths(), force, progress_bar);
        progress_bar.tick();

        progress_bar.set_prefix("Initializing navigation");
        _navigation_interface->init_from_file(this->get_index_paths(), force, progress_bar, true);

        progress_bar.close(std::string("Done"));

        // TODO(next step): enable these as each interface is implemented:
        // _environment_interface->init_from_file(this->get_index_paths(), force, progress_bar);
        // _otherfiledata_interface->init_from_file(this->get_index_paths(), force, progress_bar);
        // _ping_interface->init_from_file(this->get_index_paths(), force, progress_bar, true,
        //                                 mp_cores);
    }

    auto& datagramdata_interface() { return *_datagramdata_interface; }
    auto& configuration_interface() { return *_configuration_interface; }
    auto& navigation_interface() { return *_navigation_interface; }
    auto& environment_interface() { return *_environment_interface; }
    auto& otherfiledata_interface() { return *_otherfiledata_interface; }
    auto& ping_interface() { return *_ping_interface; }

    filedatacontainers::S7KPingContainer<t_ifstream> get_pings(bool sorted_by_time = true) const
    {
        if (sorted_by_time)
        {
            return _ping_interface->get_pings().get_sorted_by_time();
        }
        return _ping_interface->get_pings();
    }

    std::vector<std::string> get_channel_ids() const { return _ping_interface->get_channel_ids(); }

  protected:
    void callback_scan_new_file_begin([[maybe_unused]] const std::string& file_path,
                                      [[maybe_unused]] size_t             file_paths_cnt) final
    {
        // TODO: this is a bit ugly since it updates all files and not just the new ones
        // add file info
        _datagramdata_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _configuration_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _navigation_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _environment_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _otherfiledata_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _ping_interface->add_file_information(this->_input_file_manager->get_file_paths());
    }
    void callback_scan_new_file_end([[maybe_unused]] const std::string& file_path,
                                    [[maybe_unused]] size_t             file_paths_cnt) final
    {
    }

    void callback_scan_packet(
        filetemplates::datatypes::DatagramInfo_ptr<t_S7KDatagramIdentifier, t_ifstream>
            datagram_info) final
    {
        // Every datagram is tracked by the generic datagram-data interface.
        _datagramdata_interface->add_datagram_info(datagram_info);

        switch (datagram_info->get_datagram_identifier())
        {
            // ---------------- Configuration datagrams ----------------
            case t_S7KDatagramIdentifier::ReferencePoint: // 1000
                [[fallthrough]];
            case t_S7KDatagramIdentifier::SensorOffsetPosition: // 1001
                [[fallthrough]];
            case t_S7KDatagramIdentifier::SensorOffsetPositionCalibrated: // 1002
                [[fallthrough]];
            case t_S7KDatagramIdentifier::SonarInstallationIdentifiers: // 1020
                [[fallthrough]];
            case t_S7KDatagramIdentifier::Configuration: // 7001
                [[fallthrough]];
            case t_S7KDatagramIdentifier::FirmwareAndHardwareConfiguration: // 7003
                [[fallthrough]];
            case t_S7KDatagramIdentifier::FileHeader: // 7003
                [[fallthrough]];
            case t_S7KDatagramIdentifier::SonarInstallationParameters: // 7030
                _configuration_interface->add_datagram_info(datagram_info);
                break;

            // ---------------- Navigation datagrams ----------------
            case t_S7KDatagramIdentifier::Position: // 1003
                [[fallthrough]];
            case t_S7KDatagramIdentifier::CustomAttitudeInformation: // 1004
                [[fallthrough]];
            case t_S7KDatagramIdentifier::Tide: // 1005
                [[fallthrough]];
            case t_S7KDatagramIdentifier::Altitude: // 1006
                [[fallthrough]];
            case t_S7KDatagramIdentifier::MotionOverGround: // 1007
                [[fallthrough]];
            case t_S7KDatagramIdentifier::Depth: // 1008
                [[fallthrough]];
            case t_S7KDatagramIdentifier::RollPitchHeave: // 1012
                [[fallthrough]];
            case t_S7KDatagramIdentifier::Heading: // 1013
                [[fallthrough]];
            case t_S7KDatagramIdentifier::Navigation: // 1015
                [[fallthrough]];
            case t_S7KDatagramIdentifier::Attitude: // 1016
                [[fallthrough]];
            case t_S7KDatagramIdentifier::PanTilt: // 1017
                _navigation_interface->add_datagram_info(datagram_info);
                break;

            // ---------------- Environment datagrams ----------------
            case t_S7KDatagramIdentifier::SoundVelocityProfile: // 1009
                [[fallthrough]];
            case t_S7KDatagramIdentifier::CTD: // 1010
                [[fallthrough]];
            case t_S7KDatagramIdentifier::SonarPipeEnvironment: // 2004
                [[fallthrough]];
            case t_S7KDatagramIdentifier::SoundVelocity: // 7610
                [[fallthrough]];
            case t_S7KDatagramIdentifier::AbsorptionLoss: // 7611
                [[fallthrough]];
            case t_S7KDatagramIdentifier::SpreadingLoss: // 7612
                [[fallthrough]];
            case t_S7KDatagramIdentifier::ProfileAverageSalinity: // 7613
                [[fallthrough]];
            case t_S7KDatagramIdentifier::ProfileAverageTemperature: // 7614
                _environment_interface->add_datagram_info(datagram_info);
                break;

            // ---------------- Ping datagrams ----------------
            case t_S7KDatagramIdentifier::SonarSettings: // 7000
                [[fallthrough]];
            case t_S7KDatagramIdentifier::MatchFilter: // 7002
                [[fallthrough]];
            case t_S7KDatagramIdentifier::BeamGeometry: // 7004
                [[fallthrough]];
            case t_S7KDatagramIdentifier::BathymetricData: // 7006
                [[fallthrough]];
            case t_S7KDatagramIdentifier::SideScanData: // 7007
                [[fallthrough]];
            case t_S7KDatagramIdentifier::GenericWaterColumnData: // 7008
                [[fallthrough]];
            case t_S7KDatagramIdentifier::VerticalDepth: // 7009
                [[fallthrough]];
            case t_S7KDatagramIdentifier::TVGValues: // 7010
                [[fallthrough]];
            case t_S7KDatagramIdentifier::ImageData: // 7011
                [[fallthrough]];
            case t_S7KDatagramIdentifier::PingMotionData: // 7012
                [[fallthrough]];
            case t_S7KDatagramIdentifier::BeamformedData: // 7018
                [[fallthrough]];
            case t_S7KDatagramIdentifier::DetectionData: // 7026
                [[fallthrough]];
            case t_S7KDatagramIdentifier::RawDetectionData: // 7027
                [[fallthrough]];
            case t_S7KDatagramIdentifier::SnippetData: // 7028
                [[fallthrough]];
            case t_S7KDatagramIdentifier::CompressedBeamformedIntensityData: // 7041
                [[fallthrough]];
            case t_S7KDatagramIdentifier::CompressedWaterColumnData: // 7042
                [[fallthrough]];
            case t_S7KDatagramIdentifier::SegmentedRawDetectionData: // 7047
                [[fallthrough]];
            case t_S7KDatagramIdentifier::CalibratedBeamData: // 7048
                [[fallthrough]];
            case t_S7KDatagramIdentifier::CalibratedSideScanData: // 7057
                [[fallthrough]];
            case t_S7KDatagramIdentifier::SnippetBackscatteringStrength: // 7058
                [[fallthrough]];
            case t_S7KDatagramIdentifier::Sonar8kSeriesData: // 8100
                _ping_interface->add_datagram_info(datagram_info);
                break;

            // ---------------- Other datagrams ----------------
            // Everything not sorted above (e.g. Geodesy, SurveyLine, versions, BITE, system events,
            // remote control, file header/catalog, timestamps, ...) is tracked by the generic
            // other-file-data interface.
            default: {
                _otherfiledata_interface->add_datagram_info(datagram_info);
                break;
            }
        }
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "S7KFileHandler", float_precision, superscript_exponents);

        auto interface_printer = t_base::__printer__(float_precision, superscript_exponents);
        printer.append(interface_printer);

        return printer;
    }

  public:
    // -- class helper function macros --
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
