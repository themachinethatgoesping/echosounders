// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/fileem3000.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../filetemplates/datacontainers/pingcontainer.hpp"
#include "../filetemplates/i_inputfile.hpp"

#include "em3000_datagrams.hpp"
#include "em3000_types.hpp"

#include "filedatainterfaces/em3000annotationdatainterface.hpp"
#include "filedatainterfaces/em3000configurationdatainterface.hpp"
#include "filedatainterfaces/em3000datagraminterface.hpp"
#include "filedatainterfaces/em3000environmentdatainterface.hpp"
#include "filedatainterfaces/em3000navigationdatainterface.hpp"
#include "filedatainterfaces/em3000otherfiledatainterface.hpp"
#include "filedatainterfaces/em3000pingdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {

template<typename t_ifstream>
class FileEM3000
    : public filetemplates::I_InputFile<datagrams::EM3000Datagram,
                                        filedatainterfaces::EM3000DatagramInterface<t_ifstream>>
{
    using t_base =
        filetemplates::I_InputFile<datagrams::EM3000Datagram,
                                   filedatainterfaces::EM3000DatagramInterface<t_ifstream>>;

    // ----- types -----
    using t_OtherFileDataInterface =
        typename filedatainterfaces::EM3000OtherFileDataInterface<t_ifstream>;
    using t_AnnotationDataInterface =
        typename filedatainterfaces::EM3000AnnotationDataInterface<t_ifstream>;
    using t_ConfigurationDataInterface =
        typename filedatainterfaces::EM3000ConfigurationDataInterface<t_ifstream>;
    using t_NavigationDataInterface =
        typename filedatainterfaces::EM3000NavigationDataInterface<t_ifstream>;
    using t_EnvironmentDataInterface =
        typename filedatainterfaces::EM3000EnvironmentDataInterface<t_ifstream>;
    using t_PingDataInterface = typename filedatainterfaces::EM3000PingDataInterface<t_ifstream>;

    // ----- file data interfaces -----
    std::shared_ptr<t_OtherFileDataInterface> _otherfiledata_interface =
        std::make_shared<t_OtherFileDataInterface>();
    std::shared_ptr<t_AnnotationDataInterface> _annotation_interface =
        std::make_shared<t_AnnotationDataInterface>();

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
    // This does not work, because I_InputFile calls append before the callback functions are
    // overwritten Thus inheriting constructors would lead to calling the callback functions of the
    // base class using filetemplates::I_InputFile<datagrams::EM3000Datagram,
    // t_EM3000DatagramIdentifier, t_ifstream>::
    //     I_InputFile;

    FileEM3000(const std::string& file_path, bool init = true, bool show_progress = true)
    {
        this->append_file(file_path, show_progress);
        if (init)
            init_interfaces(false, show_progress);
    }
    FileEM3000(const std::string&                  file_path,
               bool                                init,
               tools::progressbars::I_ProgressBar& progress_bar)
    {
        this->append_file(file_path, progress_bar);
        if (init)
            init_interfaces(false, progress_bar);
    }

    FileEM3000(const std::vector<std::string>& file_paths,
               bool                            init          = true,
               bool                            show_progress = true)
    {
        this->append_files(file_paths, show_progress);
        if (init)
            init_interfaces(false, show_progress);
    }
    FileEM3000(const std::vector<std::string>&     file_paths,
               bool                                init,
               tools::progressbars::I_ProgressBar& progress_bar)
    {
        this->append_files(file_paths, progress_bar);
        if (init)
            init_interfaces(false, progress_bar);
    }
    ~FileEM3000() = default;

    using t_base::init_interfaces;
    void init_interfaces([[maybe_unused]] bool               force,
                         tools::progressbars::I_ProgressBar& progress_bar) final
    {
        // add file info
        _configuration_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _navigation_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _environment_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _annotation_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _otherfiledata_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _ping_interface->add_file_information(this->_input_file_manager->get_file_paths());

        // link wcd/all files
        std::map<std::string, size_t> wcd_files;
        std::map<std::string, size_t> all_files;
        const auto&                   file_paths = *(this->_input_file_manager->get_file_paths());

        // sort the files into wcd and all files
        for (unsigned int file_nr = 0; file_nr < file_paths.size(); ++file_nr)
        {
            // use std filesystem to get the file name (without extension) and file extension
            std::filesystem::path file_path(file_paths[file_nr]);
            std::string           file_name = file_path.stem().string();
            std::string           file_ext  = file_path.extension().string();

            if (file_ext == ".all")
            {
                if (all_files.find(file_name) != all_files.end())
                {
                    throw std::runtime_error(
                        fmt::format("Multiple .all files with the same name: \n[{}]: {}\n[{}]: {}",
                                    file_nr,
                                    file_paths[file_nr],
                                    all_files[file_name],
                                    file_paths[all_files[file_name]]));
                }

                all_files[file_name] = file_nr;
            }
            else if (file_ext == ".wcd")
            {
                if (wcd_files.find(file_name) != wcd_files.end())
                {
                    throw std::runtime_error(
                        fmt::format("Multiple .wcd files with the same name: \n[{}]: {}\n[{}]: {}",
                                    file_nr,
                                    file_paths[file_nr],
                                    wcd_files[file_name],
                                    file_paths[wcd_files[file_name]]));
                }

                wcd_files[file_name] = file_nr;
            }
            else
            {
                throw std::runtime_error(
                    fmt::format("Unknown file extension: {} [must be .all or .wcd]", file_ext));
            }
        }

        // link the wcd to matching all files
        for (const auto& [file_name, wcd_file_nr] : wcd_files)
        {
            using t_filedatainterface =
                typename filetemplates::datainterfaces::I_FileDataInterfacePerFile<
                    filedatainterfaces::EM3000DatagramInterface<t_ifstream>>;

            auto all_path = all_files.find(file_name);

            // check if there is a matching all file
            if (all_path != all_files.end())
            {
                auto all_file_nr = all_path->second;
                t_filedatainterface::link_file_interfaces(
                    _configuration_interface->per_file_ptr(all_file_nr),
                    _configuration_interface->per_file_ptr(wcd_file_nr));
                t_filedatainterface::link_file_interfaces(
                    _navigation_interface->per_file_ptr(all_file_nr),
                    _navigation_interface->per_file_ptr(wcd_file_nr));
                t_filedatainterface::link_file_interfaces(
                    _environment_interface->per_file_ptr(all_file_nr),
                    _environment_interface->per_file_ptr(wcd_file_nr));
                t_filedatainterface::link_file_interfaces(
                    _annotation_interface->per_file_ptr(all_file_nr),
                    _annotation_interface->per_file_ptr(wcd_file_nr));
                t_filedatainterface::link_file_interfaces(
                    _otherfiledata_interface->per_file_ptr(all_file_nr),
                    _otherfiledata_interface->per_file_ptr(wcd_file_nr));
                t_filedatainterface::link_file_interfaces(
                    _ping_interface->per_file_ptr(all_file_nr),
                    _ping_interface->per_file_ptr(wcd_file_nr));
            }
        }

        progress_bar.init(0., double(2), fmt::format("Initializing file interfaces"));

        progress_bar.set_postfix("Initializing configuration");
        _configuration_interface->init_from_file(force, progress_bar);
        progress_bar.set_postfix("Initializing navigation");
        _navigation_interface->init_from_file(force, progress_bar);
        progress_bar.tick();

        progress_bar.set_postfix("Initializing environment");
        _environment_interface->init_from_file(force, progress_bar);
        progress_bar.set_postfix("Initializing annotation");
        _annotation_interface->init_from_file(force, progress_bar);
        progress_bar.set_postfix("Initializing other");
        _otherfiledata_interface->init_from_file(force, progress_bar);

        progress_bar.set_postfix("Initializing ping interface");
        _ping_interface->init_from_file(force, progress_bar);
        progress_bar.tick();
        progress_bar.close(std::string("Done"));
    }

    auto& configuration_interface() { return *_configuration_interface; }
    auto& navigation_interface() { return *_navigation_interface; }
    auto& environment_interface() { return *_environment_interface; }
    auto& annotation_interface() { return *_annotation_interface; }
    auto& otherfiledata_interface() { return *_otherfiledata_interface; }
    auto& ping_interface() { return *_ping_interface; }

    filedatacontainers::EM3000PingContainer<t_ifstream> pings() const
    {
        return _ping_interface->get_pings();
    }

    filedatacontainers::EM3000PingContainer<t_ifstream> pings(const std::string& channel_id) const
    {
        return _ping_interface->get_pings(channel_id);
    }
    filedatacontainers::EM3000PingContainer<t_ifstream> pings(
        const std::vector<std::string>& channel_ids) const
    {
        return _ping_interface->get_pings()(channel_ids);
    }
    std::vector<std::string> channel_ids() const { return _ping_interface->channel_ids(); }

  protected:
    void callback_scan_new_file_begin([[maybe_unused]] const std::string& file_path,
                                      [[maybe_unused]] size_t             file_paths_cnt) final
    {
        // TODO: this is a bit ugly since updates all files and not just the new ones
        // add file info
        _configuration_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _navigation_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _environment_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _annotation_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _otherfiledata_interface->add_file_information(this->_input_file_manager->get_file_paths());
        //_ping_interface->add_file_information(this->_input_file_manager->get_file_paths());
    }
    void callback_scan_new_file_end([[maybe_unused]] const std::string& file_path,
                                    [[maybe_unused]] size_t             file_paths_cnt) final
    {
    }

    filetemplates::datatypes::DatagramInfo_ptr<t_EM3000DatagramIdentifier, t_ifstream>
    callback_scan_packet(t_ifstream&                   ifs,
                         typename t_ifstream::pos_type pos,
                         size_t                        file_paths_cnt) final
    {
        auto header    = datagrams::EM3000Datagram::from_stream(ifs);
        auto type      = header.get_datagram_identifier();
        auto timestamp = header.get_timestamp();

        auto datagram_info = std::make_shared<
            filetemplates::datatypes::DatagramInfo<t_EM3000DatagramIdentifier, t_ifstream>>(
            file_paths_cnt, pos, this->_input_file_manager, timestamp, type);

        switch (type)
        {
                // Navigation datagrams
            case t_EM3000DatagramIdentifier::AttitudeDatagram:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::NetworkAttitudeVelocityDatagram:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::ClockDatagram:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::DepthOrHeightDatagram:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::HeadingDatagram:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::PositionDatagram:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::SingleBeamEchoSounderDepth: {
                _navigation_interface->add_datagram_info(datagram_info);
                header.skip(ifs);
                break;
            }
                // multibeam data datagrams
            case t_EM3000DatagramIdentifier::XYZDatagram:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::ExtraDetections:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::RawRangeAndAngle:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::SeabedImageData:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::WaterColumnDatagram:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::QualityFactorDatagram: {
                _ping_interface->add_datagram_info(datagram_info);
                header.skip(ifs);
                break;
            }
                // Environment datagrams
            case t_EM3000DatagramIdentifier::SurfaceSoundSpeedDatagram:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::SoundSpeedProfileDatagram: {
                _environment_interface->add_datagram_info(datagram_info);
                header.skip(ifs);
                break;
            }
                // Configuration datagrams
            case t_EM3000DatagramIdentifier::InstallationParametersStart:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::InstallationParametersStop:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::RuntimeParameters:
                [[fallthrough]];
            case t_EM3000DatagramIdentifier::ExtraParameters: {
                _configuration_interface->add_datagram_info(datagram_info);
                header.skip(ifs);
                break;
            }
                //     case t_EM3000DatagramIdentifier::XML0: {

                //         auto xml = datagrams::XML0::from_stream(ifs, header);

                //         if (!ifs.good())
                //             break;

                //         auto xml_type = xml.get_xml_datagram_type();

                //         if (xml_type == "Parameter")
                //         {
                //             _ping_interface->add_datagram_info(datagram_info);
                //         }
                //         else if (xml_type == "InitialParameter")
                //         {
                //             _ping_interface->add_datagram_info(datagram_info);
                //         }
                //         else if (xml_type == "Configuration")
                //         {
                //             _configuration_interface->add_datagram_info(datagram_info);
                //         }
                //         else if (xml_type == "Environment")
                //         {
                //             _environment_interface->add_datagram_info(datagram_info);
                //         }
                //         else
                //         {
                //             _otherfiledata_interface->add_datagram_info(datagram_info);
                //         }
                //         // don't skip here, because the XML datagram was read already
                //         break;
                //     }
                //     case t_EM3000DatagramIdentifier::RAW3: {
                //         _ping_interface->add_datagram_info(datagram_info);
                //         header.skip(ifs);
                //         break;
                //     }
                //     case t_EM3000DatagramIdentifier::FIL1: {
                //         _configuration_interface->add_datagram_info(datagram_info);
                //         header.skip(ifs);
                //         break;
                //     }
                //     case t_EM3000DatagramIdentifier::TAG0: {
                //         _annotation_interface->add_datagram_info(datagram_info);
                //         header.skip(ifs);
                //         break;
                //     }
            default: {
                _otherfiledata_interface->add_datagram_info(datagram_info);
                header.skip(ifs);
                break;
            }
        }

        return datagram_info;
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("FileEM3000", float_precision);

        auto interface_printer = t_base::__printer__(float_precision);

        printer.append(interface_printer);

        printer.register_section("Detected Pings");
        printer.append(_ping_interface->get_pings().__printer__(float_precision), false, '^');

        return printer;
    }

  public:
    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
