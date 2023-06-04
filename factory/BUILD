cc_library(
    name = "factory_lib",
    hdrs = ["public/factory.h"],
)

cc_library(
    name = "person_factory_lib",
    hdrs = ["public/person_factory.h"],
)

cc_library(
    name = "drink_factory_lib",
    hdrs = ["public/coffee_factory.h",
    "public/tea_factory.h",
    "public/drink_factory.h",
    "public/factory.h",
    "public/hot_drink_factory.h",
    "public/hot_drink.h"],
)

cc_test(
    name = "drink_factory_test",
    size = "small",
    srcs = ["hot_drink_factory_test.cc"],
    deps = [
        ":drink_factory_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "person_factory_test",
    size = "small",
    srcs = ["person_factory_test.cc"],
    deps = [
        ":person_factory_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "factory_test",
    size = "small",
    srcs = ["factory_test.cc"],
    deps = [
        ":factory_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
