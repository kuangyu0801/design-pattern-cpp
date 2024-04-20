cc_library(
    name = "proxy_lib",
    hdrs = [
        "public/bank_account.h",
        "public/property.h",
        "public/pingpong.h",
        "public/bitmap.h",
    ],
)

cc_test(
    name = "proxy_test",
    size = "small",
    srcs = ["proxy_test.cc"],
    deps = [
        ":proxy_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
