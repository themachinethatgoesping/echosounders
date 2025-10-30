// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "types.hpp"

namespace themachinethatgoesping {
namespace echosounders {

std::string datagram_identifier_info(kmall::t_KMALLDatagramIdentifier datagram_type)
{
    using kmall::t_KMALLDatagramIdentifier;
    switch (datagram_type)
    {
        case t_KMALLDatagramIdentifier::I_INSTALLATION_PARAM:
            return "I_INSTALLATION_PARAM";
        case t_KMALLDatagramIdentifier::I_OP_RUNTIME:
            return "I_OP_RUNTIME";
        case t_KMALLDatagramIdentifier::S_POSITION:
            return "S_POSITION";
        case t_KMALLDatagramIdentifier::S_POSITION_ERROR:
            return "S_POSITION_ERROR";
        case t_KMALLDatagramIdentifier::S_POSITION_DATUM:
            return "S_POSITION_DATUM";
        case t_KMALLDatagramIdentifier::S_KM_BINARY:
            return "S_KM_BINARY";
        case t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_PROFILE:
            return "S_SOUND_VELOCITY_PROFILE";
        case t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_TRANSDUCER:
            return "S_SOUND_VELOCITY_TRANSDUCER";
        case t_KMALLDatagramIdentifier::S_CLOCK:
            return "S_CLOCK";
        case t_KMALLDatagramIdentifier::S_DEPTH:
            return "S_DEPTH";
        case t_KMALLDatagramIdentifier::S_HEIGHT:
            return "S_HEIGHT";
        case t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH:
            return "M_RANGE_AND_DEPTH";
        case t_KMALLDatagramIdentifier::M_WATER_COLUMN:
            return "M_WATER_COLUMN";
        case t_KMALLDatagramIdentifier::C_POSITION:
            return "C_POSITION";
        case t_KMALLDatagramIdentifier::C_HEAVE:
            return "C_HEAVE";
        case t_KMALLDatagramIdentifier::F_CALIBRATION_FILE:
            return "F_CALIBRATION_FILE";
        default:
            return "unknown (" + std::to_string(magic_enum::enum_integer(datagram_type)) + ")";
    }
}
}
}

template class themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier,
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_values.size(),
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_values,
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_names,
    themachinethatgoesping::echosounders::kmall::t_KMALLDatagramIdentifier_alt_names>;