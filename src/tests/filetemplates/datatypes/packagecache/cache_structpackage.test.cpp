// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/cache_structures/filepackagecache.hpp>
#include <themachinethatgoesping/echosounders/filetemplates/datatypes/cache_structures/packagecache.hpp>
#include <themachinethatgoesping/echosounders/filetemplates/datatypes/cache_structures/structpackage.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::cache_structures;

#define TESTTAG "[filetemplates]"

using Catch::Approx;

TEST_CASE("StructPackage should support common functions", TESTTAG)
{
    struct test_struct
    {
        size_t a;
        double b;
        int    c;

        test_struct() = default;
        test_struct(size_t a, double b, int c)
            : a(a)
            , b(b)
            , c(c)
        {
        }
        test_struct(const test_struct&) = default;

        bool operator==(const test_struct& other) const = default;
    };

    using t_StructPackage = StructPackage<test_struct>;

    // initialize class structure
    t_StructPackage dat(1000, -3.14, -42);

    // test inequality
    REQUIRE(dat != t_StructPackage());

    // test copy
    // INFO(dat.info_string());
    // INFO(t_StructPackage(dat).info_string());
    REQUIRE(dat == t_StructPackage(dat));

    // test binary
    auto dat2 = dat.from_binary(dat.to_binary());
    REQUIRE(dat == dat2);

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == dat.from_stream(buffer));

    // test stream reading should be simple binary representation
    // This is not the case! (tuple often inverts the order of the elements, so we cannot use this
    // test here)
    size_t a = 1000;
    double b = -3.14;
    int    c = -42;
    buffer.clear();
    buffer.write(reinterpret_cast<const char*>(&a), sizeof(a));
    buffer.write(reinterpret_cast<const char*>(&b), sizeof(b));
    buffer.write(reinterpret_cast<const char*>(&c), sizeof(c));
    auto dat3 = dat.from_stream(buffer);
    // INFO(dat3.info_string());
    REQUIRE(dat == dat3);

    // test print does not crash
    // REQUIRE(dat.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(dat.a == 1000);
    REQUIRE(dat2.a == 1000);
    REQUIRE(dat.b == Approx(-3.14));
    REQUIRE(dat2.b == Approx(-3.14));
    REQUIRE(dat.c == -42);
    REQUIRE(dat2.c == -42);
}

TEST_CASE("StructPackage should be convertible to PackageCache", TESTTAG)
{
    // initialize class structure
    struct test_struct
    {
        size_t a;
        double b;
        int    c;

        test_struct() = default;
        test_struct(size_t a, double b, int c)
            : a(a)
            , b(b)
            , c(c)
        {
        }
        test_struct(const test_struct&) = default;

        bool operator==(const test_struct& other) const = default;
    };

    using t_StructPackage = StructPackage<test_struct>;

    // initialize class structure
    t_StructPackage dat(1000, -3.14, -42);

    std::unordered_map<size_t, std::string> hash_cache;

    PackageCache<t_StructPackage> package_cache(0, 0, std::make_unique<t_StructPackage>(dat));

    // test basic access
    REQUIRE(dat == package_cache.get());

    // test to/from binary
    SECTION("PackageCache: to/from binary")
    {
        // INFO(dat.info_string());
        //  INFO(package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache)
        //           .get()
        //           .info_string());
        REQUIRE(dat ==
                package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache).get());
        REQUIRE(package_cache ==
                package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache));
    }
}

TEST_CASE("StructPackage should be usable with FilePackageCache", TESTTAG)
{
    // initialize class structure
    struct test_struct
    {
        size_t a;
        double b;
        int    c;

        test_struct() = default;
        test_struct(size_t a, double b, int c)
            : a(a)
            , b(b)
            , c(c)
        {
        }
        test_struct(const test_struct&) = default;

        bool operator==(const test_struct& other) const = default;
    };

    using t_StructPackage = StructPackage<test_struct>;

    // initialize class structure
    t_StructPackage dat(1000, -3.14, -42);
    t_StructPackage dat2(2000, -4.14, 52);
    t_StructPackage dat3(100, 3.14, 34);

    std::unordered_map<size_t, std::string> hash_cache;

    PackageCache<t_StructPackage> package_cache(0, 0, std::make_unique<t_StructPackage>(dat));

    FilePackageCache<t_StructPackage> package_cache_buffer;

    package_cache_buffer.add_package(package_cache);
    package_cache_buffer.add_package(12, 3, std::make_unique<t_StructPackage>(dat2));
    package_cache_buffer.add_package(22, 3, std::make_unique<t_StructPackage>(dat));
    package_cache_buffer.add_package(24, 3, std::make_unique<t_StructPackage>(dat2));
    package_cache_buffer.add_package(24, 3, std::make_unique<t_StructPackage>(dat3), 1);

    REQUIRE(package_cache_buffer.has_package(0));
    REQUIRE(!package_cache_buffer.has_package(1));
    REQUIRE(package_cache_buffer.has_package(22));
    REQUIRE(package_cache_buffer.has_package(24));

    SECTION("FilePackageCache: test basic access")
    {
        // INFO(dat.info_string());
        // INFO(package_cache_buffer.get_package(0, 0).info_string());
        // INFO("--- dat 2 ---");
        // INFO(dat2.info_string());
        // INFO(package_cache_buffer.get_package(12, 3).info_string());
        REQUIRE(dat == package_cache_buffer.get_package(0, 0));
        REQUIRE(dat2 == package_cache_buffer.get_package(12, 3));
        REQUIRE_THROWS(package_cache_buffer.get_package(1, 3));

        REQUIRE(dat3 == package_cache_buffer.get_package(24, 3, 1));
        REQUIRE(dat2 == package_cache_buffer.get_package(24, 3, 0));

        REQUIRE(package_cache_buffer.get_package_buffer().size() == 4);
        REQUIRE(package_cache_buffer.get_hash_cache().size() == 3);
    }

    // test to/from binary
    REQUIRE(package_cache_buffer != FilePackageCache<t_StructPackage>());
    REQUIRE(package_cache_buffer ==
            package_cache_buffer.from_binary(package_cache_buffer.to_binary()));

    // INFO(package_cache_buffer.info_string());
    // REQUIRE(package_cache_buffer.info_string() != "");

    SECTION("FilePackageCache: test multi-dat support")
    {
        REQUIRE(package_cache_buffer.get_subpackage_count(0) == 1);
        REQUIRE(package_cache_buffer.get_subpackage_count(1) == 0);
        REQUIRE(package_cache_buffer.get_subpackage_count(24) == 2);
        REQUIRE(package_cache_buffer.get_subpackage_count(12) == 1);

        auto packages_0 = package_cache_buffer.get_packages(0, 0);
        REQUIRE_THROWS(package_cache_buffer.get_packages(0, 3));
        auto packages_12 = package_cache_buffer.get_packages(12, 3);
        auto packages_24 = package_cache_buffer.get_packages(24, 3);
        REQUIRE_THROWS(package_cache_buffer.get_packages(1, 1));

        REQUIRE(packages_0.size() == 1);
        REQUIRE(packages_12.size() == 1);
        REQUIRE(packages_24.size() == 2);

        REQUIRE(packages_0[0] == dat);
        REQUIRE(packages_12[0] == dat2);
        REQUIRE(packages_24[0] == dat2);
        REQUIRE(packages_24[1] == dat3);
    }
}
