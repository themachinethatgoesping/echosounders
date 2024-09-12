// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/sbesamplitudecalibration.doc.hpp"

/* generated doc strings */
#include ".docstrings/datagraminfo.doc.hpp"

#include <fstream>
#include <limits>
#include <memory>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

class SBESAmplitudeCalibration
{
  protected:
    float _calibration_sp = std::numeric_limits<float>::quiet_NaN; // absolute calibration offset
                                                                   // towards point scattering
    float _calibration_sv = std::numeric_limits<float>::quiet_NaN; // absolute calibration offset
                                                                   // towards volume scattering
    float _calibration_sp_db =
        std::numeric_limits<float>::quiet_NaN; // absolute calibration offset
                                               // towards point scattering in dB
    float _calibration_sv_db =
        std::numeric_limits<float>::quiet_NaN; // absolute calibration offset
                                               // towards volume scattering in dB

  public:
    SBESAmplitudeCalibration() = default;

    SBESAmplitudeCalibration(float calibration_sp, float calibration_sv, bool in_db = false)
    {
        set_calibration_sp(calibration_sp, in_db);
        set_calibration_sv(calibration_sv, in_db);
    }

    virtual ~SBESAmplitudeCalibration() = default;

    bool operator==(const t_base&) const = default;

    // ----- getters -----
    float get_calibration_sp() const { return _calibration_sp; }
    float get_calibration_sp_db() const { return _calibration_sp_db; }
    float get_calibration_sv() const { return _calibration_sv; }
    float get_calibration_sv_db() const { return _calibration_sv_db; }

    // ----- setters -----
    void set_calibration_sp(float calibration_sp, bool in_db = false)
    {
        if (in_db)
        {
            _calibration_sp_db = calibration_sp;
            _calibration_sp    = std::pow(10, calibration_sp / 10);
        }
        else
        {
            _calibration_sp    = calibration_sp;
            _calibration_sp_db = 10 * std::log10(calibration_sp);
        }
    }

    void set_calibration_sv(float calibration_sv, bool in_db = false)
    {
        if (in_db)
        {
            _calibration_sv_db = calibration_sv;
            _calibration_sv    = std::pow(10, calibration_sv / 10);
        }
        else
        {
            _calibration_sv    = calibration_sv;
            _calibration_sv_db = 10 * std::log10(calibration_sv);
        }
    }

    // ----- to/from stream interface -----
    static SBESAmplitudeCalibration<t_DatagramIdentifier> from_stream(std::istream& is)
    {
        SBESAmplitudeCalibration data;
        is.read(reinterpret_cast<char*>(&data._calibration_sp), sizeof(float) * 4);

        return data;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&_calibration_sp), sizeof(float) * 4);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("SBESAmplitudeCalibration", float_precision);

        // raw values
        printer.register_value("Calibration offset towards Sp:", _calibration_sp_db, '[dB]');
        printer.register_value("Calibration offset towards Sv:", _calibration_sv_db, '[dB]');

        return printer;
    }

    // hash
    xxh::hash_t<64> binary_hash()
    {
        xxh::hash3_state_t<64>               hash;
        boost::iostreams::stream<XXHashSink> stream(hash);
        //only hashing the db values
        stream.write(reinterpret_cast<const char*>(&_calibration_sp_db), sizeof(float) * 2);
        stream.flush();
        return hash.digest();
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NO_HASH__(SBESAmplitudeCalibration)
};

// boost hash

/**
 * @brief Boost hash function for SBESAmplitudeCalibration
 *
 * @return std::size_t
 */
std::size_t hash_value(const SBESAmplitudeCalibration& data)
{
    return data.binary_hash();
}

}
}
}
}
