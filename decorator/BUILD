cc_library(
    name = "shape",
    hdrs = ["public/shape.h"],
)


cc_library(
    name = "flowers",
    hdrs = ["public/rose.h",
            "public/flower.h",
            "public/blue_flower.h",
            "public/red_flower.h",],
)


cc_test(
    name = "flower_tests",
    
    srcs = ["flower_decorator_test.cc"],
    deps = [":flowers", "@com_google_googletest//:gtest_main", ],
)