#include <gtest/gtest.h>

#include <Geometry/BoundingBox.h>

namespace {

TEST(BoundingBox, create) {
    std::vector<Point> points {
        { 1., 2. },
        { 3., 4. },
        { -0., -2. }
    };

    EXPECT_EQ(BoundingBox::create(points), BoundingBox({0., -2.}, {3., 4.}));
}

TEST(BoundingBox, throws_on_empty_input) {
    std::vector<Point> emptyVector;
    EXPECT_ANY_THROW( (BoundingBox::create(emptyVector)) );
}

} // namespace
