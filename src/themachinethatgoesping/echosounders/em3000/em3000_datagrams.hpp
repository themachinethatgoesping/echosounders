// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000_datagrams.doc.hpp"

#include "datagrams/attitudedatagram.hpp"
#include "datagrams/em3000datagram.hpp"
#include "datagrams/em3000unknown.hpp"
#include "datagrams/extradetections.hpp"
#include "datagrams/qualityfactordatagram.hpp"
#include "datagrams/rawrangeandangle.hpp"
#include "datagrams/seabedimagedata.hpp"
#include "datagrams/watercolumndatagram.hpp"
#include "datagrams/xyzdatagram.hpp"
#include "em3000_types.hpp"

#include <pybind11/pybind11.h>

/**
 * @brief Type definitions for EM datagram format specifications
 *
 * Note: these definitions are valid for kongsberg .all and .wcd files
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {

namespace datagrams {

// EM3000DATAGRAMTYPEAREA
using t_EM3000DatagramVariant = std::variant<EM3000Datagram,
                                             XYZDatagram,
                                             ExtraDetections,
                                             RawRangeAndAngle,
                                             SeabedImageData,
                                             WaterColumnDatagram,
                                             QualityFactorDatagram,
                                             AttitudeDatagram,
                                             EM3000Unknown>;

struct EM3000DatagramVariant
{
    t_EM3000DatagramVariant _datagram_variant;

  public:
    EM3000DatagramVariant() = default;
    EM3000DatagramVariant(t_EM3000DatagramVariant&& datagram_variant)
        : _datagram_variant(std::move(datagram_variant))
    {
    }

    static t_EM3000DatagramVariant from_stream(std::istream&              is,
                                               t_EM3000DatagramIdentifier datagram_type)
    {
        // EM3000DATAGRAMTYPEAREA
        switch (datagram_type)
        {
            case t_EM3000DatagramIdentifier::XYZDatagram:
                return t_EM3000DatagramVariant(XYZDatagram::from_stream(is));
            case t_EM3000DatagramIdentifier::ExtraDetections:
                return t_EM3000DatagramVariant(ExtraDetections::from_stream(is));
            case t_EM3000DatagramIdentifier::RawRangeAndAngle:
                return t_EM3000DatagramVariant(RawRangeAndAngle::from_stream(is));
            case t_EM3000DatagramIdentifier::SeabedImageData:
                return t_EM3000DatagramVariant(SeabedImageData::from_stream(is));
            case t_EM3000DatagramIdentifier::WaterColumnDatagram:
                return t_EM3000DatagramVariant(WaterColumnDatagram::from_stream(is));
            case t_EM3000DatagramIdentifier::QualityFactorDatagram:
                return t_EM3000DatagramVariant(datagrams::QualityFactorDatagram::from_stream(is));
            case t_EM3000DatagramIdentifier::AttitudeDatagram:
                return t_EM3000DatagramVariant(datagrams::AttitudeDatagram::from_stream(is));
            default:
                return t_EM3000DatagramVariant(EM3000Unknown::from_stream(is, datagram_type));
        }
    }

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

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
