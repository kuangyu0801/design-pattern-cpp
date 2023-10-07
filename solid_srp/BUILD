cc_library(
    name = "srp_lib",
    hdrs = [
        "public/journal.h"
    ],
)

cc_test(
    name = "srp_test",
    size = "small",
    srcs = ["srp_test.cc"],
    deps = [
        ":srp_lib",
        "@com_google_googletest//:gtest_main",
    ]
)