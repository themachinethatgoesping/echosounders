// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_pingcommon.doc.hpp"

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

#include "../../pingtools/pingsampleselection.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

class I_PingCommon
{
    std::string _name;

  protected:
    const std::string& get_name() const { return _name; }

  public:
    I_PingCommon(std::string name)
        : _name(std::move(name))
    {
    }
    virtual ~I_PingCommon() = default;

    //----- multi transducer selection -----
    /**
     * @brief Get all registered transducer ids (in case multiple transducers are associated with a
     * single ping)
     *
     * @return std::vector<std::string>
     */
    virtual std::vector<std::string> get_transducer_ids() const
    {
        throw not_implemented(__func__, get_name());
    }

    /**
     * @brief Get all registered transducer ids (in case multiple transducers are associated with a
     * single ping) as a set (unique ids, order may be different)
     *
     * @return std::set<std::string>
     */
    virtual std::set<std::string> get_transducer_ids_as_set() const
    {
        throw not_implemented(__func__, get_name());
    }

    /**
     * @brief Get all register transducer ids as a string (useful for printing)
     *
     * @return std::string
     */
    std::string get_transducer_ids_as_string() const
    {
        std::string ids = "";
        for (const auto& id : get_transducer_ids())
            ids += id + ",";
        ids.pop_back();

        return ids;
    }

    /**
     * @brief Get the transducer id of the ping. In case multiple transducer ids are associated with
     * a single ping, this function will return the one selected with the "select_transducer_id"
     * function.
     *
     */
    std::string get_transducer_id() const
    {
        auto transducer_ids = get_transducer_ids();
        if (transducer_ids.size() == 1)
            return transducer_ids[0];
        if (transducer_ids.empty())
            throw std::runtime_error("ERROR[get_transducer_id]: no transducer id registered! "
                                     "Please report, this should not happen;");

        throw std::domain_error(fmt::format(
            "ERROR[get_transducer_id]: Multi transducer configuration. You have to select one of "
            "the following transducer ids: [{}] using select_transducer_id() first.",
            get_transducer_ids_as_string()));
    }

    virtual std::string feature_string([[maybe_unused]] bool has_features = true) const
    {
        std::string features = "";

        return features;
    }

  protected:
    struct not_implemented : public std::runtime_error
    {
        not_implemented(std::string_view method_name, std::string_view name)
            : std::runtime_error(
                  fmt::format("method {} not implemented for ping type '{}'", method_name, name))
        {
        }
    };

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        if (get_transducer_ids().size() > 1)
        {
            printer.register_section("Transducer locations (multiple transducers)");
            printer.register_container("transducer_ids", get_transducer_ids());
        }
        else
        {
            printer.register_section("Transducer location");
            printer.register_string("transducer_id", get_transducer_id());
        }


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