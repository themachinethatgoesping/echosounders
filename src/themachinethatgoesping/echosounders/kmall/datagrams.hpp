// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/datagrams.doc.hpp"

#include "datagrams/iinstallationparam.hpp"
#include "datagrams/iopruntime.hpp"
#include "datagrams/kmalldatagram.hpp"
#include "datagrams/kmallunknown.hpp"
#include "datagrams/sposition.hpp"
#include "datagrams/spositionerror.hpp"
#include "types.hpp"

#include <variant>

/**
 * @brief Type definitions for EM datagram format specifications
 *
 * Note: these definitions are valid for kongsberg .all and .wcd files
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {

namespace datagrams {

// KMALLDATAGRAMTYPEAREA
using t_KMALLDatagramVariant =
    std::variant<KMALLDatagram, KMALLUnknown, IInstallationParam, IOpRuntime, SPosition, SPositionError>;

struct KMALLDatagramVariant
{
    t_KMALLDatagramVariant _datagram_variant;

  public:
    KMALLDatagramVariant() = default;
    KMALLDatagramVariant(t_KMALLDatagramVariant&& datagram_variant)
        : _datagram_variant(std::move(datagram_variant))
    {
    }

    static t_KMALLDatagramVariant from_stream(std::istream&             is,
                                              t_KMALLDatagramIdentifier datagram_type,
                                              [[maybe_unused]] bool     skip_data = false);

    /**
     * @brief This is the visitor function that  tries to convert the internal variant to the
     * specified type.
     *
     * @tparam t_ProgressBar
     * @param progress_bar ProgressBar class that is derived from I_ProgressBar
     * @return I_ProgressBar&
     */
    template<typename t_Datagram>
    t_Datagram& operator()() const
    {
        return t_Datagram(_datagram_variant);
    }
};

template<typename t_datagram>
struct KMALLSkipDataFactory
{
    static t_datagram from_stream(std::istream& is) { return t_datagram::from_stream(is, true); }

    static t_datagram from_stream(std::istream& is, t_KMALLDatagramIdentifier type)
    {
        return t_datagram::from_stream(is, type, true);
    }
};

struct KMALLSkipDataVariantFactory
{
    static t_KMALLDatagramVariant from_stream(std::istream& is, t_KMALLDatagramIdentifier type)
    {
        return KMALLDatagramVariant::from_stream(is, type, true);
    }
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
