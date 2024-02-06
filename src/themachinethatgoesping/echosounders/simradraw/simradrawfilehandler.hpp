// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawfilehandler.doc.hpp"

/* library includes */
#include <frozen/map.h>
#include <frozen/string.h>
#include <frozen/unordered_map.h>
#include <magic_enum.hpp>

/* simradraw types */
#include "datagrams.hpp"
#include "types.hpp"

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../filetemplates/datacontainers/pingcontainer.hpp"
#include "../filetemplates/i_inputfilehandler.hpp"

#include "filedatainterfaces/simradrawdatagramdatainterface.hpp"
#include "filedatainterfaces/simradrawannotationdatainterface.hpp"
#include "filedatainterfaces/simradrawconfigurationdatainterface.hpp"
#include "filedatainterfaces/simradrawenvironmentdatainterface.hpp"
#include "filedatainterfaces/simradrawnavigationdatainterface.hpp"
#include "filedatainterfaces/simradrawotherfiledatainterface.hpp"
#include "filedatainterfaces/simradrawpingdatainterface.hpp"

#include "filedatainterfaces/simradrawdatagraminterface.hpp"
#include "filedatatypes/simradrawping.hpp"

#include "filedatacontainers/simradrawfiledatacontainers.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {

template<typename t_ifstream>
class SimradRawFileHandler
    : public filetemplates::I_InputFileHandler<datagrams::SimradRawDatagram,
                                        filedatainterfaces::SimradRawDatagramInterface<t_ifstream>>
{
  public:
    // ----- types -----
    using t_base =
        filetemplates::I_InputFileHandler<datagrams::SimradRawDatagram,
                                   filedatainterfaces::SimradRawDatagramInterface<t_ifstream>>;

    using t_DatagramDataInterface =
        typename filedatainterfaces::SimradRawDatagramDataInterface<t_ifstream>;
    using t_ConfigurationDataInterface =
        typename filedatainterfaces::SimradRawConfigurationDataInterface<t_ifstream>;
    using t_NavigationDataInterface =
        typename filedatainterfaces::SimradRawNavigationDataInterface<t_ifstream>;
    using t_EnvironmentDataInterface =
        typename filedatainterfaces::SimradRawEnvironmentDataInterface<t_ifstream>;
    using t_PingDataInterface = typename filedatainterfaces::SimradRawPingDataInterface<t_ifstream>;
    using t_AnnotationDataInterface =
        typename filedatainterfaces::SimradRawAnnotationDataInterface<t_ifstream>;
    using t_OtherFileDataInterface =
        typename filedatainterfaces::SimradRawOtherFileDataInterface<t_ifstream>;

    using typename t_base::FilePackageIndex;
    using typename t_base::FileInfos;

  private:
    // ----- file data interfaces -----
    std::shared_ptr<t_DatagramDataInterface> _datagramdata_interface =
        std::make_shared<t_DatagramDataInterface>();
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
    // This does not work, because I_InputFileHandler calls append before the callback functions are
    // overwritten Thus inheriting constructors would lead to calling the callback functions of the
    // base class using filetemplates::I_InputFileHandler<datagrams::SimradRawDatagram,
    // t_SimradRawDatagramIdentifier, t_ifstream>::
    //     I_InputFileHandler;

    SimradRawFileHandler(const std::string&                                   file_path,
                  const std::unordered_map<std::string, std::string>& cached_paths_per_file_path =
                      std::unordered_map<std::string, std::string>(),
                  bool init          = true,
                  bool show_progress = true)
        : t_base(cached_paths_per_file_path)
    {
        this->append_file(file_path, show_progress);
        if (init)
            init_interfaces(false, show_progress);
    }
    SimradRawFileHandler(const std::string&                                   file_path,
                  const std::unordered_map<std::string, std::string>& cached_paths_per_file_path,
                  bool                                                 init,
                  tools::progressbars::I_ProgressBar&                  progress_bar)
        : t_base(cached_paths_per_file_path)
    {
        this->append_file(file_path, progress_bar);
        if (init)
            init_interfaces(false, progress_bar);
    }

    SimradRawFileHandler(const std::vector<std::string>&                      file_paths,
                  const std::unordered_map<std::string, std::string>& cached_paths_per_file_path =
                      std::unordered_map<std::string, std::string>(),
                  bool init          = true,
                  bool show_progress = true)
        : t_base(cached_paths_per_file_path)
    {
        this->append_files(file_paths, show_progress);
        if (init)
            init_interfaces(false, show_progress);
    }
    SimradRawFileHandler(const std::vector<std::string>&                      file_paths,
                  const std::unordered_map<std::string, std::string>& cached_paths_per_file_path,
                  bool                                                 init,
                  tools::progressbars::I_ProgressBar&                  progress_bar)
        : t_base(cached_paths_per_file_path)
    {
        this->append_files(file_paths, progress_bar);
        if (init)
            init_interfaces(false, progress_bar);
    }
    ~SimradRawFileHandler() = default;

    using t_base::init_interfaces;
    void init_interfaces(bool force, tools::progressbars::I_ProgressBar& progress_bar) final
    {
        auto number_of_primary_files = _configuration_interface->per_primary_file().size();
        progress_bar.init(
            0., number_of_primary_files * 2 + 5, fmt::format("Initializing file interfaces"));

        progress_bar.set_prefix("Initializing datagramdata interface");
        _datagramdata_interface->init_from_file(force, progress_bar);
        progress_bar.tick();

        progress_bar.set_prefix("Initializing configuration");
        _configuration_interface->init_from_file(force, progress_bar);
        progress_bar.tick();

        progress_bar.set_prefix("Initializing navigation");
        _navigation_interface->init_from_file(force, progress_bar, true);

        progress_bar.set_prefix("Initializing environment");
        _environment_interface->init_from_file(force, progress_bar);
        progress_bar.tick();
        progress_bar.set_prefix("Initializing annotation");
        _annotation_interface->init_from_file(force, progress_bar);
        progress_bar.tick();
        progress_bar.set_prefix("Initializing other");
        _otherfiledata_interface->init_from_file(force, progress_bar);
        progress_bar.tick();

        progress_bar.set_prefix("Initializing ping interface");
        _ping_interface->init_from_file(force, progress_bar, true);

        progress_bar.close(std::string("Done"));
    }

    auto& datagramdata_interface() { return *_datagramdata_interface; }
    auto& configuration_interface() { return *_configuration_interface; }
    auto& navigation_interface() { return *_navigation_interface; }
    auto& environment_interface() { return *_environment_interface; }
    auto& ping_interface() { return *_ping_interface; }
    auto& annotation_interface() { return *_annotation_interface; }
    auto& otherfiledata_interface() { return *_otherfiledata_interface; }

    filedatacontainers::SimradRawPingContainer<t_ifstream> pings(bool sorted_by_time) const
    {
        if (sorted_by_time)
        {
            return _ping_interface->get_pings().get_sorted_by_time();
        }
        return _ping_interface->get_pings();
    }


    std::vector<std::string> channel_ids() const { return _ping_interface->channel_ids(); }

  protected:
    void callback_scan_new_file_begin([[maybe_unused]] const std::string& file_path,
                                      [[maybe_unused]] size_t             file_paths_cnt) final
    {
        // TODO: this is a bit ugly since updates all files and not just the new ones
        // add file info
        _datagramdata_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _configuration_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _navigation_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _environment_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _annotation_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _otherfiledata_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _ping_interface->add_file_information(this->_input_file_manager->get_file_paths());
    }
    void callback_scan_new_file_end([[maybe_unused]] const std::string& file_path,
                                    [[maybe_unused]] size_t             file_paths_cnt) final
    {
    }

    void callback_scan_packet(
        filetemplates::datatypes::DatagramInfo_ptr<t_SimradRawDatagramIdentifier, t_ifstream>
            datagram_info) final
    {
        _datagramdata_interface->add_datagram_info(datagram_info);

        switch (datagram_info->get_datagram_identifier())
        {
            case t_SimradRawDatagramIdentifier::MRU0:
                [[fallthrough]];
            case t_SimradRawDatagramIdentifier::NME0: {
                _navigation_interface->add_datagram_info(datagram_info);
                break;
            }
            case t_SimradRawDatagramIdentifier::XML0: {
                // speed up decision making by using a map lookup
                static constexpr frozen::map<frozen::string, int, 5> xml_type_map = {
                    { "Parameter", 1 },        { "Configuration", 2 }, { "Environment", 3 },
                    { "InitialParameter", 4 }, { "invalid", 5 },
                };
                
                if (datagram_info->get_extra_infos().empty())
                {
                    auto& ifs = datagram_info->get_stream_and_seek();

                    // this also changes xml_type since it is a reference
                    auto xml_type = datagrams::XML0::get_xml_datagram_type_from_stream(ifs);
                    
                    datagram_info->set_extra_infos(xml_type);

                    if (!datagram_info->get_stream().good())
                        break;
                }

                const auto xml_type_it =
                    xml_type_map.find(frozen::string(datagram_info->get_extra_infos()));

                switch (xml_type_it->second)
                {
                    case 1: //"Parameter"
                        _ping_interface->add_datagram_info(datagram_info);
                        break;
                    case 2: //"Configuration"
                        _configuration_interface->add_datagram_info(datagram_info);
                        break;
                    case 3: //"Environment"
                        _environment_interface->add_datagram_info(datagram_info);
                        break;
                    case 4: //"InitialParameter"
                        _ping_interface->add_datagram_info(datagram_info);
                        break;
                    case 5: //"invalid"
                        throw std::runtime_error(fmt::format("XML0 datagram is invalid: {}",
                                                             datagram_info->info_string()));
                        break;
                    default:
                        _otherfiledata_interface->add_datagram_info(datagram_info);
                        break;
                }

                break;
            }
            case t_SimradRawDatagramIdentifier::RAW3: {
                _ping_interface->add_datagram_info(datagram_info);
                break;
            }
            case t_SimradRawDatagramIdentifier::FIL1: {
                _configuration_interface->add_datagram_info(datagram_info);
                break;
            }
            case t_SimradRawDatagramIdentifier::TAG0: {
                _annotation_interface->add_datagram_info(datagram_info);
                break;
            }
            default: {
                _otherfiledata_interface->add_datagram_info(datagram_info);
                break;
            }
        }
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("SimradRawFileHandler", float_precision);

        auto interface_printer = t_base::__printer__(float_precision);

        printer.append(interface_printer);

        printer.register_section("Detected Pings");
        printer.append(_ping_interface->get_pings().__printer__(float_precision), false, '^');
        // printer.append(_ping_container.__printer__(float_precision), false, '^');

        return printer;
    }

  public:
    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
