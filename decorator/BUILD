cc_library(
    name = "shape_lib",
    hdrs = [
        "public/circle.h",
        "public/colored_shape.h",
        "public/shape.h",
        "public/square.h",
        "public/transparent_shape.h",
        "public/logger.h",
    ],
)

cc_library(
    name = "flowers",
    hdrs = [
        "public/blue_flower.h",
        "public/flower.h",
        "public/red_flower.h",
        "public/rose.h",
    ],
)

cc_test(
    name = "flower_tests",
    srcs = ["flower_decorator_test.cc"],
    deps = [
        ":flowers",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "shape_decorator_tests",
    srcs = ["decorator_test.cc"],
    deps = [
        ":shape_lib",
        "@com_google_googletest//:gtest_main",
    ],
)