// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "datagrams.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {

namespace datagrams {

t_S7KDatagramVariant S7KDatagramVariant::from_stream(std::istream&           is,
                                                     t_S7KDatagramIdentifier datagram_type,
                                                     bool                    skip_data)
{
    // S7KDATAGRAMTYPEAREA
    switch (datagram_type)
    {
        case t_S7KDatagramIdentifier::ReferencePoint:
            return t_S7KDatagramVariant(ReferencePoint::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::Position:
            return t_S7KDatagramVariant(Position::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::RollPitchHeave:
            return t_S7KDatagramVariant(RollPitchHeave::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::Heading:
            return t_S7KDatagramVariant(Heading::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::Navigation:
            return t_S7KDatagramVariant(Navigation::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::SonarSettings:
            return t_S7KDatagramVariant(SonarSettings::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::MatchFilter:
            return t_S7KDatagramVariant(MatchFilter::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::SoundVelocity:
            return t_S7KDatagramVariant(SoundVelocity::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::AbsorptionLoss:
            return t_S7KDatagramVariant(AbsorptionLoss::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::SpreadingLoss:
            return t_S7KDatagramVariant(SpreadingLoss::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::RawDetectionData:
            return t_S7KDatagramVariant(RawDetection::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::SnippetData:
            return t_S7KDatagramVariant(Snippet::from_stream(is, datagram_type, skip_data));
        case t_S7KDatagramIdentifier::CompressedWaterColumnData:
            return t_S7KDatagramVariant(
                CompressedWaterColumn::from_stream(is, datagram_type, skip_data));
        case t_S7KDatagramIdentifier::BeamGeometry:
            return t_S7KDatagramVariant(BeamGeometry::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::Attitude:
            return t_S7KDatagramVariant(Attitude::from_stream(is, datagram_type));
        case t_S7KDatagramIdentifier::FileHeader:
            return t_S7KDatagramVariant(FileHeader::from_stream(is, datagram_type));

        default:
            return t_S7KDatagramVariant(S7KUnknown::from_stream(is, datagram_type));
    }
}

} // namespace datagrams

} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
