// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/datagrams.doc.hpp"

#include <variant>

#include "datagrams/attitudedatagram.hpp"
#include "datagrams/clockdatagram.hpp"
#include "datagrams/depthorheightdatagram.hpp"
#include "datagrams/kongsbergalldatagram.hpp"
#include "datagrams/kongsbergallunknown.hpp"
#include "datagrams/extradetections.hpp"
#include "datagrams/extraparameters.hpp"
#include "datagrams/headingdatagram.hpp"
#include "datagrams/installationparameters.hpp"
#include "datagrams/networkattitudevelocitydatagram.hpp"
#include "datagrams/positiondatagram.hpp"
#include "datagrams/puidoutput.hpp"
#include "datagrams/pustatusoutput.hpp"
#include "datagrams/qualityfactordatagram.hpp"
#include "datagrams/rawrangeandangle.hpp"
#include "datagrams/runtimeparameters.hpp"
#include "datagrams/seabedimagedata.hpp"
#include "datagrams/singlebeamechosounderdepth.hpp"
#include "datagrams/soundspeedprofiledatagram.hpp"
#include "datagrams/surfacesoundspeeddatagram.hpp"
#include "datagrams/watercolumndatagram.hpp"
#include "datagrams/xyzdatagram.hpp"
#include "types.hpp"

//#include <pybind11/pybind11.h>

/**
 * @brief Type definitions for EM datagram format specifications
 *
 * Note: these definitions are valid for kongsberg .all and .wcd files
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {

namespace datagrams {

// KongsbergAllDATAGRAMTYPEAREA
using t_KongsbergAllDatagramVariant = std::variant<KongsbergAllDatagram,
                                             XYZDatagram,
                                             ExtraDetections,
                                             RawRangeAndAngle,
                                             SeabedImageData,
                                             WatercolumnDatagram,
                                             QualityFactorDatagram,
                                             AttitudeDatagram,
                                             NetworkAttitudeVelocityDatagram,
                                             ClockDatagram,
                                             DepthOrHeightDatagram,
                                             HeadingDatagram,
                                             PositionDatagram,
                                             SingleBeamEchoSounderDepth,
                                             SurfaceSoundSpeedDatagram,
                                             SoundSpeedProfileDatagram,
                                             InstallationParameters,
                                             RuntimeParameters,
                                             ExtraParameters,
                                             PUIDOutput,
                                             PUStatusOutput,
                                             KongsbergAllUnknown>;

struct KongsbergAllDatagramVariant
{
    t_KongsbergAllDatagramVariant _datagram_variant;

  public:
    KongsbergAllDatagramVariant();
    explicit KongsbergAllDatagramVariant(t_KongsbergAllDatagramVariant&& datagram_variant);

    static t_KongsbergAllDatagramVariant from_stream(std::istream&              is,
                                                     o_KongsbergAllDatagramIdentifier datagram_type,
                                                     bool skip_data = false);

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
struct KongsbergAllSkipDataFactory
{
    static t_datagram from_stream(std::istream& is) { return t_datagram::from_stream(is, true); }

    static t_datagram from_stream(std::istream& is, t_KongsbergAllDatagramIdentifier type)
    {
        return t_datagram::from_stream(is, type, true);
    }
};

struct KongsbergAllSkipDataVariantFactory
{
    static t_KongsbergAllDatagramVariant from_stream(std::istream& is, t_KongsbergAllDatagramIdentifier type)
    {
        return KongsbergAllDatagramVariant::from_stream(is, type, true);
    }
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
