// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawfiledatacontainers.doc.hpp"

/* themachinethatgoesping includes */
#include "../../filetemplates/datacontainers/pingcontainer.hpp"

#include "../filedatatypes/simradrawping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatacontainers {

template<typename t_ifstream>
using SimradRawPingContainer =
    filetemplates::datacontainers::PingContainer<filedatatypes::SimradRawPing<t_ifstream>>;

} // namespace filedatacontainers
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
