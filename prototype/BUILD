cc_library(
    name = "prototype_lib",
    hdrs = [
        "public/record.h",
        "public/prototype_exercise.h",
    ],
    deps = [
        "@boost//:serialization",
    ]
)

cc_test(
    name = "prototype_test",
    size = "small",
    srcs = ["prototype_test.cc"],
    deps = [
        ":prototype_lib",
        "@com_google_googletest//:gtest_main",
    ],
)