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
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

class I_Ping
{
    std::string_view _name;

  public:
    I_Ping(std::string_view name)
        : _name(name)
    {
    }
    virtual ~I_Ping() = default;

    //------ interface ------//
    virtual size_t max_number_of_samples() const
    {
        throw std::runtime_error(
            fmt::format("get_number_of_samples not implemented for this ping type ({})", _name));
    }

    virtual xt::xtensor<float, 2> get_sv()
    {
        throw std::runtime_error(
            fmt::format("get_sv not implemented for this ping type ({})", _name));
    }
    virtual xt::xtensor<float, 1> get_sv_stacked()
    {
        throw std::runtime_error(
            fmt::format("get_sv_stacked not implemented for this ping type ({})", _name));
    }

    virtual xt::xtensor<float, 2> get_angle()
    {
        throw std::runtime_error(
            fmt::format("get_angle not implemented for this ping type ({})", _name));
    }
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping