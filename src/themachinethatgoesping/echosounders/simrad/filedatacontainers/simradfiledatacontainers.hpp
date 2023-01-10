// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* themachinethatgoesping includes */
#include "../../filetemplates/datacontainers/datagramcontainer.hpp"
#include "../../filetemplates/datacontainers/pingcontainer.hpp"

#include "../filedatatypes/simradping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace filedatacontainers {

template<typename t_ifstream>
using SimradPingContainer =
    filetemplates::datacontainers::PingContainer<filedatatypes::SimradPing<t_ifstream>>;

} // namespace filedatacontainers
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
