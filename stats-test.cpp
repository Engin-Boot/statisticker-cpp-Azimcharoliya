#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>
#include <vector>

TEST_CASE("reports average, minimum and maximum") {
    auto computedStats = Statistics::ComputeStatistics<float>({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("reports average, minimum and maximum of vector of integers values") {
    vector<int>values{1,2,3,4,5};
    auto computedStats = Statistics::ComputeStatistics(values);
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 3) < epsilon);
    REQUIRE(std::abs(computedStats.max - 5) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1) < epsilon);
}

TEST_CASE("reports average, minimum and maximum of vector of float values") {
    vector<float>values{1.1,2.2,3.3,4.4,5.5};
    auto computedStats = Statistics::ComputeStatistics(values);
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 3.3) < epsilon);
    REQUIRE(std::abs(computedStats.max - 5.5) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.1) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    auto computedStats = Statistics::ComputeStatistics({});
    
    REQUIRE(std::isnan(computedStats.average));
    REQUIRE(std::isnan(computedStats.max));
    REQUIRE(std::isnan(computedStats.min));
}

TEST_CASE("average is NaN for vector of char values.) {
    vector<char>values{'a','b','e','g','y'};
    auto computedStats = Statistics::ComputeStatistics(values);
    
    REQUIRE(std::isnan(computedStats.average));
    REQUIRE(computedStats.max=='y');
    REQUIRE(computedStats.min=='a');
}

