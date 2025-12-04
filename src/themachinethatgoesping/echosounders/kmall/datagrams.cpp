// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "datagrams.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {

namespace datagrams {

t_KMALLDatagramVariant KMALLDatagramVariant::from_stream(std::istream&             is,
                                                         t_KMALLDatagramIdentifier datagram_type,
                                                         [[maybe_unused]] bool     skip_data)
{
    // KMALLDATAGRAMTYPEAREA
    switch (datagram_type)
    {
        case t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH:
            return t_KMALLDatagramVariant(MRangeAndDepth::from_stream(is));
        case t_KMALLDatagramIdentifier::M_WATER_COLUMN:
            return t_KMALLDatagramVariant(MWaterColumn::from_stream(is, skip_data));
        case t_KMALLDatagramIdentifier::I_INSTALLATION_PARAM:
            return t_KMALLDatagramVariant(IInstallationParam::from_stream(is));
        case t_KMALLDatagramIdentifier::I_OP_RUNTIME:
            return t_KMALLDatagramVariant(IOpRuntime::from_stream(is));
        case t_KMALLDatagramIdentifier::S_POSITION:
            return t_KMALLDatagramVariant(SPosition::from_stream(is));
        case t_KMALLDatagramIdentifier::S_POSITION_ERROR:
            return t_KMALLDatagramVariant(SPositionError::from_stream(is));
        case t_KMALLDatagramIdentifier::S_CLOCK:
            return t_KMALLDatagramVariant(SClock::from_stream(is));
        case t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_PROFILE:
            return t_KMALLDatagramVariant(SSoundVelocityProfile::from_stream(is));
        case t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_TRANSDUCER:
            return t_KMALLDatagramVariant(SSoundVelocityTransducer::from_stream(is));
        case t_KMALLDatagramIdentifier::S_KM_BINARY:
            return t_KMALLDatagramVariant(SKMBinary::from_stream(is));
        case t_KMALLDatagramIdentifier::C_POSITION:
            return t_KMALLDatagramVariant(CPosition::from_stream(is));
        case t_KMALLDatagramIdentifier::C_HEAVE:
            return t_KMALLDatagramVariant(CHeave::from_stream(is));

        default:
            return t_KMALLDatagramVariant(KMALLUnknown::from_stream(is, datagram_type));
    }
}

} // namespace datagrams

} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
