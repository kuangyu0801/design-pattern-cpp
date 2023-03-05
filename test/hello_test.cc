#include "gtest/gtest.h"
#include "public/hello.h"

TEST(Hello, Basic) {
    ASSERT_TRUE(true);
    ASSERT_TRUE(hello::PrintHelloWorld());
}