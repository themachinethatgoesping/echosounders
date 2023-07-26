// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_ping.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <set>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>
// #include "../../pingtools/pingsampleselector.hpp"
// #include "../../pingtools/pingsampleselection.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

class I_Ping
{
    std::string_view _name;
    std::string      _selected_transducer_id =
        ""; ///< In case of multi transducer ping, set the chosen transducer name here. If empty, no
            ///< transducer name was chosen yet;

  protected:
    std::string_view get_name() const { return _name; }

    std::string _channel_id;    ///< channel id of the transducer
    double      _timestamp = 0; ///< Unix timestamp in seconds (saved in UTC0)
    std::map<std::string, navigation::datastructures::GeoLocationLatLon>
        _geolocations; ///< Geolocation of the transducer with the specified transducer_id. A
                       /// Geolocation object holds lat,lon and attitude of
                       /// the transducer. If not set manually, this variable is set by calling
                       /// file.I_navigation.get_geolocation(ping.get_channel_id(),
                       /// ping.get_timestamp()).

  public:
    I_Ping(std::string_view name)
        : _name(name)
    {
    }
    virtual ~I_Ping() = default;

    //------ interface / accessors -----
    double             get_timestamp() const { return _timestamp; }
    const std::string& get_channel_id() const { return _channel_id; }
    void               set_channel_id(const std::string& channel_id) { _channel_id = channel_id; }

    virtual size_t get_file_nr() const { throw not_implemented("get_file_nr", this->get_name()); }
    virtual std::string get_file_path() const
    {
        throw not_implemented("get_file_path", this->get_name());
    }

    //----- multi transducer selection -----
    /**
     * @brief Get all registered transducer ids (in case multiple transducers are associated with a
     * single ping)
     *
     * @return std::set<std::string>
     */
    virtual std::set<std::string> get_transducer_ids() const
    {
        std::set<std::string> transducer_ids;

        /* return the keys from _geolocations */
        for (const auto& [k, v] : _geolocations)
            transducer_ids.insert(k);

        return transducer_ids;
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
        // if a transducer id was selected, use this one
        if (!_selected_transducer_id.empty())
        {
            return _selected_transducer_id;
        }

        auto transducer_ids = get_transducer_ids();
        if (transducer_ids.size() == 1)
            return *transducer_ids.begin();
        if (transducer_ids.empty())
            throw std::runtime_error("ERROR[get_transducer_id]: no transducer id registered! "
                                     "Please report, this should not happen;");

        throw std::domain_error(fmt::format(
            "ERROR[get_transducer_id]: Multi transducer configuration. You have to select one of "
            "the following transducer ids: [{}] using select_transducer_id() first.",
            get_transducer_ids_as_string()));
    }

    /**
     * @brief Select a transducer id that will be used by default when calling functions on this
     * ping. (Useful when multiple transducers are associated with a single ping.)
     *
     * @param id
     */
    void select_transducer_id(std::string id)
    {
        auto transducer_ids = get_transducer_ids();
        if (transducer_ids.contains(id))
            _selected_transducer_id = std::move(id);
        else
            throw std::domain_error(fmt::format(
                "ERROR[select_transducer_id]: Invalid transducer id. You may select one of "
                "the following ids: [{}] using select_transducer_id().",
                get_transducer_ids_as_string()));
    }

    /**
     * @brief Select a transducer id using the number (first, secpnd etc.). (Useful when multiple
     * transducers are associated with a single ping.)
     *
     * @param transducer_number: number first, second etc.
     */
    void select_transducer_id(int transducer_number)
    {
        auto transducer_ids = get_transducer_ids();

        auto pyindexer = tools::pyhelper::PyIndexer(transducer_ids.size());

        auto it = transducer_ids.begin();
        std::advance(it, pyindexer(transducer_number));

        _selected_transducer_id = *it;
    }

    void set_timestamp(double timestamp) { _timestamp = timestamp; }

    /**
     * @brief Get the geolocation of the transducer with the specified transducer_id.
     *
     * @param transducer_id: id of the transducer
     * @return const navigation::datastructures::GeoLocationLatLon&
     */
    const navigation::datastructures::GeoLocationLatLon& get_geolocation(
        const std::string& transducer_id)
    {
        return _geolocations.at(transducer_id);
    }
    /**
     * @brief Get the geolocation of the transducer. In case of multi transducer configuration, the
     * transducer that was selected with "select_transducer_id" is used.
     *
     * @return const navigation::datastructures::GeoLocationLatLon&
     */
    const navigation::datastructures::GeoLocationLatLon& get_geolocation()
    {
        return _geolocations.at(get_transducer_id());
    }

    /**
     * @brief Set the geolocation of the transducer with the specified transducer_id.
     *
     * @param transducer_id: id of the transducer
     * @return const navigation::datastructures::GeoLocationLatLon&
     */
    void set_geolocation(const std::string&                            transducer_id,
                         navigation::datastructures::GeoLocationLatLon geolocation)
    {
        _geolocations[transducer_id] = std::move(geolocation);
    }
    /**
     * @brief Set the geolocation of the transducer. In case of multi transducer configuration, the
     * transducer that was selected with "select_transducer_id" is used.
     *
     * @return const navigation::datastructures::GeoLocationLatLon&
     */
    void set_geolocation(navigation::datastructures::GeoLocationLatLon geolocation)
    {
        _geolocations[get_transducer_id()] = std::move(geolocation);
    }

    //------ interface ------//
    virtual void load_data() { throw not_implemented("load_data", this->get_name()); }
    virtual void release_data() { throw not_implemented("release_data", this->get_name()); }

    virtual size_t get_number_of_samples() const
    {
        throw not_implemented("get_number_of_samples", this->get_name());
    }

    /**
     * @brief Compute volume backscattering. If you see this comment, this function was not
     * implemented for the current ping type.
     *
     * @param dB Output Sv in dB if true, or linear if false (default).
     * @return xt::xtensor<float, 2>
     */
    virtual xt::xtensor<float, 2> get_sv([[maybe_unused]] bool dB = false)
    {
        throw not_implemented("get_sv", this->get_name());
    }

    /**
     * @brief Compute stacked volume backscattering (sum over all beams). If you see this comment,
     * this function was not implemented for the current ping type.
     *
     * @param dB Output Sv in dB if true, or linear if false (default).
     * @return xt::xtensor<float, 1>
     */
    virtual xt::xtensor<float, 1> get_sv_stacked([[maybe_unused]] bool dB = false)
    {
        throw not_implemented("get_sv_stacked", this->get_name());
    }

    /**
     * @brief Compute the launch angle of the (sinle) target within each sample. If you see this
     * comment, this function was not implemented for the current ping type.
     *
     * @return xt::xtensor<float, 2>
     */
    virtual xt::xtensor<float, 2> get_angle()
    {
        throw not_implemented("get_angle", this->get_name());
    }

    virtual bool has_angle() const { return false; }

    virtual bool has_sv() const { return false; }

    std::string feature_string(bool has_features = true) const
    {
        std::string features = "";
        if (has_sv() == has_features)
        {
            features += "sv";
        }
        if (has_angle() == has_features)
        {
            if (!features.empty())
                features += ", ";
            features += "angle";
        }

        return features;
    }

  private:
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

        printer.register_section("Ping infos");

        std::string time_str =
            tools::timeconv::unixtime_to_datestring(this->_timestamp, 2, "%d/%m/%Y %H:%M:%S");

        printer.register_string(
            "Source file", this->get_file_path(), std::to_string(this->get_file_nr()));
        printer.register_string("Channel id", this->_channel_id);
        printer.register_value("Time info", time_str, std::to_string(this->_timestamp));

        auto features     = this->feature_string();
        auto not_features = this->feature_string(false);
        if (!not_features.empty())
            printer.register_string("Features", features, std::string("Not:") + not_features);
        else
            printer.register_string("Features", features);

        if (get_transducer_ids().size() > 1)
        {
            printer.register_section("Transducer locations (multiple transducers)");
            printer.register_container("transducer_ids", get_transducer_ids());
            printer.register_string("selected_transducer_id", _selected_transducer_id);
        }
        else
        {
            printer.register_section("Transducer location");
            printer.register_string("transducer_id", get_transducer_id());
        }

        for (const auto& [k, v] : this->_geolocations)
        {
            printer.register_section(k, '^');
            printer.append(v.__printer__(float_precision));
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