// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "simradrawpingwatercolumn.hpp"

#include <xtensor/views/xview.hpp>

// Include stream headers for template instantiations
#include <fstream>
#include "../../filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {

// ----- SimradRawPingWatercolumn implementation -----

template<typename t_ifstream>
xt::xtensor<size_t, 1> SimradRawPingWatercolumn<t_ifstream>::get_tx_sector_per_beam(
    const pingtools::BeamSelection& selection)
{
    this->beam_selection_must_be_one(__func__, selection);
    return { 0 };
}

template<typename t_ifstream>
std::vector<std::vector<size_t>> SimradRawPingWatercolumn<t_ifstream>::get_beam_numbers_per_tx_sector(
    const pingtools::BeamSelection& selection)
{
    this->beam_selection_must_be_one(__func__, selection);
    std::vector<std::vector<size_t>> beam_numbers_per_tx_sector(1);
    // beam_numbers_per_tx_sector[0].resize(1);
    // beam_numbers_per_tx_sector[0][0] = 0;
    return beam_numbers_per_tx_sector;
}

template<typename t_ifstream>
std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
SimradRawPingWatercolumn<t_ifstream>::get_tx_signal_parameters() const
{
    return { file_data().get_parameter().get_tx_signal_parameters() };
}

template<typename t_ifstream>
xt::xtensor<float, 1> SimradRawPingWatercolumn<t_ifstream>::get_beam_crosstrack_angles(
    const pingtools::BeamSelection& selection)
{
    this->beam_selection_must_be_one(__func__, selection);
    
    return { 0 };
}

template<typename t_ifstream>
xt::xtensor<float, 1> SimradRawPingWatercolumn<t_ifstream>::get_beam_alongtrack_angles(
    const pingtools::BeamSelection& selection)
{
    this->beam_selection_must_be_one(__func__, selection);
    
    return { 0 };
}

template<typename t_ifstream>
xt::xtensor<uint32_t, 1> SimradRawPingWatercolumn<t_ifstream>::get_number_of_samples_per_beam(
    const pingtools::BeamSelection& selection)
{
    this->beam_selection_must_be_one(__func__, selection);
    
    return { uint32_t(_file_data->get_ping_data().get_count()) };
}

template<typename t_ifstream>
xt::xtensor<uint32_t, 1> SimradRawPingWatercolumn<t_ifstream>::get_first_sample_offset_per_beam()
{
    return { uint32_t(_file_data->get_ping_data().get_offset()) };
}

template<typename t_ifstream>
const xt::xtensor<uint8_t, 1>& SimradRawPingWatercolumn<t_ifstream>::get_transmit_sector_numbers()
{
    static const xt::xtensor<uint8_t, 1> sector_numbers = { 0 };
    return sector_numbers;
}

template<typename t_ifstream>
float SimradRawPingWatercolumn<t_ifstream>::get_sound_speed_at_transducer()
{
    // TODO: check if sound speed is available in the file
    //  if not, use the environment sound speed
    //  is environment sound speed always available? Is it a good replacement? Or better search
    //  for Soundvelocity profile?
    auto sound_speed = _file_data->get_parameter().SoundVelocity;
    if (sound_speed > 0)
        return sound_speed;
    return _file_data->get_environment().SoundSpeed;
}

template<typename t_ifstream>
float SimradRawPingWatercolumn<t_ifstream>::get_sample_interval()
{
    return _file_data->get_parameter().SampleInterval;
}

template<typename t_ifstream>
xt::xtensor<float, 2> SimradRawPingWatercolumn<t_ifstream>::get_amplitudes(
    const pingtools::BeamSampleSelection& selection,
    [[maybe_unused]] int mp_cores)
{
    this->beam_selection_must_be_one(__func__, selection);

    size_t ensemble_offset = selection.get_first_sample_number_ensemble();

    auto amplitudes =
        xt::xtensor<float, 2>::from_shape({ 1, selection.get_number_of_samples_ensemble() });

    // read amplitudes
    auto rsr = selection.get_read_sample_range(0 // beam number
                                               ,
                                               _file_data->get_ping_data().get_offset(),
                                               _file_data->get_ping_data().get_count());

    if (rsr.get_number_of_samples_to_read() > 0)
    {
        xt::view(amplitudes,
                 0, // beam number
                 xt::range(rsr.get_first_read_sample_offset() - ensemble_offset,
                           rsr.get_last_read_sample_offset() + 1 - ensemble_offset)) =
            xt::cast<float>(_file_data->read_sample_data(true));
    }

    return amplitudes;
}

template<typename t_ifstream>
void SimradRawPingWatercolumn<t_ifstream>::load(bool force)
{
    // load watercolumn calibration
    _file_data->init_watercolumn_calibration(force);
}

template<typename t_ifstream>
void SimradRawPingWatercolumn<t_ifstream>::release()
{
    _file_data->release_watercolumn_calibration();
}

template<typename t_ifstream>
bool SimradRawPingWatercolumn<t_ifstream>::loaded()
{
    if (!_file_data->watercolumn_calibration_loaded())
        return false;

    return true;
}

template<typename t_ifstream>
tools::classhelper::ObjectPrinter SimradRawPingWatercolumn<t_ifstream>::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        this->class_name(), float_precision, superscript_exponents);

    printer.append(t_base1::__printer__(float_precision, superscript_exponents));

    auto& wcinfos = _file_data->get_wcinfos();

    printer.register_container("beam_crosstrack_angles", wcinfos.get_beam_crosstrack_angles());
    printer.register_container("start_range_sample_numbers",
                               wcinfos.get_start_range_sample_numbers());
    printer.register_container("number_of_samples_per_bean",
                               wcinfos.get_number_of_samples_per_beam());
    printer.register_container("detected_range_in_samples",
                               wcinfos.get_detected_range_in_samples());
    printer.register_container("transmit_sector_numbers",
                               wcinfos.get_transmit_sector_numbers());

    return printer;
}

// ----- Explicit template instantiations -----
template class SimradRawPingWatercolumn<std::ifstream>;
template class SimradRawPingWatercolumn<filetemplates::datastreams::MappedFileStream>;

} // namespace filedatatypes
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
