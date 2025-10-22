// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "datagrams.hpp"

#include <utility>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

KongsbergAllDatagramVariant::KongsbergAllDatagramVariant() = default;

KongsbergAllDatagramVariant::KongsbergAllDatagramVariant(
	t_KongsbergAllDatagramVariant&& datagram_variant)
	: _datagram_variant(std::move(datagram_variant))
{
}

t_KongsbergAllDatagramVariant KongsbergAllDatagramVariant::from_stream(
	std::istream&                    is,
	o_KongsbergAllDatagramIdentifier datagram_type,
	bool                             skip_data)
{
	switch (datagram_type.value)
	{
		case t_KongsbergAllDatagramIdentifier::XYZDatagram:
			return t_KongsbergAllDatagramVariant(XYZDatagram::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::ExtraDetections:
			return t_KongsbergAllDatagramVariant(ExtraDetections::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::RawRangeAndAngle:
			return t_KongsbergAllDatagramVariant(RawRangeAndAngle::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::SeabedImageData:
			return t_KongsbergAllDatagramVariant(SeabedImageData::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::WatercolumnDatagram:
			return t_KongsbergAllDatagramVariant(WatercolumnDatagram::from_stream(is, skip_data));
		case t_KongsbergAllDatagramIdentifier::QualityFactorDatagram:
			return t_KongsbergAllDatagramVariant(QualityFactorDatagram::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::AttitudeDatagram:
			return t_KongsbergAllDatagramVariant(AttitudeDatagram::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::NetworkAttitudeVelocityDatagram:
			return t_KongsbergAllDatagramVariant(NetworkAttitudeVelocityDatagram::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::ClockDatagram:
			return t_KongsbergAllDatagramVariant(ClockDatagram::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::DepthOrHeightDatagram:
			return t_KongsbergAllDatagramVariant(DepthOrHeightDatagram::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::HeadingDatagram:
			return t_KongsbergAllDatagramVariant(HeadingDatagram::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::PositionDatagram:
			return t_KongsbergAllDatagramVariant(PositionDatagram::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::SingleBeamEchoSounderDepth:
			return t_KongsbergAllDatagramVariant(SingleBeamEchoSounderDepth::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::SurfaceSoundSpeedDatagram:
			return t_KongsbergAllDatagramVariant(SurfaceSoundSpeedDatagram::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram:
			return t_KongsbergAllDatagramVariant(SoundSpeedProfileDatagram::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::InstallationParametersStart:
			return t_KongsbergAllDatagramVariant(InstallationParameters::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::InstallationParametersStop:
			return t_KongsbergAllDatagramVariant(InstallationParameters::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::RuntimeParameters:
			return t_KongsbergAllDatagramVariant(RuntimeParameters::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::ExtraParameters:
			return t_KongsbergAllDatagramVariant(ExtraParameters::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::PUIDOutput:
			return t_KongsbergAllDatagramVariant(PUIDOutput::from_stream(is));
		case t_KongsbergAllDatagramIdentifier::PUStatusOutput:
			return t_KongsbergAllDatagramVariant(PUStatusOutput::from_stream(is));
		default:
			return t_KongsbergAllDatagramVariant(KongsbergAllUnknown::from_stream(is, datagram_type));
	}
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
