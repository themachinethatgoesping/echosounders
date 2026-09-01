// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kfilehandler.doc.hpp"

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "datagrams.hpp"
#include "types.hpp"

#include "../filetemplates/i_inputfilehandler.hpp"

#include "filedatainterfaces/s7kdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {

/**
 * @brief File handler for Teledyne RESON .s7k (7k) data files.
 *
 * Indexes all datagrams (Data Record Frames) in the given file(s) and provides access to the
 * raw datagrams via the datagram_interface().
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

    using typename t_base::FileInfos;
    using typename t_base::FilePackageIndex;

  public:
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
        // no additional interfaces yet (step 1: datagram indexing only)
    }

    using t_base::init_interfaces;
    void init_interfaces([[maybe_unused]] bool                                force,
                         [[maybe_unused]] tools::progressbars::I_ProgressBar& progress_bar,
                         [[maybe_unused]] int mp_cores = 1) final
    {
        // no additional interfaces to initialize yet (step 1: datagram indexing only)
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
