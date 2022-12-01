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
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

class I_Ping
{
    std::string_view _name;

  protected:
    std::string_view get_name() const { return _name; }

    std::string _channel_id; ///< channel id of the transducer
    double      _timestamp;  ///< Unix timestamp in seconds (saved in UTC0)
    navigation::datastructures::GeoLocationLatLon
        _geolocation; ///< Geolocation of the transducer (object that hold lat,lon and attitude of
                      /// the transducer). If not set manually, this variable is set by calling
                      /// file.I_navigation.get_geolocation(ping.get_channel_id(),
                      /// ping.get_timestamp()).

  public:
    I_Ping(std::string_view name)
        : _name(name)
    {
    }
    virtual ~I_Ping() = default;

    //------ interface / accessors -----
    const std::string& get_channel_id() const { return _channel_id; }
    double             get_timestamp() const { return _timestamp; }
    void               set_channel_id(const std::string& channel_id) { _channel_id = channel_id; }
    void               set_timestamp(double timestamp) { _timestamp = timestamp; }
    const navigation::datastructures::GeoLocationLatLon& get_geolocation() { return _geolocation; }

    void set_geolocation(navigation::datastructures::GeoLocationLatLon geolocation)
    {
        _geolocation = std::move(geolocation);
    }

    virtual size_t get_file_nr() const { throw not_implemented("get_file_nr", this->get_name()); }
    virtual std::string get_file_path() const
    {
        throw not_implemented("get_file_path", this->get_name());
    }

    //------ interface ------//
    virtual void load_data() { throw not_implemented("load_data", this->get_name()); }
    virtual void release_data() { throw not_implemented("release_data", this->get_name()); }

    virtual size_t get_number_of_samples() const
    {
        throw not_implemented("get_number_of_samples", this->get_name());
    }

    virtual xt::xtensor<float, 2> get_sv([[maybe_unused]] bool dB = false)
    {
        throw not_implemented("get_sv", this->get_name());
    }
    virtual xt::xtensor<float, 1> get_sv_stacked([[maybe_unused]] bool dB = false)
    {
        throw not_implemented("get_sv_stacked", this->get_name());
    }

    virtual xt::xtensor<float, 2> get_angle()
    {
        throw not_implemented("get_angle", this->get_name());
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
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping