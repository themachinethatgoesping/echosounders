// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallfilehandler.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "datagrams.hpp"
#include "types.hpp"

#include "../filetemplates/datacontainers/pingcontainer.hpp"
#include "../filetemplates/i_inputfilehandler.hpp"

// #include "filedatainterfaces/kmallannotationdatainterface.hpp"
// #include "filedatainterfaces/kmallconfigurationdatainterface.hpp"
// #include "filedatainterfaces/kmalldatagramdatainterface.hpp"
#include "filedatainterfaces/kmalldatagraminterface.hpp"
// #include "filedatainterfaces/kmallenvironmentdatainterface.hpp"
// #include "filedatainterfaces/kmallnavigationdatainterface.hpp"
// #include "filedatainterfaces/kmallotherfiledatainterface.hpp"
// #include "filedatainterfaces/kmallpingdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {

template<typename t_ifstream>
class KMALLFileHandler
    : public filetemplates::I_InputFileHandler<datagrams::KMALLDatagram,
                                               filedatainterfaces::KMALLDatagramInterface<t_ifstream>>
{
  public:
    using t_base =
        filetemplates::I_InputFileHandler<datagrams::KMALLDatagram,
                                          filedatainterfaces::KMALLDatagramInterface<t_ifstream>>;

    // ----- types -----
    // using t_DatagramDataInterface =
    //     typename filedatainterfaces::KMALLDatagramDataInterface<t_ifstream>;
    // using t_OtherFileDataInterface =
    //     typename filedatainterfaces::KMALLOtherFileDataInterface<t_ifstream>;
    // using t_AnnotationDataInterface =
    //     typename filedatainterfaces::KMALLAnnotationDataInterface<t_ifstream>;
    // using t_ConfigurationDataInterface =
    //     typename filedatainterfaces::KMALLConfigurationDataInterface<t_ifstream>;
    // using t_NavigationDataInterface =
    //     typename filedatainterfaces::KMALLNavigationDataInterface<t_ifstream>;
    // using t_EnvironmentDataInterface =
    //     typename filedatainterfaces::KMALLEnvironmentDataInterface<t_ifstream>;
    // using t_PingDataInterface =
    //     typename filedatainterfaces::KMALLPingDataInterface<t_ifstream>;

    using typename t_base::FileInfos;
    using typename t_base::FilePackageIndex;

  private:
    // ----- file data interfaces -----
    // std::shared_ptr<t_DatagramDataInterface> _datagramdata_interface =
    //     std::make_shared<t_DatagramDataInterface>();
    // std::shared_ptr<t_OtherFileDataInterface> _otherfiledata_interface =
    //     std::make_shared<t_OtherFileDataInterface>();
    // std::shared_ptr<t_AnnotationDataInterface> _annotation_interface =
    //     std::make_shared<t_AnnotationDataInterface>();

    // std::shared_ptr<t_ConfigurationDataInterface> _configuration_interface =
    //     std::make_shared<t_ConfigurationDataInterface>();
    // std::shared_ptr<t_NavigationDataInterface> _navigation_interface =
    //     std::make_shared<t_NavigationDataInterface>(_configuration_interface);
    // std::shared_ptr<t_EnvironmentDataInterface> _environment_interface =
    //     std::make_shared<t_EnvironmentDataInterface>(_navigation_interface);
    // std::shared_ptr<t_PingDataInterface> _ping_interface =
    //     std::make_shared<t_PingDataInterface>(_environment_interface);

  public:
    // inherit constructors
    // This does not work, because I_InputFileHandler calls append before the callback functions are
    // overwritten Thus inheriting constructors would lead to calling the callback functions of the
    // base class using filetemplates::I_InputFileHandler<datagrams::KMALLDatagram,
    // t_KMALLDatagramIdentifier, t_ifstream>::
    //     I_InputFileHandler;

    KMALLFileHandler(const std::string&                                  file_path,
                   const std::unordered_map<std::string, std::string>& index_paths =
                       std::unordered_map<std::string, std::string>(),
                   bool init          = true,
                   bool show_progress = true)
        : t_base(index_paths)
    {
        this->append_file(file_path, show_progress);
        setup_interfaces();
        if (init)
            init_interfaces(false, show_progress);
    }
    KMALLFileHandler(const std::string&                                  file_path,
                   const std::unordered_map<std::string, std::string>& index_paths,
                   bool                                                init,
                   tools::progressbars::I_ProgressBar&                 progress_bar)
        : t_base(index_paths)
    {
        this->append_file(file_path, progress_bar);
        setup_interfaces();
        if (init)
            init_interfaces(false, progress_bar);
    }

    KMALLFileHandler(const std::vector<std::string>&                     file_paths,
                   const std::unordered_map<std::string, std::string>& index_paths =
                       std::unordered_map<std::string, std::string>(),
                   bool init          = true,
                   bool show_progress = true)
        : t_base(index_paths)
    {
        this->append_files(file_paths, show_progress);
        setup_interfaces();
        if (init)
            init_interfaces(false, show_progress);
    }
    KMALLFileHandler(const std::vector<std::string>&                     file_paths,
                   const std::unordered_map<std::string, std::string>& index_paths,
                   bool                                                init,
                   tools::progressbars::I_ProgressBar&                 progress_bar)
        : t_base(index_paths)
    {
        this->append_files(file_paths, progress_bar);
        setup_interfaces();
        if (init)
            init_interfaces(false, progress_bar);
    }
    ~KMALLFileHandler() = default;

    void setup_interfaces()
    {
        // auto t_start = std::chrono::high_resolution_clock::now();
        //  link wcd/all files
        // link_all_and_wcd_files();
        // auto t_end = std::chrono::high_resolution_clock::now();

        // double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end -
        // t_start).count();

        // TODO: such messages should be logged, could also be part of the object printer
        // std::cerr << fmt::format("Linking wcd/all files took: {}ms", elapsed_time_ms) <<
        // std::endl; std::cerr << fmt::format("Linking wcd/all files took: {}µs", elapsed_time_ms /
        // 1000)
        //           << std::endl;
    }

    using t_base::init_interfaces;
    void init_interfaces([[maybe_unused]] bool               force,
                         [[maybe_unused]] tools::progressbars::I_ProgressBar& progress_bar) final
    {
        // auto number_of_primary_files = _configuration_interface->per_primary_file().size();
        // progress_bar.init(
        //     0., number_of_primary_files * 1 + 5, fmt::format("Initializing file interfaces"));

        // progress_bar.set_prefix("Initializing datagramdata interface");
        // _datagramdata_interface->init_from_file(this->get_index_paths(), force, progress_bar);
        // progress_bar.tick();

        // progress_bar.set_prefix("Initializing configuration");
        // _configuration_interface->init_from_file(this->get_index_paths(), force, progress_bar);
        // progress_bar.tick();

        // progress_bar.set_prefix("Initializing navigation");
        // _navigation_interface->init_from_file(
        //     this->get_index_paths(), force, progress_bar, true);

        // progress_bar.set_prefix("Initializing environment");
        // _environment_interface->init_from_file(this->get_index_paths(), force, progress_bar);
        // progress_bar.tick();
        // progress_bar.set_prefix("Initializing annotation");
        // _annotation_interface->init_from_file(this->get_index_paths(), force, progress_bar);
        // progress_bar.tick();
        // progress_bar.set_prefix("Initializing other");
        // _otherfiledata_interface->init_from_file(this->get_index_paths(), force, progress_bar);
        // progress_bar.tick();

        // // std::cout << std::endl; // TODO: remove this workaround
        // progress_bar.init(0., number_of_primary_files, fmt::format("Initializing ping
        // interface")); _ping_interface->init_from_file(this->get_index_paths(), force,
        // progress_bar, true);

        // progress_bar.close(std::string("Done"));
    }

    // auto& datagramdata_interface() { return *_datagramdata_interface; }
    // auto& configuration_interface() { return *_configuration_interface; }
    // auto& navigation_interface() { return *_navigation_interface; }
    // auto& environment_interface() { return *_environment_interface; }
    // auto& annotation_interface() { return *_annotation_interface; }
    // auto& otherfiledata_interface() { return *_otherfiledata_interface; }
    // auto& ping_interface() { return *_ping_interface; }

    // filedatacontainers::KMALLPingContainer<t_ifstream> get_pings(
    //     bool sorted_by_time = true) const
    // {
    //     if (sorted_by_time)
    //     {
    //         return _ping_interface->get_pings().get_sorted_by_time();
    //     }
    //     return _ping_interface->get_pings();
    // }

    // std::vector<std::string> get_channel_ids() const { return _ping_interface->get_channel_ids();
    // }

  protected:
    // void callback_scan_new_file_begin([[maybe_unused]] const std::string& file_path,
    //                                   [[maybe_unused]] size_t             file_paths_cnt) final
    // {
    //     // TODO: this is a bit ugly since updates all files and not just the new ones
    //     // add file info
    //     //
    //     _datagramdata_interface->add_file_information(this->_input_file_manager->get_file_paths());
    //     //
    //     _configuration_interface->add_file_information(this->_input_file_manager->get_file_paths());
    //     //
    //     _navigation_interface->add_file_information(this->_input_file_manager->get_file_paths());
    //     //
    //     _environment_interface->add_file_information(this->_input_file_manager->get_file_paths());
    //     //
    //     _annotation_interface->add_file_information(this->_input_file_manager->get_file_paths());
    //     //
    //     _otherfiledata_interface->add_file_information(this->_input_file_manager->get_file_paths());
    //     // _ping_interface->add_file_information(this->_input_file_manager->get_file_paths());
    // }
    // void callback_scan_new_file_end([[maybe_unused]] const std::string& file_path,
    //                                 [[maybe_unused]] size_t             file_paths_cnt) final
    // {
    // }

    // void callback_scan_packet(
    //     filetemplates::datatypes::DatagramInfo_ptr<t_KMALLDatagramIdentifier, t_ifstream>
    //         datagram_info) final
    // {
    //     _datagramdata_interface->add_datagram_info(datagram_info);
    //     switch (datagram_info->get_datagram_identifier())
    //     {
    //             // Navigation datagrams
    //         case t_KMALLDatagramIdentifier::AttitudeDatagram:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::NetworkAttitudeVelocityDatagram:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::ClockDatagram:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::DepthOrHeightDatagram:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::HeadingDatagram:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::PositionDatagram:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::SingleBeamEchoSounderDepth: {
    //             _navigation_interface->add_datagram_info(datagram_info);
    //             break;
    //         }
    //         // multibeam data datagrams
    //         case t_KMALLDatagramIdentifier::XYZDatagram:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::ExtraDetections:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::RawRangeAndAngle:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::SeabedImageData:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::WatercolumnDatagram:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::QualityFactorDatagram: {
    //             if (datagram_info->get_extra_infos().size() != 4)
    //             {
    //                 // read the ping counter
    //                 auto& ifs =
    //                     datagram_info->get_stream_and_seek(16); // offset=16 bytes (header size)

    //                 struct
    //                 {
    //                     uint16_t ping_counter;
    //                     uint16_t serial_number;
    //                 } counter_snumber;

    //                 // ifs.seekg(16, std::ios::cur); // skip header
    //                 ifs.read(reinterpret_cast<char*>(&counter_snumber), sizeof(counter_snumber));

    //                 datagram_info->template
    //                 add_extra_info<uint16_t>(counter_snumber.ping_counter);
    //                 datagram_info->template
    //                 add_extra_info<uint16_t>(counter_snumber.serial_number);
    //             }
    //             _ping_interface->add_datagram_info(datagram_info);
    //             break;
    //         }
    //             // Environment datagrams
    //         case t_KMALLDatagramIdentifier::SurfaceSoundSpeedDatagram:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::SoundSpeedProfileDatagram: {
    //             _environment_interface->add_datagram_info(datagram_info);
    //             break;
    //         }
    //         // Configuration datagrams
    //         case t_KMALLDatagramIdentifier::RuntimeParameters:
    //             // this datagram also has ping counter and system serial number
    //             if (datagram_info->get_extra_infos().size() != 4)
    //             {
    //                 // read the ping counter
    //                 auto& ifs =
    //                     datagram_info->get_stream_and_seek(16); // offset=16 bytes (header size)

    //                 struct
    //                 {
    //                     uint16_t ping_counter;
    //                     uint16_t serial_number;
    //                 } counter_snumber;

    //                 // ifs.seekg(16, std::ios::cur); // skip header
    //                 ifs.read(reinterpret_cast<char*>(&counter_snumber), sizeof(counter_snumber));

    //                 datagram_info->template
    //                 add_extra_info<uint16_t>(counter_snumber.ping_counter);
    //                 datagram_info->template
    //                 add_extra_info<uint16_t>(counter_snumber.serial_number);
    //             }
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::InstallationParametersStart:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::InstallationParametersStop:
    //             [[fallthrough]];
    //         case t_KMALLDatagramIdentifier::ExtraParameters: {
    //             _configuration_interface->add_datagram_info(datagram_info);
    //             break;
    //         }
    //         default: {
    //             _otherfiledata_interface->add_datagram_info(datagram_info);
    //             break;
    //         }
    //     }
    // }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "KMALLFileHandler", float_precision, superscript_exponents);

        auto interface_printer = t_base::__printer__(float_precision, superscript_exponents);

        printer.append(interface_printer);

        // printer.register_section("Detected Pings");
        // printer.append(
        //     _ping_interface->get_pings().__printer__(float_precision, superscript_exponents),
        //     false,
        //     '^');

        return printer;
    }

  public:
    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
