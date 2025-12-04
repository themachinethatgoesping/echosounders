// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallpingcontainer.doc.hpp"

/* themachinethatgoesping includes */
#include "../../filetemplates/datacontainers/datagramcontainer.hpp"
#include "../../filetemplates/datacontainers/pingcontainer.hpp"

#include "../filedatatypes/kmallping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatacontainers {

template<typename t_ifstream>
using KMALLPingContainer =
    filetemplates::datacontainers::PingContainer<filedatatypes::KMALLPing<t_ifstream>>;

} // namespace filedatacontainers
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
