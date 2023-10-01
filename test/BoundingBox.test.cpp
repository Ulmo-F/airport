#include <gtest/gtest.h>

#include <Geometry/BoundingBox.h>

namespace {

TEST(Utils, Dummy) {
    std::vector<Point> points {
        { 1., 2. },
        { 3., 4. },
        { -0., -2. }
    };

    EXPECT_EQ(BoundingBox::create(points), BoundingBox({0., -2.}, {3., 4.}));
}

TEST(Utils, init) {
    std::vector<Point> emptyVector;
    EXPECT_ANY_THROW( (BoundingBox::create(emptyVector)) );
}

} // namespace
