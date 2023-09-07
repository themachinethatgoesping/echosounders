// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/filesimradraw.doc.hpp"

/* library includes */
#include <frozen/map.h>
#include <frozen/string.h>
#include <frozen/unordered_map.h>
#include <magic_enum.hpp>

/* simrad types */
#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../filetemplates/datacontainers/pingcontainer.hpp"
#include "../filetemplates/i_inputfile.hpp"

#include "filedatainterfaces/simradannotationdatainterface.hpp"
#include "filedatainterfaces/simradconfigurationdatainterface.hpp"
#include "filedatainterfaces/simradenvironmentdatainterface.hpp"
#include "filedatainterfaces/simradnavigationdatainterface.hpp"
#include "filedatainterfaces/simradotherfiledatainterface.hpp"
#include "filedatainterfaces/simradpingdatainterface.hpp"

#include "filedatainterfaces/simraddatagraminterface.hpp"
#include "filedatatypes/simradping.hpp"

#include "filedatacontainers/simradfiledatacontainers.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class FileSimradRaw
    : public filetemplates::I_InputFile<datagrams::SimradDatagram,
                                        filedatainterfaces::SimradDatagramInterface<t_ifstream>>
{
  public:
    // ----- types -----
    using t_base =
        filetemplates::I_InputFile<datagrams::SimradDatagram,
                                   filedatainterfaces::SimradDatagramInterface<t_ifstream>>;

    using t_ConfigurationDataInterface =
        typename filedatainterfaces::SimradConfigurationDataInterface<t_ifstream>;
    using t_NavigationDataInterface =
        typename filedatainterfaces::SimradNavigationDataInterface<t_ifstream>;
    using t_EnvironmentDataInterface =
        typename filedatainterfaces::SimradEnvironmentDataInterface<t_ifstream>;
    using t_PingDataInterface = typename filedatainterfaces::SimradPingDataInterface<t_ifstream>;
    using t_AnnotationDataInterface =
        typename filedatainterfaces::SimradAnnotationDataInterface<t_ifstream>;
    using t_OtherFileDataDataInterface =
        typename filedatainterfaces::SimradOtherFileDataInterface<t_ifstream>;

    using typename t_base::FileInfoData;
    using typename t_base::FileInfos;

  private:
    // ----- file data interfaces -----
    std::shared_ptr<t_ConfigurationDataInterface> _configuration_interface =
        std::make_shared<t_ConfigurationDataInterface>();
    std::shared_ptr<t_NavigationDataInterface> _navigation_interface =
        std::make_shared<t_NavigationDataInterface>(_configuration_interface);
    std::shared_ptr<t_EnvironmentDataInterface> _environment_interface =
        std::make_shared<t_EnvironmentDataInterface>(_navigation_interface);
    std::shared_ptr<t_PingDataInterface> _ping_interface =
        std::make_shared<t_PingDataInterface>(_environment_interface);

    std::shared_ptr<t_AnnotationDataInterface> _annotation_interface =
        std::make_shared<t_AnnotationDataInterface>();
    std::shared_ptr<t_OtherFileDataDataInterface> _otherfiledata_interface =
        std::make_shared<t_OtherFileDataDataInterface>();

  public:
    // inherit constructors
    // This does not work, because I_InputFile calls append before the callback functions are
    // overwritten Thus inheriting constructors would lead to calling the callback functions of the
    // base class using filetemplates::I_InputFile<datagrams::SimradDatagram,
    // t_SimradDatagramIdentifier, t_ifstream>::
    //     I_InputFile;

    FileSimradRaw(const std::string&                                   file_path,
                  const std::unordered_map<std::string, FileInfoData>& cached_index =
                      std::unordered_map<std::string, FileInfoData>(),
                  bool init          = true,
                  bool show_progress = true)
        : t_base(cached_index)
    {
        this->append_file(file_path, show_progress);
        if (init)
            init_interfaces(false, show_progress);
    }
    FileSimradRaw(const std::string&                                   file_path,
                  const std::unordered_map<std::string, FileInfoData>& cached_index,
                  bool                                                 init,
                  tools::progressbars::I_ProgressBar&                  progress_bar)
        : t_base(cached_index)
    {
        this->append_file(file_path, progress_bar);
        if (init)
            init_interfaces(false, progress_bar);
    }

    FileSimradRaw(const std::vector<std::string>&                      file_paths,
                  const std::unordered_map<std::string, FileInfoData>& cached_index =
                      std::unordered_map<std::string, FileInfoData>(),
                  bool init          = true,
                  bool show_progress = true)
        : t_base(cached_index)
    {
        this->append_files(file_paths, show_progress);
        if (init)
            init_interfaces(false, show_progress);
    }
    FileSimradRaw(const std::vector<std::string>&                      file_paths,
                  const std::unordered_map<std::string, FileInfoData>& cached_index,
                  bool                                                 init,
                  tools::progressbars::I_ProgressBar&                  progress_bar)
        : t_base(cached_index)
    {
        this->append_files(file_paths, progress_bar);
        if (init)
            init_interfaces(false, progress_bar);
    }
    ~FileSimradRaw() = default;

    using t_base::init_interfaces;
    void init_interfaces(bool force, tools::progressbars::I_ProgressBar& progress_bar) final
    {
        // add file info
        _configuration_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _navigation_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _environment_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _annotation_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _otherfiledata_interface->add_file_information(this->_input_file_manager->get_file_paths());
        _ping_interface->add_file_information(this->_input_file_manager->get_file_paths());

        progress_bar.init(0., double(6), fmt::format("Initializing file interfaces"));
        ;
        _configuration_interface->init_from_file(force, progress_bar);
        progress_bar.tick();
        _navigation_interface->init_from_file(force, progress_bar);
        progress_bar.tick();
        _environment_interface->init_from_file(force, progress_bar);
        progress_bar.tick();

        _annotation_interface->init_from_file(force, progress_bar);
        progress_bar.tick();
        _otherfiledata_interface->init_from_file(force, progress_bar);
        progress_bar.tick();

        _ping_interface->init_from_file(force, progress_bar);
        progress_bar.tick();
        progress_bar.close(std::string("Done"));
    }

    auto& configuration_interface() { return *_configuration_interface; }
    auto& navigation_interface() { return *_navigation_interface; }
    auto& environment_interface() { return *_environment_interface; }
    auto& ping_interface() { return *_ping_interface; }
    auto& annotation_interface() { return *_annotation_interface; }
    auto& otherfiledata_interface() { return *_otherfiledata_interface; }

    filedatacontainers::SimradPingContainer<t_ifstream> pings() const
    {
        return _ping_interface->get_pings();
    }

    filedatacontainers::SimradPingContainer<t_ifstream> pings(const std::string& channel_id) const
    {
        return _ping_interface->get_pings(channel_id);
    }
    filedatacontainers::SimradPingContainer<t_ifstream> pings(
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
        _ping_interface->add_file_information(this->_input_file_manager->get_file_paths());
    }
    void callback_scan_new_file_end([[maybe_unused]] const std::string& file_path,
                                    [[maybe_unused]] size_t             file_paths_cnt) final
    {
    }

    void callback_scan_packet(
        filetemplates::datatypes::DatagramInfo_ptr<t_SimradDatagramIdentifier, t_ifstream>
            datagram_info) final
    {
        switch (datagram_info->get_datagram_identifier())
        {
            case t_SimradDatagramIdentifier::MRU0:
                [[fallthrough]];
            case t_SimradDatagramIdentifier::NME0: {
                _navigation_interface->add_datagram_info(datagram_info);
                break;
            }
            case t_SimradDatagramIdentifier::XML0: {
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
            case t_SimradDatagramIdentifier::RAW3: {
                _ping_interface->add_datagram_info(datagram_info);
                break;
            }
            case t_SimradDatagramIdentifier::FIL1: {
                _configuration_interface->add_datagram_info(datagram_info);
                break;
            }
            case t_SimradDatagramIdentifier::TAG0: {
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
        tools::classhelper::ObjectPrinter printer("FileSimradRaw", float_precision);

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

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
