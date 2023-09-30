#include <gtest/gtest.h>

#include <Geometry/Utils.h>

namespace {

TEST(Utils, Dummy) {
    EXPECT_TRUE(true);
}

TEST(Utils, init) {
    EXPECT_NO_THROW( init() );
}

} // namespace
