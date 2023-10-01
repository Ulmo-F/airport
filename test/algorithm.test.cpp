#include <gtest/gtest.h>

#include <Geometry/algorithm.h>

namespace {

TEST(greatestDistance, compute) {
    std::vector<Point> points {
        { 1., 0. },
        { 3., 0. },
        { 0., 0. },
        { -1., 0. }
    };

    EXPECT_EQ(greatestDistance(points), 4.);
}

} // namespace
