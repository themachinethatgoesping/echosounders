// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "types.hpp"

// explicit instantiation of the OptionFrozen template (matching the extern template declaration in
// types.hpp) to avoid re-instantiating the frozen lookup maps in every translation unit
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::t_S7KDatagramIdentifier,
    themachinethatgoesping::echosounders::s7k::t_S7KDatagramIdentifier_values.size(),
    themachinethatgoesping::echosounders::s7k::t_S7KDatagramIdentifier_values,
    themachinethatgoesping::echosounders::s7k::t_S7KDatagramIdentifier_names,
    themachinethatgoesping::echosounders::s7k::t_S7KDatagramIdentifier_alt_names>;
