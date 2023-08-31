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

#include "i_pingbottom.hpp"
#include "i_pingcommon.hpp"
#include "i_pingwatercolumn.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

class I_Ping : virtual public I_PingCommon
{
  protected:
    std::string _channel_id;    ///< channel id of the transducer
    double      _timestamp = 0; ///< Unix timestamp in seconds (saved in UTC0)
    navigation::datastructures::GeoLocationLatLon
        _geolocation; ///< Geolocation of the transducer. A
                      /// Geolocation object holds lat,lon and attitude of
                      /// the transducer. If not set manually, this variable is set by calling
                      /// file.I_navigation.get_geolocation(ping.get_channel_id(),
                      /// ping.get_timestamp()).

  public:
    using t_base = I_PingCommon;
    using t_base::register_feature;

    I_Ping()
        : I_PingCommon("I_Ping")
    {
        register_feature("bottom", [this]() { return this->has_bottom(); });
        register_feature("watercolumn", [this]() { return this->has_watercolumn(); });
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

    void set_timestamp(double timestamp) { _timestamp = timestamp; }

    /**
     * @brief Get the geolocation of the transducer.
     *
     * @return const navigation::datastructures::GeoLocationLatLon&
     */
    const navigation::datastructures::GeoLocationLatLon& get_geolocation() const
    {
        return _geolocation;
    }

    /**
     * @brief Set the geolocation of the transducer.
     */
    void set_geolocation(navigation::datastructures::GeoLocationLatLon geolocation)
    {
        _geolocation = std::move(geolocation);
    }

    void load() override
    {
        if (has_bottom())
            bottom().load();
        if (has_watercolumn())
            watercolumn().load();
    }
    void release() override
    {
        if (has_bottom())
            bottom().release();
        if (has_watercolumn())
            watercolumn().release();
    }
    bool loaded() override
    {
        if (has_bottom() && !bottom().loaded())
            return false;
        if (has_watercolumn() && !watercolumn().loaded())
            return false;
        return true;
    }

    /**
     * @brief Get the number of beams
     *
     * @return size_t
     */
    virtual size_t get_number_of_beams() const
    {
        throw not_implemented("get_number_of_beams", this->get_name());
    }

    /**
     * @brief Get the number of beams when specifying the beams and samples to select.
     * Note: this function just returns selection.get_number_of_beams()
     *
     * @param selection: Structure containing information about which beams and samples to select.
     * @return size_t
     */
    size_t get_number_of_beams(const pingtools::BeamSampleSelection& selection) const
    {
        return selection.get_number_of_beams();
    }

    /**
     * @brief Get the beam pointing angles in °.
     *
     * @return xt::xtensor<float, 1> in °
     */
    virtual xt::xtensor<float, 1> get_beam_pointing_angles() const
    {
        throw not_implemented("get_beam_pointing_angles", this->get_name());
    }

    /**
     * @brief Get the beam pointing angles in ° when specifying the beams and samples to select.
     *
     * @param selection: Structure containing information about which beams and samples to select.
     * @return xt::xtensor<float, 1> in °
     */
    virtual xt::xtensor<float, 1> get_beam_pointing_angles(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection) const
    {
        throw not_implemented("get_beam_pointing_angles(BeamSampleSelection)", this->get_name());
    }

    /**
     * @brief Get the number of samples per beam
     *
     * @return xt::xtensor<uint16_t, 1>
     */
    virtual xt::xtensor<uint16_t, 1> get_number_of_samples_per_beam() const
    {
        throw not_implemented("get_number_of_samples_per_beam", this->get_name());
    }

    /**
     * @brief Get the number of samples per beam when specifying the beams and samples to select.
     * Note: this function just returns an array of selection.get_number_of_samples_ensemble()
     *
     * @param selection: Structure containing information about which beams and samples to select.
     * @return xt::xtensor<uint16_t, 1>
     */
    xt::xtensor<uint16_t, 1> get_number_of_samples_per_beam(
        [[maybe_unused]] const pingtools::BeamSampleSelection& selection) const
    {
        auto number_of_samples_per_beam =
            xt::xtensor<uint16_t, 1>::from_shape({ selection.get_number_of_beams() });

        number_of_samples_per_beam.fill(selection.get_number_of_samples_ensemble());

        return number_of_samples_per_beam;
    }

    virtual I_PingBottom& bottom() { throw not_implemented("bottom", this->get_name()); }
    const I_PingBottom&   bottom() const { return const_cast<I_Ping*>(this)->bottom(); }

    virtual I_PingWatercolumn& watercolumn()
    {
        throw not_implemented("watercolumn", this->get_name());
    }
    const I_PingWatercolumn& watercolumn() const
    {
        return const_cast<I_Ping*>(this)->watercolumn();
    }

    virtual bool has_bottom() const { return false; }
    virtual bool has_watercolumn() const { return false; }

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

        printer.register_section("Ping infos");

        std::string time_str =
            tools::timeconv::unixtime_to_datestring(this->_timestamp, 2, "%d/%m/%Y %H:%M:%S");

        printer.register_string(
            "Source file", this->get_file_path(), std::to_string(this->get_file_nr()));
        printer.register_string("Channel id", this->_channel_id);
        printer.register_value("Time info", time_str, std::to_string(this->_timestamp));

        // print features
        printer.append(t_base::__printer__(float_precision));
        // if (has_bottom())
        //     bottom().print_features(printer);
        // if (has_watercolumn())
        //     watercolumn().print_features(printer);

        printer.register_section("Geolocation");
        printer.append(_geolocation.__printer__(float_precision));

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