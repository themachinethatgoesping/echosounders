// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallpingcontainer.doc.hpp"

/* themachinethatgoesping includes */
#include "../../filetemplates/datacontainers/datagramcontainer.hpp"
#include "../../filetemplates/datacontainers/pingcontainer.hpp"

#include "../filedatatypes/kongsbergallping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatacontainers {

template<typename t_ifstream>
using KongsbergAllPingContainer =
    filetemplates::datacontainers::PingContainer<filedatatypes::KongsbergAllPing<t_ifstream>>;

} // namespace filedatacontainers
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
