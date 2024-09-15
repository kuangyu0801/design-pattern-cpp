cc_library(
    name = "dynamic_strategy",
    hdrs = [
        "public/list_strategy.h",
        "public/output_format.h",
        "public/text_processor.h",
    ],
)

cc_library(
    name = "discriminant_strategy",
    hdrs = [
        "public/discriminant_strategy.h",
        "public/quadratic_equation_solver.h",
    ],
)

cc_library(
    name = "text_processor_strategy",
    hdrs = [
        "public/text_processor.h",
        "public/list_strategy.h",
    ]
)

cc_test(
    name = "discriminant_strategy_test",
    size = "small",
    srcs = ["discriminant_strategy_test.cc"],
    deps = [
        ":discriminant_strategy",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "text_processor_test",
    size = "small",
    srcs = ["strategy_test.cc"],
    deps = [
        ":text_processor_strategy",
        "@com_google_googletest//:gtest_main",
    ]
)