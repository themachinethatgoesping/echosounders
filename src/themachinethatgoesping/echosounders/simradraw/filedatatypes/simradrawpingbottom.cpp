// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "simradrawpingbottom.hpp"

// Include stream headers for template instantiations
#include <fstream>
#include "../../filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {

// ----- SimradRawPingBottom implementation -----

template<typename t_ifstream>
xt::xtensor<size_t, 1> SimradRawPingBottom<t_ifstream>::get_tx_sector_per_beam(
    [[maybe_unused]] const pingtools::BeamSelection& selection)
{
    return { 0 };
}

template<typename t_ifstream>
std::vector<std::vector<size_t>> SimradRawPingBottom<t_ifstream>::get_beam_numbers_per_tx_sector(
   [[maybe_unused]] const pingtools::BeamSelection& selection)
{
    return { { 0 } };
}

template<typename t_ifstream>
uint32_t SimradRawPingBottom<t_ifstream>::get_number_of_beams()
{
    if (has_xyz())
        return 1;

    if (has_two_way_travel_times())
        return 1;

    return 0;
}

template<typename t_ifstream>
tools::classhelper::ObjectPrinter SimradRawPingBottom<t_ifstream>::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        this->class_name(), float_precision, superscript_exponents);

    printer.append(t_base1::__printer__(float_precision, superscript_exponents));

    // printer.register_section("SimradRaw ping infos");

    // printer.register_string(
    //     "Sample data type",
    //     std::string(magic_enum::enum_name(_file_data->_ping_data.get_data_type())));

    // printer.register_section("Important members");
    // printer.register_string("file_data", "SimradRawPingFileData");

    return printer;
}

// ----- Explicit template instantiations -----
template class SimradRawPingBottom<std::ifstream>;
template class SimradRawPingBottom<filetemplates::datastreams::MappedFileStream>;

} // namespace filedatatypes
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
