cc_library(
    name = "builder",
    hdrs = ["public/builder.h"],
)

cc_test(
    name = "builder_test",
    size = "small",
    srcs = ["builder_test.cc"],
    deps = [
        ":builder",
        "@com_google_googletest//:gtest_main",
    ],
)
