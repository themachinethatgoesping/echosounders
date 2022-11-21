// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

// TODO: this should be a c++20 concept
template<typename t_datagraminterface>
class I_AnnotationDataCollection : public I_FileDataCollection<t_datagraminterface>
{
    using t_base = I_FileDataCollection<t_datagraminterface>;

  public:
    I_AnnotationDataCollection(std::string_view name = "I_AnnotationDataCollection")
        : t_base(name)
    {
    }
    virtual ~I_AnnotationDataCollection() = default;

    // void init_from_file() final
    // {
    //     try
    //     {
    //         _sensor_annotation = this->read_sensor_annotation();
    //     }
    //     catch (std::exception& e)
    //     {
    //         try
    //         {
    //             std::cerr
    //                 << fmt::format(
    //                        "Warning[init_from_file]: Could not read sensor annotation from file "
    //                        "{}: {}. Using empty fallback annotation. Error was: {}",
    //                        this->get_file_nr(),
    //                        this->get_file_path(),
    //                        e.what())
    //                 << std::endl;
    //         }
    //         catch (std::exception& e2)
    //         {
    //             std::cerr << fmt::format("Warning[init_from_file]: Could not read sensor "
    //                                      "annotation nor any other information file. "
    //                                      "Error was: {}",
    //                                      e2.what())
    //                       << std::endl;
    //         }
    //         _sensor_annotation = navigation::SensorAnnotation();
    //     }
    // }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("AnnotationDataCollection");
        return printer;
    }
};
// void add_datagram(DatagramInfo_ptr<t_Datagram

template<typename t_annotationdatagraminterface>
class I_AnnotationDataInterface : public I_FileDataInterface<t_annotationdatagraminterface>
{
    using t_base = I_FileDataInterface<t_annotationdatagraminterface>;

  public:
    I_AnnotationDataInterface(std::string_view name = "I_AnnotationDataInterface")
        : t_base(name)
    {
    }
    virtual ~I_AnnotationDataInterface() = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.register_section("FileData");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("AnnotationDataInterface");

        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping