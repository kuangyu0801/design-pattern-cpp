cc_library(
    name = "dynamic_strategy",
    hdrs = [
        "public/list_strategy.h",
        "public/output_format.h",
        "public/text_processor.h",
    ],
)

cc_test(
    name = "dynamic_strategy_test",
    size = "small",
    srcs = ["strategy_test.cc"],
    deps = [
        ":dynamic_strategy",
        "@com_google_googletest//:gtest_main",
    ],
)
