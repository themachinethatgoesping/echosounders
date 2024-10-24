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

#include <boost/flyweight.hpp>
#include <fmt/core.h>

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

class I_Ping : public I_PingCommon
{
    bool _sensor_configuration_set = false;
    bool _sensor_data_latlon_set   = false;

  public:
    using t_base = I_PingCommon;

  protected:
    std::string class_name() const override { return "I_Ping"; }

  public:
    boost::flyweights::flyweight<std::string> _channel_id; ///< channel id of the transducer
    double _timestamp = 0; ///< Unix timestamp in seconds (saved in UTC0)
    boost::flyweights::flyweight<navigation::SensorConfiguration> _sensor_configuration;
    navigation::datastructures::SensordataLatLon                  _sensor_data_latlon;

    std::map<t_pingfeature, std::function<bool()>> primary_feature_functions() const override
    {
        auto features = t_base ::primary_feature_functions();

        features[t_pingfeature::timestamp] = std::bind(&I_Ping::has_timestamp, this);
        // datetime is a timestamp alias that only exists in the python module (implemented as
        // lamda)
        features[t_pingfeature::datetime]   = std::bind(&I_Ping::has_timestamp, this);
        features[t_pingfeature::channel_id] = std::bind(&I_Ping::has_channel_id, this);
        features[t_pingfeature::sensor_configuration] =
            std::bind(&I_Ping::has_sensor_configuration, this);
        features[t_pingfeature::sensor_data_latlon] =
            std::bind(&I_Ping::has_sensor_data_latlon, this);
        features[t_pingfeature::geolocation] = std::bind(&I_Ping::has_geolocation, this);

        return features;
    }
    std::map<t_pingfeature, std::function<bool()>> secondary_feature_functions() const
    {
        return t_base ::secondary_feature_functions();
    }
    std::map<t_pingfeature, std::function<bool()>> feature_group_functions() const
    {
        auto features                        = t_base ::feature_group_functions();
        features[t_pingfeature::bottom]      = std::bind(&I_Ping::has_bottom, this);
        features[t_pingfeature::watercolumn] = std::bind(&I_Ping::has_watercolumn, this);
        return features;
    }

  public:
    I_Ping()          = default;
    virtual ~I_Ping() = default;

    //------ features -----
    bool   has_timestamp() const { return _timestamp > 0; }
    void   set_timestamp(double timestamp) { _timestamp = timestamp; }
    double get_timestamp() const { return _timestamp; }

    bool               has_channel_id() const { return !_channel_id.get().empty(); }
    const std::string& get_channel_id() const { return _channel_id.get(); }
    void               set_channel_id(const std::string& channel_id) { _channel_id = channel_id; }

    bool has_geolocation() const { return has_sensor_configuration() && has_sensor_data_latlon(); }
    navigation::datastructures::GeolocationLatLon get_geolocation(
        const std::string& target_id = "Transducer") const
    {
        return get_sensor_configuration().compute_target_position(target_id,
                                                                  get_sensor_data_latlon());
    }
    void set_geolocation(const navigation::datastructures::GeolocationLatLon& location)
    {
        // create a new sensor configuration assuming no offsets between sensor data and transducer
        navigation::SensorConfiguration config;
        config.add_target("Transducer", 0.f, 0.f, 0.f, 0.f, 0.f, 0.f);
        this->set_sensor_configuration(config);

        // set sensor data
        this->set_sensor_data_latlon(
            navigation::datastructures::SensordataLatLon(location.latitude,
                                                         location.longitude,
                                                         location.z,
                                                         0.f,
                                                         location.yaw,
                                                         location.pitch,
                                                         location.roll));
    }

    const navigation::SensorConfiguration& get_sensor_configuration() const
    {
        return _sensor_configuration.get();
    }

    /**
     * @brief Returns the hash of the base sensor configuraiton. 
     * This is the sensor configuration with the "Transducer" target removed.
     * This hash can be used to get the correct navigation interpolator from the navigation_data_interface
     * Note: This function is for testing and finding errors. It is rather slow.
     * 
     * @return uint64_t 
     */
    uint64_t get_sensor_configuration_base_hash() const
    {
        auto sc = get_sensor_configuration();
        sc.remove_target("Transducer");
        return sc.binary_hash();
    } 

    bool has_sensor_configuration() const { return _sensor_configuration_set; }
    void set_sensor_configuration(const navigation::SensorConfiguration& sensor_configuration)
    {
        _sensor_configuration     = sensor_configuration;
        _sensor_configuration_set = true;
    }
    void set_sensor_configuration_flyweight(
        boost::flyweight<navigation::SensorConfiguration> sensor_configuration)
    {
        _sensor_configuration     = std::move(sensor_configuration); // avoid reference counting
        _sensor_configuration_set = true;
    }

    bool has_sensor_data_latlon() const { return _sensor_data_latlon_set; }
    const navigation::datastructures::SensordataLatLon& get_sensor_data_latlon() const
    {
        return _sensor_data_latlon;
    }

    void set_sensor_data_latlon(const navigation::datastructures::SensordataLatLon& sensor_data)
    {
        _sensor_data_latlon_set = true;
        _sensor_data_latlon     = sensor_data;
    }

    void load(bool force = false) override
    {
        if (has_bottom())
            bottom().load(force);
        if (has_watercolumn())
            watercolumn().load(force);
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

    // ----- ping interface -----
    virtual I_PingBottom& bottom() { throw not_implemented("bottom", this->class_name()); }
    const I_PingBottom&   bottom() const { return const_cast<I_Ping*>(this)->bottom(); }

    virtual I_PingWatercolumn& watercolumn()
    {
        throw not_implemented("watercolumn", this->class_name());
    }
    const I_PingWatercolumn& watercolumn() const
    {
        return const_cast<I_Ping*>(this)->watercolumn();
    }

    virtual bool has_bottom() const
    {
        try
        {
            return bottom().has_primary_features();
        }
        catch (const not_implemented& e)
        {
            return false;
        }
    }
    virtual bool has_watercolumn() const
    {
        try
        {
            return watercolumn().has_primary_features();
        }
        catch (const not_implemented& e)
        {
            return false;
        }
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
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.register_section("Ping infos");

        std::string time_str =
            tools::timeconv::unixtime_to_datestring(this->_timestamp, 2, "%d/%m/%Y %H:%M:%S");

        printer.register_string("Channel id", this->get_channel_id());
        printer.register_value("Time info", time_str, std::to_string(this->_timestamp));

        // print features
        printer.append(t_base::__printer__(float_precision, superscript_exponents));
        if (has_bottom())
            bottom().print_features(printer, "bottom");
        if (has_watercolumn())
            watercolumn().print_features(printer, "watercolumn");

        if (has_geolocation())
        {
            printer.register_section("Geolocation");
            printer.append(
                get_geolocation("Transducer").__printer__(float_precision, superscript_exponents));
        }
        else
        {
            printer.register_string(
                "Geolocation",
                "not available",
                fmt::format("Sensor configuration: {}, Sensor data: {}",
                            has_sensor_configuration() ? "available" : "not available",
                            has_sensor_data_latlon() ? "available" : "not available"));
        }

        // printer.register_section("Sensor data");
        // printer.append(_sensor_data_latlon.__printer__(float_precision, superscript_exponents));

        // printer.register_section("Sensor configuration");
        // printer.append(get_sensor_configuration().__printer__(float_precision,
        // superscript_exponents));

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