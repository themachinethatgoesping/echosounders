// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/FIL1.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>

#include <xtensor/io/xio.hpp>
#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper/approx.hpp>



#include "../types.hpp"
#include "simradrawdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

/**
 * @brief Filter binary datagram (FIL1)
 * This datagram contains filter coefficients used by the EK80 to filter the received signal.
 *
 */
class FIL1 : public SimradRawDatagram
{
    // ----- datagram content -----
    simradraw_short _stage   = '\x00';        ///< Filter stage number
    simradraw_char  _spare_1 = '\x00';        ///< For future expansions
    simradraw_char  _spare_2 = '\x00';        ///< For future expansions
    std::string  _channel_id;              ///< Channel identification (size is always 128)
    simradraw_short _no_of_coefficients = 0;  ///< Number of complex filter coefficients
    simradraw_short _decimation_factor  = -1; ///< Filter decimation factor

    xt::xtensor<simradraw_float, 2> _coefficients; ///< Filter coefficients, ...)

  private:
    // ----- public constructors -----
    explicit FIL1(SimradRawDatagram header)
        : SimradRawDatagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    FIL1()
        : SimradRawDatagram(148, simradraw_long(t_SimradRawDatagramIdentifier::FIL1))
    {
    }
    ~FIL1() = default;

    // ----- operators -----
    bool operator==(const FIL1& other) const
    {
        using namespace tools::helper; // approx and approx_container

        return SimradRawDatagram::operator==(other) && _stage == other._stage &&
               _spare_1 == other._spare_1 && _spare_2 == other._spare_2 &&
               _channel_id == other._channel_id &&
               _no_of_coefficients == other._no_of_coefficients &&
               _decimation_factor == other._decimation_factor &&
               approx_container(xt::flatten(_coefficients), xt::flatten(other._coefficients));
    }
    bool operator!=(const FIL1& other) const { return !operator==(other); }

    // ----- getter setter -----
    simradraw_short get_stage() const { return _stage; }
    simradraw_char  get_spare_1() const { return _spare_1; }
    simradraw_char  get_spare_2() const { return _spare_2; }
    std::string  get_channel_id() const { return _channel_id; }
    simradraw_short get_no_of_coefficients() const { return _no_of_coefficients; }
    simradraw_short get_decimation_factor() const { return _decimation_factor; }
    const xt::xtensor<simradraw_float, 2>& get_coefficients() const { return _coefficients; }

    void set_stage(simradraw_short stage) { _stage = stage; }
    void set_spare_1(simradraw_char spare_1) { _spare_1 = spare_1; }
    void set_spare_2(simradraw_char spare_2) { _spare_2 = spare_2; }
    void set_channel_id(std::string channel_id) { _channel_id = std::move(channel_id); }
    void set_no_of_coefficients(simradraw_short no_of_coefficients)
    {
        _no_of_coefficients = no_of_coefficients;
    }
    void set_decimation_factor(simradraw_short decimation_factor)
    {
        _decimation_factor = decimation_factor;
    }
    void set_coefficients(xt::xtensor<simradraw_float, 2> coefficients)
    {
        _coefficients = std::move(coefficients);
    }

    // ----- file I/O -----
    static FIL1 from_stream(std::istream& is, SimradRawDatagram header)
    {
        FIL1 datagram(std::move(header));
        datagram._channel_id.resize(128);

        is.read(reinterpret_cast<char*>(&datagram._stage), sizeof(datagram._stage));
        is.read(reinterpret_cast<char*>(&datagram._spare_1), sizeof(datagram._spare_1));
        is.read(reinterpret_cast<char*>(&datagram._spare_2), sizeof(datagram._spare_2));
        is.read(datagram._channel_id.data(), datagram._channel_id.size());
        is.read(reinterpret_cast<char*>(&datagram._no_of_coefficients),
                sizeof(datagram._no_of_coefficients));
        is.read(reinterpret_cast<char*>(&datagram._decimation_factor),
                sizeof(datagram._decimation_factor));

        int size = datagram._no_of_coefficients * sizeof(simradraw_float) * 2;
        if (size + 148 != datagram._length)
            throw std::runtime_error(
                fmt::format("FIL1: size mismatch (NoOfCoefficients {}/{} vs datagram Length {})",
                            datagram._no_of_coefficients,
                            size,
                            datagram._length));

        using xt_shape = xt::xtensor<simradraw_float, 2>::shape_type;
        datagram._coefficients =
            xt::empty<simradraw_float>(xt_shape({ size_t(datagram._no_of_coefficients), 2 }));

        is.read(reinterpret_cast<char*>(datagram._coefficients.data()),
                datagram._coefficients.size() * sizeof(simradraw_float));

        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);

        return datagram;
    }

    static FIL1 from_stream(std::istream& is)
    {
        return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::FIL1));
    }

    static FIL1 from_stream(std::istream& is, t_SimradRawDatagramIdentifier type)
    {
        if (type != t_SimradRawDatagramIdentifier::FIL1)
            throw std::runtime_error("FIL1::from_stream: wrong datagram type");

        return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::FIL1));
    }

    void to_stream(std::ostream& os)
    {
        _no_of_coefficients = simradraw_short(_coefficients.size() / 2);

        _length        = simradraw_long(_coefficients.size() * sizeof(simradraw_float) + 148);
        _datagram_type = simradraw_long(t_SimradRawDatagramIdentifier::FIL1);
        _channel_id.resize(128, '\x00');

        SimradRawDatagram::to_stream(os);

        os.write(reinterpret_cast<char*>(&_stage), sizeof(_stage));
        os.write(reinterpret_cast<char*>(&_spare_1), sizeof(_spare_1));
        os.write(reinterpret_cast<char*>(&_spare_2), sizeof(_spare_2));
        os.write(_channel_id.data(), _channel_id.size());
        os.write(reinterpret_cast<char*>(&_no_of_coefficients), sizeof(_no_of_coefficients));
        os.write(reinterpret_cast<char*>(&_decimation_factor), sizeof(_decimation_factor));
        os.write(reinterpret_cast<char*>(_coefficients.data()),
                 _coefficients.size() * sizeof(simradraw_float));
        os.write(reinterpret_cast<char*>(&_length), sizeof(_length));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("Filter binary datagram (FIL1)", float_precision, superscript_exponents);

        printer.append(SimradRawDatagram::__printer__(float_precision, superscript_exponents));

        std::string channel_id = _channel_id;
        // remove all non ascii characters
        channel_id.erase(std::remove_if(channel_id.begin(),
                                        channel_id.end(),
                                        [](char c) { return !std::isprint(c); }),
                         channel_id.end());
        // remove all white spaces
        channel_id.erase(std::remove_if(channel_id.begin(),
                                        channel_id.end(),
                                        [](char c) { return std::isspace(c); }),
                         channel_id.end());

        printer.register_section("Filter datagram content");
        printer.register_value("stage", _stage);
        printer.register_value("spare_1", _spare_1);
        printer.register_value("spare_2", _spare_2);
        printer.register_string("channel_id", channel_id);
        printer.register_value("no_of_coefficients", _no_of_coefficients);
        printer.register_value("decimation_factor", _decimation_factor);

        printer.register_section("Filter coefficients");
        std::stringstream ss;
        ss << _coefficients;
        printer.register_string("coefficients", ss.str());

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(FIL1)
};

}
}
}
}