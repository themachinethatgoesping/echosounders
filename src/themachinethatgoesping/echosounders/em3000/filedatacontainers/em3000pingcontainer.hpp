// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000pingcontainer.doc.hpp"

/* themachinethatgoesping includes */
#include "../../filetemplates/datacontainers/datagramcontainer.hpp"
#include "../../filetemplates/datacontainers/pingcontainer.hpp"

#include "../filedatatypes/em3000ping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatacontainers {

template<typename t_ifstream>
class EM3000PingContainer
    : public filetemplates::datacontainers::PingContainer<filedatatypes::EM3000Ping<t_ifstream>>
{
    using t_base =
        filetemplates::datacontainers::PingContainer<filedatatypes::EM3000Ping<t_ifstream>>;

  public:
    EM3000PingContainer()
        : t_base("EM3000PingContainer")
    {
    }
    EM3000PingContainer(std::string_view name)
        : t_base(name)
    {
    }
    ~EM3000PingContainer() = default;
};
// using EM3000PingContainer =
//     filetemplates::datacontainers::PingContainer<filedatatypes::EM3000Ping<t_ifstream>>;

} // namespace filedatacontainers
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
