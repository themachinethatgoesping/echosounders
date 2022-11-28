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
namespace filetemplates {
namespace datainterfaces {

// TODO: this should be a c++20 concept
template<typename t_datagraminterface>
class I_AnnotationPerFileDataInterface : public I_PerFileDataInterface<t_datagraminterface>
{
    using t_base = I_PerFileDataInterface<t_datagraminterface>;

  public:
    I_AnnotationPerFileDataInterface(std::string_view name = "I_AnnotationPerFileDataInterface")
        : t_base(name)
    {
    }
    virtual ~I_AnnotationPerFileDataInterface() = default;

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

        printer.register_section("AnnotationPerFileDataInterface");
        return printer;
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping