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
#include "filedatainterfaces/em3000datagraminterface.hpp"
#include "filedatainterfaces/em3000otherfiledatainterface.hpp"

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

    // ----- file data interfaces -----
    std::shared_ptr<filedatainterfaces::EM3000OtherFileDataInterface<t_ifstream>>
        _otherfiledata_interface =
            std::make_shared<filedatainterfaces::EM3000OtherFileDataInterface<t_ifstream>>();
    std::shared_ptr<filedatainterfaces::EM3000AnnotationDataInterface<t_ifstream>>
        _annotation_interface =
            std::make_shared<filedatainterfaces::EM3000AnnotationDataInterface<t_ifstream>>();

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
        progress_bar.init(0., double(6), fmt::format("Initializing file interfaces"));

        // _configuration_interface->init_from_file(force, progress_bar);
        progress_bar.tick();
        // _navigation_interface->init_from_file(force, progress_bar);
        progress_bar.tick();
        // _environment_interface->init_from_file(force, progress_bar);
        progress_bar.tick();

        _annotation_interface->init_from_file(force, progress_bar);
        progress_bar.tick();
        _otherfiledata_interface->init_from_file(force, progress_bar);
        progress_bar.tick();

        //_ping_interface->init_from_file(force, progress_bar);
        progress_bar.tick();
        progress_bar.close(std::string("Done"));
    }

    // filedatainterfaces::EM3000ConfigurationDataInterface<t_ifstream>& configuration_interface()
    // {
    //     return *_configuration_interface;
    // }
    // filedatainterfaces::EM3000NavigationDataInterface<t_ifstream>& navigation_interface()
    // {
    //     return *_navigation_interface;
    // }
    // filedatainterfaces::EM3000EnvironmentDataInterface<t_ifstream>& environment_interface()
    // {
    //     return *_environment_interface;
    // }
    // filedatainterfaces::EM3000PingDataInterface<t_ifstream>& ping_interface()
    // {
    //     return *_ping_interface;
    // }
    filedatainterfaces::EM3000AnnotationDataInterface<t_ifstream>& annotation_interface()
    {
        return *_annotation_interface;
    }
    filedatainterfaces::EM3000OtherFileDataInterface<t_ifstream>& otherfiledata_interface()
    {
        return *_otherfiledata_interface;
    }

    // filedatacontainers::EM3000PingContainer<t_ifstream> pings() const
    // {
    //     return _ping_interface->get_pings();
    // }

    // filedatacontainers::EM3000PingContainer<t_ifstream> pings(const std::string& channel_id)
    // const
    // {
    //     return _ping_interface->get_pings(channel_id);
    // }
    // filedatacontainers::EM3000PingContainer<t_ifstream> pings(
    //     const std::vector<std::string>& channel_ids) const
    // {
    //     return _ping_interface->get_pings()(channel_ids);
    // }
    // std::vector<std::string> channel_ids() const { return _ping_interface->channel_ids(); }

  protected:
    void callback_scan_new_file_begin([[maybe_unused]] const std::string& file_path,
                                      [[maybe_unused]] size_t             file_paths_cnt) final
    {
        // _configuration_interface->add_file_interface(file_paths_cnt);
        // _navigation_interface->add_file_interface(file_paths_cnt);
        // _environment_interface->add_file_interface(file_paths_cnt);
        // _ping_interface->add_file_interface(file_paths_cnt);
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
                //     case t_EM3000DatagramIdentifier::MRU0:
                //         [[fallthrough]];
                //     case t_EM3000DatagramIdentifier::NME0: {
                //         _navigation_interface->add_datagram_info(datagram_info);
                //         header.skip(ifs);
                //         break;
                //     }
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

        // printer.register_section("Detected Pings");
        // printer.append(_ping_interface->get_pings().__printer__(float_precision), false, '^');

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
