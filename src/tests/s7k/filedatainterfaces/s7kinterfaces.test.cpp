// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_test_macros.hpp>

#include <fstream>
#include <memory>

#include "../themachinethatgoesping/echosounders/s7k/filedatacontainers/s7kpingcontainer.hpp"
#include "../themachinethatgoesping/echosounders/s7k/filedatainterfaces/s7kconfigurationdatainterface.hpp"
#include "../themachinethatgoesping/echosounders/s7k/filedatainterfaces/s7kdatagramdatainterface.hpp"
#include "../themachinethatgoesping/echosounders/s7k/filedatainterfaces/s7kenvironmentdatainterface.hpp"
#include "../themachinethatgoesping/echosounders/s7k/filedatainterfaces/s7knavigationdatainterface.hpp"
#include "../themachinethatgoesping/echosounders/s7k/filedatainterfaces/s7kotherfiledatainterface.hpp"
#include "../themachinethatgoesping/echosounders/s7k/filedatainterfaces/s7kpingdatainterface.hpp"
#include "../themachinethatgoesping/echosounders/s7k/filedatatypes/s7kping.hpp"

using namespace themachinethatgoesping::echosounders::s7k;

#define TESTTAG "[s7k]"

// The file-data interfaces and ping types are structural shells at this step (the datagram-
// processing functions are not implemented yet). These tests only verify that the interfaces can be
// constructed (including the configuration<-navigation<-environment<-ping dependency chain) and that
// their printers produce output without throwing.

TEST_CASE("S7K file data interfaces can be constructed and printed", TESTTAG)
{
    using t_ifstream = std::ifstream;

    // generic interfaces (default constructible)
    auto datagramdata = std::make_shared<filedatainterfaces::S7KDatagramDataInterface<t_ifstream>>();
    auto otherfile = std::make_shared<filedatainterfaces::S7KOtherFileDataInterface<t_ifstream>>();

    // specialized interfaces form a dependency chain
    auto configuration =
        std::make_shared<filedatainterfaces::S7KConfigurationDataInterface<t_ifstream>>();
    auto navigation =
        std::make_shared<filedatainterfaces::S7KNavigationDataInterface<t_ifstream>>(configuration);
    auto environment =
        std::make_shared<filedatainterfaces::S7KEnvironmentDataInterface<t_ifstream>>(navigation);
    auto ping =
        std::make_shared<filedatainterfaces::S7KPingDataInterface<t_ifstream>>(environment);

    CHECK(datagramdata->__printer__(2, false).create_str().size() != 0);
    CHECK(otherfile->__printer__(2, false).create_str().size() != 0);
    CHECK(configuration->__printer__(2, false).create_str().size() != 0);
    CHECK(navigation->__printer__(2, false).create_str().size() != 0);
    CHECK(environment->__printer__(2, false).create_str().size() != 0);
    CHECK(ping->__printer__(2, false).create_str().size() != 0);
}

TEST_CASE("S7K ping type can be constructed, printed and deep-copied", TESTTAG)
{
    using t_ifstream = std::ifstream;

    filedatatypes::S7KPing<t_ifstream> ping;

    // bottom / watercolumn sub-objects are available and printable
    CHECK(ping.__printer__(2, false).create_str().size() != 0);
    CHECK(ping.bottom().__printer__(2, false).create_str().size() != 0);
    CHECK(ping.watercolumn().__printer__(2, false).create_str().size() != 0);

    // deep copy keeps its own file_data
    auto copy = ping.deep_copy();
    CHECK(copy.__printer__(2, false).create_str().size() != 0);

    // the ping container is default constructible
    filedatacontainers::S7KPingContainer<t_ifstream> container;
    CHECK(container.size() == 0);
}
