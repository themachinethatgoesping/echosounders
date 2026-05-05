// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mrzextradetclassinfocontainer.hpp"

#include <fmt/core.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

const std::vector<MRZExtraDetClassInfo>&
MRZExtraDetClassInfoContainer::get_extra_det_class_info() const
{
    return _extra_det_class_info;
}

std::vector<MRZExtraDetClassInfo>& MRZExtraDetClassInfoContainer::extra_det_class_info()
{
    return _extra_det_class_info;
}

void MRZExtraDetClassInfoContainer::set_extra_det_class_info(
    const std::vector<MRZExtraDetClassInfo>& info)
{
    _extra_det_class_info = info;
}

xt::xtensor<uint16_t, 1> MRZExtraDetClassInfoContainer::get_num_extra_det_in_class_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<uint16_t>(
        [](const MRZExtraDetClassInfo& c) { return c.get_num_extra_det_in_class(); }, indices);
}

xt::xtensor<int8_t, 1> MRZExtraDetClassInfoContainer::get_padding_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<int8_t>(
        [](const MRZExtraDetClassInfo& c) { return c.get_padding(); }, indices);
}

xt::xtensor<uint8_t, 1> MRZExtraDetClassInfoContainer::get_alarm_flag_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<uint8_t>(
        [](const MRZExtraDetClassInfo& c) { return c.get_alarm_flag(); }, indices);
}

size_t MRZExtraDetClassInfoContainer::get_number_of_extra_det_class_info() const
{
    return _extra_det_class_info.size();
}

tools::classhelper::ObjectPrinter MRZExtraDetClassInfoContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MRZExtraDetClassInfoContainer", float_precision, superscript_exponents);
    printer.register_value("number_of_extra_det_class_info", _extra_det_class_info.size());
    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
