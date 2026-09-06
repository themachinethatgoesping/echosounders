// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kpingcontainer.doc.hpp"

/* themachinethatgoesping includes */
#include "../../filetemplates/datacontainers/datagramcontainer.hpp"
#include "../../filetemplates/datacontainers/pingcontainer.hpp"

#include "../filedatatypes/s7kping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatacontainers {

template<typename t_ifstream>
using S7KPingContainer =
    filetemplates::datacontainers::PingContainer<filedatatypes::S7KPing<t_ifstream>>;

} // namespace filedatacontainers
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
