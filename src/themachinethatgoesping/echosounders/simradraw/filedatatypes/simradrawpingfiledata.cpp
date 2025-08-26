// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "simradrawpingfiledata.hpp"

#include <fmt/core.h>
#include <set>
#include <stdexcept>

// Include stream headers for template instantiations
#include <fstream>
#include "../../filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {

// ----- SimradRawPingFileData implementation -----

template<typename t_ifstream>
void SimradRawPingFileData<t_ifstream>::init_watercolumn_calibration(bool force)
{
    using datagrams::raw3datatypes::t_RAW3DataType;

    if (_watercolumn_calibration && !force)
        return;

    size_t n_complex_samples = 0;
    switch (_ping_data.get_data_type())
    {
        case t_RAW3DataType::ComplexFloat32:
            n_complex_samples = _ping_data.get_number_of_complex_samples();
            break;
        case t_RAW3DataType::PowerAndAngle:
            [[fallthrough]];
        case t_RAW3DataType::Power:
            [[fallthrough]];
        case t_RAW3DataType::Angle:
            n_complex_samples = 0;
            break;
        default:
            throw std::runtime_error(
                "Error[SimradRawPingFileData::init_watercolumn_calibration]: "
                "Unsupported data type!");
    }

    _watercolumn_calibration =
        std::make_unique<boost::flyweight<calibration::SimradRawWaterColumnCalibration>>(
            _ping_environment.get(),
            _ping_parameter.get(),
            _transceiver_information.get(),
            _filter_stages.get(),
            n_complex_samples);
}

template<typename t_ifstream>
size_t SimradRawPingFileData<t_ifstream>::get_pulse_duration_index() const
{
    const auto& param = get_parameter();
    return _transceiver_information.get().get_pulse_duration_index(
        param.get_pulse_duration(), param.get_pulse_form_is_fm());
}

template<typename t_ifstream>
xt::xtensor<float, 1> SimradRawPingFileData<t_ifstream>::read_sample_data(bool dB)
{
    if (this->_datagram_infos_by_type.at(t_SimradRawDatagramIdentifier::RAW3).empty())
        throw std::runtime_error("No RAW3 datagram in ping!");

    // this assumes that there is exactly one RAW3 datagram saved for this ping
    const auto& datagram_info =
        this->_datagram_infos_by_type.at(t_SimradRawDatagramIdentifier::RAW3).at(0);

    auto sample_data = _ping_data.read_skipped_sample_data(datagram_info->get_stream(),
                                                           datagram_info->get_file_pos());

    return tools::helper::visit_variant(sample_data,
                                        [dB](auto& data) { return data.get_power(dB); });
}

template<typename t_ifstream>
bool SimradRawPingFileData<t_ifstream>::has_power() const
{
    using namespace datagrams::raw3datatypes;

    switch (_ping_data.get_data_type())
    {
        case t_RAW3DataType::Angle:
            return false;
        case t_RAW3DataType::Power:
            [[fallthrough]];
        case t_RAW3DataType::PowerAndAngle:
            [[fallthrough]];
        case t_RAW3DataType::ComplexFloat16:
            return true;
        case t_RAW3DataType::ComplexFloat32:
            return get_transceiver_information().is_initialized();
        default:
            throw std::runtime_error("Unknown data type");
    }
}

template<typename t_ifstream>
bool SimradRawPingFileData<t_ifstream>::has_angle() const
{
    using namespace datagrams::raw3datatypes;

    switch (_ping_data.get_data_type())
    {
        case t_RAW3DataType::Power:
            return false;
        case t_RAW3DataType::Angle:
            [[fallthrough]];
        case t_RAW3DataType::ComplexFloat32:
            [[fallthrough]];
        case t_RAW3DataType::PowerAndAngle:
            [[fallthrough]];
        case t_RAW3DataType::ComplexFloat16:
            return true;
        default:
            throw std::runtime_error("Unknown data type");
    }
}

template<typename t_ifstream>
std::vector<size_t> SimradRawPingFileData<t_ifstream>::get_file_numbers() const
{
    std::vector<size_t> fnr     = { get_primary_file_nr() };
    std::set<size_t>    fnr_set = { get_primary_file_nr() };

    for (const auto& datagram_info : this->_datagram_infos_all)
    {
        auto nr = datagram_info->get_file_nr();
        if (!fnr_set.contains(nr))
        {
            fnr.push_back(nr);
            fnr_set.insert(nr);
        }
    }

    return fnr;
}

template<typename t_ifstream>
std::string SimradRawPingFileData<t_ifstream>::get_primary_file_path() const
{
    must_have_datagrams("get_primary_file_path");

    return this->_datagram_infos_all.at(0)->file_nr_to_file_path(get_primary_file_nr());
}

template<typename t_ifstream>
std::vector<std::string> SimradRawPingFileData<t_ifstream>::get_file_paths() const
{
    must_have_datagrams("get_file_paths");

    auto fnrs = get_file_numbers();

    std::vector<std::string> fps;

    for (const auto& fnr : fnrs)
    {
        fps.push_back(this->_datagram_infos_all.at(0)->file_nr_to_file_path(fnr));
    }

    return fps;
}

template<typename t_ifstream>
void SimradRawPingFileData<t_ifstream>::must_have_datagrams(std::string_view method_name) const
{
    if (this->_datagram_infos_all.empty())
        throw std::runtime_error(
            fmt::format("{}: No datagram in ping!", __func__, method_name));
}

template<typename t_ifstream>
tools::classhelper::ObjectPrinter SimradRawPingFileData<t_ifstream>::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        this->class_name(), float_precision, superscript_exponents);

    printer.append(t_base1::__printer__(float_precision, superscript_exponents));
    printer.append(t_base2::__printer__(float_precision, superscript_exponents));

    printer.register_section("Raw data infos");

    // // convert _ping_data.get_data_type() to string using magic enum
    // printer.register_string("Raw data type",
    //                         std::string(magic_enum::enum_name(_ping_data.get_data_type())));
    // printer.register_value("Has power", has_power());
    // printer.register_value("Has angle", has_angle());

    // printer.register_section("Important members");
    // printer.register_string("ping_data", "RAW3DataVariant");
    // printer.register_string("get_parameter()", "XML_Parameter_Channel");

    return printer;
}

// ----- Explicit template instantiations -----
template class SimradRawPingFileData<std::ifstream>;
template class SimradRawPingFileData<filetemplates::datastreams::MappedFileStream>;

} // namespace filedatatypes
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
