#include "FIL1.hpp"

// std
#include <algorithm>
#include <sstream>

// deps
#include <fmt/format.h>
#include <xtensor/io/xio.hpp>
#include <xtensor/views/xview.hpp>

// project
#include <themachinethatgoesping/tools/helper/approx.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

// ----- constructors -----
FIL1::FIL1(SimradRawDatagram header)
    : SimradRawDatagram(std::move(header))
{
}

FIL1::FIL1()
    : SimradRawDatagram(148, simradraw_long(t_SimradRawDatagramIdentifier::FIL1))
{
    _channel_id.fill('\x00');
}

// ----- operators -----
bool FIL1::operator==(const FIL1& other) const
{
    using namespace tools::helper; // approx and approx_container

    return SimradRawDatagram::operator==(other) && _stage == other._stage &&
           _spare_1 == other._spare_1 && _spare_2 == other._spare_2 &&
           _channel_id == other._channel_id && _no_of_coefficients == other._no_of_coefficients &&
           _decimation_factor == other._decimation_factor &&
           approx_container_complex(xt::flatten(_coefficients), xt::flatten(other._coefficients));
}

// ----- getters -----
std::string_view FIL1::get_channel_id_stripped() const
{
    auto channel_id = get_channel_id();
    return channel_id.substr(0, channel_id.find('\x00'));
}

// ----- setters -----
void FIL1::set_channel_id(std::string_view channel_id)
{
    if (channel_id.size() > 128)
        throw std::runtime_error("channel_id too long");

    std::copy(channel_id.begin(), channel_id.end(), _channel_id.begin());
    // fill _channel_id with \x00
    std::fill(_channel_id.begin() + channel_id.size(), _channel_id.end(), '\x00');
}

void FIL1::set_no_of_coefficients(simradraw_short no_of_coefficients)
{
    _no_of_coefficients = no_of_coefficients;
}

void FIL1::set_decimation_factor(simradraw_short decimation_factor)
{
    _decimation_factor = decimation_factor;
}

void FIL1::set_coefficients(xt::xtensor<std::complex<simradraw_float>, 1> coefficients)
{
    _coefficients       = std::move(coefficients);
    _no_of_coefficients = simradraw_short(_coefficients.size());
    _length = simradraw_long(148 + _no_of_coefficients * sizeof(std::complex<simradraw_float>));
}

// ----- file I/O -----
FIL1 FIL1::from_stream(std::istream& is, SimradRawDatagram header)
{
    FIL1 datagram(std::move(header));

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

    using xt_shape         = xt::xtensor<std::complex<simradraw_float>, 1>::shape_type;
    datagram._coefficients = xt::empty<std::complex<simradraw_float>>(
        xt_shape({ size_t(datagram._no_of_coefficients) }));

    is.read(reinterpret_cast<char*>(datagram._coefficients.data()),
            datagram._coefficients.size() * sizeof(std::complex<simradraw_float>));

    // verify the datagram is read correctly by reading the length field at the end
    datagram._verify_datagram_end(is);

    return datagram;
}

FIL1 FIL1::from_stream(std::istream& is)
{
    return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::FIL1));
}

FIL1 FIL1::from_stream(std::istream& is, t_SimradRawDatagramIdentifier type)
{
    if (type != t_SimradRawDatagramIdentifier::FIL1)
        throw std::runtime_error("FIL1::from_stream: wrong datagram type");

    return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::FIL1));
}

void FIL1::to_stream(std::ostream& os) const
{
    if (simradraw_long(_coefficients.size()) != _no_of_coefficients)
        throw std::runtime_error(fmt::format("FIL1: coefficients size mismatch ({} vs {})",
                                             _coefficients.size(),
                                             _no_of_coefficients));

    if (_length !=
        simradraw_long(_coefficients.size() * sizeof(std::complex<simradraw_float>) + 148))
        throw std::runtime_error(fmt::format(
            "FIL1: length mismatch ({} vs {})",
            _length,
            simradraw_long(_coefficients.size() * sizeof(std::complex<simradraw_float>) + 148)));

    if (_datagram_type != simradraw_long(t_SimradRawDatagramIdentifier::FIL1))
        throw std::runtime_error(fmt::format("FIL1: datagram type mismatch ({} vs {})",
                                             _datagram_type,
                                             simradraw_long(t_SimradRawDatagramIdentifier::FIL1)));

    SimradRawDatagram::to_stream(os);

    os.write(reinterpret_cast<const char*>(&_stage), sizeof(_stage));
    os.write(reinterpret_cast<const char*>(&_spare_1), sizeof(_spare_1));
    os.write(reinterpret_cast<const char*>(&_spare_2), sizeof(_spare_2));
    os.write(_channel_id.data(), _channel_id.size());
    os.write(reinterpret_cast<const char*>(&_no_of_coefficients), sizeof(_no_of_coefficients));
    os.write(reinterpret_cast<const char*>(&_decimation_factor), sizeof(_decimation_factor));
    os.write(reinterpret_cast<const char*>(_coefficients.data()),
             _coefficients.size() * sizeof(std::complex<simradraw_float>));
    os.write(reinterpret_cast<const char*>(&_length), sizeof(_length));
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter FIL1::__printer__(unsigned int float_precision,
                                                    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "Filter binary datagram (FIL1)", float_precision, superscript_exponents);

    printer.append(SimradRawDatagram::__printer__(float_precision, superscript_exponents));

    printer.register_section("Filter datagram content");
    printer.register_value("stage", _stage);
    printer.register_value("spare_1", _spare_1);
    printer.register_value("spare_2", _spare_2);
    printer.register_string("channel_id", std::string(get_channel_id_stripped()));
    printer.register_value("no_of_coefficients", _no_of_coefficients);
    printer.register_value("decimation_factor", _decimation_factor);

    printer.register_section("Filter coefficients");
    std::stringstream ss;
    ss << _coefficients;
    printer.register_string("coefficients", ss.str());

    return printer;
}

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping