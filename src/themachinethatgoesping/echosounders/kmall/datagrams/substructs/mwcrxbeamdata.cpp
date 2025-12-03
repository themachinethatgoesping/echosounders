// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mwcrxbeamdata.hpp"
#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

xt::xtensor<int8_t, 1> MWCRxBeamData::read_sample_amplitudes_05dB(std::istream& ifs) const
{
    auto samples = xt::empty<int8_t>(xt::xtensor<int8_t, 1>::shape_type({ _number_of_samples }));

    ifs.seekg(get_sample_position());
    ifs.read(reinterpret_cast<char*>(samples.data()),
             static_cast<std::streamsize>(_number_of_samples * sizeof(int8_t)));

    return samples;
}

xt::xtensor<int8_t, 1> MWCRxBeamData::read_sample_amplitudes_05dB(
    std::istream& ifs,
    size_t        pos_first_sample,
    size_t        first_sample,
    size_t        number_of_samples,
    size_t        number_of_samples_in_datagram)
{
    auto samples = xt::xtensor<int8_t, 1>::from_shape({ number_of_samples });

    if (first_sample + number_of_samples > number_of_samples_in_datagram)
        throw std::range_error(
            fmt::format("ERROR[MWCRxBeamData::read_samples]: The requested number of "
                        "samples [{} + {} ] exceeds the number of samples in the datagram [{}]!",
                        first_sample,
                        number_of_samples,
                        number_of_samples_in_datagram));

    ifs.seekg(pos_first_sample + static_cast<std::streamoff>(first_sample * sizeof(int8_t)));
    ifs.read(reinterpret_cast<char*>(samples.data()),
             static_cast<std::streamsize>(number_of_samples * sizeof(int8_t)));

    return samples;
}

xt::xtensor<int8_t, 1>& MWCRxBeamData::sample_amplitudes_05dB()
{
    return _sample_amplitudes_05dB.value();
}

xt::xtensor<float, 1> MWCRxBeamData::get_sample_amplitudes_in_db(float db_offset) const
{
    if (get_samples_are_skipped())
        throw std::runtime_error(
            fmt::format("ERROR[MWCRxBeamData::get_samples]: The data is not available "
                        "because it was skipped! Call load or set_data first."));

    return xt::xtensor<float, 1>(xt::eval(_sample_amplitudes_05dB.value() * 0.5f - db_offset));
}

MWCRxBeamData MWCRxBeamData::from_stream(std::istream& is, bool skip_data)
{
    MWCRxBeamData data;

    is.read(reinterpret_cast<char*>(&data._beam_pointing_angle_re_vertical_deg),
            16 * sizeof(uint8_t));

    data._sample_pos = static_cast<size_t>(is.tellg());

    if (skip_data)
    {
        data._sample_amplitudes_05dB = std::nullopt;
        data._rx_beam_phase          = std::nullopt;
        is.seekg(static_cast<std::streamoff>(data._number_of_samples * sizeof(int8_t)),
                 std::ios_base::cur);
    }
    else
    {
        data._sample_amplitudes_05dB =
            xt::empty<int8_t>(xt::xtensor<int8_t, 1>::shape_type({ data._number_of_samples }));
        is.read(reinterpret_cast<char*>(data._sample_amplitudes_05dB.value().data()),
                static_cast<std::streamsize>(data._number_of_samples * sizeof(int8_t)));
    }

    return data;
}

void MWCRxBeamData::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(&_beam_pointing_angle_re_vertical_deg),
             16 * sizeof(uint8_t));

    if (!get_samples_are_skipped())
    {
        if (_sample_amplitudes_05dB.value().size() != _number_of_samples)
            throw std::runtime_error(
                fmt::format("ERROR[MWCRxBeamData::to_stream]: The number of samples "
                            "does not match the number of samples in the sample amplitude "
                            "array!"));

        os.write(reinterpret_cast<const char*>(_sample_amplitudes_05dB.value().data()),
                 static_cast<std::streamsize>(_number_of_samples * sizeof(int8_t)));
    }
    else
    {
        std::vector<int8_t> zeros(_number_of_samples, 0);
        os.write(reinterpret_cast<const char*>(zeros.data()),
                 static_cast<std::streamsize>(_number_of_samples * sizeof(int8_t)));
    }
}

bool MWCRxBeamData::operator==(const MWCRxBeamData& other) const
{
    return tools::helper::float_equals(_beam_pointing_angle_re_vertical_deg,
                                        other._beam_pointing_angle_re_vertical_deg) &&
           _start_range_sample_number == other._start_range_sample_number &&
           _detected_range_in_samples == other._detected_range_in_samples &&
           _transmit_sector_number == other._transmit_sector_number &&
           _number_of_samples == other._number_of_samples &&
           _detected_range_in_samples_high_resolution ==
               other._detected_range_in_samples_high_resolution &&
           _sample_amplitudes_05dB == other._sample_amplitudes_05dB &&
           _rx_beam_phase == other._rx_beam_phase;
}

tools::classhelper::ObjectPrinter MWCRxBeamData::__printer__(unsigned int float_precision,
                                                             bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MWCRxBeamData", float_precision, superscript_exponents);

    printer.register_value(
        "beam_pointing_angle_re_vertical_deg", _beam_pointing_angle_re_vertical_deg, "°");
    printer.register_value("start_range_sample_number", _start_range_sample_number);
    printer.register_value("detected_range_in_samples", _detected_range_in_samples, "samples");
    printer.register_value("transmit_sector_number", _transmit_sector_number);
    printer.register_value("number_of_samples", _number_of_samples);
    printer.register_value("detected_range_in_samples_high_resolution",
                           _detected_range_in_samples_high_resolution,
                           "samples");

    printer.register_section("sample data");
    if (!get_samples_are_skipped())
    {
        if (_sample_amplitudes_05dB.has_value())
            printer.register_container("sample_amplitudes_05dB", _sample_amplitudes_05dB.value());
        if (_rx_beam_phase.has_value())
            printer.register_container("rx_beam_phase", _rx_beam_phase.value());
    }
    else
        printer.register_string("samples", "skipped");

    // printer.register_section("processed");=

    return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
