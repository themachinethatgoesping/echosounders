// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_pingwatercolumn.doc.hpp"

/* generated doc strings */
#include ".docstrings/i_pingwatercolumn.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/hashhelper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../pingtools/beamsampleselection.hpp"
#include "i_pingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

/**
 * @brief Interface for all ping watercolumn functions
 *
 */
class I_PingWatercolumn : virtual public I_PingCommon
{
  public:
    using t_base = I_PingCommon;

    I_PingWatercolumn()
        : I_PingCommon("I_PingWatercolumn")
    {
    }
    virtual ~I_PingWatercolumn() = default;

    //------ interface / accessors -----
    /**
     * @brief Get tha raw water amplitude data converted to float(32bit)
     *
     * @return xt::xtensor<float,2>
     */
    virtual xt::xarray<float> get_amplitudes() const
    {
        throw not_implemented(__func__, get_name());
    }

    /**
     * @brief Get tha raw water amplitude data converted to float(32bit)
     *
     * @param selection Selection of Beams and Samples to extract
     * @return xt::xtensor<float,2>
     */
    virtual xt::xarray<float> get_amplitudes(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection) const
    {
        throw not_implemented(__func__, this->get_name());
    }

    /**
     * @brief Check this pings supports AMPLITUDES data
     *
     * @return true
     * @return false
     */
    virtual bool has_amplitudes() const { return false; }

    std::string feature_string(bool has_features = true) const override
    {
        std::string features = "";
        if (has_amplitudes() == has_features)
        {
            features += "amplitudes";
        }

        return features;
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // Transducers
        printer.append(I_PingCommon::__printer__(float_precision));

        printer.register_section("Watercolumn detection infos");
        auto features     = this->feature_string();
        auto not_features = this->feature_string(false);
        if (!not_features.empty())
            printer.register_string("Features", features, std::string("Not:") + not_features);
        else
            printer.register_string("Features", features);

        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping